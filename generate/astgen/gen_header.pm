sub gen_header {
   my ($dataname, $name, $members) = @_;

   my $fh = maybe_open ("layer1/a/include/${dataname}/gen/$name.h")
      or return;

   print $fh "/*\n * ";
   print $fh do { my $spaced = $name; $spaced =~ s/_/ /g; $spaced };
   print $fh "\n */\n\n";

   print $fh "/* constructor */\n";
   my $new = "${dataname}_node *${dataname}_${name}_new ";
   if ($#$members) {
      print $fh "$new( ";
      print $fh join ' ' x (length $new) . ", ", map { "${dataname}_node *$_\n" } all $members;
      print $fh ' ' x (length $new) . ");\n\n";
   } else {
      print $fh "$new(${dataname}_node *$members->[0]);\n\n";
   }

   print $fh "/* accessors */\n";
   print $fh "${dataname}_accessor_fn ${dataname}_${name}_$_;\n"
      for all $members;
}


1
