#include <stack.h>

#include "stack.h"

/* reallocate new stack with n slots */
static void stack_realloc (stack *self, size_t n);

struct stack
{
  void **data;  /* the stack */
  size_t size;  /* current used size */
  size_t max;   /* max slots available */
};

/* public */

stack *
stack_new (void)
{
  stack *self = mem_alloc (sizeof (stack));

  self->data = mem_alloc (sizeof (void *));
  self->max  = 1;
  self->size = 0;

  return self;
}

void
stack_delete (stack *self)
{
  assert (self != NULL);

#if STACK_VERBOSE
  printf ("max was %d\n", self->max);
#endif

  mem_free (self->data, self->max * sizeof (void *));
  mem_free (self, sizeof (stack));
}

void
stack_push (stack *self, void *data)
{
  assert (self != NULL);

  if (self->size == self->max)
    stack_realloc (self, self->max * 2);

  assert (self->size < self->max);

  self->data[self->size] = data;
  self->size++;

#if STACK_VERBOSE
  printf ("push %d\n", self->size);
#endif
}

void *
stack_pop (stack *self)
{
  assert (self != NULL);
  assert (self->size > 0);

#if 0
  if (self->size < self->max / 4)
    stack_realloc (self, self->max / 2);
#endif

#if STACK_VERBOSE
  printf ("pop %d\n", self->size);
#endif

  self->size--;
  return self->data[self->size];
}

void *
stack_top (stack const *self)
{
  assert (self != NULL);
  assert (self->size > 0);

  return self->data[self->size - 1];
}

size_t
stack_size (stack const *self)
{
  assert (self != NULL);

  return self->size;
}

/* internal only */

void *
stack_get (stack const *self, size_t index)
{
  assert (self != NULL);
  assert (index < self->size);

  return self->data[index];
}

void *
stack_set (stack *self, size_t index, void *data)
{
  void *ret;

  assert (self != NULL);
#if STACK_VERBOSE
  printf ("setting %d/%d\n", index, self->size);
#endif

  if (index >= self->size)
    {
      ret = NULL;
    }
  else
    {
      ret = self->data[index];
      self->data[index] = data;
    }

  return ret;
}

void *const *
stack_raw (stack *const self)
{
  assert (self != NULL);

  return self->data;
}

/* static */

static void
stack_realloc (stack *self, size_t n)
{
  void **new;
#if 0
  void **p, **q;
#endif

  assert (self->size <= n);

  new = mem_alloc (n * sizeof (void *));

  memcpy (new, self->data, self->size * sizeof (void *));

#if 0
  q = new;
  p = self->data;
  while (p < self->data + self->size)
    *q++ = *p++;
#endif

  mem_free (self->data, self->max * sizeof (void *));
  self->data = new;
  self->max = n;

#if STACK_VERBOSE
  printf ("realloc %d\n", self->max);
#endif
}
