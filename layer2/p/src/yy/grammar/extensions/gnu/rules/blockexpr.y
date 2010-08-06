%%
%%

primary_expression
	: lbrack:'(' lbrace:'{'                        stmts:statement_list rbrace:'}' rbrack:')'
	  { brace_expression }
	| lbrack:'(' lbrace:'{' decls:declaration_list stmts:statement_list rbrace:'}' rbrack:')'
	  { brace_expression }
	;
