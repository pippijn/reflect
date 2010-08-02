%%
%%

struct_declaring_list
	: n1:struct_or_union n2:'{' n3:struct_declaration_list n4:'}'
	  { fmt392 }
	;
