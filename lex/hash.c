
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void hashInit(void)
{
int i;
for(i=0;i<HASH_SIZE;i++)
	Table[i]=0;
}

int hashAddress(char *text)
{
int i;
int address=1;
for(i=0;i<strlen(text);i++)
	address = (address * text[i]) % HASH_SIZE +1;
return address-1;
}

HASH_NODE *hashFind(char *text){
int address=1;
HASH_NODE *node;
address = hashAddress(text);
for (node=Table[address];node;node=node->next)
	if (!strcmp(text,node->text))
		return node;
return 0;
}

HASH_NODE * hashInsert(char *text)
{
int address;
HASH_NODE *newnode;
address = hashAddress(text);
newnode = (HASH_NODE*) calloc(1,sizeof(HASH_NODE));
newnode->text = (char*) calloc (strlen(text)+1,sizeof(char));
strcpy(newnode->text,text);
newnode->next =0;
newnode->next = Table[address];
Table[address] = newnode;
return newnode;
}

void hashPrint(void){
int i;
HASH_NODE *node;
for (i=0;i<HASH_SIZE;i++)
	for (node=Table[i];node;node=node->next)
		printf("Table[%d] has %s",i,node->text);
}

