%%
%%

default_int
	: :empty
	;

type_name
	: tquals:type_qualifier+ defint:default_int
	  { type_name151 }
	| tquals:type_qualifier+ defint:default_int decl:abstract_declarator
	  { type_name151 }
	;

parameter_declaration
	: attrs:attributes? quals:qualifier_list defint:default_int
	  { parameter_declaration156 }
	| attrs:attributes? quals:qualifier_list defint:default_int decl:abstract_declarator
	  { parameter_declaration157 }
	| attrs:attributes? quals:qualifier_list defint:default_int decl:identifier_declarator
	  { parameter_declaration158 }
	;

qualifier_list
	: :declaration_qualifier_list
	| :type_qualifier+
	;
