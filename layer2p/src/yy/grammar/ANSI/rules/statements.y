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
	: n1:identifier_or_typedef_name n2:':'
	  { label_statement }
	| n1:CASE n2:constant_expression n3:':'
	  { case_label_statement }
	| n1:DEFAULT n2:':'
	  { default_label_statement }
	;

compound_statement
	: n1:'{' n2:'}'
	  { fmt292 }
	| n1:'{' n2:declaration_list n3:'}'
	  { fmt293 }
	| n1:'{' n2:statement_list n3:'}'
	  { fmt294 }
	| n1:'{' n2:declaration_list n3:statement_list n4:'}'
	  { fmt295 }
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
	: n1:IF n2:'(' n3:expression n4:')' n5:statement
	  { fmt301 }
	| n1:IF n2:'(' n3:expression n4:')' n5:statement n6:ELSE n7:statement
	  { fmt302 }
	| n1:SWITCH n2:'(' n3:expression n4:')' n5:statement
	  { fmt303 }
	;

iteration_statement
	: n1:WHILE n2:'(' n3:expression n4:')' n5:statement
	  { fmt304 }
	| n1:DO n2:statement n3:WHILE n4:'(' n5:expression n6:')' n7:';'
	  { fmt305 }
	| n1:FOR n2:'(' n3:expression_opt n4:';' n5:expression_opt n6:';' n7:expression_opt n8:')' n9:statement
	  { fmt306 }
	;

jump_statement
	: n1:GOTO n2:identifier_or_typedef_name n3:';'
	  { fmt307 }
	| n1:CONTINUE n2:';'
	  { fmt308 }
	| n1:BREAK n2:';'
	  { fmt309 }
	| n1:RETURN n2:expression_opt n3:';'
	  { fmt310 }
	;
