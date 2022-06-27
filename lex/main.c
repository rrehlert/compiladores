extern int isRunning;
int main(){
    int yytok = 0;
    yytok = yylex();
    while(isRunning){
        printf("token number: %d\n", yytok);
        yytok = yylex();
    }
    return 0;
}

