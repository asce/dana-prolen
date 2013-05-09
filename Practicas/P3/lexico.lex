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
suma_resta [+-]
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
":"			{return DOSP;}
"break"			{return BREAK;}
{digito}+ 		{return CONSTANTE;}
{digito}+"."{digito}+	{return CONSTANTE;}
{digito}+"E+"{digito}+	{return CONSTANTE;}
{digito}+"E-"{digito}+	{return CONSTANTE;}
{digito}+"."{digito}+"E+"{digito}+	{return CONSTANTE;}
{digito}+"."{digito}+"E-"{digito}+	{return CONSTANTE;}
"!" 					{return OPU;}
"**"					{return OPB;}
"*"					{return OPB;}
"/"					{return OPB;}
"&&"					{return OPBLOG;}
"||"					{return OPBLOG;}
"¬|"					{return OPBLOG;}
"!="					{return OPBIG;}
"<"					{return OPBIG;}
"<="					{return OPBIG;}
">"					{return OPBIG;}
">="					{return OPBIG;}
"=="					{return OPBIG;}
")"					{return PARDER;}
"("					{return PARIZ;}
{suma_resta}			      {return SUMA_RESTA;}
{espacioblanco}				{					;}
\"[^\"\n]*\"				{return CADENA;}
"'"[^"'"]"'"				{return CONSTANTE;}
{letra}({letra}|{digito}|{guionbajo})*	{return IDENTIFICADOR;}
.					{printf("(linea %d) ERROR_LEXICO: token %s\n",yylineno,yytext);}
%%
