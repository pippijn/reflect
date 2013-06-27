package astgen::source;

use common::sense;

use astgen::util;

sub gen_member_list {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh "static char const *const members[] = {\n";
   for my $member (all $members) {
      print $fh "  \"$member\",\n";
   }
   print $fh "  NULL\n";
   print $fh "};\n\n";
}


1
