%%
%%

type_name
	: type_qualifier_list /*DEFAULT_INT*/
	  { new (fmt151) ($1); }
	| type_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { new (fmt152) ($1, $2); }
	;

parameter_declaration
	: attributes_opt declaration_qualifier_list /*DEFAULT_INT*/
	  { new (fmt153) ($1, $2); }
	| attributes_opt declaration_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { new (fmt154) ($1, $2, $3); }
	| attributes_opt declaration_qualifier_list /*DEFAULT_INT*/ identifier_declarator
	  { new (fmt155) ($1, $2, $3); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/
	  { new (fmt156) ($1, $2); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { new (fmt157) ($1, $2, $3); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/ identifier_declarator
	  { new (fmt158) ($1, $2, $3); }
	;
