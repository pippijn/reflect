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
	: n1:ATTRIBUTE n2:'(' n3:'(' n4:attribute_list n5:')' n6:')'
	  { fmt372 }
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
	| n1:any_word
	  { fmt376 }
	| n1:any_word n2:'(' n3:IDENTIFIER n4:')'
	  { fmt377 }
	| n1:any_word n2:'(' n3:IDENTIFIER n4:',' n5:nonnull_expression_list n6:')'
	  { fmt378 }
	| n1:any_word n2:'(' n3:nonnull_expression_list n4:')'
	  { fmt379 }
	;
