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

program : list
    ;

list: dec ';' list
    | func list
    |
    ;

dec: type TK_IDENTIFIER '(' literal ')'
    | type TK_IDENTIFIER '[' LIT_INTEGER ']' init
    ;

func: type TK_IDENTIFIER '(' param ')' body
    ;

type: KW_INT
    | KW_FLOAT
    | KW_CHAR
    ;

init: literal init
    |
    ;

literal: LIT_INTEGER
    | LIT_FLOAT
    | LIT_CHAR
    ;

body: '{' cmd cmdl '}'
    ;

cmdl: ';' cmd cmdl
    |
    ;

cmd: '{' cmd cmdl '}'
    | TK_IDENTIFIER ASSIGNMENT LIT_INTEGER
    | TK_IDENTIFIER ASSIGNMENT TK_IDENTIFIER '(' args ')'
    | TK_IDENTIFIER ASSIGNMENT expr
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr
    | KW_READ TK_IDENTIFIER read
    | KW_PRINT printl
    | KW_RETURN expr
    | flux
    |
    ;

args: TK_IDENTIFIER args
    | LIT_CHAR args
    | LIT_INTEGER args
    | LIT_FLOAT args
    |
    ;

flux:   KW_IF '(' expr ')' cmd
    |   KW_IF '(' expr ')' cmd KW_ELSE cmd
    |   KW_WHILE '(' expr ')' body
    ;

read: '[' expr ']'
    |
    ;


printl: print printl
    |
    ;


print: LIT_STRING
    | expr
    ;


param: type TK_IDENTIFIER param
    |
    ;

expr: LIT_INTEGER
    | LIT_FLOAT
    | LIT_CHAR
    | TK_IDENTIFIER '[' expr ']'
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


%%


int yyerror(){
    fprintf(stderr, " \n Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
