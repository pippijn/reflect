#pragma once

#include <location.h>

#define L_TREE          ast
#define U_TREE          AST
#define VISITOR_VTBL_H  <ast/gen/visitor_vtbl.h>

#include <_tree/node.h.in>

#include <_tree/token.h.in>
#include <_tree/visitor.h.in>

#ifndef INTERNAL
#include <ast/gen/nodes.h>
#endif

#undef VISITOR_VTBL_H
#undef U_TREE
#undef L_TREE
