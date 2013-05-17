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
"true"		       {return CONSTANTE;}
"false"		       {return CONSTANTE;}
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
":"			{return DOSP;}
"break"			{return BREAK;}
{digito}+"E+"{digito}+	{return CONSTANTE;}
{digito}+"E-"{digito}+	{return CONSTANTE;}
{digito}+"."{digito}+"E+"{digito}+	{return CONSTANTE;}
{digito}+"."{digito}+"E-"{digito}+	{return CONSTANTE;}
{digito}+ 		{return CONSTANTE_E;}
{digito}+"."{digito}+	{return CONSTANTE;}
"!="					{return OPB_IG;}
"!" 					{return OPU;}
"**"					{return OPB_MUL;}
"*"					{return OPB_MUL;}
"/"					{return OPB_MUL;}
"&&"					{return OPB_AND;}
"||"					{return OPB_OR;}
"¬|"					{return OPB_OR;}
"<="					{return OPB_REL;}
">="					{return OPB_REL;}
"<"					{return OPB_REL;}
">"					{return OPB_REL;}
"=="					{return OPB_IG;}
")"					{return PARDER;}
"("					{return PARIZ;}
{suma_resta}			        {return OPB_ADD;}
{espacioblanco}				{					;}
\"[^\"\n]*\"				{return CADENA;}
"'"[^"'"]"'"				{return CARACTER;}
{letra}({letra}|{digito}|{guionbajo})*	{return IDENTIFICADOR;}
.					{printf("(linea %d) ERROR_LEXICO: token %s\n",yylineno,yytext);}
%%
