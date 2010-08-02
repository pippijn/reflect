%%
%%

constant
	: FLOATING_CONSTANT
	  { new (fmt255) ($1); }
	| INTEGER_CONSTANT
	  { new (fmt256) ($1); }
	| OCTAL_CONSTANT
	  { new (fmt257) ($1); }
	| HEX_CONSTANT
	  { new (fmt258) ($1); }
	| CHAR_CONSTANT
	  { new (fmt259) ($1); }
	| WCHAR_CONSTANT
	  { new (fmt260) ($1); }
	;

string_literal_list
	: STRING_LITERAL
	  { new (fmt261) ($1); }
	| string_literal_list STRING_LITERAL
	  { new (fmt262) ($1, $2); }
	;

type_qualifier
	: CONST
	  { new (fmt263) ($1); }
	| VOLATILE
	  { new (fmt264) ($1); }
	;

pointer_type_qualifier
	: CONST
	  { new (fmt265) ($1); }
	| VOLATILE
	  { new (fmt266) ($1); }
	;

storage_class
	: TYPEDEF
	  { new (fmt267) ($1); }
	| EXTERN
	  { new (fmt268) ($1); }
	| STATIC
	  { new (fmt269) ($1); }
	| AUTO
	  { new (fmt270) ($1); }
	| REGISTER
	  { new (fmt271) ($1); }
	;

basic_type_name
	: VOID
	  { new (fmt272) ($1); }
	| CHAR
	  { new (fmt273) ($1); }
	| WCHAR_T
	  { new (fmt274) ($1); }
	| INT
	  { new (fmt275) ($1); }
	| FLOAT
	  { new (fmt276) ($1); }
	| DOUBLE
	  { new (fmt277) ($1); }

	| SIGNED
	  { new (fmt278) ($1); }
	| UNSIGNED
	  { new (fmt279) ($1); }

	| SHORT
	  { new (fmt280) ($1); }
	| LONG
	  { new (fmt281) ($1); }
	;
