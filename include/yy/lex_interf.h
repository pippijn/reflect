#pragma once

#include <yy/location.h>
#include <yy/semantic.h>

#include <parse_context.h>

#include <parser.h>

void lexer_update_lloc (YYLTYPE* yylloc, int lineno, int column, int leng);
