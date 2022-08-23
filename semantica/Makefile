#
# UFRGS - Compiladores B - Marcelo Johann - 2022/1 - Etapa 4
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa4:  lex.yy.o main.o y.tab.o hash.o ast.o semantic.o 
	gcc -o etapa4 lex.yy.o main.o y.tab.o hash.o ast.o semantic.o

main.o:	main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

semantic.o: semantic.c
	gcc -c semantic.c

y.tab.o: y.tab.c 
	gcc -c y.tab.c 

lex.yy.o: lex.yy.c 
	gcc -c lex.yy.c 

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c *.o etapa4
