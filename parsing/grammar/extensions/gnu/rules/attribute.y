%%
%%

attributes_opt
	: empty
	  { $$ = pt_fmt368_new ($1); }
	| attributes
	  { $$ = pt_fmt369_new ($1); }
	;

attributes
	: attribute
	  { $$ = pt_fmt370_new ($1); }
	| attributes attribute
	  { $$ = pt_fmt371_new ($1, $2); }
	;

attribute
	: ATTRIBUTE '(' '(' attribute_list ')' ')'
	  { $$ = pt_fmt372_new ($1, $2, $3, $4, $5, $6); }
	;

attribute_list
	: attrib
	  { $$ = pt_fmt373_new ($1); }
	| attribute_list ',' attrib
	  { $$ = pt_fmt374_new ($1, $2, $3); }
	;

attrib
	: empty
	  { $$ = pt_fmt375_new ($1); }
	| any_word
	  { $$ = pt_fmt376_new ($1); }
	| any_word '(' IDENTIFIER ')'
	  { $$ = pt_fmt377_new ($1, $2, $3, $4); }
	| any_word '(' IDENTIFIER ',' nonnull_expression_list ')'
	  { $$ = pt_fmt378_new ($1, $2, $3, $4, $5, $6); }
	| any_word '(' nonnull_expression_list ')'
	  { $$ = pt_fmt379_new ($1, $2, $3, $4); }
	;
