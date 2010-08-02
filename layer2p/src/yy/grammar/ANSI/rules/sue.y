%%
%%

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	  { new (fmt312) ($1, $2, $3, $4); }
	| struct_or_union identifier_or_typedef_name '{' struct_declaration_list '}'
	  { new (fmt313) ($1, $2, $3, $4, $5); }
	| struct_or_union identifier_or_typedef_name
	  { new (fmt314) ($1, $2); }
	| struct_or_union '{' '}'
	  { new (fmt315) ($1, $2, $3); }
	| struct_or_union identifier_or_typedef_name '{' '}'
	  { new (fmt316) ($1, $2, $3, $4); }
	;

struct_or_union
	: STRUCT
	  { new (fmt317) ($1); }
	| UNION
	  { new (fmt318) ($1); }
	;

struct_declaration_list
	: attributes_opt struct_declaration
	  { new (fmt319) ($1, $2); }
	| struct_declaration_list attributes_opt struct_declaration
	  { new (fmt320) ($1, $2, $3); }
	;

struct_declaration
	: struct_declaring_list ';'
	  { new (fmt321) ($1, $2); }
	| struct_default_declaring_list ';'
	  { new (fmt322) ($1, $2); }
	;

struct_default_declaring_list
	: type_qualifier_list struct_identifier_declarator
	  { new (fmt323) ($1, $2); }
	| struct_default_declaring_list ',' struct_identifier_declarator
	  { new (fmt324) ($1, $2, $3); }
	;

struct_declaring_list
	: type_specifier struct_declarator
	  { new (fmt325) ($1, $2); }
	| type_specifier_nosue attributes struct_declarator
	  { new (fmt326) ($1, $2, $3); }
	| struct_declaring_list ',' struct_declarator
	  { new (fmt327) ($1, $2, $3); }
	;


struct_declarator
	: declarator bit_field_size_opt attributes_opt
	  { new (fmt328) ($1, $2, $3); }
	;

struct_identifier_declarator
	: identifier_declarator bit_field_size_opt attributes_opt
	  { new (fmt329) ($1, $2, $3); }
	;

bit_field_size_opt
	: empty
	  { new (fmt330) ($1); }
	| bit_field_size
	  { new (fmt331) ($1); }
	;

bit_field_size
	: ':' constant_expression
	  { new (fmt332) ($1, $2); }
	;

enum_specifier
	: ENUM '{' enumerator_list comma_opt '}'
	  { new (fmt333) ($1, $2, $3, $4, $5); }
	| ENUM identifier_or_typedef_name '{' enumerator_list comma_opt '}'
	  { new (fmt334) ($1, $2, $3, $4, $5, $6); }
	| ENUM identifier_or_typedef_name
	  { new (fmt335) ($1, $2); }
	;

enumerator_list
	: identifier_or_typedef_name enumerator_value_opt
	  { new (fmt336) ($1, $2); }
	| enumerator_list ',' identifier_or_typedef_name enumerator_value_opt
	  { new (fmt337) ($1, $2, $3, $4); }
	;

enumerator_value_opt
	: empty
	  { new (fmt338) ($1); }
	| '=' constant_expression
	  { new (fmt339) ($1, $2); }
	;

comma_opt
	: empty
	  { new (fmt340) ($1); }
	| ','
	  { new (fmt341) ($1); }
	;
