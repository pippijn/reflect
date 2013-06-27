%%
%%

struct_or_union_specifier
	: sudcl:struct_or_union               lbrace:'{'                                rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union               lbrace:'{' fields:struct_declaration_list rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier lbrace:'{'                                rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier lbrace:'{' fields:struct_declaration_list rbrace:'}'
	  { struct_or_union_specifier }
	;

struct_or_union
	: struct_tok:STRUCT
	  { struct }
	| union_tok:UNION
	  { union }
	;

struct_declaration_list
	: decl:struct_declaration[attributes?]+
	  { struct_declaration_list }
	;

struct_declaration
	: declrs:struct_declaring_list semi:';'
	  { struct_declaration }
	| declrs:struct_default_declaring_list semi:';'
	  { struct_declaration }
	;

struct_default_declaring_list
	: squals:type_qualifier+ id:struct_identifier_declarator
	  { struct_default_declaring_list1 }
	| prev:struct_default_declaring_list sep:',' id:struct_identifier_declarator
	  { struct_default_declaring_list2 }
	;

struct_declaring_list
	: tspec:type_specifier                        declr:struct_declarator
	  { struct_declaring_list325 }
	| tspec:type_specifier_nosue attrs:attributes declr:struct_declarator
	  { struct_declaring_list325 }
	| prev:struct_declaring_list sep:',' declr:struct_declarator
	  { struct_declaring_list327 }
	;


struct_declarator
	: decl:declarator bitfield:bit_field_size? attrs:attributes?
	  { struct_declarator }
	;

struct_identifier_declarator
	: decl:identifier_declarator bitfield:bit_field_size? attrs:attributes?
	  { struct_identifier_declarator }
	;

bit_field_size
	: colon:':' expr:constant_expression
	  { bit_field_size }
	;

enum_specifier
	: enum_tok:ENUM                lbrace:'{' values:enumerator+ comma:comma_opt rbrace:'}'
	  { enum_specifier }
	| enum_tok:ENUM tag:identifier lbrace:'{' values:enumerator+ comma:comma_opt rbrace:'}'
	  { enum_specifier }
	| enum_tok:ENUM tag:identifier
	  { enum_specifier }
	;

enumerator
	: id:identifier value:enumerator_value?
	  { enumerator }
	;

enumerator_value
	: equals:'=' expr:constant_expression
	  { enumerator_value }
	;

comma_opt
	: :empty
	| comma:','
	;
