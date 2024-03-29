/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/
%{
#include "ast.h"
#include "y.tab.h"

int lineNumber = 1;
int running = 1;

int getLineNumber(void){
    return lineNumber;
}
%}

%x COMMENTS

%%

char                        {return KW_CHAR;}
int                         {return KW_INT;}
float                       {return KW_FLOAT;}
if                          {return KW_IF;}
else                        {return KW_ELSE;}
while                       {return KW_WHILE;}
read                        {return KW_READ;}
print                       {return KW_PRINT;}
return                      {return KW_RETURN;}
"<-"                        {return ASSIGNMENT;}
"<="                        {return OPERATOR_LE;}
">="                        {return OPERATOR_GE;}
"=="                        {return OPERATOR_EQ;}
"!="                        {return OPERATOR_DIF;}
[_a-zA-Z]+                  {yylval.symbol = hashInsert(yytext,SYMBOL_IDENTIFIER);return TK_IDENTIFIER;}
[0-9]+                      {yylval.symbol = hashInsert(yytext,SYMBOL_INTEGER);return LIT_INTEGER;}
'.'                         {yylval.symbol = hashInsert(yytext,SYMBOL_CHAR);return LIT_CHAR;}
[0-9]+,[0-9]+               {yylval.symbol = hashInsert(yytext,SYMBOL_FLOAT);return LIT_FLOAT;}
\"(\\.|[^"])*\"             {yylval.symbol = hashInsert(yytext,SYMBOL_STRING);return LIT_STRING;}
[ \t]                       {}
"\n"                        {lineNumber++;}
[-+\;\(\)\[\]\{\}./<>&|~]   {return yytext[0];}
##(.)*                    {}
\\#                         {BEGIN COMMENTS;}
.                           {return TOKEN_ERROR;}
<COMMENTS>#\\               {BEGIN INITIAL;}
<COMMENTS>\n                {lineNumber++;}
<COMMENTS>.                 {}

%%

int isRunning(void){
    return running;
}

void initMe(void){
    hashInit();

}

int yywrap(void){
    int x = 0;
    running = 0;
    x = getLineNumber();
    printf("File has %d lines\n", x--);
    return 1;
}

