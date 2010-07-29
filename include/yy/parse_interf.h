#pragma once

#include <yy/location.h>
#include <yy/semantic.h>

#include <parse_context.h>

#include <parser.h>
#include <lexer.h>

void yyerror (YYLTYPE const* llocp, parse_context* context, char const* s);
