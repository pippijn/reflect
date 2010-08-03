%%
%%

type_qualifier
	: n1:INLINE
	  { inline_type_qualifier }
	| n1:RESTRICT
	  { restrict_type_qualifier }
	| n1:COMPLEX
	  { complex_type_qualifier }
	;

pointer_type_qualifier
	: n1:RESTRICT
	  { restrict_pointer_type_qualifier }
	;
