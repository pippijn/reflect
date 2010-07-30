#!/usr/bin/perl -w
# usage: ./foo node_name member1 [member2 ... memberN]

use strict;

my $name = shift @ARGV;
my $memc = @ARGV;
my @members = @ARGV;
my $spaced_name = $name;
my $filler = $name;
my $i, my $tmp;

$spaced_name =~ s/_/ /g;
$filler =~ s/[a-z0-9_]/ /g;

print "/*\n";

print " * $spaced_name\n";

print <<"EOF";
 */

/* constructor */
EOF

if ($memc > 1) {
  print "ast_node*       ast_${name}_new           (ast_node *$members[0],\n";
} else {
  print "ast_node*       ast_${name}_new           (ast_node *$members[0]);\n";
}

for($i = 1; $i < $memc - 1; $i++) {
  print "$filler                                    ast_node *$members[$i],\n";
}

if ($memc > 1) {
  print "$filler                                    ast_node *$members[-1]);\n";
}

print <<"EOF";

/* accessors */
EOF

for($i = 0; $i < $memc; $i++) {
  $tmp = $members[$i];
  $tmp =~ s/_tok$//;
  printf ("ast_node*       ast_${name}_%-13s (ast_node const *self);\n", $tmp);
}
