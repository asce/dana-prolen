%{
#include "y.tab.h"
#include <stdio.h>
#define ERROR_LEXICO -1

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
digito [0-9]
guionbajo [_]
delimitador [ \t\n]
espacioblanco	{delimitador}+
%%

"main"			{printf("main\t");ECHO;printf("\n");}
"{"			{printf("INICIO\t");ECHO;printf("\n");}
"}"			{printf("FINBLO\t");ECHO;printf("\n");}
"begin_declare"		{printf("INICIOV\t");ECHO;printf("\n");}
"end_declare"		{printf("FINV\t");ECHO;printf("\n");}
";"			{printf("PYC\t");ECHO;printf("\n");}
","			{printf("COMA\t");ECHO;printf("\n");}
"int"			{printf("TIPOSIMPLE\t");ECHO;printf("\n");}
"double"		{printf("TIPOSIMPLE\t");ECHO;printf("\n");}
"bool"			{printf("TIPOSIMPLE\t");ECHO;printf("\n");}
"char"			{printf("TIPOSIMPLE\t");ECHO;printf("\n");}
"void"			{printf("PROCED\t");ECHO;printf("\n");}
"["			{printf("CORIZ\t");ECHO;printf("\n");}
"]"			{printf("CORDER\t");ECHO;printf("\n");}
"="			{printf("ASIG\t");ECHO;printf("\n");}
"if"			{printf("IF\t");ECHO;printf("\n");}
"else"			{printf("ELSE\t");ECHO;printf("\n");}
"while"			{printf("WHILE\t");ECHO;printf("\n");}
"read"			{printf("READ\t");ECHO;printf("\n");}
"write"			{printf("WRITE\t");ECHO;printf("\n");}
"switch"		{printf("SWITCH\t");ECHO;printf("\n");}
"case"			{printf("CASE\t");ECHO;printf("\n");}
"default"		{printf("DEFAULT\t");ECHO;printf("\n");}
":"			{printf("DOSP\t");ECHO;printf("\n");}
"break"			{printf("\t");ECHO;printf("\n");}
{digito}+ 		{printf("CENTERA\t");ECHO;printf("\n");}
{digito}+"."{digito}+	{printf("CREAL\t");ECHO;printf("\n");}
{digito}+"E+"{digito}+	{printf("CREAL\t");ECHO;printf("\n");}
{digito}+"E-"{digito}+	{printf("CREAL\t");ECHO;printf("\n");}
{digito}+"."{digito}+"E+"{digito}+	{printf("CREAL\t");ECHO;printf("\n");}
{digito}+"."{digito}+"E-"{digito}+	{printf("CREAL\t");ECHO;printf("\n");}
"!" 					{printf("OPUNARIO\t");ECHO;printf("\n");}
"**"					{printf("OPBINARIO_1\t");ECHO;printf("\n");}
"*"					{printf("OPBINARIO_2\t");ECHO;printf("\n");}
"/"					{printf("OPBINARIO_3\t");ECHO;printf("\n");}
"&&"					{printf("OPBINARIO_4\t");ECHO;printf("\n");}
"||"					{printf("OPBINARIO_5\t");ECHO;printf("\n");}
"¬|"					{printf("OPBINARIO_6\t");ECHO;printf("\n");}
"!="					{printf("OPBINARIO_7\t");ECHO;printf("\n");}
"<"					{printf("OPBINARIO_8\t");ECHO;printf("\n");}
"<="					{printf("OPBINARIO_9\t");ECHO;printf("\n");}
">"					{printf("OPBINARIO_10\t");ECHO;printf("\n");}
">="					{printf("OPBINARIO_11\t");ECHO;printf("\n");}
"=="					{printf("OPBINARIO_12\t");ECHO;printf("\n");}
"~"					{printf("GUSANILLO\t");ECHO;printf("\n");}
")"					{printf("PARDERECHO\t");ECHO;printf("\n");}
"("					{printf("PARIZQUIERDO\t");ECHO;printf("\n");}
"+"					{printf("OPBINARIO_13\t");ECHO;printf("\n");}
"-"					{printf("OPBINARIO_14\t");ECHO;printf("\n");}
{espacioblanco}				{					;}
\"[^\"\n]*\"				{printf("CADENA\t");ECHO;printf("\n");}
"'"[^"'"]"'"				{printf("CCHAR\t");ECHO;printf("\n");}
{letra}({letra}|{digito}|{guionbajo})*	{printf("IDENTIFICADOR\t");ECHO;printf("\n");}
.					{printf("(linea %d) ERROR_LEXICO: token %s\n",yylineno,yytext);}
%%

int main(int argc, char** argv)
{
	int val;
	val= yylex() ;
	while (val != 0)
	{
		printf("%s %d\n",yytext,val);
		val= yylex() ;
	}
	exit (1);
	
}

