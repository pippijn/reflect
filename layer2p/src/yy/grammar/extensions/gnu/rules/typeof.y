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
	: n1:TYPEOF n2:'(' n3:typeof_expression n4:')'
	  { fmt390 }
	| n1:type_qualifier_list n2:TYPEOF n3:'(' n4:typeof_expression n5:')'
	  { fmt391 }
	;
