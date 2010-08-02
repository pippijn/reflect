%%
%%

struct_declaring_list
	: struct_or_union '{' struct_declaration_list '}'
	  { new (fmt392) ($1, $2, $3, $4); }
	;
