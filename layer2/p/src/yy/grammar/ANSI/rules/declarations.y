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
	: n1:declaration_specifier n2:declarator n3:asm? n4:attributes? n5:decl_initialiser?
	  { declaring_list9 }
	| n1:declaration_specifier_nosue n2:attributes n3:declarator n4:asm? n5:attributes? n6:decl_initialiser?
	  { declaring_list10 }
	| n1:type_specifier n2:declarator n3:asm? n4:attributes? n5:decl_initialiser?
	  { declaring_list11 }
	| n1:type_specifier_nosue n2:attributes n3:declarator n4:asm? n5:attributes? n6:decl_initialiser?
	  { declaring_list12 }
	| n1:declaring_list n2:',' n3:declarator n4:asm? n5:attributes? n6:decl_initialiser?
	  { declaring_list13 }
	;

default_declaring_list
	: n1:declaration_qualifier_list n2:identifier_declarator n3:attributes? n4:decl_initialiser?
	  { default_declaring_list14 }
	| n1:type_qualifier+ n2:identifier_declarator n3:attributes? n4:decl_initialiser?
	  { default_declaring_list15 }
	| n1:default_declaring_list n2:',' n3:identifier_declarator n4:attributes? n5:decl_initialiser?
	  { default_declaring_list16 }
	;

declaration_specifier
	: :declaration_specifier_nosue
	| :sue_declaration_specifier
	;

declaration_specifier_nosue
	: :basic_declaration_specifier
	| :typedef_declaration_specifier
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
	| n1:declaration_qualifier_list n2:elaborated_type_name n3:attributes?
	  { sue_declaration_specifier26 }
	| n1:sue_declaration_specifier n2:declaration_qualifier
	  { sue_declaration_specifier27 }
	;

typedef_declaration_specifier
	: n1:typedef_type_specifier n2:storage_class
	  { typedef_declaration_specifier28 }
	| n1:declaration_qualifier_list n2:typedef_name
	  { typedef_declaration_specifier29 }
	| n1:typedef_declaration_specifier n2:declaration_qualifier
	  { typedef_declaration_specifier30 }
	;

declaration_qualifier_list
	:                                   n3:storage_class n4:attributes?
	  { declaration_qualifier_list31 }
	| n1:type_qualifier+ n2:attributes? n3:storage_class n4:attributes?
	  { declaration_qualifier_list31 }
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
	:                         n2:basic_type_name
	  { basic_type_specifier41 }
	| n1:type_qualifier+      n2:basic_type_name
	  { basic_type_specifier41 }
	| n1:basic_type_specifier n2:type_qualifier
	  { basic_type_specifier42 }
	| n1:basic_type_specifier n2:basic_type_name
	  { basic_type_specifier43 }
	;

sue_type_specifier
	:                       n2:elaborated_type_name
	  { sue_type_specifier44 }
	| n1:type_qualifier+    n2:elaborated_type_name
	  { sue_type_specifier44 }
	| n1:sue_type_specifier n2:type_qualifier
	  { sue_type_specifier46 }
	;

typedef_type_specifier
	:                        n2:typedef_name
	  { typedef_type_specifier47 }
	| n1:type_qualifier+ n2:typedef_name
	  { typedef_type_specifier47 }
	| n1:typedef_type_specifier n2:type_qualifier
	  { typedef_type_specifier49 }
	;

elaborated_type_name
	: :struct_or_union_specifier
	| :enum_specifier
	;

declarator
	: :paren_typedef_declarator
	| :parameter_typedef_declarator %merge <node_merge>
	| :identifier_declarator %merge <node_merge>
	| :old_function_declarator
	;

paren_typedef_declarator
	: n1:paren_postfix_typedef_declarator
	  { paren_typedef_declarator60 }
	| n1:'*' n2:attributes? n3:paren_typedef_declarator
	  { paren_typedef_declarator61 }
	| n1:'*' n2:attributes? n3:'(' n4:simple_paren_typedef_declarator n5:')'
	  { paren_typedef_declarator62 }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:'(' n5:simple_paren_typedef_declarator n6:')'
	  { paren_typedef_declarator63 }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:paren_typedef_declarator
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
	: n1:typedef_name
	  { simple_paren_typedef_declarator68 }
	| n1:'(' n2:simple_paren_typedef_declarator n3:')'
	  { simple_paren_typedef_declarator69 }
	;

parameter_typedef_declarator
	: n1:typedef_name
	  { parameter_typedef_declarator70 }
	| n1:typedef_name n2:postfixing_abstract_declarator
	  { parameter_typedef_declarator71 }
	| n1:clean_typedef_declarator
	  { parameter_typedef_declarator72 }
	;

clean_typedef_declarator
	: n1:clean_postfix_typedef_declarator
	  { clean_typedef_declarator73 }
	| n1:'*' n2:attributes? n3:parameter_typedef_declarator
	  { clean_typedef_declarator74 }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:parameter_typedef_declarator
	  { clean_typedef_declarator75 }
	;

clean_postfix_typedef_declarator
	: n1:'(' n2:clean_typedef_declarator n3:')'
	  { clean_postfix_typedef_declarator76 }
	| n1:'(' n2:clean_typedef_declarator n3:')' n4:postfixing_abstract_declarator
	  { clean_postfix_typedef_declarator77 }
	;

