#ifndef SPVM_VALUE_H
#define SPVM_VALUE_H

#include "spvm_base.h"

// SPVM_VALUE
union SPVM_value {
  int8_t byte_value;
  int16_t short_value;
  int32_t int_value;
  int64_t long_value;
  float float_value;
  double double_value;
  SPVM_BASE_OBJECT* object_value;
  uint8_t* address_value;
};

#endif
