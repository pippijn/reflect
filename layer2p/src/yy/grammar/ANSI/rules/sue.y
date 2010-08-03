%%
%%

struct_or_union_specifier
	: sudcl:struct_or_union                               lbrace:'{'                                rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union                               lbrace:'{' fields:struct_declaration_list rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier_or_typedef_name
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier_or_typedef_name lbrace:'{'                                rbrace:'}'
	  { struct_or_union_specifier }
	| sudcl:struct_or_union id:identifier_or_typedef_name lbrace:'{' fields:struct_declaration_list rbrace:'}'
	  { struct_or_union_specifier }
	;

struct_or_union
	: n1:STRUCT
	  { fmt317 }
	| n1:UNION
	  { fmt318 }
	;

struct_declaration_list
	:                              attrs:attributes_opt decl:struct_declaration
	  { struct_declaration_list }
	| prev:struct_declaration_list attrs:attributes_opt decl:struct_declaration
	  { struct_declaration_list }
	;

struct_declaration
	: n1:struct_declaring_list n2:';'
	  { fmt321 }
	| n1:struct_default_declaring_list n2:';'
	  { fmt322 }
	;

struct_default_declaring_list
	: n1:type_qualifier_list n2:struct_identifier_declarator
	  { fmt323 }
	| n1:struct_default_declaring_list n2:',' n3:struct_identifier_declarator
	  { fmt324 }
	;

struct_declaring_list
	: n1:type_specifier n2:struct_declarator
	  { fmt325 }
	| n1:type_specifier_nosue n2:attributes n3:struct_declarator
	  { fmt326 }
	| n1:struct_declaring_list n2:',' n3:struct_declarator
	  { fmt327 }
	;


struct_declarator
	: n1:declarator n2:bit_field_size_opt n3:attributes_opt
	  { fmt328 }
	;

struct_identifier_declarator
	: n1:identifier_declarator n2:bit_field_size_opt n3:attributes_opt
	  { fmt329 }
	;

bit_field_size_opt
	: n1:empty
	  { fmt330 }
	| n1:bit_field_size
	  { fmt331 }
	;

bit_field_size
	: n1:':' n2:constant_expression
	  { fmt332 }
	;

enum_specifier
	: enum_tok:ENUM                                lbrace:'{' values:enumerator_list comma:comma_opt rbrace:'}'
	  { enum_specifier }
	| enum_tok:ENUM tag:identifier_or_typedef_name lbrace:'{' values:enumerator_list comma:comma_opt rbrace:'}'
	  { enum_specifier }
	| enum_tok:ENUM tag:identifier_or_typedef_name
	  { enum_specifier }
	;

enumerator_list
	:                                id:identifier_or_typedef_name value:enumerator_value_opt
	  { enumerator_list }
	| prev:enumerator_list comma:',' id:identifier_or_typedef_name value:enumerator_value_opt
	  { enumerator_list }
	;

enumerator_value_opt
	: n1:empty
	  { fmt338 }
	| n1:'=' n2:constant_expression
	  { fmt339 }
	;

comma_opt
	: n1:empty
	  { fmt340 }
	| n1:','
	  { fmt341 }
	;
