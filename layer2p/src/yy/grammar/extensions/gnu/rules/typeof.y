%%
%%

type_specifier_nosue
	: typeof_type_specifier
	  { new (fmt387) ($1); }
	;

typeof_expression
	: expression
	  { new (fmt388) ($1); }
	| type_specifier
	  { new (fmt389) ($1); }
	;

typeof_type_specifier
	: TYPEOF '(' typeof_expression ')'
	  { new (fmt390) ($1, $2, $3, $4); }
	| type_qualifier_list TYPEOF '(' typeof_expression ')'
	  { new (fmt391) ($1, $2, $3, $4, $5); }
	;
