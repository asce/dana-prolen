pr2:
	lex -X -8 lexico.lex
	gcc -c lex.yy.c -o lexico.o
	gcc -o lexico lexico.o -ll
clean:
	rm *.o lexico lex.yy.c *~
