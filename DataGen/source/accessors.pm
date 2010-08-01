package DataGen::source;

use DataGen::util;

sub gen_accessors {
   my ($fh, $name, $members) = @_;

   print $fh "\n\n/* accessors */\n\n";
   print $fh "ACCESSOR ($name, $_)\n"
      for all $members;
}


1
