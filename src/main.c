#include "yyinterf.h"

#include <stdio.h>

void
yyerror (YYLTYPE const* llocp, parse_context* context, char const* s)
{
  fflush (stdout);
  printf ("%d:%d: %s\n", llocp->first_line, llocp->first_column, s);
}

int
main (void)
{
  parse_context* pctx;

  pctx = parse_context_new ();
  yyparse (pctx);
  parse_context_delete (pctx);

  return 0;
}
