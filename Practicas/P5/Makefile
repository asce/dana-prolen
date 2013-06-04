.SUFFIXES:
semantico: main.o y.tab.o
	gcc -g -o semantico main.o y.tab.o
y.tab.o: y.tab.c
	gcc -c y.tab.c
main.o: main.c
	gcc -c main.c
y.tab.c: semantico.y lex.yy.c tablaSimbolos.h
	bison -d --report=state -o y.tab.c semantico.y
lex.yy.c: lexico.l
	flex -l lexico.l
out: out.c
	gcc -o out out.c

clean:
	rm -f semantico main.o y.tab.o y.tab.h y.tab.c y.output lex.yy.c
all:
	make clean
	make semantico
