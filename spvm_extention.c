#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "spvm_api.h"

void SPVM_EXTENTION_std__sum_int(SPVM_API* api) {
  void* array = api->get_var_object(api, 0);
  
  int32_t length = api->get_array_length(api, array);
  
  int32_t* values = api->get_int_array_elements(api, array);
  
  int64_t total = 0;
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      total += values[i];
    }
  }
  
  api->push_retval_int(api, total);
}

void SPVM_EXTENTION_std__test1(SPVM_API* api) {
  int32_t num1 = api->get_var_int(api, 0);
  int32_t num2 = api->get_var_int(api, 1);
  
  int32_t sub_id = api->get_sub_id(api, "std::test2");
  
  api->push_var_int(api, 5);
  api->push_var_int(api, 3);
  api->call_sub(api, sub_id);
  int32_t ret = api->pop_retval_int(api);
  
  int32_t num3 = num1 + num2 + ret;
  
  api->push_retval_int(api, num3);
}

void SPVM_EXTENTION_std__test2(SPVM_API* api) {
  int32_t num1 = api->get_var_int(api, 0);
  int32_t num2 = api->get_var_int(api, 1);
  
  int32_t num3 = num1 * num2;
  
  api->push_retval_int(api, num3);
}

void SPVM_EXTENTION_std__print(SPVM_API* api) {
  void* array = api->get_var_object(api, 0);

  int32_t length = api->get_array_length(api, array);
  int8_t* string = api->get_byte_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      putchar((int)string[i]);
    }
  }
}

void SPVM_EXTENTION_std__println(SPVM_API* api) {
  void* array = api->get_var_object(api, 0);

  int32_t length = api->get_array_length(api, array);
  
  int8_t* string = api->get_byte_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      putchar((int)string[i]);
    }
  }
  
  printf("\n");
}

void SPVM_EXTENTION_std__println_byte(SPVM_API* api) {
  int8_t value = api->get_var_byte(api, 0);
  
  printf("%" PRId8 "\n", value);
}

void SPVM_EXTENTION_std__println_short(SPVM_API* api) {
  int16_t value = api->get_var_short(api, 0);
  
  printf("%" PRId16 "\n", value);
}

void SPVM_EXTENTION_std__println_int(SPVM_API* api) {
  int32_t value = api->get_var_int(api, 0);
  
  printf("%" PRId32 "\n", value);
}

void SPVM_EXTENTION_std__println_long(SPVM_API* api) {
  int64_t value = api->get_var_long(api, 0);
  
  printf("%" PRId64 "\n", value);
}

void SPVM_EXTENTION_std__println_float(SPVM_API* api) {
  float value = api->get_var_float(api, 0);

  printf("%f\n", value);
}

void SPVM_EXTENTION_std__println_double(SPVM_API* api) {
  double value = api->get_var_double(api, 0);
  
  printf("%f\n", value);
}

void SPVM_EXTENTION_std__print_byte(SPVM_API* api) {
  int8_t value = api->get_var_byte(api, 0);
  
  printf("%" PRId8, value);
}

void SPVM_EXTENTION_std__print_short(SPVM_API* api) {
  int16_t value = api->get_var_short(api, 0);
  
  printf("%" PRId16, value);
}

void SPVM_EXTENTION_std__print_int(SPVM_API* api) {
  int32_t value = api->get_var_int(api, 0);
  
  printf("%" PRId32, value);
}

void SPVM_EXTENTION_std__print_long(SPVM_API* api) {
  int64_t value = api->get_var_long(api, 0);
  
  printf("%" PRId64, value);
}

void SPVM_EXTENTION_std__print_float(SPVM_API* api) {
  float value = api->get_var_float(api, 0);
  
  printf("%f", value);
}

void SPVM_EXTENTION_std__print_double(SPVM_API* api) {
  double value = api->get_var_double(api, 0);
  
  printf("%f", value);
}
