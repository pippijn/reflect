#pragma once

#define stack_get fast_stack_get
#define stack_set fast_stack_set
#define stack_raw fast_stack_raw

#include "stack.h"

#if defined (WANT_FAST_STACK)
#undef stack_get
#undef stack_set
#undef stack_raw
#endif
