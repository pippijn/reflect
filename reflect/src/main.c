#include <pt/visitors.h>
#include <xml_input.h>
#include <yyinterf.h>

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
    pt_visitor *printer;
    FILE *fh = fopen ("parse.xml", "w");
    assert (fh != NULL);

    printer = pt_print_visitor_new (fh);
    pt_node_accept (parse_context_unit (pctx), printer);

    pt_print_visitor_delete (printer);
    fclose (fh);
  }

  test_xml_parse ("parse.xml");

  {
    pt_visitor *printer;
    FILE *fh = fopen ("parse.lsp", "w");
    assert (fh != NULL);

    printer = pt_store_visitor_new (fh, 0);
    pt_node_accept (parse_context_unit (pctx), printer);

    pt_store_visitor_delete (printer);
    fclose (fh);
  }

#if 0
  pt_node_print (parse_context_unit (pctx), stdout);
  pt_node_store (parse_context_unit (pctx), stdout, 0);
#endif
  parse_context_delete (pctx);

  return 0;
}
