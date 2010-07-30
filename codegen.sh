#!/bin/sh

while read line;
do
  header=`echo $line | awk '{ print $1 }' | sed 's/_.*/.h_/'`
  src=`echo $line | awk '{ print $1 }' | sed 's/_.*/.c_/'`

  ./include/ast/_templ_header.pl $line > ./include/ast/$header
  ./src/ast/_templ_header.pl $line > ./src/ast/$header
  ./src/ast/_templ_source.pl $line > ./src/ast/$src
done 
