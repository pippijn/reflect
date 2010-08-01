#include <pt/visitors.h>
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
  {
    pt_visitor *printer = pt_print_visitor_new (stdout);
    pt_node_accept (parse_context_unit (pctx), printer);
    pt_print_visitor_delete (printer);
  }
  pt_node_store (parse_context_unit (pctx), stdout, 0);
  parse_context_delete (pctx);

  return 0;
}
