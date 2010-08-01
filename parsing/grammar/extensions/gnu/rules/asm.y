%%
%%

statement
	: asm_statement
	  { $$ = pt_fmt350_new ($1); }
	;

asm_statement
	: ASM '(' string_literal_list ')' ';'
	  { $$ = pt_fmt351_new ($1, $2, $3, $4, $5); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ')' ';'
	  { $$ = pt_fmt352_new ($1, $2, $3, $4, $5, $6, $7); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ')' ';'
	  { $$ = pt_fmt353_new ($1, $2, $3, $4, $5, $6, $7, $8, $9); }
	| ASM '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ':' asm_clobbered_list ')' ';'
	  { $$ = pt_fmt354_new ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11); }
	| ASM type_qualifier '(' string_literal_list ')' ';'
	  { $$ = pt_fmt355_new ($1, $2, $3, $4, $5, $6); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ')' ';'
	  { $$ = pt_fmt356_new ($1, $2, $3, $4, $5, $6, $7, $8); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ')' ';'
	  { $$ = pt_fmt357_new ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10); }
	| ASM type_qualifier '(' string_literal_list ':' asm_argument_list_opt ':' asm_argument_list_opt ':' asm_clobbered_list ')' ';'
	  { $$ = pt_fmt358_new ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12); }
	;

asm_opt
	: empty
	  { $$ = pt_fmt359_new ($1); }
	| asm
	  { $$ = pt_fmt360_new ($1); }
	;
asm
	: ASM '(' string_literal_list ')'
	  { $$ = pt_fmt361_new ($1, $2, $3, $4); }
	;

asm_argument_list_opt
	: asm_argument_list
	  { $$ = pt_fmt362_new ($1); }
	;
asm_argument_list
	: asm_argument
	  { $$ = pt_fmt363_new ($1); }
	| asm_argument_list ',' asm_argument
	  { $$ = pt_fmt364_new ($1, $2, $3); }
	;
asm_argument
	: string_literal_list '(' assignment_expression ')'
	  { $$ = pt_fmt365_new ($1, $2, $3, $4); }
	;
asm_clobbered_list
	: string_literal_list
	  { $$ = pt_fmt366_new ($1); }
	| asm_clobbered_list ',' string_literal_list
	  { $$ = pt_fmt367_new ($1, $2, $3); }
	;
