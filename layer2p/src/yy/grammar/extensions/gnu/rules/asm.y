%%
%%

statement
	: n1:asm_statement
	  { fmt350 }
	;

asm_statement
	: asm_tok:ASM tquals:type_qualifier_opt lbrack:'(' code:string_literal_list                                                                                                                                               rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier_opt lbrack:'(' code:string_literal_list in_arg_colon:':' in_args:asm_argument_list_opt                                                                                                rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier_opt lbrack:'(' code:string_literal_list in_arg_colon:':' in_args:asm_argument_list_opt out_arg_colon:':' out_args:asm_argument_list_opt                                               rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier_opt lbrack:'(' code:string_literal_list in_arg_colon:':' in_args:asm_argument_list_opt out_arg_colon:':' out_args:asm_argument_list_opt clobber_colon:':' clobbers:asm_clobbered_list rbrack:')' semi:';'
	  { asm_statement }
	;

asm_opt
	: n1:empty
	  { fmt359 }
	| n1:asm
	  { fmt360 }
	;
asm
	: n1:ASM n2:'(' n3:string_literal_list n4:')'
	  { fmt361 }
	;

asm_argument_list_opt
	: n1:asm_argument_list
	  { fmt362 }
	;
asm_argument_list
	: n1:asm_argument
	  { fmt363 }
	| n1:asm_argument_list n2:',' n3:asm_argument
	  { fmt364 }
	;
asm_argument
	: target:string_literal_list lbrack:'(' expr:assignment_expression rbrack:')'
	  { asm_argument }
	;
asm_clobbered_list
	: n1:string_literal_list
	  { fmt366 }
	| n1:asm_clobbered_list n2:',' n3:string_literal_list
	  { fmt367 }
	;
