%%
%%

type_specifier_nosue
	: n1:typeof_type_specifier
	  { type_specifier_nosue387 }
	;

typeof_expression
	: n1:expression
	  { typeof_expression388 }
	| n1:type_specifier
	  { typeof_expression389 }
	;

typeof_type_specifier
	:                        typeof_tok:TYPEOF lbrack:'(' expr:typeof_expression rbrack:')'
	  { typeof_type_specifier }
	| tquals:type_qualifier+ typeof_tok:TYPEOF lbrack:'(' expr:typeof_expression rbrack:')'
	  { typeof_type_specifier }
	;
