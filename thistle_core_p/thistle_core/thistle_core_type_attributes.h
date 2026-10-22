#ifndef th_include_core_type_attributes
#define th_include_core_type_attributes
#define th_include_core_type_attributes_impl

#if __has_attribute(visibility)
#define th_attr_export __attribute__((visibility("default")))
#else
#define th_attr_export
#endif

#endif
