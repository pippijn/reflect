%%
%%

struct_declaration
	: gcc_extension struct_declaration
	  { $$ = pt_fmt382_new ($1, $2); }
	;

unary_expression
	: gcc_extension cast_expression
	  { $$ = pt_fmt383_new ($1, $2); }
	;

declarator
	: gcc_extension declarator
	  { $$ = pt_fmt384_new ($1, $2); }
	;

external_definition
	: gcc_extension external_definition
	  { $$ = pt_fmt385_new ($1, $2); }
	;

gcc_extension
	: EXTENSION
	  { $$ = pt_fmt386_new ($1); }
	;
