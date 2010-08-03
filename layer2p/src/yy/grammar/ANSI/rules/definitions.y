%%
%%

translation_unit
	:                       def:external_definition
	  { translation_unit }
	| prev:translation_unit def:external_definition
	  { translation_unit }
	;

external_definition
	: n1:declaration
	  { external_definition159 }
	| n1:function_definition
	  { external_definition160 }
	| n1:';'
	  { external_definition161 }
	;

function_definition
	:                               n1:function_declarator n2:compound_statement
	  { function_definition }
	| n1:declaration_qualifier_list n2:function_declarator n3:compound_statement
	  { function_definition_dqual }
	| n1:type_qualifier_list        n2:function_declarator n3:compound_statement
	  { function_definition_tqual }
	| n1:declaration_specifier      n2:full_old_function_declarator n3:compound_statement
	  { old_function_definition_dspec }
	| n1:type_specifier             n2:full_old_function_declarator n3:compound_statement
	  { old_function_definition_tspec }
	;

function_declarator
	: n1:identifier_declarator
	  { function_declarator162 }
	| n2:full_old_function_declarator
	  { function_declarator163 }
	;

full_old_function_declarator
	: n1:old_function_declarator
	  { fullold_function_declarator }
	| n1:old_function_declarator n2:old_function_declaration_list
	  { fullold_function_declarator }
	;


old_function_declaration_list
	: n1:declaration_list
	  { old_function_declaration_list164 }
	;
