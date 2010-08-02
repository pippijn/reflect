%%
%%

unary_expression
	: ALIGNOF unary_expression
	  { new (fmt348) ($1, $2); }
	| ALIGNOF '(' type_name ')'
	  { new (fmt349) ($1, $2, $3, $4); }
	;
