/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 997
#ifndef HASH_H
#define HASH_H


typedef struct hash_node{
int type;
char *text;
struct hash_node *next;
} HASH_NODE;
extern HASH_NODE *Table[HASH_SIZE];
void hashInit(void);
int hashAddress(char *text);
HASH_NODE * hashInsert(char *text);
void hashPrint(void);
HASH_NODE *hashFind(char *text);

#endif
