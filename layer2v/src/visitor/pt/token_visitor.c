#include <pt/visitors.h>
#include <pt/visitor/impl.h>

typedef struct pt_token_visitor self_type;

struct pt_token_visitor
{
  visitor_type base;

  FILE *fh;
};

static void
pt_token_visitor_visit_token (visitor_type *object, node_type const *node)
{
  SELF ();

  fprintf (self->fh, "%s ", pt_token_text (node));
}

static vtbl_type pt_token_visitor_vtbl = {
  {
    "token_visitor",
    sizeof (self_type)
  },
  pt_token_visitor_visit_token
};



static void
pt_token_visitor_construct (self_type *self, FILE *fh)
{
  assert (self != NULL);
  assert (fh != NULL);

  pt_visitor_construct (&self->base, &pt_token_visitor_vtbl);

  self->fh = fh;
}

visitor_type *
pt_token_visitor_new (FILE *fh)
{
  return NEW (token_visitor, fh);
}

void
pt_token_visitor_delete (visitor_type *object)
{
  SELF ();

  mem_free (self, self->base.vtbl->ti.size);
}
