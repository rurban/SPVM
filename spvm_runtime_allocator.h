#ifndef SPVM_RUNTIME_ALLOCATOR_H
#define SPVM_RUNTIME_ALLOCATOR_H

#include <stddef.h>

#include "spvm_base.h"
#include "spvm_api.h"

struct SPVM_runtime_allocator {
  // Memory_pool
  SPVM_MEMORY_POOL* memory_pool;
  
  // Free lists
  SPVM_DYNAMIC_ARRAY** freelists;

  // use memory pool max reference byte size
  int64_t base_object_max_byte_size_use_memory_pool;
};

SPVM_RUNTIME_ALLOCATOR* SPVM_RUNTIME_ALLOCATOR_new(SPVM_RUNTIME* runtime);

void* SPVM_RUNTIME_ALLOCATOR_malloc(SPVM_API* api, SPVM_RUNTIME_ALLOCATOR* allocator, int64_t size);
void SPVM_RUNTIME_ALLOCATOR_free_base_object(SPVM_API* api, SPVM_RUNTIME_ALLOCATOR* allocator, SPVM_BASE_OBJECT* base_object);
int32_t SPVM_RUNTIME_ALLOCATOR_get_freelist_index(SPVM_API* api, SPVM_RUNTIME_ALLOCATOR* allocator, int64_t size);

void SPVM_RUNTIME_ALLOCATOR_free(SPVM_RUNTIME* runtime, SPVM_RUNTIME_ALLOCATOR* allocator);

#endif
