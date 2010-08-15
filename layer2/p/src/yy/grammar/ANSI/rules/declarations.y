%%
%%

declaration
	: declrs:declaring_list           semi:';'
	  { declaration1 }
	| declrs:default_declaring_list   semi:';'
	  { declaration2 }
	| dspec:sue_declaration_specifier semi:';'
	  { declaration3 }
	| tspec:sue_type_specifier        semi:';'
	  { declaration4 }
	| dspec:declaration_specifier                        id:identifier_declarator body:compound_statement
	  { declaration5 }
	| dspec:declaration_specifier_nosue attrs:attributes id:identifier_declarator body:compound_statement
	  { declaration5 }
	| tspec:type_specifier                               id:identifier_declarator body:compound_statement
	  { declaration6 }
	| tspec:type_specifier_nosue        attrs:attributes id:identifier_declarator body:compound_statement
	  { declaration6 }
	;


declaring_list
	: dspec:declaration_specifier                        declr:declarator register:asm? attrs2:attributes? init:decl_initialiser?
	  { declaring_list9 }
	| dspec:declaration_specifier_nosue attrs:attributes declr:declarator register:asm? attrs2:attributes? init:decl_initialiser?
	  { declaring_list10 }
	| tspec:type_specifier                               declr:declarator register:asm? attrs2:attributes? init:decl_initialiser?
	  { declaring_list11 }
	| tspec:type_specifier_nosue attrs:attributes        declr:declarator register:asm? attrs2:attributes? init:decl_initialiser?
	  { declaring_list12 }
	| prev:declaring_list sep:','                        declr:declarator register:asm? attrs2:attributes? init:decl_initialiser?
	  { declaring_list13 }
	;

default_declaring_list
	: dquals:declaration_qualifier_list   id:identifier_declarator attrs:attributes? init:decl_initialiser?
	  { default_declaring_list14 }
	| tquals:type_qualifier+              id:identifier_declarator attrs:attributes? init:decl_initialiser?
	  { default_declaring_list15 }
	| prev:default_declaring_list sep:',' id:identifier_declarator attrs:attributes? init:decl_initialiser?
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
	: tspec:basic_type_specifier str_class:storage_class
	  { basic_declaration_specifier21 }
	| dquals:declaration_qualifier_list tname:basic_type_name
	  { basic_declaration_specifier22 }
	| dspec:basic_declaration_specifier dqual:declaration_qualifier
	  { basic_declaration_specifier23 }
	| dspec:basic_declaration_specifier tname:basic_type_name
	  { basic_declaration_specifier24 }
	;

sue_declaration_specifier
	: tspec:sue_type_specifier str_class:storage_class
	  { sue_declaration_specifier25 }
	| dquals:declaration_qualifier_list tname:elaborated_type_name attrs:attributes?
	  { sue_declaration_specifier26 }
	| dspec:sue_declaration_specifier dqual:declaration_qualifier
	  { sue_declaration_specifier27 }
	;

typedef_declaration_specifier
	: tspec:typedef_type_specifier str_class:storage_class
	  { typedef_declaration_specifier28 }
	| dquals:declaration_qualifier_list tname:typedef_name
	  { typedef_declaration_specifier29 }
	| dspec:typedef_declaration_specifier dqual:declaration_qualifier
	  { typedef_declaration_specifier30 }
	;

declaration_qualifier_list
	:                                          str_class:storage_class attrs2:attributes?
	  { declaration_qualifier_list31 }
	| tquals:type_qualifier+ attrs:attributes? str_class:storage_class attrs2:attributes?
	  { declaration_qualifier_list31 }
	| dquals:declaration_qualifier_list dqual:declaration_qualifier
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
	:                        tname:basic_type_name
	  { basic_type_specifier41 }
	| tquals:type_qualifier+ tname:basic_type_name
	  { basic_type_specifier41 }
	| tspec:basic_type_specifier tqual:type_qualifier
	  { basic_type_specifier42 }
	| tspec:basic_type_specifier tname:basic_type_name
	  { basic_type_specifier43 }
	;

sue_type_specifier
	:                        tname:elaborated_type_name
	  { sue_type_specifier44 }
	| tquals:type_qualifier+ tname:elaborated_type_name
	  { sue_type_specifier44 }
	| tspec:sue_type_specifier tqual:type_qualifier
	  { sue_type_specifier46 }
	;

typedef_type_specifier
	:                        tname:typedef_name
	  { typedef_type_specifier47 }
	| tquals:type_qualifier+ tname:typedef_name
	  { typedef_type_specifier47 }
	| tspec:typedef_type_specifier tqual:type_qualifier
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
	| :old_function_declarator %merge <node_merge>
	;

paren_typedef_declarator
	: :paren_postfix_typedef_declarator
	| star:'*' attrs:attributes?                                           tdeclr:paren_typedef_declarator
	  { paren_typedef_declarator }
	| star:'*' attrs:attributes?                                lbrack:'(' tdeclr:simple_paren_typedef_declarator rbrack:')'
	  { paren_typedef_declarator }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+ lbrack:'(' tdeclr:simple_paren_typedef_declarator rbrack:')'
	  { paren_typedef_declarator }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+            tdeclr:paren_typedef_declarator
	  { paren_typedef_declarator }
	;

