#include <pt/visitors.h>
#include <xml_input.h>
#include <yyinterf.h>

#include <stdio.h>

void
yyerror (YYLTYPE const *llocp, parse_context const *context, char const *s)
{
  printf ("%d:%d: %s\n", llocp->first_line, llocp->first_column, s);
}

static void
print_node (pt_node *node, char const *file)
{
  pt_visitor *printer;
  FILE *fh = fopen (file, "w");
  assert (fh != NULL);

  printer = pt_print_visitor_new (fh);
  pt_node_accept (node, printer);

  pt_print_visitor_delete (printer);
  fclose (fh);
}

static void
store_node (pt_node *node, char const *file)
{
  pt_visitor *printer;
  FILE *fh = fopen (file, "w");
  assert (fh != NULL);

  printer = pt_store_visitor_new (fh, 0);
  pt_node_accept (node, printer);

  pt_store_visitor_delete (printer);
  fclose (fh);
}

int
main (void)
{
  parse_context *pctx;
  pt_node *node;

  pctx = parse_context_new ();
  yydebug = 0;
  yyparse (pctx);
  node = parse_context_unit (pctx);

  print_node (node, "parse.xml");
  store_node (node, "parse.lsp");

  parse_context_delete (pctx);

  {
    pt_node *node = test_xml_parse ("parse.xml");
    assert (node != NULL);
    print_node (node, "reparse.xml");
  }

  return 0;
}
