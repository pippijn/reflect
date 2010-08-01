%%
%%

unary_expression
	: IMAG unary_expression
	  { $$ = pt_fmt342_new ($1, $2); }
	| REAL unary_expression
	  { $$ = pt_fmt343_new ($1, $2); }
	;
