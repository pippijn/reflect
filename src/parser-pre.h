#include <stdio.h>

extern int column;

static int
yyerror (char const* s)
{
  fflush (stdout);
  printf ("\n%*s\n%*s\n", column, "^", column, s);
}
