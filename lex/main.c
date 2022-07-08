/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/
int isRunning(void);
int main(){
   	hashInit();
	int yytok = 0;
    	yytok = yylex();
    	while(isRunning()){
      	printf("token number: %d\n", yytok);
        	yytok = yylex();
    	}
	hashPrint();
    return 0;
}

