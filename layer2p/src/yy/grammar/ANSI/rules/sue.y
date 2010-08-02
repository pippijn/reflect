%%
%%

struct_or_union_specifier
	: n1:struct_or_union n2:'{' n3:struct_declaration_list n4:'}'
	  { fmt312 }
	| n1:struct_or_union n2:identifier_or_typedef_name n3:'{' n4:struct_declaration_list n5:'}'
	  { fmt313 }
	| n1:struct_or_union n2:identifier_or_typedef_name
	  { fmt314 }
	| n1:struct_or_union n2:'{' n3:'}'
	  { fmt315 }
	| n1:struct_or_union n2:identifier_or_typedef_name n3:'{' n4:'}'
	  { fmt316 }
	;

struct_or_union
	: n1:STRUCT
	  { fmt317 }
	| n1:UNION
	  { fmt318 }
	;

struct_declaration_list
	: n1:attributes_opt n2:struct_declaration
	  { fmt319 }
	| n1:struct_declaration_list n2:attributes_opt n3:struct_declaration
	  { fmt320 }
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
	: n1:ENUM n2:'{' n3:enumerator_list n4:comma_opt n5:'}'
	  { fmt333 }
	| n1:ENUM n2:identifier_or_typedef_name n3:'{' n4:enumerator_list n5:comma_opt n6:'}'
	  { fmt334 }
	| n1:ENUM n2:identifier_or_typedef_name
	  { fmt335 }
	;

enumerator_list
	: n1:identifier_or_typedef_name n2:enumerator_value_opt
	  { fmt336 }
	| n1:enumerator_list n2:',' n3:identifier_or_typedef_name n4:enumerator_value_opt
	  { fmt337 }
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
