#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>


#include "spvm_compiler.h"
#include "spvm_dumper.h"
#include "spvm_dynamic_array.h"
#include "spvm_hash.h"
#include "spvm_constant.h"
#include "spvm_field.h"
#include "spvm_sub.h"
#include "spvm_my_var.h"
#include "spvm_var.h"
#include "spvm_op.h"
#include "spvm_enumeration_value.h"
#include "spvm_type.h"
#include "spvm_enumeration.h"
#include "spvm_package.h"
#include "spvm_type.h"
#include "spvm_constant_pool.h"
#include "spvm_bytecode.h"
#include "spvm_bytecode_array.h"

void SPVM_DUMPER_dump_ast(SPVM_COMPILER* compiler, SPVM_OP* op_base) {
  int32_t depth = 0;
  
  // Run OPs
  SPVM_OP* op_cur = op_base;
  _Bool finish = 0;
  while (op_cur) {
    // [START]Preorder traversal position
    
    {
      int32_t i;
      for (i = 0; i < depth; i++) {
        printf(" ");
      }
    }
    int32_t code = op_cur->code;
    printf("%s", SPVM_OP_C_CODE_NAMES[code]);
    if (op_cur->code == SPVM_OP_C_CODE_CONSTANT) {
      SPVM_CONSTANT* constant = op_cur->uv.constant;
      printf(" %s", SPVM_CONSTANT_C_CODE_NAMES[constant->code]);
      switch (constant->code) {
        case SPVM_CONSTANT_C_CODE_INT:
          printf(" %" PRId64, constant->uv.long_value);
          break;
        case SPVM_CONSTANT_C_CODE_LONG:
          printf(" %" PRId64, constant->uv.long_value);
          break;
        case SPVM_CONSTANT_C_CODE_FLOAT:
          printf(" %f", constant->uv.float_value);
          break;
        case SPVM_CONSTANT_C_CODE_DOUBLE:
          printf(" %f", constant->uv.double_value);
          break;
        case SPVM_CONSTANT_C_CODE_STRING:
          printf(" \"%s\"", constant->uv.string_value);
          break;
      }
      printf(" (index %" PRId32 ")", constant->constant_pool_index);
    }
    else if (code == SPVM_OP_C_CODE_MY) {
      SPVM_MY_VAR* my_var = op_cur->uv.my_var;
      printf(" \"%s\"", my_var->op_name->uv.name);
      printf(" (my_var->index:%d)", my_var->index);
    }
    else if (code == SPVM_OP_C_CODE_VAR) {
      SPVM_VAR* var = op_cur->uv.var;
      printf(" \"%s\"", var->op_name->uv.name);
      printf(" (my_var->index:%d)", var->op_my_var->uv.my_var->index);
    }
    else if (code == SPVM_OP_C_CODE_NAME) {
      printf(" \"%s\"", op_cur->uv.name);
    }
    else if (code == SPVM_OP_C_CODE_TYPE) {
      printf(" \"%s\"", op_cur->uv.type->name);
    }
    printf("\n");
    
    // [END]Preorder traversal position
    
    if (op_cur->first) {
      op_cur = op_cur->first;
      depth++;
    }
    else {
      while (1) {
        // [START]Postorder traversal position
        
        // [END]Postorder traversal position
        
        if (op_cur == op_base) {
          finish = 1;
          break;
        }
        
        // Next sibling
        if (op_cur->moresib) {
          op_cur = SPVM_OP_sibling(compiler, op_cur);
          break;
        }
        // Next is parent
        else {
          op_cur = op_cur->sibparent;
          depth--;
        }
      }
      if (finish) {
        break;
      }
    }
  }
}

void SPVM_DUMPER_dump_all(SPVM_COMPILER* compiler) {
  
  printf("\n[Abstract Syntax Tree]\n");
  SPVM_DUMPER_dump_ast(compiler, compiler->op_grammar);
  
  printf("\n[Resolved types]\n");
  SPVM_DUMPER_dump_types(compiler, compiler->types);

  printf("\n[Types]\n");
  SPVM_DUMPER_dump_types(compiler, compiler->types);
  
  printf("\n[Constant pool]\n");
  SPVM_DUMPER_dump_constant_pool(compiler, compiler->constant_pool);
  
  printf("\n[Packages]\n");
  SPVM_DUMPER_dump_packages(compiler, compiler->op_packages);
}

