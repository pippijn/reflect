#!/bin/sh
if [ ! -f ./Makefile ]
then
  echo "Error: this script must be run from the project root!"
  exit 1
fi

while read line;
do
  argv=`echo $line | cut -f 2- -d ' '`
  base=`echo $line | cut -f 1 -d ' '`
  header=`echo $base | sed 's/$/.h/'`
  src=`echo $base | sed 's/$/.c/'`

  if [ -f ./include/ast/$header ]
  then
    continue		# remove this, if you want to diff
    header=${header}_
    src=${src}_
  fi

  echo "  GEN  $base"
  ./include/ast/_templ_header.pl $argv > ./include/ast/$header
  ./src/ast/_templ_header.pl $argv > ./src/ast/$header
  ./src/ast/_templ_source.pl $argv > ./src/ast/$src
done 
