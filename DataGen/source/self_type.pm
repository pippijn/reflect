package DataGen::source;

use DataGen::util;

sub gen_self_type {
   my ($fh, $name, $members) = @_;

   print $fh <<EOF;
#include "../internal.h"

/* type of *self */

typedef struct ${dataname}_node_${name} self_type;


/* vtable */

EOF
}


1
