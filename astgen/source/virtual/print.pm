package astgen::source;

use common::sense;

use astgen::util;

sub gen_print {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh <<EOF;

void
${dataname}_${name}_print (${dataname}_node const *object, FILE *fh)
{
  CONST_SELF ();

  fprintf (fh, "<$name>\\n");
EOF
   for my $member (@$members) {
      if (ref $member eq "ARRAY") {
         for my $mem (@$member) {
            print $fh "  if (self->$mem != NULL)\n";
            print $fh "    {\n";
            print $fh "      fprintf (fh, \"<$mem>\\n\");\n";
            print $fh "      ${dataname}_node_print (self->$mem, fh);\n";
            print $fh "      fprintf (fh, \"</$mem>\\n\");\n";
            print $fh "    }\n";
         }
      } else {
         print $fh "  fprintf (fh, \"<$member>\\n\");\n";
         print $fh "  ${dataname}_node_print (self->$member, fh);\n";
         print $fh "  fprintf (fh, \"</$member>\\n\");\n";
      }
   }
   print $fh "  fprintf (fh, \"</$name>\\n\");\n";
   print $fh "}\n";
}


1
