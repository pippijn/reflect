package astgen::source;

use common::sense;

use astgen::util;

use astgen::source::accessors;
use astgen::source::ctor;
use astgen::source::new;
use astgen::source::self_type;
use astgen::source::functions;
use astgen::source::vtbl;

sub generate {
   my ($file, $dataname, $name, $members) = @_;

   my $fh = maybe_open "src/${dataname}/gen/$file.c"
      or return;

   gen_self_type $fh, $dataname, $name, $members;
   gen_vtbl $fh, $dataname, $name, $members;
   gen_ctor $fh, $dataname, $name, $members;
   gen_new $fh, $dataname, $name, $members;
   gen_accessors $fh, $dataname, $name, $members;
   gen_functions $fh, $dataname, $name, $members;
}


1
