%{
// vim:noexpandtab
#include "yy/parse_interf.h"
#define scanner parse_context_scanner (context)
%}

%define api.pure
%locations
%debug
%error-verbose
%expect 1
%glr-parser
%token-table

%parse-param { parse_context* context }
%lex-param { void* scanner }

%destructor { ast_node_delete ($$); } <>


%token IDENTIFIER	"identifier"
%token CONSTANT		"constant"
%token STRING_LITERAL	"string literal"

%token SIZEOF		"sizeof"

%token PTR_OP		"->"
%token INC_OP		"++"
%token DEC_OP		"--"
%token LEFT_OP		"<<"
%token RIGHT_OP		">>"
%token LE_OP		"<="
%token GE_OP		">="
%token EQ_OP		"=="
%token NE_OP		"!="
%token AND_OP		"&&"
%token OR_OP		"||"

%token MUL_ASSIGN	"*="
%token DIV_ASSIGN	"/="
%token MOD_ASSIGN	"%="
%token ADD_ASSIGN	"+="
%token SUB_ASSIGN	"-="
%token LEFT_ASSIGN	"<<="
%token RIGHT_ASSIGN	">>="
%token AND_ASSIGN	"&="
%token XOR_ASSIGN	"^="
%token OR_ASSIGN	"|="
%token TYPE_NAME	"type name"

%token TYPEDEF		"typedef"
%token EXTERN		"extern"
%token STATIC		"static"
%token AUTO		"auto"
%token REGISTER		"register"

%token CHAR		"char"
%token SHORT		"short"
%token INT		"int"
%token LONG		"long"
%token SIGNED		"signed"
%token UNSIGNED		"unsigned"
%token FLOAT		"float"
%token DOUBLE		"double"
%token CONST		"const"
%token VOLATILE		"volatile"
%token VOID		"void"

%token STRUCT		"struct"
%token UNION		"union"
%token ENUM		"enum"
%token ELLIPSIS		"..."

%token CASE		"case"
%token DEFAULT		"default"
%token IF		"if"
%token ELSE		"else"
%token SWITCH		"switch"
%token WHILE		"while"
%token DO		"do"
%token FOR		"for"
%token GOTO		"goto"
%token CONTINUE		"continue"
%token BREAK		"break"
%token RETURN		"return"


%start translation_unit
%%

primary_expression
	: IDENTIFIER
	  { $$ = ast_variable_new ($1); }
	| CONSTANT
	  { $$ = ast_constant_new ($1); }
	| STRING_LITERAL
	  { $$ = ast_string_literal_new ($1); }
	| '(' expression ')'
	  { $$ = ast_bracket_expression_new ($1, $2, $3); }
	;

postfix_expression
	: primary_expression		
	  { $$ = $1; }
	| postfix_expression '[' expression ']'
	  { $$ = ast_array_access_new ($1, $2, $3, $4); }
	| postfix_expression '(' ')'
	  { $$ = ast_function_call_new ($1, $2, NULL, $3); }
	| postfix_expression '(' argument_expression_list ')'
	  { $$ = ast_function_call_new ($1, $2, $3, $4); }
	| postfix_expression '.' IDENTIFIER
	  { $$ = ast_struct_access_new ($1, $2, $3); }
	| postfix_expression "->" IDENTIFIER
	  { $$ = ast_pointer_access_new ($1, $2, $3); }
	| postfix_expression "++"
	  { $$ = ast_post_increment_new ($1, $2); }
	| postfix_expression "--"
	  { $$ = ast_post_decrement_new ($1, $2); }
	;

argument_expression_list
	: assignment_expression							{ /* argument_expression_list */ }
	| argument_expression_list ',' assignment_expression			{ /* argument_expression_list */ }
	;

unary_expression
	: postfix_expression
	  { $$ = $1; }
	| "++" unary_expression
	  { $$ = ast_pre_increment_new ($1, $2); }
	| "--" unary_expression
	  { $$ = ast_pre_decrement_new ($1, $2); }
	| '&' cast_expression
	  { $$ = ast_address_of_new ($1, $2); }
	| '*' cast_expression
	  { $$ = ast_pointer_dereference_new ($1, $2); }
	| '+' cast_expression
	  { $$ = ast_positive_new ($1, $2); }
	| '-' cast_expression
	  { $$ = ast_negate_new ($1, $2); }
	| '~' cast_expression
	  { $$ = ast_bitwise_negate_new ($1, $2); }
	| '!' cast_expression
	  { $$ = ast_logical_not_new ($1, $2); }
	| "sizeof" unary_expression
	  { $$ = ast_sizeof_var_new ($1, $2); }
	| "sizeof" '(' type_name ')'
	  { $$ = ast_sizeof_type_new ($1, $2, $3, $4); }
	;

