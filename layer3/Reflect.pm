package Reflect;

our $TYPES;

BEGIN {
   $TYPES = require "generate/data/pt.ast"
}

use Reflect::Transform::List;
use Reflect::Transform::Parent;
use Reflect::Transform::UnParent;
use Reflect::Transform::Empty;
use Reflect::Analyse::Scopes;
use Reflect::Output::Print;

sub import {
   *token::TO_JSON = sub { my %hash = %{$_[0]}; \%hash };
   for (keys %$TYPES) {
      *{"${_}::TO_JSON"} = sub {
         my %hash = %{ $_[0] };
         return { ref $_[0] => \%hash }
      }
   }
}

sub bless_all {
   my ($tree) = @_;

   my ($type, $unwanted) = keys %$tree;

   return $tree
      unless $type;
   die "Too many keys: ", join ", ", keys %$tree
      if $unwanted;

   $tree->{$type}{$_} = bless_all ($tree->{$type}{$_})
      for keys %{ $tree->{$type} };

   bless $tree->{$type}, $type
}

sub damn_all {
   my ($tree) = @_;

   if (ref $tree eq "ARRAY") {
      damn_all ($_)
         for @$tree
   } else {
      $tree->{$_} = damn_all ($tree->{$_})
         for keys %$tree
   }

   use Acme::Damn;
   $tree = damn $tree
      if ref $tree
      && ref $tree ne "HASH"
      && ref $tree ne "ARRAY";

   $tree
}


1
