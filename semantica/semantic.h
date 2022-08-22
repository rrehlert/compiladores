// tabela semantica Ricardo Ehlert e Vitor Camargo

#ifndef UNTITLED_SEMANTIC_H
#define UNTITLED_SEMANTIC_H


#include "hash.h"
#include "ast.h"

int SemanticErrors = 0;

void set_declaration(AST *node);
void check_declaration();
int get_datatype(AST *node);

#endif //UNTITLED_SEMANTIC_H