#include <stdio.h>
#include<stdlib.h>
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
        fprintf(stderr, " ");
    }
    fprintf(stderr,"AST ");
    switch (node->type) {
        case AST_SYMBOL:
            fprintf(stderr,"AST_SYMBOL ");
            break;
        case AST_ADD:
            fprintf(stderr,"AST_ADD ");
            break;
        case AST_LCMD:
            fprintf(stderr,"AST_LCMD ");
            break;
        case AST_ASSIGN:
            fprintf(stderr,"AST_ASSIGN ");
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
