#!/bin/sh

while read line;
do
  header=`echo $line | awk '{ print $1 }' | sed 's/_.*/.h/'`
  src=`echo $line | awk '{ print $1 }' | sed 's/_.*/.c/'`
  name=`echo $line | awk '{print $1 }'`

  if [ -f ./include/ast/$header ]
  then
    header=${header}_
    src=${src}_
  fi

  echo "  GEN  $name"
  ./include/ast/_templ_header.pl $line > ./include/ast/$header
  ./src/ast/_templ_header.pl $line > ./src/ast/$header
  ./src/ast/_templ_source.pl $line > ./src/ast/$src
done 