paren_postfix_typedef_declarator
	: lbrack:'(' tdeclr:paren_typedef_declarator                                                  rbrack:')'
	  { paren_postfix_typedef_declarator }
	| lbrack:'(' tdeclr:simple_paren_typedef_declarator post_declr:postfixing_abstract_declarator rbrack:')'
	  { paren_postfix_typedef_declarator }
	| lbrack:'(' tdeclr:paren_typedef_declarator                                                  rbrack:')' post_declr2:postfixing_abstract_declarator
	  { paren_postfix_typedef_declarator }
	;

simple_paren_typedef_declarator
	: :typedef_name
	| lbrack:'(' tdeclr:simple_paren_typedef_declarator rbrack:')'
	  { simple_paren_typedef_declarator }
	;

parameter_typedef_declarator
	: tname:typedef_name
	  { parameter_typedef_declarator70 }
	| tname:typedef_name post_declr:postfixing_abstract_declarator
	  { parameter_typedef_declarator71 }
	| :clean_typedef_declarator
	;

clean_typedef_declarator
	: :clean_postfix_typedef_declarator
	| star:'*' attrs:attributes?                                tdeclr:parameter_typedef_declarator
	  { clean_typedef_declarator }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+ tdeclr:parameter_typedef_declarator
	  { clean_typedef_declarator }
	;

clean_postfix_typedef_declarator
	: lbrack:'(' tdeclr:clean_typedef_declarator rbrack:')'
	  { clean_postfix_typedef_declarator }
	| lbrack:'(' tdeclr:clean_typedef_declarator rbrack:')' post_declr:postfixing_abstract_declarator
	  { clean_postfix_typedef_declarator }
	;

abstract_declarator
	: :unary_abstract_declarator
	| :postfix_abstract_declarator
	| :postfixing_abstract_declarator
	;

unary_abstract_declarator
	: star:'*' attrs:attributes?
	  { pointer }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+
	  { pointer }
	| star:'*' attrs:attributes?                                declr:abstract_declarator
	  { pointer }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+ declr:abstract_declarator
	  { pointer }
	;

postfix_abstract_declarator
	: lbrack:'(' declr:unary_abstract_declarator      rbrack:')'
	  { postfix_abstract_declarator }
	| lbrack:'(' declr:unary_abstract_declarator      rbrack:')' post_declr:postfixing_abstract_declarator
	  { postfix_abstract_declarator }
	| lbrack:'(' declr:postfix_abstract_declarator    rbrack:')'
	  { postfix_abstract_declarator }
	| lbrack:'(' declr:postfixing_abstract_declarator rbrack:')'
	  { postfix_abstract_declarator }
	;

postfixing_abstract_declarator
	: :array_abstract_declarator+
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
	: :postfix_identifier_declarator
	| star:'*' attrs:attributes?                                id:identifier_declarator
	  { unary_identifier_declarator }
	| star:'*' attrs:attributes? tquals:pointer_type_qualifier+ id:identifier_declarator
	  { unary_identifier_declarator }
	;

postfix_identifier_declarator
	:            declr:paren_identifier_declarator            post_declr:postfixing_abstract_declarator
	  { postfix_identifier_declarator }
	| lbrack:'(' declr:unary_identifier_declarator rbrack:')'
	  { postfix_identifier_declarator }
	| lbrack:'(' declr:unary_identifier_declarator rbrack:')' post_declr:postfixing_abstract_declarator
	  { postfix_identifier_declarator }
	;

paren_identifier_declarator
	:            id:identifier
	  { paren_identifier_declarator }
	| lbrack:'(' id:paren_identifier_declarator rbrack:')'
	  { paren_identifier_declarator }
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
	: equals:'=' init:initialiser
	  { decl_initialiser }
	;

initialiser
	: :basic_initialiser
	| id:identifier colon:':' init:basic_initialiser
	  { initialiser121 }
	| dot:'.' id:identifier equals:'=' init:basic_initialiser
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
	: decls:parameter_declaration[',']+
	  { parameter_type_list }
	| decls:parameter_declaration[',']+ comma:',' ellipsis:ELLIPSIS
	  { parameter_type_list }
	;

parameter_declaration
	: attrs:attributes? dspec:declaration_specifier
	  { parameter_declaration }
	| attrs:attributes? dspec:declaration_specifier declr:abstract_declarator
	  { parameter_declaration }
	| attrs:attributes? dspec:declaration_specifier declr:identifier_declarator
	  { parameter_declaration }
	| attrs:attributes? dspec:declaration_specifier declr:parameter_typedef_declarator
	  { parameter_declaration }
	| attrs:attributes? tspec:type_specifier
	  { parameter_declaration }
	| attrs:attributes? tspec:type_specifier declr:abstract_declarator
	  { parameter_declaration }
	| attrs:attributes? tspec:type_specifier declr:identifier_declarator %merge <node_merge>
	  { parameter_declaration }
	| attrs:attributes? tspec:type_specifier declr:parameter_typedef_declarator %merge <node_merge>
	  { parameter_declaration }
	;

array_abstract_declarator
	: lsqbrack:'['                          rsqbrack:']'
	  { array_abstract_declarator }
	| lsqbrack:'[' expr:constant_expression rsqbrack:']'
	  { array_abstract_declarator }
	;
