%%
%%

declaration
	: n1:declaring_list n2:';'
	  { fmt1 }
	| n1:default_declaring_list n2:';'
	  { fmt2 }
	| n1:sue_declaration_specifier n2:';'
	  { fmt3 }
	| n1:sue_type_specifier n2:';'
	  { fmt4 }
	| n1:declaration_specifier n2:identifier_declarator n3:compound_statement
	  { fmt5 }
	| n1:declaration_specifier_nosue n2:attributes n3:identifier_declarator n4:compound_statement
	  { fmt6 }
	| n1:type_specifier n2:identifier_declarator n3:compound_statement
	  { fmt7 }
	| n1:type_specifier_nosue n2:attributes n3:identifier_declarator n4:compound_statement
	  { fmt8 }
	;


declaring_list
	: n1:declaration_specifier n2:declarator n3:asm_opt n4:attributes_opt n5:initialiser_opt
	  { fmt9 }
	| n1:declaration_specifier_nosue n2:attributes n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { fmt10 }
	| n1:type_specifier n2:declarator n3:asm_opt n4:attributes_opt n5:initialiser_opt
	  { fmt11 }
	| n1:type_specifier_nosue n2:attributes n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { fmt12 }
	| n1:declaring_list n2:',' n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { fmt13 }
	;

default_declaring_list
	: n1:declaration_qualifier_list n2:identifier_declarator n3:attributes_opt n4:initialiser_opt
	  { fmt14 }
	| n1:type_qualifier_list n2:identifier_declarator n3:attributes_opt n4:initialiser_opt
	  { fmt15 }
	| n1:default_declaring_list n2:',' n3:identifier_declarator n4:attributes_opt n5:initialiser_opt
	  { fmt16 }
	;

declaration_specifier
	: n1:declaration_specifier_nosue
	  { fmt17 }
	| n1:sue_declaration_specifier
	  { fmt18 }
	;

declaration_specifier_nosue
	: n1:basic_declaration_specifier
	  { fmt19 }
	| n1:typedef_declaration_specifier
	  { fmt20 }
	;

basic_declaration_specifier
	: n1:basic_type_specifier n2:storage_class
	  { fmt21 }
	| n1:declaration_qualifier_list n2:basic_type_name
	  { fmt22 }
	| n1:basic_declaration_specifier n2:declaration_qualifier
	  { fmt23 }
	| n1:basic_declaration_specifier n2:basic_type_name
	  { fmt24 }
	;

sue_declaration_specifier
	: n1:sue_type_specifier n2:storage_class
	  { fmt25 }
	| n1:declaration_qualifier_list n2:elaborated_type_name n3:attributes_opt
	  { fmt26 }
	| n1:sue_declaration_specifier n2:declaration_qualifier
	  { fmt27 }
	;

typedef_declaration_specifier
	: n1:typedef_type_specifier n2:storage_class
	  { fmt28 }
	| n1:declaration_qualifier_list n2:TYPEDEF_NAME
	  { fmt29 }
	| n1:typedef_declaration_specifier n2:declaration_qualifier
	  { fmt30 }
	;

declaration_qualifier_list
	: n1:storage_class n2:attributes_opt
	  { fmt31 }
	| n1:type_qualifier_list n2:attributes_opt n3:storage_class n4:attributes_opt
	  { fmt32 }
	| n1:declaration_qualifier_list n2:declaration_qualifier
	  { fmt33 }
	;

declaration_qualifier
	: n1:type_qualifier
	  { fmt34 }
	| n1:storage_class
	  { fmt35 }
	;

type_specifier
	: n1:type_specifier_nosue
	  { fmt36 }
	| n1:sue_type_specifier
	  { fmt37 }
	;

type_specifier_nosue
	: n1:basic_type_specifier
	  { fmt38 }
	| n1:typedef_type_specifier
	  { fmt39 }
	;

basic_type_specifier
	: n1:basic_type_name
	  { fmt40 }
	| n1:type_qualifier_list n2:basic_type_name
	  { fmt41 }
	| n1:basic_type_specifier n2:type_qualifier
	  { fmt42 }
	| n1:basic_type_specifier n2:basic_type_name
	  { fmt43 }
	;

sue_type_specifier
	: n1:elaborated_type_name
	  { fmt44 }
	| n1:type_qualifier_list n2:elaborated_type_name
	  { fmt45 }
	| n1:sue_type_specifier n2:type_qualifier
	  { fmt46 }
	;

typedef_type_specifier
	: n1:TYPEDEF_NAME
	  { fmt47 }
	| n1:type_qualifier_list n2:TYPEDEF_NAME
	  { fmt48 }
	| n1:typedef_type_specifier n2:type_qualifier
	  { fmt49 }
	;

