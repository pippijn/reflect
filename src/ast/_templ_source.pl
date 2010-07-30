#!/usr/bin/perl -w
# usage: ./foo node_name member1 [member2 ... memberN]

use strict;

my $name = shift @ARGV;
my $memc = @ARGV;
my @members = @ARGV;
my $spaced_name = $name;
my $upper_name = uc($name);
my $filler = $name;
my $i, my $tmp;
my $longest = 0;
my $memstr = join(", ", @members);

foreach(@members) {
  if (length $_ > $longest) {
    $longest = length $_;
  }
}

$spaced_name =~ s/_/ /g;
$filler =~ s/[a-z0-9_]/ /g;

print <<"EOF";
#include "internal.h"

/* type of self */

typedef struct ast_node_${name} self_type;


/* vtable */

#if 0
static fn_destruct ast_${name}_destruct;
#endif
static fn_print ast_${name}_print;

static struct ast_vtbl const* const vtbl = &ast_${name}_vtbl;
struct ast_vtbl const ast_${name}_vtbl = {
  {
    &ast_node_vtbl,
    "${name}",
EOF

print "    AST_$upper_name,\n";

print <<"EOF";
  },
#if 0
  ast_${name}_destruct,
#else
  ast_node_destruct,
#endif
  ast_${name}_print,
};


/* internal */

void
ast_${name}_construct (self_type* self, ast_node *$members[0],
EOF

#for ((i=0; i<argc-2; i++))
#do
#  printf "%s                ast_node *\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
#done
#printf "%s                ast_node *)\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
for($i = 1; $i < $memc - 1; $i++) {
  print "$filler                ast_node *$members[$i],\n";
}

print "$filler                ast_node *$members[-1]);\n";

print <<"EOF";
{
  struct location loc;

EOF

for($i = 0; $i < $memc; $i++) {
  print "  assert (); /* FIXME */\n";
}

print <<"EOF";

  COMPUTE_LOC ($members[0], $members[-1]) /* FIXME */;
  BASE_CTOR (node, &loc);

EOF

foreach(@members) {
  printf("  self->%-${longest}s = %s;\n", $_, $_);
}

print <<"EOF";
}


/* public */

ast_node*
ast_${name}_new (ast_node *$members[0],
EOF

#for ((i=0; i<argc-2; i++))
#do
#  printf "%s          ast_node *\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
#done
#printf "%s          ast_node *)\n" $(echo $name | tr 'a-z0-9_' '%') | sed 's/%/ /g'
for($i = 1; $i < $memc - 1; $i++) {
  print "$filler          ast_node *$members[$i],\n";
}

print "$filler          ast_node *$members[-1]);\n";

print <<"EOF";
{
  return NEW (${name}, $memstr);
}


/* accessors */

EOF

foreach (@members) {
  $tmp = $_;
  if ($tmp =~ m/_tok$/) {
    $tmp =~ s/_tok$//;
    print <<"EOF";
ast_node*
ast_${name}_$tmp (ast_node const *object)
{
  CONST_SELF ();

  return self->$_;
}

EOF
  } else {
    print "ACCESSOR ($name, $tmp)\n"
  }
}

print <<"EOF";


/* virtual */

void
ast_${name}_print (ast_node const* object, FILE* fh)
{
  CONST_SELF ();

EOF

foreach(@members) {
  print "  ast_node_print (self->$_, fh);\n";
}

print "}\n";
