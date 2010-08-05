#include <cpparray_stack.h>

#include <vector>

struct cpparray_stack
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
cpparray_stack_ensure (cpparray_stack *self, size_t index)
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

cpparray_stack *
cpparray_stack_new (void)
{
  return new cpparray_stack;
}

void
cpparray_stack_delete (cpparray_stack *self)
{
  assert (self != NULL);
  delete self;
}


void
cpparray_stack_push (cpparray_stack *self, void *data)
{
  assert (self != NULL);
  cpparray_stack_ensure (self, -1);
  self->data.back ().push_back (data);
}

void *
cpparray_stack_pop (cpparray_stack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  void *data = self->data.back ().back ();
  self->data.back ().pop_back ();
  return data;
}

void *
cpparray_stack_first (cpparray_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  return self->data.back ().front ();
}

void *
cpparray_stack_last (cpparray_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  return self->data.back ().back ();
}

void *
cpparray_stack_set (cpparray_stack *self, size_t index, void *data)
{
  assert (self != NULL);
  cpparray_stack_ensure (self, index);
  void *prev = self->data.back ().back ();
  self->data.back ().back () = data;
  return prev;
}

void *
cpparray_stack_get (cpparray_stack *self, size_t index)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (index < self->data.back ().size ());
  return self->data.back ().at (index);
}

size_t
cpparray_stack_size (cpparray_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  return self->data.back ().size ();
}


void
cpparray_stack_push_level (cpparray_stack *self)
{
  assert (self != NULL);
  self->data.emplace_back ();
}

/*
 * XXX: this implementation is incorrect because of std::vector deleting the
 * top vector on pop_back
 */
void *const *
cpparray_stack_pop_level (cpparray_stack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  self->data.pop_back ();
  return NULL;
}

void *const *
cpparray_stack_last_level (cpparray_stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  assert (!self->data.back ().empty ());
  return &self->data.back ()[0];
}

size_t
cpparray_stack_levels (cpparray_stack const *self)
{
  assert (self != NULL);
  return self->data.size ();
}
