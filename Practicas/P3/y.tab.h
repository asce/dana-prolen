/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     INICIO = 259,
     FINBLO = 260,
     INICIOV = 261,
     FINV = 262,
     PYC = 263,
     COMA = 264,
     TIPOSIMPLE = 265,
     PROCED = 266,
     CORDER = 267,
     IF = 268,
     ELSE = 269,
     WHILE = 270,
     READ = 271,
     WRITE = 272,
     SWITCH = 273,
     CASE = 274,
     DEFAULT = 275,
     DOSP = 276,
     BREAK = 277,
     CONSTANTE = 278,
     PARDER = 279,
     PARIZ = 280,
     CADENA = 281,
     IDENTIFICADOR = 282,
     CONSTANTE_E = 283,
     CARACTER = 284,
     CORIZ = 285,
     ASIG = 286,
     OPU = 287,
     OPBLOG = 288,
     OPBIG = 289,
     OPB = 290,
     SUMA_RESTA = 291
   };
#endif
/* Tokens.  */
#define MAIN 258
#define INICIO 259
#define FINBLO 260
#define INICIOV 261
#define FINV 262
#define PYC 263
#define COMA 264
#define TIPOSIMPLE 265
#define PROCED 266
#define CORDER 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define READ 271
#define WRITE 272
#define SWITCH 273
#define CASE 274
#define DEFAULT 275
#define DOSP 276
#define BREAK 277
#define CONSTANTE 278
#define PARDER 279
#define PARIZ 280
#define CADENA 281
#define IDENTIFICADOR 282
#define CONSTANTE_E 283
#define CARACTER 284
#define CORIZ 285
#define ASIG 286
#define OPU 287
#define OPBLOG 288
#define OPBIG 289
#define OPB 290
#define SUMA_RESTA 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

