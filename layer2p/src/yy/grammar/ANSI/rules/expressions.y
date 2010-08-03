%%
%%

primary_expression
	: n1:IDENTIFIER
	  { variable }
	| n1:constant
	  { constant }
	| n1:string_literal_list
	  { string_literal }
	| n1:'(' n2:expression n3:')'
	  { bracket_expression }
	;

postfix_expression
	: n1:primary_expression
	  { fmt180 }
	| n1:postfix_expression n2:'[' n3:expression n4:']'
	  { array_access }
	| n1:postfix_expression n2:'(' n4:')'
	  { function_call }
	| n1:postfix_expression n2:'(' n3:argument_expression_list n4:')'
	  { function_call }
	| n1:postfix_expression n2:'.' n3:identifier_or_typedef_name
	  { struct_access }
	| n1:postfix_expression n2:PTR_OP n3:identifier_or_typedef_name
	  { pointer_access }
	| n1:postfix_expression n2:INC_OP
	  { post_increment }
	| n1:postfix_expression n2:DEC_OP
	  { post_decrement }
	;

argument_expression_list
	: n1:assignment_expression
	  { fmt190 }
	| n1:argument_expression_list n2:',' n3:assignment_expression
	  { fmt191 }
	;

unary_expression
	: n1:postfix_expression
	  { fmt192 }
	| n1:INC_OP n2:unary_expression
	  { pre_increment }
	| n1:DEC_OP n2:unary_expression
	  { pre_decrement }
	| n1:'&' n2:cast_expression
	  { address_of }
	| n1:'*' n2:cast_expression
	  { pointer_dereference }
	| n1:'+' n2:cast_expression
	  { positive }
	| n1:'-' n2:cast_expression
	  { negate }
	| n1:'~' n2:cast_expression
	  { bitwise_negate }
	| n1:'!' n2:cast_expression
	  { logical_not }
	| n1:SIZEOF n2:unary_expression
	  { sizeof_var }
	| n1:SIZEOF n2:'(' n3:type_name n4:')'
	  { sizeof_type }
	;

cast_expression
	: n1:unary_expression
	  { fmt204 }
	| n1:'(' n2:type_name n3:')' n4:bracketed_initialiser_list
	  { compound_literal }
	| n1:'(' n2:type_name n3:')' n4:cast_expression
	  { type_cast }
	;

multiplicative_expression
	: n1:cast_expression
	  { fmt207 }
	| n1:multiplicative_expression n2:'*' n3:cast_expression
	  { multiply }
	| n1:multiplicative_expression n2:'/' n3:cast_expression
	  { divide }
	| n1:multiplicative_expression n2:'%' n3:cast_expression
	  { modulo }
	;

additive_expression
	: n1:multiplicative_expression
	  { fmt211 }
	| n1:additive_expression n2:'+' n3:multiplicative_expression
	  { add }
	| n1:additive_expression n2:'-' n3:multiplicative_expression
	  { subtract }
	;

shift_expression
	: n1:additive_expression
	  { fmt214 }
	| n1:shift_expression n2:LSH_OP n3:additive_expression
	  { shift_left }
	| n1:shift_expression n2:RSH_OP n3:additive_expression
	  { shift_right }
	;

relational_expression
	: n1:shift_expression
	  { fmt217 }
	| n1:relational_expression n2:'<' n3:shift_expression
	  { less_than }
	| n1:relational_expression n2:'>' n3:shift_expression
	  { greater_than }
	| n1:relational_expression n2:LE_OP n3:shift_expression
	  { less_than_equals }
	| n1:relational_expression n2:GE_OP n3:shift_expression
	  { greater_than_equals }
	;

equality_expression
	: n1:relational_expression
	  { fmt222 }
	| n1:equality_expression n2:EQ_OP n3:relational_expression
	  { equals }
	| n1:equality_expression n2:NE_OP n3:relational_expression
	  { not_equals }
	;

and_expression
	: n1:equality_expression
	  { fmt225 }
	| n1:and_expression n2:'&' n3:equality_expression
	  { bitwise_and }
	;

exclusive_or_expression
	: n1:and_expression
	  { fmt227 }
	| n1:exclusive_or_expression n2:'^' n3:and_expression
	  { bitwise_xor }
	;

inclusive_or_expression
	: n1:exclusive_or_expression
	  { fmt229 }
	| n1:inclusive_or_expression n2:'|' n3:exclusive_or_expression
	  { bitwise_or }
	;

logical_and_expression
	: n1:inclusive_or_expression
	  { fmt231 }
	| n1:logical_and_expression n2:AND_OP n3:inclusive_or_expression
	  { logical_and }
	;

logical_or_expression
	: n1:logical_and_expression
	  { fmt233 }
	| n1:logical_or_expression n2:OR_OP n3:logical_and_expression
	  { logical_or }
	;

conditional_expression
	: n1:logical_or_expression
	  { fmt235 }
	| n1:logical_or_expression n2:'?' n3:expression n4:':' n5:conditional_expression
	  { ternary_op }
	| n1:logical_or_expression n2:'?' n4:':' n5:conditional_expression
	  { ternary_op }
	;

assignment_expression
	: n1:conditional_expression
	  { fmt238 }
	| n1:cast_expression n2:'=' n3:assignment_expression
	  { assign }
	| n1:cast_expression n2:MUL_ASSIGN n3:assignment_expression
	  { multiply_assign }
	| n1:cast_expression n2:DIV_ASSIGN n3:assignment_expression
	  { divide_assign }
	| n1:cast_expression n2:MOD_ASSIGN n3:assignment_expression
	  { modulo_assign }
	| n1:cast_expression n2:ADD_ASSIGN n3:assignment_expression
	  { add_assign }
	| n1:cast_expression n2:SUB_ASSIGN n3:assignment_expression
	  { subtract_assign }
	| n1:cast_expression n2:LSH_ASSIGN n3:assignment_expression
	  { left_shift_assign }
	| n1:cast_expression n2:RSH_ASSIGN n3:assignment_expression
	  { right_shift_assign }
	| n1:cast_expression n2:AND_ASSIGN n3:assignment_expression
	  { and_assign }
	| n1:cast_expression n2:XOR_ASSIGN n3:assignment_expression
	  { xor_assign }
	| n1:cast_expression n2:OR_ASSIGN n3:assignment_expression
	  { or_assign }
	;

expression
	: n1:assignment_expression
	  { fmt251 }
	| n1:expression n2:',' n3:assignment_expression
	  { fmt252 }
	;

constant_expression
	: n1:conditional_expression
	  { fmt253 }
	;

expression_opt
	: n1:empty
	  { fmt250 }
	| n1:expression
	  { fmt254 }
	;
