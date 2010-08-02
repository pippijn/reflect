use common::sense;


sub locate_args {
   my ($rules) = @_;

   my %inv;
   for (@$rules) {
      push @{ $inv{$_->{node}} }, $_->{rhs};
   }

   my %nodes;
   while (my ($node, $rule) = each %inv) {
      for my $rhs (@$rule) {
         my $i = 1;
         for my $arg (@$rhs) {
            if ($nodes{$node}{$arg->{name}} < $i) {
               $nodes{$node}{$arg->{name}} = $i
            }
            ++$i;
         }
      }
   }

   \%nodes
}

sub assemble {
   my ($nodes, $rule) = @_;

   my $rhs = join ' ', map { $_->{expr} } @{ $rule->{rhs} };
   my $code = "\n\t  { \$\$ = ${dataname}_$rule->{node}_new (";

   my @args;
   for my $i (0 .. $#{ $rule->{rhs} }) {
      my $arg  = $rule->{rhs}[$i]{name};
      my $node = $rule->{node};
      my $idx  = $nodes->{$node}{$arg};

      for ($i + 1 .. $idx - 1) {
         push @args, undef;
      }

      push @args, $arg;
   }
   for (@args + 1 .. keys %{ $nodes->{$rule->{node}} }) {
      push @args, undef;
   }

   my $count = 1;
   $code .= join ", ", map { $_ ? '$' . $count++ : "NULL" } @args;
   $code .= "); }";

   $rhs . $code
}

sub gen_rules {
   my ($rules, $fh) = @_;

   while (my ($nterm, $rule) = each %$rules) {
      my $nodes = locate_args $rule;

      print $fh "$nterm\n\t: ";
      print $fh join "\n\t| ", map { assemble $nodes, $_ } @$rule;
      print $fh "\n\t;\n\n";
   }
}


1
