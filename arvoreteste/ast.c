#include <stdio.h>
#include "ast.h"

AST* astCreate(int type, HASH_NODE *symbol, AST*filho0, AST*filho1, AST*filho2, AST*filho3){
	AST*newnode;
	newnode = (AST*) calloc(1,sizeof(AST));
	newnode ->type = type;
	newnode->symbol = symbol;
	newnode->filho[0] = filho0;
	newnode->filho[1] = filho1;
	newnode->filho[2] = filho2;
	newnode->filho[3] = filho3;
	return newnode;
}

void astPrint (AST* node, int level) {
    int i;
    if(!node)
        return;
    for (i=0; i<level; ++i){
        fprintf(stderr, "	");
    }
    fprintf(stderr,"AST ");
    switch (node->type) {

       case AST_NOT:
            fprintf(stderr,"AST_NOT ");
            break;

       case AST_OR:
            fprintf(stderr,"AST_OR ");
            break;

       case AST_AND:
            fprintf(stderr,"AST_AND ");
            break;

       case AST_OPDIF:
            fprintf(stderr,"AST_OPDIF ");
            break;

       case AST_OPEQ:
            fprintf(stderr,"AST_OPEQ ");
            break;

       case AST_OPLE:
            fprintf(stderr,"AST_OPLE ");
            break;

       case AST_OPGE:
            fprintf(stderr,"AST_OPGE ");
            break;

       case AST_BIG:
            fprintf(stderr,"AST_BIG ");
            break;

       case AST_LESS:
            fprintf(stderr,"AST_LESS ");
            break;

       case AST_DIV:
            fprintf(stderr,"AST_DIV ");
            break;

       case AST_MULT:
            fprintf(stderr,"AST_MULT ");
            break;

       case AST_SUB:
            fprintf(stderr,"AST_SUB ");
            break;

       case AST_ADD:
            fprintf(stderr,"AST_ADD ");
            break;

       case AST_IDENT:
            fprintf(stderr,"AST_IDENT ");
            break;

       case AST_SYMBOL:
            fprintf(stderr,"AST_SYMBOL ");
            break;

       case AST_PARAM:
            fprintf(stderr,"AST_PARAM ");
            break;

       case AST_STR:
            fprintf(stderr,"AST_STR ");
            break;

       case AST_PRINTL:
            fprintf(stderr,"AST_PRINTL ");
            break;

       case AST_WHILE:
            fprintf(stderr,"AST_WHILE ");
            break;

       case AST_IFELSE:
            fprintf(stderr,"AST_IFELSE ");
            break;

       case AST_IF:
            fprintf(stderr,"AST_IF ");
            break;

       case AST_ARGS:
            fprintf(stderr,"AST_ARGS ");
            break;

       case AST_FASSIGN:
            fprintf(stderr,"AST_FASSIGN ");
            break;

       case AST_RETURN:
            fprintf(stderr,"AST_RETURN ");
            break;

       case AST_PRINT:
            fprintf(stderr,"AST_PRINT ");
            break;

       case AST_READ:
            fprintf(stderr,"AST_READ ");
            break;

       case AST_ASSIGN:
            fprintf(stderr,"AST_ASSIGN ");
            break;

       case AST_LCMD:
            fprintf(stderr,"AST_LCMD ");
            break;

       case AST_INIT:
            fprintf(stderr,"AST_INIT ");
            break;

       case AST_FUNC:
            fprintf(stderr,"AST_FUNC ");
            break;

       case AST_DEC:
            fprintf(stderr,"AST_DEC ");
            break;

	  case AST_DECP:
            fprintf(stderr,"AST_DECP ");
            break;

       case AST_LIST:
            fprintf(stderr,"AST_LIST ");
            break;

       case AST_INT:
            fprintf(stderr,"AST_INT ");
            break;

       case AST_FLOAT:
            fprintf(stderr,"AST_FLOAT ");
            break;

       case AST_CHAR:
            fprintf(stderr,"AST_CHAR ");
            break;

		
       default:
            fprintf(stderr, "DESCONHECIDO ");
            break;
    }
    if (node->symbol)
        fprintf(stderr,"%s\n", node->symbol->text);
    else
        fprintf(stderr, ", 0\n");

    // imprimir filhos
    for (i=0; i<MAXFILHOS; ++i)
        astPrint(node->filho[i],level+1);

}

