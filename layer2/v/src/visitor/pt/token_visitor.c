#include <ctype.h>

#include <pt/visitors.h>
#include <pt/visitor/impl.h>

typedef struct pt_token_visitor self_type;

struct pt_token_visitor
{
  visitor_type base;

  FILE *fh;
  int lineno;
  int column;
  char last;
};

static void
output_location (self_type *self, struct location const *loc, char next)
{
  bool needspace = isalnum (self->last) && isalnum (next);
  while (self->lineno < loc->first_line)
    {
      fprintf (self->fh, "\n");
      self->lineno++;
      self->column = 1;
      self->last = '\n';
      needspace = false;
    }
  while (self->column < loc->first_column || needspace)
    {
      fprintf (self->fh, " ");
      self->column++;
      self->last = ' ';
      needspace = false;
    }
}

static void
output_text (self_type *self, char const *text)
{
  fprintf (self->fh, "%s", text);
  self->column += strlen (text);
  self->last = text[strlen (text) - 1];
}

static void
pt_token_visitor_visit_token (visitor_type *object, node_type const *node)
{
  SELF ();
  char const *text = pt_token_text (node);

  output_location (self, pt_node_location (node), text[0]);
  if (pt_token_token (node) != EOF)
    output_text (self, text);
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
  self->lineno = 1;
  self->column = 0;
  self->last = '\0';
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
