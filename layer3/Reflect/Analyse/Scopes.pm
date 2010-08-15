package Reflect::Analyse::Scopes;

use common::sense;

use base 'Reflect::Visitor';

use constant {
   TYPEDEF => 1,
};

sub new {
   bless { }, $_[0]
}

sub declaring_list11 {
   my ($self, $tree) = @_;

   #$self->dump ($tree->{tspec});
   $self->dump ($tree->{declr});
   $self->{current} = $tree;
   $self->visit ($tree->{tspec});
   $self->visit ($tree->{declr});
   $self->visit ($tree->{register});
   $self->visit ($tree->{attrs2});
   $self->visit ($tree->{init});
}

#sub paren_identifier_declarator {
   #my ($self, $tree) = @_;

   #print Dumper $tree->{id};

   #$self->visit ($tree->{dquals});
   #$self->visit ($tree->{tname});
#}


1
