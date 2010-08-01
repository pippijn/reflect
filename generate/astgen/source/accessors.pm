package astgen::source;

use common::sense;

use astgen::util;

sub gen_accessors {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh "\n\n/* accessors */\n\n";
   print $fh "ACCESSOR ($name, $_)\n"
      for all $members;
}


1
