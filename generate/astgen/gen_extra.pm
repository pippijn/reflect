package astgen::extra;

use common::sense;

use astgen::util;

use Template;
use Template::Stash;

$Template::Stash::SCALAR_OPS->{optional}  = sub { 0 };
$Template::Stash::SCALAR_OPS->{upper}     = sub { uc $_[0] };
$Template::Stash::LIST_OPS->{optional}    = sub { 1 };
$Template::Stash::LIST_OPS->{all}         = \&all;
$Template::Stash::LIST_OPS->{args}        = sub {
   my ($list, $args) = @_;

   my $count = -1;
   join ", ", map { $count++; "$args\[$count\]" } @$list
};

my $template = new Template {
   INTERPOLATE    => 1,
   PRE_CHOMP      => 1,
   POST_CHOMP     => 1,
   INCLUDE_PATH   => 'generate/data/extra',
};

sub generate {
   my ($dataname, $rules) = @_;

   for my $extra (@main::extra) {
      my $fh = maybe_open "layer1/src/$dataname/gen/$extra.c"
         or next;

      process $template "$extra.c.in", {
         dataname => $dataname,
         rules    => $rules,
      }, $fh
         or die $template->error
   }
}


1
