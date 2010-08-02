%%
%%

constant
	: n1:FLOATING_CONSTANT
	  { fmt255 }
	| n1:INTEGER_CONSTANT
	  { fmt256 }
	| n1:OCTAL_CONSTANT
	  { fmt257 }
	| n1:HEX_CONSTANT
	  { fmt258 }
	| n1:CHAR_CONSTANT
	  { fmt259 }
	| n1:WCHAR_CONSTANT
	  { fmt260 }
	;

string_literal_list
	: n1:STRING_LITERAL
	  { fmt261 }
	| n1:string_literal_list n2:STRING_LITERAL
	  { fmt262 }
	;

type_qualifier
	: n1:CONST
	  { fmt263 }
	| n1:VOLATILE
	  { fmt264 }
	;

pointer_type_qualifier
	: n1:CONST
	  { fmt265 }
	| n1:VOLATILE
	  { fmt266 }
	;

storage_class
	: n1:TYPEDEF
	  { fmt267 }
	| n1:EXTERN
	  { fmt268 }
	| n1:STATIC
	  { fmt269 }
	| n1:AUTO
	  { fmt270 }
	| n1:REGISTER
	  { fmt271 }
	;

basic_type_name
	: n1:VOID
	  { fmt272 }
	| n1:CHAR
	  { fmt273 }
	| n1:WCHAR_T
	  { fmt274 }
	| n1:INT
	  { fmt275 }
	| n1:FLOAT
	  { fmt276 }
	| n1:DOUBLE
	  { fmt277 }

	| n1:SIGNED
	  { fmt278 }
	| n1:UNSIGNED
	  { fmt279 }

	| n1:SHORT
	  { fmt280 }
	| n1:LONG
	  { fmt281 }
	;
