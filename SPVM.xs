#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <stdint.h>
#include <assert.h>

#include "spvm_compiler.h"
#include "spvm_hash.h"
#include "spvm_dynamic_array.h"
#include "spvm_util_allocator.h"
#include "spvm_constant_pool.h"
#include "spvm_bytecode_array.h"
#include "spvm_runtime.h"
#include "spvm_op.h"
#include "spvm_sub.h"
#include "spvm_package.h"
#include "spvm_sub.h"
#include "spvm_my_var.h"
#include "spvm_type.h"
#include "spvm_field.h"

#include "spvm_api.h"
#include "spvm_xs_util.h"

SPVM_COMPILER* SPVM_XS_INTERNAL_UTIL_get_compiler() {

  // Get compiler
  SV* sv_compiler = get_sv("SPVM::COMPILER", 0);
  SV* sviv_compiler = SvROK(sv_compiler) ? SvRV(sv_compiler) : sv_compiler;
  size_t iv_compiler = SvIV(sviv_compiler);
  SPVM_COMPILER* compiler = INT2PTR(SPVM_COMPILER*, iv_compiler);
  
  return compiler;
}

MODULE = SPVM::Object		PACKAGE = SPVM::Object

SV*
malloc_object(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_package = ST(1);
  
  if (!SvOK(sv_package)) {
    croak("Type must be specified(SPVM::Object::malloc_object)");
  }
  
  const char* package = SvPV_nolen(sv_package);

  int32_t package_id = SPVM_XS_UTIL_get_package_id(package);
  if (package_id == SPVM_API_ERROR_NO_ID) {
    croak("Unkown package \"%s\"(SPVM::Object::malloc_object", package);
  }
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_OBJECT* object =  api->malloc_object_noinc(api, package_id);
  
  // Increment
  api->inc_ref_count(api, object);

  // New sv object
  SV* sv_object = SPVM_XS_UTIL_new_sv_object(package, object);
  
  XPUSHs(sv_object);
  XSRETURN(1);
}

SV*
set(...)
  PPCODE:
{
  SV* sv_object = ST(0);
  SV* sv_field_name = ST(1);
  SV* sv_value = ST(2);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_OBJECT* object = SPVM_XS_UTIL_get_object(sv_object);

  // Package name
  const char* package_name = SPVM_XS_UTIL_get_type(sv_object);
  
  // Field type
  const char* field_name = SvPV_nolen(sv_field_name);
  const char* field_type = SPVM_XS_UTIL_get_field_type(package_name, field_name);

  // Field id
  int32_t field_id = api->get_field_id(api, object, field_name);
  if (field_id == SPVM_API_ERROR_NO_ID) {
    croak("Can't find %s \"%s\" field(SPVM::Object::set)", package_name, field_name);
  }
  
  assert(field_type);
  
  int32_t field_type_length = strlen(field_type);
  if (strEQ(field_type, "byte")) {
    int8_t value = (int8_t)SvIV(sv_value);
    api->set_byte_field(api, object, field_id, value);
  }
  else if (strEQ(field_type, "short")) {
    int16_t value = (int16_t)SvIV(sv_value);
    api->set_short_field(api, object, field_id, value);
  }
  else if (strEQ(field_type, "int")) {
    int32_t value = (int32_t)SvIV(sv_value);
    api->set_int_field(api, object, field_id, value);
  }
  else if (strEQ(field_type, "long")) {
    int64_t value = (int64_t)SvIV(sv_value);
    api->set_long_field(api, object, field_id, value);
  }
  else if (strEQ(field_type, "float")) {
    float value = (float)SvNV(sv_value);
    api->set_float_field(api, object, field_id, value);
  }
  else if (strEQ(field_type, "double")) {
    double value = (double)SvNV(sv_value);
    api->set_double_field(api, object, field_id, value);
  }
  else {
    if (!(sv_isobject(sv_value) && sv_derived_from(sv_value, "SPVM::BaseObject"))) {
      croak("Can't set numeric value to \"%s\" field", field_type);
    }
    const char* value_type = SPVM_XS_UTIL_get_type(sv_value);
    if (!strEQ(field_type, value_type)) {
      croak("Can't set \"%s\" value to \"%s\" field", value_type, field_type);
    }
    
    SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_value);
    
    api->set_object_field(api, object, field_id, array);
  }
  
  XSRETURN(0);
}

