%%
%%

declaration
	: n1:declaring_list n2:';'
	  { declaration1 }
	| n1:default_declaring_list n2:';'
	  { declaration2 }
	| n1:sue_declaration_specifier n2:';'
	  { declaration3 }
	| n1:sue_type_specifier n2:';'
	  { declaration4 }
	| n1:declaration_specifier n2:identifier_declarator n3:compound_statement
	  { declaration5 }
	| n1:declaration_specifier_nosue n2:attributes n3:identifier_declarator n4:compound_statement
	  { declaration6 }
	| n1:type_specifier n2:identifier_declarator n3:compound_statement
	  { declaration7 }
	| n1:type_specifier_nosue n2:attributes n3:identifier_declarator n4:compound_statement
	  { declaration8 }
	;


declaring_list
	: n1:declaration_specifier n2:declarator n3:asm_opt n4:attributes_opt n5:initialiser_opt
	  { declaring_list9 }
	| n1:declaration_specifier_nosue n2:attributes n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { declaring_list10 }
	| n1:type_specifier n2:declarator n3:asm_opt n4:attributes_opt n5:initialiser_opt
	  { declaring_list11 }
	| n1:type_specifier_nosue n2:attributes n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { declaring_list12 }
	| n1:declaring_list n2:',' n3:declarator n4:asm_opt n5:attributes_opt n6:initialiser_opt
	  { declaring_list13 }
	;

default_declaring_list
	: n1:declaration_qualifier_list n2:identifier_declarator n3:attributes_opt n4:initialiser_opt
	  { default_declaring_list14 }
	| n1:type_qualifier_list n2:identifier_declarator n3:attributes_opt n4:initialiser_opt
	  { default_declaring_list15 }
	| n1:default_declaring_list n2:',' n3:identifier_declarator n4:attributes_opt n5:initialiser_opt
	  { default_declaring_list16 }
	;

declaration_specifier
	: n1:declaration_specifier_nosue
	  { declaration_specifier17 }
	| n1:sue_declaration_specifier
	  { declaration_specifier18 }
	;

declaration_specifier_nosue
	: n1:basic_declaration_specifier
	  { declaration_specifier_nosue19 }
	| n1:typedef_declaration_specifier
	  { declaration_specifier_nosue20 }
	;

basic_declaration_specifier
	: n1:basic_type_specifier n2:storage_class
	  { basic_declaration_specifier21 }
	| n1:declaration_qualifier_list n2:basic_type_name
	  { basic_declaration_specifier22 }
	| n1:basic_declaration_specifier n2:declaration_qualifier
	  { basic_declaration_specifier23 }
	| n1:basic_declaration_specifier n2:basic_type_name
	  { basic_declaration_specifier24 }
	;

sue_declaration_specifier
	: n1:sue_type_specifier n2:storage_class
	  { sue_declaration_specifier25 }
	| n1:declaration_qualifier_list n2:elaborated_type_name n3:attributes_opt
	  { sue_declaration_specifier26 }
	| n1:sue_declaration_specifier n2:declaration_qualifier
	  { sue_declaration_specifier27 }
	;

typedef_declaration_specifier
	: n1:typedef_type_specifier n2:storage_class
	  { typedef_declaration_specifier28 }
	| n1:declaration_qualifier_list n2:TYPEDEF_NAME
	  { typedef_declaration_specifier29 }
	| n1:typedef_declaration_specifier n2:declaration_qualifier
	  { typedef_declaration_specifier30 }
	;

declaration_qualifier_list
	: n1:storage_class n2:attributes_opt
	  { declaration_qualifier_list31 }
	| n1:type_qualifier_list n2:attributes_opt n3:storage_class n4:attributes_opt
	  { declaration_qualifier_list32 }
	| n1:declaration_qualifier_list n2:declaration_qualifier
	  { declaration_qualifier_list33 }
	;

declaration_qualifier
	: :type_qualifier
	| :storage_class
	;

type_specifier
	: :type_specifier_nosue
	| :sue_type_specifier
	;

type_specifier_nosue
	: :basic_type_specifier
	| :typedef_type_specifier
	;

basic_type_specifier
	: n1:basic_type_name
	  { basic_type_specifier40 }
	| n1:type_qualifier_list n2:basic_type_name
	  { basic_type_specifier41 }
	| n1:basic_type_specifier n2:type_qualifier
	  { basic_type_specifier42 }
	| n1:basic_type_specifier n2:basic_type_name
	  { basic_type_specifier43 }
	;

sue_type_specifier
	: n1:elaborated_type_name
	  { sue_type_specifier44 }
	| n1:type_qualifier_list n2:elaborated_type_name
	  { sue_type_specifier45 }
	| n1:sue_type_specifier n2:type_qualifier
	  { sue_type_specifier46 }
	;

typedef_type_specifier
	: n1:TYPEDEF_NAME
	  { typedef_type_specifier47 }
	| n1:type_qualifier_list n2:TYPEDEF_NAME
	  { typedef_type_specifier48 }
	| n1:typedef_type_specifier n2:type_qualifier
	  { typedef_type_specifier49 }
	;

