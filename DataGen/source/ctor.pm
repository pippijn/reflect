package DataGen::source;

use DataGen::util;

sub gen_ctor {
   my ($fh, $name, $members) = @_;

   my $ctor = "${dataname}_${name}_construct ";
   print $fh <<EOF;


/* internal */

void
$ctor( self_type *self
EOF
   print $fh ' ' x (length $ctor) . ", ${dataname}_node *$_\n"
      for all $members;
   print $fh ' ' x (length $ctor) . ")\n";
   print $fh "{";
   print $fh "\n  struct location loc;";
   print $fh "\n  ${dataname}_node* fst = NULL;";
   print $fh "\n  ${dataname}_node* lst = NULL;";
   print $fh "\n\n";

   print $fh "  assert ($_ != NULL);\n"
      for required $members;

   for (all $members) {
      print $fh <<EOF;
  if ($_ != NULL)
    {
      lst = $_;
      if (fst == NULL)
        fst = $_;
    }
EOF
   }
   print $fh "\n  COMPUTE_LOC (fst, lst);";
   print $fh "\n  BASE_CTOR (node, &loc);\n";
   #print $fh "\n  self->$_ = ${dataname}_node_ref_ornull ($_);"
   print $fh "\n  self->$_ = $_;"
      for all $members;
   print $fh "\n}\n";
}


1
