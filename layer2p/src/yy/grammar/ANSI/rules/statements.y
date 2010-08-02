%%
%%

statement
	: labeled_statement
	  { new (fmt282) ($1); }
	| compound_statement
	  { new (fmt283) ($1); }
	| expression_statement
	  { new (fmt284) ($1); }
	| selection_statement
	  { new (fmt285) ($1); }
	| iteration_statement
	  { new (fmt286) ($1); }
	| jump_statement
	  { new (fmt287) ($1); }
	;

labeled_statement
	: identifier_or_typedef_name ':'
	  { new (label_statement) ($1, $2); }
	| CASE constant_expression ':'
	  { new (case_label_statement) ($1, $2, $3); }
	| DEFAULT ':'
	  { new (default_label_statement) ($1, $2); }
	;

compound_statement
	: '{' '}'
	  { new (fmt292) ($1, $2); }
	| '{' declaration_list '}'
	  { new (fmt293) ($1, $2, $3); }
	| '{' statement_list '}'
	  { new (fmt294) ($1, $2, $3); }
	| '{' declaration_list statement_list '}'
	  { new (fmt295) ($1, $2, $3, $4); }
	;



declaration_list
	: declaration
	  { new (fmt296) ($1); }
	| declaration_list declaration
	  { new (fmt297) ($1, $2); }
	;

statement_list
	: statement
	  { new (fmt298) ($1); }
	| statement_list statement
	  { new (fmt299) ($1, $2); }
	;

expression_statement
	: expression_opt ';'
	  { new (fmt300) ($1, $2); }
	;

selection_statement
	: IF '(' expression ')' statement
	  { new (fmt301) ($1, $2, $3, $4, $5); }
	| IF '(' expression ')' statement ELSE statement
	  { new (fmt302) ($1, $2, $3, $4, $5, $6, $7); }
	| SWITCH '(' expression ')' statement
	  { new (fmt303) ($1, $2, $3, $4, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	  { new (fmt304) ($1, $2, $3, $4, $5); }
	| DO statement WHILE '(' expression ')' ';'
	  { new (fmt305) ($1, $2, $3, $4, $5, $6, $7); }
	| FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement
	  { new (fmt306) ($1, $2, $3, $4, $5, $6, $7, $8, $9); }
	;

jump_statement
	: GOTO identifier_or_typedef_name ';'
	  { new (fmt307) ($1, $2, $3); }
	| CONTINUE ';'
	  { new (fmt308) ($1, $2); }
	| BREAK ';'
	  { new (fmt309) ($1, $2); }
	| RETURN expression_opt ';'
	  { new (fmt310) ($1, $2, $3); }
	;
