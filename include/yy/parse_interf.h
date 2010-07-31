#pragma once

#include <yy/location.h>
#include <yy/semantic.h>

#include <parse_context.h>

#include <lexer.h>
#include <parser.h>

void yyerror (YYLTYPE const *llocp, parse_context const *context, char const *s);
