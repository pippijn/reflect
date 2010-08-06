#include <memman.h>
#include <fast_stack.h>

#include "fast_stack.h"

/* reallocate new stack with n slots */
static struct elem *elem_new (size_t n);
static void stack_add_elem (stack *self, struct elem *last, size_t n);

struct elem
{
  void        **data;   /* data */
  struct elem  *next;   /* next elem */
  size_t        size;   /* used size */
  size_t        max;    /* max size */
};

struct stack
{
  struct elem *first;   /* the stack */
  size_t       size;    /* current used size */
  size_t       max;     /* max slots available */
};

/* public */

stack *
stack_new (void)
{
  stack *self = mem_alloc (sizeof (stack));

  self->first = elem_new (1);
  self->max  = 1;
  self->size = 0;

  return self;
}

void
stack_delete (stack *self)
{
  struct elem *rm, *e;

  assert (self != NULL);

#if STACK_VERBOSE
  printf ("max was %d\n", self->max);
#endif

  e = self->first;
  while (e)
    {
      rm = e;
      e = e->next;
      mem_free (rm, rm->max * sizeof (void *));
    }

  mem_free (self, sizeof (stack));
}

void
stack_push (stack *self, void *data)
{
  struct elem *e;

  assert (self != NULL);

  e = self->first;
  while (e->size == e->max && e->next)
    e = e->next;

  if (e->size == e->max)
    {
      stack_add_elem (self, e, e->max * 2);
      e = e->next;
    }

  assert (self->size < self->max);

  e->data[e->size] = data;
  e->size++;
  self->size++;

#if STACK_VERBOSE
  printf ("push %d\n", self->size);
#endif
}

void *
stack_pop (stack *self)
{
  struct elem *e;

  assert (self != NULL);
  assert (self->size > 0);

#if 0
  if (self->size < self->max / 4)
    stack_realloc (self, self->max / 2);
#endif

#if STACK_VERBOSE
  printf ("pop %d\n", self->size);
#endif

  e = self->first;
  while (e->size == e->max && e->next)
    if (e->next->size)
      e = e->next;

  self->size--;
  e->size--;

  return e->data[e->size];
}

void *
stack_top (stack const *self)
{
  struct elem *e;

  assert (self != NULL);
  assert (self->size > 0);

  e = self->first;
  while (e->size == e->max && e->next)
    e = e->next;

  return e->data[e->size - 1];
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
  size_t i;
  struct elem *e;

  assert (self != NULL);
  assert (index < self->size);

  e = self->first;
  for (i = 0; i < index; i += e->size)
    e = e->next;

  i -= e->size;

  return e->data[index - i];
}

void *
stack_set (stack *self, size_t index, void *data)
{
  size_t i;
  void *ret;
  struct elem *e;

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
      e = self->first;
      for (i = 0; i < index; i += e->size)
        e = e->next;

      i -= e->size;

      ret = e->data[index - i];
      e->data[index - i] = data;
    }

  return ret;
}

void *const *
stack_raw (stack *const self)
{
  assert (self != NULL);

  return self->first->data;
}

/* static */

static struct elem *
elem_new (size_t n)
{
  struct elem *e;

  e = mem_alloc (sizeof (struct elem));

  e->data = mem_alloc (n * sizeof (void *));
  e->next = NULL;
  e->size = 0;
  e->max  = n;

  return e;
}

static void
stack_add_elem (stack *self, struct elem *last, size_t n)
{
  struct elem *new;

  new = elem_new (n);

  last->next = new;
  self->max += n;
}
