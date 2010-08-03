package astgen::source;

use common::sense;

use astgen::util;

sub gen_self_type {
   my ($fh, $dataname, $name, $members) = @_;

   print $fh <<EOF;
#include "../internal.h"
#include <$dataname/gen/$name.h>
#include "$name.h"

/* type of *self */

typedef struct ${dataname}_node_${name} self_type;


/* vtable */

EOF
}


1
