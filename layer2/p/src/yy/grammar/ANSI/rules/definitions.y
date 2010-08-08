%%
%%

translation_unit
	: defs:external_definition+
	  { translation_unit }
	;

external_definition
	: :declaration %merge <node_merge>
	| :function_definition %merge <node_merge>
	| :';'
	;

function_definition
	:                                  declarator:function_declarator          body:compound_statement
	  { function_definition }
	| dqual:declaration_qualifier_list declarator:function_declarator          body:compound_statement
	  { function_definition_dqual }
	| tqual:type_qualifier+            declarator:function_declarator          body:compound_statement
	  { function_definition_tqual }
	| dspec:declaration_specifier      declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_dspec }
	| tspec:type_specifier             declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_tspec }
	;

function_declarator
	: :identifier_declarator %merge <node_merge>
	| :full_old_function_declarator %merge <node_merge>
	;

full_old_function_declarator
	: declarator:old_function_declarator
	  { fullold_function_declarator }
	| declarator:old_function_declarator decls:old_function_declaration_list
	  { fullold_function_declarator }
	;


old_function_declaration_list
	: :declaration+
	;
