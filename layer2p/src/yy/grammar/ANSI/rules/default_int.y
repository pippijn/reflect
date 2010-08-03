%%
%%

type_name
	: n1:type_qualifier_list /*DEFAULT_INT*/
	  { type_name151 }
	| n1:type_qualifier_list /*DEFAULT_INT*/ n2:abstract_declarator
	  { type_name151 }
	;

parameter_declaration
	: n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/
	  { parameter_declaration153 }
	| n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/ n3:abstract_declarator
	  { parameter_declaration154 }
	| n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/ n3:identifier_declarator
	  { parameter_declaration155 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/
	  { parameter_declaration156 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/ n3:abstract_declarator
	  { parameter_declaration157 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/ n3:identifier_declarator
	  { parameter_declaration158 }
	;