void SPVM_DUMPER_dump_constants(SPVM_COMPILER* compiler, SPVM_DYNAMIC_ARRAY* op_constants) {
  {
    int32_t i;
    int32_t len;
    for (i = 0, len = op_constants->length; i < len; i++) {
      SPVM_OP* op_constant = SPVM_DYNAMIC_ARRAY_fetch(op_constants, i);
      SPVM_CONSTANT* constant = op_constant->uv.constant;
      printf("    constant[%" PRId32 "]\n", i);
      SPVM_DUMPER_dump_constant(compiler, constant);
    }
  }
}

void SPVM_DUMPER_dump_packages(SPVM_COMPILER* compiler, SPVM_DYNAMIC_ARRAY* op_packages) {
  {
    int32_t i;
    int32_t len;
    for (i = 0, len = op_packages->length; i < len; i++) {
      printf("package[%" PRId32 "]\n", i);
      SPVM_OP* op_package = SPVM_DYNAMIC_ARRAY_fetch(op_packages, i);
      SPVM_PACKAGE* package = op_package->uv.package;
      printf("  name => \"%s\"\n", package->op_name->uv.name);
      
      if (package->op_type) {
        SPVM_TYPE* type = package->op_type->uv.type;
        printf("  type => \"%s\"\n", type->name);
      }
      
      printf("  byte_size => %" PRId32 "\n", package->op_fields->length);
      
      // Field information
      printf("  fields\n");
      SPVM_DYNAMIC_ARRAY* op_fields = package->op_fields;
      {
        int32_t j;
        int32_t len2;
        for (j = 0, len2 = op_fields->length; j < len2; j++) {
          SPVM_OP* op_field = SPVM_DYNAMIC_ARRAY_fetch(op_fields, j);
          SPVM_FIELD* field = op_field->uv.field;
          printf("    field%" PRId32 "\n", j);
          SPVM_DUMPER_dump_field(compiler, field);
        }
      }
      
      // Sub information
      printf("  subs\n");
      SPVM_DYNAMIC_ARRAY* op_subs = package->op_subs;
      {
        int32_t i;
        for (i = 0, len = op_subs->length; i < len; i++) {
          SPVM_OP* op_sub = SPVM_DYNAMIC_ARRAY_fetch(op_subs, i);
          SPVM_SUB* sub = op_sub->uv.sub;
          printf("    sub%" PRId32 "\n", i);
          SPVM_DUMPER_dump_sub(compiler, sub);
        }
      }
    }
  }
}

void SPVM_DUMPER_dump_types(SPVM_COMPILER* compiler, SPVM_DYNAMIC_ARRAY* types) {
  (void)compiler;
  
  {
    int32_t i;
    int32_t len;
    for (i = 0, len = types->length; i < len; i++) {
      printf("type[%" PRId32 "]\n", i);
      SPVM_TYPE* type = SPVM_DYNAMIC_ARRAY_fetch(types, i);
      printf("    name => \"%s\"\n", type->name);
      printf("    id => \"%" PRId32 "\"\n", type->id);
    }
  }
}

void SPVM_DUMPER_dump_constant_pool(SPVM_COMPILER* compiler, SPVM_CONSTANT_POOL* constant_pool) {
  (void)compiler;
  
  {
    int32_t i;
    for (i = 0; i < constant_pool->length; i++) {
      printf("      constant_pool[%" PRId32 "] %" PRId32 "\n", i, constant_pool->values[i]);
    }
  }
}

