%{
#include <stdlib.h>
#include "ast.h"
#include "tac.h"
int yyerror();
int yylex();
int getLineNumber();

AST* raiz;
	

%}

%union
{
    HASH_NODE *symbol;
    AST* AST;

}


%token<symbol> KW_CHAR
%token<symbol> KW_INT
%token<symbol> KW_FLOAT

%token<symbol> KW_IF
%token<symbol> KW_ELSE
%token<symbol> KW_WHILE
%token<symbol> KW_READ
%token<symbol> KW_PRINT
%token<symbol> KW_RETURN

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
%type<AST> literal
%type<AST> program
%type<AST> list
%type<AST> dec
%type<AST> func
%type<AST> type
%type<AST> init
%type<AST> fassign
%type<AST> args
%type<AST> flux
%type<AST> read
%type<AST> printl
%type<AST> print
%type<AST> param
%type<AST> array



%left '&' '|' '~'
%left OPERATOR_DIF OPERATOR_EQ
%left OPERATOR_LE OPERATOR_GE '<' '>'
%left '+' '-'
%left '.' '/'


%%

program : list										{ raiz = $1;
                                                    TAC* code;
                                                    code = generateCode($1);
                                                    tacPrintBack(code);
                                                    code = tacReverse(code);
                                                    generateAsm(code);
                                                    }
    ;

list: dec ';' list									{ $$ = astCreate(AST_LIST, 0, $1, $3, 0, 0);}
    | func list										{ $$ = astCreate(AST_LIST, 0, $1, $2, 0, 0);}
    |												{ $$ = 0; }
    ;

dec: type TK_IDENTIFIER '(' literal ')'					{ $$ = astCreate(AST_DECP, $2, $1, $4, 0, 0);}
    | type TK_IDENTIFIER array							{ $$ = astCreate(AST_DEC, $2, $1, $3, 0, 0);}
    ;

func: type TK_IDENTIFIER '(' param ')' body 			{ $$ = astCreate(AST_FUNC, $2, $1, $4, $6, 0);}
    ;

type: KW_INT				{ $$ = astCreate(AST_INT, 0, 0, 0, 0, 0);}
    | KW_FLOAT			{ $$ = astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
    | KW_CHAR				{ $$ = astCreate(AST_CHAR, 0, 0, 0, 0, 0);}
    ;

array: '[' LIT_INTEGER ']' init		{ $$ = astCreate(AST_INIT,$2,$4,0,0,0);}
    ;

init: literal init				{ $$ = astCreate(AST_INIT,0,$1,$2,0,0); }
    |							{ $$ = 0; }
    ;

literal: LIT_INTEGER    { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_FLOAT         { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_CHAR          { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    ;

body:'{' cmd '}' 			{ $$ = astCreate(AST_CMD, 0, $2, 0, 0, 0);}
    |'{' cmd ';' cmdl'}' 	{ $$ = astCreate(AST_LCMD, 0, $2, $4, 0, 0);}
    	;

cmdl: cmd     				{ $$ = astCreate(AST_CMD, 0, $1, 0, 0, 0);}
	| cmd ';' cmdl  			{ $$ = astCreate(AST_LCMD, 0, $1, $3, 0, 0);}
	| cmd ';'    				{ $$ = astCreate(AST_CMD, 0, $1, 0, 0, 0);}
	;


cmd: '{' cmdl '}'       								{ $$ = astCreate(AST_CMD, 0, $2, 0, 0, 0); }
    | TK_IDENTIFIER ASSIGNMENT   fassign     			{ $$ = astCreate(AST_ASSIGN, $1, $3, 0, 0, 0);}
    | TK_IDENTIFIER ASSIGNMENT expr         			{ $$ = astCreate(AST_ASSIGN, $1, $3, 0, 0, 0);}
    | TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr        	{ $$ = astCreate(AST_ASSIGN, $1, $3, $6, 0, 0);}
    | KW_READ read        								{ $$ = astCreate(AST_READ,0, $2, 0, 0, 0); }
    | KW_PRINT printl       							{ $$ = astCreate(AST_PRINT,0, $2, 0, 0, 0);}
    | KW_RETURN expr        							{ $$ = astCreate(AST_RETURN,0, $2, 0, 0, 0);}
    | flux                  							{ $$ = $1; }
    |                 								{ $$ = 0; }    
	;

fassign: TK_IDENTIFIER '(' args ')'		{ $$ = astCreate(AST_FASSIGN, $1, $3, 0, 0, 0);}
	;

args: expr args						{ $$ = astCreate(AST_ARGS,0, $1, $2, 0, 0);}
    |								{ $$ = 0;}
    ;

flux:   KW_IF '(' expr ')' cmd				{$$ = astCreate(AST_IF, 0, $3, $5, 0, 0);}
    |   KW_IF '(' expr ')' cmd KW_ELSE cmd	{$$ = astCreate(AST_IFELSE, 0, $3, $5, $7, 0);}
    |   KW_WHILE '(' expr ')' cmd				{$$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0);}
    ;

read: TK_IDENTIFIER'[' expr ']'			{ $$ = astCreate(AST_IDENT, $1, $3, 0, 0, 0);}
    | TK_IDENTIFIER						{ $$ = astCreate(AST_IDENT, $1, 0, 0, 0, 0);}
    ;


printl: print printl			{ $$ = astCreate(AST_PRINTL, 0, $1, $2, 0, 0); }
    |						{$$ = 0; }
    ;


print: LIT_STRING				{ $$ = astCreate(AST_STR, $1, 0, 0, 0, 0); }
    | expr					{ $$ = $1;}
    ;


param: type TK_IDENTIFIER param 	{$$ = astCreate(AST_PARAM, $2, $1, $3, 0, 0);}
    |						{$$=0;}
    ;

expr: LIT_INTEGER           		{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_FLOAT             		{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | LIT_CHAR              		{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
    | TK_IDENTIFIER '[' expr ']'   { $$ = astCreate(AST_IDENT, $1, $3, 0, 0, 0); }
    | TK_IDENTIFIER                { $$ = astCreate(AST_IDENT, $1, 0, 0, 0, 0); }
    | expr '+' expr                { $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
    | expr '-' expr                { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
    | expr '.' expr                { $$ = astCreate(AST_MULT, 0, $1, $3, 0, 0); }
    | expr '/' expr                { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
    | expr '<' expr                { $$ = astCreate(AST_LESS, 0, $1, $3, 0, 0); }
    | expr '>' expr                { $$ = astCreate(AST_BIG, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LE expr		{ $$ = astCreate(AST_OPLE, 0, $1, $3, 0, 0); }	
    | expr OPERATOR_GE expr		{ $$ = astCreate(AST_OPGE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_EQ expr		{ $$ = astCreate(AST_OPEQ, 0, $1, $3, 0, 0); }
    | expr OPERATOR_DIF expr		{ $$ = astCreate(AST_OPDIF, 0, $1, $3, 0, 0); }
    | expr '&' expr				{ $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
    | expr '|' expr				{ $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
    | expr '~' expr				{ $$ = astCreate(AST_NOT, 0, $1, $3, 0, 0); }
    | '(' expr ')'          		{ $$ = $2; }
    ;


%%

AST* return_node(){
	return raiz;
}
 
int yyerror(){
    fprintf(stderr, " \n Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
