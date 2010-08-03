%%
%%

type_specifier_nosue
	: n1:typeof_type_specifier
	  { fmt387 }
	;

typeof_expression
	: n1:expression
	  { fmt388 }
	| n1:type_specifier
	  { fmt389 }
	;

typeof_type_specifier
	:                            typeof_tok:TYPEOF lbrack:'(' expr:typeof_expression rbrack:')'
	  { typeof_type_specifier }
	| tquals:type_qualifier_list typeof_tok:TYPEOF lbrack:'(' expr:typeof_expression rbrack:')'
	  { typeof_type_specifier }
	;
