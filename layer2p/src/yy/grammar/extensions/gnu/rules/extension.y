%%
%%

struct_declaration
	: gcc_extension struct_declaration
	  { new (fmt382) ($1, $2); }
	;

unary_expression
	: gcc_extension cast_expression
	  { new (fmt383) ($1, $2); }
	;

declarator
	: gcc_extension declarator
	  { new (fmt384) ($1, $2); }
	;

external_definition
	: gcc_extension external_definition
	  { new (fmt385) ($1, $2); }
	;

gcc_extension
	: EXTENSION
	  { new (fmt386) ($1); }
	;
