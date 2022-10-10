#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1


#define TAC_ASSIGN 4
#define TAC_JFALSE 5
#define TAC_LABEL 6
#define TAC_JMP 7
#define TAC_OR 8
#define TAC_AND 9
#define TAC_OPDIF 10
#define TAC_OPEQ 11
#define TAC_OPGE 12 
#define TAC_OPLE 13
#define TAC_BIG 14
#define TAC_LESS 15
#define TAC_DIV 16
#define TAC_MULT 17
#define TAC_SUB 18
#define TAC_ADD 19
#define TAC_BEGINFUNC 20
#define TAC_ENDFUNC 21
#define TAC_PRINT 22



typedef struct tac_node
{
    int type;
    HASH_NODE * res;
    HASH_NODE * op1;
    HASH_NODE * op2;
    struct tac_node* prev;
    struct tac_node* next;
} TAC;

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tacPrint(TAC* tac);
void tacPrintBack(TAC* tac);
TAC* tacJoin(TAC* l1, TAC* l2);


// CODE GENERATION

TAC* generateCode(AST *node);

// ASM GENERATION
TAC * tacReverse(TAC *tac);
void generateAsm(TAC* first);





#endif