void astUndo (AST* node, FILE* arq){
	
	if(!node)
        return;
	
	switch (node->type) {

       case AST_NOT:
		   astUndo(node->filho[0],arq);
            fprintf(arq," ~ ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_OR:
		   astUndo(node->filho[0],arq);
            fprintf(arq," | ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_AND:
		   astUndo(node->filho[0],arq);
            fprintf(arq," & ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_OPDIF:
		   astUndo(node->filho[0],arq);
            fprintf(arq," != ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_OPEQ:
		   astUndo(node->filho[0],arq);
            fprintf(arq," == ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_OPLE:
		   astUndo(node->filho[0],arq);
            fprintf(arq," <= ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_OPGE:
		   astUndo(node->filho[0],arq);
            fprintf(arq," >= ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_BIG:
		   astUndo(node->filho[0],arq);
            fprintf(arq," > ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_LESS:
		   astUndo(node->filho[0],arq);
            fprintf(arq," < ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_DIV:
		   astUndo(node->filho[0],arq);
            fprintf(arq," / ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_MULT:
		   astUndo(node->filho[0],arq);
            fprintf(arq," . ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_SUB:
		   astUndo(node->filho[0],arq);
            fprintf(arq," - ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_ADD:
		   astUndo(node->filho[0],arq);
            fprintf(arq," + ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_IDENT:
            fprintf(arq," %s ", node->symbol->text);
		   if(node->filho[0]){
        			fprintf(arq,"[");
				astUndo(node->filho[0],arq);
				fprintf(arq,"]");
			}

            break;

       case AST_SYMBOL:
            fprintf(arq," %s ", node->symbol->text);
            break;

       case AST_PARAM:
		   astUndo(node->filho[0],arq);
            fprintf(arq," %s ", node->symbol->text);
		   astUndo(node->filho[1],arq);

            break;

       case AST_STR:
            fprintf(arq," %s ", node->symbol->text);
            break;

       case AST_PRINTL:
            astUndo(node->filho[0],arq);
		   astUndo(node->filho[1],arq);
            break;

       case AST_WHILE:
            fprintf(arq," WHILE ");
        	   fprintf(arq,"(");
		   astUndo(node->filho[0],arq);
        	   fprintf(arq,")");
		   fprintf(arq,"{");
		   astUndo(node->filho[1],arq);
		   fprintf(arq,"}");
            break;

       case AST_IFELSE:
            fprintf(arq,"AST_IFELSE ");
            break;

       case AST_IF:
            fprintf(arq," IF ");
		   fprintf(arq,"(");
		   astUndo(node->filho[0],arq);
        	   fprintf(arq,")");
		   fprintf(arq,"{");
		   astUndo(node->filho[1],arq);
		   fprintf(arq,"}");
            break;

       case AST_ARGS:
            astUndo(node->filho[0],arq);
		   astUndo(node->filho[1],arq);
            break;

       case AST_FASSIGN:
            fprintf(arq," %s ", node->symbol->text);
		   fprintf(arq,"(");
		   astUndo(node->filho[0],arq);
        	   fprintf(arq,")");

            break;

       case AST_RETURN:
            fprintf(arq," return ");
		   astUndo(node->filho[0],arq);

            break;

       case AST_PRINT:
            fprintf(arq," print ");
		   astUndo(node->filho[0],arq);

            break;

       case AST_READ:
            fprintf(arq," read ");
		   astUndo(node->filho[0],arq);

            break;

       case AST_ASSIGN:
             fprintf(arq," %s ", node->symbol->text);
		    if(node->filho[1],arq){
        			fprintf(arq,"[");
				astUndo(node->filho[0],arq);
				fprintf(arq,"]");
				fprintf(arq,"<-");
				astUndo(node->filho[1],arq);
			}
			else{
			fprintf(arq,"<-");
			astUndo(node->filho[0],arq);
			}

			
            break;

       case AST_LCMD:
		   astUndo(node->filho[0],arq);
            fprintf(arq,"; ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_INIT:
		   if (node->symbol)
        			fprintf(arq,"[%s]\n", node->symbol->text);
            
		   astUndo(node->filho[0],arq);
		   astUndo(node->filho[1],arq);

            break;

       case AST_FUNC:
            astUndo(node->filho[0],arq);
            fprintf(arq," %s ", node->symbol->text);
		   fprintf(arq,"(");
		   astUndo(node->filho[1],arq);
		   fprintf(arq,")");
		   fprintf(arq,"{");
		   astUndo(node->filho[2],arq);
		   fprintf(arq,"}");
            break;

       case AST_DEC:
		   astUndo(node->filho[0],arq);
            fprintf(arq," %s ", node->symbol->text);
		   astUndo(node->filho[1],arq);
            break;

       case AST_DECP:
		   astUndo(node->filho[0],arq);
            fprintf(arq," %s ", node->symbol->text);
		   fprintf(arq,"(");
		   astUndo(node->filho[1],arq);
		   fprintf(arq,")");
            break;
	
       case AST_LIST:
            astUndo(node->filho[0],arq);
		   fprintf(arq,"; ");
		   astUndo(node->filho[1],arq);
            break;

       case AST_INT:
            fprintf(arq," int ");
            break;

       case AST_FLOAT:
            fprintf(arq," float ");
            break;

       case AST_CHAR:
            fprintf(arq," char ");
            break;

		
       default:
            fprintf(arq, "DESCONHECIDO ");
            break;
    }



}