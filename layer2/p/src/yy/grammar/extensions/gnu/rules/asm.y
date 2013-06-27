%%
%%

statement
	: n1:asm_statement
	  { statement350 }
	;

asm_statement
	: asm_tok:ASM tquals:type_qualifier? lbrack:'(' code:string_literal+                                                                                                                                          rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier? lbrack:'(' code:string_literal+ in_arg_colon:':' in_args:asm_argument[',']*                                                                                              rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier? lbrack:'(' code:string_literal+ in_arg_colon:':' in_args:asm_argument[',']* out_arg_colon:':' out_args:asm_argument[',']*                                                rbrack:')' semi:';'
	  { asm_statement }
	| asm_tok:ASM tquals:type_qualifier? lbrack:'(' code:string_literal+ in_arg_colon:':' in_args:asm_argument[',']* out_arg_colon:':' out_args:asm_argument[',']* clobber_colon:':' clobbers:asm_clobbered[',']+ rbrack:')' semi:';'
	  { asm_statement }
	;

asm
	: n1:ASM n2:'(' n3:string_literal+ n4:')'
	  { asm361 }
	;

asm_argument
	: target:string_literal+ lbrack:'(' expr:assignment_expression rbrack:')'
	  { asm_argument }
	;
asm_clobbered
	: clobber:string_literal+
	  { asm_clobbered }
	;
