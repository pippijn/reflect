package DataGen::source;

use DataGen::util;

sub gen_destruct {
   my ($fh, $name, $members) = @_;

   print $fh <<EOF;


/* virtual */

void
${dataname}_${name}_destruct (${dataname}_node *object)
{
  SELF ();

EOF

   print $fh "  ${dataname}_node_unref_ornull (self->$_); self->$_ = NULL;\n"
      for all $members;

   print $fh <<EOF;

  BASE_DTOR ();
}
EOF
}


1
