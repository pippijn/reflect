%%
%%

unary_expression
	: va_arg_op:VA_ARG lbrack:'(' expr:assignment_expression comma:',' type:type_name rbrack:')'
	  { va_arg_expression }
	;

basic_type_name
	: n1:VA_LIST
	  { va_list_type_spec }
	;
