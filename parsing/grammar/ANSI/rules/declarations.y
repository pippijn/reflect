%%
%%

declaration
	: declaring_list ';'
	  { $$ = pt_fmt1_new ($1, $2); }
	| default_declaring_list ';'
	  { $$ = pt_fmt2_new ($1, $2); }
	| sue_declaration_specifier ';'
	  { $$ = pt_fmt3_new ($1, $2); }
	| sue_type_specifier ';'
	  { $$ = pt_fmt4_new ($1, $2); }
	| declaration_specifier identifier_declarator compound_statement
	  { $$ = pt_fmt5_new ($1, $2, $3); }
	| declaration_specifier_nosue attributes identifier_declarator compound_statement
	  { $$ = pt_fmt6_new ($1, $2, $3, $4); }
	| type_specifier identifier_declarator compound_statement
	  { $$ = pt_fmt7_new ($1, $2, $3); }
	| type_specifier_nosue attributes identifier_declarator compound_statement
	  { $$ = pt_fmt8_new ($1, $2, $3, $4); }
	;


declaring_list
	: declaration_specifier declarator asm_opt attributes_opt initialiser_opt
	  { $$ = pt_fmt9_new ($1, $2, $3, $4, $5); }
	| declaration_specifier_nosue attributes declarator asm_opt attributes_opt initialiser_opt
	  { $$ = pt_fmt10_new ($1, $2, $3, $4, $5, $6); }
	| type_specifier declarator asm_opt attributes_opt initialiser_opt
	  { $$ = pt_fmt11_new ($1, $2, $3, $4, $5); }
	| type_specifier_nosue attributes declarator asm_opt attributes_opt initialiser_opt
	  { $$ = pt_fmt12_new ($1, $2, $3, $4, $5, $6); }
	| declaring_list ',' declarator asm_opt attributes_opt initialiser_opt
	  { $$ = pt_fmt13_new ($1, $2, $3, $4, $5, $6); }
	;

default_declaring_list
	: declaration_qualifier_list identifier_declarator attributes_opt initialiser_opt
	  { $$ = pt_fmt14_new ($1, $2, $3, $4); }
	| type_qualifier_list identifier_declarator attributes_opt initialiser_opt
	  { $$ = pt_fmt15_new ($1, $2, $3, $4); }
	| default_declaring_list ',' identifier_declarator attributes_opt initialiser_opt
	  { $$ = pt_fmt16_new ($1, $2, $3, $4, $5); }
	;

declaration_specifier
	: declaration_specifier_nosue
	  { $$ = pt_fmt17_new ($1); }
	| sue_declaration_specifier
	  { $$ = pt_fmt18_new ($1); }
	;

declaration_specifier_nosue
	: basic_declaration_specifier
	  { $$ = pt_fmt19_new ($1); }
	| typedef_declaration_specifier
	  { $$ = pt_fmt20_new ($1); }
	;

basic_declaration_specifier
	: basic_type_specifier storage_class
	  { $$ = pt_fmt21_new ($1, $2); }
	| declaration_qualifier_list basic_type_name
	  { $$ = pt_fmt22_new ($1, $2); }
	| basic_declaration_specifier declaration_qualifier
	  { $$ = pt_fmt23_new ($1, $2); }
	| basic_declaration_specifier basic_type_name
	  { $$ = pt_fmt24_new ($1, $2); }
	;

sue_declaration_specifier
	: sue_type_specifier storage_class
	  { $$ = pt_fmt25_new ($1, $2); }
	| declaration_qualifier_list elaborated_type_name attributes_opt
	  { $$ = pt_fmt26_new ($1, $2, $3); }
	| sue_declaration_specifier declaration_qualifier
	  { $$ = pt_fmt27_new ($1, $2); }
	;

typedef_declaration_specifier
	: typedef_type_specifier storage_class
	  { $$ = pt_fmt28_new ($1, $2); }
	| declaration_qualifier_list TYPEDEF_NAME
	  { $$ = pt_fmt29_new ($1, $2); }
	| typedef_declaration_specifier declaration_qualifier
	  { $$ = pt_fmt30_new ($1, $2); }
	;

declaration_qualifier_list
	: storage_class attributes_opt
	  { $$ = pt_fmt31_new ($1, $2); }
	| type_qualifier_list attributes_opt storage_class attributes_opt
	  { $$ = pt_fmt32_new ($1, $2, $3, $4); }
	| declaration_qualifier_list declaration_qualifier
	  { $$ = pt_fmt33_new ($1, $2); }
	;

