package astgen::source;

use common::sense;

use astgen::util;

use Template;
use Template::Stash;

my $template = new Template {
   INTERPOLATE    => 1,
   PRE_CHOMP      => 1,
   POST_CHOMP     => 1,
   INCLUDE_PATH   => 'generate/data/members',
};

sub gen_functions {
   my ($fh, $dataname, $name, $members) = @_;

   local $Template::Stash::LIST_OPS->{args}     = sub { join ", ", @{$_[0]} };
   local $Template::Stash::LIST_OPS->{params}   = sub { join ", ", map { "${dataname}_node *$_\n  " } @{$_[0]} };

   (process $template "$_.c.in", {
      dataname => $dataname,
      name     => $name,
      members  => $members,
   }, $fh)
      || die $template->error
         for grep { !/virtual/ } @main::mfuns;

   print $fh "\n\n/* virtual */\n\n";

   (process $template "$_.c.in", {
      dataname => $dataname,
      name     => $name,
      members  => $members,
   }, $fh)
      || die $template->error
         for grep { /virtual/ } @main::mfuns;
}


1
