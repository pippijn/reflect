%%
%%

translation_unit
	: external_definition
	  { new (fmt159) ($1); parse_context_unit_set (context, $$); }
	| translation_unit external_definition
	  { new (fmt160) ($1, $2); parse_context_unit_set (context, $$); }
	;

external_definition
	: declaration
	  { new (fmt161) ($1); }
	| function_definition
	  { new (fmt162) ($1); }
	| empty ';'
	  { new (fmt163) ($1, $2); }
	;

function_definition
	: identifier_declarator compound_statement
	  { new (fmt164) ($1, $2); }
	| declaration_qualifier_list identifier_declarator compound_statement type_qualifier_list identifier_declarator compound_statement
	  { new (fmt165) ($1, $2, $3, $4, $5, $6); }
	| old_function_declarator compound_statement
	  { new (fmt166) ($1, $2); }
	| declaration_specifier old_function_declarator compound_statement
	  { new (fmt167) ($1, $2, $3); }
	| type_specifier old_function_declarator compound_statement
	  { new (fmt168) ($1, $2, $3); }
	| declaration_qualifier_list old_function_declarator compound_statement type_qualifier_list old_function_declarator compound_statement
	  { new (fmt169) ($1, $2, $3, $4, $5, $6); }
	| old_function_declarator old_function_declaration_list compound_statement
	  { new (fmt170) ($1, $2, $3); }
	| declaration_specifier old_function_declarator old_function_declaration_list compound_statement
	  { new (fmt171) ($1, $2, $3, $4); }
	| type_specifier old_function_declarator old_function_declaration_list compound_statement
	  { new (fmt172) ($1, $2, $3, $4); }
	| declaration_qualifier_list old_function_declarator old_function_declaration_list compound_statement
	  { new (fmt173) ($1, $2, $3, $4); }
	| type_qualifier_list old_function_declarator old_function_declaration_list compound_statement
	  { new (fmt174) ($1, $2, $3, $4); }
	;


old_function_declaration_list
	: declaration_list
	  { new (fmt175) ($1); }
	;
