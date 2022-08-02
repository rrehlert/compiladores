/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/
#include <stdio.h>
#include "hash.h"



extern FILE *yyin;
int yyparse();


int isRunning(void);
int main(int argc, char ** argv){
   	hashInit();
	if (argc < 2){
		fprintf(stderr, "Call: etapa2 fileName\n");
		exit(1);
	}
	yyin = fopen(argv[1],"r");
	if (yyin ==0){
		fprintf(stderr,"Cannot open file %s\n", argv[1]);
		exit(2);
	}
	int yytok;

	yyparse();

	hashPrint();
    return 0;
}