void SPVM_DUMPER_dump_bytecode_array(SPVM_COMPILER* compiler, SPVM_BYTECODE_ARRAY* bytecode_array, int32_t start_pos, int32_t length) {
  (void)compiler;
  
  int32_t end_pos = start_pos + length - 1;
  
  {
    int32_t i;
    for (i = start_pos; i <= end_pos; i++) {
      
      uint8_t bytecode = bytecode_array->values[i];
      printf("        [%" PRId32 "] %s\n", i, SPVM_BYTECODE_C_CODE_NAMES[bytecode]);
      
      // Operand
      switch (bytecode) {
        case SPVM_BYTECODE_C_CODE_WIDE: {
          i++;
          bytecode = bytecode_array->values[i];
          
          switch (bytecode) {
            // Have tow operand]
            case SPVM_BYTECODE_C_CODE_STORE:
            case SPVM_BYTECODE_C_CODE_STORE_OBJECT:
            case SPVM_BYTECODE_C_CODE_LOAD:
            {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
              
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
              
              break;
            }
          }
          
          break;
        }
        
        // Have one operand
        case SPVM_BYTECODE_C_CODE_PUSH_BYTE:
        case SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_SHORT:
        case SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_INT:
        case SPVM_BYTECODE_C_CODE_PUSH_BYTE_TO_LONG:
        case SPVM_BYTECODE_C_CODE_STORE:
        case SPVM_BYTECODE_C_CODE_STORE_OBJECT:
        case SPVM_BYTECODE_C_CODE_LOAD:
        case SPVM_BYTECODE_C_CODE_MALLOC_ARRAY:
        {
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          break;
        }
        
        // Have tow operands
        case SPVM_BYTECODE_C_CODE_INC_BYTE:
        case SPVM_BYTECODE_C_CODE_INC_SHORT:
        case SPVM_BYTECODE_C_CODE_INC_INT:
        case SPVM_BYTECODE_C_CODE_INC_LONG:
        case SPVM_BYTECODE_C_CODE_PUSH_SHORT:
        case SPVM_BYTECODE_C_CODE_PUSH_SHORT_TO_INT:
        case SPVM_BYTECODE_C_CODE_PUSH_SHORT_TO_LONG:
        case SPVM_BYTECODE_C_CODE_IF_EQ_CMP:
        case SPVM_BYTECODE_C_CODE_IF_NE_CMP:
        case SPVM_BYTECODE_C_CODE_IF_LT_CMP:
        case SPVM_BYTECODE_C_CODE_IF_GE_CMP:
        case SPVM_BYTECODE_C_CODE_IF_GT_CMP:
        case SPVM_BYTECODE_C_CODE_IF_LE_CMP:
        case SPVM_BYTECODE_C_CODE_IF_EQ_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_NE_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_LT_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_GE_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_GT_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_LE_ZERO:
        case SPVM_BYTECODE_C_CODE_IF_EQ_CMP_OBJECT:
        case SPVM_BYTECODE_C_CODE_IF_NE_CMP_OBJECT:
        case SPVM_BYTECODE_C_CODE_IF_NON_NULL:
        case SPVM_BYTECODE_C_CODE_IF_NULL:
        case SPVM_BYTECODE_C_CODE_GOTO:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_BYTE:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_SHORT:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_INT:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_LONG:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_FLOAT:
        case SPVM_BYTECODE_C_CODE_GET_FIELD_DOUBLE:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_BYTE:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_SHORT:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_INT:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_LONG:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_FLOAT:
        case SPVM_BYTECODE_C_CODE_SET_FIELD_DOUBLE:
        {
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          break;
        }
        
        // Have four operands
        case SPVM_BYTECODE_C_CODE_CALL_SUB:
        case SPVM_BYTECODE_C_CODE_LOAD_CONSTANT:
        case SPVM_BYTECODE_C_CODE_LOAD_CONSTANT2:
        case SPVM_BYTECODE_C_CODE_MALLOC_STRING:
        case SPVM_BYTECODE_C_CODE_MALLOC_OBJECT:
        {
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          i++;
          bytecode = bytecode_array->values[i];
          printf("        [%" PRId32 "] %d\n", i, bytecode);
          
          break;
        }
        
        case SPVM_BYTECODE_C_CODE_TABLE_SWITCH: {
          
          // Bytecode index to calculate padding
          int32_t pc = i;
          
          // Padding
          int32_t padding = (sizeof(int32_t) - 1) - (pc % sizeof(int32_t));
          
          {
            int32_t j;
            for (j = 0; j < padding; j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Default
          {
            int32_t j;
            for (j = 0; j < (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Low
          int32_t min = *(int32_t*)&bytecode_array->values[i + 1];
          {
            int32_t j;
            for (j = 0; j < (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // High
          int32_t max = *(int32_t*)&bytecode_array->values[i + 1];
          {
            int32_t j;
            for (j = 0; j < (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Addresses
          int32_t length = max - min + 1;
          {
            int32_t j;
            for (j = 0; j < length * (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          break;
        }
        case SPVM_BYTECODE_C_CODE_LOOKUP_SWITCH: {
          
          // Bytecode index to calculate padding
          int32_t pc = i;
          
          // Padding
          int32_t padding = (sizeof(int32_t) - 1) - (pc % sizeof(int32_t));
          
          {
            int32_t j;
            for (j = 0; j < padding; j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Default
          {
            int32_t j;
            for (j = 0; j < (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Count
          int32_t length = *(int32_t*)&bytecode_array->values[i + 1];
          {
            int32_t j;
            for (j = 0; j < (int32_t)sizeof(int32_t); j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          // Addresses
          {
            int32_t j;
            for (j = 0; j < length * (int32_t)sizeof(int32_t) * 2; j++) {
              i++;
              bytecode = bytecode_array->values[i];
              printf("        [%" PRId32 "] %d\n", i, bytecode);
            }
          }
          
          break;
        }
      }
    }
  }
}

void SPVM_DUMPER_dump_constant(SPVM_COMPILER* compiler, SPVM_CONSTANT* constant) {
  (void)compiler;
  
  switch(constant->code) {
    case SPVM_CONSTANT_C_CODE_INT:
      printf("      int ld%" PRId64 "\n", constant->uv.long_value);
      break;
    case SPVM_CONSTANT_C_CODE_LONG:
      printf("      long ld%" PRId64 "\n", constant->uv.long_value);
      break;
    case SPVM_CONSTANT_C_CODE_FLOAT:
      printf("      float %f\n", constant->uv.float_value);
      break;
    case SPVM_CONSTANT_C_CODE_DOUBLE:
      printf("      double %f\n", constant->uv.double_value);
      break;
    case SPVM_CONSTANT_C_CODE_STRING:
      printf("      string \"%s\"\n", constant->uv.string_value);
      break;
  }
  printf("      address => %" PRId32 "\n", constant->constant_pool_index);
}

void SPVM_DUMPER_dump_sub(SPVM_COMPILER* compiler, SPVM_SUB* sub) {
  (void)compiler;
  
  if (sub) {
    
    printf("      name => \"%s\"\n", sub->op_name->uv.name);
    printf("      abs_name => \"%s\"\n", sub->abs_name);
    
    if (sub->op_return_type->code == SPVM_OP_C_CODE_VOID) {
      printf("      type => void\n");
    }
    else {
      printf("      type => \"%s\"\n", sub->op_return_type->uv.type->name);
    }
    
    printf("      is_constant => %d\n", sub->is_constant);
    printf("      is_native => %d\n", sub->is_native);
    
    printf("      args\n");
    SPVM_DYNAMIC_ARRAY* op_args = sub->op_args;
    {
      int32_t i;
      int32_t len;
      for (i = 0, len = op_args->length; i < len; i++) {
        SPVM_OP* op_arg = SPVM_DYNAMIC_ARRAY_fetch(sub->op_args, i);
        SPVM_MY_VAR* my_var = op_arg->uv.my_var;
        printf("        arg[%" PRId32 "]\n", i);
        SPVM_DUMPER_dump_my_var(compiler, my_var);
      }
    }
    
    if (!sub->is_native) {
      printf("      my_vars\n");
      SPVM_DYNAMIC_ARRAY* op_my_vars = sub->op_my_vars;
      {
        int32_t i;
        int32_t len;
        for (i = 0, len = op_my_vars->length; i < len; i++) {
          SPVM_OP* op_my_var = SPVM_DYNAMIC_ARRAY_fetch(sub->op_my_vars, i);
          SPVM_MY_VAR* my_var = op_my_var->uv.my_var;
          printf("        my_var[%" PRId32 "]\n", i);
          SPVM_DUMPER_dump_my_var(compiler, my_var);
        }
      }
      
      printf("      operand_stack_max => %" PRId32 "\n", sub->operand_stack_max);
      
      printf("      bytecode_array\n");
      SPVM_DUMPER_dump_bytecode_array(compiler, compiler->bytecode_array, sub->bytecode_base, sub->bytecode_length);
    }
  }
  else {
    printf("      None\n");
  }
}

void SPVM_DUMPER_dump_field(SPVM_COMPILER* compiler, SPVM_FIELD* field) {
  (void)compiler;
  
  if (field) {
    printf("      name => \"%s\"\n", field->op_name->uv.name);
    
    printf("      index => \"%" PRId32 "\"\n", field->index);
    
    SPVM_TYPE* type = field->op_type->uv.type;
    printf("      type => \"%s\"\n", type->name);
    printf("      byte_size => \"%" PRId32 "\"\n", SPVM_FIELD_get_byte_size(compiler, field));
    
    printf("      constant_pool_index => \"%" PRId32 "\"\n", field->constant_pool_index);
  }
  else {
    printf("        None\n");
  }
}


void SPVM_DUMPER_dump_enumeration_value(SPVM_COMPILER* compiler, SPVM_ENUMERATION_VALUE* enumeration_value) {
  (void)compiler;
  
  if (enumeration_value) {
    printf("      name => \"%s\"\n", enumeration_value->op_name->uv.name);
    printf("      value => %" PRId64 "\n", enumeration_value->op_constant->uv.constant->uv.long_value);
  }
  else {
    printf("      None\n");
  }
}

void SPVM_DUMPER_dump_my_var(SPVM_COMPILER* compiler, SPVM_MY_VAR* my_var) {
  (void)compiler;

  if (my_var) {
    printf("          name => \"%s\"\n", my_var->op_name->uv.name);
    
    SPVM_TYPE* type = my_var->op_type->uv.type;
    printf("          type => \"%s\"\n", type->name);
    
  }
  else {
    printf("          None\n");
  }
}
