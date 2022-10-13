/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/

#include "semantic.h"
#include "tac.h"
#include <stdio.h>
#include <stdlib.h>

extern AST* return_node();
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
	
	
	AST* no = return_node();
	set_declaration(no);
	check_declaration();
	set_nodes(no);
	int x = get_errors();
	if (x>0)
		exit(4);
	astPrint(no,0);
	FILE *out;
	out=fopen(argv[2],"w");
	if (out==NULL)
		fprintf(stderr, "Não foi possivel gerar output.txt\n");
	astUndo(no,out);	
	hashPrint();
	TAC* code;
    code = generateCode(no);
    tacPrintBack(code);
    code = tacReverse(code);
    generateAsm(code);
    return 0;
}

