package Reflect::Transform::List;

use common::sense;

use base 'Reflect::Visitor';

sub new {
   bless { }, $_[0]
}

sub DESTROY {
   my ($self) = @_;

   override (
      "node_list",
      sub {
         my ($self, $tree) = @_;

         return $self->any ($tree)
            if exists ${(ref $self) . "::"}{any};

         $self->visit ($_)
            for @{ $tree->{list} };

         $tree
      }
   )
}

sub node_list {
   my ($self, $tree) = @_;

   my $subtree = $tree;

   do {
      unshift @{ $tree->{list} }, $subtree->{node}
   } while $subtree = $subtree->{prev}
           and exists $subtree->{node};

   delete $tree->{prev};
   delete $tree->{node};

   $self->visit ($_)
      for @{ $tree->{list} };

   $tree
}

1
