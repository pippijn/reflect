#pragma once

#define stack fast_stack
#define stack_new fast_stack_new
#define stack_delete fast_stack_delete
#define stack_push fast_stack_push
#define stack_pop fast_stack_pop
#define stack_top fast_stack_top
#define stack_size fast_stack_size

#include <stack.h>

#if defined (WANT_FAST_STACK)
#undef stack
#undef stack_new
#undef stack_delete
#undef stack_push
#undef stack_pop
#undef stack_top
#undef stack_size
#endif
