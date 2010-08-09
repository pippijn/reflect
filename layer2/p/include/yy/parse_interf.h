#pragma once

#include <yy/location.h>
#include <yy/semantic.h>

#include <parse_context.h>

#include <lexer.h>
#include <parser.h>

void yyerror (YYSTYPE lvalp, YYLTYPE const *llocp, parse_context const *context, char const *s);
extern int yydebug;

YYSTYPE node_merge (YYSTYPE n1, YYSTYPE n2);

char const *token_name (int token);
