%{
#include "y.tab.h"
#include <stdio.h>

 
%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
digito [0-9]
guionbajo [_]
delimitador [ \t\n]
espacioblanco	{delimitador}+
suma_resta [+-]
%%

"main"			{return MAIN;}
"{"			{return INICIO;}
"}"			{return FINBLO;}
"begin_declare"		{return INICIOV;}
"end_declare"		{return FINV;}
"true"		       {yylval.lexema=strdup(yytext);
                        yylval.atrib = 7;
                        yylval.tipo = booleano;
                        return CONSTANTE;}
"false"		       {yylval.lexema=strdup(yytext);
                        yylval.atrib = 8;
                        yylval.tipo = booleano;
                        return CONSTANTE;}
";"			{return PYC;}
","			{return COMA;}

"int"			{yylval.atrib = 1; 
                         yylval.tipo = entero;                                           
                         return TIPOSIMPLE;}

"double"		{yylval.atrib = 2; 
                        yylval.tipo = real;                                              
                        return TIPOSIMPLE;}

"bool"			{yylval.atrib = 3; 
                         yylval.tipo = booleano;
                         return TIPOSIMPLE;}

"char"			{yylval.atrib = 4; 
                         yylval.tipo = caracter;                        
                         return TIPOSIMPLE;}

"void"			{return PROCED;}
"["			{return CORIZ;}
"]"			{return CORDER;}
"="			{return ASIG;}
"if"			{return IF;}
"else"			{return ELSE;}
"while"			{return WHILE;}
"read"			{return READ;}
"write"			{return WRITE;}
"switch"		{return SWITCH;}
"case"			{return CASE;}
"default"		{return DEFAULT;}
":"			{return DOSP;}
"break"			{return BREAK;}
{digito}+"E+"{digito}+	                {yylval.lexema=strdup(yytext);yylval.tipo=real;yylval.atrib = 2;return CONSTANTE;}
{digito}+"E-"{digito}+	                {yylval.lexema=strdup(yytext);yylval.tipo=real;yylval.atrib = 3;return CONSTANTE;}
{digito}+"."{digito}+"E+"{digito}+	{yylval.lexema=strdup(yytext);yylval.tipo=real;yylval.atrib = 4;return CONSTANTE;}
{digito}+"."{digito}+"E-"{digito}+	{yylval.lexema=strdup(yytext);yylval.tipo=real;yylval.atrib = 5;return CONSTANTE;}
{digito}+ 		                {yylval.lexema=strdup(yytext); yylval.tipo=entero; return CONSTANTE_E;}
{digito}+"."{digito}+	                {yylval.lexema=strdup(yytext);yylval.tipo=real;yylval.atrib = 1;return CONSTANTE;}
"!="					{yylval.atrib = 2; return OPB_IG;}
"!" 					{return OPU;}
"**"					{yylval.atrib = 1; return OPB_MUL;}
"*"					{yylval.atrib = 2; return OPB_MUL;}
"/"					{yylval.atrib = 3; return OPB_MUL;}
"&&"					{return OPB_AND;}
"||"					{return OPB_OR;}
"¬|"					{return OPB_OR;}
"<="					{yylval.atrib = 3; return OPB_REL;}
">="					{yylval.atrib = 4; return OPB_REL;}
"<"					{yylval.atrib = 1; return OPB_REL;}
">"					{yylval.atrib = 2; return OPB_REL;}
"=="					{yylval.atrib = 1; return OPB_IG;}
")"					{return PARDER;}
"("					{return PARIZ;}
"+"			                {yylval.atrib = 1; return OPB_ADD;}
"-"                                     {yylval.atrib = 2; return OPB_ADD;}                 
{espacioblanco}				{					;}
\"[^\"\n]*\"				{yylval.lexema = strdup(strdup(yytext));return CADENA;}
"'"[^"'"]"'"				{yylval.lexema = strdup(strdup(yytext));yylval.tipo=caracter;return CARACTER;}
{letra}({letra}|{digito}|{guionbajo})*	{ yylval.lexema = strdup(strdup(yytext)); 
                                          return IDENTIFICADOR;
                                        }
.					{printf("(linea %d) ERROR_LEXICO: token %s\n",yylineno,strdup(yytext));}
%%


