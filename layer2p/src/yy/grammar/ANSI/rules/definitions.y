%%
%%

external_definition
	: n1:declaration
	  { fmt161 }
	| n1:function_definition
	  { fmt162 }
	| n1:empty n2:';'
	  { fmt163 }
	;

function_definition
	: n1:identifier_declarator n2:compound_statement
	  { fmt164 }
	| n1:declaration_qualifier_list n2:identifier_declarator n3:compound_statement n4:type_qualifier_list n5:identifier_declarator n6:compound_statement
	  { fmt165 }
	| n1:old_function_declarator n2:compound_statement
	  { fmt166 }
	| n1:declaration_specifier n2:old_function_declarator n3:compound_statement
	  { fmt167 }
	| n1:type_specifier n2:old_function_declarator n3:compound_statement
	  { fmt168 }
	| n1:declaration_qualifier_list n2:old_function_declarator n3:compound_statement n4:type_qualifier_list n5:old_function_declarator n6:compound_statement
	  { fmt169 }
	| n1:old_function_declarator n2:old_function_declaration_list n3:compound_statement
	  { fmt170 }
	| n1:declaration_specifier n2:old_function_declarator n3:old_function_declaration_list n4:compound_statement
	  { fmt171 }
	| n1:type_specifier n2:old_function_declarator n3:old_function_declaration_list n4:compound_statement
	  { fmt172 }
	| n1:declaration_qualifier_list n2:old_function_declarator n3:old_function_declaration_list n4:compound_statement
	  { fmt173 }
	| n1:type_qualifier_list n2:old_function_declarator n3:old_function_declaration_list n4:compound_statement
	  { fmt174 }
	;


old_function_declaration_list
	: n1:declaration_list
	  { fmt175 }
	;
