%%
%%

declaration
	: declaring_list ';'
	  { new (fmt1) ($1, $2); }
	| default_declaring_list ';'
	  { new (fmt2) ($1, $2); }
	| sue_declaration_specifier ';'
	  { new (fmt3) ($1, $2); }
	| sue_type_specifier ';'
	  { new (fmt4) ($1, $2); }
	| declaration_specifier identifier_declarator compound_statement
	  { new (fmt5) ($1, $2, $3); }
	| declaration_specifier_nosue attributes identifier_declarator compound_statement
	  { new (fmt6) ($1, $2, $3, $4); }
	| type_specifier identifier_declarator compound_statement
	  { new (fmt7) ($1, $2, $3); }
	| type_specifier_nosue attributes identifier_declarator compound_statement
	  { new (fmt8) ($1, $2, $3, $4); }
	;


declaring_list
	: declaration_specifier declarator asm_opt attributes_opt initialiser_opt
	  { new (fmt9) ($1, $2, $3, $4, $5); }
	| declaration_specifier_nosue attributes declarator asm_opt attributes_opt initialiser_opt
	  { new (fmt10) ($1, $2, $3, $4, $5, $6); }
	| type_specifier declarator asm_opt attributes_opt initialiser_opt
	  { new (fmt11) ($1, $2, $3, $4, $5); }
	| type_specifier_nosue attributes declarator asm_opt attributes_opt initialiser_opt
	  { new (fmt12) ($1, $2, $3, $4, $5, $6); }
	| declaring_list ',' declarator asm_opt attributes_opt initialiser_opt
	  { new (fmt13) ($1, $2, $3, $4, $5, $6); }
	;

default_declaring_list
	: declaration_qualifier_list identifier_declarator attributes_opt initialiser_opt
	  { new (fmt14) ($1, $2, $3, $4); }
	| type_qualifier_list identifier_declarator attributes_opt initialiser_opt
	  { new (fmt15) ($1, $2, $3, $4); }
	| default_declaring_list ',' identifier_declarator attributes_opt initialiser_opt
	  { new (fmt16) ($1, $2, $3, $4, $5); }
	;

declaration_specifier
	: declaration_specifier_nosue
	  { new (fmt17) ($1); }
	| sue_declaration_specifier
	  { new (fmt18) ($1); }
	;

declaration_specifier_nosue
	: basic_declaration_specifier
	  { new (fmt19) ($1); }
	| typedef_declaration_specifier
	  { new (fmt20) ($1); }
	;

basic_declaration_specifier
	: basic_type_specifier storage_class
	  { new (fmt21) ($1, $2); }
	| declaration_qualifier_list basic_type_name
	  { new (fmt22) ($1, $2); }
	| basic_declaration_specifier declaration_qualifier
	  { new (fmt23) ($1, $2); }
	| basic_declaration_specifier basic_type_name
	  { new (fmt24) ($1, $2); }
	;

sue_declaration_specifier
	: sue_type_specifier storage_class
	  { new (fmt25) ($1, $2); }
	| declaration_qualifier_list elaborated_type_name attributes_opt
	  { new (fmt26) ($1, $2, $3); }
	| sue_declaration_specifier declaration_qualifier
	  { new (fmt27) ($1, $2); }
	;

typedef_declaration_specifier
	: typedef_type_specifier storage_class
	  { new (fmt28) ($1, $2); }
	| declaration_qualifier_list TYPEDEF_NAME
	  { new (fmt29) ($1, $2); }
	| typedef_declaration_specifier declaration_qualifier
	  { new (fmt30) ($1, $2); }
	;

declaration_qualifier_list
	: storage_class attributes_opt
	  { new (fmt31) ($1, $2); }
	| type_qualifier_list attributes_opt storage_class attributes_opt
	  { new (fmt32) ($1, $2, $3, $4); }
	| declaration_qualifier_list declaration_qualifier
	  { new (fmt33) ($1, $2); }
	;

