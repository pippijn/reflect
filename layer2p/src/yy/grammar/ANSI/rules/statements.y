%%
%%

statement
	: n1:labeled_statement
	  { fmt282 }
	| n1:compound_statement
	  { fmt283 }
	| n1:expression_statement
	  { fmt284 }
	| n1:selection_statement
	  { fmt285 }
	| n1:iteration_statement
	  { fmt286 }
	| n1:jump_statement
	  { fmt287 }
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
	: n1:declaration
	  { fmt296 }
	| n1:declaration_list n2:declaration
	  { fmt297 }
	;

statement_list
	: n1:statement
	  { fmt298 }
	| n1:statement_list n2:statement
	  { fmt299 }
	;

expression_statement
	: n1:expression_opt n2:';'
	  { fmt300 }
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
