/**
 * This is the standard include header. It includes all standard headers we
 * need and defines some universally usable macros.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if WANT_GLIB
#include <glib.h>
#endif

#include <memman.h>

#define PASTE(a, b) PAST_(a, b)
#define PAST_(a, b) PAS__(a, b)
#define PAS__(a, b) a##b

#define NEW(class, ...)         ({ self_type *self = mem_alloc (sizeof *self); L (class##_construct) (self, __VA_ARGS__); &self->base; })
