%%
%%

statement
	: asm_statement
	  { new (fmt350) ($1); }
	;

asm_statement
	: ASM '(' string_literal_list ')' ';'
	  { new (fmt351) ($1, $2, $3, $4, $5); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ')' ';'
	  { new (fmt352) ($1, $2, $3, $4, $5, $6, $7); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ')' ';'
	  { new (fmt353) ($1, $2, $3, $4, $5, $6, $7, $8, $9); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ':' asm_clobbered_list ')' ';'
	  { new (fmt354) ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11); }
	| ASM type_qualifier '(' string_literal_list ')' ';'
	  { new (fmt355) ($1, $2, $3, $4, $5, $6); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ')' ';'
	  { new (fmt356) ($1, $2, $3, $4, $5, $6, $7, $8); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ')' ';'
	  { new (fmt357) ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ':' asm_clobbered_list ')' ';'
	  { new (fmt358) ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12); }
	;

asm_opt
	: empty
	  { new (fmt359) ($1); }
	| asm
	  { new (fmt360) ($1); }
	;
asm
	: ASM '(' string_literal_list ')'
	  { new (fmt361) ($1, $2, $3, $4); }
	;

asm_argument_list_opt
	: asm_argument_list
	  { new (fmt362) ($1); }
	;
asm_argument_list
	: asm_argument
	  { new (fmt363) ($1); }
	| asm_argument_list ',' asm_argument
	  { new (fmt364) ($1, $2, $3); }
	;
asm_argument
	: string_literal_list '(' assignment_expression ')'
	  { new (fmt365) ($1, $2, $3, $4); }
	;
asm_clobbered_list
	: string_literal_list
	  { new (fmt366) ($1); }
	| asm_clobbered_list ',' string_literal_list
	  { new (fmt367) ($1, $2, $3); }
	;
