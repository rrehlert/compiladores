
#include "tac.h"

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2)
{
    TAC* newtac = 0;
    newtac = (TAC*) calloc(1,sizeof(TAC));
    newtac->type = type;
        newtac->res = res;
        newtac->op1 = op1;
        newtac->op2 = op2;
        newtac->prev = 0;
        newtac->next = 0;
        return newtac;
}
void tacPrint(TAC* tac){
    if(!tac) return;
    if(tac->type == TAC_SYMBOL) return;
    fprintf(stderr,"TAC(");
    switch(tac->type)
    {
        case TAC_SYMBOL:fprintf(stderr,"TAC_SYMBOL"); break;

        case TAC_ADD:fprintf(stderr,"TAC_ADD"); break;
        case TAC_SUB:fprintf(stderr,"TAC_SUB"); break;
	    case TAC_OR:fprintf(stderr,"TAC_OR"); break;
		case TAC_AND:fprintf(stderr,"TAC_AND"); break;
		case TAC_OPDIF:fprintf(stderr,"TAC_OPDIF"); break;
		case TAC_OPEQ:fprintf(stderr,"TAC_OPEQ"); break;
		case TAC_OPGE:fprintf(stderr,"TAC_OPGE"); break;
		case TAC_OPLE:fprintf(stderr,"TAC_OPLE"); break;
		case TAC_BIG:fprintf(stderr,"TAC_BIG"); break;
		case TAC_LESS:fprintf(stderr,"TAC_LESS"); break;
		case TAC_DIV:fprintf(stderr,"TAC_DIV"); break;
		case TAC_MULT:fprintf(stderr,"TAC_MULT"); break;

		case TAC_ASSIGN:fprintf(stderr,"TAC_ASSIGN"); break;
        case TAC_JFALSE:fprintf(stderr,"TAC_JFALSE"); break;
        case TAC_LABEL:fprintf(stderr,"TAC_LABEL"); break;
	    case TAC_JMP:fprintf(stderr,"TAC_JMP"); break;

		case TAC_BEGINFUNC: fprintf(stderr,"TAC_BEGINFUNC"); break;
		case TAC_ENDFUNC: fprintf(stderr,"TAC_ENDFUNC"); break;
		case TAC_PRINT: fprintf(stderr,"TAC_PRINT"); break;

        default:fprintf(stderr,"TAC_UNKNOWN"); break;
    }
fprintf(stderr,",%s", (tac->res)?tac->res->text:"0");
fprintf(stderr,",%s", (tac->op1)?tac->op1->text:"0");
fprintf(stderr,",%s", (tac->op2)?tac->op2->text:"0");
fprintf(stderr,");\n");

}

void tacPrintBack(TAC* tac){
    if (!tac)
        return;
    else
    {
        tacPrintBack(tac->prev);
        tacPrint(tac);
    }
}

TAC* tacJoin(TAC* l1, TAC* l2){
    TAC*join;
    if (!l1) return l2;
    if (!l2) return l1;
    for (join = l2; join->prev != 0; join = join->prev)
        ;
    join->prev = l1;
    return l2;
}

// CODE GENERATION

TAC* makeBinCode(int type,TAC* code0, TAC* code1){
    TAC* result = 0;
    result = tacJoin(tacJoin(code0,code1),tacCreate(type,makeTemp(),code0?code0->res:0,code1?code1->res:0));
    return result;
}

TAC* makeIf(TAC* code0, TAC* code1){
    TAC* jumptac = 0;
    TAC* labeltac = 0;
    HASH_NODE* newlabel = 0;
    newlabel = makeLabel();

    jumptac = tacCreate(TAC_JFALSE, newlabel, code0?code0->res:0, 0);
    jumptac->prev = code0;
    labeltac = tacCreate(TAC_LABEL, newlabel,0,0);
    labeltac->prev = code1;
    return tacJoin(jumptac,labeltac);
}

