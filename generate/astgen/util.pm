package astgen::util;

use base 'Exporter';

@EXPORT = qw/maybe_open all required/;


use Template::Stash;

$Template::Stash::SCALAR_OPS->{optional}  = sub { 0 };
$Template::Stash::SCALAR_OPS->{upper}     = sub { uc $_[0] };
$Template::Stash::LIST_OPS->{optional}    = sub { 1 };
$Template::Stash::LIST_OPS->{all}         = \&all;
$Template::Stash::LIST_OPS->{required}    = \&required;


sub maybe_open {
   my ($name) = @_;

   open my $fh, ">", $name
      || die "Could not open $name: $!"
         unless -f $name;

   $fh
}

sub all {
   my ($members) = @_;

   map { ref $_ eq "ARRAY" ? @$_ : $_ } @$members;
}

sub required {
   my ($members) = @_;

   grep { ref $_ ne "ARRAY" } @$members;
}



1
