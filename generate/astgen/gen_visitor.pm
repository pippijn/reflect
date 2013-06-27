package astgen::visitor;

use common::sense;

use astgen::util;

use Template;

my $template = new Template {
   INTERPOLATE    => 1,
   PRE_CHOMP      => 1,
   POST_CHOMP     => 1,
   INCLUDE_PATH   => 'generate/data/visitor',
};

sub generate {
   my ($dataname, $rules) = @_;

   for my $visitor (@main::visitors) {
      my $fh = maybe_open "layer2/v/src/visitor/$dataname/gen/$visitor.c"
         or next;

      process $template "$visitor.c.in", {
         dataname => $dataname,
         rules    => $rules,
      }, $fh
         or die $template->error
   }
}


1
