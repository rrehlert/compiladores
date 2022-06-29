extern int isRunning;
int main(){
   	hashInit();
	int yytok = 0;
    	yytok = yylex();
    	while(isRunning){
      	printf("token number: %d\n", yytok);
        	yytok = yylex();
    	}
	hashPrint();
    return 0;
}

