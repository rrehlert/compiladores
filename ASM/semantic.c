// tabela semantica Ricardo Ehlert e Vitor Camargo



#include "semantic.h"
#include <string.h>

int SemanticErrors = 0;




void set_nodes(AST *node){
	if(!node)
		return;
	for (int i=0; i<MAXFILHOS; ++i)
		set_nodes(node->filho[i]);

	switch (node->type){

		case AST_SYMBOL:
			node->datatype = node->symbol->type;
			break;

		case AST_IDENT:
			if(node->filho[0])
				if (node->filho[0]->datatype != DATATYPE_INT){
					fprintf(stderr, "Semantic ERROR: Vector expect int inside [] in line %d\n", node->lineNumber);
					++ SemanticErrors;
					}

			node->datatype = node->symbol->datatype;
			break;

		case AST_ADD:
		case AST_SUB:
		case AST_MULT:
		case AST_DIV:
			if (node->filho[0]->datatype == node->filho[1]->datatype)
				node->datatype = node->filho[0]->datatype;
			else{
				fprintf(stderr, "Semantic ERROR: Operators mismatch in line %d\n", node->lineNumber);
				++ SemanticErrors;
			}
			break;

		case AST_LESS:
		case AST_BIG:
		case AST_OPLE:
		case AST_OPGE:
		case AST_OPEQ:
		case AST_OPDIF:
		case AST_AND:
		case AST_OR:
		case AST_NOT:
			if (node->filho[0]->datatype == node->filho[1]->datatype)
				node->datatype = DATATYPE_BOOL;
			else{
				fprintf(stderr, "Semantic ERROR: Operators mismatch in line %d\n", node->lineNumber);
				++ SemanticErrors;
			}
			break;

		case AST_FASSIGN:
			node->datatype = node->symbol->datatype;
			break;
		case AST_ASSIGN:
			if ((!node->filho[1]) && (node->symbol->type == SYMBOL_VECTOR)){
				fprintf(stderr, "Semantic ERROR: Vector %s expect [int] in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}
			if (node->filho[1]){
				if (node->filho[1]->datatype != DATATYPE_INT){
					fprintf(stderr, "Semantic ERROR: Vector %s expect int inside [] in line %d\n", node->symbol->text, node->lineNumber);
					++ SemanticErrors;
				}

				if (node->symbol->datatype != node->filho[0]->datatype){
					fprintf(stderr, "Semantic ERROR: Trying to assign %s with the wrong type in line %d\n", node->symbol->text, node->lineNumber);
					++ SemanticErrors;
				}
			}
			if ((node->filho[1]) && (node->symbol->type != SYMBOL_VECTOR)){
				fprintf(stderr, "Semantic ERROR: Variable %s used with unexpected [int] in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}

			if (node->symbol->datatype != node->filho[0]->datatype){
				fprintf(stderr, "Semantic ERROR: Trying to assign %s with the wrong type in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
			}
			break;
		case AST_READ:
			break;
		case AST_PRINT:
			break;
		case AST_RETURN:
			break;
		case AST_IF:
		case AST_IFELSE:
		case AST_WHILE:
			if(node->filho[0]->datatype != DATATYPE_BOOL){
				fprintf(stderr, "Semantic ERROR: Flux expression must be type Bool in line %d\n",node->lineNumber);
				++ SemanticErrors;
			}
			break;

	}
}

void set_declaration(AST *node){

	if(!node)
    		return;

	switch (node->type){
		case AST_DEC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: variable %s already declared in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_VECTOR;
			node->symbol->datatype = get_datatype(node->filho[0]);
			AST *filho;
			if (node->filho[1]->filho[0]){
				filho = node->filho[1]->filho[0];
				while (filho){
					if (filho->filho[0]->symbol->type != node->symbol->datatype){
						fprintf(stderr, "Semantic ERROR: vector %s declared with wrong type in line %d\n", node->symbol->text, node->lineNumber);
					++ SemanticErrors;
					}
/*
					strcat(node->symbol->startValue,filho->filho[0]->symbol->text);
					fprintf(stderr, "%s\n",filho->filho[0]->symbol->text);
*/
					filho = filho->filho[1];
				}
			}
			break;
		case AST_DECP:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: variable %s already declared in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_VARIABLE;
			node->symbol->datatype = get_datatype(node->filho[0]);
			node->symbol->startValue = node->filho[1]->symbol->text;
			if (node->symbol->datatype != node->filho[1]->symbol->type){
				fprintf(stderr, "Semantic ERROR: variable %s declared with wrong type in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
			}
			break;
		case AST_FUNC:
			if (node->symbol->type != SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR: function %s already declared in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}
			node->symbol->type = SYMBOL_FUNCTION;
			node->symbol->datatype = get_datatype(node->filho[0]);
/*			if (node->filho[1]){
			AST* param;
			param = node->filho[1];
			while(param){
			if (filho->filho[0]->symbol->type != node->symbol->datatype){
						fprintf(stderr, "Semantic ERROR: vector %s declared with wrong type\n",node->symbol->text);
					++ SemanticErrors;
					}			
			param = param->filho[1];							
}
			
			}
*/			break;
		case AST_PARAM:
			if (node->symbol->type != SYMBOL_IDENTIFIER){	
				fprintf(stderr, "Semantic ERROR: variable %s already declared in line %d\n", node->symbol->text, node->lineNumber);
				++ SemanticErrors;
				}
			else{	
			node->symbol->type = SYMBOL_VARIABLE;
			node->symbol->datatype = get_datatype(node->filho[0]);
			node->datatype = node->symbol->type;
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

int get_errors(){
	return SemanticErrors;
}
