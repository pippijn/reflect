%%
%%

primary_expression
	: IDENTIFIER
	  { $$ = pt_variable_new ($1); }
	| constant
	  { $$ = pt_constant_new ($1); }
	| string_literal_list
	  { $$ = pt_string_literal_new ($1); }
	| '(' expression ')'
	  { $$ = pt_bracket_expression_new ($1, $2, $3); }
	;

postfix_expression
	: primary_expression
	  { $$ = pt_fmt180_new ($1); }
	| postfix_expression '[' expression ']'
	  { $$ = pt_fmt181_new ($1, $2, $3, $4); }
	| postfix_expression '(' ')'
	  { $$ = pt_fmt182_new ($1, $2, $3); }
	| postfix_expression '(' argument_expression_list ')'
	  { $$ = pt_fmt183_new ($1, $2, $3, $4); }
	| postfix_expression '.' IDENTIFIER
	  { $$ = pt_fmt184_new ($1, $2, $3); }
	| postfix_expression PTR_OP IDENTIFIER
	  { $$ = pt_fmt185_new ($1, $2, $3); }
	| postfix_expression INC_OP
	  { $$ = pt_fmt186_new ($1, $2); }
	| postfix_expression DEC_OP
	  { $$ = pt_fmt187_new ($1, $2); }
	| postfix_expression '.' TYPEDEF_NAME
	  { $$ = pt_fmt188_new ($1, $2, $3); }
	| postfix_expression PTR_OP TYPEDEF_NAME
	  { $$ = pt_fmt189_new ($1, $2, $3); }
	;

argument_expression_list
	: assignment_expression
	  { $$ = pt_fmt190_new ($1); }
	| argument_expression_list ',' assignment_expression
	  { $$ = pt_fmt191_new ($1, $2, $3); }
	;

unary_expression
	: postfix_expression
	  { $$ = pt_fmt192_new ($1); }
	| INC_OP unary_expression
	  { $$ = pt_fmt193_new ($1, $2); }
	| DEC_OP unary_expression
	  { $$ = pt_fmt194_new ($1, $2); }
	| unary_operator cast_expression
	  { $$ = pt_fmt195_new ($1, $2); }
	| SIZEOF unary_expression
	  { $$ = pt_fmt196_new ($1, $2); }
	| SIZEOF '(' type_name ')'
	  { $$ = pt_fmt197_new ($1, $2, $3, $4); }
	;

unary_operator
	: '&'
	  { $$ = pt_fmt198_new ($1); }
	| '*'
	  { $$ = pt_fmt199_new ($1); }
	| '+'
	  { $$ = pt_fmt200_new ($1); }
	| '-'
	  { $$ = pt_fmt201_new ($1); }
	| '~'
	  { $$ = pt_fmt202_new ($1); }
	| '!'
	  { $$ = pt_fmt203_new ($1); }
	;

cast_expression
	: unary_expression
	  { $$ = pt_fmt204_new ($1); }
	| '(' type_name ')' bracketed_initialiser_list
	  { $$ = pt_fmt205_new ($1, $2, $3, $4); }
	| '(' type_name ')' cast_expression
	  { $$ = pt_fmt206_new ($1, $2, $3, $4); }
	;

multiplicative_expression
	: cast_expression
	  { $$ = pt_fmt207_new ($1); }
	| multiplicative_expression '*' cast_expression
	  { $$ = pt_fmt208_new ($1, $2, $3); }
	| multiplicative_expression '/' cast_expression
	  { $$ = pt_fmt209_new ($1, $2, $3); }
	| multiplicative_expression '%' cast_expression
	  { $$ = pt_fmt210_new ($1, $2, $3); }
	;

additive_expression
	: multiplicative_expression
	  { $$ = pt_fmt211_new ($1); }
	| additive_expression '+' multiplicative_expression
	  { $$ = pt_fmt212_new ($1, $2, $3); }
	| additive_expression '-' multiplicative_expression
	  { $$ = pt_fmt213_new ($1, $2, $3); }
	;

shift_expression
	: additive_expression
	  { $$ = pt_fmt214_new ($1); }
	| shift_expression LSH_OP additive_expression
	  { $$ = pt_fmt215_new ($1, $2, $3); }
	| shift_expression RSH_OP additive_expression
	  { $$ = pt_fmt216_new ($1, $2, $3); }
	;

