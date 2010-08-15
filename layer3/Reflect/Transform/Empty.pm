package Reflect::Transform::Empty;

use common::sense;

use base 'Reflect::Visitor';

sub new {
   bless { }, $_[0]
}

sub node_opt {
   my ($self, $tree) = @_;

   ref $tree->{node} eq "token" and $tree->{node}{token} == -1
      ? { }
      : $tree->{node}
}

1
