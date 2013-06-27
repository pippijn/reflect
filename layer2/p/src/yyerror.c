#include "yyinterf.h"

static void
print_location (YYLTYPE const *llocp)
{
  printf ("\n<stdin>:%d:%d: ", llocp->first_line, llocp->first_column);
}

#undef L
#define L print_location (llocp),

static void
print_members_recursive (YYLTYPE const *llocp, pt_node const *node, FILE *fh, int indent)
{
  char const *const *members;

  L fprintf (fh, "%*s- node `%s'@%p:", indent, "", pt_node_type_name (node), node);
  if (strcmp (pt_node_type_name (node), "token") == 0)
    {
      L fprintf (fh, "%*s- text: `%s´", indent + 2, "", pt_token_text (node));
      L fprintf (fh, "%*s- token: %d", indent + 2, "", pt_token_token (node));
    }
  else
    for (members = pt_node_members (node); *members != NULL; members++)
      {
        pt_node const *next = pt_node_member (node, *members);
        L fprintf (fh, "%*s- member `%s':", indent + 2, "", *members);
        if (next != NULL)
          print_members_recursive (llocp, next, fh, indent + 4);
        else
          L fprintf (fh, "%*s  (nil)", indent + 2, "");
      }
}

static void
print_tokens (pt_node const *node)
{
  char const *const *members;

  if (strcmp (pt_node_type_name (node), "token") == 0 && pt_token_token (node) != EOF)
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
yyerror (YYSTYPE lvalp, YYLTYPE const *llocp, parse_context const *context, char const *s)
{
  L printf ("%s", s);

  if (lvalp != NULL)
    {
      L printf ("offending token: ");
      print_tokens (lvalp);
    }

  L printf ("deparsed correct subtree: ");
  print_tokens (parse_context_unit (context));

  L printf ("current subtree:");
  print_members_recursive (llocp, parse_context_unit (context), stdout, 0);
  fputc ('\n', stdout);

  exit (EXIT_FAILURE);
}
