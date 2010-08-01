sub gen_header_internal {
   my ($file, $dataname, $name, $members) = @_;

   my $fh = maybe_open ("layer1/src/$dataname/gen/$file.h")
      or return;

   print $fh <<EOF;
struct ${dataname}_node_$name
{
  ${dataname}_node base;

EOF

   print $fh "  ${dataname}_node *$_;\n"
      for all $members;
    
   my $ctor = "void ${dataname}_${name}_construct ";
   print $fh <<EOF;
};


extern struct ${dataname}_vtbl const ${dataname}_${name}_vtbl;


$ctor( struct ${dataname}_node_${name} *self
EOF

   print $fh ' ' x (length $ctor) . ", ${dataname}_node *$_\n"
      for all $members;
   print $fh ' ' x (length $ctor) . ");\n";
}


1
