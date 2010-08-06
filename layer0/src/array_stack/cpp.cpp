#include <array_stack/impl_cpp.h>
#include <array_stack.h>

#include <vector>

struct array_stack
{
  std::vector<std::vector<void*>> data;
};

/*
 * private
 */

/**
 * Ensures that the array on the current level has at least size elements.
 */
static void
array_stack_ensure (array_stack *self, size_t index)
{
  assert (self != NULL);
  if (self->data.empty ())
    self->data.emplace_back ();
  if (index != (size_t)-1)
    if (self->data.back ().size () < index + 1)
      self->data.back ().resize (index + 1);
}


/*
 * public
 */

array_stack *
array_stack_new (void)
{
  return new array_stack;
}

void
array_stack_delete (array_stack *self)
{
  assert (self != NULL);
  delete self;
}


void
array_stack_push (array_stack *self, void *data)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  self->data.back ().push_back (data);
}

void *
array_stack_pop (array_stack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  void *data = self->data.back ().back ();
  self->data.back ().pop_back ();
  return data;
}

void *
array_stack_first (array_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  return self->data.back ().front ();
}

void *
array_stack_last (array_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  return self->data.back ().back ();
}

void *
array_stack_set (array_stack *self, size_t index, void *data)
{
  assert (self != NULL);
  array_stack_ensure (self, index);
  void *prev = self->data.back ().back ();
  self->data.back ().back () = data;
  return prev;
}

void *
array_stack_get (array_stack *self, size_t index)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (index < self->data.back ().size ());
  return self->data.back ().at (index);
}

size_t
array_stack_size (array_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  return self->data.back ().size ();
}


void
array_stack_push_level (array_stack *self)
{
  assert (self != NULL);
  self->data.emplace_back ();
}

/*
 * XXX: this implementation is incorrect because of std::vector deleting the
 * top vector on pop_back
 */
void *const *
array_stack_pop_level (array_stack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  self->data.pop_back ();
  return NULL;
}

void *const *
array_stack_last_level (array_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());

  if (self->data.back ().empty ())
    return NULL;

  return &self->data.back ()[0];
}

size_t
array_stack_levels (array_stack const *self)
{
  assert (self != NULL);
  return self->data.size ();
}