declaration_qualifier
	: type_qualifier
	  { $$ = pt_fmt34_new ($1); }
	| storage_class
	  { $$ = pt_fmt35_new ($1); }
	;

type_specifier
	: type_specifier_nosue
	  { $$ = pt_fmt36_new ($1); }
	| sue_type_specifier
	  { $$ = pt_fmt37_new ($1); }
	;

type_specifier_nosue
	: basic_type_specifier
	  { $$ = pt_fmt38_new ($1); }
	| typedef_type_specifier
	  { $$ = pt_fmt39_new ($1); }
	;

basic_type_specifier
	: basic_type_name
	  { $$ = pt_fmt40_new ($1); }
	| type_qualifier_list basic_type_name
	  { $$ = pt_fmt41_new ($1, $2); }
	| basic_type_specifier type_qualifier
	  { $$ = pt_fmt42_new ($1, $2); }
	| basic_type_specifier basic_type_name
	  { $$ = pt_fmt43_new ($1, $2); }
	;

sue_type_specifier
	: elaborated_type_name
	  { $$ = pt_fmt44_new ($1); }
	| type_qualifier_list elaborated_type_name
	  { $$ = pt_fmt45_new ($1, $2); }
	| sue_type_specifier type_qualifier
	  { $$ = pt_fmt46_new ($1, $2); }
	;

typedef_type_specifier
	: TYPEDEF_NAME
	  { $$ = pt_fmt47_new ($1); }
	| type_qualifier_list TYPEDEF_NAME
	  { $$ = pt_fmt48_new ($1, $2); }
	| typedef_type_specifier type_qualifier
	  { $$ = pt_fmt49_new ($1, $2); }
	;

type_qualifier_list
	: type_qualifier
	  { $$ = pt_fmt50_new ($1); }
	| type_qualifier_list type_qualifier
	  { $$ = pt_fmt51_new ($1, $2); }
	;

pointer_type_qualifier_list
	: pointer_type_qualifier
	  { $$ = pt_fmt52_new ($1); }
	| pointer_type_qualifier_list pointer_type_qualifier
	  { $$ = pt_fmt53_new ($1, $2); }
	;

elaborated_type_name
	: struct_or_union_specifier
	  { $$ = pt_fmt54_new ($1); }
	| enum_specifier
	  { $$ = pt_fmt55_new ($1); }
	;

declarator
	: paren_typedef_declarator
	  { $$ = pt_fmt56_new ($1); }
	| parameter_typedef_declarator
	  { $$ = pt_fmt57_new ($1); }
	| identifier_declarator
	  { $$ = pt_fmt58_new ($1); }
	| old_function_declarator
	  { $$ = pt_fmt59_new ($1); }
	;

paren_typedef_declarator
	: paren_postfix_typedef_declarator
	  { $$ = pt_fmt60_new ($1); }
	| '*' attributes_opt paren_typedef_declarator
	  { $$ = pt_fmt61_new ($1, $2, $3); }
	| '*' attributes_opt '(' simple_paren_typedef_declarator ')'
	  { $$ = pt_fmt62_new ($1, $2, $3, $4, $5); }
	| '*' attributes_opt pointer_type_qualifier_list '(' simple_paren_typedef_declarator ')'
	  { $$ = pt_fmt63_new ($1, $2, $3, $4, $5, $6); }
	| '*' attributes_opt pointer_type_qualifier_list paren_typedef_declarator
	  { $$ = pt_fmt64_new ($1, $2, $3, $4); }
	;

paren_postfix_typedef_declarator
	: '(' paren_typedef_declarator ')'
	  { $$ = pt_fmt65_new ($1, $2, $3); }
	| '(' simple_paren_typedef_declarator postfixing_abstract_declarator ')'
	  { $$ = pt_fmt66_new ($1, $2, $3, $4); }
	| '(' paren_typedef_declarator ')' postfixing_abstract_declarator
	  { $$ = pt_fmt67_new ($1, $2, $3, $4); }
	;

simple_paren_typedef_declarator
	: TYPEDEF_NAME
	  { $$ = pt_fmt68_new ($1); }
	| '(' simple_paren_typedef_declarator ')'
	  { $$ = pt_fmt69_new ($1, $2, $3); }
	;

parameter_typedef_declarator
	: TYPEDEF_NAME
	  { $$ = pt_fmt70_new ($1); }
	| TYPEDEF_NAME postfixing_abstract_declarator
	  { $$ = pt_fmt71_new ($1, $2); }
	| clean_typedef_declarator
	  { $$ = pt_fmt72_new ($1); }
	;

