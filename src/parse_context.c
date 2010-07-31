#include "parse_context.h"

#include "yyinterf.h"

#include <stdlib.h>

struct parse_context
{
  void *scanner;
  ast_node *unit;
};


/* constructor */

parse_context *
parse_context_new (void)
{
  parse_context *self = alloc (sizeof *self);

  yylex_init (&self->scanner);
  yyset_extra (self, self->scanner);

  self->unit = NULL;

  return self;
}

/* destructor */

void
parse_context_delete (parse_context *self)
{
  yylex_destroy (self->scanner);
  ast_node_unref_ornull (self->unit);

  sever (self, sizeof *self);
}



/* accessors */

void *
parse_context_scanner (parse_context const *self)
{
  return self->scanner;
}


ast_node *
parse_context_unit (parse_context const *self)
{
  return self->unit;
}

void
parse_context_unit_set (parse_context *self, ast_node *unit)
{
  ast_node_unref_ornull (self->unit);
  self->unit = unit;
  ast_node_ref_ornull (self->unit);
}