TAC* makeIfElse(TAC* code0, TAC* code1, TAC* code2){
    TAC* jumptac = 0;
    TAC* finallabeltac = 0;
    TAC* elselabeltac = 0;
	TAC* elsejumptac = 0;
    HASH_NODE* newlabel = 0;
    newlabel = makeLabel();
	HASH_NODE* newlabel2 = 0;
    newlabel2 = makeLabel();

    jumptac = tacCreate(TAC_JFALSE, newlabel, code0?code0->res:0, 0);
    jumptac->prev = code0;
	
	elsejumptac = tacCreate(TAC_JMP, newlabel2, 0, 0);
	elsejumptac->prev = code1;

	elselabeltac = tacCreate(TAC_LABEL, newlabel,0,0);
	elselabeltac->prev = elsejumptac;

    finallabeltac = tacCreate(TAC_LABEL, newlabel2,0,0);
    finallabeltac->prev = code2;

    return tacJoin(jumptac,tacJoin(elselabeltac,finallabeltac));
}

TAC* makeWhile(TAC* code0, TAC* code1){
    TAC* jumptac = 0;
    TAC* labeltac = 0;
    TAC* jumpWhileTac = 0;
    TAC* labelWhileTac = 0;
    HASH_NODE* newlabel = 0;
    HASH_NODE* newlabel2 = 0;
    newlabel = makeLabel();
    newlabel2 = makeLabel();

    labelWhileTac = tacCreate(TAC_LABEL, newlabel2,0,0);
    labelWhileTac->prev = code0->prev;
	code0->prev = labelWhileTac;

    jumptac = tacCreate(TAC_JFALSE, newlabel, code0?code0->res:0, 0);
    jumptac->prev = code0;

    jumpWhileTac = tacCreate(TAC_JMP, newlabel2,0,0);
    jumpWhileTac->prev = code1;

    labeltac = tacCreate(TAC_LABEL, newlabel,0,0);
    labeltac->prev = jumpWhileTac;


    return tacJoin(jumptac, labeltac);
}


TAC* generateCode(AST *node){
    int i;
    TAC* result = 0;
    TAC* code[MAXFILHOS];

    if (!node)
        return 0;

    //PROCESSA FILHOS
    for (i=0;  i<MAXFILHOS; ++i)
        code[i] = generateCode(node->filho[i]);

    //PROCESSA O NODO
    switch(node->type)
    {
        case AST_SYMBOL:
        case AST_IDENT:
        case AST_INT:   result = tacCreate(TAC_SYMBOL,node->symbol,0,0); break;
		case AST_ADD:result = makeBinCode(TAC_ADD, code[0], code[1]);
            break;
		case AST_SUB:result = makeBinCode(TAC_SUB, code[0], code[1]);
            break;
		case AST_MULT:result = makeBinCode(TAC_MULT, code[0], code[1]);
            break;
		case AST_DIV:result = makeBinCode(TAC_DIV, code[0], code[1]);
            break;
		case AST_OR:result = makeBinCode(TAC_OR, code[0], code[1]);
            break;
		case AST_AND:result = makeBinCode(TAC_AND, code[0], code[1]);
            break;
		case AST_OPDIF:result = makeBinCode(TAC_OPDIF, code[0], code[1]);
            break;
		case AST_OPEQ:result = makeBinCode(TAC_OPEQ, code[0], code[1]);
            break;
		case AST_OPGE:result = makeBinCode(TAC_OPGE, code[0], code[1]);
            break;
		case AST_OPLE:result = makeBinCode(TAC_OPLE, code[0], code[1]);
            break;
		case AST_BIG:result = makeBinCode(TAC_BIG, code[0], code[1]);
            break;
		case AST_LESS: result = makeBinCode(TAC_LESS, code[0], code[1]);
            break;
		case AST_ASSIGN: result = tacJoin(code[0],tacCreate(TAC_ASSIGN,node->symbol,code[0]?code[0]->res:0,code[1]?code[1]->res:0));
            break;
		case AST_IF: result = makeIf(code[0],code[1]); break;	
		case AST_WHILE: result = makeWhile(code[0], code[1]); break;
		case AST_IFELSE: result = makeIfElse(code[0],code[1],code[2]);break;
		case AST_FUNC: result = tacJoin(tacJoin(tacCreate(TAC_BEGINFUNC, node->symbol,0,0),code[2])
								,tacCreate(TAC_ENDFUNC,node->symbol,0,0));break;
		case AST_PRINT: result = tacJoin(code[0],tacCreate(TAC_PRINT, node->symbol,code[0]?code[0]->res:0,0));break;

        default: result = tacJoin(code[0],tacJoin(code[1],tacJoin(code[2],code[3])));
        break;
    }


    return result;

}

// ASM GENERATION

