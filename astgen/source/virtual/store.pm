package astgen::source;

use common::sense;

use astgen::util;

sub gen_store {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh <<EOF;

void
${dataname}_${name}_store (${dataname}_node const *object, FILE *fh)
{
  CONST_SELF ();

  fputs ("(${name}\\n", fh);
EOF

   for my $member (@$members) {
      if (ref $member eq "ARRAY") {
         for my $mem (@$member) {
            print $fh "  if (self->$mem != NULL)\n";
            print $fh "    {\n";
            print $fh "      fputs (\"($mem \", fh);\n";
            print $fh "      ${dataname}_node_store (self->$mem, fh);\n";
            print $fh "      fputs (\")\\n\", fh);\n";
            print $fh "    }\n";
         }
      } else {
         print $fh "  fputs (\"($member \", fh);\n";
         print $fh "  ${dataname}_node_store (self->$member, fh);\n";
         print $fh "  fputs (\")\\n\", fh);\n";
      }
   }

   print $fh <<EOF;
  fputs (")", fh);
}
EOF
}


1
