#include <array_stack.h>
#include <memman.h>
#include <stack.h>

#include "stack.h"

struct array_stack
{
  stack *arrays;        /* the stack of arrays, each being another stack */
  size_t levels;        /* number of levels */
};

array_stack *
array_stack_new (void)
{
  array_stack *self = mem_alloc (sizeof (array_stack));

  self->arrays = stack_new ();
  self->levels = 0;

  return self;
}

void
array_stack_delete (array_stack *self)
{
  assert (self != NULL);

  while (stack_size (self->arrays))
    stack_delete (stack_pop (self->arrays));

  stack_delete (self->arrays);
  mem_free (self, sizeof (array_stack));
}

void
array_stack_push (array_stack *self, void *data)
{
  assert (self != NULL);
  assert (self->levels > 0);

#if ARRAY_STACK_VERBOSE
  printf ("level %zd push %zd\n", self->levels, stack_size (
            stack_get (self->arrays, self->levels - 1)));
#endif
  stack_push (stack_get (self->arrays, self->levels - 1), data);
}

void *
array_stack_pop (array_stack *self)
{
  assert (self != NULL);
  assert (self->levels > 0);

#if ARRAY_STACK_VERBOSE
  printf ("level %zd pop\n", self->levels);
#endif
  return stack_pop (stack_get (self->arrays, self->levels - 1));
}

void *
array_stack_first (array_stack const *self)
{
  assert (self != NULL);
  assert (self->levels > 0);
  assert (stack_size (stack_get (self->arrays, self->levels - 1)) > 0);

  return stack_get (stack_get (self->arrays, self->levels - 1), 0);
}

void *
array_stack_last (array_stack const *self)
{
  assert (self != NULL);
  assert (self->levels > 0);
  assert (stack_size (stack_get (self->arrays, self->levels - 1)) > 0);

  return stack_top (stack_get (self->arrays, self->levels - 1));
}

void *
array_stack_set (array_stack *self, size_t index, void *data)
{
  void *ret;
  int levels;

  assert (self != NULL);
  assert (self->levels > 0);

  levels = self->levels;

  if (stack_size (stack_get (self->arrays, levels - 1)) <= index)
    {
#if ARRAY_STACK_VERBOSE
      printf ("NULLret @ size %d\n", stack_size (stack_get (self->arrays, levels - 1)));
#endif
      ret = NULL;
    }
  else
    {
      ret = stack_get (stack_get (self->arrays, levels - 1), index);
      stack_set (stack_get (self->arrays, levels - 1), index, data);
    }

  return ret;
}

void *
array_stack_get (array_stack *self, size_t index)
{
  assert (self != NULL);
  assert (self->levels > 0);
  assert (stack_size (stack_get (self->arrays, self->levels - 1)) > index);

  return stack_get (stack_get (self->arrays, self->levels - 1), index);
}

size_t
array_stack_size (array_stack const *self)
{
  assert (self != NULL);
  assert (self->levels > 0);

  return stack_size (stack_get (self->arrays, self->levels - 1));
}

void
array_stack_push_level (array_stack *self)
{
  assert (self != NULL);

  if (self->levels < stack_size (self->arrays))
    { /* replace the old array */
      stack_delete (stack_get (self->arrays, self->levels));
      stack_set (self->arrays, self->levels, stack_new ());
    }
  else
    { /* push a new one */
      stack_push (self->arrays, stack_new ());
    }

  self->levels++;
}

void *const *
array_stack_pop_level (array_stack *self)
{
  assert (self != NULL);
  assert (self->levels > 0);
#if 0
  assert (stack_size (stack_get (self->arrays, self->levels - 1)) > 0);
#endif

  return stack_raw (stack_get (self->arrays, --self->levels));
}

void *const *
array_stack_last_level (array_stack const *self)
{
  assert (self != NULL);
  assert (self->levels > 0);
  assert (stack_size (stack_get (self->arrays, self->levels - 1)) > 0);

  return stack_raw (stack_get (self->arrays, self->levels - 1));
}

size_t
array_stack_levels (array_stack const *self)
{
  return self->levels;
}
