%{

#define MAXLONBUFFER 200
char buffer[MAXLONBUFFER];

%}

%option noyywrap

%%

el|la           { return ARTICULO;}
a               { return ARTICULO_A;}
habla|ve|mira   { return VERBO;}
Juan|Pepe|Maria { return NOMBRE_PROPIO;}
perro|gato|luna { return NOMBRE;}
\n              {linea_actual++;}
[ \t]+          {}
.               { snprintf(buffer, MAXLONBUFFER, "el caracter o caracteres %s no forma un token conocido",yytext);
                  yyerror(buffer);
                }