TAC* tacReverse(TAC* tac){
    TAC* t = tac;
    for (t=tac; t->prev; t = t->prev)
        t->prev->next = t;
    return t;
}

void generateAsm(TAC* first)
{
    TAC* tac;
    FILE *fout;
    fout = fopen("out.s","w");
    // INIT
    fprintf(fout,"##FIXED INIT\n"
    "printintstr:	.asciz	\"%%d\\n\"\n"
    "printstringst:  .asciz \"%%s\\n\"\n"
    "\n"
	".text\n");
    // EACH TAC

    for (tac = first; tac; tac = tac->next)
    {
    switch(tac->type)
    {
        case TAC_BEGINFUNC: fprintf(fout, "## TAC_BEGIN_FUN\n"
                                    "\t.globl	%s\n"
                                    "\t.type	%s, @function\n"
                                    "%s:\n"
                                    "\tpushq	%%rbp\n"
                                    "\tmovq	%%rsp, %%rbp\n", tac->res->text,tac->res->text,tac->res->text);
        break;
        case TAC_ENDFUNC: fprintf(fout, "## TAC_END_FUN:\n"
                                    "\tpopq	%%rbp\n"
                                    "\tret\n");
        break;
        case TAC_PRINT: fprintf(fout,"## TAC_PRINT\n"
                                "	movl	_%s(%%rip), %%esi\n"
                                "\tleaq	printintstr(%%rip), %%rax\n"
                                "\tmovq	%%rax, %%rdi\n"
                                "\tcall	printf@PLT\n", tac->op1->text);
        break;
        case TAC_ASSIGN: fprintf(fout, "## TAC_ASSIGN\n"
                                        "\tmovl\t_%s(%%rip), %%eax\n"
                                        "\tmovl\t%%eax, _%s(%%rip)\n", tac->op1->text, tac->res->text);
        break;
        case TAC_ADD: fprintf(fout, "## TAC_ADD\n"
                                    "\tmovl\t_%s(%%rip), %%edx\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\taddl\t%%edx, %%eax\n"
                                    "\tmovl\t%%eax, _%s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_SUB: fprintf(fout, "## TAC_SUB\n"
                                    "\tmovl\t_%s(%%rip), %%edx\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\tsubl\t%%eax, %%edx\n"
                                    "\tmovl\t%%edx, _%s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_MULT: fprintf(fout,"## TAC_MULT\n"
                                    "\tmovl\t_%s(%%rip), %%edx\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\timull\t%%edx, %%eax\n"
                                    "\tmovl\t%%eax, _%s(%%rip)\n",tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_DIV: fprintf(fout, "## TAC_DIV\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\tmovl\t_%s(%%rip), %%ecx\n"
                                    "\tcltd\n"
                                    "\tidivl\t%%ecx\n"
                                    "\tmovl\t%%eax, _%s(%%rip)\n",tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_LESS: fprintf(fout,"## TAC_LESS\n"
                                    "\tmovl\t_%s(%%rip), %%edx\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\tcmpl\t%%eax,%%edx\n"
                                    "\tsetl\t%%al\n"
                                    "\tmovzbl\t%%al,%%eax\n"
                                    "\tmovl\t%%eax, _%s(%%rip)\n",tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_BIG: fprintf(fout, "## TAC_BIG\n"
                                    "\tmovl\t_%s(%%rip), %%edx\n"
                                    "\tmovl\t_%s(%%rip), %%eax\n"
                                    "\tcmpl\t%%eax,%%edx\n"
                                    "\tsetg\t%%al\n"
                                    "\tmovzbl\t%%al,%%eax\n"
                                    "\tmovl\t%%eax, _%s(%%rip)\n",tac->op1->text, tac->op2->text, tac->res->text);
        break;
        case TAC_JFALSE: fprintf(fout,  "## TAC_JFALSE\n"
                                        "\tmovl\t_%s(%%rip), %%eax\n"
                                        "\ttestl\t%%eax, %%eax\n"
                                        "\tje\t.%s\n",tac->op1->text, tac->res->text);
        break;
        case TAC_JMP: fprintf(fout, "## TAC_JMP\n"
                                    "\tjmp\t.%s\n",tac->res->text);
        break;
        case TAC_LABEL: fprintf(fout,   "## TAC_LABEL\n"
                                        ".%s:\n", tac->res->text);
        break;
    }
    }
    // HASH TABLE
    printAsm(fout);
    fclose(fout);
}





