package astgen::source;

use common::sense;

use astgen::util;

use Template;
use Template::Stash;

$Template::Stash::SCALAR_OPS->{optional}  = sub { 0 };
$Template::Stash::LIST_OPS->{optional}    = sub { 1 };
$Template::Stash::LIST_OPS->{all}         = \&all;

my $template = new Template {
   INTERPOLATE    => 1,
   PRE_CHOMP      => 1,
   POST_CHOMP     => 1,
   INCLUDE_PATH   => 'generate/data/virtual',
};

sub gen_functions {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh "\n\n/* virtual */\n\n";

   (process $template "$_.c.in", {
      dataname => $dataname,
      name     => $name,
      members  => $members,
   }, $fh)
      || die $template->error
         for @main::vfuns
}


1
