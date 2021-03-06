#ifndef SPVM_CONSTANT_POOL_SUB_H
#define SPVM_CONSTANT_POOL_SUB_H

#include "spvm_base.h"

struct SPVM_constant_pool_sub {
  void* native_address;
  int32_t bytecode_base;
  int32_t file_name_constant_pool_index;
  int32_t abs_name_constant_pool_index;
  int32_t operand_stack_max;
  int32_t my_vars_length;
  int32_t args_length;
  int32_t object_args_length;
  int32_t object_arg_indexes_constant_pool_index;
  int32_t object_my_vars_length;
  int32_t object_my_var_indexes_constant_pool_index;
  int32_t return_type_id;
  _Bool is_native;
};

#endif