relational_expression
	: shift_expression
	  { $$ = pt_fmt217_new ($1); }
	| relational_expression '<' shift_expression
	  { $$ = pt_fmt218_new ($1, $2, $3); }
	| relational_expression '>' shift_expression
	  { $$ = pt_fmt219_new ($1, $2, $3); }
	| relational_expression LE_OP shift_expression
	  { $$ = pt_fmt220_new ($1, $2, $3); }
	| relational_expression GE_OP shift_expression
	  { $$ = pt_fmt221_new ($1, $2, $3); }
	;

equality_expression
	: relational_expression
	  { $$ = pt_fmt222_new ($1); }
	| equality_expression EQ_OP relational_expression
	  { $$ = pt_fmt223_new ($1, $2, $3); }
	| equality_expression NE_OP relational_expression
	  { $$ = pt_fmt224_new ($1, $2, $3); }
	;

AND_expression
	: equality_expression
	  { $$ = pt_fmt225_new ($1); }
	| AND_expression '&' equality_expression
	  { $$ = pt_fmt226_new ($1, $2, $3); }
	;

exclusive_OR_expression
	: AND_expression
	  { $$ = pt_fmt227_new ($1); }
	| exclusive_OR_expression '^' AND_expression
	  { $$ = pt_fmt228_new ($1, $2, $3); }
	;

inclusive_OR_expression
	: exclusive_OR_expression
	  { $$ = pt_fmt229_new ($1); }
	| inclusive_OR_expression '|' exclusive_OR_expression
	  { $$ = pt_fmt230_new ($1, $2, $3); }
	;

logical_AND_expression
	: inclusive_OR_expression
	  { $$ = pt_fmt231_new ($1); }
	| logical_AND_expression AND_OP inclusive_OR_expression
	  { $$ = pt_fmt232_new ($1, $2, $3); }
	;

logical_OR_expression
	: logical_AND_expression
	  { $$ = pt_fmt233_new ($1); }
	| logical_OR_expression OR_OP logical_AND_expression
	  { $$ = pt_fmt234_new ($1, $2, $3); }
	;

conditional_expression
	: logical_OR_expression
	  { $$ = pt_fmt235_new ($1); }
	| logical_OR_expression '?' expression ':' conditional_expression
	  { $$ = pt_fmt236_new ($1, $2, $3, $4, $5); }
	| logical_OR_expression '?' ':' conditional_expression
	  { $$ = pt_fmt237_new ($1, $2, $3, $4); }
	;

assignment_expression
	: conditional_expression
	  { $$ = pt_fmt238_new ($1); }
	| cast_expression assignment_operator assignment_expression
	  { $$ = pt_fmt239_new ($1, $2, $3); }
	;

assignment_operator
	: '='
	  { $$ = pt_fmt240_new ($1); }
	| MUL_ASSIGN
	  { $$ = pt_fmt241_new ($1); }
	| DIV_ASSIGN
	  { $$ = pt_fmt242_new ($1); }
	| MOD_ASSIGN
	  { $$ = pt_fmt243_new ($1); }
	| ADD_ASSIGN
	  { $$ = pt_fmt244_new ($1); }
	| SUB_ASSIGN
	  { $$ = pt_fmt245_new ($1); }
	| LSH_ASSIGN
	  { $$ = pt_fmt246_new ($1); }
	| RSH_ASSIGN
	  { $$ = pt_fmt247_new ($1); }
	| AND_ASSIGN
	  { $$ = pt_fmt248_new ($1); }
	| XOR_ASSIGN
	  { $$ = pt_fmt249_new ($1); }
	| OR_ASSIGN
	  { $$ = pt_fmt250_new ($1); }
	;

expression
	: assignment_expression
	  { $$ = pt_fmt251_new ($1); }
	| expression ',' assignment_expression
	  { $$ = pt_fmt252_new ($1, $2, $3); }
	;

constant_expression
	: conditional_expression
	  { $$ = pt_fmt253_new ($1); }
	;

expression_opt
	: expression
	  { $$ = pt_fmt254_new ($1); }
	;
