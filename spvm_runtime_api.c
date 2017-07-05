#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "spvm_value.h"
#include "spvm_runtime_api.h"
#include "spvm_constant_pool_sub.h"
#include "spvm_constant_pool_field.h"
#include "spvm_constant_pool_package.h"
#include "spvm_base_object.h"
#include "spvm_array_object.h"
#include "spvm_object.h"
#include "spvm_value.h"
#include "spvm_runtime.h"
#include "spvm_runtime_allocator.h"
#include "spvm_api.h"

int64_t SPVM_RUNTIME_API_calcurate_base_object_byte_size(SPVM_API* api, SPVM_BASE_OBJECT* base_object) {
  
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int64_t byte_size;
  
  // Reference is string
  if (base_object->type == SPVM_BASE_OBJECT_C_TYPE_ARRAY) {
    SPVM_ARRAY_OBJECT* array_object = (SPVM_ARRAY_OBJECT*)base_object;
    byte_size = sizeof(SPVM_ARRAY_OBJECT) + array_object->length * SPVM_RUNTIME_API_get_array_value_size(api, array_object->value_type);
  }
  // Reference is object
  else if (base_object->type == SPVM_BASE_OBJECT_C_TYPE_OBJECT) {
    SPVM_OBJECT* object = (SPVM_OBJECT*)base_object;
    SPVM_CONSTANT_POOL_PACKAGE constant_pool_package;
    memcpy(&constant_pool_package, &runtime->constant_pool[object->package_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_PACKAGE));
    byte_size = sizeof(SPVM_OBJECT) + sizeof(SPVM_VALUE) * constant_pool_package.fields_length;
  }
  else {
    assert(0);
  }
  
  return byte_size;
}

SPVM_ARRAY_OBJECT* SPVM_RUNTIME_API_create_array_object_byte(SPVM_API* api, int32_t length) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  SPVM_RUNTIME_ALLOCATOR* allocator = runtime->allocator;
  
  // Allocate array
  int32_t array_object_byte_size = sizeof(SPVM_ARRAY_OBJECT) + sizeof(int8_t) * length;
  SPVM_ARRAY_OBJECT* array_object = SPVM_RUNTIME_ALLOCATOR_malloc(api, allocator, array_object_byte_size);
  
  // Fatal memory allocation error
  if (!array_object) {
    fprintf(stderr, "Failed to allocate memory(create_array_object_from_pv)");
    abort();
  }
  
  // Set type
  array_object->type = SPVM_BASE_OBJECT_C_TYPE_ARRAY;
  
  // Set sub type
  array_object->value_type = SPVM_ARRAY_OBJECT_C_VALUE_TYPE_BYTE;
  
  // Set reference count
  array_object->ref_count = 0;
  
  // Set array length
  array_object->length = length;
  
  assert(array_object_byte_size == SPVM_RUNTIME_API_calcurate_base_object_byte_size(api, (SPVM_BASE_OBJECT*)array_object));
  
  return array_object;
}

SPVM_ARRAY_OBJECT* SPVM_RUNTIME_API_create_array_object_byte_from_pv(SPVM_API* api, const char* pv) {
  (void)api;
  
  int32_t length = strlen(pv);
  SPVM_ARRAY_OBJECT* array_object = SPVM_RUNTIME_API_create_array_object_byte(api, length);
  
  // Copy string
  memcpy((void*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT)), pv, length);
  
  return array_object;
}

void SPVM_RUNTIME_API_dec_ref_count(SPVM_API* api, SPVM_BASE_OBJECT* base_object) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  if (base_object != NULL) {
    
    assert(base_object->ref_count > 0);
    
    // Decrement reference count
    base_object->ref_count -= 1;
    
    // If reference count is zero, free address.
    if (base_object->ref_count == 0) {
      
      if (base_object->type == SPVM_BASE_OBJECT_C_TYPE_ARRAY) {
        SPVM_ARRAY_OBJECT* array_object = (SPVM_ARRAY_OBJECT*)base_object;
        if (array_object->value_type == SPVM_ARRAY_OBJECT_C_VALUE_TYPE_REF) {
          
          // Array length
          int32_t length = array_object->length;
          
          {
            int32_t i;
            for (i = 0; i < length; i++) {
              SPVM_BASE_OBJECT* base_object_element = *(SPVM_BASE_OBJECT**)((intptr_t)array_object + sizeof(SPVM_OBJECT) + sizeof(void*) * i);
              SPVM_RUNTIME_API_dec_ref_count(api, base_object_element);
            }
          }
        }
        SPVM_RUNTIME_ALLOCATOR_free_base_object(api, runtime->allocator, base_object);
      }
      // Reference is object
      else if (base_object->type == SPVM_BASE_OBJECT_C_TYPE_OBJECT) {
        SPVM_OBJECT* object = (SPVM_OBJECT*)base_object;
        
        int32_t package_constant_pool_index = object->package_constant_pool_index;
        SPVM_CONSTANT_POOL_PACKAGE constant_pool_package;
        memcpy(&constant_pool_package, &runtime->constant_pool[package_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_PACKAGE));
        
        int32_t object_fields_length = constant_pool_package.object_fields_length;
        
        {
          int32_t i;
          for (i = 0; i < object_fields_length; i++) {
            SPVM_BASE_OBJECT* base_object_field = *(SPVM_BASE_OBJECT**)((intptr_t)object + sizeof(SPVM_OBJECT) + sizeof(void*) * i);
            SPVM_RUNTIME_API_dec_ref_count(api, base_object_field);
          }
        }
        
        SPVM_RUNTIME_ALLOCATOR_free_base_object(api, runtime->allocator, (SPVM_BASE_OBJECT*)object);
      }
    }
  }
}

