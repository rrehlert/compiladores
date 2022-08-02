/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/

#define HASH_SIZE 997

#ifndef UNTITLED_HASH_H
#define UNTITLED_HASH_H





typedef struct hash_node{
int type;
char *text;
struct hash_node *next;
} HASH_NODE;
HASH_NODE *Table[HASH_SIZE];
void hashInit(void);
int hashAddress(char *text);
HASH_NODE * hashInsert(char *text);
void hashPrint(void);
HASH_NODE *hashFind(char *text);

#endif //UNTITLED_HASH_H