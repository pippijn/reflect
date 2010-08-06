#include <fast_stack.h>

#include "fast_stack.h"

static struct elem *elem_new (size_t n);
static void elem_free (struct elem *e);
static void stack_add_elem (stack *self, size_t n);
static void stack_repack (stack *self);

struct elem
{
  void        **data;   /* data */
  struct elem  *prev;   /* next elem */
  size_t        size;   /* used size */
  size_t        max;    /* max size */
};

struct stack
{
  struct elem *last;    /* the last stack block */
  size_t       size;    /* current used size */
  size_t       max;     /* max slots available */
};

/* public */

stack *
stack_new (void)
{
  stack *self = mem_alloc (sizeof (stack));

  self->last = elem_new (1);
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

  e = self->last;
  while (e)
    {
      rm = e;
      e = e->prev;
      elem_free (rm);
    }

  mem_free (self, sizeof (stack));
}

void
stack_push (stack *self, void *data)
{
  struct elem *e;

  assert (self != NULL);

  e = self->last;

  if (e->size == e->max)
    {
      stack_add_elem (self, self->size);
      e = self->last;

#if STACK_VERBOSE
      printf("after add: %d/%d\n", self->size, self->max);
#endif
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
  void *ret;
  struct elem *e;

  assert (self != NULL);
  assert (self->size > 0);

#if STACK_VERBOSE
  printf ("pop %d\n", self->size);
#endif

  e = self->last;

  self->size--;
  e->size--;
  ret = e->data[e->size];

  if (!e->size)
    {
      self->last = e->prev;
      elem_free (e);
    }

  return ret;
}

void *
stack_top (stack const *self)
{
  struct elem *e;

  assert (self != NULL);
  assert (self->size > 0);

  e = self->last;

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
  struct elem *e;
  size_t i, rindex;

  assert (self != NULL);
  assert (index < self->size);

  rindex = self->size - index;

  e = self->last;
  for (i = 0; i < rindex; i += e->size)
    e = e->prev;

  return e->data[i - rindex];
}

void *
stack_set (stack *self, size_t index, void *data)
{
  void *ret;
  struct elem *e;
  size_t i, rindex;

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
      rindex = self->size - index;

      e = self->last;
      for (i = 0; i < rindex; i += e->size)
        e = e->prev;

      ret = e->data[i - rindex];
      e->data[i - rindex] = data;
    }

  return ret;
}

void *const *
stack_raw (stack *const self)
{
  assert (self != NULL);

  stack_repack (self);

  return self->last->data;
}

/* static */

static struct elem *
elem_new (size_t n)
{
  struct elem *e;

  e = mem_alloc (sizeof (struct elem));

  e->data = mem_alloc (n * sizeof (void *));
  e->prev = NULL;
  e->size = 0;
  e->max  = n;

  return e;
}

static void
elem_free (struct elem *e)
{
  mem_free (e->data, e->max * sizeof (void *));
  mem_free (e, sizeof (struct elem));

  return;
}

static void
stack_add_elem (stack *self, size_t n)
{
  struct elem *new;

  new = elem_new (n);

  new->prev = self->last;
  self->last = new;
  self->max += n;

  return;
}

static void
stack_repack (stack *self)
{
  int i, j;
  struct elem *new, *e, *rm;

  assert (self != NULL);

  new = elem_new (self->size);

  i = self->size - 1;
  e = self->last;
  while (i >= 0)
    {
      for (j = e->size - 1; j >= 0; j--)
        new->data[i] = e->data[j];

      rm = e;
      e = e->prev;
      elem_free (rm);
    }

  self->last = new;

  return;
}
