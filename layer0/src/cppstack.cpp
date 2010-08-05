#include <cppstack.h>

#include <vector>

struct cppstack
{
  std::vector<void*> data;
};

/*
 * private
 */


/*
 * public
 */

cppstack *
cppstack_new (void)
{
  return new cppstack;
}

void
cppstack_delete (cppstack *self)
{
  assert (self != NULL);
  delete self;
}


void
cppstack_push (cppstack *self, void *data)
{
  assert (self != NULL);
  self->data.push_back (data);
}

void *
cppstack_pop (cppstack *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  void *data = self->data.back ();
  self->data.pop_back ();
  return data;
}

void *
cppstack_top (cppstack const *self)
{
  assert (self != NULL);
  assert (!self->data.empty ());
  return self->data.back ();
}

size_t
cppstack_size (cppstack const *self)
{
  assert (self != NULL);
  return self->data.size ();
}
