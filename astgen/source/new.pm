package astgen::source;

use common::sense;

use astgen::util;

sub gen_new {
   my ($fh, $dataname, $name, $members) = @_;

   my $new = "${dataname}_${name}_new ";
   print $fh <<EOF;


/* public */

${dataname}_node *
EOF
   my $new = "${dataname}_${name}_new ";
   if ($#$members) {
      print $fh "$new( ";
      print $fh join ' ' x (length $new) . ", ", map { "${dataname}_node *$_\n" } all $members;
      print $fh ' ' x (length $new) . ")\n";
   } else {
      print $fh "$new(${dataname}_node *$members->[0])\n";
   }
   print $fh "{\n  return NEW ($name, " . (join ", ", all $members) . ");\n}\n";
}


1
