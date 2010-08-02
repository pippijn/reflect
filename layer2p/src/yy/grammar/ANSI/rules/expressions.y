%%
%%

primary_expression
	: IDENTIFIER
	  { new (variable) ($1); }
	| constant
	  { new (constant) ($1); }
	| string_literal_list
	  { new (string_literal) ($1); }
	| '(' expression ')'
	  { new (bracket_expression) ($1, $2, $3); }
	;

postfix_expression
	: primary_expression
	  { new (fmt180) ($1); }
	| postfix_expression '[' expression ']'
	  { new (array_access) ($1, $2, $3, $4); }
	| postfix_expression '(' ')'
	  { new (function_call) ($1, $2, NULL, $3); }
	| postfix_expression '(' argument_expression_list ')'
	  { new (function_call) ($1, $2, $3, $4); }
	| postfix_expression '.' identifier_or_typedef_name
	  { new (struct_access) ($1, $2, $3); }
	| postfix_expression PTR_OP identifier_or_typedef_name
	  { new (pointer_access) ($1, $2, $3); }
	| postfix_expression INC_OP
	  { new (post_increment) ($1, $2); }
	| postfix_expression DEC_OP
	  { new (post_decrement) ($1, $2); }
	;

argument_expression_list
	: assignment_expression
	  { new (fmt190) ($1); }
	| argument_expression_list ',' assignment_expression
	  { new (fmt191) ($1, $2, $3); }
	;

unary_expression
	: postfix_expression
	  { new (fmt192) ($1); }
	| INC_OP unary_expression
	  { new (pre_increment) ($1, $2); }
	| DEC_OP unary_expression
	  { new (pre_decrement) ($1, $2); }
	| '&' cast_expression
	  { new (address_of) ($1, $2); }
	| '*' cast_expression
	  { new (pointer_dereference) ($1, $2); }
	| '+' cast_expression
	  { new (positive) ($1, $2); }
	| '-' cast_expression
	  { new (negate) ($1, $2); }
	| '~' cast_expression
	  { new (bitwise_negate) ($1, $2); }
	| '!' cast_expression
	  { new (logical_not) ($1, $2); }
	| SIZEOF unary_expression
	  { new (sizeof_var) ($1, $2); }
	| SIZEOF '(' type_name ')'
	  { new (sizeof_type) ($1, $2, $3, $4); }
	;

cast_expression
	: unary_expression
	  { new (fmt204) ($1); }
	| '(' type_name ')' bracketed_initialiser_list
	  { new (compound_literal) ($1, $2, $3, $4); }
	| '(' type_name ')' cast_expression
	  { new (type_cast) ($1, $2, $3, $4); }
	;

multiplicative_expression
	: cast_expression
	  { new (fmt207) ($1); }
	| multiplicative_expression '*' cast_expression
	  { new (multiply) ($1, $2, $3); }
	| multiplicative_expression '/' cast_expression
	  { new (divide) ($1, $2, $3); }
	| multiplicative_expression '%' cast_expression
	  { new (modulo) ($1, $2, $3); }
	;

additive_expression
	: multiplicative_expression
	  { new (fmt211) ($1); }
	| additive_expression '+' multiplicative_expression
	  { new (add) ($1, $2, $3); }
	| additive_expression '-' multiplicative_expression
	  { new (subtract) ($1, $2, $3); }
	;

shift_expression
	: additive_expression
	  { new (fmt214) ($1); }
	| shift_expression LSH_OP additive_expression
	  { new (shift_left) ($1, $2, $3); }
	| shift_expression RSH_OP additive_expression
	  { new (shift_right) ($1, $2, $3); }
	;

relational_expression
	: shift_expression
	  { new (fmt217) ($1); }
	| relational_expression '<' shift_expression
	  { new (less_than) ($1, $2, $3); }
	| relational_expression '>' shift_expression
	  { new (greater_than) ($1, $2, $3); }
	| relational_expression LE_OP shift_expression
	  { new (less_than_equals) ($1, $2, $3); }
	| relational_expression GE_OP shift_expression
	  { new (greater_than_equals) ($1, $2, $3); }
	;

equality_expression
	: relational_expression
	  { new (fmt222) ($1); }
	| equality_expression EQ_OP relational_expression
	  { new (equals) ($1, $2, $3); }
	| equality_expression NE_OP relational_expression
	  { new (not_equals) ($1, $2, $3); }
	;

and_expression
	: equality_expression
	  { new (fmt225) ($1); }
	| and_expression '&' equality_expression
	  { new (bitwise_and) ($1, $2, $3); }
	;

exclusive_or_expression
	: and_expression
	  { new (fmt227) ($1); }
	| exclusive_or_expression '^' and_expression
	  { new (bitwise_xor) ($1, $2, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	  { new (fmt229) ($1); }
	| inclusive_or_expression '|' exclusive_or_expression
	  { new (bitwise_or) ($1, $2, $3); }
	;

logical_and_expression
	: inclusive_or_expression
	  { new (fmt231) ($1); }
	| logical_and_expression AND_OP inclusive_or_expression
	  { new (logical_and) ($1, $2, $3); }
	;

logical_or_expression
	: logical_and_expression
	  { new (fmt233) ($1); }
	| logical_or_expression OR_OP logical_and_expression
	  { new (logical_or) ($1, $2, $3); }
	;

conditional_expression
	: logical_or_expression
	  { new (fmt235) ($1); }
	| logical_or_expression '?' expression ':' conditional_expression
	  { new (ternary_op) ($1, $2, $3, $4, $5); }
	| logical_or_expression '?' ':' conditional_expression
	  { new (ternary_op) ($1, $2, NULL, $3, $4); }
	;

assignment_expression
	: conditional_expression
	  { new (fmt238) ($1); }
	| cast_expression '=' assignment_expression
	  { new (assign) ($1, $2, $3); }
	| cast_expression MUL_ASSIGN assignment_expression
	  { new (multiply_assign) ($1, $2, $3); }
	| cast_expression DIV_ASSIGN assignment_expression
	  { new (divide_assign) ($1, $2, $3); }
	| cast_expression MOD_ASSIGN assignment_expression
	  { new (modulo_assign) ($1, $2, $3); }
	| cast_expression ADD_ASSIGN assignment_expression
	  { new (add_assign) ($1, $2, $3); }
	| cast_expression SUB_ASSIGN assignment_expression
	  { new (subtract_assign) ($1, $2, $3); }
	| cast_expression LSH_ASSIGN assignment_expression
	  { new (left_shift_assign) ($1, $2, $3); }
	| cast_expression RSH_ASSIGN assignment_expression
	  { new (right_shift_assign) ($1, $2, $3); }
	| cast_expression AND_ASSIGN assignment_expression
	  { new (and_assign) ($1, $2, $3); }
	| cast_expression XOR_ASSIGN assignment_expression
	  { new (xor_assign) ($1, $2, $3); }
	| cast_expression OR_ASSIGN assignment_expression
	  { new (or_assign) ($1, $2, $3); }
	;

expression
	: assignment_expression
	  { new (fmt251) ($1); }
	| expression ',' assignment_expression
	  { new (fmt252) ($1, $2, $3); }
	;

constant_expression
	: conditional_expression
	  { new (fmt253) ($1); }
	;

expression_opt
	: empty
	  { new (fmt250) ($1); }
	| expression
	  { new (fmt254) ($1); }
	;
