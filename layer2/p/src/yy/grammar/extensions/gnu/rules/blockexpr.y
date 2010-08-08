%%
%%

primary_expression
	: lbrack:'(' body:compound_statement rbrack:')'
	  { brace_expression }
	;
