package Reflect::Visitor;

use common::sense;

use Data::Dumper;

sub dump {
   my $dumper = new Data::Dumper [$_[1]];
   $dumper->Seen ({ ref $_[1]->{parent}{node} => $_[1]->{parent}{node} });

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
            #printf "stub: %s->$member\n", ref $tree;
            use Carp 'confess';
            eval {
               $tree->$member = $self->visit ($tree->$member);
            } or confess $@;
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
   my ($sym, $code) = @_;

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

   for my $member (grep { $_ ne "parent" } keys %$tree) {
      $tree->$member = $self->visit ($tree->$member);
      #delete $tree->{$member}
         #unless $tree->{$member}
   }
}

sub token {
   my ($self, $tree) = @_;

   $tree
}


1
