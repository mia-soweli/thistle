#ifndef th_include_core_type_attributes
#define th_include_core_type_attributes
#define th_include_core_type_attributes_impl

#if __has_attribute(visibility)
#define th_visibility __attribute__((visibility("default")))
#else
#define th_visibility
#endif

#if __has_attribute(always_inline)
#define th_inline inline
#define th_inline_always inline __attribute__((always_inline))
#else
#define th_inline inline
#define th_inline_always inline
#endif

#endif
