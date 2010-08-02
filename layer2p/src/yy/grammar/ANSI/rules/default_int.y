%%
%%

type_name
	: n1:type_qualifier_list /*DEFAULT_INT*/
	  { fmt151 }
	| n1:type_qualifier_list /*DEFAULT_INT*/ n2:abstract_declarator
	  { fmt152 }
	;

parameter_declaration
	: n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/
	  { fmt153 }
	| n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/ n3:abstract_declarator
	  { fmt154 }
	| n1:attributes_opt n2:declaration_qualifier_list /*DEFAULT_INT*/ n3:identifier_declarator
	  { fmt155 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/
	  { fmt156 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/ n3:abstract_declarator
	  { fmt157 }
	| n1:attributes_opt n2:type_qualifier_list /*DEFAULT_INT*/ n3:identifier_declarator
	  { fmt158 }
	;
