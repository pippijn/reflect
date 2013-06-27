%%
%%

struct_declaration
	: n1:gcc_extension n2:struct_declaration
	  { struct_declaration382 }
	;

unary_expression
	: n1:gcc_extension n2:cast_expression
	  { unary_expression383 }
	;

declarator
	: n1:gcc_extension n2:declarator
	  { declarator384 }
	;

external_definition
	: n1:gcc_extension n2:external_definition
	  { external_definition385 }
	;

gcc_extension
	: n1:EXTENSION
	  { gcc_extension386 }
	;
