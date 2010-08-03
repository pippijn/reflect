%%
%%

default_int
	: n1:empty
	  { default_int }
	;

type_name
	: tquals:type_qualifier_list defint:default_int
	  { type_name151 }
	| tquals:type_qualifier_list defint:default_int decl:abstract_declarator
	  { type_name151 }
	;

parameter_declaration
	: attrs:attributes_opt dquals:declaration_qualifier_list defint:default_int
	  { parameter_declaration153 }
	| attrs:attributes_opt dquals:declaration_qualifier_list defint:default_int decl:abstract_declarator
	  { parameter_declaration154 }
	| attrs:attributes_opt dquals:declaration_qualifier_list defint:default_int decl:identifier_declarator
	  { parameter_declaration155 }
	| attrs:attributes_opt tquals:type_qualifier_list defint:default_int
	  { parameter_declaration156 }
	| attrs:attributes_opt tquals:type_qualifier_list defint:default_int decl:abstract_declarator
	  { parameter_declaration157 }
	| attrs:attributes_opt tquals:type_qualifier_list defint:default_int decl:identifier_declarator
	  { parameter_declaration158 }
	;
