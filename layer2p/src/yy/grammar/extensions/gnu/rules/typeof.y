%%
%%

type_specifier_nosue
	: typeof_type_specifier
	  { $$ = pt_fmt387_new ($1); }
	;

typeof_expression
	: expression
	  { $$ = pt_fmt388_new ($1); }
	| type_specifier
	  { $$ = pt_fmt389_new ($1); }
	;

typeof_type_specifier
	: TYPEOF '(' typeof_expression ')'
	  { $$ = pt_fmt390_new ($1, $2, $3, $4); }
	| type_qualifier_list TYPEOF '(' typeof_expression ')'
	  { $$ = pt_fmt391_new ($1, $2, $3, $4, $5); }
	;
