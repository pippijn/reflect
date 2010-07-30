#!/usr/bin/perl -w
# usage: ./foo node_name member1 [member2 ... memberN]

use strict;

my $name = shift @ARGV;
my $memc = @ARGV;
my @members = @ARGV;
my $spaced_name = $name;
my $filler = $name;
my $i;

$spaced_name =~ s/_/ /g;
$filler =~ s/[a-z0-9_]/ /g;

print <<"EOF";
struct ast_node_${name}
{
  ast_node base;

EOF

for($i = 0; $i < $memc; $i++) {
  print "  ast_node *$members[$i];\n";
}

print <<"EOF";
};


extern struct ast_vtbl const ast_${name}_vtbl;


void ast_${name}_construct (struct ast_node_${name} *self,
EOF

for($i = 0; $i < $memc - 1; $i++) {
  print "$filler                     ast_node *$members[$i],\n";
}

print "$filler                     ast_node *$members[-1]);\n";
