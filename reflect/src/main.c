#include <pt/visitors.h>
#include <xml_input.h>
#include <yyinterf.h>

#include <stdarg.h>
#include <sys/time.h>

static void
phase (char const *name, ...)
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
    {
      va_list ap;

      printf ("phase %2d: ", ++number);
      va_start (ap, name);
      vprintf (name, ap);
      va_end (ap);
      printf ("... ");
    }
  fflush (stdout);

  gettimeofday (&start, NULL);
}

static void
print_node (pt_node const *node, char const *file)
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
store_node (pt_node const *node, char const *file)
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

static char const *
dot_escape (char const *text)
{
  static char buf[1024];
  char *ptr = buf;
  char c;

  while ((c = *text++) != '\0')
    switch (c)
      {
      case '"': case '\\':
        *ptr++ = '\\';
      default:
        *ptr++ = c;
      }
  *ptr = '\0';

  return buf;
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
          struct location const *loc = pt_node_location (next);
          fprintf ( fh
                  , "\t\"%s\\n@%p\\nrefcnt: %d\" -> \"%s\\n@%p\\nrefcnt: %d"
                  , pt_node_type_name (node), node, pt_node_refcnt (node)
                  , pt_node_type_name (next), next, pt_node_refcnt (next)
                  );
          if (strcmp (pt_node_type_name (next), "token") == 0)
            fprintf ( fh
                    , "\\n`%s´ (%d)\\n%d:%d - %d:%d\"\n "
                    , dot_escape (pt_token_text (next))
                    , pt_token_token (next)
                    , loc->first_line, loc->first_column
                    , loc->last_line, loc->last_column
                    );
          else
            fprintf ( fh
                    , "\" "
                    );
          fprintf (fh, "[ label = \"%s\" ];\n", *members);
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

static void
action (pt_node const *node, char const *base, char const *name)
{
  char buf[1024];

  assert (node != NULL);

  phase ("generating xml from %s tree", name);
  snprintf (buf, sizeof buf, "%s.xml", base);
  print_node (node, buf);

  phase ("generating s-expression tree from %s tree", name);
  snprintf (buf, sizeof buf, "%s.lsp", base);
  store_node (node, buf);

  phase ("deparsing %s tree", name);
  snprintf (buf, sizeof buf, "%s.tok", base);
  print_tokens (node, buf);

  phase ("printing %s tree", name);
  snprintf (buf, sizeof buf, "%s.out", base);
  print_members (node, buf);

  phase ("printing %s tree as dot file", name);
  snprintf (buf, sizeof buf, "%s.dot", base);
  dot_members (node, buf);

  phase ("visualising parse graph for %s tree", name);
  snprintf (buf, sizeof buf, "dot -Tpng %s.dot -o %s.png", base, base);
  system (buf);
}

int
main (void)
{
  mem_init ();

  {
    parse_context *pctx = parse_context_new ();
    pt_node *node;

    yydebug = 0;
    phase ("parsing");
    if (yyparse (pctx) == 1)
      puts ("An unrecoverable syntax has occurred. Parsing was aborted.");
    node = parse_context_unit (pctx);

    action (node, "parse", "parse");

    phase ("destroying parse context");
    parse_context_delete (pctx);
  }

  {
    pt_node *node;

    phase ("reading back tree from xml");
    node = test_xml_parse ("parse.xml");

    action (node, "reparse", "read-back");

    phase ("destroying read-back tree");
    pt_node_unref (node);
  }

  phase (NULL);

  return 0;
}
