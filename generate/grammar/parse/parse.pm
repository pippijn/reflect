use common::sense;

my %state = (
   num => 0,
);

sub expect {
   my ($tok) = @_;

   die "Expected $tok, got $state{token}"
   if $state{token} ne $tok
}

sub parse {
   my ($file) = @_;

   my @tokens = split /\s+/, do { local $/; open my $fh, "<", $file or die "Could not open $file: $!"; <$fh> };

   my %rules;
   for (@tokens) {
      next unless length;
      $state{token} = $_;
      #print "state $state{num} token `$_´\n";

      # left hand side non-terminal
      if ($state{num} == 0)

      {
         $state{nonterm} = $state{token};
         $state{num} = 1;
      }

      # ':' after non-terminal
      elsif ($state{num} == 1)

      {
         expect ':';
         $state{num} = 2;
      }

      # one right hand side token (term/nonterm)
      elsif ($state{num} == 2)

      {
         my ($name, $expr) = split /:/, $state{token}, 2;
         push @{ $state{rhs} }, {
            name => $name,
            expr => $expr,
         };
         $state{num} = 3;

      }

      # after a term/nonterm
      elsif ($state{num} == 3)

      {
         # one rule finished
         if ($state{token} eq '|' or $state{token} eq ';') {
            push @{ $rules{$state{nonterm}} }, {
               rhs => $state{rhs},
               node => $state{node},
            };
            delete $state{rhs};
            delete $state{node};
         }

         # next will be the node name
         elsif ($state{token} eq '{') {
            $state{num} = 4;
         }

         # anything else must be another rhs token
         else {
            $state{num} = 2;
            redo
         }

         if ($state{token} eq '|') {
            # next rule
            $state{num} = 2;
         } elsif ($state{token} eq ';') {
            # finished nonterminal
            $state{num} = 0;
         }
      }

      # after { comes the node name
      elsif ($state{num} == 4)

      {
         $state{node} = $state{token};
         $state{num} = 5;
      }

      # closing }
      elsif ($state{num} == 5)

      {
         expect '}';
         $state{num} = 3;
      }

      else

      {
         last
      }
   }

   \%rules
}
