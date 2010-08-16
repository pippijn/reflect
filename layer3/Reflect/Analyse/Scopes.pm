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

   $self->visit ($tree->dspec);
   $self->visit ($tree->declr);
}

sub paren_identifier_declarator {
   my ($self, $tree) = @_;

   $self->visit ($tree->id);
}

sub paren_typedef_declarator70 {
   my ($self, $tree) = @_;

   $self->visit ($tree->tname);
}

sub basic_declaration_specifier22 {
   my ($self, $tree) = @_;

   $self->visit ($tree->dquals);
   $self->visit ($tree->tname);
}

sub declaration_qualifier_list31 {
   my ($self, $tree) = @_;

   $self->visit ($tree->str_class);
}

sub typedef_str_class_spec {
   my ($self, $tree) = @_;

   $self->{declaration}{str_class} = "typedef";

   $self->visit ($tree->typedef);
}


1