clean_typedef_declarator
	: clean_postfix_typedef_declarator
	  { $$ = pt_fmt73_new ($1); }
	| '*' attributes_opt parameter_typedef_declarator
	  { $$ = pt_fmt74_new ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list parameter_typedef_declarator
	  { $$ = pt_fmt75_new ($1, $2, $3, $4); }
	;

clean_postfix_typedef_declarator
	: '(' clean_typedef_declarator ')'
	  { $$ = pt_fmt76_new ($1, $2, $3); }
	| '(' clean_typedef_declarator ')' postfixing_abstract_declarator
	  { $$ = pt_fmt77_new ($1, $2, $3, $4); }
	;

abstract_declarator
	: unary_abstract_declarator
	  { $$ = pt_fmt78_new ($1); }
	| postfix_abstract_declarator
	  { $$ = pt_fmt79_new ($1); }
	| postfixing_abstract_declarator
	  { $$ = pt_fmt80_new ($1); }
	;

unary_abstract_declarator
	: '*' attributes_opt
	  { $$ = pt_fmt81_new ($1, $2); }
	| '*' attributes_opt pointer_type_qualifier_list
	  { $$ = pt_fmt82_new ($1, $2, $3); }
	| '*' attributes_opt abstract_declarator
	  { $$ = pt_fmt83_new ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list abstract_declarator
	  { $$ = pt_fmt84_new ($1, $2, $3, $4); }
	;

postfix_abstract_declarator
	: '(' unary_abstract_declarator ')'
	  { $$ = pt_fmt85_new ($1, $2, $3); }
	| '(' postfix_abstract_declarator ')'
	  { $$ = pt_fmt86_new ($1, $2, $3); }
	| '(' postfixing_abstract_declarator ')'
	  { $$ = pt_fmt87_new ($1, $2, $3); }
	| '(' unary_abstract_declarator ')' postfixing_abstract_declarator
	  { $$ = pt_fmt88_new ($1, $2, $3, $4); }
	;

postfixing_abstract_declarator
	: array_abstract_declarator
	  { $$ = pt_fmt89_new ($1); }
	| '(' ')'
	  { $$ = pt_fmt90_new ($1, $2); }
	| '(' parameter_type_list ')'
	  { $$ = pt_fmt91_new ($1, $2, $3); }
	;

identifier_declarator
	: unary_identifier_declarator
	  { $$ = pt_fmt92_new ($1); }
	| paren_identifier_declarator
	  { $$ = pt_fmt93_new ($1); }
	;

unary_identifier_declarator
	: postfix_identifier_declarator
	  { $$ = pt_fmt94_new ($1); }
	| '*' attributes_opt identifier_declarator
	  { $$ = pt_fmt95_new ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list identifier_declarator
	  { $$ = pt_fmt96_new ($1, $2, $3, $4); }
	;

postfix_identifier_declarator
	: paren_identifier_declarator postfixing_abstract_declarator
	  { $$ = pt_fmt97_new ($1, $2); }
	| '(' unary_identifier_declarator ')'
	  { $$ = pt_fmt98_new ($1, $2, $3); }
	| '(' unary_identifier_declarator ')' postfixing_abstract_declarator
	  { $$ = pt_fmt99_new ($1, $2, $3, $4); }
	;

paren_identifier_declarator
	: IDENTIFIER
	  { $$ = pt_fmt100_new ($1); }
	| '(' paren_identifier_declarator ')'
	  { $$ = pt_fmt101_new ($1, $2, $3); }
	 ;

old_function_declarator
	: postfix_old_function_declarator
	  { $$ = pt_fmt102_new ($1); }
	| '*' attributes_opt old_function_declarator
	  { $$ = pt_fmt103_new ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list old_function_declarator
	  { $$ = pt_fmt104_new ($1, $2, $3, $4); }
	;

postfix_old_function_declarator
	: paren_identifier_declarator '(' identifier_list ')'
	  { $$ = pt_fmt105_new ($1, $2, $3, $4); }
	| '(' old_function_declarator ')'
	  { $$ = pt_fmt106_new ($1, $2, $3); }
	| '(' old_function_declarator ')' postfixing_abstract_declarator
	  { $$ = pt_fmt107_new ($1, $2, $3, $4); }
	;

identifier_list
	: IDENTIFIER
	  { $$ = pt_fmt108_new ($1); }
	| identifier_list ',' IDENTIFIER
	  { $$ = pt_fmt109_new ($1, $2, $3); }
	;

identifier_or_typedef_name
	: IDENTIFIER
	  { $$ = pt_fmt110_new ($1); }
	| TYPEDEF_NAME
	  { $$ = pt_fmt111_new ($1); }
	;

type_name
	: type_specifier
	  { $$ = pt_fmt112_new ($1); }
	| type_specifier abstract_declarator
	  { $$ = pt_fmt113_new ($1, $2); }
	;


nonnull_expression_list
	: argument_expression_list
	  { $$ = pt_fmt114_new ($1); }
	;

any_word
	: IDENTIFIER
	  { $$ = pt_fmt115_new ($1); }
	| TYPEDEF_NAME
	  { $$ = pt_fmt116_new ($1); }
	| CONST
	  { $$ = pt_fmt117_new ($1); }
	;

initialiser_opt
	: empty
	  { $$ = pt_fmt118_new ($1); }
	| '=' initialiser
	  { $$ = pt_fmt119_new ($1, $2); }
	;

initialiser
	: basic_initialiser
	  { $$ = pt_fmt120_new ($1); }
	| IDENTIFIER ':' basic_initialiser
	  { $$ = pt_fmt121_new ($1, $2, $3); }
	| TYPEDEF_NAME ':' basic_initialiser
	  { $$ = pt_fmt122_new ($1, $2, $3); }
	| '.' IDENTIFIER '=' basic_initialiser
	  { $$ = pt_fmt123_new ($1, $2, $3, $4); }
	| '.' TYPEDEF_NAME '=' basic_initialiser
	  { $$ = pt_fmt124_new ($1, $2, $3, $4); }
	| '[' assignment_expression ']' basic_initialiser
	  { $$ = pt_fmt125_new ($1, $2, $3, $4); }
	| '[' assignment_expression ']' '=' basic_initialiser
	  { $$ = pt_fmt126_new ($1, $2, $3, $4, $5); }
	| '[' assignment_expression ELLIPSIS assignment_expression ']' basic_initialiser
	  { $$ = pt_fmt127_new ($1, $2, $3, $4, $5, $6); }
	;

basic_initialiser
	: bracketed_initialiser_list
	  { $$ = pt_fmt128_new ($1); }
	| assignment_expression
	  { $$ = pt_fmt129_new ($1); }
	;

bracketed_initialiser_list
	: '{' '}'
	  { $$ = pt_fmt130_new ($1, $2); }
	| '{' initialiser_list '}'
	  { $$ = pt_fmt131_new ($1, $2, $3); }
	| '{' initialiser_list ',' '}'
	  { $$ = pt_fmt132_new ($1, $2, $3, $4); }
	;

initialiser_list
	: initialiser
	  { $$ = pt_fmt133_new ($1); }
	| initialiser_list ',' initialiser
	  { $$ = pt_fmt134_new ($1, $2, $3); }
	;

parameter_type_list
	: parameter_list
	  { $$ = pt_fmt135_new ($1); }
	| parameter_list ',' ELLIPSIS
	  { $$ = pt_fmt136_new ($1, $2, $3); }
	;

parameter_list
	: parameter_declaration
	  { $$ = pt_fmt137_new ($1); }
	| parameter_list ',' parameter_declaration
	  { $$ = pt_fmt138_new ($1, $2, $3); }
	;

parameter_declaration
	: attributes_opt declaration_specifier
	  { $$ = pt_fmt139_new ($1, $2); }
	| attributes_opt declaration_specifier abstract_declarator
	  { $$ = pt_fmt140_new ($1, $2, $3); }
	| attributes_opt declaration_specifier identifier_declarator
	  { $$ = pt_fmt141_new ($1, $2, $3); }
	| attributes_opt declaration_specifier parameter_typedef_declarator
	  { $$ = pt_fmt142_new ($1, $2, $3); }
	| attributes_opt type_specifier
	  { $$ = pt_fmt143_new ($1, $2); }
	| attributes_opt type_specifier abstract_declarator
	  { $$ = pt_fmt144_new ($1, $2, $3); }
	| attributes_opt type_specifier identifier_declarator attributes_opt
	  { $$ = pt_fmt145_new ($1, $2, $3, $4); }
	| attributes_opt type_specifier parameter_typedef_declarator
	  { $$ = pt_fmt146_new ($1, $2, $3); }
	;

array_abstract_declarator
	: '[' ']'
	  { $$ = pt_fmt147_new ($1, $2); }
	| '[' constant_expression ']'
	  { $$ = pt_fmt148_new ($1, $2, $3); }
	| array_abstract_declarator '[' constant_expression ']'
	  { $$ = pt_fmt149_new ($1, $2, $3, $4); }
	| array_abstract_declarator '[' ']'
	  { $$ = pt_fmt150_new ($1, $2, $3); }
	;
