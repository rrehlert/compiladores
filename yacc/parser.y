%token KW_CHAR
%token KW_INT
%token KW_FLOAT

%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token ASSIGNMENT
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_FLOAT
%token LIT_CHAR
%token LIT_STRING

%token TOKEN_ERROR


%%

program : decl
    ;

list: dec ';' list
    |
    ;


decl: dec ';' decl
    |
    ;

resto: ';' dec resto
    |
    ;

dec: KW_INT TK_IDENTIFIER '(' ')'
    ;
//    | type TK_IDENTIFIER '[' LIT_INTEGER ']' init
//    | KW_INT TK_IDENTIFIER '(' ')' '{' LIT_INTEGER '}'

/*
body: '{' cmdl '}'
    ;

type: KW_INT
    | KW_FLOAT
    | KW_CHAR
    ;

literal: LIT_INTEGER
    | LIT_FLOAT
    | LIT_CHAR
    ;

init: LIT_INTEGER init
    |
    ;

param: type TK_IDENTIFIER param
    |
    ;
    */
/*
cmdl: ';' cmd
    |
    ;

cmd: '{' cmd cmdl '}'
    | TK_IDENTIFIER ASSIGNMENT expr
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr
    | KW_READ TK_IDENTIFIER read
    | KW_PRINT printl
    | KW_RETURN expr
    | flux
    ;

read: '[' expr ']'
    |
    ;

printl: LIT_STRING print
    | expr print
    ;

print: printl
    |
    ;

expr: LIT_INTEGER
    | TK_IDENTIFIER
    | expr '+' expr
    | expr '-' expr
    | expr '.' expr
    | expr '/' expr
    | expr '<' expr
    | expr '>' expr
    | expr OPERATOR_LE expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_DIF expr
    | expr '&' expr
    | expr '|' expr
    | expr '~' expr
    | '(' expr ')'
    ;

flux:   KW_IF '(' expr ')' cmd
    |   KW_IF '(' expr ')' cmd KW_ELSE cmd
    |   KW_WHILE '(' expr ')' cmd
    ;
*/

%%


int yyerror(){
    fprintf(stderr, "Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
