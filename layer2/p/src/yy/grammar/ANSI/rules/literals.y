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

string_literal
	: token:STRING_LITERAL
	  { string_literal }
	;

type_qualifier
	: const:CONST
	  { const_type_qualifier }
	| volatile:VOLATILE
	  { volatile_type_qualifier }
	;

pointer_type_qualifier
	: const:CONST
	  { const_type_qualifier }
	| volatile:VOLATILE
	  { volatile_type_qualifier }
	;

storage_class
	: typedef:TYPEDEF
	  { typedef_str_class_spec }
	| extern:EXTERN
	  { extern_str_class_spec }
	| static:STATIC
	  { static_str_class_spec }
	| auto:AUTO
	  { auto_str_class_spec }
	| register:REGISTER
	  { register_str_class_spec }
	;

basic_type_name
	: void:VOID
	  { void_type_spec }
	| char:CHAR
	  { char_type_spec }
	| wchar:WCHAR_T
	  { wchar_type_spec }
	| int:INT
	  { int_type_spec }
	| float:FLOAT
	  { float_type_spec }
	| double:DOUBLE
	  { double_type_spec }

	| signed:SIGNED
	  { signer_type_spec }
	| unsigned:UNSIGNED
	  { unsigned_type_spec }

	| short:SHORT
	  { short_type_spec }
	| long:LONG
	  { long_type_spec }
	;


identifier
	: token:IDENTIFIER
	  { identifier }
	;

any_word
	: :identifier
	| token:CONST
	  { identifier }
	;

typedef_name
	: token:IDENTIFIER
	  { typedef_name }
	;
