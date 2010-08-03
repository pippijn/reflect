%%

%token PTR_OP		"->"
%token INC_OP		"++"
%token DEC_OP		"--"
%token LSH_OP		"<<"
%token RSH_OP		">>"
%token LE_OP		"<="
%token GE_OP		">="
%token EQ_OP		"=="
%token NE_OP		"!="
%token AND_OP		"&&"
%token OR_OP		"||"
%token ELLIPSIS		"..."

%token MUL_ASSIGN	"*="
%token DIV_ASSIGN	"/="
%token MOD_ASSIGN	"%="
%token ADD_ASSIGN	"+="
%token SUB_ASSIGN	"-="
%token LSH_ASSIGN	"<<="
%token RSH_ASSIGN	">>="
%token AND_ASSIGN	"&="
%token XOR_ASSIGN	"^="
%token OR_ASSIGN	"|="

%right '?' ':'
%left "||"
%left "&&"
%left '|'
%left '^'
%left '&'
%left "==" "!="
%left '<' '>' "<=" ">="
%left "<<" ">>"
%left '+' '-'
%left '*' '/' '%'
