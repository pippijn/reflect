package astgen::util;

use base 'Exporter';

@EXPORT = qw/maybe_open all required mangle/;


use Template::Stash;

$Template::Stash::SCALAR_OPS->{optional}  = sub { 0 };
$Template::Stash::SCALAR_OPS->{upper}     = sub { uc $_[0] };
$Template::Stash::SCALAR_OPS->{mangle}    = \&mangle_one;
$Template::Stash::LIST_OPS->{optional}    = sub { 1 };
$Template::Stash::LIST_OPS->{all}         = \&all;
$Template::Stash::LIST_OPS->{mangle}      = \&mangle;
$Template::Stash::LIST_OPS->{required}    = \&required;


sub maybe_open {
   my ($name) = @_;

   open my $fh, ">", $name
      || die "Could not open $name: $!"
         unless -f $name;

   $fh
}

sub all {
   map { ref $_ ? map { all ($_) } @$_ : $_ } @_;
}

sub required {
   my ($members) = @_;

   grep { ref $_ ne "ARRAY" } @$members;
}

sub mangle_one {
   my ($name) = @_;
   "_$name"
}

sub mangle {
   map { mangle_one $_ } all [@_]
}


1
