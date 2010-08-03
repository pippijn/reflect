#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memman.h>

#define PASTE(a, b) PAST_(a, b)
#define PAST_(a, b) PAS__(a, b)
#define PAS__(a, b) a##b

#define NEW(class, ...)         ({ self_type *self = xalloc (sizeof *self); L (class##_construct) (self, __VA_ARGS__); &self->base; })
