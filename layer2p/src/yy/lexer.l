%{
#include "yy/lex_interf.h"

static size_t
sz (int length)
{
  assert (length > 0);
  return (size_t)length;
}

#define YY_USER_ACTION                                          \
  {                                                             \
    lexer_update_lloc (yylloc, yylineno, yycolumn, yyleng);     \
    if (*yytext == '\n')                                        \
      yycolumn = 1;                                             \
    else                                                        \
      yycolumn += yyleng;                                       \
  }

#define RETURN(TOK)                                             \
  {                                                             \
    *yylval = pt_token_new (yylloc, yytext, sz (yyleng), TOK);  \
    return TOK;                                                 \
  }
%}

%option bison-locations
%option reentrant
%option header-file="layer2p/src/yy/lexer.h"
%option yylineno
%option noyywrap nounput noinput

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%x COMMENT

%%
"/*"			{ BEGIN (COMMENT); }

"auto"			{ RETURN (AUTO); }
"break"			{ RETURN (BREAK); }
"case"			{ RETURN (CASE); }
"char"			{ RETURN (CHAR); }
"const"			{ RETURN (CONST); }
"continue"		{ RETURN (CONTINUE); }
"default"		{ RETURN (DEFAULT); }
"do"			{ RETURN (DO); }
"double"		{ RETURN (DOUBLE); }
"else"			{ RETURN (ELSE); }
"enum"			{ RETURN (ENUM); }
"extern"		{ RETURN (EXTERN); }
"float"			{ RETURN (FLOAT); }
"for"			{ RETURN (FOR); }
"goto"			{ RETURN (GOTO); }
"if"			{ RETURN (IF); }
"int"			{ RETURN (INT); }
"long"			{ RETURN (LONG); }
"register"		{ RETURN (REGISTER); }
"return"		{ RETURN (RETURN); }
"short"			{ RETURN (SHORT); }
"signed"		{ RETURN (SIGNED); }
"sizeof"		{ RETURN (SIZEOF); }
"static"		{ RETURN (STATIC); }
"struct"		{ RETURN (STRUCT); }
"switch"		{ RETURN (SWITCH); }
"typedef"		{ RETURN (TYPEDEF); }
"union"			{ RETURN (UNION); }
"unsigned"		{ RETURN (UNSIGNED); }
"void"			{ RETURN (VOID); }
"volatile"		{ RETURN (VOLATILE); }
"while"			{ RETURN (WHILE); }

{L}({L}|{D})*		{ RETURN (IDENTIFIER); }

0[xX]{H}+{IS}?		{ RETURN (HEX_CONSTANT); }
0{D}+{IS}?		{ RETURN (OCTAL_CONSTANT); }
{D}+{IS}?		{ RETURN (INTEGER_CONSTANT); }
'(\\.|[^\\'])+'	        { RETURN (CHAR_CONSTANT); }
L'(\\.|[^\\'])+'	{ RETURN (WCHAR_CONSTANT); }

{D}+{E}{FS}?		{ RETURN (FLOATING_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ RETURN (FLOATING_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ RETURN (FLOATING_CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ RETURN (STRING_LITERAL); }

"..."			{ RETURN (ELLIPSIS); }
">>="			{ RETURN (RSH_ASSIGN); }
"<<="			{ RETURN (LSH_ASSIGN); }
"+="			{ RETURN (ADD_ASSIGN); }
"-="			{ RETURN (SUB_ASSIGN); }
"*="			{ RETURN (MUL_ASSIGN); }
"/="			{ RETURN (DIV_ASSIGN); }
"%="			{ RETURN (MOD_ASSIGN); }
"&="			{ RETURN (AND_ASSIGN); }
"^="			{ RETURN (XOR_ASSIGN); }
"|="			{ RETURN (OR_ASSIGN); }
">>"			{ RETURN (RSH_OP); }
"<<"			{ RETURN (LSH_OP); }
"++"			{ RETURN (INC_OP); }
"--"			{ RETURN (DEC_OP); }
"->"			{ RETURN (PTR_OP); }
"&&"			{ RETURN (AND_OP); }
"||"			{ RETURN (OR_OP); }
"<="			{ RETURN (LE_OP); }
">="			{ RETURN (GE_OP); }
"=="			{ RETURN (EQ_OP); }
"!="			{ RETURN (NE_OP); }
";"			{ RETURN (';'); }
("{"|"<%")		{ RETURN ('{'); }
("}"|"%>")		{ RETURN ('}'); }
","			{ RETURN (','); }
":"			{ RETURN (':'); }
"="			{ RETURN ('='); }
"("			{ RETURN ('('); }
")"			{ RETURN (')'); }
("["|"<:")		{ RETURN ('['); }
("]"|":>")		{ RETURN (']'); }
"."			{ RETURN ('.'); }
"&"			{ RETURN ('&'); }
"!"			{ RETURN ('!'); }
"~"			{ RETURN ('~'); }
"-"			{ RETURN ('-'); }
"+"			{ RETURN ('+'); }
"*"			{ RETURN ('*'); }
"/"			{ RETURN ('/'); }
"%"			{ RETURN ('%'); }
"<"			{ RETURN ('<'); }
">"			{ RETURN ('>'); }
"^"			{ RETURN ('^'); }
"|"			{ RETURN ('|'); }
"?"			{ RETURN ('?'); }

[ \t\v\n\f]		{ }
.			{ /* ignore bad characters */ }

%%
