sub gen_header {
   my ($file, $dataname, $name, $members) = @_;

   #my (@longest) = reverse sort map length, all $members;
   #use Data::Dumper;
   #print Dumper \@longest;
   my $longest = 0;
   for (all $members) {
      if ($longest < length $_) {
         $longest = length $_;
      }
   }

   my $fh = maybe_open ("layer1/include/${dataname}/gen/$file.h")
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
   print $fh "${dataname}_node *${dataname}_${name}_$_"
      . ' ' x ($longest - length $_)
      . " (${dataname}_node const *self);\n"
      for all $members;
}


1
