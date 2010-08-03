use common::sense;


my %state = (
   num => 0,
);

sub expect {
   local $" = ", ";
   die "Expected one of @_, got $state{token}"
      unless grep { $_ } map { $_ eq $state{token} } @_
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
         $state{num} = 1
      }

      # ':' after non-terminal
      elsif ($state{num} == 1)

      {
         expect ':';
         $state{num} = 2
      }

      # one right hand side token (term/nonterm)
      elsif ($state{num} == 2)

      {
         # %dprec or %merge
         if ($state{token} =~ /^%/) {
            $state{num} = 6;
            redo
         }

         my ($name, $expr) = split /:/, $state{token}, 2;
         push @{ $state{rhs} }, {
            name => $name,
            expr => $expr,
         };

         $state{num} = 3
      }

      # after a term/nonterm
      elsif ($state{num} == 3)

      {
         # one rule finished
         if ($state{token} eq '|' or $state{token} eq ';') {
            push @{ $rules{$state{nonterm}} }, {
               rhs   => $state{rhs},
               node  => $state{node},
               dprec => $state{dprec},
               merge => $state{merge},
            };
            delete $state{rhs};
            delete $state{node};
            delete $state{dprec};
            delete $state{merge};
         }

         # next will be the node name
         elsif ($state{token} eq '{') {
            $state{num} = 4
         }

         # anything else must be another rhs token
         else {
            $state{num} = 2;
            redo
         }

         if ($state{token} eq '|') {
            # next rule
            $state{num} = 2
         } elsif ($state{token} eq ';') {
            # finished nonterminal
            $state{num} = 0
         }
      }

      # after { comes the node name
      elsif ($state{num} == 4)

      {
         $state{node} = $state{token};
         $state{num} = 5
      }

      # closing }
      elsif ($state{num} == 5)

      {
         expect '}';
         $state{num} = 3
      }

      # %dprec or %merge
      elsif ($state{num} == 6)

      {
         expect "%dprec", "%merge";
         ($state{directive}) = $state{token} =~ /%(.+)/;
         $state{num} = 7
      }

      # the precedence or merge function
      elsif ($state{num} == 7)
      {
         $state{$state{directive}} = $state{token};
         $state{num} = 3
      }

      else

      {
         die "Invalid state: $state{num}"
      }
   }

   \%rules
}


1
