#include "yyinterf.h"

void
lexer_update_lloc (YYLTYPE* yylloc, int lineno, int column, int leng)
{
  yylloc->first_line = lineno;
  yylloc->first_column = column;
  yylloc->last_column = column + leng;
  yylloc->last_line = lineno;
}
