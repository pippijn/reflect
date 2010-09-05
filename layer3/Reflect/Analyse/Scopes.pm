package Reflect::Analyse::Scopes;

use common::sense;

use base 'Reflect::Visitor';

use constant {
   TYPEDEF => 1,
};

sub new {
   bless { }, $_[0]
}

sub declaring_list9 {
   my ($self, $tree) = @_;

   $self->{current} = $tree;

   $tree->dspec = $self->visit ($tree->dspec);
   $tree->declr = $self->visit ($tree->declr);

   $tree
}

sub paren_identifier_declarator {
   my ($self, $tree) = @_;

   $tree->id = $self->visit ($tree->id);

   $tree
}

sub paren_typedef_declarator70 {
   my ($self, $tree) = @_;

   $tree->tname = $self->visit ($tree->tname);

   $tree
}

sub basic_declaration_specifier22 {
   my ($self, $tree) = @_;

   $tree->dquals = $self->visit ($tree->dquals);
   $tree->tname = $self->visit ($tree->tname);

   $tree
}

sub declaration_qualifier_list31 {
   my ($self, $tree) = @_;

   $tree->str_class = $self->visit ($tree->str_class);

   $tree
}

sub typedef_str_class_spec {
   my ($self, $tree) = @_;

   $self->{declaration}{str_class} = "typedef";

   $tree->typedef = $self->visit ($tree->typedef);

   $tree
}

sub in_scope {
   my ($self, $token) = @_;

   for my $scope (@{ $self->{scopes} }) {
      return $scope->{$token}
         if exists $scope->{$token}
   }

   ()
}

sub delete_branch {
   my ($self, $tree) = @_;

   my $parent = $tree;
   do {
      $parent = $parent->{parent}{node}
   } while ref $parent->{parent}{node} ne "node_merge";

   push @{ $self->{deleted} }, $parent->{parent}{member};
}

sub identifier {
   my ($self, $tree) = @_;

   $self->delete_branch ($tree)
      if $self->in_scope ($tree->token) eq "typedef_name";

   $tree
}

sub typedef_name {
   my ($self, $tree) = @_;

   $self->delete_branch ($tree)
      if $self->in_scope ($tree->token) ne "typedef_name";

   $tree
}

sub node_merge {
   my ($self, $tree) = @_;

   $self->resume ($tree);

   if (@{ $self->{deleted} }) {
      my $deleted = pop @{ $self->{deleted} };
      delete $tree->{$deleted}
   }

   # 1 branch left
   my ($choice, $unwanted) = grep { $_ ne "parent" } keys %$tree;
   die unless $choice;
   die if $unwanted;

   $tree->{$choice}
}


1
