// tabela semantica Ricardo Ehlert e Vitor Camargo

#ifndef UNTITLED_SEMANTIC_H
#define UNTITLED_SEMANTIC_H


#include "ast.h"

void set_declaration(AST *node);
void check_declaration();
void set_nodes(AST *node);
int get_datatype(AST *node);

#endif //UNTITLED_SEMANTIC_H