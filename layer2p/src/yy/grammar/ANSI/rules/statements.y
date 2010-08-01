%%
%%

statement
	: labeled_statement
	  { $$ = pt_fmt282_new ($1); }
	| compound_statement
	  { $$ = pt_fmt283_new ($1); }
	| expression_statement
	  { $$ = pt_fmt284_new ($1); }
	| selection_statement
	  { $$ = pt_fmt285_new ($1); }
	| iteration_statement
	  { $$ = pt_fmt286_new ($1); }
	| jump_statement
	  { $$ = pt_fmt287_new ($1); }
	;

labeled_statement
	: IDENTIFIER ':'
	  { $$ = pt_fmt288_new ($1, $2); }
	| CASE constant_expression ':'
	  { $$ = pt_fmt289_new ($1, $2, $3); }
	| DEFAULT ':'
	  { $$ = pt_fmt290_new ($1, $2); }
	| TYPEDEF_NAME ':'
	  { $$ = pt_fmt291_new ($1, $2); }
	;

compound_statement
	: '{' '}'
	  { $$ = pt_fmt292_new ($1, $2); }
	| '{' declaration_list '}'
	  { $$ = pt_fmt293_new ($1, $2, $3); }
	| '{' statement_list '}'
	  { $$ = pt_fmt294_new ($1, $2, $3); }
	| '{' declaration_list statement_list '}'
	  { $$ = pt_fmt295_new ($1, $2, $3, $4); }
	;



declaration_list
	: declaration
	  { $$ = pt_fmt296_new ($1); }
	| declaration_list declaration
	  { $$ = pt_fmt297_new ($1, $2); }
	;

statement_list
	: statement
	  { $$ = pt_fmt298_new ($1); }
	| statement_list statement
	  { $$ = pt_fmt299_new ($1, $2); }
	;

expression_statement
	: expression_opt ';'
	  { $$ = pt_fmt300_new ($1, $2); }
	;

selection_statement
	: IF '(' expression ')' statement
	  { $$ = pt_fmt301_new ($1, $2, $3, $4, $5); }
	| IF '(' expression ')' statement ELSE statement
	  { $$ = pt_fmt302_new ($1, $2, $3, $4, $5, $6, $7); }
	| SWITCH '(' expression ')' statement
	  { $$ = pt_fmt303_new ($1, $2, $3, $4, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	  { $$ = pt_fmt304_new ($1, $2, $3, $4, $5); }
	| DO statement WHILE '(' expression ')' ';'
	  { $$ = pt_fmt305_new ($1, $2, $3, $4, $5, $6, $7); }
	| FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement
	  { $$ = pt_fmt306_new ($1, $2, $3, $4, $5, $6, $7, $8, $9); }
	;

jump_statement
	: GOTO IDENTIFIER ';'
	  { $$ = pt_fmt307_new ($1, $2, $3); }
	| CONTINUE ';'
	  { $$ = pt_fmt308_new ($1, $2); }
	| BREAK ';'
	  { $$ = pt_fmt309_new ($1, $2); }
	| RETURN expression_opt ';'
	  { $$ = pt_fmt310_new ($1, $2, $3); }
	| GOTO TYPEDEF_NAME ';'
	  { $$ = pt_fmt311_new ($1, $2, $3); }
	;
