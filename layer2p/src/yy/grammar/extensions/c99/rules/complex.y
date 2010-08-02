%%
%%

unary_expression
	: IMAG unary_expression
	  { new (fmt342) ($1, $2); }
	| REAL unary_expression
	  { new (fmt343) ($1, $2); }
	;
