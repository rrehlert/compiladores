/*Ricardo Rodrigues Ehlert - 00313284
Vitor Camargo de Moura - 00315212*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

HASH_NODE *Table[HASH_SIZE];

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
int address;
HASH_NODE *node;
address = hashAddress(text);
for (node=Table[address];node;node=node->next)
	if (!strcmp(text,node->text))
		return node;
return 0;
}

HASH_NODE * hashInsert(char *text, int type)
{
int address;
HASH_NODE *newnode;
if ((newnode = hashFind(text)) != 0)
	return newnode;
address = hashAddress(text);
newnode = (HASH_NODE*) calloc(1,sizeof(HASH_NODE));
newnode->text = (char*) calloc (strlen(text)+1,sizeof(char));
strcpy(newnode->text,text);
newnode->type = type;
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
		printf("Table[%d] has %s of type %d and datatype %d\n",i,node->text,node->type,node->datatype);
}

int hash_check_undeclared(){
	int i;
	int undeclared =0;
	HASH_NODE *node;
	for (i=0; i<HASH_SIZE; ++i)
		for (node = Table[i];node; node = node->next)
			if(node->type == SYMBOL_IDENTIFIER){
				printf("SEMANTIC ERROR: %s UNDECLARED \n", node->text);
				++undeclared;
			}
return undeclared;
}

HASH_NODE* makeTemp(void)
{
	static int serial = 0;
	char buffer[256] = "";

	sprintf(buffer, "sPeRWeiRDfCk_Temp%d", serial++);
	return hashInsert(buffer, SYMBOL_VARIABLE);

}

HASH_NODE* makeLabel(void)
{
	static int serial = 0;
	char buffer[256] = "";

	sprintf(buffer, "sPeRWeiRDfCk_Label%d", serial++);
	return hashInsert(buffer, SYMBOL_LABEL);

}

void printAsm(FILE *fout){
	int i;
	HASH_NODE *node;
	fprintf(fout,".LFE0:\n"
	"\t.size	main, .-main\n"
	"\t.ident	\"GCC: (GNU) 12.1.1 20220730\"\n"
	"\t.section	.note.GNU-stack,\"\",@progbits\n"
	"## DATA SECTION\n"
	"\t.section	.rodata\n\n"
	"\t.data\n"	);
	for (i=0;i<HASH_SIZE;i++)
		for (node=Table[i];node;node=node->next){
			if (node->datatype != 0){
				if (node->type == SYMBOL_VARIABLE)
					fprintf(fout,"_%s:\t.long\t%s\n",node->text,node->startValue);
				if (node->type == SYMBOL_VECTOR)
					fprintf(fout,"_%s:\t.long\t0\n",node->text);
			}
			else
				switch(node->type){
					case SYMBOL_INTEGER:fprintf(fout,"_%s:\t.long\t%s\n",node->text,node->text);
									   break;

					 default: fprintf(fout,"_%s:\t.long\t0\n",node->text);
				}
		}
}
