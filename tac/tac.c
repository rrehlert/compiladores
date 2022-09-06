
#include "tac.h"

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2)
{
    TAC* newtac = 0;
    newtac = (TAC*) calloc(1,sizeof(TAC));
    newtac->type = type;
        newtac->res = res;
        newtac->op1 = op1;
        newtac->op2 = op2;
        newtac->prev = 0;
        newtac->next = 0;
        return newtac;
}
void tacPrint(TAC* tac){
    if(!tac) return;
    if(tac->type == TAC_SYMBOL) return;
    fprintf(stderr,"TAC(");
    switch(tac->type)
    {
        case TAC_SYMBOL:fprintf(stderr,"TAC_SYMBOL"); break;
        case TAC_ADD:fprintf(stderr,"TAC_ADD"); break;
        case TAC_SUB:fprintf(stderr,"TAC_SUB"); break;
        case TAC_ASSIGN:fprintf(stderr,"TAC_ASSIGN"); break;
        case TAC_JFALSE:fprintf(stderr,"TAC_JFALSE"); break;
        case TAC_LABEL:fprintf(stderr,"TAC_LABEL"); break;
        default:fprintf(stderr,"TAC_UNKNOWN"); break;
    }
fprintf(stderr,",%s", (tac->res)?tac->res->text:"0");
fprintf(stderr,",%s", (tac->op1)?tac->op1->text:"0");
fprintf(stderr,",%s", (tac->op2)?tac->op2->text:"0");
fprintf(stderr,");\n");

}

void tacPrintBack(TAC* tac){
    if (!tac)
        return;
    else
    {
        tacPrintBack(tac->prev);
        tacPrint(tac);
    }
}

TAC* tacJoin(TAC* l1, TAC* l2){
    TAC*join;
    if (!l1) return l2;
    if (!l2) return l1;
    for (join = l2; join->prev != 0; join = join->prev)
        ;
    join->prev = l1;
    return l2;
}

// CODE GENERATION

TAC* makeBinCode(int type,TAC* code0, TAC* code1){
    TAC* result = 0;
    result = tacJoin(tacJoin(code0,code1),tacCreate(type,makeTemp(),code0?code0->res:0,code1?code1->res:0));
    return result;
}

TAC* makeIf(TAC* code0, TAC* code1){
    TAC* jumptac = 0;
    TAC* labeltac = 0;
    HASH_NODE* newlabel = 0;
    newlabel = makeLabel();

    jumptac = tacCreate(TAC_JFALSE, newlabel, code0?code0->res:0, 0);
    jumptac->prev = code0;
    labeltac = tacCreate(TAC_LABEL, newlabel,0,0);
    labeltac->prev = code1;
    return tacJoin(jumptac,labeltac);
}

TAC* generateCode(AST *node){
    int i;
    TAC* result = 0;
    TAC* code[MAXFILHOS];

    if (!node)
        return 0;

    //PROCESSA FILHOS
    for (i=0;  i<MAXFILHOS; ++i)
        code[i] = generateCode(node->filho[i]);

    //PROCESSA O NODO
    switch(node->type)
    {
        case AST_SYMBOL: result = tacCreate(TAC_SYMBOL,node->symbol,0,0); break;
        case AST_ADD: result = makeBinCode(TAC_ADD, code[0], code[1]);
            break;
        case AST_ASSIGN: result = tacJoin(code[0],tacCreate(TAC_ASSIGN,node->symbol,code[0]?code[0]->res:0,code[1]?code[1]->res:0));
            break;
        case AST_IF: result = makeIf(code[0],code[1]); break;
        default: result = tacJoin(code[0],tacJoin(code[1],tacJoin(code[2],code[3])));
        break;
    }


    return result;

}






