#pragma once

#include <location.h>

#define L_TREE          pt
#define U_TREE          PT
#define VISITOR_VTBL_H  <pt/gen/visitor_vtbl.h>

#include <_tree/node.h.in>

#include <_tree/token.h.in>
#include <_tree/visitor.h.in>

#ifndef INTERNAL
#include <pt/gen/nodes.h>
#endif

#undef VISITOR_VTBL_H
#undef U_TREE
#undef L_TREE
