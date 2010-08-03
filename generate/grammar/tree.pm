use common::sense;

my %structs;

use Data::Dumper;

sub assemble_tree {
   my ($nodes, $rule) = @_;

   if ($rule->{node}) {
      my $node = $nodes->{$rule->{node}};
   
      $structs{$rule->{node}} = [sort { $node->{$a} <=> $node->{$b} } keys %$node]
         unless exists $structs{$rule->{node}};
   
      my $structs = $structs{$rule->{node}};
   
      my $cur = 0;
      for my $i (0 .. $#{ $rule->{rhs} }) {
         my $arg  = $rule->{rhs}[$i]{name};
         my $idx  = $node->{$arg};
   
         for ($cur + 1 .. $idx - 1) {
            $structs->[$cur] = [$structs->[$cur]]
               unless ref $structs->[$cur] eq "ARRAY";
            ++$cur
         }
   
         ++$cur
      }
      for ($cur .. (keys %{ $nodes->{$rule->{node}} }) - 1) {
         $structs->[$_] = [$structs->[$_]]
            unless ref $structs->[$_] eq "ARRAY"
      }
   }

   ()
}

sub gen_tree {
   my ($rules, $fh) = @_;

   while (my ($nterm, $rule) = each %$rules) {
      my $nodes = locate_args $rule;

      assemble_tree $nodes, $_
         for @$rule
   }

   local $Data::Dumper::Terse = 1;
   local $Data::Dumper::Indent = 0;

   print $fh "# vim:ft=perl\n\n";
   print $fh "\$main::dataname = '$dataname';\n\n";
   print $fh "{\n";
   for (sort keys %structs) {
      my ($struct, $members) = ($_, $structs{$_});
      print $fh "   $struct => " . Data::Dumper->new ([$members])->Dump . ",\n";
   }
   print $fh "}\n"
}


1
