package astgen::visitor;

use common::sense;

use astgen::util;

use Template;
use Template::Stash;

$Template::Stash::SCALAR_OPS->{optional}  = sub { 0 };
$Template::Stash::LIST_OPS->{optional}    = sub { 1 };
$Template::Stash::LIST_OPS->{all}         = \&all;

my $template = new Template {
   INTERPOLATE => 1,
   PRE_CHOMP => 1,
   POST_CHOMP => 1,
};

sub generate {
   my ($dataname, $rules) = @_;

   for my $visitor (@main::visitors) {
      my $fh = maybe_open "src/visitor/$dataname/gen/$visitor.c"
         or next;

      process $template "data/visitor/$visitor.c.in", {
         dataname => $dataname,
         rules    => $rules,
      }, $fh
         or die $template->error
   }
}


1
