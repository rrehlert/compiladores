%{
#include "tokens.h"
int lineNumber = 1;
int yytok = 0;
int isRunning = 1;

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
"_"                         {return TK_IDENTIFIER;}
[0-9]+                      {printf("string: %s\n", yytext);return LIT_INTEGER;}
'.'                         {printf("string: %s\n", yytext);return LIT_CHAR;}
[0-9]+,[0-9]+               {printf("string: %s\n", yytext);return LIT_FLOAT;}
\"(\\.|[^"])*\"             {printf("string: %s\n", yytext);return LIT_STRING;}
[ \t]                       {}
"\n"                        {lineNumber++;}
[-+\;\(\)\[\]\{\}./<>&|~]+  {return yytext[0];}
##(.)*\n                    {}
\\#                         {BEGIN COMMENTS;}
.                           {return TOKEN_ERROR;}
<COMMENTS>#\\               {BEGIN INITIAL;}
<COMMENTS>\n                {lineNumber++;}
<COMMENTS>.                 {}

%%

int main(){
    yytok = yylex();
    while(isRunning){
        printf("token number: %d\n", yytok);
        yytok = yylex();
    }
    return 0;
}


int yywrap(void){
    int x = 0;
    isRunning = 0;
    x = getLineNumber();
    printf("File has %d lines\n", x--);
    return 1;
}
