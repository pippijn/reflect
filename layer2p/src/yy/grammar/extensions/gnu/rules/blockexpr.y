%%
%%

primary_expression
	: n1:'(' n2:'{' n3:statement_list n4:'}' n5:')'
	  { fmt380 }
	| n1:'(' n2:'{' n3:declaration_list n4:statement_list n5:'}' n6:')'
	  { fmt381 }
	;
