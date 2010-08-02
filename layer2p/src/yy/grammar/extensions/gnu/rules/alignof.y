%%
%%

unary_expression
	: n1:ALIGNOF n2:unary_expression
	  { fmt348 }
	| n1:ALIGNOF n2:'(' n3:type_name n4:')'
	  { fmt349 }
	;
