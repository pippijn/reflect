#!/bin/sh

name=$1
argc=$2

echo "/*"

echo " * $namen" | sed 's/_/ /g'

cat <<EOF
 */

/* constructor */
ast_node*       ast_${name}_new           (ast_node *
EOF

for ((i=0; i<argc-2; i++))
do
  printf "%s                                    ast_node *\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g';
done

printf "%s                                    ast_node *);\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g';

cat <<EOF

/* accessors */
EOF

for ((i=0; i<argc; i++))
do
  echo "ast_node*       ast_${name}_              (ast_node const *self);"
done
