%%
%%

statement
	: n1:labeled_statement
	  { statement282 }
	| n1:compound_statement
	  { statement283 }
	| n1:expression_statement
	  { statement284 }
	| n1:selection_statement
	  { statement285 }
	| n1:iteration_statement
	  { statement286 }
	| n1:jump_statement
	  { statement287 }
	;

labeled_statement
	: label:identifier_or_typedef_name semi:':'
	  { label_statement }
	| case_tok:CASE expr:constant_expression semi:':'
	  { case_label_statement }
	| default_tok:DEFAULT semi:':'
	  { default_label_statement }
	;

compound_statement
	: lbrace:'{'                                             rbrace:'}'
	  { compound_statement }
	| lbrace:'{' decls:declaration_list                      rbrace:'}'
	  { compound_statement }
	| lbrace:'{'                        stmts:statement_list rbrace:'}'
	  { compound_statement }
	| lbrace:'{' decls:declaration_list stmts:statement_list rbrace:'}'
	  { compound_statement }
	;



declaration_list
	:                       decl:declaration
	  { declaration_list }
	| prev:declaration_list decl:declaration
	  { declaration_list }
	;

statement_list
	:                     stmt:statement
	  { statement_list }
	| prev:statement_list stmt:statement
	  { statement_list }
	;

expression_statement
	: n1:expression_opt n2:';'
	  { expression_statement300 }
	;

selection_statement
	: if_tok:IF lbrack:'(' cond:expression rbrack:')' then_stmt:statement
	  { if_statement }
	| if_tok:IF lbrack:'(' cond:expression rbrack:')' then_stmt:statement else_tok:ELSE else_stmt:statement
	  { if_statement }
	| switch_tok:SWITCH lbrack:'(' expr:expression rbrack:')' stmt:statement
	  { switch_statement }
	;

iteration_statement
	: while_tok:WHILE lbrack:'(' cond:expression rbrack:')' stmt:statement
	  { while_statement }
	| do_tok:DO stmt:statement while_tok:WHILE lbrack:'(' cond:expression rbrack:')' semi:';'
	  { do_statement }
	| for_tok:FOR lbrack:'(' init:expression_opt init_semi:';' cond:expression_opt cond_semi:';' inc:expression_opt rbrack:')' stmt:statement
	  { for_statement }
	;

jump_statement
	: goto_tok:GOTO label:identifier_or_typedef_name semi:';'
	  { goto_statement }
	| continue_tok:CONTINUE semi:';'
	  { continue_statement }
	| break_tok:BREAK semi:';'
	  { break_statement }
	| return_tok:RETURN expr:expression_opt semi:';'
	  { return_statement }
	;
