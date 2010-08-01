package astgen::source;

use common::sense;

use astgen::util;

sub gen_vtbl {
   my ($fh, $dataname, $name, $members) = @_;

   my $NAME = uc $name;
   my $DATANAME = uc $dataname;

   print $fh "static fn_$_ ${dataname}_${name}_$_;\n"
      for @main::vfuns;

   print $fh <<EOF;

static struct ${dataname}_vtbl const* const vtbl = &${dataname}_${name}_vtbl;
struct ${dataname}_vtbl const ${dataname}_${name}_vtbl = {
  {
    &${dataname}_node_vtbl,
    "$name",
    ${DATANAME}_$NAME,
    sizeof (self_type),
  },
EOF
   print $fh "  ${dataname}_${name}_$_,\n"
      for @main::vfuns;
   print $fh "};\n";
}


1
