%%
%%

constant
	: n1:FLOATING_CONSTANT
	  { floating_constant }
	| n1:INTEGER_CONSTANT
	  { integer_constant }
	| n1:OCTAL_CONSTANT
	  { octal_constant }
	| n1:HEX_CONSTANT
	  { hex_constant }
	| n1:CHAR_CONSTANT
	  { char_constant }
	| n1:WCHAR_CONSTANT
	  { wchar_constant }
	;

string_literal_list
	:                          string:STRING_LITERAL
	  { string_literal_list }
	| prev:string_literal_list string:STRING_LITERAL
	  { string_literal_list }
	;

type_qualifier
	: n1:CONST
	  { const_type_qualifier }
	| n1:VOLATILE
	  { volatile_type_qualifier }
	;

type_qualifier_opt
	: n1:empty
	  { type_qualifier_opt270 }
	| n1:type_qualifier
	  { type_qualifier_opt271 }
	;

pointer_type_qualifier
	: n1:CONST
	  { const_pointer_type_qualifier }
	| n1:VOLATILE
	  { volatile_pointer_type_qualifier }
	;

storage_class
	: n1:TYPEDEF
	  { typedef_str_class_spec }
	| n1:EXTERN
	  { extern_str_class_spec }
	| n1:STATIC
	  { static_str_class_spec }
	| n1:AUTO
	  { auto_str_class_spec }
	| n1:REGISTER
	  { register_str_class_spec }
	;

basic_type_name
	: n1:VOID
	  { void_type_spec }
	| n1:CHAR
	  { char_type_spec }
	| n1:WCHAR_T
	  { wchar_type_spec }
	| n1:INT
	  { int_type_spec }
	| n1:FLOAT
	  { float_type_spec }
	| n1:DOUBLE
	  { double_type_spec }

	| n1:SIGNED
	  { signer_type_spec }
	| n1:UNSIGNED
	  { unsigned_type_spec }

	| n1:SHORT
	  { short_type_spec }
	| n1:LONG
	  { long_type_spec }
	;
