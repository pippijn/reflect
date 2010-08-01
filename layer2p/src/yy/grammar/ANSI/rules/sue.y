%%
%%

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	  { $$ = pt_fmt312_new ($1, $2, $3, $4); }
	| struct_or_union identifier_or_typedef_name '{' struct_declaration_list '}'
	  { $$ = pt_fmt313_new ($1, $2, $3, $4, $5); }
	| struct_or_union identifier_or_typedef_name
	  { $$ = pt_fmt314_new ($1, $2); }
	| struct_or_union '{' '}'
	  { $$ = pt_fmt315_new ($1, $2, $3); }
	| struct_or_union identifier_or_typedef_name '{' '}'
	  { $$ = pt_fmt316_new ($1, $2, $3, $4); }
	;

struct_or_union
	: STRUCT
	  { $$ = pt_fmt317_new ($1); }
	| UNION
	  { $$ = pt_fmt318_new ($1); }
	;

struct_declaration_list
	: attributes_opt struct_declaration
	  { $$ = pt_fmt319_new ($1, $2); }
	| struct_declaration_list attributes_opt struct_declaration
	  { $$ = pt_fmt320_new ($1, $2, $3); }
	;

struct_declaration
	: struct_declaring_list ';'
	  { $$ = pt_fmt321_new ($1, $2); }
	| struct_default_declaring_list ';'
	  { $$ = pt_fmt322_new ($1, $2); }
	;

struct_default_declaring_list
	: type_qualifier_list struct_identifier_declarator
	  { $$ = pt_fmt323_new ($1, $2); }
	| struct_default_declaring_list ',' struct_identifier_declarator
	  { $$ = pt_fmt324_new ($1, $2, $3); }
	;

struct_declaring_list
	: type_specifier struct_declarator
	  { $$ = pt_fmt325_new ($1, $2); }
	| type_specifier_nosue attributes struct_declarator
	  { $$ = pt_fmt326_new ($1, $2, $3); }
	| struct_declaring_list ',' struct_declarator
	  { $$ = pt_fmt327_new ($1, $2, $3); }
	;


struct_declarator
	: declarator bit_field_size_opt attributes_opt
	  { $$ = pt_fmt328_new ($1, $2, $3); }
	;

struct_identifier_declarator
	: identifier_declarator bit_field_size_opt attributes_opt
	  { $$ = pt_fmt329_new ($1, $2, $3); }
	;

bit_field_size_opt
	: empty
	  { $$ = pt_fmt330_new ($1); }
	| bit_field_size
	  { $$ = pt_fmt331_new ($1); }
	;

bit_field_size
	: ':' constant_expression
	  { $$ = pt_fmt332_new ($1, $2); }
	;

enum_specifier
	: ENUM '{' enumerator_list comma_opt '}'
	  { $$ = pt_fmt333_new ($1, $2, $3, $4, $5); }
	| ENUM identifier_or_typedef_name '{' enumerator_list comma_opt '}'
	  { $$ = pt_fmt334_new ($1, $2, $3, $4, $5, $6); }
	| ENUM identifier_or_typedef_name
	  { $$ = pt_fmt335_new ($1, $2); }
	;

enumerator_list
	: identifier_or_typedef_name enumerator_value_opt
	  { $$ = pt_fmt336_new ($1, $2); }
	| enumerator_list ',' identifier_or_typedef_name enumerator_value_opt
	  { $$ = pt_fmt337_new ($1, $2, $3, $4); }
	;

enumerator_value_opt
	: empty
	  { $$ = pt_fmt338_new ($1); }
	| '=' constant_expression
	  { $$ = pt_fmt339_new ($1, $2); }
	;

comma_opt
	: empty
	  { $$ = pt_fmt340_new ($1); }
	| ','
	  { $$ = pt_fmt341_new ($1); }
	;
