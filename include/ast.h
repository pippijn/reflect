#pragma once

#include <location.h>

#define L_TREE          ast
#define U_TREE          AST
#define VISITOR_H       <ast/gen/visitor.h>

#include <_tree/node.h.in>

#include <_tree/token.h.in>
#include <_tree/visitor.h.in>

#include <ast/gen/nodes.h>
#include <ast/gen/visitor.h>

#undef VISITOR_H
#undef U_TREE
#undef L_TREE
