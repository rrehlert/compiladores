%{
#include "tokens.h"
int lineNumber = 1;
int yytok = 0;

int getLineNumber(void){
    return lineNumber;
}


%}


%%

char         {return KW_CHAR;}
int          {return KW_INT;}
float        {return KW_FLOAT;}
if           {return KW_IF;}
else         {return KW_ELSE;}
while        {return KW_WHILE;}
read         {return KW_READ;}
print        {return KW_PRINT;}
return       {return KW_RETURN;}
"<-"         {return ASSIGNMENT;}
"<="         {return OPERATOR_LE;}
">="         {return OPERATOR_GE;}
"=="         {return OPERATOR_EQ;}
"!="         {return OPERATOR_DIF;}
"_"          {return TK_IDENTIFIER;}
[0-9]+       {return LIT_INTEGER;}
'.'          {return LIT_CHAR;}
[0-9]+,[0-9]+  {return LIT_FLOAT;}
\"(\\.|[^"])*\"   {return LIT_STRING;}
[ \t]        {}
[a-zA-Z]+    {stderr; (printf("texto normal\n"));}
"\n"         {lineNumber++;}
[-+\;\(\)\[\]\{\}./<>&|~]+            {stderr; (printf("especial\n"));}
.            {stderr; printf("Excuse me, what?\n");}


%%

int main(){
    yytok = yylex();
    while(yytok){
        printf("token number: %d\n", yytok);
        yytok = yylex();
    }
    return 0;
}


int yywrap(void){
    int x = 0;
    x = getLineNumber();
    printf("File has %d lines\n", x--);
    return 1;
}
