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

sub assemble_rules {
   my ($nodes, $rule) = @_;

   my $rhs = join ' ', map { $_->{expr} } @{ $rule->{rhs} };

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
         my $arg  = $rule->{rhs}[$i]{name};
         my $idx  = $node->{$arg};

         for ($cur + 1 .. $idx - 1) {
            push @args, undef;
            ++$cur
         }

         push @args, $arg;

         ++$cur
      }
      push @args, undef
         for $cur .. (keys %{ $nodes->{$rule->{node}} }) - 1;

      my $count = 0;
      $code .= join ", ", map { $_ ? '$' . ++$count : "NULL" } @args;
      $code .= "); parse_context_unit_set (context, \$\$); }";
   }

   $rhs . $code
}

sub gen_rules {
   my ($rules, $fh) = @_;

   while (my ($nterm, $rule) = each %$rules) {
      my $nodes = locate_args $rule;

      print $fh "$nterm\n\t: "
              . (join "\n\t| ", map { assemble_rules $nodes, $_ } @$rule)
              . "\n\t;\n\n";
   }
}


1
