#pragma once

#define array_stack cpparray_stack
#define array_stack_new cpparray_stack_new
#define array_stack_delete cpparray_stack_delete
#define array_stack_push cpparray_stack_push
#define array_stack_pop cpparray_stack_pop
#define array_stack_first cpparray_stack_first
#define array_stack_last cpparray_stack_last
#define array_stack_set cpparray_stack_set
#define array_stack_get cpparray_stack_get
#define array_stack_size cpparray_stack_size
#define array_stack_push_level cpparray_stack_push_level
#define array_stack_pop_level cpparray_stack_pop_level
#define array_stack_last_level cpparray_stack_last_level
#define array_stack_levels cpparray_stack_levels

#include <array_stack.h>

#if !defined (__cplusplus) && defined (WANT_CPP_STACK)
#undef array_stack
#undef array_stack_new
#undef array_stack_delete
#undef array_stack_push
#undef array_stack_pop
#undef array_stack_first
#undef array_stack_last
#undef array_stack_set
#undef array_stack_get
#undef array_stack_size
#undef array_stack_push_level
#undef array_stack_pop_level
#undef array_stack_last_level
#undef array_stack_levels
#endif