SV*
get(...)
  PPCODE:
{
  SV* sv_object = ST(0);
  SV* sv_field_name = ST(1);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_OBJECT* object = SPVM_XS_UTIL_get_object(sv_object);

  // Package name
  const char* package_name = SPVM_XS_UTIL_get_type(sv_object);
  
  // Field type
  const char* field_name = SvPV_nolen(sv_field_name);
  const char* field_type = SPVM_XS_UTIL_get_field_type(package_name, field_name);
  
  // Field id
  int32_t field_id = api->get_field_id(api, object, field_name);
  if (field_id == SPVM_API_ERROR_NO_ID) {
    croak("Can't find %s \"%s\" field(SPVM::Object::set)", package_name, field_name);
  }
  
  if (strEQ(field_type, "byte")) {
    int8_t return_value = api->get_byte_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSViv(return_value));
    XPUSHs(sv_value);
  }
  else if (strEQ(field_type, "short")) {
    int16_t return_value = api->get_short_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSViv(return_value));
    XPUSHs(sv_value);
  }
  else if (strEQ(field_type, "int")) {
    int32_t return_value = api->get_int_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSViv(return_value));
    XPUSHs(sv_value);
  }
  else if (strEQ(field_type, "long")) {
    int64_t return_value = api->get_long_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSViv(return_value));
    XPUSHs(sv_value);
  }
  else if (strEQ(field_type, "float")) {
    float return_value = api->get_float_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSVnv(return_value));
    NV value = SvNV(sv_value);
    XPUSHs(sv_value);
  }
  else if (strEQ(field_type, "double")) {
    double return_value = api->get_double_field(api, object, field_id);
    SV* sv_value = sv_2mortal(newSVnv(return_value));
    XPUSHs(sv_value);
  }
  else {
    SPVM_API_BASE_OBJECT* return_value = api->get_object_field(api, object, field_id);
    
    int32_t field_type_length = strlen(field_type);
    if (field_type[field_type_length - 1] == ']' || strcmp(field_type, "string") == 0) {
      SV* sv_array = SPVM_XS_UTIL_new_sv_array(field_type, (SPVM_API_ARRAY*)return_value);
      XPUSHs(sv_array);
    }
    else {
      SV* sv_object = SPVM_XS_UTIL_new_sv_object(field_type, (SPVM_API_OBJECT*)return_value);
      XPUSHs(sv_object);
    }
  }
  
  XSRETURN(1);
}

MODULE = SPVM::Array		PACKAGE = SPVM::Array

