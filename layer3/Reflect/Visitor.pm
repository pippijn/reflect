package Reflect::Visitor;

use common::sense;

use Data::Dumper;

sub dump {
   my $dumper = new Data::Dumper [$_[1]];
   $dumper->Seen ({ parent => $_[1]->{parent} });

   print $dumper->Dump
}

sub all {
   map { ref $_ ? map { all ($_) } @$_ : $_ } @_;
}

my %derived;

sub import {
   my ($pkg) = @_;

   $derived{$pkg} = undef;
   while (my ($ctor, $members) = each %$Reflect::TYPES) {
      *{"${pkg}::$ctor"} = sub {
         my ($self, $tree) = @_;
         #print "stub: $ctor\n";

         return $self->any ($tree)
            if exists ${"${pkg}::"}{any};

         for my $member (all $members) {
            #print "stub -> $member\n";
            $tree->{$member} = $self->visit ($tree->{$member});
            #delete $tree->{$member}
               #unless $tree->{$member}
         }

         $tree
      } unless exists ${"${pkg}::"}{$ctor}
   }
}

sub unimport {
   my ($pkg) = @_;

   delete $derived{$pkg}
}

sub override {
   my ($self, $sym, $code) = @_;

   *{"${_}::$sym"} = $code
      for keys %derived
}

sub visit {
   my ($self, $tree) = @_;

   my $ref = ref $tree;
   if ($ref eq "HASH") {
      die if keys %$tree != 0;
   } elsif ($ref eq "ARRAY") {
      for (0 .. $#$tree) {
         my $ref = ref $tree->[$_];
         $tree->[$_] = $self->$ref ($tree->[$_])
      }
   } else {
      #print "<visit $ref>\n";
      $tree = $self->$ref ($tree);
      #print "</visit $ref>\n";
   }

   $tree
}

sub resume {
   my ($self, $tree) = @_;

   for my $member (keys %$tree) {
      $tree->{$member} = $self->visit ($tree->{$member});
      #delete $tree->{$member}
         #unless $tree->{$member}
   }
}

sub token {
   my ($self, $tree) = @_;

   $tree
}


1
