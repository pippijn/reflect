%%
%%

unary_expression
	: VA_ARG '(' assignment_expression ',' type_name ')'
	  { $$ = pt_fmt393_new ($1, $2, $3, $4, $5, $6); }
	;

basic_type_name
	: VA_LIST
	  { $$ = pt_fmt394_new ($1); }
	;
