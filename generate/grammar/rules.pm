use common::sense;


sub locate_args {
   my ($rules) = @_;

   my %inv;
   push @{ $inv{$_->{node}} }, $_->{rhs}
      for @$rules;

   my %nodes;
   while (my ($node, $rule) = each %inv) {
      for my $rhs (@$rule) {
         my $i = 1;
         for my $arg (@$rhs) {
            $nodes{$node}{$arg->{name}} = $i
               if $nodes{$node}{$arg->{name}} < $i;
            ++$i;
         }
      }
   }

   \%nodes
}

my %lists;
my %opts;

sub opt_rule {
   my ($term) = @_;

   (
      {
         rhs => [
            {
               expr => 'empty',
               name => 'term',
            },
         ],
         node => 'node_opt',
      },
      {
         rhs => [
            {
               expr => $term,
               name => 'term',
            },
         ],
         node => 'node_opt',
      }
   )
}

sub list_rule {
   my ($term, $sep) = @_;

   (
      {
         rhs => [
            {
               expr => $term,
               name => 'term',
            },
         ],
         node => 'node_list',
      },
      {
         rhs => [
            {
               expr => $term . '__list',
               name => 'prev',
            },
            {
               expr => $sep,
               name => 'sep',
            },
            {
               expr => $term,
               name => 'term',
            },
         ],
         node => 'node_list',
      }
   )
}

sub quantise {
   my ($term) = @_;

   # list separator regex
   my $lsre = qr/(?:\[(.*)\])?/;

   if ($term =~ s/$lsre\*$/__list/) {
      my $sep = $1;
      @{ $lists{$term} } = list_rule $term =~ /(.+)__list/, $sep;
      $term .= '?';
   }

   if ($term =~ s/\?$/__opt/) {
      @{ $opts{$term} } = opt_rule $term =~ /(.+)__opt/
   }

   if ($term =~ s/$lsre\+$/__list/) {
      my $sep = $1;
      @{ $lists{$term} } = list_rule $term =~ /(.+)__list/, $sep
   }

   $term
}

sub assemble_rules {
   my ($nodes, $rule) = @_;

   my $rhs = join ' ', map { quantise $_->{expr} } @{ $rule->{rhs} };

   for (qw/prec dprec merge/) {
      $rhs .= " %$_ $rule->{$_}"
         if $rule->{$_}
   }

   my $code;
   if ($rule->{node}) {
      $code = "\n\t  { \$\$ = ${dataname}_$rule->{node}_new (";

      my $node = $nodes->{$rule->{node}};

      my @args;
      my $cur = 0;
      for my $i (0 .. $#{ $rule->{rhs} }) {
         my $name = $rule->{rhs}[$i]{name};
         my $expr = $rule->{rhs}[$i]{expr};
         my $idx  = $node->{$name};

         for ($cur + 1 .. $idx - 1) {
            push @args, undef;
            ++$cur
         }

         push @args, $expr ? $name : undef;

         ++$cur
      }
      push @args, undef
         for $cur .. (keys %{ $nodes->{$rule->{node}} }) - 1;

      {
         my $count = 0;
         $code .= join ", ", map { $_ ? '$' . ++$count : "NULL" } @args;
         $code .= "); parse_context_unit_set (context, \$\$); ";
      }
      if (0) {
         my $count = 0;
         $code .= join " ", map { "${dataname}_node_unref (\$" . ++$count . ");" } grep { $_ } @args;
      }
      $code .= " }"
   }

   $rhs . $code
}

sub gen_list {
   my ($term) = @_;

<<EOF
${term}__list
\t: $term
\t  { \$\$ = make list from \$1 }
\t| ${term}__list $term
\t  { \$\$ = add \$2 to list \$1 }
\t;
EOF
}

sub gen_opt {
   my ($term) = @_;

<<EOF
${term}__opt
\t: empty
\t| ${term}
\t;
EOF
}

sub gen_yacc_rules {
   my ($rules, $fh) = @_;

   while (my ($nterm, $rule) = each %$rules) {
      my $nodes = locate_args $rule;

      print $fh "$nterm\n\t: "
              . (join "\n\t| ", map { assemble_rules $nodes, $_ } @$rule)
              . "\n\t;\n\n\n";
   }
}

sub gen_rules {
   my ($rules, $fh) = @_;

   gen_yacc_rules $rules, $fh;
   gen_yacc_rules \%lists, $fh;
   gen_yacc_rules \%opts, $fh;
}


1
