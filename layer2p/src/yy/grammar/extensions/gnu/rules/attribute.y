%%
%%

attributes_opt
	: n1:empty
	  { fmt368 }
	| n1:attributes
	  { fmt369 }
	;

attributes
	: n1:attribute
	  { fmt370 }
	| n1:attributes n2:attribute
	  { fmt371 }
	;

attribute
	: attribute_tok:ATTRIBUTE lbrack1:'(' lbrack2:'(' attributes:attribute_list rbrack1:')' rbrack2:')'
	  { attribute }
	;

attribute_list
	: n1:attrib
	  { fmt373 }
	| n1:attribute_list n2:',' n3:attrib
	  { fmt374 }
	;

attrib
	: n1:empty
	  { fmt375 }
	| name:any_word
	  { attrib }
	| name:any_word lbrack:'(' id:IDENTIFIER                                        rbrack:')'
	  { attrib }
	| name:any_word lbrack:'(' id:IDENTIFIER comma:',' expr:nonnull_expression_list rbrack:')'
	  { attrib }
	| name:any_word lbrack:'('                         expr:nonnull_expression_list rbrack:')'
	  { attrib }
	;
