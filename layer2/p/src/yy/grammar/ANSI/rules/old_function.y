%%
%%

declarator
	: :old_function_declarator %merge <node_merge>
	;

old_function_declarator
	: :postfix_old_function_declarator
	| star:'*' attrs:attributes?                                declr:old_function_declarator
	  { old_function_declarator103 }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+ declr:old_function_declarator
	  { old_function_declarator103 }
	;

postfix_old_function_declarator
	: name:paren_identifier_declarator lbrack:'(' params:identifier[',']+ rbrack:')'
	  { postfix_old_function_declarator105 }
	| lbrack:'(' declr:old_function_declarator rbrack:')'
	  { postfix_old_function_declarator106 }
	| lbrack:'(' declr:old_function_declarator rbrack:')' post_declr:postfixing_abstract_declarator
	  { postfix_old_function_declarator106 }
	;


function_definition
	: dspec:declaration_specifier      declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_dspec }
	| tspec:type_specifier             declarator:full_old_function_declarator body:compound_statement
	  { old_function_definition_tspec }
	;

function_declarator
	: :full_old_function_declarator %merge <node_merge>
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
