#pragma once

#define stack cppstack
#define stack_new cppstack_new
#define stack_delete cppstack_delete
#define stack_push cppstack_push
#define stack_pop cppstack_pop
#define stack_top cppstack_top
#define stack_size cppstack_size

#include <stack.h>

#if !defined (__cplusplus) && defined (WANT_CPP_STACK)
#undef stack
#undef stack_new
#undef stack_delete
#undef stack_push
#undef stack_pop
#undef stack_top
#undef stack_size
#endif
