%%
%%

primary_expression
	: '(' '{' statement_list '}' ')'
	  { $$ = pt_fmt380_new ($1, $2, $3, $4, $5); }
	| '(' '{' declaration_list statement_list '}' ')'
	  { $$ = pt_fmt381_new ($1, $2, $3, $4, $5, $6); }
	;