type_qualifier_list
	: n1:type_qualifier
	  { fmt50 }
	| n1:type_qualifier_list n2:type_qualifier
	  { fmt51 }
	;

pointer_type_qualifier_list
	: n1:pointer_type_qualifier
	  { fmt52 }
	| n1:pointer_type_qualifier_list n2:pointer_type_qualifier
	  { fmt53 }
	;

elaborated_type_name
	: n1:struct_or_union_specifier
	  { fmt54 }
	| n1:enum_specifier
	  { fmt55 }
	;

declarator
	: n1:paren_typedef_declarator
	  { fmt56 }
	| n1:parameter_typedef_declarator
	  { fmt57 }
	| n1:identifier_declarator
	  { fmt58 }
	| n1:old_function_declarator
	  { fmt59 }
	;

paren_typedef_declarator
	: n1:paren_postfix_typedef_declarator
	  { fmt60 }
	| n1:'*' n2:attributes_opt n3:paren_typedef_declarator
	  { fmt61 }
	| n1:'*' n2:attributes_opt n3:'(' n4:simple_paren_typedef_declarator n5:')'
	  { fmt62 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:'(' n5:simple_paren_typedef_declarator n6:')'
	  { fmt63 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:paren_typedef_declarator
	  { fmt64 }
	;

paren_postfix_typedef_declarator
	: n1:'(' n2:paren_typedef_declarator n3:')'
	  { fmt65 }
	| n1:'(' n2:simple_paren_typedef_declarator n3:postfixing_abstract_declarator n4:')'
	  { fmt66 }
	| n1:'(' n2:paren_typedef_declarator n3:')' n4:postfixing_abstract_declarator
	  { fmt67 }
	;

simple_paren_typedef_declarator
	: n1:TYPEDEF_NAME
	  { fmt68 }
	| n1:'(' n2:simple_paren_typedef_declarator n3:')'
	  { fmt69 }
	;

parameter_typedef_declarator
	: n1:TYPEDEF_NAME
	  { fmt70 }
	| n1:TYPEDEF_NAME n2:postfixing_abstract_declarator
	  { fmt71 }
	| n1:clean_typedef_declarator
	  { fmt72 }
	;

clean_typedef_declarator
	: n1:clean_postfix_typedef_declarator
	  { fmt73 }
	| n1:'*' n2:attributes_opt n3:parameter_typedef_declarator
	  { fmt74 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:parameter_typedef_declarator
	  { fmt75 }
	;

clean_postfix_typedef_declarator
	: n1:'(' n2:clean_typedef_declarator n3:')'
	  { fmt76 }
	| n1:'(' n2:clean_typedef_declarator n3:')' n4:postfixing_abstract_declarator
	  { fmt77 }
	;

abstract_declarator
	: n1:unary_abstract_declarator
	  { fmt78 }
	| n1:postfix_abstract_declarator
	  { fmt79 }
	| n1:postfixing_abstract_declarator
	  { fmt80 }
	;

unary_abstract_declarator
	: n1:'*' n2:attributes_opt
	  { pointer }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list
	  { pointer }
	| n1:'*' n2:attributes_opt n4:abstract_declarator
	  { pointer }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:abstract_declarator
	  { pointer }
	;

postfix_abstract_declarator
	: n1:'(' n2:unary_abstract_declarator n3:')'
	  { fmt85 }
	| n1:'(' n2:unary_abstract_declarator n3:')' n4:postfixing_abstract_declarator
	  { fmt88 }
	| n1:'(' n2:postfix_abstract_declarator n3:')'
	  { fmt86 }
	| n1:'(' n2:postfixing_abstract_declarator n3:')'
	  { fmt87 }
	;

postfixing_abstract_declarator
	: n1:array_abstract_declarator
	  { fmt89 }
	| n1:'(' n2:')'
	  { fmt90 }
	| n1:'(' n2:parameter_type_list n3:')'
	  { fmt91 }
	;

identifier_declarator
	: n1:unary_identifier_declarator
	  { fmt92 }
	| n1:paren_identifier_declarator
	  { fmt93 }
	;

unary_identifier_declarator
	: n1:postfix_identifier_declarator
	  { fmt94 }
	| n1:'*' n2:attributes_opt n3:identifier_declarator
	  { fmt95 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:identifier_declarator
	  { fmt96 }
	;

postfix_identifier_declarator
	: n1:paren_identifier_declarator n2:postfixing_abstract_declarator
	  { fmt97 }
	| n1:'(' n2:unary_identifier_declarator n3:')'
	  { fmt98 }
	| n1:'(' n2:unary_identifier_declarator n3:')' n4:postfixing_abstract_declarator
	  { fmt99 }
	;

paren_identifier_declarator
	: n1:IDENTIFIER
	  { fmt100 }
	| n1:'(' n2:paren_identifier_declarator n3:')'
	  { fmt101 }
	 ;

old_function_declarator
	: n1:postfix_old_function_declarator
	  { fmt102 }
	| n1:'*' n2:attributes_opt n3:old_function_declarator
	  { fmt103 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:old_function_declarator
	  { fmt104 }
	;

postfix_old_function_declarator
	: n1:paren_identifier_declarator n2:'(' n3:identifier_list n4:')'
	  { fmt105 }
	| n1:'(' n2:old_function_declarator n3:')'
	  { fmt106 }
	| n1:'(' n2:old_function_declarator n3:')' n4:postfixing_abstract_declarator
	  { fmt107 }
	;

identifier_list
	: n1:IDENTIFIER
	  { fmt108 }
	| n1:identifier_list n2:',' n3:IDENTIFIER
	  { fmt109 }
	;

identifier_or_typedef_name
	: n1:IDENTIFIER
	  { fmt110 }
	| n1:TYPEDEF_NAME
	  { fmt111 }
	;

type_name
	: n1:type_specifier
	  { fmt112 }
	| n1:type_specifier n2:abstract_declarator
	  { fmt113 }
	;


nonnull_expression_list
	: n1:argument_expression_list
	  { fmt114 }
	;

any_word
	: n1:IDENTIFIER
	  { fmt115 }
	| n1:TYPEDEF_NAME
	  { fmt116 }
	| n1:CONST
	  { fmt117 }
	;

initialiser_opt
	: n1:empty
	  { fmt118 }
	| n1:'=' n2:initialiser
	  { fmt119 }
	;

initialiser
	: n1:basic_initialiser
	  { fmt120 }
	| n1:identifier_or_typedef_name n2:':' n3:basic_initialiser
	  { fmt121 }
	| n1:'.' n2:identifier_or_typedef_name n3:'=' n4:basic_initialiser
	  { fmt123 }
	| n1:'[' n2:assignment_expression n3:']' n4:basic_initialiser
	  { fmt125 }
	| n1:'[' n2:assignment_expression n3:']' n4:'=' n5:basic_initialiser
	  { fmt126 }
	| n1:'[' n2:assignment_expression n3:ELLIPSIS n4:assignment_expression n5:']' n6:basic_initialiser
	  { fmt127 }
	;

basic_initialiser
	: n1:bracketed_initialiser_list
	  { fmt128 }
	| n1:assignment_expression
	  { fmt129 }
	;

bracketed_initialiser_list
	: lbrack:'{'                                       rbrack:'}'
	  { bracketed_initialiser_list }
	| lbrack:'{' list:initialiser_list comma:comma_opt rbrack:'}'
	  { bracketed_initialiser_list }
	;

initialiser_list
	: n1:initialiser
	  { fmt133 }
	| n1:initialiser_list n2:',' n3:initialiser
	  { fmt134 }
	;

parameter_type_list
	: n1:parameter_list
	  { fmt135 }
	| n1:parameter_list n2:',' n3:ELLIPSIS
	  { fmt136 }
	;

parameter_list
	: n1:parameter_declaration
	  { fmt137 }
	| n1:parameter_list n2:',' n3:parameter_declaration
	  { fmt138 }
	;

parameter_declaration
	: n1:attributes_opt n2:declaration_specifier
	  { fmt139 }
	| n1:attributes_opt n2:declaration_specifier n3:abstract_declarator
	  { fmt140 }
	| n1:attributes_opt n2:declaration_specifier n3:identifier_declarator
	  { fmt141 }
	| n1:attributes_opt n2:declaration_specifier n3:parameter_typedef_declarator
	  { fmt142 }
	| n1:attributes_opt n2:type_specifier
	  { fmt143 }
	| n1:attributes_opt n2:type_specifier n3:abstract_declarator
	  { fmt144 }
	| n1:attributes_opt n2:type_specifier n3:identifier_declarator n4:attributes_opt
	  { fmt145 }
	| n1:attributes_opt n2:type_specifier n3:parameter_typedef_declarator
	  { fmt146 }
	;

array_abstract_declarator
	:                                lsqbrack:'['                          rsqbrack:']'
	  { array_abstract_declarator }
	|                                lsqbrack:'[' expr:constant_expression rsqbrack:']'
	  { array_abstract_declarator }
	| decl:array_abstract_declarator lsqbrack:'[' expr:constant_expression rsqbrack:']'
	  { array_abstract_declarator }
	| decl:array_abstract_declarator lsqbrack:'['                          rsqbrack:']'
	  { array_abstract_declarator }
	;
