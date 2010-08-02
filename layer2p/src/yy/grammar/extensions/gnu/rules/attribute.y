%%
%%

attributes_opt
	: empty
	  { new (fmt368) ($1); }
	| attributes
	  { new (fmt369) ($1); }
	;

attributes
	: attribute
	  { new (fmt370) ($1); }
	| attributes attribute
	  { new (fmt371) ($1, $2); }
	;

attribute
	: ATTRIBUTE '(' '(' attribute_list ')' ')'
	  { new (fmt372) ($1, $2, $3, $4, $5, $6); }
	;

attribute_list
	: attrib
	  { new (fmt373) ($1); }
	| attribute_list ',' attrib
	  { new (fmt374) ($1, $2, $3); }
	;

attrib
	: empty
	  { new (fmt375) ($1); }
	| any_word
	  { new (fmt376) ($1); }
	| any_word '(' IDENTIFIER ')'
	  { new (fmt377) ($1, $2, $3, $4); }
	| any_word '(' IDENTIFIER ',' nonnull_expression_list ')'
	  { new (fmt378) ($1, $2, $3, $4, $5, $6); }
	| any_word '(' nonnull_expression_list ')'
	  { new (fmt379) ($1, $2, $3, $4); }
	;
