#include "parse_context.h"

#include "yyinterf.h"

struct parse_context
{
  void* scanner;
};

parse_context*
parse_context_new (void)
{
  parse_context* self = malloc (sizeof *self);

  yylex_init (&self->scanner);
  yyset_extra (self, self->scanner);

  return self;
}

void
parse_context_delete (parse_context* self)
{
  yylex_destroy (self->scanner);

  free (self);
}


void*
parse_context_scanner_get (parse_context* self)
{
  return self->scanner;
}
