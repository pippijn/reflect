package Reflect::Output::Print;

use common::sense;

use base 'Reflect::Visitor';

sub new {
   my ($pkg, $file) = @_;

   if ($file and not ref $file) {
      open $file, ">", $file
         or die "Could not open $file: $!"
   } elsif (not $file) {
      $file = \*STDOUT
   }

   bless {
      lineno => 1,
      column => 0,
      fh     => $file,
   }, $pkg
}

sub DESTROY {
   my ($self) = @_;

   $self->{fh}->print ("\n")
}

sub output_location {
   my ($self, $lineno, $column) = @_;

   while ($self->{lineno}++ < $lineno) {
      $self->{fh}->print ("\n");
      $self->{column} = 1;
   }

   while ($self->{column}++ < $column) {
      $self->{fh}->print (" ");
   }
}

sub output_token {
   my ($self, $text) = @_;

   if ($self->{saw_id}) {
      if ($text =~ /^[a-zA-Z0-9_]/) {
         $self->{fh}->print (" ");
         ++$self->{column};
      } else {
         $self->{saw_id} = 0;
      }
   }
   $self->{saw_id} = $text =~ /[a-zA-Z0-9_]$/;

   $self->{column} += length $text;
   $self->{fh}->print ($text)
}

sub token {
   my ($self, $tree) = @_;

   return if $tree->{token} == -1;

   $self->output_location (split /:/, $tree->{left});
   $self->output_token ($tree->{content});

   $tree
}

sub node_merge {
   my ($self, $tree) = @_;

   $self->visit ($tree->{n1});

   $tree
};


1
