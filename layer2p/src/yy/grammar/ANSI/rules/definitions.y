%%
%%

translation_unit
	:                       def:external_definition
	  { translation_unit }
	| prev:translation_unit def:external_definition
	  { translation_unit }
	;

external_definition
	: :declaration
	| :function_definition
	| :';'
	;

function_definition
	:                                  declarator:function_declarator          body:compound_statement
	  { function_definition }
	| dqual:declaration_qualifier_list declarator:function_declarator          body:compound_statement
	  { function_definition_dqual }
	| tqual:type_qualifier_list        declarator:function_declarator          body:compound_statement
	  { function_definition_tqual }
	| dspec:declaration_specifier      declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_dspec }
	| tspec:type_specifier             declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_tspec }
	;

function_declarator
	: :identifier_declarator
	| :full_old_function_declarator
	;

full_old_function_declarator
	: n1:old_function_declarator
	  { fullold_function_declarator }
	| n1:old_function_declarator n2:old_function_declaration_list
	  { fullold_function_declarator }
	;


old_function_declaration_list
	: :declaration_list
	;
