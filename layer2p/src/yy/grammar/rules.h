#define new(rule) $$ = pt_##rule##_new

#include "ANSI/rules.y"

#include "extensions/c99/rules.y"
#include "extensions/gnu/rules.y"
