%%
%%

type_qualifier
	: INLINE
	  { new (fmt344) ($1); }
	| RESTRICT
	  { new (fmt345) ($1); }
	| COMPLEX
	  { new (fmt346) ($1); }
	;

pointer_type_qualifier
	: RESTRICT
	  { new (fmt347) ($1); }
	;
