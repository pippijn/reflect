#!/bin/sh

while read line;
do
  base=`echo $line | awk '{ print $1 }' | sed 's/_.*//'`
  header=`echo $base | sed 's/$/.h/'`
  src=`echo $base | sed 's/$/.c/'`
  name=`echo $line | awk '{print $1 }'`

  if [ -f ./include/ast/$header ]
  then
    continue		# remove this, if you want to diff
    header=${header}_
    src=${src}_
  fi

  echo "  GEN  $name"
  ./include/ast/_templ_header.pl $line > ./include/ast/$header
  ./src/ast/_templ_header.pl $line > ./src/ast/$header
  ./src/ast/_templ_source.pl $line > ./src/ast/$src
done 
