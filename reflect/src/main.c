#include <pt/visitors.h>
#include <xml_input.h>
#include <yyinterf.h>

#include <stdio.h>

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

static void
print_members (pt_node const *node, int indent)
{
  char const *const *members;

  printf ("%*s- node `%s':\n", indent, "", pt_node_type_name (node));
  if (strcmp (pt_node_type_name (node), "token") == 0)
    {
      printf ("%*s- text: `%s´\n", indent + 2, "", pt_token_text (node));
      printf ("%*s- token: %d\n", indent + 2, "", pt_token_token (node));
    }
  else
    for (members = pt_node_members (node); *members != NULL; members++)
      {
        pt_node const *next = pt_node_member (node, *members);
        printf ("%*s- member `%s':\n", indent + 2, "", *members);
        if (next != NULL)
          print_members (next, indent + 2);
        else
          printf ("%*s  (nil)\n", indent + 2, "");
      }
}

static void
print_tokens (pt_node const *node)
{
  char const *const *members;

  if (strcmp (pt_node_type_name (node), "token") == 0)
    printf ("%s ", pt_token_text (node));
  else
    for (members = pt_node_members (node); *members != NULL; members++)
      {
        pt_node const *next = pt_node_member (node, *members);
        if (next != NULL)
          print_tokens (next);
      }
}

void
yyerror (YYLTYPE const *llocp, parse_context const *context, char const *s)
{
  printf ("%d:%d: %s\n", llocp->first_line, llocp->first_column, s);
  printf ("Current symbol:\n");
  print_tokens (parse_context_unit (context));
  puts ("");
  printf ("Current symbol's parse tree:\n");
  print_members (parse_context_unit (context), 0);

  exit (EXIT_FAILURE);
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
    print_members (node, 0);
    print_node (pt_node_path (node, "/n1/n1"), "reparse.xml");
    pt_node_unref (node);
  }

  return 0;
}