declaration_qualifier
	: type_qualifier
	  { new (fmt34) ($1); }
	| storage_class
	  { new (fmt35) ($1); }
	;

type_specifier
	: type_specifier_nosue
	  { new (fmt36) ($1); }
	| sue_type_specifier
	  { new (fmt37) ($1); }
	;

type_specifier_nosue
	: basic_type_specifier
	  { new (fmt38) ($1); }
	| typedef_type_specifier
	  { new (fmt39) ($1); }
	;

basic_type_specifier
	: basic_type_name
	  { new (fmt40) ($1); }
	| type_qualifier_list basic_type_name
	  { new (fmt41) ($1, $2); }
	| basic_type_specifier type_qualifier
	  { new (fmt42) ($1, $2); }
	| basic_type_specifier basic_type_name
	  { new (fmt43) ($1, $2); }
	;

sue_type_specifier
	: elaborated_type_name
	  { new (fmt44) ($1); }
	| type_qualifier_list elaborated_type_name
	  { new (fmt45) ($1, $2); }
	| sue_type_specifier type_qualifier
	  { new (fmt46) ($1, $2); }
	;

typedef_type_specifier
	: TYPEDEF_NAME
	  { new (fmt47) ($1); }
	| type_qualifier_list TYPEDEF_NAME
	  { new (fmt48) ($1, $2); }
	| typedef_type_specifier type_qualifier
	  { new (fmt49) ($1, $2); }
	;

type_qualifier_list
	: type_qualifier
	  { new (fmt50) ($1); }
	| type_qualifier_list type_qualifier
	  { new (fmt51) ($1, $2); }
	;

pointer_type_qualifier_list
	: pointer_type_qualifier
	  { new (fmt52) ($1); }
	| pointer_type_qualifier_list pointer_type_qualifier
	  { new (fmt53) ($1, $2); }
	;

elaborated_type_name
	: struct_or_union_specifier
	  { new (fmt54) ($1); }
	| enum_specifier
	  { new (fmt55) ($1); }
	;

declarator
	: paren_typedef_declarator
	  { new (fmt56) ($1); }
	| parameter_typedef_declarator
	  { new (fmt57) ($1); }
	| identifier_declarator
	  { new (fmt58) ($1); }
	| old_function_declarator
	  { new (fmt59) ($1); }
	;

paren_typedef_declarator
	: paren_postfix_typedef_declarator
	  { new (fmt60) ($1); }
	| '*' attributes_opt paren_typedef_declarator
	  { new (fmt61) ($1, $2, $3); }
	| '*' attributes_opt '(' simple_paren_typedef_declarator ')'
	  { new (fmt62) ($1, $2, $3, $4, $5); }
	| '*' attributes_opt pointer_type_qualifier_list '(' simple_paren_typedef_declarator ')'
	  { new (fmt63) ($1, $2, $3, $4, $5, $6); }
	| '*' attributes_opt pointer_type_qualifier_list paren_typedef_declarator
	  { new (fmt64) ($1, $2, $3, $4); }
	;

paren_postfix_typedef_declarator
	: '(' paren_typedef_declarator ')'
	  { new (fmt65) ($1, $2, $3); }
	| '(' simple_paren_typedef_declarator postfixing_abstract_declarator ')'
	  { new (fmt66) ($1, $2, $3, $4); }
	| '(' paren_typedef_declarator ')' postfixing_abstract_declarator
	  { new (fmt67) ($1, $2, $3, $4); }
	;

simple_paren_typedef_declarator
	: TYPEDEF_NAME
	  { new (fmt68) ($1); }
	| '(' simple_paren_typedef_declarator ')'
	  { new (fmt69) ($1, $2, $3); }
	;

parameter_typedef_declarator
	: TYPEDEF_NAME
	  { new (fmt70) ($1); }
	| TYPEDEF_NAME postfixing_abstract_declarator
	  { new (fmt71) ($1, $2); }
	| clean_typedef_declarator
	  { new (fmt72) ($1); }
	;

