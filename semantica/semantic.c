// tabela semantica Ricardo Ehlert e Vitor Camargo


#include "semantic.h"

int SemanticErrors = 0;

void set_declaration(AST *node){

	if(!node)
    		return;
	
	switch (node->type){
		case AST_DEC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: variable %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_VECTOR;
			node->symbol->datatype = get_datatype(node->filho[0]);
			AST *filho;
			if (node->filho[1]->filho[0]){
				filho = node->filho[1]->filho[0];
				while (filho){
					if (filho->filho[0]->symbol->type != node->symbol->datatype){
						fprintf(stderr, "Semantic ERROR: vector %s declared with wrong type\n",node->symbol->text);
					++ SemanticErrors;
					}

					filho = filho->filho[1];
				}
			}
			break;
		case AST_DECP:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: variable %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_VARIABLE;
			node->symbol->datatype = get_datatype(node->filho[0]);
			if (node->symbol->datatype != node->filho[1]->symbol->type){
				fprintf(stderr, "Semantic ERROR: variable %s declared with wrong type\n",node->symbol->text);
				++ SemanticErrors;
			}
			break;
		case AST_FUNC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: function %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_FUNCTION;
			node->symbol->datatype = get_datatype(node->filho[0]);
			break;
		case AST_ASSIGN:
			if (node->symbol->datatype != node->filho[0]->symbol->type){
				fprintf(stderr, "Semantic ERROR: Wrong type Assignement with variable %s\n",node->symbol->text);
				++ SemanticErrors;
			}
			break;
		case AST_FASSIGN:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: function %s already declared\n",node->symbol->text);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_FUNCTION;
			node->symbol->datatype = get_datatype(node->filho[0]);
			if (node->symbol->datatype != node->filho[0]->symbol->type){
				fprintf(stderr, "Semantic ERROR: variable %s declared with wrong type\n",node->symbol->text);
				++ SemanticErrors;
			}
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