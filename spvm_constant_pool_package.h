#ifndef SPVM_CONSTANT_POOL_PACKAGE_H
#define SPVM_CONSTANT_POOL_PACKAGE_H

#include "spvm_base.h"

// SPVM_CONSTANT_POOL_PACKAGE
struct SPVM_constant_pool_package {
  int32_t name_constant_pool_index;
  int32_t fields_length;
  int32_t object_fields_length;
  int32_t field_name_indexes_constant_pool_index;
  int32_t field_indexes_constant_pool_index;
};

#endif
