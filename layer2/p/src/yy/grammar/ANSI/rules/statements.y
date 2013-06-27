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
	: label:identifier semi:':'
	  { label_statement }
	| case:CASE expr:constant_expression semi:':'
	  { case_label_statement }
	| default:DEFAULT semi:':'
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
	: if:IF lbrack:'(' cond:expression rbrack:')' then_stmt:statement %prec SHIFT_THERE
	  { if_statement }
	| if:IF lbrack:'(' cond:expression rbrack:')' then_stmt:statement else:ELSE else_stmt:statement
	  { if_statement }
	| switch:SWITCH lbrack:'(' expr:expression rbrack:')' stmt:statement
	  { switch_statement }
	;

iteration_statement
	: while:WHILE lbrack:'(' cond:expression rbrack:')' stmt:statement
	  { while_statement }
	| do:DO stmt:statement while:WHILE lbrack:'(' cond:expression rbrack:')' semi:';'
	  { do_statement }
	| for:FOR lbrack:'(' init:expression? init_semi:';' cond:expression? cond_semi:';' inc:expression? rbrack:')' stmt:statement
	  { for_statement }
	;

jump_statement
	: goto:GOTO label:identifier semi:';'
	  { goto_statement }
	| continue:CONTINUE semi:';'
	  { continue_statement }
	| break:BREAK semi:';'
	  { break_statement }
	| return:RETURN expr:expression? semi:';'
	  { return_statement }
	;
