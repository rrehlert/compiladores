#include "asm.h"

void printAsm(FILE *fout){
	int i;
	HASH_NODE *node;
	fprintf(fout,".LFE0:\n"
	"\t.size	main, .-main\n"
	"\t.ident	\"GCC: (GNU) 12.1.1 20220730\"\n"
	"\t.section	.note.GNU-stack,\"\",@progbits\n"
	"## DATA SECTION\n"
	"\t.section	.rodata\n\n");
	for (i=0;i<HASH_SIZE;i++)
		for (node=Table[i];node;node=node->next){
			if (node->type == SYMBOL_VARIABLE || node->type == SYMBOL_IDENTIFIER )
				fprintf(fout,"_%s:\t.long\t0\n",node->text);
		}
}