void SPVM_RUNTIME_API_inc_ref_count(SPVM_API* api, SPVM_BASE_OBJECT* base_object) {
  (void)api;
  
  if (base_object != NULL) {
    assert(base_object->ref_count >= 0);
    // Increment reference count
    base_object->ref_count += 1;
  }
}

int32_t SPVM_RUNTIME_API_get_ref_count(SPVM_API* api, SPVM_BASE_OBJECT* base_object) {
  (void)api;
  
  return base_object->ref_count;
}

void SPVM_RUNTIME_API_push_stack_byte(SPVM_API* api, int8_t value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].byte_value = value;
}

void SPVM_RUNTIME_API_push_stack_short(SPVM_API* api, int16_t value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].short_value = value;
}

void SPVM_RUNTIME_API_push_stack_int(SPVM_API* api, int32_t value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].int_value = value;
}

void SPVM_RUNTIME_API_push_stack_long(SPVM_API* api, int64_t value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].long_value = value;
}

void SPVM_RUNTIME_API_push_stack_float(SPVM_API* api, float value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].float_value = value;
}

void SPVM_RUNTIME_API_push_stack_double(SPVM_API* api, double value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].double_value = value;
}

void SPVM_RUNTIME_API_push_stack_object(SPVM_API* api, void* value) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  runtime->operand_stack_top++;
  runtime->call_stack[runtime->operand_stack_top].address_value = value;
}

int8_t SPVM_RUNTIME_API_pop_stack_byte(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int8_t ret = runtime->call_stack[runtime->operand_stack_top].byte_value;
  runtime->operand_stack_top--;
  return ret;
}

int16_t SPVM_RUNTIME_API_pop_stack_short(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int16_t ret = runtime->call_stack[runtime->operand_stack_top].short_value;
  runtime->operand_stack_top--;
  return ret;
}

int32_t SPVM_RUNTIME_API_pop_stack_int(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int32_t ret = runtime->call_stack[runtime->operand_stack_top].int_value;
  runtime->operand_stack_top--;
  return ret;
}

int64_t SPVM_RUNTIME_API_pop_stack_long(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;

  int64_t ret = runtime->call_stack[runtime->operand_stack_top].long_value;
  runtime->operand_stack_top--;
  return ret;
}

float SPVM_RUNTIME_API_pop_stack_float(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  float ret = runtime->call_stack[runtime->operand_stack_top].float_value;
  runtime->operand_stack_top--;
  return ret;
}

double SPVM_RUNTIME_API_pop_stack_double(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  double ret = runtime->call_stack[runtime->operand_stack_top].double_value;
  runtime->operand_stack_top--;
  return ret;
}

void* SPVM_RUNTIME_API_pop_stack_address(SPVM_API* api) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  void* ret = runtime->call_stack[runtime->operand_stack_top].address_value;
  runtime->operand_stack_top--;
  return ret;
}

int8_t SPVM_RUNTIME_API_get_var_byte(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].byte_value;
}

int16_t SPVM_RUNTIME_API_get_var_short(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].short_value;
}

int32_t SPVM_RUNTIME_API_get_var_int(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].int_value;
}

int64_t SPVM_RUNTIME_API_get_var_long(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].long_value;
}

float SPVM_RUNTIME_API_get_var_float(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].float_value;
}

double SPVM_RUNTIME_API_get_var_double(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].double_value;
}

void* SPVM_RUNTIME_API_get_var_address(SPVM_API* api, int32_t index) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  return runtime->call_stack[runtime->call_stack_base + (size_t)index].address_value;
}

int32_t SPVM_RUNTIME_API_get_array_value_size(SPVM_API* api, int32_t type) {
  (void)api;
  
  static const int32_t array_value_sizes[] = {
    sizeof(int8_t),
    sizeof(int16_t),
    sizeof(int32_t),
    sizeof(int64_t),
    sizeof(float),
    sizeof(double),
    sizeof(void*),
  };
  
  return array_value_sizes[type];
}

SPVM_VALUE* SPVM_RUNTIME_API_get_fields(SPVM_API* api, SPVM_OBJECT* object) {
  (void)api;
  
  return (SPVM_VALUE*)((intptr_t)object + sizeof(SPVM_OBJECT));
}

