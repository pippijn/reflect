%%
%%

primary_expression
	: :IDENTIFIER
	| :constant
	| :string_literal_list
	| lbrack:'(' expr:expression rbrack:')'
	  { bracket_expression }
	;

postfix_expression
	: :primary_expression
	| lhs:postfix_expression lsqbrack:'[' rhs:expression rsqbrack:']'
	  { array_access }
	| lhs:postfix_expression lbrack:'('                               rbrack:')'
	  { function_call }
	| lhs:postfix_expression lbrack:'(' args:argument_expression_list rbrack:')'
	  { function_call }
	| lhs:postfix_expression op:'.' member:identifier_or_typedef_name
	  { struct_access }
	| lhs:postfix_expression op:PTR_OP member:identifier_or_typedef_name
	  { pointer_access }
	| expr:postfix_expression op:INC_OP
	  { post_increment }
	| expr:postfix_expression op:DEC_OP
	  { post_decrement }
	;

argument_expression_list
	:                                         expr:assignment_expression
	  { argument_expression_list }
	| prev:argument_expression_list comma:',' expr:assignment_expression
	  { argument_expression_list }
	;

unary_expression
	: :postfix_expression
	| op:INC_OP expr:unary_expression
	  { pre_increment }
	| op:DEC_OP expr:unary_expression
	  { pre_decrement }
	| op:'&' expr:cast_expression
	  { address_of }
	| op:'*' expr:cast_expression
	  { pointer_dereference }
	| op:'+' expr:cast_expression
	  { positive }
	| op:'-' expr:cast_expression
	  { negate }
	| op:'~' expr:cast_expression
	  { bitwise_negate }
	| op:'!' expr:cast_expression
	  { logical_not }
	| op:SIZEOF expr:unary_expression
	  { sizeof_var }
	| op:SIZEOF lbrack:'(' expr:type_name rbrack:')'
	  { sizeof_type }
	;

cast_expression
	: :unary_expression
	| lbrack:'(' type:type_name rbrack:')' init_list:bracketed_initialiser_list
	  { compound_literal }
	| lbrack:'(' type:type_name rbrack:')' expr:cast_expression
	  { type_cast }
	;

multiplicative_expression
	: :cast_expression
	| lhs:multiplicative_expression op:'*' rhs:multiplicative_expression
	  { multiply }
	| lhs:multiplicative_expression op:'/' rhs:multiplicative_expression
	  { divide }
	| lhs:multiplicative_expression op:'%' rhs:multiplicative_expression
	  { modulo }

	| lhs:multiplicative_expression op:'+' rhs:multiplicative_expression
	  { add }
	| lhs:multiplicative_expression op:'-' rhs:multiplicative_expression
	  { subtract }

	| lhs:multiplicative_expression op:LSH_OP rhs:multiplicative_expression
	  { shift_left }
	| lhs:multiplicative_expression op:RSH_OP rhs:multiplicative_expression
	  { shift_right }

	| lhs:multiplicative_expression op:'<' rhs:multiplicative_expression
	  { less_than }
	| lhs:multiplicative_expression op:'>' rhs:multiplicative_expression
	  { greater_than }
	| lhs:multiplicative_expression op:LE_OP rhs:multiplicative_expression
	  { less_than_equals }
	| lhs:multiplicative_expression op:GE_OP rhs:multiplicative_expression
	  { greater_than_equals }

	| lhs:multiplicative_expression op:EQ_OP rhs:multiplicative_expression
	  { equals }
	| lhs:multiplicative_expression op:NE_OP rhs:multiplicative_expression
	  { not_equals }

	| lhs:multiplicative_expression op:'&' rhs:multiplicative_expression
	  { bitwise_and }

	| lhs:multiplicative_expression op:'^' rhs:multiplicative_expression
	  { bitwise_xor }

	| lhs:multiplicative_expression op:'|' rhs:multiplicative_expression
	  { bitwise_or }

	| lhs:multiplicative_expression op:AND_OP rhs:multiplicative_expression
	  { logical_and }

	| lhs:multiplicative_expression op:OR_OP rhs:multiplicative_expression
	  { logical_or }

	| cond:multiplicative_expression qmark:'?' then_expr:expression colon:':' else_expr:multiplicative_expression
	  { ternary_op }
	| cond:multiplicative_expression qmark:'?'                      colon:':' else_expr:multiplicative_expression
	  { ternary_op }
	;

assignment_expression
	: :multiplicative_expression
	| lhs:multiplicative_expression op:'=' rhs:assignment_expression
	  { assign }
	| lhs:multiplicative_expression op:MUL_ASSIGN rhs:assignment_expression
	  { multiply_assign }
	| lhs:multiplicative_expression op:DIV_ASSIGN rhs:assignment_expression
	  { divide_assign }
	| lhs:multiplicative_expression op:MOD_ASSIGN rhs:assignment_expression
	  { modulo_assign }
	| lhs:multiplicative_expression op:ADD_ASSIGN rhs:assignment_expression
	  { add_assign }
	| lhs:multiplicative_expression op:SUB_ASSIGN rhs:assignment_expression
	  { subtract_assign }
	| lhs:multiplicative_expression op:LSH_ASSIGN rhs:assignment_expression
	  { left_shift_assign }
	| lhs:multiplicative_expression op:RSH_ASSIGN rhs:assignment_expression
	  { right_shift_assign }
	| lhs:multiplicative_expression op:AND_ASSIGN rhs:assignment_expression
	  { and_assign }
	| lhs:multiplicative_expression op:XOR_ASSIGN rhs:assignment_expression
	  { xor_assign }
	| lhs:multiplicative_expression op:OR_ASSIGN rhs:assignment_expression
	  { or_assign }
	;

expression
	: :assignment_expression
	| prev:expression comma:',' expr:assignment_expression
	  { comma_expression }
	;

constant_expression
	: :multiplicative_expression
	;

expression_opt
	: n1:empty
	  { expression_opt250 }
	| n1:expression
	  { expression_opt254 }
	;
