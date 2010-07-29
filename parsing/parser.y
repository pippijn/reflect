%{
// vim:noexpandtab
#include "yy/parse_interf.h"
#define scanner parse_context_scanner_get (context)
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
	: IDENTIFIER								{ /* variable_expr */ }
	| CONSTANT								{ /* constant */ }
	| STRING_LITERAL							{ /* string_literal */ }
	| '(' expression ')'							{ /* parenth_expr */ }
	;

postfix_expression
	: primary_expression							{ $$ = $1; }
	| postfix_expression '[' expression ']'					{ /* array_access */ }
	| postfix_expression '(' ')'						{ /* function_call */ }
	| postfix_expression '(' argument_expression_list ')'			{ /* function_call */ }
	| postfix_expression '.' IDENTIFIER					{ /* struct_access */ }
	| postfix_expression PTR_OP IDENTIFIER					{ /* pointer_access */ }
	| postfix_expression INC_OP						{ /* post_increment */ }
	| postfix_expression DEC_OP						{ /* post_decrement */ }
	;

argument_expression_list
	: assignment_expression							{ /* argument_expression_list */ }
	| argument_expression_list ',' assignment_expression			{ /* argument_expression_list */ }
	;

unary_expression
	: postfix_expression							{ $$ = $1; }
	| INC_OP unary_expression						{ /* pre_increment */ }
	| DEC_OP unary_expression						{ /* pre_decrement */ }
	| '&' cast_expression							{ /* address_of */ }
	| '*' cast_expression							{ /* pointer_dereference */ }
	| '+' cast_expression							{ /* positive */ }
	| '-' cast_expression							{ /* negate */ }
	| '~' cast_expression							{ /* bitwise_negate */ }
	| '!' cast_expression							{ /* logical_not */ }
	| SIZEOF unary_expression						{ /* sizeof_var */ }
	| SIZEOF '(' type_name ')'						{ /* sizeof_type */ }
	;

cast_expression
	: unary_expression							{ $$ = $1; }
	| '(' type_name ')' cast_expression					{ /* type_cast */ }
	;

multiplicative_expression
	: cast_expression							{ $$ = $1; }
	| multiplicative_expression '*' cast_expression				{ /* multiply */ }
	| multiplicative_expression '/' cast_expression				{ /* divide */ }
	| multiplicative_expression '%' cast_expression				{ /* modulo */ }
	;

additive_expression
	: multiplicative_expression						{ $$ = $1; }
	| additive_expression '+' multiplicative_expression			{ /* add */ }
	| additive_expression '-' multiplicative_expression			{ /* subtract */ }
	;

shift_expression
	: additive_expression							{ $$ = $1; }
	| shift_expression LEFT_OP additive_expression				{ /* left_shift */ }
	| shift_expression RIGHT_OP additive_expression				{ /* right_shift */ }
	;

relational_expression
	: shift_expression							{ $$ = $1; }
	| relational_expression '<' shift_expression				{ /* less_than */ }
	| relational_expression '>' shift_expression				{ /* greater_than */ }
	| relational_expression LE_OP shift_expression				{ /* less_than_equals */ }
	| relational_expression GE_OP shift_expression				{ /* greater_than_equals */ }
	;

equality_expression
	: relational_expression							{ $$ = $1; }
	| equality_expression EQ_OP relational_expression			{ /* equals */ }
	| equality_expression NE_OP relational_expression			{ /* not_equals */ }
	;

and_expression
	: equality_expression							{ $$ = $1; }
	| and_expression '&' equality_expression				{ /* bitwise_and */ }
	;

exclusive_or_expression
	: and_expression							{ $$ = $1; }
	| exclusive_or_expression '^' and_expression				{ /* bitwise_xor */ }
	;

inclusive_or_expression
	: exclusive_or_expression						{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression			{ /* bitwise_or */ }
	;

logical_and_expression
	: inclusive_or_expression						{ $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression			{ /* logical_and */ }
	;

logical_or_expression
	: logical_and_expression						{ $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression			{ /* logical_or */ }
	;

conditional_expression
	: logical_or_expression							{ $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression	{ /* ternary_op */ }
	;

assignment_expression
	: conditional_expression						{ $$ = $1; }
	| unary_expression '=' assignment_expression				{ /* assign */ }
	| unary_expression MUL_ASSIGN assignment_expression			{ /* multiply_assign */ }
	| unary_expression DIV_ASSIGN assignment_expression			{ /* divide_assign */ }
	| unary_expression MOD_ASSIGN assignment_expression			{ /* modulo_assign */ }
	| unary_expression ADD_ASSIGN assignment_expression			{ /* add_assign */ }
	| unary_expression SUB_ASSIGN assignment_expression			{ /* subtract_assign */ }
	| unary_expression LEFT_ASSIGN assignment_expression			{ /* left_shift_assign */ }
	| unary_expression RIGHT_ASSIGN assignment_expression			{ /* right_shift_assign */ }
	| unary_expression AND_ASSIGN assignment_expression			{ /* and_assign */ }
	| unary_expression XOR_ASSIGN assignment_expression			{ /* xor_assign */ }
	| unary_expression OR_ASSIGN assignment_expression			{ /* or_assign */ }
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
	: TYPEDEF								{ /* typedef_str_class_spec */ }
	| EXTERN								{ /* extern_str_class_spec */ }
	| STATIC								{ /* static_str_class_spec */ }
	| AUTO									{ /* auto_str_class_spec */ }
	| REGISTER								{ /* register_str_class_spec */ }
	;

type_specifier
	: VOID									{ /* void_type_spec */ }
	| CHAR									{ /* char_type_spec */ }
	| SHORT									{ /* short_type_spec */ }
	| INT									{ /* int_type_spec */ }
	| LONG									{ /* long_type_spec */ }
	| FLOAT									{ /* float_type_spec */ }
	| DOUBLE								{ /* double_type_spec */ }
	| SIGNED								{ /* signed_type_spec */ }
	| UNSIGNED								{ /* unsigned_type_spec */ }
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'		{ /* struct_definition_spec */ }
	| struct_or_union '{' struct_declaration_list '}'			{ /* struct_definition_spec */ }
	| struct_or_union IDENTIFIER						{ /* struct_definition_spec */ }
	;

struct_or_union
	: STRUCT
	| UNION
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
	: ENUM '{' enumerator_list '}'						{ /* defined_enum_spec */ }
	| ENUM IDENTIFIER '{' enumerator_list '}'				{ /* defined_enum_spec */ }
	| ENUM IDENTIFIER							{ /* referenced_enum_spec */ }
	;

enumerator_list
	: enumerator								{ /* enumerator_list */ }
	| enumerator_list ',' enumerator					{ /* enumerator_list */ }
	;

enumerator
	: IDENTIFIER								{ /* enumerator */ }
	| IDENTIFIER '=' constant_expression					{ /* enumerator */ }
	;

type_qualifier
	: CONST									{ /* const_type_qualifier */ }
	| VOLATILE								{ /* volatile_type_qualifier */ }
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
	| parameter_list ',' ELLIPSIS						{ /* parameter_type_list */ }
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
	: IDENTIFIER ':' statement						{ /* label_statement */ }
	| CASE constant_expression ':' statement				{ /* case_label_statement */ }
	| DEFAULT ':' statement							{ /* default_label_statement */ }
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
	: ';'									{ /* expression_statement */ }
	| expression ';'							{ /* expression_statement */ }
	;

selection_statement
	: IF '(' expression ')' statement					{ /* if_statement */ }
	| IF '(' expression ')' statement ELSE statement			{ /* if_statement */ }
	| SWITCH '(' expression ')' statement					{ /* switch_statement */ }
	;

iteration_statement
	: WHILE '(' expression ')' statement					{ /* while_statement */ }
	| DO statement WHILE '(' expression ')' ';'				{ /* do_statement */ }
	| FOR '(' expression_statement expression_statement ')' statement
	  { /* for_statement */ 
	    ast_for_statement_new($n, @1, @2, @3, @4, NULL, @5, @6);
          }
	| FOR '(' expression_statement expression_statement expression ')' statement
          { /* for_statement */
            ast_for_statement_new(@n, @1, @2, @3, @4, @5, @6, @7);
          }
	;

jump_statement
	: GOTO IDENTIFIER ';'							{ /* goto_statement */ }
	| CONTINUE ';'								{ /* continue_statement */ }
	| BREAK ';'								{ /* break_statement */ }
	| RETURN ';'								{ /* return_statement */ }
	| RETURN expression ';'							{ /* return_statement */ }
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
