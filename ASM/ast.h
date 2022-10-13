//
// Created by vitor on 31/07/2022.
//

#include <stdio.h>
#include <stdlib.h>
#ifndef UNTITLED_AST_H
#define UNTITLED_AST_H

#include "hash.h"
#define MAXFILHOS 4


#define AST_NOT 1
#define AST_OR 2
#define AST_AND 3
#define AST_OPDIF 4
#define AST_OPEQ 5
#define AST_OPGE 6 
#define AST_OPLE 7
#define AST_BIG 8
#define AST_LESS 9
#define AST_DIV 10
#define AST_MULT 11
#define AST_SUB 12
#define AST_ADD 13
#define AST_IDENT 14
#define AST_SYMBOL 15
#define AST_PARAM 16
#define AST_STR 17
#define AST_PRINTL 18
#define AST_WHILE 19
#define AST_IFELSE 20
#define AST_IF 21
#define AST_ARGS 22
#define AST_FASSIGN 23
#define AST_RETURN 24
#define AST_PRINT 25
#define AST_READ 26
#define AST_ASSIGN 27
#define AST_LCMD 28
#define AST_INIT 29
#define AST_FUNC 30
#define AST_DEC 31
#define AST_LIST 32
#define AST_INT 33
#define AST_FLOAT 34
#define AST_CHAR 35
#define AST_DECP 36
#define AST_CMD 37



typedef struct astnode{
    int type;
    int datatype;
    struct astnode* filho[MAXFILHOS];
    HASH_NODE* symbol;
} AST;

AST* astCreate(int type, HASH_NODE *symbol, AST* filho0, AST* filho1, AST* filho2, AST* filho3);
void astPrint(AST* node, int level);
void astUndo(AST* node, FILE* arq);

#endif //UNTITLED_AST_H