SV*
malloc_byte_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_byte_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("byte[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_byte_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  int8_t* elements = api->get_byte_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (int8_t)SvIV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_short_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_short_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("short[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_short_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  int16_t* elements = api->get_short_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (int16_t)SvIV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_int_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_int_array_noinc(api, length);

  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("int[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_int_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  int32_t* elements = api->get_int_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (int32_t)SvIV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_long_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_long_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("long[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_long_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  int64_t* elements = api->get_long_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (int64_t)SvIV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_float_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_float_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("float[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_float_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  float* elements = api->get_float_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (float)SvNV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_double_array(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_length = ST(1);
  
  int32_t length = (int32_t)SvIV(sv_length);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_double_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("double[]", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

SV*
set_double_array_elements(...)
  PPCODE:
{
  SV* sv_array = ST(0);
  SV* sv_nums = ST(1);
  AV* av_nums = SvRV(sv_nums);

  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Get content
  SPVM_API_ARRAY* array = SPVM_XS_UTIL_get_array(sv_array);
  
  int32_t length = api->get_array_length(api, array);
  
  double* elements = api->get_double_array_elements(api, array);
  
  {
    int32_t i;
    for (i = 0; i < length; i++) {
      SV** sv_num_ptr = av_fetch(av_nums, i, 0);
      SV* sv_num = sv_num_ptr ? *sv_num_ptr : &PL_sv_undef;
      elements[i] = (double)SvNV(sv_num);
    }
  }
  
  XSRETURN(0);
}

SV*
malloc_string_raw(...)
  PPCODE:
{
  SV* sv_class = ST(0);
  SV* sv_string = ST(1);
  
  int32_t length = (int32_t)sv_len(sv_string);
  
  // Set API
  SPVM_API* api = SPVM_XS_UTIL_get_api();
  
  // Malloc array
  SPVM_API_ARRAY* array =  api->malloc_byte_array_noinc(api, length);
  
  // Increment reference count
  api->inc_ref_count(api, array);
  
  const char* string = SvPV_nolen(sv_string);
  int8_t* elements = api->get_byte_array_elements(api, array);
  memcpy(elements, string, length);
  
  // New sv array
  SV* sv_array = SPVM_XS_UTIL_new_sv_array("string", array);
  
  XPUSHs(sv_array);
  XSRETURN(1);
}

MODULE = SPVM		PACKAGE = SPVM

SV*
compile(...)
  PPCODE:
{
  // Create compiler
  SPVM_COMPILER* compiler = SPVM_COMPILER_new();

  // Add package
  AV* av_package_infos = get_av("SPVM::PACKAGE_INFOS", 0);
  int32_t av_package_infos_length = (int32_t)av_len(av_package_infos) + 1;
  {
    int32_t i;
    for (i = 0; i < av_package_infos_length; i++) {
      SV** sv_package_info_ptr = av_fetch(av_package_infos, i, 0);
      SV* sv_package_info = sv_package_info_ptr ? *sv_package_info_ptr : &PL_sv_undef;
      HV* hv_package_info = (HV*)SvRV(sv_package_info);
      
      // Name
      SV** sv_name_ptr = hv_fetch(hv_package_info, "name", strlen("name"), 0);
      SV* sv_name = sv_name_ptr ? *sv_name_ptr : &PL_sv_undef;
      const char* name = SvPV_nolen(sv_name);
      
      // File
      SV** sv_file_ptr = hv_fetch(hv_package_info, "file", strlen("file"), 0);
      SV* sv_file = sv_file_ptr ? *sv_file_ptr : &PL_sv_undef;
      const char* file = SvPV_nolen(sv_file);
      
      // Line
      SV** sv_line_ptr = hv_fetch(hv_package_info, "line", strlen("line"), 0);
      SV* sv_line = sv_line_ptr ? *sv_line_ptr : &PL_sv_undef;
      int32_t line = (int32_t)SvIV(sv_line);
      
      // push package to compiler use stack
      SPVM_OP* op_use_package = SPVM_OP_new_op_use_from_package_name(compiler, name, file, line);
      SPVM_DYNAMIC_ARRAY_push(compiler->op_use_stack, op_use_package);
      SPVM_HASH_insert(compiler->op_use_symtable, name, strlen(name), op_use_package);
    }
  }
  
  // Add include paths
  AV* av_include_paths = get_av("main::INC", 0);;
  int32_t av_include_paths_length = (int32_t)av_len(av_include_paths) + 1;
  {
    int32_t i;
    for (i = 0; i < av_include_paths_length; i++) {
      SV** sv_include_path_ptr = av_fetch(av_include_paths, i, 0);
      SV* sv_include_path = sv_include_path_ptr ? *sv_include_path_ptr : &PL_sv_undef;
      char* include_path = SvPV_nolen(sv_include_path);
      SPVM_DYNAMIC_ARRAY_push(compiler->include_pathes, include_path);
    }
  }
  
  // Compile SPVM
  SPVM_COMPILER_compile(compiler);
  if (compiler->error_count > 0) {
    croak("SPVM compile error %d", compiler->error_count);
  }
  
  // Set compiler
  size_t iv_compiler = PTR2IV(compiler);
  SV* sviv_compiler = sv_2mortal(newSViv(iv_compiler));
  SV* sv_compiler = sv_2mortal(newRV_inc(sviv_compiler));
  sv_setsv(get_sv("SPVM::COMPILER", 0), sv_compiler);
  
  XSRETURN(0);
}

SV*
build_sub_symtable(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Subroutine information
  HV* hv_sub_symtable = get_hv("SPVM::SUB_SYMTABLE", 0);
  
  // abs_name, arg_types, return_type, id, type_id
  SPVM_DYNAMIC_ARRAY* op_packages = compiler->op_packages;
  {
    int32_t package_index;
    for (package_index = 0; package_index < op_packages->length; package_index++) {
      SPVM_OP* op_package = SPVM_DYNAMIC_ARRAY_fetch(op_packages, package_index);
      SPVM_DYNAMIC_ARRAY* op_subs = op_package->uv.package->op_subs;
      {
        int32_t sub_index;
        for (sub_index = 0; sub_index < op_subs->length; sub_index++) {
          // Sub information
          HV* hv_sub_info = (HV*)sv_2mortal((SV*)newHV());
          
          SPVM_OP* op_sub = SPVM_DYNAMIC_ARRAY_fetch(op_subs, sub_index);
          SPVM_SUB* sub = op_sub->uv.sub;
          const char* sub_abs_name = sub->abs_name;
          
          // Subroutine id
          int32_t sub_id = sub->constant_pool_index;
          SV* sv_sub_id = sv_2mortal(newSViv(sub_id));
          hv_store(hv_sub_info, "id", strlen("id"), SvREFCNT_inc(sv_sub_id), 0);
          
          // Argument types
          AV* av_arg_type_names = (AV*)sv_2mortal((SV*)newAV());
          SPVM_DYNAMIC_ARRAY* op_args = sub->op_args;
          {
            int32_t arg_index;
            for (arg_index = 0; arg_index < op_args->length; arg_index++) {
              SPVM_OP* op_arg = SPVM_DYNAMIC_ARRAY_fetch(op_args, arg_index);
              SPVM_OP* op_arg_type = op_arg->uv.my_var->op_type;
              const char* arg_type_name = op_arg_type->uv.type->name;
              
              SV* sv_arg_type_name = sv_2mortal(newSVpv(arg_type_name, 0));
              av_push(av_arg_type_names, SvREFCNT_inc(sv_arg_type_name));
            }
          }
          SV* sv_arg_type_names = sv_2mortal(newRV_inc((SV*)av_arg_type_names));
          hv_store(hv_sub_info, "arg_types", strlen("arg_types"), SvREFCNT_inc(sv_arg_type_names), 0);
          
          // Return type
          SPVM_OP* op_return_type = sub->op_return_type;
          SPVM_TYPE* return_type = SPVM_OP_get_type(compiler, op_return_type);
          if (return_type) {
            const char* return_type = op_return_type->uv.type->name;
            SV* sv_return_type = sv_2mortal(newSVpv(return_type, 0));
            hv_store(hv_sub_info, "return_type", strlen("return_type"), SvREFCNT_inc(sv_return_type), 0);
          }
          else {
            hv_store(hv_sub_info, "return_type", strlen("return_type"), &PL_sv_undef, 0);
          }
          
          SV* sv_sub_info = sv_2mortal(newRV_inc((SV*)hv_sub_info));
          hv_store(hv_sub_symtable, sub_abs_name, strlen(sub_abs_name), SvREFCNT_inc(sv_sub_info), 0);
        }
      }
    }
  }
  
  XSRETURN(0);
}

SV*
build_type_symtable(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Subroutine information
  HV* hv_type_symtable = get_hv("SPVM::TYPE_SYMTABLE", 0);
  
  // abs_name, arg_types, return_type, id, type_id
  SPVM_DYNAMIC_ARRAY* types = compiler->types;
  {
    int32_t type_id;
    for (type_id = 0; type_id < types->length; type_id++) {
      SPVM_TYPE* type = SPVM_DYNAMIC_ARRAY_fetch(types, type_id);
      
      const char* type_name = type->name;
      int32_t type_id = type->id;
      SV* sv_type_id = sv_2mortal(newSViv(type_id));
      
      HV* hv_type_info = (HV*)sv_2mortal((SV*)newHV());
      hv_store(hv_type_info, "id", strlen("id"), SvREFCNT_inc(sv_type_id), 0);
      SV* sv_type_info = sv_2mortal(newRV_inc((SV*)hv_type_info));
      
      hv_store(hv_type_symtable, type_name, strlen(type_name), SvREFCNT_inc(sv_type_info), 0);
    }
  }
  
  XSRETURN(0);
}

SV*
build_package_symtable(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Subroutine information
  HV* hv_package_symtable = get_hv("SPVM::PACKAGE_SYMTABLE", 0);
  
  // abs_name, arg_packages, return_package, id, package_id
  SPVM_DYNAMIC_ARRAY* op_packages = compiler->op_packages;
  {
    int32_t package_index;
    for (package_index = 0; package_index < op_packages->length; package_index++) {
      SPVM_OP* op_package = SPVM_DYNAMIC_ARRAY_fetch(op_packages, package_index);
      SPVM_PACKAGE* package = op_package->uv.package;
      
      const char* package_name = package->op_name->uv.name;
      int32_t package_id = package->constant_pool_index;
      SV* sv_package_id = sv_2mortal(newSViv(package_id));
      
      HV* hv_package_info = (HV*)sv_2mortal((SV*)newHV());
      hv_store(hv_package_info, "id", strlen("id"), SvREFCNT_inc(sv_package_id), 0);
      SV* sv_package_info = sv_2mortal(newRV_inc((SV*)hv_package_info));

      hv_store(hv_package_symtable, package_name, strlen(package_name), SvREFCNT_inc(sv_package_info), 0);
    }
  }
  
  XSRETURN(0);
}

SV*
build_field_symtable(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Field symbol table
  HV* hv_field_symtable = get_hv("SPVM::FIELD_SYMTABLE", 0);
  
  // name, arg_types, return_type
  SPVM_DYNAMIC_ARRAY* op_packages = compiler->op_packages;
  {
    int32_t package_index;
    for (package_index = 0; package_index < op_packages->length; package_index++) {
      SPVM_OP* op_package = SPVM_DYNAMIC_ARRAY_fetch(op_packages, package_index);
      const char* package_name = op_package->uv.package->op_name->uv.name;
      
      HV* hv_package_info = (HV*)sv_2mortal((SV*)newHV());
      
      SPVM_DYNAMIC_ARRAY* op_fields = op_package->uv.package->op_fields;
      {
        int32_t field_index;
        for (field_index = 0; field_index < op_fields->length; field_index++) {
          SPVM_OP* op_field = SPVM_DYNAMIC_ARRAY_fetch(op_fields, field_index);
          SPVM_FIELD* field = op_field->uv.field;
          const char* field_name = field->op_name->uv.name;
          
          // Field type
          const char* field_type = field->op_type->uv.type->name;
          SV* sv_field_type = sv_2mortal(newSVpv(field_type, 0));
          
          // Field id
          int32_t field_id = field->index;
          SV* sv_field_id = sv_2mortal(newSViv(field_id));
          
          HV* hv_field_info = (HV*)sv_2mortal((SV*)newHV());
          hv_store(hv_field_info, "type", strlen("type"), SvREFCNT_inc(sv_field_type), 0);
          hv_store(hv_field_info, "id", strlen("id"), SvREFCNT_inc(sv_field_id), 0);
          SV* sv_field_info = sv_2mortal(newRV_inc((SV*)hv_field_info));
          
          hv_store(hv_package_info, field_name, strlen(field_name), SvREFCNT_inc(sv_field_info), 0);
        }
      }
      
      SV* sv_package_info = sv_2mortal(newRV_inc((SV*)hv_package_info));
      hv_store(hv_field_symtable, package_name, strlen(package_name), SvREFCNT_inc(sv_package_info), 0);
    }
  }
  
  XSRETURN(0);
}

SV*
build_runtime(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Create run-time
  SPVM_RUNTIME* runtime = SPVM_COMPILER_new_runtime(compiler);
  
  // SPVM API
  SPVM_API* api = runtime->api;
  size_t iv_api = PTR2IV(api);
  SV* sviv_api = sv_2mortal(newSViv(iv_api));
  SV* sv_api = sv_2mortal(newRV_inc(sviv_api));
  sv_setsv(get_sv("SPVM::API", 0), sv_api);
  
  XSRETURN(0);
}

SV*
free_compiler(...)
  PPCODE:
{
  // Get compiler
  SPVM_COMPILER* compiler = SPVM_XS_INTERNAL_UTIL_get_compiler();
  
  // Free compiler
  SPVM_COMPILER_free(compiler);
  
  // Set undef to compiler
  sv_setsv(get_sv("SPVM::COMPILER", 0), &PL_sv_undef);
  
  XSRETURN(0);
}

SV*
call_sub(...)
  PPCODE:
{
  SV* sv_sub_abs_name = ST(0);
  
  HV* hv_sub_symtable = get_hv("SPVM::SUB_SYMTABLE", 0);
  
  const char* sub_abs_name = SvPV_nolen(sv_sub_abs_name);
  SV** sv_sub_info_ptr = hv_fetch(hv_sub_symtable, sub_abs_name, strlen(sub_abs_name), 0);
  SV* sv_sub_info = sv_sub_info_ptr ? *sv_sub_info_ptr : &PL_sv_undef;
  HV* hv_sub_info = (HV*)SvRV(sv_sub_info);
  
  // Subroutine id
  SV** sv_sub_id_ptr = hv_fetch(hv_sub_info, "id", strlen("id"), 0);
  SV* sv_sub_id = sv_sub_id_ptr ? *sv_sub_id_ptr : &PL_sv_undef;
  int32_t sub_id = (int32_t)SvIV(sv_sub_id);
  
  // Argument types
  SV** sv_arg_type_names_ptr = hv_fetch(hv_sub_info, "arg_types", strlen("arg_types"), 0);
  SV* sv_arg_type_names = sv_arg_type_names_ptr ? *sv_arg_type_names_ptr : &PL_sv_undef;
  AV* av_arg_type_names = (AV*)SvRV(sv_arg_type_names);
  int32_t args_length = av_len(av_arg_type_names) + 1;
  
  // Return type
  SV** sv_return_type_ptr = hv_fetch(hv_sub_info, "return_type", strlen("return_type"), 0);
  SV* sv_return_type = sv_return_type_ptr ? *sv_return_type_ptr : &PL_sv_undef;
  
  // Get API
  SV* sv_api = get_sv("SPVM::API", 0);
  SV* sviv_api = SvROK(sv_api) ? SvRV(sv_api) : sv_api;
  size_t iv_api = SvIV(sviv_api);
  SPVM_API* api = INT2PTR(SPVM_API*, iv_api);
  
  // Check argument count
  if (items - 1 != args_length) {
    croak("Argument count is defferent");
  }
  
  // Push arguments
  {
    int32_t arg_index;
    for (arg_index = 0; arg_index < args_length; arg_index++) {
      SV* sv_base_object = ST(arg_index + 1);
      
      SV** sv_arg_type_name_ptr = av_fetch(av_arg_type_names, arg_index, 0);
      SV* sv_arg_type_name = sv_arg_type_name_ptr ? *sv_arg_type_name_ptr : &PL_sv_undef;
      const char* arg_type_name = SvPV_nolen(sv_arg_type_name);
      
      if (sv_isobject(sv_base_object) && sv_derived_from(sv_base_object, "SPVM::BaseObject")) {
        
        HV* hv_base_object = (HV*)SvRV(sv_base_object);
        
        SV** sv_base_object_type_name_ptr = hv_fetch(hv_base_object, "type", strlen("type"), 0);
        SV* sv_base_object_type_name = sv_base_object_type_name_ptr ? *sv_base_object_type_name_ptr : &PL_sv_undef;
        const char* base_object_type_name = SvPV_nolen(sv_base_object_type_name);
        
        if (!strEQ(base_object_type_name, arg_type_name)) {
          croak("Argument base_object type need %s, but %s", arg_type_name, base_object_type_name);
        }
        
        // Get content
        SV** sv_content_ptr = hv_fetch(hv_base_object, "content", strlen("content"), 0);
        SV* sv_content = sv_content_ptr ? *sv_content_ptr : &PL_sv_undef;
        SV* sviv_content = SvRV(sv_content);
        size_t iv_content = SvIV(sviv_content);
        SPVM_API_BASE_OBJECT* base_object = INT2PTR(SPVM_API_BASE_OBJECT*, iv_content);
        
        api->push_var_object(api, base_object);
      }
      else {
        SV* sv_value = sv_base_object;
        if (strEQ(arg_type_name, "byte")) {
          int8_t value = (int8_t)SvIV(sv_value);
          api->push_var_byte(api, value);
        }
        else if (strEQ(arg_type_name, "short")) {
          int16_t value = (int16_t)SvIV(sv_value);
          api->push_var_short(api, value);
        }
        else if (strEQ(arg_type_name, "int")) {
          int32_t value = (int32_t)SvIV(sv_value);
          api->push_var_int(api, value);
        }
        else if (strEQ(arg_type_name, "long")) {
          int64_t value = (int64_t)SvIV(sv_value);
          api->push_var_long(api, value);
        }
        else if (strEQ(arg_type_name, "float")) {
          float value = (float)SvNV(sv_value);
          api->push_var_float(api, value);
        }
        else if (strEQ(arg_type_name, "double")) {
          double value = (double)SvNV(sv_value);
          api->push_var_double(api, value);
        }
        else {
          assert(0);
        }
      }
    }
  }
  
  api->call_sub(api, sub_id);
  
  SPVM_API_ARRAY* exception = api->get_exception(api);
  if (exception) {
    croak("Exception occur(%s)", sub_abs_name);
    XSRETURN(0);
  }
  
  if (SvOK(sv_return_type)) {
    // Create base_object
    HV* hv_base_object = sv_2mortal((SV*)newHV());
    SV* sv_base_object = sv_2mortal(newRV_inc((SV*)hv_base_object));
    HV* hv_class = gv_stashpv("SPVM::Object", 0);
    sv_bless(sv_base_object, hv_class);
    
    const char* return_type = SvPV_nolen(sv_return_type);
    
    if (strEQ(return_type, "byte")) {
      int8_t return_value = api->pop_retval_byte(api);
      SV* sv_value = sv_2mortal(newSViv(return_value));
      XPUSHs(sv_value);
    }
    else if (strEQ(return_type, "short")) {
      int16_t return_value = api->pop_retval_short(api);
      SV* sv_value = sv_2mortal(newSViv(return_value));
      XPUSHs(sv_value);
    }
    else if (strEQ(return_type, "int")) {
      int32_t return_value = api->pop_retval_int(api);
      SV* sv_value = sv_2mortal(newSViv(return_value));
      XPUSHs(sv_value);
    }
    else if (strEQ(return_type, "long")) {
      int64_t return_value = api->pop_retval_long(api);
      SV* sv_value = sv_2mortal(newSViv(return_value));
      XPUSHs(sv_value);
    }
    else if (strEQ(return_type, "float")) {
      float return_value = api->pop_retval_float(api);
      SV* sv_value = sv_2mortal(newSVnv(return_value));
      NV value = SvNV(sv_value);
      XPUSHs(sv_value);
    }
    else if (strEQ(return_type, "double")) {
      double return_value = api->pop_retval_double(api);
      SV* sv_value = sv_2mortal(newSVnv(return_value));
      XPUSHs(sv_value);
    }
    else {
      SPVM_API_BASE_OBJECT* return_value = api->pop_retval_object(api);
      
      int32_t type_length = strlen(return_type);
      if (return_type[type_length - 1] == ']' || strcmp(return_type, "string") == 0) {
        SV* sv_array = SPVM_XS_UTIL_new_sv_array(return_type, (SPVM_API_ARRAY*)return_value);
        XPUSHs(sv_array);
      }
      else {
        SV* sv_object = SPVM_XS_UTIL_new_sv_object(return_type, (SPVM_API_OBJECT*)return_value);
        XPUSHs(sv_object);
      }
    }
    XSRETURN(1);
  }
  else {
    XSRETURN(0);
  }
}
