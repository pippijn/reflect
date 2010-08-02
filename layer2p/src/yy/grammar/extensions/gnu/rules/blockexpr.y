%%
%%

primary_expression
	: '(' '{' statement_list '}' ')'
	  { new (fmt380) ($1, $2, $3, $4, $5); }
	| '(' '{' declaration_list statement_list '}' ')'
	  { new (fmt381) ($1, $2, $3, $4, $5, $6); }
	;
