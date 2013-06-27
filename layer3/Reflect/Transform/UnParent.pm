package Reflect::Transform::UnParent;

use common::sense;

use base 'Reflect::Visitor';

sub new {
   bless { }, $_[0]
}

sub any {
   my ($self, $tree) = @_;

   #use Data::Dumper;
   #print Dumper $tree;

   #return $tree;

   #printf "any: %s\n", ref $tree;
   while (my ($member, $subtree) = each %$tree) {
      next if $member eq "parent";

      #printf "$member: %s<\n", ref $subtree;
      if (ref $subtree eq "ARRAY") {
         for (@$subtree) {
            delete $_->{parent}
         }
      } elsif (ref $subtree ne "HASH") {
         delete $subtree->{parent}
      }
      $self->visit ($subtree)
         if ref $subtree;
   }

   $tree
}

1
