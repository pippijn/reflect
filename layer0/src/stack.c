#include <stack.h>

#include <assert.h>

/* reallocate new stack with n slots */
static void stack_realloc (stack *self, int n);

struct stack {
  void **a;      /* the stack */
  int    top;    /* highest valid index */
  int    max;    /* max slots available */
};

stack *stack_new (void)
{
  stack *self = (stack *)malloc (sizeof (stack));

  self->a = malloc (sizeof (void *));
  self->max = 1;
  self->top = -1;

  return self;
}

void stack_delete (stack *self)
{
  assert (self != NULL);

#if STACK_VERBOSE
  printf ("max was %d\n", self->max);
#endif

  free (self->a);
  free (self);

  return;
}

void stack_push (stack *self, void *data)
{
  int *top;

  assert (self != NULL);

  top = &self->top;

  if (*top + 1 == self->max)
    stack_realloc (self, self->max * 2);

  self->a[++*top] = data;

#if STACK_VERBOSE
  printf("push %d\n", self->top);
#endif

  return;
}

void *stack_pop (stack *self)
{
  int *top;

  assert (self != NULL);
  assert (self->top >= 0);

  top = &self->top;

#if 0
  if (*top < self->max / 4)
    stack_realloc (self, self->max / 2);
#endif

#if STACK_VERBOSE
  printf("pop %d\n", self->top);
#endif

  return self->a[(*top)--];
}

void *stack_top (stack const *self)
{
  assert (self != NULL);
  assert (self->top >= 0);

  return self->a[self->top];
}

size_t stack_size (stack const *self)
{
  assert (self != NULL);

  return self->top + 1;
}

static void stack_realloc (stack *self, int n)
{
  void **p, **q, **new;

  new = malloc (sizeof (void *) * n);

  p = self->a;
  q = new;

  while (p <= self->a + self->top)
    *q++ = *p++;

  free (self->a);
  self->a = new;
  self->max = n;

#if STACK_VERBOSE
  printf ("realloc %d\n", self->max);
#endif

  return;
}
