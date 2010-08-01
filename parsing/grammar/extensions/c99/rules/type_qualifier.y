%%
%%

type_qualifier
	: INLINE
	  { $$ = pt_fmt344_new ($1); }
	| RESTRICT
	  { $$ = pt_fmt345_new ($1); }
	| COMPLEX
	  { $$ = pt_fmt346_new ($1); }
	;

pointer_type_qualifier
	: RESTRICT
	  { $$ = pt_fmt347_new ($1); }
	;
