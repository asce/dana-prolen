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
"true"		       {yylval.tipo = booleano; yylval.lexema = strdup(yytext);yylval.atrib = 7;return CONSTANTE;}
"false"		       {yylval.tipo = booleano; yylval.lexema = strdup(yytext);yylval.atrib = 8;return CONSTANTE;}
";"			{return PYC;}
","			{return COMA;}
"int"			{yylval.tipo = entero; yylval.lexema = strdup(yytext); yylval.atrib = 1 ;return TIPOSIMPLE;}
"double"		{yylval.tipo = real; yylval.lexema = strdup(yytext);yylval.atrib = 2;return TIPOSIMPLE;}
"bool"			{yylval.tipo = booleano; yylval.lexema = strdup(yytext); yylval.atrib = 3;return TIPOSIMPLE;}
"char"			{yylval.tipo = caracter; yylval.lexema = strdup(yytext); yylval.atrib = 4;return TIPOSIMPLE;}
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
{digito}+"E+"{digito}+	{yylval.tipo = real; yylval.lexema = strdup(yytext); yylval.atrib = 2;return CONSTANTE;}
{digito}+"E-"{digito}+	{yylval.tipo = real; yylval.lexema = strdup(yytext); yylval.atrib = 3;return CONSTANTE;}
{digito}+"."{digito}+"E+"{digito}+	{yylval.tipo = real; yylval.lexema = strdup(yytext); yylval.atrib = 4;return CONSTANTE;}
{digito}+"."{digito}+"E-"{digito}+	{yylval.tipo = real; yylval.lexema = strdup(yytext); yylval.atrib = 5;return CONSTANTE;}
{digito}+ 		{yylval.tipo = entero; yylval.lexema = strdup(yytext);return CONSTANTE_E;}
{digito}+"."{digito}+	{yylval.tipo = real; yylval.lexema = strdup(yytext); yylval.atrib = 1;return CONSTANTE;}
"!="					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_IG;}
"!" 					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPU;}
"**"					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_MUL;}
"*"					{yylval.atrib = 2; yylval.lexema = strdup(yytext);return OPB_MUL;}
"/"					{yylval.atrib = 3; yylval.lexema = strdup(yytext);return OPB_MUL;}
"&&"					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_AND;}
"||"					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_OR;}
"¬|"					{yylval.atrib = 2; yylval.lexema = strdup(yytext);return OPB_OR;}
"<="					{yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_REL;}
">="					{yylval.atrib = 2; yylval.lexema = strdup(yytext);return OPB_REL;}
"<"					{yylval.atrib = 3; yylval.lexema = strdup(yytext);return OPB_REL;}
">"					{yylval.atrib = 4; yylval.lexema = strdup(yytext);return OPB_REL;}
"=="					{yylval.atrib = 2; yylval.lexema = strdup(yytext);return OPB_IG;}
")"					{return PARDER;}
"("					{return PARIZ;}
{suma_resta}			        {yylval.atrib = 1; yylval.lexema = strdup(yytext);return OPB_ADD;}
{espacioblanco}				{					;}
\"[^\"\n]*\"				{yylval.tipo = string;return CADENA;}
"'"[^"'"]"'"				{yylval.tipo = caracter;return CARACTER;}
{letra}({letra}|{digito}|{guionbajo})*	{yylval.lexema = strdup(yytext);return IDENTIFICADOR;}
.					{yylval.tipo=desconocido;printf("(linea %d) ERROR_LEXICO: token %s\n",yylineno,yytext);}
%%
