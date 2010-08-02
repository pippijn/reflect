%%
%%

struct_declaration
	: n1:gcc_extension n2:struct_declaration
	  { fmt382 }
	;

unary_expression
	: n1:gcc_extension n2:cast_expression
	  { fmt383 }
	;

declarator
	: n1:gcc_extension n2:declarator
	  { fmt384 }
	;

external_definition
	: n1:gcc_extension n2:external_definition
	  { fmt385 }
	;

gcc_extension
	: n1:EXTENSION
	  { fmt386 }
	;
