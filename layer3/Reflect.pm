package Reflect;

BEGIN {
   our $TYPES = require "generate/data/pt.ast"
}

use Reflect::Transform::List;
use Reflect::Transform::Parent;
use Reflect::Transform::UnParent;
use Reflect::Transform::Empty;
use Reflect::Transform::Clean;
use Reflect::Analyse::Scopes;
use Reflect::Output::Print;

{
   package token;

   sub content { $_[0]->{content} }
   sub left    { $_[0]->{left}    }
   sub right   { $_[0]->{right}   }
   sub token   { $_[0]->{token}   }
}

sub all {
   map { ref $_ ? map { all ($_) } @$_ : $_ } @_;
}

sub import {
   *token::TO_JSON = sub { my %hash = %{$_[0]}; \%hash };
   while (my ($type, $members) = each %$TYPES) {
      *{"${type}::TO_JSON"} = sub {
         my %hash = %{ $_[0] };
         return { ref $_[0] => \%hash }
      };
      for my $member (all $members) {
         *{"${type}::$member"} = sub : lvalue {
            $_[0]->{$member}
         }
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
