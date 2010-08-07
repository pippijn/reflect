#include <yyinterf.h>

YYSTYPE
node_merge (YYSTYPE n1, YYSTYPE n2)
{
  pt_node *merged = pt_node_merge_new (n1, n2);

  pt_node_unref (n1);
  pt_node_unref (n2);

  return merged;
}
