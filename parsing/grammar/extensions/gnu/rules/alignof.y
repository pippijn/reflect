%%
%%

unary_expression
	: ALIGNOF unary_expression
	  { $$ = pt_fmt348_new ($1, $2); }
	| ALIGNOF '(' type_name ')'
	  { $$ = pt_fmt349_new ($1, $2, $3, $4); }
	;