abstract_declarator
	: :unary_abstract_declarator
	| :postfix_abstract_declarator
	| :postfixing_abstract_declarator
	;

unary_abstract_declarator
	: n1:'*' n2:attributes?
	  { pointer }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+
	  { pointer }
	| n1:'*' n2:attributes?                            n4:abstract_declarator
	  { pointer }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:abstract_declarator
	  { pointer }
	;

postfix_abstract_declarator
	: n1:'(' n2:unary_abstract_declarator      n3:')'
	  { postfix_abstract_declarator85 }
	| n1:'(' n2:unary_abstract_declarator      n3:')' n4:postfixing_abstract_declarator
	  { postfix_abstract_declarator88 }
	| n1:'(' n2:postfix_abstract_declarator    n3:')'
	  { postfix_abstract_declarator86 }
	| n1:'(' n2:postfixing_abstract_declarator n3:')'
	  { postfix_abstract_declarator87 }
	;

postfixing_abstract_declarator
	: n1:array_abstract_declarator+
	  { postfixing_abstract_declarator89 }
	| lbrack:'('                            rbrack:')'
	  { postfixing_abstract_declarator90 }
	| lbrack:'(' params:parameter_type_list rbrack:')'
	  { postfixing_abstract_declarator90 }
	;

identifier_declarator
	: :unary_identifier_declarator
	| :paren_identifier_declarator
	;

unary_identifier_declarator
	: n1:postfix_identifier_declarator
	  { unary_identifier_declarator94 }
	| n1:'*' n2:attributes?                            n4:identifier_declarator
	  { unary_identifier_declarator95 }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:identifier_declarator
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
	: n1:identifier
	  { paren_identifier_declarator100 }
	| n1:'(' n2:paren_identifier_declarator n3:')'
	  { paren_identifier_declarator101 }
	 ;

old_function_declarator
	: n1:postfix_old_function_declarator
	  { old_function_declarator102 }
	| n1:'*' n2:attributes?                            n4:old_function_declarator
	  { old_function_declarator103 }
	| n1:'*' n2:attributes? n3:pointer_type_qualifier+ n4:old_function_declarator
	  { old_function_declarator103 }
	;

postfix_old_function_declarator
	: n1:paren_identifier_declarator n2:'(' n3:identifier[',']+ n4:')'
	  { postfix_old_function_declarator105 }
	| n1:'(' n2:old_function_declarator n3:')'
	  { postfix_old_function_declarator106 }
	| n1:'(' n2:old_function_declarator n3:')' n4:postfixing_abstract_declarator
	  { postfix_old_function_declarator106 }
	;

type_name
	: tspec:type_specifier
	  { type_name }
	| tspec:type_specifier decl:abstract_declarator
	  { type_name }
	;


nonnull_expression_list
	: :assignment_expression[',']+
	;

decl_initialiser
	: n1:'=' n2:initialiser
	  { decl_initialiser }
	;

initialiser
	: n1:basic_initialiser
	| n1:identifier_or_typedef_name n2:':' n3:basic_initialiser
	  { initialiser121 }
	| dot:'.' id:identifier_or_typedef_name equals:'=' init:basic_initialiser
	  { designated_initialiser }
	| lsqbrack:'[' expr:assignment_expression                                           rsqbrack:']'            init:basic_initialiser
	  { array_labelled_initialised }
	| lsqbrack:'[' expr:assignment_expression                                           rsqbrack:']' equals:'=' init:basic_initialiser
	  { array_labelled_initialised }
	| lsqbrack:'[' expr:assignment_expression dots:ELLIPSIS expr2:assignment_expression rsqbrack:']'            init:basic_initialiser
	  { array_labelled_initialised }
	;

basic_initialiser
	: :bracketed_initialiser_list
	| :assignment_expression
	;

bracketed_initialiser_list
	: lbrack:'{'                                        rbrack:'}'
	  { bracketed_initialiser_list }
	| lbrack:'{' list:initialiser[',']+ comma:comma_opt rbrack:'}'
	  { bracketed_initialiser_list }
	;

parameter_type_list
	: n1:parameter_declaration[',']+
	  { parameter_type_list135 }
	| n1:parameter_declaration[',']+ n2:',' n3:ELLIPSIS
	  { parameter_type_list135 }
	;

parameter_declaration
	: n1:attributes? n2:declaration_specifier
	  { parameter_declaration139 }
	| n1:attributes? n2:declaration_specifier n3:abstract_declarator
	  { parameter_declaration140 }
	| n1:attributes? n2:declaration_specifier n3:identifier_declarator
	  { parameter_declaration141 }
	| n1:attributes? n2:declaration_specifier n3:parameter_typedef_declarator
	  { parameter_declaration142 }
	| n1:attributes? n2:type_specifier
	  { parameter_declaration143 }
	| n1:attributes? n2:type_specifier n3:abstract_declarator
	  { parameter_declaration144 }
	| n1:attributes? n2:type_specifier n3:identifier_declarator n4:attributes? %merge <node_merge>
	  { parameter_declaration145 }
	| n1:attributes? n2:type_specifier n3:parameter_typedef_declarator %merge <node_merge>
	  { parameter_declaration146 }
	;

array_abstract_declarator
	: lsqbrack:'['                          rsqbrack:']'
	  { array_abstract_declarator }
	| lsqbrack:'[' expr:constant_expression rsqbrack:']'
	  { array_abstract_declarator }
	;
