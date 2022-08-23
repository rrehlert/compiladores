/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/

#define HASH_SIZE 997

#ifndef UNTITLED_HASH_H
#define UNTITLED_HASH_H

#define SYMBOL_IDENTIFIER 1
#define SYMBOL_INTEGER 2
#define SYMBOL_CHAR 2
#define SYMBOL_FLOAT 3
#define SYMBOL_STRING 4
#define SYMBOL_FUNCTION 5
#define SYMBOL_VARIABLE 6
#define SYMBOL_VECTOR 7

#define DATATYPE_INT 2
#define DATATYPE_FLOAT 3
#define DATATYPE_CHAR 2
#define DATATYPE_STRING 4
#define DATATYPE_BOOL 5

typedef struct hash_node{
int type;
int datatype;
char *text;
struct hash_node *next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE * hashInsert(char *text, int type);
void hashPrint(void);
HASH_NODE *hashFind(char *text);
int hash_check_undeclared(void);


#endif //UNTITLED_HASH_H	