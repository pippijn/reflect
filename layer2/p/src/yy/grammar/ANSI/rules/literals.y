%%
%%

constant
	: token:FLOATING_CONSTANT
	  { floating_constant }
	| token:INTEGER_CONSTANT
	  { integer_constant }
	| token:OCTAL_CONSTANT
	  { octal_constant }
	| token:HEX_CONSTANT
	  { hex_constant }
	| token:CHAR_CONSTANT
	  { char_constant }
	| token:WCHAR_CONSTANT
	  { wchar_constant }
	;

string_literal_list
	:                          string:STRING_LITERAL
	  { string_literal_list }
	| prev:string_literal_list string:STRING_LITERAL
	  { string_literal_list }
	;

type_qualifier
	: const_tok:CONST
	  { const_type_qualifier }
	| volatile_tok:VOLATILE
	  { volatile_type_qualifier }
	;

type_qualifier_opt
	: n1:empty
	  { type_qualifier_opt270 }
	| n1:type_qualifier
	  { type_qualifier_opt271 }
	;

pointer_type_qualifier
	: const_tok:CONST
	  { const_type_qualifier }
	| volatile_tok:VOLATILE
	  { volatile_type_qualifier }
	;

storage_class
	: typedef_tok:TYPEDEF
	  { typedef_str_class_spec }
	| extern_tok:EXTERN
	  { extern_str_class_spec }
	| static_tok:STATIC
	  { static_str_class_spec }
	| auto_tok:AUTO
	  { auto_str_class_spec }
	| register_tok:REGISTER
	  { register_str_class_spec }
	;

basic_type_name
	: void_tok:VOID
	  { void_type_spec }
	| char_tok:CHAR
	  { char_type_spec }
	| wchar_tok:WCHAR_T
	  { wchar_type_spec }
	| int_tok:INT
	  { int_type_spec }
	| float_tok:FLOAT
	  { float_type_spec }
	| double_tok:DOUBLE
	  { double_type_spec }

	| signed_tok:SIGNED
	  { signer_type_spec }
	| unsigned_tok:UNSIGNED
	  { unsigned_type_spec }

	| short_tok:SHORT
	  { short_type_spec }
	| long_tok:LONG
	  { long_type_spec }
	;
