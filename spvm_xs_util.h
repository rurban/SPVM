#ifndef SPVM_XS_UTIL_H
#define SPVM_XS_UTIL_H

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "spvm_api.h"

#include <stdint.h>

SPVM_API* SPVM_XS_UTIL_get_api() {
  SV* sv_api = get_sv("SPVM::API", 0);
  SV* sviv_api = SvRV(sv_api);
  size_t iv_api = SvIV(sviv_api);
  
  SPVM_API* api = INT2PTR(SPVM_API*, iv_api);
  
  return api;
}

SV* SPVM_XS_UTIL_new_sv_array(const char* type, SPVM_API_ARRAY* array) {
  // Create array
  HV* hv_array = sv_2mortal((SV*)newHV());
  SV* sv_array = sv_2mortal(newRV_inc((SV*)hv_array));
  HV* hv_class = gv_stashpv("SPVM::Array", 0);
  sv_bless(sv_array, hv_class);
  
  // Create content
  size_t iv_content = PTR2IV(array);
  SV* sviv_content = sv_2mortal(newSViv(iv_content));
  SV* sv_content = sv_2mortal(newRV_inc(sviv_content));
  
  // Set content
  hv_store(hv_array, "content", strlen("content"), SvREFCNT_inc(sv_content), 0);
  
  // Set type
  SV* sv_type = sv_2mortal(newSVpv(type, 0));
  hv_store(hv_array, "type", strlen("type"), SvREFCNT_inc(sv_type), 0);
  
  return sv_array;
}

SV* SPVM_XS_UTIL_new_sv_object(const char* type, SPVM_API_OBJECT* object) {
  // Create object
  HV* hv_object = sv_2mortal((SV*)newHV());
  SV* sv_object = sv_2mortal(newRV_inc((SV*)hv_object));
  HV* hv_class = gv_stashpv("SPVM::Object", 0);
  sv_bless(sv_object, hv_class);
  
  // Create content
  size_t iv_content = PTR2IV(object);
  SV* sviv_content = sv_2mortal(newSViv(iv_content));
  SV* sv_content = sv_2mortal(newRV_inc(sviv_content));
  
  // Set content
  hv_store(hv_object, "content", strlen("content"), SvREFCNT_inc(sv_content), 0);
  
  // Set type
  SV* sv_type = sv_2mortal(newSVpv(type, 0));
  hv_store(hv_object, "type", strlen("type"), SvREFCNT_inc(sv_type), 0);
  
  return sv_object;
}

SPVM_API_ARRAY* SPVM_XS_UTIL_get_array(SV* sv_array) {
  
  HV* hv_array = (HV*)SvRV(sv_array);
  SV** sv_content_ptr = hv_fetch(hv_array, "content", strlen("content"), 0);
  SV* sv_content = sv_content_ptr ? *sv_content_ptr : &PL_sv_undef;
  SV* sviv_content = SvRV(sv_content);
  size_t iv_content = SvIV(sviv_content);
  SPVM_API_ARRAY* array = INT2PTR(SPVM_API_ARRAY*, iv_content);
  
  return array;
}

int32_t SPVM_XS_UTIL_search_type_id(const char* type) {
  HV* hv_type_symtable = get_hv("SPVM::TYPE_SYMTABLE", 0);

  SV** sv_type_ptr = hv_fetch(hv_type_symtable, type, strlen(type), 0);
  if (sv_type_ptr) {
    SV* sv_type = *sv_type_ptr;
    int32_t type_id = (int32_t)SvIV(sv_type);
    return type_id;
  }
  else {
    return -1;
  }
  
  return 1;
}

#endif