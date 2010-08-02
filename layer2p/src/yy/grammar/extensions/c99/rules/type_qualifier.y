%%
%%

type_qualifier
	: n1:INLINE
	  { fmt344 }
	| n1:RESTRICT
	  { fmt345 }
	| n1:COMPLEX
	  { fmt346 }
	;

pointer_type_qualifier
	: n1:RESTRICT
	  { fmt347 }
	;