cast_expression
	: unary_expression
	  { $$ = $1; }
	| '(' type_name ')' cast_expression
	  { $$ = ast_type_cast_new ($1, $2, $3, $4); }
	;

multiplicative_expression
	: cast_expression
	  { $$ = $1; }
	| multiplicative_expression '*' cast_expression
	  { $$ = ast_multiply_new ($1, $2, $3); }
	| multiplicative_expression '/' cast_expression
	  { $$ = ast_divide_new ($1, $2, $3); }
	| multiplicative_expression '%' cast_expression
	  { $$ = ast_modulo_new ($1, $2, $3); }
	;

additive_expression
	: multiplicative_expression
	  { $$ = $1; }
	| additive_expression '+' multiplicative_expression
	  { $$ = ast_add_new ($1, $2, $3); }
	| additive_expression '-' multiplicative_expression
	  { $$ = ast_subtract_new ($1, $2, $3); }
	;

shift_expression
	: additive_expression
	  { $$ = $1; }
	| shift_expression "<<" additive_expression
	  { $$ = ast_left_shift_new ($1, $2, $3); }
	| shift_expression ">>" additive_expression
	  { $$ = ast_right_shift_new ($1, $2, $3); }
	;

relational_expression
	: shift_expression
	  { $$ = $1; }
	| relational_expression '<' shift_expression
	  { $$ = ast_less_than_new ($1, $2, $3); }
	| relational_expression '>' shift_expression
	  { $$ = ast_greater_than_new ($1, $2, $3); }
	| relational_expression "<=" shift_expression
	  { $$ = ast_less_than_equals_new ($1, $2, $3); }
	| relational_expression ">=" shift_expression
	  { $$ = ast_greater_than_equals_new ($1, $2, $3); }
	;

equality_expression
	: relational_expression	
	  { $$ = $1; }
	| equality_expression "==" relational_expression
	  { $$ = ast_equals_new ($1, $2, $3); }
	| equality_expression "!=" relational_expression
	  { $$ = ast_not_equals_new ($1, $2, $3); }
	;

and_expression
	: equality_expression
	  { $$ = $1; }
	| and_expression '&' equality_expression
	  { $$ = ast_bitwise_and_new ($1, $2, $3); }
	;

