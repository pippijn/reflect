package Reflect::Transform::Clean;

use common::sense;

use base 'Reflect::Visitor';

sub new {
   bless { }, $_[0]
}

sub any {
   my ($self, $tree) = @_;

   for (values %$tree) {
      delete $_->{members};
      $self->visit ($_)
         if ref;
   }

   $tree
}

1
