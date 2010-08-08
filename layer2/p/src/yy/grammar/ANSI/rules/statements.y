%%
%%

statement
	: :labeled_statement
	| :compound_statement
	| :expression_statement
	| :selection_statement
	| :iteration_statement
	| :jump_statement
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
	: lbrace:'{'                                     rbrace:'}'
	  { compound_statement }
	| lbrace:'{' decls:declaration+                  rbrace:'}' %merge <node_merge>
	  { compound_statement }
	| lbrace:'{'                    stmts:statement+ rbrace:'}' %merge <node_merge>
	  { compound_statement }
	| lbrace:'{' decls:declaration+ stmts:statement+ rbrace:'}' %merge <node_merge>
	  { compound_statement }
	;


expression_statement
	: expr:expression? semi:';'
	  { expression_statement }
	;

selection_statement
	: if_tok:IF lbrack:'(' cond:expression rbrack:')' then_stmt:statement %prec SHIFT_THERE
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
	| for_tok:FOR lbrack:'(' init:expression? init_semi:';' cond:expression? cond_semi:';' inc:expression? rbrack:')' stmt:statement
	  { for_statement }
	;

jump_statement
	: goto_tok:GOTO label:identifier_or_typedef_name semi:';'
	  { goto_statement }
	| continue_tok:CONTINUE semi:';'
	  { continue_statement }
	| break_tok:BREAK semi:';'
	  { break_statement }
	| return_tok:RETURN expr:expression? semi:';'
	  { return_statement }
	;
