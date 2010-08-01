%%
%%

constant
	: FLOATING_CONSTANT
	  { $$ = pt_fmt255_new ($1); }
	| INTEGER_CONSTANT
	  { $$ = pt_fmt256_new ($1); }
	| OCTAL_CONSTANT
	  { $$ = pt_fmt257_new ($1); }
	| HEX_CONSTANT
	  { $$ = pt_fmt258_new ($1); }
	| CHAR_CONSTANT
	  { $$ = pt_fmt259_new ($1); }
	| WCHAR_CONSTANT
	  { $$ = pt_fmt260_new ($1); }
	;

string_literal_list
	: STRING_LITERAL
	  { $$ = pt_fmt261_new ($1); }
	| string_literal_list STRING_LITERAL
	  { $$ = pt_fmt262_new ($1, $2); }
	;

type_qualifier
	: CONST
	  { $$ = pt_fmt263_new ($1); }
	| VOLATILE
	  { $$ = pt_fmt264_new ($1); }
	;

pointer_type_qualifier
	: CONST
	  { $$ = pt_fmt265_new ($1); }
	| VOLATILE
	  { $$ = pt_fmt266_new ($1); }
	;

storage_class
	: TYPEDEF
	  { $$ = pt_fmt267_new ($1); }
	| EXTERN
	  { $$ = pt_fmt268_new ($1); }
	| STATIC
	  { $$ = pt_fmt269_new ($1); }
	| AUTO
	  { $$ = pt_fmt270_new ($1); }
	| REGISTER
	  { $$ = pt_fmt271_new ($1); }
	;

basic_type_name
	: VOID
	  { $$ = pt_fmt272_new ($1); }
	| CHAR
	  { $$ = pt_fmt273_new ($1); }
	| WCHAR_T
	  { $$ = pt_fmt274_new ($1); }
	| INT
	  { $$ = pt_fmt275_new ($1); }
	| FLOAT
	  { $$ = pt_fmt276_new ($1); }
	| DOUBLE
	  { $$ = pt_fmt277_new ($1); }

	| SIGNED
	  { $$ = pt_fmt278_new ($1); }
	| UNSIGNED
	  { $$ = pt_fmt279_new ($1); }

	| SHORT
	  { $$ = pt_fmt280_new ($1); }
	| LONG
	  { $$ = pt_fmt281_new ($1); }
	;
