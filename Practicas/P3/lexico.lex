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

"main"			{return MAIN;}
"{"			{return INICIO;}
"}"			{return FINBLO;}
"begin_declare"		{return INICIOV;}
"end_declare"		{return FINV;}
";"			{return PYC;}
","			{return COMA;}
"int"			{return TIPOSIMPLE;}
"double"		{return TIPOSIMPLE;}
"bool"			{return TIPOSIMPLE;}
"char"			{return TIPOSIMPLE;}
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
