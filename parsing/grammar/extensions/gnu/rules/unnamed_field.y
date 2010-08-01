%%
%%

struct_declaring_list
	: struct_or_union '{' struct_declaration_list '}'
	  { $$ = pt_fmt392_new ($1, $2, $3, $4); }
	;
