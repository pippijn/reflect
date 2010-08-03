#include <array_stack.h>

struct array_stack
{
  char dummy;
};


array_stack *
array_stack_new (void)
{
  assert (!"unimplemented");
}

void
array_stack_delete (array_stack *self)
{
  assert (!"unimplemented");
}


void
array_stack_push (array_stack *self, void *data)
{
  assert (!"unimplemented");
}

void *
array_stack_pop (array_stack *self)
{
  assert (!"unimplemented");
}

void *
array_stack_first (array_stack const *self)
{
  assert (!"unimplemented");
}

void *
array_stack_last (array_stack const *self)
{
  assert (!"unimplemented");
}

void *
array_stack_set (array_stack *self, size_t index, void *data)
{
  assert (!"unimplemented");
}

void *
array_stack_get (array_stack *self, size_t index)
{
  assert (!"unimplemented");
}

size_t
array_stack_size (array_stack const *self)
{
  assert (!"unimplemented");
}


void
array_stack_push_level (array_stack *self)
{
  assert (!"unimplemented");
}

void **
array_stack_pop_level (array_stack *self)
{
  assert (!"unimplemented");
}

void **
array_stack_last_level (array_stack const *self)
{
  assert (!"unimplemented");
}

size_t
array_stack_levels (array_stack const *self)
{
  assert (!"unimplemented");
}
