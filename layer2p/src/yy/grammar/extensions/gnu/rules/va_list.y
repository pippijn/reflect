%%
%%

unary_expression
	: n1:VA_ARG n2:'(' n3:assignment_expression n4:',' n5:type_name n6:')'
	  { fmt393 }
	;

basic_type_name
	: n1:VA_LIST
	  { fmt394 }
	;
