#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../spvm_compiler.h"
#include "../spvm_hash.h"
#include "../spvm_dynamic_array.h"
#include "../spvm_util_allocator.h"
#include "../spvm_constant_pool.h"
#include "../spvm_bytecode_array.h"
#include "../spvm_runtime.h"
#include "../spvm_runtime_allocator.h"
#include "../spvm_op.h"
#include "../spvm_sub.h"
#include "../spvm_dumper.h"
#include "../spvm_api.h"

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Not script\n");
    exit(1);
  }
  
  // Package name
  const char* package_name = argv[1];
  
  // Create compiler
  SPVM_COMPILER* compiler = SPVM_COMPILER_new();
  
  compiler->entry_point_package_name = package_name;
  
  SPVM_DYNAMIC_ARRAY_push(compiler->include_pathes, "lib");
  SPVM_DYNAMIC_ARRAY_push(compiler->include_pathes, "solo");
  
  SPVM_COMPILER_compile(compiler);
  
  if (compiler->error_count > 0) {
    return 1;
  }
  else {
#ifdef DEBUG
    // Dump spvm information
    SPVM_DUMPER_dump_all(compiler);
#endif
  }

  
  // Create run-time
  SPVM_RUNTIME* runtime = SPVM_COMPILER_new_runtime(compiler);
  SPVM_API* api = runtime->api;

  // Entry point subroutine address
  const char* entry_point_sub_name = compiler->entry_point_sub_name;
  SPVM_OP* op_sub_start;
  int32_t sub_constant_pool_index;
  if (entry_point_sub_name) {
    op_sub_start = SPVM_HASH_search(compiler->op_sub_symtable, entry_point_sub_name, strlen(entry_point_sub_name));
    if (op_sub_start) {
      sub_constant_pool_index = op_sub_start->uv.sub->constant_pool_index;
    }
    else {
      fprintf(stderr, "Can't find entry point subroutine %s", entry_point_sub_name);
      exit(EXIT_FAILURE);
    }
  }
  else {
    fprintf(stderr, "Can't find entry point subroutine\n");
    exit(EXIT_FAILURE);
  }
  
  // Free compiler
  SPVM_COMPILER_free(compiler);
  
  // Push argument
  api->push_var_int(api, 2);
  
  // Run
  api->call_sub(api, sub_constant_pool_index);
  
#ifdef DEBUG
  if (runtime->abort) {
    void* message_object = runtime->exception;;
    int8_t* message = api->get_byte_array_elements(api, message_object);
    
    printf("%s", (char*)message);
    printf("\n");
  }
  else {
    // Get return value
    int64_t return_value = api->pop_retval_int(api);
    
    printf("TEST return_value: %ld\n", return_value);
  }
#endif
  
  SPVM_RUNTIME_free(runtime);
  
  return 0;
}