type_qualifier_list
	:                          qual:type_qualifier
	  { type_qualifier_list }
	| prev:type_qualifier_list qual:type_qualifier
	  { type_qualifier_list }
	;

pointer_type_qualifier_list
	:                                  qual:pointer_type_qualifier
	  { pointer_type_qualifier_list }
	| prev:pointer_type_qualifier_list qual:pointer_type_qualifier
	  { pointer_type_qualifier_list }
	;

elaborated_type_name
	: :struct_or_union_specifier
	| :enum_specifier
	;

declarator
	: :paren_typedef_declarator
	| :parameter_typedef_declarator
	| :identifier_declarator
	| :old_function_declarator
	;

paren_typedef_declarator
	: n1:paren_postfix_typedef_declarator
	  { paren_typedef_declarator60 }
	| n1:'*' n2:attributes_opt n3:paren_typedef_declarator
	  { paren_typedef_declarator61 }
	| n1:'*' n2:attributes_opt n3:'(' n4:simple_paren_typedef_declarator n5:')'
	  { paren_typedef_declarator62 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:'(' n5:simple_paren_typedef_declarator n6:')'
	  { paren_typedef_declarator63 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:paren_typedef_declarator
	  { paren_typedef_declarator64 }
	;

paren_postfix_typedef_declarator
	: n1:'(' n2:paren_typedef_declarator n3:')'
	  { paren_postfix_typedef_declarator65 }
	| n1:'(' n2:simple_paren_typedef_declarator n3:postfixing_abstract_declarator n4:')'
	  { paren_postfix_typedef_declarator66 }
	| n1:'(' n2:paren_typedef_declarator n3:')' n4:postfixing_abstract_declarator
	  { paren_postfix_typedef_declarator67 }
	;

simple_paren_typedef_declarator
	: n1:TYPEDEF_NAME
	  { simple_paren_typedef_declarator68 }
	| n1:'(' n2:simple_paren_typedef_declarator n3:')'
	  { simple_paren_typedef_declarator69 }
	;

parameter_typedef_declarator
	: n1:TYPEDEF_NAME
	  { parameter_typedef_declarator70 }
	| n1:TYPEDEF_NAME n2:postfixing_abstract_declarator
	  { parameter_typedef_declarator71 }
	| n1:clean_typedef_declarator
	  { parameter_typedef_declarator72 }
	;

clean_typedef_declarator
	: n1:clean_postfix_typedef_declarator
	  { clean_typedef_declarator73 }
	| n1:'*' n2:attributes_opt n3:parameter_typedef_declarator
	  { clean_typedef_declarator74 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:parameter_typedef_declarator
	  { clean_typedef_declarator75 }
	;

clean_postfix_typedef_declarator
	: n1:'(' n2:clean_typedef_declarator n3:')'
	  { clean_postfix_typedef_declarator76 }
	| n1:'(' n2:clean_typedef_declarator n3:')' n4:postfixing_abstract_declarator
	  { clean_postfix_typedef_declarator77 }
	;

abstract_declarator
	: n1:unary_abstract_declarator
	  { abstract_declarator78 }
	| n1:postfix_abstract_declarator
	  { abstract_declarator79 }
	| n1:postfixing_abstract_declarator
	  { abstract_declarator80 }
	;

unary_abstract_declarator
	: n1:'*' n2:attributes_opt
	  { pointer }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list
	  { pointer }
	| n1:'*' n2:attributes_opt                                n4:abstract_declarator
	  { pointer }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:abstract_declarator
	  { pointer }
	;

postfix_abstract_declarator
	: n1:'(' n2:unary_abstract_declarator n3:')'
	  { postfix_abstract_declarator85 }
	| n1:'(' n2:unary_abstract_declarator n3:')' n4:postfixing_abstract_declarator
	  { postfix_abstract_declarator88 }
	| n1:'(' n2:postfix_abstract_declarator n3:')'
	  { postfix_abstract_declarator86 }
	| n1:'(' n2:postfixing_abstract_declarator n3:')'
	  { postfix_abstract_declarator87 }
	;

postfixing_abstract_declarator
	: n1:array_abstract_declarator_list
	  { postfixing_abstract_declarator89 }
	| n1:'('                        n3:')'
	  { postfixing_abstract_declarator90 }
	| n1:'(' n2:parameter_type_list n3:')'
	  { postfixing_abstract_declarator90 }
	;

identifier_declarator
	: :unary_identifier_declarator
	| :paren_identifier_declarator
	;

unary_identifier_declarator
	: n1:postfix_identifier_declarator
	  { unary_identifier_declarator94 }
	| n1:'*' n2:attributes_opt                                n4:identifier_declarator
	  { unary_identifier_declarator95 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:identifier_declarator
	  { unary_identifier_declarator95 }
	;

postfix_identifier_declarator
	: n1:paren_identifier_declarator n2:postfixing_abstract_declarator
	  { postfix_identifier_declarator97 }
	| n1:'(' n2:unary_identifier_declarator n3:')'
	  { postfix_identifier_declarator98 }
	| n1:'(' n2:unary_identifier_declarator n3:')' n4:postfixing_abstract_declarator
	  { postfix_identifier_declarator99 }
	;

paren_identifier_declarator
	: n1:IDENTIFIER
	  { paren_identifier_declarator100 }
	| n1:'(' n2:paren_identifier_declarator n3:')'
	  { paren_identifier_declarator101 }
	 ;

old_function_declarator
	: n1:postfix_old_function_declarator
	  { old_function_declarator102 }
	| n1:'*' n2:attributes_opt                                n4:old_function_declarator
	  { old_function_declarator103 }
	| n1:'*' n2:attributes_opt n3:pointer_type_qualifier_list n4:old_function_declarator
	  { old_function_declarator103 }
	;

postfix_old_function_declarator
	: n1:paren_identifier_declarator n2:'(' n3:identifier_list n4:')'
	  { postfix_old_function_declarator105 }
	| n1:'(' n2:old_function_declarator n3:')'
	  { postfix_old_function_declarator106 }
	| n1:'(' n2:old_function_declarator n3:')' n4:postfixing_abstract_declarator
	  { postfix_old_function_declarator106 }
	;

identifier_list
	:                                id:IDENTIFIER
	  { identifier_list }
	| prev:identifier_list comma:',' id:IDENTIFIER
	  { identifier_list }
	;

identifier_or_typedef_name
	: :IDENTIFIER
	| :TYPEDEF_NAME
	;

type_name
	: tspec:type_specifier
	  { type_name }
	| tspec:type_specifier decl:abstract_declarator
	  { type_name }
	;


nonnull_expression_list
	: :argument_expression_list
	;

any_word
	: n1:IDENTIFIER
	  { any_word115 }
	| n1:TYPEDEF_NAME
	  { any_word116 }
	| n1:CONST
	  { any_word117 }
	;

initialiser_opt
	: n1:empty
	  { initialiser_opt118 }
	| n1:'=' n2:initialiser
	  { initialiser_opt119 }
	;

initialiser
	: n1:basic_initialiser
	| n1:identifier_or_typedef_name n2:':' n3:basic_initialiser
	  { initialiser121 }
	| n1:'.' n2:identifier_or_typedef_name n3:'=' n4:basic_initialiser
	  { designated_initialiser }
	| n1:'[' n2:assignment_expression                                      n5:']'        n7:basic_initialiser
	  { array_labelled_initialised }
	| n1:'[' n2:assignment_expression                                      n5:']' n6:'=' n7:basic_initialiser
	  { array_labelled_initialised }
	| n1:'[' n2:assignment_expression n3:ELLIPSIS n4:assignment_expression n5:']'        n7:basic_initialiser
	  { array_labelled_initialised }
	;

basic_initialiser
	: :bracketed_initialiser_list
	| :assignment_expression
	;

bracketed_initialiser_list
	: lbrack:'{'                                       rbrack:'}'
	  { bracketed_initialiser_list }
	| lbrack:'{' list:initialiser_list comma:comma_opt rbrack:'}'
	  { bracketed_initialiser_list }
	;

initialiser_list
	:                                 init:initialiser
	  { initialiser_list }
	| prev:initialiser_list comma:',' init:initialiser
	  { initialiser_list }
	;

parameter_type_list
	: n1:parameter_list
	  { parameter_type_list135 }
	| n1:parameter_list n2:',' n3:ELLIPSIS
	  { parameter_type_list135 }
	;

parameter_list
	:                               param:parameter_declaration
	  { parameter_list }
	| prev:parameter_list comma:',' param:parameter_declaration
	  { parameter_list }
	;

parameter_declaration
	: n1:attributes_opt n2:declaration_specifier
	  { parameter_declaration139 }
	| n1:attributes_opt n2:declaration_specifier n3:abstract_declarator
	  { parameter_declaration140 }
	| n1:attributes_opt n2:declaration_specifier n3:identifier_declarator
	  { parameter_declaration141 }
	| n1:attributes_opt n2:declaration_specifier n3:parameter_typedef_declarator
	  { parameter_declaration142 }
	| n1:attributes_opt n2:type_specifier
	  { parameter_declaration143 }
	| n1:attributes_opt n2:type_specifier n3:abstract_declarator
	  { parameter_declaration144 }
	| n1:attributes_opt n2:type_specifier n3:identifier_declarator n4:attributes_opt
	  { parameter_declaration145 }
	| n1:attributes_opt n2:type_specifier n3:parameter_typedef_declarator
	  { parameter_declaration146 }
	;

array_abstract_declarator_list
	: decl:array_abstract_declarator
	  { array_abstract_declarator_list }
	| prev:array_abstract_declarator_list decl:array_abstract_declarator
	  { array_abstract_declarator_list }
	;

array_abstract_declarator
	: lsqbrack:'['                          rsqbrack:']'
	  { array_abstract_declarator }
	| lsqbrack:'[' expr:constant_expression rsqbrack:']'
	  { array_abstract_declarator }
	;