int32_t SPVM_RUNTIME_API_get_field_index(SPVM_API* api, SPVM_OBJECT* object, const char* name) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int32_t* constant_pool = runtime->constant_pool;
  SPVM_CONSTANT_POOL_PACKAGE constant_pool_package;
  memcpy(&constant_pool_package, &constant_pool[object->package_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_PACKAGE));
  
  int32_t length = constant_pool_package.fields_length;
  int32_t field_indexes_constant_pool_index = constant_pool_package.field_indexes_constant_pool_index;
  
  int32_t field_index = -1;
  _Bool found = 0;
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      
      int32_t field_constant_pool_index = constant_pool[field_indexes_constant_pool_index + i];
      SPVM_CONSTANT_POOL_FIELD constant_pool_field;
      memcpy(&constant_pool_field, &constant_pool[field_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_FIELD));
      
      int32_t field_name_constant_pool_index = constant_pool_field.name_constant_pool_index;
      
      char* match_name = (char*)&constant_pool[field_name_constant_pool_index];
      if (strcmp(name, match_name) == 0) {
        found = 1;
        field_index = i;
        break;
      }
    }
  }
  
  if (!found) {
    fprintf(stderr, "Can't find filed name \"%s\"\n", name);
    abort();
  }
  
  return field_index;
}

int32_t SPVM_RUNTIME_API_get_fields_length(SPVM_API* api, SPVM_OBJECT* object) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int32_t* constant_pool = runtime->constant_pool;
  SPVM_CONSTANT_POOL_PACKAGE constant_pool_package;
  memcpy(&constant_pool_package, &constant_pool[object->package_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_PACKAGE));
  int32_t length = constant_pool_package.fields_length;
  
  return length;
}

void SPVM_RUNTIME_API_set_byte_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, int8_t value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].byte_value = value;
}

void SPVM_RUNTIME_API_set_short_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, int16_t value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].short_value = value;
}

void SPVM_RUNTIME_API_set_int_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, int32_t value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].int_value = value;
}

void SPVM_RUNTIME_API_set_long_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, int64_t value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].long_value = value;
}

void SPVM_RUNTIME_API_set_float_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, float value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].float_value = value;
}

void SPVM_RUNTIME_API_set_double_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index, double value) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  fields[field_index].double_value = value;
}

int8_t SPVM_RUNTIME_API_get_byte_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  int8_t byte_value = fields[field_index].byte_value;
  
  return byte_value;
}

int16_t SPVM_RUNTIME_API_get_short_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  int16_t short_value = fields[field_index].short_value;
  
  return short_value;
}

int32_t SPVM_RUNTIME_API_get_int_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  int32_t int_value = fields[field_index].int_value;
  
  return int_value;
}

int64_t SPVM_RUNTIME_API_get_long_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  int64_t long_value = fields[field_index].long_value;
  
  return long_value;
}

float SPVM_RUNTIME_API_get_float_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  float float_value = fields[field_index].float_value;
  
  return float_value;
}

double SPVM_RUNTIME_API_get_double_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  double double_value = fields[field_index].double_value;
  
  return double_value;
}

SPVM_BASE_OBJECT* SPVM_RUNTIME_API_get_object_field(SPVM_API* api, SPVM_OBJECT* object, int32_t field_index) {
  SPVM_VALUE* fields = SPVM_RUNTIME_API_get_fields(api, object);
  SPVM_BASE_OBJECT* address_value = fields[field_index].address_value;
  
  return address_value;
}

int32_t SPVM_RUNTIME_API_dump_field_names(SPVM_API* api, SPVM_OBJECT* object) {
  SPVM_RUNTIME* runtime = (SPVM_RUNTIME*)api->runtime;
  
  int32_t* constant_pool = runtime->constant_pool;
  SPVM_CONSTANT_POOL_PACKAGE constant_pool_package;
  memcpy(&constant_pool_package, &constant_pool[object->package_constant_pool_index], sizeof(SPVM_CONSTANT_POOL_PACKAGE));
  int32_t field_name_indexes_constant_pool_index = constant_pool_package.field_name_indexes_constant_pool_index;
  int32_t length = constant_pool_package.fields_length;
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      int32_t name_index = constant_pool[field_name_indexes_constant_pool_index + i];
      char* name = (char*)&constant_pool[name_index + 1];
      fprintf(stderr, "%s\n", name);
    }
  }
  
  return length;
}

int32_t SPVM_RUNTIME_API_get_array_length(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return array_object->length;
}

int8_t* SPVM_RUNTIME_API_get_byte_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;

  return (int8_t*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

int16_t* SPVM_RUNTIME_API_get_short_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (int16_t*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

int32_t* SPVM_RUNTIME_API_get_int_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (int32_t*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

int64_t* SPVM_RUNTIME_API_get_long_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (int64_t*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

float* SPVM_RUNTIME_API_get_float_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (float*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

double* SPVM_RUNTIME_API_get_double_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (double*)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}

SPVM_BASE_OBJECT** SPVM_RUNTIME_API_get_object_array_elements(SPVM_API* api, SPVM_ARRAY_OBJECT* array_object) {
  (void)api;
  
  return (SPVM_BASE_OBJECT**)((intptr_t)array_object + sizeof(SPVM_ARRAY_OBJECT));
}