exclusive_or_expression
	: and_expression
	  { $$ = $1; }
	| exclusive_or_expression '^' and_expression
	  { $$ = ast_bitwise_xor_new ($1, $2, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	  { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression
	  { $$ = ast_bitwise_or_new ($1, $2, $3); }
	;

logical_and_expression
	: inclusive_or_expression
	  { $$ = $1; }
	| logical_and_expression "&&" inclusive_or_expression
	  { $$ = ast_logical_and_new ($1, $2, $3); }
	;

logical_or_expression
	: logical_and_expression
	  { $$ = $1; }
	| logical_or_expression "||" logical_and_expression
	  { $$ = ast_logical_or_new ($1, $2, $3); }
	;

conditional_expression
	: logical_or_expression
	  { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression
	  { $$ = ast_ternary_op_new ($1, $2, $3, $4, $5); }
	;

assignment_expression
	: conditional_expression						{ $$ = $1; }
	| unary_expression '=' assignment_expression				{ /* assign */ }
	| unary_expression "*=" assignment_expression				{ /* multiply_assign */ }
	| unary_expression "/=" assignment_expression				{ /* divide_assign */ }
	| unary_expression "%=" assignment_expression				{ /* modulo_assign */ }
	| unary_expression "+=" assignment_expression				{ /* add_assign */ }
	| unary_expression "-=" assignment_expression				{ /* subtract_assign */ }
	| unary_expression "<<=" assignment_expression				{ /* left_shift_assign */ }
	| unary_expression ">>=" assignment_expression				{ /* right_shift_assign */ }
	| unary_expression "&=" assignment_expression				{ /* and_assign */ }
	| unary_expression "^=" assignment_expression				{ /* xor_assign */ }
	| unary_expression "|=" assignment_expression				{ /* or_assign */ }
	;

expression
	: assignment_expression							{ $$ = $1; }
	| expression ',' assignment_expression					{ /* comma */ }
	;

constant_expression
	: conditional_expression						{ $$ = $1; }
	;

declaration
	: declaration_specifiers ';'						{ /* declaration */ }
	| declaration_specifiers init_declarator_list ';'			{ /* declaration */ }
	;

declaration_specifiers
	: storage_class_specifier						{ /* storage_decl_spec */ }
	| storage_class_specifier declaration_specifiers			{ /* storage_decl_spec */ }
	| type_specifier							{ /* type_spec_decl_spec */ }
	| type_specifier declaration_specifiers					{ /* type_spec_decl_spec */ }
	| type_qualifier							{ /* type_qual_decl_spec */ }
	| type_qualifier declaration_specifiers					{ /* type_qual_decl_spec */ }
	;

init_declarator_list
	: init_declarator							{ /* init_declarator_list */ }
	| init_declarator_list ',' init_declarator				{ /* init_declarator_list */ }
	;

init_declarator
	: declarator								{ /* init_declr */ }
	| declarator '=' initializer						{ /* init_declr */ }
	;

storage_class_specifier
	: "typedef"
	  { $$ = ast_typedef_str_class_spec_new ($1); }
	| "extern"
	  { $$ = ast_extern_str_class_spec_new ($1); }
	| "static"
	  { $$ = ast_static_str_class_spec_new ($1); }
	| "auto"
	  { $$ = ast_auto_str_class_spec_new ($1); }
	| "register"
	  { $$ = ast_register_str_class_spec_new ($1); }
	;

type_specifier
	: "void"
	  { $$ = ast_void_type_spec_new ($1); }
	| "char"
	  { $$ = ast_char_type_spec_new ($1); }
	| "short"
	  { $$ = ast_short_type_spec_new ($1); }
	| "int"
	  { $$ = ast_int_type_spec_new ($1); }
	| "long"
	  { $$ = ast_long_type_spec_new ($1); }
	| "float"
	  { $$ = ast_float_type_spec_new ($1); }
	| "double"
	  { $$ = ast_double_type_spec_new ($1); }
	| "signed"
	  { $$ = ast_signed_type_spec_new ($1); }
	| "unsigned"
	  { $$ = ast_unsigned_type_spec_new ($1); }
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME								{ /* would it be sufficient to just save the token, here? */ }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'		{ /* struct_definition_spec */ }
	| struct_or_union '{' struct_declaration_list '}'			{ /* struct_definition_spec */ }
	| struct_or_union IDENTIFIER						{ /* struct_definition_spec */ }
	;

struct_or_union
	: "struct"
	| "union"
	;

struct_declaration_list
	: struct_declaration							{ /* struct_declaration_list */ }
	| struct_declaration_list struct_declaration				{ /* struct_declaration_list */ }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'			{ /* struct_declaration */ }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator							{ /* struct_declarator_list */ }
	| struct_declarator_list ',' struct_declarator				{ /* struct_declarator_list */ }
	;

struct_declarator
	: declarator								{ $$ = $1; }
	| ':' constant_expression						{ /* bitfield_declarator */ }
	| declarator ':' constant_expression					{ /* bitfield_declarator */ }
	;

enum_specifier
	: "enum" '{' enumerator_list '}'					{ /* defined_enum_spec */ }
	| "enum" IDENTIFIER '{' enumerator_list '}'				{ /* defined_enum_spec */ }
	| "enum" IDENTIFIER							{ /* referenced_enum_spec */ }
	;

enumerator_list
	: enumerator								{ /* enumerator_list */ }
	| enumerator_list ',' enumerator					{ /* enumerator_list */ }
	;

enumerator
	: IDENTIFIER
	  { $$ = ast_enumerator_new ($1, NULL, NULL); }
	| IDENTIFIER '=' constant_expression
	  { $$ = ast_enumerator_new ($1, $2, $3); }
	;

type_qualifier
	: "const"
	  { $$ = ast_const_type_qualifier_new ($1); }
	| "volatile"
	  { $$ = ast_volatile_type_qualifier_new ($1); }
	;

declarator
	: pointer direct_declarator						{ $$ = $1; }
	| direct_declarator							{ $$ = $1; }
	;

direct_declarator
	: IDENTIFIER								{ /* name_dir_declr */ }
	| '(' declarator ')'							{ /* paren_dir_declr */ }
	| direct_declarator '[' constant_expression ']'				{ /* bracket_dir_declr */ }
	| direct_declarator '[' ']'						{ /* bracket_dir_declr */ }
	| direct_declarator '(' parameter_type_list ')'				{ /* type_func_list_dir_declr */ }
	| direct_declarator '(' identifier_list ')'				{ /* id_func_list_dir_declr */ }
	| direct_declarator '(' ')'						{ /* type_func_list_dir_declr */ }
	;

pointer
	: '*'									{ /* pointer */ }
	| '*' type_qualifier_list						{ /* pointer */ }
	| '*' pointer								{ /* pointer */ }
	| '*' type_qualifier_list pointer					{ /* pointer */ }
	;

type_qualifier_list
	: type_qualifier							{ /* type_qualifier_list */ }
	| type_qualifier_list type_qualifier					{ /* type_qualifier_list */ }
	;


parameter_type_list
	: parameter_list							{ /* parameter_type_list */ }
	| parameter_list ',' "..."						{ /* parameter_type_list */ }
	;

parameter_list
	: parameter_declaration							{ /* parameter_list */ }
	| parameter_list ',' parameter_declaration				{ /* parameter_list */ }
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER								{ /* identifier_list */ }
	| identifier_list ',' IDENTIFIER					{ /* identifier_list */ }
	;

type_name
	: specifier_qualifier_list						{ /* type_name */ }
	| specifier_qualifier_list abstract_declarator				{ /* type_name */ }
	;

abstract_declarator
	: pointer								{ /* abstract_declarator */ }
	| direct_abstract_declarator						{ /* abstract_declarator */ }
	| pointer direct_abstract_declarator					{ /* abstract_declarator */ }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'						{ /* initializer */ }
	| '{' initializer_list ',' '}'						{ /* initializer */ }
	;

initializer_list
	: initializer								{ /* initializer_list */ }
	| initializer_list ',' initializer					{ /* initializer_list */ }
	;

statement
	: labeled_statement							{ $$ = $1; }
	| compound_statement							{ $$ = $1; }
	| expression_statement							{ $$ = $1; }
	| selection_statement							{ $$ = $1; }
	| iteration_statement							{ $$ = $1; }
	| jump_statement							{ $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement
	  { $$ = ast_label_statement_new ($1, $2, $3); }
	| "case" constant_expression ':' statement
	  { $$ = ast_case_label_statement_new ($1, $2, $3, $4); }
	| "default" ':' statement
	  { $$ = ast_default_label_statement_new ($1, $2, $3); }
	;

compound_statement
	: '{' '}'								{ /* compound_statement */ }
	| '{' statement_list '}'						{ /* compound_statement */ }
	| '{' declaration_list '}'						{ /* compound_statement */ }
	| '{' declaration_list statement_list '}'				{ /* compound_statement */ }
	;

declaration_list
	: declaration								{ /* declaration_list */ }
	| declaration_list declaration						{ /* declaration_list */ }
	;

statement_list
	: statement								{ /* statement_list */ }
	| statement_list statement						{ /* statement_list */ }
	;

expression_statement
	: ';'
	  { $$ = ast_expression_statement_new (NULL, $1); }
	| expression ';'
	  { $$ = ast_expression_statement_new ($1, $2); }
	;

selection_statement
	: "if" '(' expression ')' statement
	  { $$ = ast_if_statement_new ($1, $2, $3, $4, $5, NULL, NULL); }
	| "if" '(' expression ')' statement "else" statement
	  { $$ = ast_if_statement_new ($1, $2, $3, $4, $5, $6, $7); }
	| "switch" '(' expression ')' statement
	  { $$ = ast_switch_statement_new ($1, $2, $3, $4, $5); }
	;

iteration_statement
	: "while" '(' expression ')' statement
	  { $$ = ast_while_statement_new ($1, $2, $3, $4, $5); }
	| "do" statement "while" '(' expression ')' ';'
	  { $$ = ast_do_statement_new ($1, $2, $3, $4, $5, $6, $7); }
	| "for" '(' expression_statement expression_statement ')' statement
	  { $$ = ast_for_statement_new ($1, $2, $3, $4, NULL, $5, $6); }
	| "for" '(' expression_statement expression_statement expression ')' statement
	  { $$ = ast_for_statement_new ($1, $2, $3, $4, $5, $6, $7);	}
	;

jump_statement
	: "goto" IDENTIFIER ';'
	  { $$ = ast_goto_statement_new ($1, $2, $3); }
	| "continue" ';'
	  { $$ = ast_continue_statement_new ($1, $2); }
	| "break" ';'
	  { $$ = ast_break_statement_new ($1, $2); }
	| "return" ';'
	  { $$ = ast_return_statement_new ($1, NULL, $2); }
	| "return" expression ';'
	  { $$ = ast_return_statement_new ($1, $2, $3); }
	;

translation_unit
	: external_declaration							{ /* translation_unit */ }
	| translation_unit external_declaration					{ /* translation_unit */ }
	;

external_declaration
	: function_definition							{ $$ = $1; }
	| declaration								{ $$ = $1; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement	{ /* function_definition */ }
	| declaration_specifiers declarator compound_statement			{ /* function_definition */ }
	| declarator declaration_list compound_statement			{ /* function_definition */ }
	| declarator compound_statement						{ /* function_definition */ }
	;

%%
