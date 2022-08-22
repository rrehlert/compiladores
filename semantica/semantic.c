// tabela semantica Ricardo Ehlert e Vitor Camargo


#include "semantic.h"


extern int SemanticErrors;

void set_declaration(AST *node){

	if(!node)
    		return;

	switch (node->type){
		case AST_DEC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: variable %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_VARIABLE;
			node->symbol->datatype = get_datatype(node->filho[0]);
			break;
		case AST_FUNC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: function %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_FUNCTION;
			node->symbol->datatype = get_datatype(node->filho[0]);
			break;
}
			

	for (int i=0; i<MAXFILHOS; ++i)
    		set_declaration(node->filho[i]);
}

void check_declaration(){
	SemanticErrors += hash_check_undeclared();
}


int get_datatype(AST* node){
	switch(node->type){
		case AST_INT: return DATATYPE_INT;
		case AST_FLOAT: return DATATYPE_FLOAT;
		case AST_CHAR: return DATATYPE_CHAR;
	}
}