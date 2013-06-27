#include <stack/impl_cpp.h>
#include <stack.h>

#include <vector>

struct stack
{
  std::vector<void*> data;
};

/*
 * private
 */


/*
 * public
 */

stack *
stack_new (void)
{
  return new stack;
}

void
stack_delete (stack *self)
{
  assert (self != NULL);
  delete self;
}


void
stack_push (stack *self, void *data)
{
  assert (self != NULL);
  self->data.push_back (data);
}

void *
stack_pop (stack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  void *data = self->data.back ();
  self->data.pop_back ();
  return data;
}

void *
stack_top (stack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  return self->data.back ();
}

size_t
stack_size (stack const *self)
{
  assert (self != NULL);
  return self->data.size ();
}
