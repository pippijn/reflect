#!/bin/sh

if [ ! -f ./Makefile ]
then
  echo "Error: this script must be run from the project root!"
  exit 1
fi

rm -f src/ast/kinds.h
rm -f src/ast/nodes.h
rm -f include/ast/nodes.h

while read line;
do
  argv=`echo $line | cut -f 2- -d ' '`
  fullbase=`echo $line | cut -f 2 -d ' '`
  base=`echo $line | cut -f 1 -d ' '`
  ucase=`echo $fullbase | tr a-z A-Z`
  header=$base.h
  src=$base.c

  if [ -f ./include/ast/$header ]
  then
    continue		# remove this, if you want to diff
    header=${header}_
    src=${src}_
  fi

  echo "  GEN  $base"

  echo "  AST_$ucase," >> src/ast/kinds.h
  echo "#include \"$header\"" >> src/ast/nodes.h
  echo "#include <ast/$header>" >> include/ast/nodes.h

  ./include/ast/_templ_header.pl $argv > ./include/ast/$header
  ./src/ast/_templ_header.pl $argv > ./src/ast/$header
  ./src/ast/_templ_source.pl $argv > ./src/ast/$src
done 
