#include "yyinterf.h"

#include <stdio.h>

void
yyerror (YYLTYPE const *llocp, parse_context const *context, char const *s)
{
  printf ("%d:%d: %s\n", llocp->first_line, llocp->first_column, s);
}

int
main (void)
{
  parse_context *pctx;

  pctx = parse_context_new ();
  yydebug = 0;
  yyparse (pctx);
  ast_node_print (parse_context_unit (pctx), stdout);
  parse_context_delete (pctx);

  return 0;
}
