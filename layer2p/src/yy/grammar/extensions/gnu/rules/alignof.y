%%
%%

unary_expression
	: alignof_tok:ALIGNOF expr:unary_expression
	  { alignof_var }
	| alignof_tok:ALIGNOF lbrack:'(' type:type_name rbrack:')'
	  { alignof_type }
	;
