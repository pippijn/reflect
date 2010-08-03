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
	  { fmt159 }
	| n1:function_definition
	  { fmt160 }
	| n1:';'
	  { fmt161 }
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
	  { fmt162 }
	| n2:full_old_function_declarator
	  { fmt163 }
	;

full_old_function_declarator
	: n1:old_function_declarator
	  { fullold_function_declarator }
	| n1:old_function_declarator n2:old_function_declaration_list
	  { fullold_function_declarator }
	;


old_function_declaration_list
	: n1:declaration_list
	  { fmt164 }
	;
