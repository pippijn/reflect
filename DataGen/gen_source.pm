package DataGen::source;

use DataGen::util;

use DataGen::source::accessors;
use DataGen::source::ctor;
use DataGen::source::new;
use DataGen::source::self_type;
use DataGen::source::vtbl;
use DataGen::source::virtual::destruct;
use DataGen::source::virtual::print;

sub generate {
   my ($file, $name, $members) = @_;

   my $fh = maybe_open "src/${dataname}/gen/$file.c"
      or return;

   gen_self_type $fh, $name, $members;
   gen_vtbl $fh, $name, $members;
   gen_ctor $fh, $name, $members;
   gen_new $fh, $name, $members;
   gen_accessors $fh, $name, $members;
   gen_destruct $fh, $name, $members;
   gen_print $fh, $name, $members;
}


1
