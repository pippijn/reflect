#pragma once

#include "yy/lex_interf.h"
#include "yy/parse_interf.h"

int yyparse (parse_context* context);
void yyerror (YYLTYPE const* llocp, parse_context* context, char const* s);
