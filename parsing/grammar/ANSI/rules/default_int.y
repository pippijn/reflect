%%
%%

type_name
	: type_qualifier_list /*DEFAULT_INT*/
	  { $$ = pt_fmt151_new ($1); }
	| type_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { $$ = pt_fmt152_new ($1, $2); }
	;

parameter_declaration
	: attributes_opt declaration_qualifier_list /*DEFAULT_INT*/
	  { $$ = pt_fmt153_new ($1, $2); }
	| attributes_opt declaration_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { $$ = pt_fmt154_new ($1, $2, $3); }
	| attributes_opt declaration_qualifier_list /*DEFAULT_INT*/ identifier_declarator
	  { $$ = pt_fmt155_new ($1, $2, $3); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/
	  { $$ = pt_fmt156_new ($1, $2); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/ abstract_declarator
	  { $$ = pt_fmt157_new ($1, $2, $3); }
	| attributes_opt type_qualifier_list /*DEFAULT_INT*/ identifier_declarator
	  { $$ = pt_fmt158_new ($1, $2, $3); }
	;
