%%
%%

unary_expression
	: VA_ARG '(' assignment_expression ',' type_name ')'
	  { new (fmt393) ($1, $2, $3, $4, $5, $6); }
	;

basic_type_name
	: VA_LIST
	  { new (fmt394) ($1); }
	;
