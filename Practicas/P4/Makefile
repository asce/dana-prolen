.SUFFIXES:

sintactico: main.o y.tab.o
	gcc -o sintactico main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: sintactico.y lex.yy.c
	bison -d --report=state -o y.tab.c sintactico.y

lex.yy.c: lexico.l
	flex lexico.l

clean:
	rm -f sintactico main.o y.tab.o y.tab.h y.tab.c y.output lex.yy.c

all:
	make clean
	make sintactico
