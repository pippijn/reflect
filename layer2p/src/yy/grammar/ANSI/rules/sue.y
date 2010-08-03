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
	: struct_tok:STRUCT
	  { struct }
	| union_tok:UNION
	  { union }
	;

struct_declaration_list
	:                              attrs:attributes_opt decl:struct_declaration
	  { struct_declaration_list }
	| prev:struct_declaration_list attrs:attributes_opt decl:struct_declaration
	  { struct_declaration_list }
	;

struct_declaration
	: n1:struct_declaring_list semi:';'
	  { struct_declaration321 }
	| n1:struct_default_declaring_list semi:';'
	  { struct_declaration322 }
	;

struct_default_declaring_list
	: n1:type_qualifier_list n2:struct_identifier_declarator
	  { struct_default_declaring_list323 }
	| n1:struct_default_declaring_list comma:',' n3:struct_identifier_declarator
	  { struct_default_declaring_list324 }
	;

struct_declaring_list
	: n1:type_specifier n2:struct_declarator
	  { struct_declaring_list325 }
	| n1:type_specifier_nosue n2:attributes n3:struct_declarator
	  { struct_declaring_list326 }
	| n1:struct_declaring_list comma:',' n3:struct_declarator
	  { struct_declaring_list327 }
	;


struct_declarator
	: decl:declarator bitfield:bit_field_size_opt attrs:attributes_opt
	  { struct_declarator }
	;

struct_identifier_declarator
	: decl:identifier_declarator bitfield:bit_field_size_opt attrs:attributes_opt
	  { struct_identifier_declarator }
	;

bit_field_size_opt
	: n1:empty
	  { bit_field_size_opt330 }
	| bitfield:bit_field_size
	  { bit_field_size_opt331 }
	;

bit_field_size
	: colon:':' expr:constant_expression
	  { bit_field_size }
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
	  { enumerator_value_opt338 }
	| equals:'=' expr:constant_expression
	  { enumerator_value_opt339 }
	;

comma_opt
	: n1:empty
	  { comma_opt340 }
	| comma:','
	  { comma_opt341 }
	;
