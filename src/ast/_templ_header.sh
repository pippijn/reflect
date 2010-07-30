#!/bin/sh

name=$1
argc=$2

cat <<EOF
struct ast_node_${name}
{
  ast_node base;

EOF

for ((i=0; i<argc; i++))
do
  echo "  ast_node *"
done

cat <<EOF
};


extern struct ast_vtbl const ast_${name}_vtbl;


void ast_${name}_construct (struct ast_node_${name} *self,
EOF

for ((i=0; i<argc-1; i++))
do
  printf "%s                                  ast_node *\n" $(echo $name | tr 'a-z0-9_' ' ');
done

printf "%s                                  ast_node *);\n" $(echo $name | tr 'a-z0-9_' ' ');
