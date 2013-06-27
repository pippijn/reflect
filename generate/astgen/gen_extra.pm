package astgen::extra;

use common::sense;

use astgen::util;

use Template;
use Template::Stash;

my $template = new Template {
   INTERPOLATE    => 1,
   PRE_CHOMP      => 1,
   POST_CHOMP     => 1,
   INCLUDE_PATH   => 'generate/data/extra',
};

sub generate {
   my ($dataname, $rules) = @_;

   local $Template::Stash::LIST_OPS->{args} = sub {
      my ($list, $args) = @_;

      my $count = -1;
      join ", ", map { $count++; "$args\[$count\]" } @$list
   };

   for my $extra (@main::extra) {
      my $fh = maybe_open "layer1/a/src/$dataname/gen/$extra.c"
         or next;

      process $template "$extra.c.in", {
         dataname => $dataname,
         rules    => $rules,
      }, $fh
         or die $template->error
   }
}


1