clean_typedef_declarator
	: clean_postfix_typedef_declarator
	  { new (fmt73) ($1); }
	| '*' attributes_opt parameter_typedef_declarator
	  { new (fmt74) ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list parameter_typedef_declarator
	  { new (fmt75) ($1, $2, $3, $4); }
	;

clean_postfix_typedef_declarator
	: '(' clean_typedef_declarator ')'
	  { new (fmt76) ($1, $2, $3); }
	| '(' clean_typedef_declarator ')' postfixing_abstract_declarator
	  { new (fmt77) ($1, $2, $3, $4); }
	;

abstract_declarator
	: unary_abstract_declarator
	  { new (fmt78) ($1); }
	| postfix_abstract_declarator
	  { new (fmt79) ($1); }
	| postfixing_abstract_declarator
	  { new (fmt80) ($1); }
	;

unary_abstract_declarator
	: '*' attributes_opt
	  { new (fmt81) ($1, $2); }
	| '*' attributes_opt pointer_type_qualifier_list
	  { new (fmt82) ($1, $2, $3); }
	| '*' attributes_opt abstract_declarator
	  { new (fmt83) ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list abstract_declarator
	  { new (fmt84) ($1, $2, $3, $4); }
	;

postfix_abstract_declarator
	: '(' unary_abstract_declarator ')'
	  { new (fmt85) ($1, $2, $3); }
	| '(' postfix_abstract_declarator ')'
	  { new (fmt86) ($1, $2, $3); }
	| '(' postfixing_abstract_declarator ')'
	  { new (fmt87) ($1, $2, $3); }
	| '(' unary_abstract_declarator ')' postfixing_abstract_declarator
	  { new (fmt88) ($1, $2, $3, $4); }
	;

postfixing_abstract_declarator
	: array_abstract_declarator
	  { new (fmt89) ($1); }
	| '(' ')'
	  { new (fmt90) ($1, $2); }
	| '(' parameter_type_list ')'
	  { new (fmt91) ($1, $2, $3); }
	;

identifier_declarator
	: unary_identifier_declarator
	  { new (fmt92) ($1); }
	| paren_identifier_declarator
	  { new (fmt93) ($1); }
	;

unary_identifier_declarator
	: postfix_identifier_declarator
	  { new (fmt94) ($1); }
	| '*' attributes_opt identifier_declarator
	  { new (fmt95) ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list identifier_declarator
	  { new (fmt96) ($1, $2, $3, $4); }
	;

postfix_identifier_declarator
	: paren_identifier_declarator postfixing_abstract_declarator
	  { new (fmt97) ($1, $2); }
	| '(' unary_identifier_declarator ')'
	  { new (fmt98) ($1, $2, $3); }
	| '(' unary_identifier_declarator ')' postfixing_abstract_declarator
	  { new (fmt99) ($1, $2, $3, $4); }
	;

paren_identifier_declarator
	: IDENTIFIER
	  { new (fmt100) ($1); }
	| '(' paren_identifier_declarator ')'
	  { new (fmt101) ($1, $2, $3); }
	 ;

old_function_declarator
	: postfix_old_function_declarator
	  { new (fmt102) ($1); }
	| '*' attributes_opt old_function_declarator
	  { new (fmt103) ($1, $2, $3); }
	| '*' attributes_opt pointer_type_qualifier_list old_function_declarator
	  { new (fmt104) ($1, $2, $3, $4); }
	;

postfix_old_function_declarator
	: paren_identifier_declarator '(' identifier_list ')'
	  { new (fmt105) ($1, $2, $3, $4); }
	| '(' old_function_declarator ')'
	  { new (fmt106) ($1, $2, $3); }
	| '(' old_function_declarator ')' postfixing_abstract_declarator
	  { new (fmt107) ($1, $2, $3, $4); }
	;

identifier_list
	: IDENTIFIER
	  { new (fmt108) ($1); }
	| identifier_list ',' IDENTIFIER
	  { new (fmt109) ($1, $2, $3); }
	;

identifier_or_typedef_name
	: IDENTIFIER
	  { new (fmt110) ($1); }
	| TYPEDEF_NAME
	  { new (fmt111) ($1); }
	;

type_name
	: type_specifier
	  { new (fmt112) ($1); }
	| type_specifier abstract_declarator
	  { new (fmt113) ($1, $2); }
	;


nonnull_expression_list
	: argument_expression_list
	  { new (fmt114) ($1); }
	;

any_word
	: IDENTIFIER
	  { new (fmt115) ($1); }
	| TYPEDEF_NAME
	  { new (fmt116) ($1); }
	| CONST
	  { new (fmt117) ($1); }
	;

initialiser_opt
	: empty
	  { new (fmt118) ($1); }
	| '=' initialiser
	  { new (fmt119) ($1, $2); }
	;

initialiser
	: basic_initialiser
	  { new (fmt120) ($1); }
	| identifier_or_typedef_name ':' basic_initialiser
	  { new (fmt121) ($1, $2, $3); }
	| '.' identifier_or_typedef_name '=' basic_initialiser
	  { new (fmt123) ($1, $2, $3, $4); }
	| '[' assignment_expression ']' basic_initialiser
	  { new (fmt125) ($1, $2, $3, $4); }
	| '[' assignment_expression ']' '=' basic_initialiser
	  { new (fmt126) ($1, $2, $3, $4, $5); }
	| '[' assignment_expression ELLIPSIS assignment_expression ']' basic_initialiser
	  { new (fmt127) ($1, $2, $3, $4, $5, $6); }
	;

basic_initialiser
	: bracketed_initialiser_list
	  { new (fmt128) ($1); }
	| assignment_expression
	  { new (fmt129) ($1); }
	;

bracketed_initialiser_list
	: '{' '}'
	  { new (fmt130) ($1, $2); }
	| '{' initialiser_list '}'
	  { new (fmt131) ($1, $2, $3); }
	| '{' initialiser_list ',' '}'
	  { new (fmt132) ($1, $2, $3, $4); }
	;

initialiser_list
	: initialiser
	  { new (fmt133) ($1); }
	| initialiser_list ',' initialiser
	  { new (fmt134) ($1, $2, $3); }
	;

parameter_type_list
	: parameter_list
	  { new (fmt135) ($1); }
	| parameter_list ',' ELLIPSIS
	  { new (fmt136) ($1, $2, $3); }
	;

parameter_list
	: parameter_declaration
	  { new (fmt137) ($1); }
	| parameter_list ',' parameter_declaration
	  { new (fmt138) ($1, $2, $3); }
	;

parameter_declaration
	: attributes_opt declaration_specifier
	  { new (fmt139) ($1, $2); }
	| attributes_opt declaration_specifier abstract_declarator
	  { new (fmt140) ($1, $2, $3); }
	| attributes_opt declaration_specifier identifier_declarator
	  { new (fmt141) ($1, $2, $3); }
	| attributes_opt declaration_specifier parameter_typedef_declarator
	  { new (fmt142) ($1, $2, $3); }
	| attributes_opt type_specifier
	  { new (fmt143) ($1, $2); }
	| attributes_opt type_specifier abstract_declarator
	  { new (fmt144) ($1, $2, $3); }
	| attributes_opt type_specifier identifier_declarator attributes_opt
	  { new (fmt145) ($1, $2, $3, $4); }
	| attributes_opt type_specifier parameter_typedef_declarator
	  { new (fmt146) ($1, $2, $3); }
	;

array_abstract_declarator
	: '[' ']'
	  { new (fmt147) ($1, $2); }
	| '[' constant_expression ']'
	  { new (fmt148) ($1, $2, $3); }
	| array_abstract_declarator '[' constant_expression ']'
	  { new (fmt149) ($1, $2, $3, $4); }
	| array_abstract_declarator '[' ']'
	  { new (fmt150) ($1, $2, $3); }
	;
