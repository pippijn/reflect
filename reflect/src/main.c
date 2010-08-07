#include <pt/visitors.h>
#include <xml_input.h>
#include <yyinterf.h>

#include <sys/time.h>

static void
phase (char const *name)
{
  static int number;
  static struct timeval start;

  if (start.tv_sec != 0)
    {
      struct timeval end;
      struct timeval diff;

      gettimeofday (&end, NULL);
      timersub (&end, &start, &diff);

      printf ("%td.%06td sec\n", diff.tv_sec, diff.tv_usec);
    }
  if (name)
    printf ("phase %2d: %s... ", ++number, name);
  fflush (stdout);

  gettimeofday (&start, NULL);
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

static void
print_tokens (pt_node const *node, char const *file)
{
  pt_visitor *printer;
  FILE *fh = fopen (file, "w");
  assert (fh != NULL);

  printer = pt_token_visitor_new (fh);
  pt_node_accept (node, printer);
  fputc ('\n', fh);

  pt_token_visitor_delete (printer);
  fclose (fh);
}

static void
dot_members_recursive (pt_node const *node, FILE *fh)
{
  char const *const *members;

  for (members = pt_node_members (node); *members != NULL; members++)
    {
      pt_node const *next = pt_node_member (node, *members);
      if (next != NULL)
        {
          fprintf ( fh
                  , "\t\"%s\\n@%p\" -> \"%s\\n@%p"
                  , pt_node_type_name (node), node
                  , pt_node_type_name (next), next
                  );
          if (strcmp (pt_node_type_name (next), "token") == 0)
            fprintf ( fh
                    , ":\\n`%s´ (%d)\";\n"
                    , pt_token_text (next)
                    , pt_token_token (next)
                    );
          else
            fprintf ( fh
                    , "\";\n"
                    );
          dot_members_recursive (next, fh);
        }
    }
}

static void
dot_members (pt_node const *node, char const *file)
{
  FILE *fh = fopen (file, "w");
  assert (fh != NULL);

  fprintf (fh, "digraph code {\n");
#if 0
  fprintf (fh, "\trankdir = \"LR\";\n");
#endif
  dot_members_recursive (node, fh);
  fprintf (fh, "}\n");

  fclose (fh);
}

static void
print_members_recursive (pt_node const *node, FILE *fh, int indent)
{
  char const *const *members;

  fprintf (fh, "%*s- node `%s'@%p:\n", indent, "", pt_node_type_name (node), node);
  if (strcmp (pt_node_type_name (node), "token") == 0)
    {
      fprintf (fh, "%*s- text: `%s´\n", indent + 2, "", pt_token_text (node));
      fprintf (fh, "%*s- token: %d\n", indent + 2, "", pt_token_token (node));
    }
  else
    for (members = pt_node_members (node); *members != NULL; members++)
      {
        pt_node const *next = pt_node_member (node, *members);
        fprintf (fh, "%*s- member `%s':\n", indent + 2, "", *members);
        if (next != NULL)
          print_members_recursive (next, fh, indent + 4);
        else
          fprintf (fh, "%*s  (nil)\n", indent + 2, "");
      }
}

static void
print_members (pt_node const *node, char const *file)
{
  FILE *fh = fopen (file, "w");
  assert (fh != NULL);

  print_members_recursive (node, fh, 0);

  fclose (fh);
}

int
main (void)
{
  parse_context *pctx;
  pt_node *node;

  mem_init ();

  pctx = parse_context_new ();
  yydebug = 0;
  phase ("parsing");
  if (yyparse (pctx) == 1)
    puts ("An unrecoverable syntax has occurred. Parsing was aborted.");
  node = parse_context_unit (pctx);

  phase ("generating xml");
  print_node (node, "parse.xml");
  phase ("generating s-expression tree");
  store_node (node, "parse.lsp");
  phase ("deparsing tree");
  print_tokens (node, "parse.tok");
  phase ("printing parse tree");
  print_members (node, "parse.out");
  phase ("printing parse tree as dot file");
  dot_members (node, "parse.dot");
  phase ("visualising parse graph");
  system ("dot -Tpng parse.dot -o parse.png");

  phase ("destroying tree");
  parse_context_delete (pctx);

  phase ("reading back tree from xml");
  node = test_xml_parse ("parse.xml");
  assert (node != NULL);
  phase ("printing read-back parse tree");
  print_members (node, "reparse.out");
  phase ("generating xml from subtree");
  print_node (pt_node_path (node, "/def/n3"), "reparse.xml");
  phase ("destroying read-back tree");
  pt_node_unref (node);
  phase (NULL);

  return 0;
}
