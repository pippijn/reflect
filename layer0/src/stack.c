#include <memman.h>
#include <stack.h>

#include "stack.h"

/* reallocate new stack with n slots */
static void stack_realloc (stack *self, size_t n);

struct stack {
  void **a;      /* the stack */
  size_t size;   /* current used size */
  size_t max;    /* max slots available */
};

/* public */

stack *stack_new (void)
{
  stack *self = mem_alloc (sizeof (stack));

  self->a = mem_alloc (sizeof (void *));
  self->max  = 1;
  self->size = 0;

  return self;
}

void stack_delete (stack *self)
{
  assert (self != NULL);

#if STACK_VERBOSE
  printf ("max was %d\n", self->max);
#endif

  mem_free (self->a, sizeof (void *) * self->max);
  mem_free (self, sizeof (stack));

  return;
}

void stack_push (stack *self, void *data)
{
  assert (self != NULL);

  if (self->size == self->max)
    stack_realloc (self, self->max * 2);

  assert (self->size < self->max);

  self->a[self->size] = data;
  self->size++;

#if STACK_VERBOSE
  printf("push %d\n", self->size);
#endif

  return;
}

void *stack_pop (stack *self)
{
  assert (self != NULL);
  assert (self->size > 0);

#if 0
  if (self->size < self->max / 4)
    stack_realloc (self, self->max / 2);
#endif

#if STACK_VERBOSE
  printf("pop %d\n", self->size);
#endif

  self->size--;
  return self->a[self->size];
}

void *stack_top (stack const *self)
{
  assert (self != NULL);
  assert (self->size > 0);

  return self->a[self->size - 1];
}

size_t stack_size (stack const *self)
{
  assert (self != NULL);

  return self->size;
}

/* internal only */

void *stack_get (stack const *self, size_t index)
{
  assert (self != NULL);
  assert (index < self->size);

  return self->a[index];
}

void *stack_set (stack *self, size_t index, void *data)
{
  void *ret;

  assert (self != NULL);
#if STACK_VERBOSE
  printf("setting %d/%d\n", index, self->size);
#endif

  if (index >= self->size)
    {
      ret = NULL;
    }
  else
    {
      ret = self->a[index];
      self->a[index] = data;
    }

  return ret;
}

void *const *stack_raw (stack *const self)
{
  assert (self != NULL);

  return self->a;
}

/* static */

static void stack_realloc (stack *self, size_t n)
{
  void **new;
  /*
  void **p, **q;
  */

  assert (self->size <= n);

  new = mem_alloc (sizeof (void *) * n);

  memcpy (new, self->a, sizeof (void *) * self->size);

  /*
  q = new;
  p = self->a;
  while (p < self->a + self->size)
    *q++ = *p++;
  */

  mem_free (self->a, sizeof (void *) * self->max);
  self->a = new;
  self->max = n;

#if STACK_VERBOSE
  printf ("realloc %d\n", self->max);
#endif

  return;
}
