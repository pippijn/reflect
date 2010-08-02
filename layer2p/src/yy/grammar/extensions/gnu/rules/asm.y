%%
%%

statement
	: n1:asm_statement
	  { fmt350 }
	;

asm_statement
	: n1:ASM n2:'(' n3:string_literal_list n4:')' n5:';'
	  { fmt351 }
	| n1:ASM n2:'(' n3:string_literal_list n4:':' n5:asm_argument_list_opt n6:')' n7:';'
	  { fmt352 }
	| n1:ASM n2:'(' n3:string_literal_list n4:':' n5:asm_argument_list_opt n6:':' n7:asm_argument_list_opt n8:')' n9:';'
	  { fmt353 }
	| n1:ASM n2:'(' n3:string_literal_list n4:':' n5:asm_argument_list_opt n6:':' n7:asm_argument_list_opt n8:':' n9:asm_clobbered_list n10:')' n11:';'
	  { fmt354 }
	| n1:ASM n2:type_qualifier n3:'(' n4:string_literal_list n5:')' n6:';'
	  { fmt355 }
	| n1:ASM n2:type_qualifier n3:'(' n4:string_literal_list n5:':' n6:asm_argument_list_opt n7:')' n8:';'
	  { fmt356 }
	| n1:ASM n2:type_qualifier n3:'(' n4:string_literal_list n5:':' n6:asm_argument_list_opt n7:':' n8:asm_argument_list_opt n9:')' n10:';'
	  { fmt357 }
	| n1:ASM n2:type_qualifier n3:'(' n4:string_literal_list n5:':' n6:asm_argument_list_opt n7:':' n8:asm_argument_list_opt n9:':' n10:asm_clobbered_list n11:')' n12:';'
	  { fmt358 }
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
	: n1:string_literal_list n2:'(' n3:assignment_expression n4:')'
	  { fmt365 }
	;
asm_clobbered_list
	: n1:string_literal_list
	  { fmt366 }
	| n1:asm_clobbered_list n2:',' n3:string_literal_list
	  { fmt367 }
	;
