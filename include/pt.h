#pragma once

#include <location.h>

#define L_TREE          pt
#define U_TREE          PT
#define VISITOR_H       <pt/gen/visitor.h>

#include <_tree/node.h.in>

#include <_tree/token.h.in>
#include <_tree/visitor.h.in>

#include <pt/gen/nodes.h>
#include <pt/gen/visitor.h>

#undef VISITOR_H
#undef U_TREE
#undef L_TREE
