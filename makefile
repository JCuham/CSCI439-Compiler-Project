project:
	lex lexer.lex
	yacc -v -d parser.yacc
	gcc y.tab.c -o cmm
run: project
	./cmm < testprog
clean:
	rm -f lex.yy.c y.tab.c y.tab.h lex.yy.c cmm output.s y.output
