%%
%%

translation_unit
	: external_definition
	  { $$ = pt_fmt159_new ($1); parse_context_unit_set (context, $$); }
	| translation_unit external_definition
	  { $$ = pt_fmt160_new ($1, $2); parse_context_unit_set (context, $$); }
	;

external_definition
	: declaration
	  { $$ = pt_fmt161_new ($1); }
	| function_definition
	  { $$ = pt_fmt162_new ($1); }
	| empty ';'
	  { $$ = pt_fmt163_new ($1, $2); }
	;

function_definition
	: identifier_declarator compound_statement
	  { $$ = pt_fmt164_new ($1, $2); }
	| declaration_qualifier_list identifier_declarator compound_statement type_qualifier_list identifier_declarator compound_statement
	  { $$ = pt_fmt165_new ($1, $2, $3, $4, $5, $6); }
	| old_function_declarator compound_statement
	  { $$ = pt_fmt166_new ($1, $2); }
	| declaration_specifier old_function_declarator compound_statement
	  { $$ = pt_fmt167_new ($1, $2, $3); }
	| type_specifier old_function_declarator compound_statement
	  { $$ = pt_fmt168_new ($1, $2, $3); }
	| declaration_qualifier_list old_function_declarator compound_statement type_qualifier_list old_function_declarator compound_statement
	  { $$ = pt_fmt169_new ($1, $2, $3, $4, $5, $6); }
	| old_function_declarator old_function_declaration_list compound_statement
	  { $$ = pt_fmt170_new ($1, $2, $3); }
	| declaration_specifier old_function_declarator old_function_declaration_list compound_statement
	  { $$ = pt_fmt171_new ($1, $2, $3, $4); }
	| type_specifier old_function_declarator old_function_declaration_list compound_statement
	  { $$ = pt_fmt172_new ($1, $2, $3, $4); }
	| declaration_qualifier_list old_function_declarator old_function_declaration_list compound_statement
	  { $$ = pt_fmt173_new ($1, $2, $3, $4); }
	| type_qualifier_list old_function_declarator old_function_declaration_list compound_statement
	  { $$ = pt_fmt174_new ($1, $2, $3, $4); }
	;


old_function_declaration_list
	: declaration_list
	  { $$ = pt_fmt175_new ($1); }
	;
