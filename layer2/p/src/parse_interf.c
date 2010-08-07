#include <stack/impl_array.h>
#include <stack.h>

#include <yyinterf.h>

#include <pt.h>
#include <pt/visitor/impl.h>

#include "token_collector.h"
#include "token_refinc.h"

YYSTYPE
node_merge (YYSTYPE n1, YYSTYPE n2)
{
  struct token_collector collector;

  return n1;

  token_collector_construct (&collector);

  pt_node_accept (n1, &collector.base);

  {
    struct token_refinc refinc;

    token_refinc_construct (&refinc, collector.tokens);

    pt_node_accept (n2, &refinc.base);

    token_refinc_destruct (&refinc);
  }

  token_collector_destruct (&collector);

  return pt_node_merge_new (n1, n2);
}
