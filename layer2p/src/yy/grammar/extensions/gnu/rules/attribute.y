%%
%%

attributes_opt
	: n1:empty
	  { attributes_opt368 }
	| n1:attributes
	  { attributes_opt369 }
	;

attributes
	: n1:attribute
	  { attributes370 }
	| n1:attributes n2:attribute
	  { attributes371 }
	;

attribute
	: attribute_tok:ATTRIBUTE lbrack1:'(' lbrack2:'(' attributes:attribute_list rbrack1:')' rbrack2:')'
	  { attribute }
	;

attribute_list
	: n1:attrib
	  { attribute_list373 }
	| n1:attribute_list n2:',' n3:attrib
	  { attribute_list374 }
	;

attrib
	: n1:empty
	  { attrib375 }
	| name:any_word
	  { attrib376 }
	| name:any_word lbrack:'(' id:IDENTIFIER                                        rbrack:')' %dprec 2
	  { attrib377 }
	| name:any_word lbrack:'(' id:IDENTIFIER comma:',' expr:nonnull_expression_list rbrack:')'
	  { attrib378 }
	| name:any_word lbrack:'('                         expr:nonnull_expression_list rbrack:')' %dprec 1
	  { attrib379 }
	;
