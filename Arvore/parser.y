%{

    #include "ast.h"

%}

%union
{
    HASH_NODE *symbol;
    AST* AST;

}




%token KW_CHAR
%token KW_INT
%token KW_FLOAT

%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token<symbol> ASSIGNMENT
%token<symbol> OPERATOR_LE
%token<symbol> OPERATOR_GE
%token<symbol> OPERATOR_EQ
%token<symbol> OPERATOR_DIF

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER
%token<symbol> LIT_FLOAT
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING

%token TOKEN_ERROR

%type<AST> expr
%type<AST> body
%type<AST> cmd
%type<AST> cmdl


%left '.' '&'
%left OPERATOR_LE OPERATOR_GE OPERATOR_DIF OPERATOR_EQ
%left '+' '-'
%left '*' '/'


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

body: '{' cmd cmdl '}' { astPrint($3, 0); }
    ;

cmdl: ';' cmd cmdl     { $$ = astCreate(AST_LCMD, 0, $2, $3, 0, 0); }
    |                  { $$ = 0; }
    ;

cmd: '{' cmd cmdl '}'       { $$ = astCreate(AST_LCMD, 0, $2, $3, 0, 0); }
    | TK_IDENTIFIER ASSIGNMENT LIT_INTEGER      { $$ = astCreate(AST_SYMBOL, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER ASSIGNMENT TK_IDENTIFIER '(' args ')'       { $$ = 0; }
    | TK_IDENTIFIER ASSIGNMENT expr         { $$ = 0; }
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr        { $$ = 0; }
    | KW_READ TK_IDENTIFIER read        { $$ = 0; }
    | KW_PRINT printl       { $$ = 0; }
    | KW_RETURN expr        { $$ = 0; }
    | flux                  { $$ = 0; }
    |                       { $$ = 0; }
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

expr: LIT_INTEGER           { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_FLOAT             { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_CHAR              { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']'    { $$ = 0; }
    | TK_IDENTIFIER                 { $$ = 0; }
    | expr '+' expr                 { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
    | expr '-' expr                 { $$ = 0; }
    | expr '.' expr                 { $$ = 0; }
    | expr '/' expr                 { $$ = 0; }
    | expr '<' expr                 { $$ = 0; }
    | expr '>' expr                 { $$ = 0; }
    | expr OPERATOR_LE expr
    | expr OPERATOR_GE expr
    | expr OPERATOR_EQ expr
    | expr OPERATOR_DIF expr
    | expr '&' expr
    | expr '|' expr
    | expr '~' expr
    | '(' expr ')'          { $$ = 0; }
    ;


%%


int yyerror(){
    fprintf(stderr, " \n Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
