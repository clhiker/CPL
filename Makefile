CC=gcc

target:
	#bison cpl.y -d
	#flex cpl.l
	$(CC) -g main.c ast.c extrac.c cpl_lexer.c cpl_parser.c utility.c -o cpl
clean:
	#rm cpl_lexer.c cpl_lexer.h cpl_parser.c cpl_parser.h cpl
