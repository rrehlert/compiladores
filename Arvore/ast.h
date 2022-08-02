//
// Created by vitor on 31/07/2022.
//



#ifndef AST_HEADER
#define AST_HEADER
#include "hash.h"
#define MAXFILHOS 4
#define AST_SYMBOL 1

#define AST_ADD 2
#define AST_LCMD 3
#define AST_ASSIGN 5

typedef struct astnode{
    int type;
    struct astnode* filho[MAXFILHOS];
    HASH_NODE* symbol;
}AST;

AST* astCreate(int type, HASH_NODE *symbol, AST* filho0, AST* filho1, AST* filho2, AST* filho3);
void astPrint(AST* node, int level);
#endif
