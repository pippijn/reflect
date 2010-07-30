#!/bin/sh

name=$1
argc=$2

cat <<EOF
#include "internal.h"

/* type of self */

typedef struct ast_node_${name} self_type;


/* vtable */

#if 0
static fn_destruct ast_${name}_destruct;
#endif
static fn_print ast_${name}_print;

static struct ast_vtbl const* const vtbl = &ast_${name}_vtbl;
struct ast_vtbl const ast_${name}_vtbl = {
  {
    &ast_node_vtbl,
    "${name}",
EOF

printf "    AST_%s,\n" $(echo $name | tr 'a-z' 'A-Z');

cat <<EOF
  },
#if 0
  ast_${name}_destruct,
#else
  ast_node_destruct,
#endif
  ast_${name}_print,
};


/* internal */

void
ast_${name}_construct (self_type* self, ast_node *,
EOF

for ((i=0; i<argc-2; i++))
do
  printf "%s                ast_node *\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
done

printf "%s                ast_node *)\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'

cat <<EOF
{
  struct location loc;

EOF

for ((i=0; i<argc; i++))
do
  echo "  assert ();"
done

cat <<EOF

  COMPUTE_LOC ();
  BASE_CTOR (node, &loc);

EOF

for ((i=0; i<argc; i++))
do
  echo "  self->"
done

cat <<EOF
}


/* public */

ast_node*
ast_${name}_new (ast_node *,
EOF

for ((i=0; i<argc-2; i++))
do
  printf "%s          ast_node *\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
done

printf "%s          ast_node *)\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'

cat <<EOF
{
  return NEW (${name}, 
              );
}


/* accessors */

EOF

for ((i=0; i<argc; i++))
do
  echo "ACCESSOR (${name}, );"
done

cat <<EOF


/* virtual */

void
ast_${name}_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

EOF

for ((i=0; i<argc; i++))
do
  echo "  ast_node_print (self->, fh);"
done

echo }
