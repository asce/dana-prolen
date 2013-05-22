/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "sintactico.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tablaSimbolos.h"

/**  La siguiente declaracion permite que 'yyerror' se pueda invocar desde el 
***  fuente de lex (prueba.l)
**/

void yyerror( char * msg ) ;

/**  La siguiente variable se usar? para conocer el numero de la l?nea
***  que se esta leyendo en cada momento. Tambi?n es posible usar la variable 
***  'yylineno' que tambi?n nos muestra la l?nea actual. Para ello es necesario
***  invocar a flex con la opción '-l' (compatibilidad con lex).
**/

int linea_actual = 1 ;
dtipo tipoPorAsignar;
int pila=0;
int argumentos =1;
int correcto=1;
char *nomproc;
int numparam=0;
char *iden;
dtipo iden_tipo;
dtipo tipoAux;

dtipo tipo_pila;		//Diferente al nombre del procedimiento tipoPila
int pilaError = 0;


/* Line 268 of yacc.c  */
#line 106 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     CONSTANTE = 259,
     OPUNARIO = 260,
     OP_MULDIV = 261,
     SIGNO = 262,
     INIVAR = 263,
     FINVAR = 264,
     TIPOSIMPLE = 265,
     PILA = 266,
     MIENTRAS = 267,
     PUNTO = 268,
     CADENA = 269,
     ESCRIBIR = 270,
     LEER = 271,
     CASO = 272,
     DE = 273,
     SI = 274,
     HACER = 275,
     ENTONCES = 276,
     SINO = 277,
     PARIZQ = 278,
     PARDER = 279,
     INICIO = 280,
     FIN = 281,
     ASIGNACION = 282,
     PROGRAMA = 283,
     DOSPUNTOS = 284,
     PUNTOCOMA = 285,
     COMA = 286,
     LLAVEIZQ = 287,
     LLAVEDER = 288,
     PROCEDIMIENTO = 289,
     OP_OR = 290,
     OP_AND = 291,
     OP_RELACIONAL = 292,
     OP_IGUALDAD = 293,
     OPMASMAS = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 187 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    15,    16,    19,    23,    24,
      28,    31,    33,    36,    38,    43,    45,    48,    49,    52,
      54,    55,    59,    60,    61,    69,    70,    75,    77,    78,
      84,    86,    89,    91,    92,    96,    97,   100,   102,   104,
     106,   108,   110,   112,   114,   116,   117,   121,   123,   125,
     126,   132,   134,   138,   142,   143,   150,   151,   154,   155,
     156,   157,   173,   174,   177,   178,   179,   185,   187,   188,
     192,   195,   197,   198,   202,   203,   210,   214,   217,   219,
     220,   224,   228,   230,   234,   236,   238,   242,   245,   249,
     253,   257,   261,   265,   269,   273,   275,   277,   279,   282,
     284,   285,   291,   292,   293,   298,   300,   303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    28,    42,    13,    -1,    -1,    25,    43,
      46,    44,    60,    26,    -1,    -1,    44,    45,    -1,    53,
      42,    30,    -1,    -1,     8,    47,     9,    -1,    48,    47,
      -1,    48,    -1,    49,    30,    -1,     1,    -1,    51,    29,
      96,    50,    -1,     1,    -1,    27,    91,    -1,    -1,     3,
      52,    -1,     1,    -1,    -1,    31,     3,    52,    -1,    -1,
      -1,    34,     3,    23,    54,    56,    55,    24,    -1,    -1,
      58,    29,    96,    57,    -1,     1,    -1,    -1,    30,    58,
      29,    96,    57,    -1,     1,    -1,     3,    59,    -1,     1,
      -1,    -1,    31,     3,    59,    -1,    -1,    60,    61,    -1,
      42,    -1,    62,    -1,    69,    -1,    72,    -1,    83,    -1,
      85,    -1,    88,    -1,     1,    -1,    -1,     3,    63,    64,
      -1,    65,    -1,    68,    -1,    -1,    23,    66,    67,    24,
      30,    -1,    91,    -1,    67,    31,    91,    -1,    27,    91,
      30,    -1,    -1,    19,    91,    70,    21,    61,    71,    -1,
      -1,    22,    61,    -1,    -1,    -1,    -1,    17,     3,    73,
      18,    79,    74,    29,    61,    79,    75,    29,    61,    77,
      76,    26,    -1,    -1,    22,    61,    -1,    -1,    -1,    79,
      78,    29,    61,    77,    -1,    81,    -1,    -1,     4,    80,
      94,    -1,     3,    82,    -1,     1,    -1,    -1,    31,     3,
      82,    -1,    -1,    12,    91,    84,    20,    61,    26,    -1,
      16,    86,    30,    -1,     3,    87,    -1,     1,    -1,    -1,
      31,     3,    87,    -1,    15,    89,    30,    -1,    90,    -1,
      90,    31,    89,    -1,    91,    -1,    14,    -1,    23,    91,
      24,    -1,     5,    91,    -1,    91,     6,    91,    -1,    91,
       7,    91,    -1,    91,    37,    91,    -1,    91,    39,    91,
      -1,    91,    35,    91,    -1,    91,    36,    91,    -1,    91,
      38,    91,    -1,     3,    -1,     4,    -1,    92,    -1,     7,
      91,    -1,     1,    -1,    -1,    32,     4,    93,    94,    33,
      -1,    -1,    -1,    31,     4,    95,    94,    -1,    10,    -1,
      11,    10,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   104,   104,   106,   106,   108,   110,   110,
     112,   112,   114,   114,   116,   116,   118,   118,   120,   123,
     125,   125,   129,   134,   129,   136,   136,   136,   139,   139,
     139,   141,   144,   146,   146,   150,   150,   152,   152,   152,
     152,   152,   152,   152,   152,   154,   154,   156,   156,   158,
     158,   174,   181,   191,   204,   204,   211,   211,   213,   217,
     221,   213,   227,   227,   229,   229,   229,   235,   235,   235,
     241,   250,   252,   252,   261,   261,   268,   270,   274,   276,
     276,   281,   283,   283,   285,   285,   287,   291,   312,   330,
     348,   360,   370,   380,   391,   404,   409,   411,   413,   421,
     423,   423,   425,   425,   425,   432,   432,   432
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "CONSTANTE", "OPUNARIO",
  "OP_MULDIV", "SIGNO", "INIVAR", "FINVAR", "TIPOSIMPLE", "PILA",
  "MIENTRAS", "PUNTO", "CADENA", "ESCRIBIR", "LEER", "CASO", "DE", "SI",
  "HACER", "ENTONCES", "SINO", "PARIZQ", "PARDER", "INICIO", "FIN",
  "ASIGNACION", "PROGRAMA", "DOSPUNTOS", "PUNTOCOMA", "COMA", "LLAVEIZQ",
  "LLAVEDER", "PROCEDIMIENTO", "OP_OR", "OP_AND", "OP_RELACIONAL",
  "OP_IGUALDAD", "OPMASMAS", "$accept", "programa", "bloque", "$@1",
  "declar_de_subprogs", "declar_subprog", "declar_de_variables_locales",
  "variables_locales", "cuerpo_declar_variables", "asdf",
  "opcion_asign_variable", "lista_variables", "lista_identificador",
  "cabecera_subprograma", "$@2", "$@3", "variables_subprograma",
  "lista_variables_subprograma", "lista_parametros",
  "lista_identificador_parametros", "sentencias", "sentencia",
  "asignacion_procedimiento", "$@4", "procedimientoOasignacion",
  "llamada_procedimiento", "$@5", "lista_parametros_procedimiento",
  "sentencia_asignacion", "sentencia_if", "$@6", "sentencia_else",
  "sentencia_switch", "$@7", "$@8", "$@9", "opcion_switch_sino",
  "lista_sentencia_switch", "$@10", "lista_variables_switch", "@11",
  "lista_variables_en_switch", "lista_identificador_en_switch",
  "sentencia_while", "$@12", "sentencia_entrada",
  "lista_variables_entrada", "lista_identificador_entrada",
  "sentencia_salida", "lista_expresiones_o_cadena", "expresion_cad",
  "expresion", "agregado", "$@13", "lista_constantes", "$@14", "tipo", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    43,    42,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    54,    55,    53,    56,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    63,    62,    64,    64,    66,
      65,    67,    67,    68,    70,    69,    71,    71,    73,    74,
      75,    72,    76,    76,    77,    78,    77,    79,    80,    79,
      81,    81,    82,    82,    84,    83,    85,    86,    86,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      93,    92,    94,    95,    94,    96,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     6,     0,     2,     3,     0,     3,
       2,     1,     2,     1,     4,     1,     2,     0,     2,     1,
       0,     3,     0,     0,     7,     0,     4,     1,     0,     5,
       1,     2,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     1,     0,
       5,     1,     3,     3,     0,     6,     0,     2,     0,     0,
       0,    15,     0,     2,     0,     0,     5,     1,     0,     3,
       2,     1,     0,     3,     0,     6,     3,     2,     1,     0,
       3,     3,     1,     3,     1,     1,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     1,
       0,     5,     0,     0,     4,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     8,     2,     0,     5,
      13,    20,     0,     0,     0,     0,    35,     0,    18,     9,
      10,    12,     0,     0,     6,     0,     0,    20,   107,   105,
       0,    17,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     4,    37,    36,    38,    39,    40,    41,    42,    43,
      21,   106,     0,    14,    22,     7,     0,    99,    95,    96,
       0,     0,     0,     0,    74,    97,    85,     0,    82,    84,
      78,    79,     0,    58,    54,    16,     0,    49,     0,    46,
      47,    48,    87,    98,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    77,    76,     0,
       0,    27,    33,    23,     0,     0,     0,    86,   102,    88,
      89,    92,    93,    90,    94,    91,     0,    83,    79,     0,
       0,     0,    31,     0,     0,     0,    51,    53,     0,     0,
       0,    80,    71,    72,    68,    59,    67,    56,    33,    24,
       0,     0,     0,   103,   101,    75,     0,    70,   102,     0,
       0,    55,    34,    30,     0,    26,    50,    52,   102,    72,
      69,     0,    57,    32,     0,   104,    73,     0,     0,    60,
       0,     0,    29,     0,     0,    62,    65,     0,     0,     0,
      63,    61,     0,     0,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    42,     6,    16,    24,     9,    12,    13,    14,
      53,    15,    18,    25,    76,   123,   103,   155,   104,   122,
      26,    43,    44,    56,    79,    80,   105,   125,    81,    45,
     100,   151,    46,    99,   149,   171,   178,   175,   179,   176,
     148,   136,   147,    47,    93,    48,    72,    97,    49,    67,
      68,    69,    65,   108,   129,   158,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
     -26,    -6,    32,  -136,    74,  -136,    95,  -136,    14,  -136,
      -1,    69,    36,   150,    85,    83,    84,   118,  -136,  -136,
    -136,  -136,    11,   122,  -136,    -6,   116,    69,  -136,  -136,
     120,   110,   117,   109,  -136,  -136,   106,    91,    65,   143,
     106,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   106,  -136,  -136,  -136,    -9,  -136,  -136,  -136,
     106,   106,   106,   151,    42,  -136,  -136,   124,   125,    42,
    -136,   126,   130,  -136,    42,    42,    96,  -136,   106,  -136,
    -136,  -136,  -136,  -136,    37,  -136,   106,   106,   106,   106,
     106,   106,   106,   127,  -136,    91,   158,  -136,  -136,   144,
     142,   135,   134,  -136,   138,   106,     1,  -136,   139,  -136,
     160,    27,    64,   137,     4,    53,   133,  -136,   126,   123,
     133,   165,  -136,   145,    11,    -4,    42,  -136,   167,   140,
     146,  -136,  -136,   147,  -136,  -136,  -136,   152,   134,  -136,
      92,   149,   106,  -136,  -136,  -136,   172,  -136,   139,   148,
     133,  -136,  -136,  -136,    81,  -136,  -136,    42,   139,   147,
    -136,   133,  -136,  -136,   153,  -136,  -136,   123,    11,  -136,
      92,   154,  -136,   133,    82,   159,  -136,   133,   161,   155,
    -136,  -136,   133,    82,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,     5,  -136,  -136,  -136,  -136,   163,  -136,  -136,
    -136,  -136,   162,  -136,  -136,  -136,  -136,    10,    31,    48,
    -136,  -115,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,     7,  -136,  -110,
    -136,  -136,    29,  -136,  -136,  -136,  -136,    73,  -136,    97,
    -136,   -36,  -136,  -136,  -135,  -136,  -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      64,   130,     1,   140,    74,   137,     4,    86,    87,   135,
      86,    87,    28,   160,    77,    10,    75,    11,    78,     3,
     141,    29,    30,   165,    82,    83,    84,   142,   -19,   -15,
      33,   127,     5,    86,    87,   162,    88,    89,    90,    91,
      92,    90,   106,    86,    87,    19,   167,   170,    86,    87,
     109,   110,   111,   112,   113,   114,   115,   169,   174,    86,
      87,   107,   180,    89,    90,    91,    70,   183,    71,   126,
      86,    87,    88,    89,    90,    91,    92,    88,    89,    90,
      91,    92,   163,   132,   102,   133,   134,     7,    88,    89,
      90,    91,    57,   153,    58,    59,    60,   101,    61,   102,
      17,    90,    91,     8,   -64,    66,   157,    57,   -64,    58,
      59,    60,    22,    61,    62,    21,   -28,    34,    23,    35,
     -25,    27,   154,    63,   132,    32,   133,   134,    36,    62,
      51,    37,    38,    39,    34,    40,    35,    52,    63,    55,
      54,     3,    41,    86,    87,    36,    73,   116,    37,    38,
      39,    10,    40,    11,    94,    85,    95,    96,     3,   -11,
      98,   118,   119,   120,   -32,   121,    86,   124,   138,   139,
     128,   143,   145,   144,   150,   159,    20,   161,   146,   156,
     172,   177,   168,   173,   182,   164,   152,   181,   166,    50,
     184,   131,   117
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-136))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      36,   116,    28,   124,    40,   120,     1,     6,     7,   119,
       6,     7,     1,   148,    23,     1,    52,     3,    27,    25,
      24,    10,    11,   158,    60,    61,    62,    31,    29,    30,
      25,    30,     0,     6,     7,   150,    35,    36,    37,    38,
      39,    37,    78,     6,     7,     9,   161,   168,     6,     7,
      86,    87,    88,    89,    90,    91,    92,   167,   173,     6,
       7,    24,   177,    36,    37,    38,     1,   182,     3,   105,
       6,     7,    35,    36,    37,    38,    39,    35,    36,    37,
      38,    39,     1,     1,     3,     3,     4,    13,    35,    36,
      37,    38,     1,     1,     3,     4,     5,     1,     7,     3,
      31,    37,    38,     8,    22,    14,   142,     1,    26,     3,
       4,     5,    29,     7,    23,    30,    24,     1,    34,     3,
      24,     3,    30,    32,     1,     3,     3,     4,    12,    23,
      10,    15,    16,    17,     1,    19,     3,    27,    32,    30,
      23,    25,    26,     6,     7,    12,     3,    20,    15,    16,
      17,     1,    19,     3,    30,     4,    31,    31,    25,     9,
      30,     3,    18,    21,    29,    31,     6,    29,     3,    24,
      31,     4,    26,    33,    22,     3,    13,    29,    31,    30,
     170,    22,    29,    29,    29,   154,   138,    26,   159,    27,
     183,   118,    95
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    41,    25,    42,     0,    43,    13,     8,    46,
       1,     3,    47,    48,    49,    51,    44,    31,    52,     9,
      47,    30,    29,    34,    45,    53,    60,     3,     1,    10,
      11,    96,     3,    42,     1,     3,    12,    15,    16,    17,
      19,    26,    42,    61,    62,    69,    72,    83,    85,    88,
      52,    10,    27,    50,    23,    30,    63,     1,     3,     4,
       5,     7,    23,    32,    91,    92,    14,    89,    90,    91,
       1,     3,    86,     3,    91,    91,    54,    23,    27,    64,
      65,    68,    91,    91,    91,     4,     6,     7,    35,    36,
      37,    38,    39,    84,    30,    31,    31,    87,    30,    73,
      70,     1,     3,    56,    58,    66,    91,    24,    93,    91,
      91,    91,    91,    91,    91,    91,    20,    89,     3,    18,
      21,    31,    59,    55,    29,    67,    91,    30,    31,    94,
      61,    87,     1,     3,     4,    79,    81,    61,     3,    24,
      96,    24,    31,     4,    33,    26,    31,    82,    80,    74,
      22,    71,    59,     1,    30,    57,    30,    91,    95,     3,
      94,    29,    61,     1,    58,    94,    82,    61,    29,    79,
      96,    75,    57,    29,    61,    77,    79,    22,    76,    78,
      61,    26,    29,    61,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 104 "sintactico.y"
    {IntroIniBloq();}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 104 "sintactico.y"
    {IntroFinBloq();}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 120 "sintactico.y"
    {if(es_repetida((yyvsp[(1) - (2)]).lexema)==0){
														InsertarElemento(variable, (yyvsp[(1) - (2)]).lexema);} 
													}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 125 "sintactico.y"
    {if(es_repetida((yyvsp[(2) - (3)]).lexema)==0){
														InsertarElemento(variable, (yyvsp[(2) - (3)]).lexema);} 
													}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 129 "sintactico.y"
    { 
								if(es_repetida((yyvsp[(2) - (3)]).lexema)==0){
									InsertarElemento(procedimiento,(yyvsp[(2) - (3)]).lexema);asignarTipo (desconocido, TOPE);
								} 
							}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 134 "sintactico.y"
    {CuentaParametros ();}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 141 "sintactico.y"
    {if(es_repetida((yyvsp[(1) - (2)]).lexema)==0){
														InsertarElemento(parametro, (yyvsp[(1) - (2)]).lexema);} 
													}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 146 "sintactico.y"
    {if(es_repetida((yyvsp[(2) - (3)]).lexema)==0){
														InsertarElemento(parametro, (yyvsp[(2) - (3)]).lexema);} 
													}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 154 "sintactico.y"
    {iden = (yyvsp[(1) - (1)]).lexema;}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 158 "sintactico.y"
    {
	if(existeProc(iden) == 0){
		printf("\nError Semantico en la linea %d: no existe ningun procedimiento llamado %s\n", yylineno, iden);
	}else{
		numparam = numParametros(iden);
	}
	}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 164 "sintactico.y"
    {
	if(existeProc(iden)){
		if(numParametros(iden) != argumentos){
			printf("\nError Semantico en la linea %d: El procedimiento %s admite %d parametros, pero se le pasaron %d\n", yylineno, iden, numParametros(iden), argumentos);
		}
	}
	argumentos = 1;
	numparam = 0;
	}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 174 "sintactico.y"
    {
	(yyval).numArgumentos = 1;
	
	if((yyval).numArgumentos <= numparam){
		if(tipoParametro((yyval).numArgumentos, iden) != (yyvsp[(1) - (1)]).tipo){
			printf("\nError Semantico en la linea %d: El parametro %s ha de ser de tipo %s.\n", yylineno, (yyvsp[(1) - (1)]).lexema, MostrarTipo(tipoParametro((yyval).numArgumentos, iden)));}
		}
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 181 "sintactico.y"
    {
			(yyval).numArgumentos = 1+(yyvsp[(1) - (3)]).numArgumentos;
			if((yyval).numArgumentos <= numparam){
				if(tipoParametro((yyval).numArgumentos, iden) != (yyvsp[(3) - (3)]).tipo){ 
					printf("\nError Semantico en la linea %d: El parametro %s ha de ser de tipo %s.\n", yylineno, (yyvsp[(1) - (3)]).lexema, MostrarTipo(tipoParametro((yyval).numArgumentos, iden)));
				}
			}
			argumentos++;
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 191 "sintactico.y"
    {
		
		if(existe (iden)==0){
			printf ("\nError Semantico en la linea %d: Identificador %s no esta declarado\n", yylineno, (yyvsp[(1) - (3)]).lexema);
		}else{
			iden_tipo=get_tipo (iden);
			
			if(iden_tipo!=(yyvsp[(2) - (3)]).tipo)
				printf ("\nError Semantico en la linea %d: Asignacion de tipos incompatibles, no se puede asignar un %s a un %s\n", yylineno,MostrarTipo((yyvsp[(2) - (3)]).tipo),MostrarTipo(iden_tipo));
			
		}
	}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 204 "sintactico.y"
    {
					if((yyvsp[(2) - (2)]).tipo!=booleano){
						printf ("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s \n", yylineno,MostrarTipo((yyvsp[(2) - (2)]).tipo));
					}
				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 213 "sintactico.y"
    {
	if ((yyvsp[(2) - (2)]).tipo != entero || (yyvsp[(2) - (2)]).tipo != real || (yyvsp[(2) - (2)]).tipo != caracter || (yyvsp[(2) - (2)]).tipo != booleano)
		printf("\nError Semantico en la linea %d: El tipo de %s es incompatible con la estructura CASO.\n", yylineno, (yyvsp[(2) - (2)]).lexema);
	else{ tipoAux = (yyvsp[(2) - (2)]).tipo;};
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 217 "sintactico.y"
    {
	if( (yyvsp[(4) - (5)]).tipo != (yyvsp[(2) - (5)]).tipo ){
		printf("\nError Semantico en la linea %d: El tipo de la lista de variables es incompatible con el tipo de %s\n", yylineno, (yyvsp[(2) - (5)]).lexema);
	}
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 221 "sintactico.y"
    {
	if( (yyvsp[(7) - (9)]).tipo != (yyvsp[(2) - (9)]).tipo ){
		printf("\nError Semantico en la linea %d: El tipo de la lista de variables es incompatible con el tipo de %s\n", yylineno, (yyvsp[(2) - (9)]).lexema);
	}
	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 229 "sintactico.y"
    {
		if( tipoAux != (yyvsp[(1) - (1)]).tipo){
			printf("\nError Semantico en la linea %d: El tipo de la lista de variables es incompatible\n", yylineno);
		}
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 235 "sintactico.y"
    {(yyval).tipo = (yyvsp[(1) - (1)]).tipo;}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 235 "sintactico.y"
    {(yyval).tipo = (yyvsp[(1) - (1)]).tipo;}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 235 "sintactico.y"
    {
						if((yyvsp[(2) - (3)]).tipo != (yyvsp[(1) - (3)]).tipo){
							printf("\nError Semantico en la linea %d: Se esperaba una constante del mismo tipo que %s\n", yylineno, (yyvsp[(1) - (3)]).lexema);
						}
					}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 241 "sintactico.y"
    {
	if(existe((yyvsp[(1) - (2)]).lexema)==0){
		printf("\nError Semantico en la linea %d: La variable %s no esta definida\n", yylineno, (yyvsp[(1) - (2)]).lexema);} 
	else if((yyvsp[(1) - (2)]).tipo != (yyvsp[(2) - (2)]).tipo){
		printf("\nError Semantico en la linea %d: La variable %s no es del mismo tipo que el resto de la lista\n", yylineno, (yyvsp[(1) - (2)]).lexema);} 
	else{
		(yyval).tipo = (yyvsp[(2) - (2)]).tipo;
		}
	}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 252 "sintactico.y"
    {
				if(existe((yyvsp[(2) - (3)]).lexema)==0){
					printf("\nError Semantico en la linea %d: La variable %s no esta definida\n", yylineno, (yyvsp[(2) - (3)]).lexema);} 
				else if((yyvsp[(2) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
					 printf("\nError Semantico en la linea %d: La variable %s no es del mismo tipo que el resto de la lista\n", yylineno, (yyvsp[(2) - (3)]).lexema);} 
				else{
					(yyval).tipo = (yyvsp[(2) - (3)]).tipo;}
				}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 261 "sintactico.y"
    {
						if((yyvsp[(2) - (2)]).tipo!=booleano){
							printf ("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s \n", yylineno,MostrarTipo((yyvsp[(2) - (2)]).tipo));
						}
					}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 270 "sintactico.y"
    {
		if(existe((yyvsp[(1) - (2)]).lexema)==0){
			printf("\nError Semantico en la linea %d: La variable %s no esta definida\n", yylineno, (yyvsp[(1) - (2)]).lexema);} 
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 276 "sintactico.y"
    {
		if(existe((yyvsp[(2) - (3)]).lexema)==0){
			printf("\nError Semantico en la linea %d: La variable %s no esta definida\n", yylineno, (yyvsp[(2) - (3)]).lexema);} 
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 287 "sintactico.y"
    {
				(yyval).tipo=(yyvsp[(2) - (3)]).tipo;
			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 291 "sintactico.y"
    {
				if((yyvsp[(1) - (2)]).atrib == 0){		//Operador no
					if((yyvsp[(2) - (2)]).tipo!=booleano && ((yyvsp[(2) - (2)]).atrib==0 || (yyvsp[(2) - (2)]).atrib==1)){
						printf ("\nError Semantico en la linea %d: El operador %s incompatible con tipo: %s, se esperaba boolean. \n", yylineno, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));
					}else{
						(yyval).tipo=(yyvsp[(2) - (2)]).tipo;
					}
				}else if((yyvsp[(1) - (2)]).atrib != 0){
					if(es_pila((yyvsp[(2) - (2)]).tipo) ==0 ){
						printf ("\nError Semantico en la linea %d: El operador %s incompatible con tipo: %s, se esperaba pila. \n", yylineno, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));
					}else{
						if((yyvsp[(1) - (2)]).atrib == 1)
							(yyval).tipo = (yyvsp[(2) - (2)]).tipo;
						else if((yyvsp[(1) - (2)]).atrib == 2)
							(yyval).tipo = tipoPila((yyvsp[(2) - (2)]).tipo);
						else if((yyvsp[(1) - (2)]).atrib == 3)
							(yyval).tipo = booleano;
					}
				}
			}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 312 "sintactico.y"
    {
				if(((yyvsp[(1) - (3)]).tipo==booleano || (yyvsp[(3) - (3)]).tipo==booleano) || ((yyvsp[(1) - (3)]).tipo == cadena || (yyvsp[(1) - (3)]).tipo == cadena)){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando con un booleano o cadena. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
					correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) ==1 && es_pila((yyvsp[(3) - (3)]).tipo) ==1 &&  (yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
						printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos de pila incompatibles. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) ==1 && es_pila((yyvsp[(3) - (3)]).tipo)==0 && tipoPila((yyvsp[(1) - (3)]).tipo) != (yyvsp[(3) - (3)]).tipo){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos incompatibles . \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) == 0 && es_pila((yyvsp[(3) - (3)]).tipo) ==1 && (yyvsp[(1) - (3)]).tipo != tipoPila((yyvsp[(3) - (3)]).tipo)){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos incompatibles. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo)==0 && es_pila((yyvsp[(3) - (3)]).tipo)==0 && (yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo){
					printf("\nError Semantico en la linea %d: Tipo %s incompatible con tipo %s. \n", yylineno, MostrarTipo((yyvsp[(1) - (3)]).tipo), MostrarTipo((yyvsp[(3) - (3)]).tipo));
				}
			}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 330 "sintactico.y"
    {
			if(((yyvsp[(1) - (3)]).tipo==booleano || (yyvsp[(3) - (3)]).tipo==booleano) || ((yyvsp[(1) - (3)]).tipo == cadena || (yyvsp[(1) - (3)]).tipo == cadena)){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando con un booleano o cadena. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
					correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) ==1 && es_pila((yyvsp[(3) - (3)]).tipo) ==1 &&  (yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
						printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos de pila incompatibles. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) ==1 && es_pila((yyvsp[(3) - (3)]).tipo)==0 && tipoPila((yyvsp[(1) - (3)]).tipo) != (yyvsp[(3) - (3)]).tipo){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos incompatibles . \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo) == 0 && es_pila((yyvsp[(3) - (3)]).tipo) ==1 && (yyvsp[(1) - (3)]).tipo != tipoPila((yyvsp[(3) - (3)]).tipo)){
					printf("\nError Semantico en la linea %d: El operador %s se esta utilizando entre tipos incompatibles. \n", yylineno, (yyvsp[(2) - (3)]).lexema);
						correcto = 0;
				}else if(es_pila((yyvsp[(1) - (3)]).tipo)==0 && es_pila((yyvsp[(3) - (3)]).tipo)==0 && (yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo){
					printf("\nError Semantico en la linea %d: Tipo %s incompatible con tipo %s. \n", yylineno, MostrarTipo((yyvsp[(1) - (3)]).tipo), MostrarTipo((yyvsp[(3) - (3)]).tipo));
				}
			}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 349 "sintactico.y"
    { if((yyvsp[(1) - (3)]).tipo==caracter || (yyvsp[(1) - (3)]).tipo==booleano || (yyvsp[(1) - (3)]).tipo==cadena || es_pila((yyvsp[(1) - (3)]).tipo) || (yyvsp[(3) - (3)]).tipo==caracter || (yyvsp[(3) - (3)]).tipo==booleano || (yyvsp[(3) - (3)]).tipo==cadena || es_pila((yyvsp[(3) - (3)]).tipo)){
				printf("\nError Semantico en la linea %d: El operador %s se esta utilizando como: %s%s%s,  operador incompatible . \n", yylineno, (yyvsp[(2) - (3)]).lexema, MostrarTipo((yyvsp[(1) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema, MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto = 0;
			}
			else{
				if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
					printf ("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s. \n", yylineno, MostrarTipo((yyvsp[(1) - (3)]).tipo), MostrarTipo((yyvsp[(3) - (3)]).tipo));
					correcto = 0;
				}else (yyval).tipo = booleano;
			}
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 361 "sintactico.y"
    { if(es_pila((yyvsp[(1) - (3)]).tipo) == 0){		//La primera expresion no es una pila
				printf("\nError Semantico en la linea %d: %s ha de ser de tipo pila.\n", yylineno, (yyvsp[(1) - (3)]).lexema);
				correcto = 0;
			  }else if(tipoPila((yyvsp[(1) - (3)]).tipo) != (yyvsp[(3) - (3)]).tipo){
			  	printf("\nError Semantico en la linea %d: El tipo de la pila es incompatible con el tipo de %s\n", yylineno, (yyvsp[(3) - (3)]).lexema);
			  	correcto = 0;
			  }else (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
			  
			}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 371 "sintactico.y"
    {if(((yyvsp[(1) - (3)]).tipo!=booleano)||((yyvsp[(3) - (3)]).tipo!=booleano)){
				printf("\nError Semantico en la linea %d: El operador %s se ha de utilizar con tipos booleanos . \n", yylineno, (yyvsp[(2) - (3)]).lexema);
				correcto = 0;
			}
			if(correcto==1)
				(yyval).tipo=booleano;	
			else
				correcto=1;
			}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 381 "sintactico.y"
    {if(((yyvsp[(1) - (3)]).tipo!=booleano)||((yyvsp[(3) - (3)]).tipo!=booleano)){
				printf("\nError Semantico en la linea %d: El operador %s se ha de utilizar con tipos booleanos . \n", yylineno, (yyvsp[(2) - (3)]).lexema);
				correcto = 0;
			}
			if(correcto==1)
				(yyval).tipo=booleano;	
			else
				correcto=1;
			}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 391 "sintactico.y"
    {
			if(((yyvsp[(1) - (3)]).tipo==cadena)||((yyvsp[(3) - (3)]).tipo==cadena)){
				printf("\nError Semantico en la linea %d: El operador %s se esta utilizando como: %s%s%s,  operador incompatible con cadenas y . \n", yylineno, (yyvsp[(2) - (3)]).lexema, MostrarTipo((yyvsp[(1) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema, MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto = 0;
			}
			else{
				if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
					printf ("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s. \n", yylineno, MostrarTipo((yyvsp[(1) - (3)]).tipo), MostrarTipo((yyvsp[(3) - (3)]).tipo));
					correcto = 0;
				}else{ (yyval).tipo = booleano;}
			}
			
		}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 404 "sintactico.y"
    {
			if(existe((yyvsp[(1) - (1)]).lexema)==0)
				printf("\nError Semantico en la linea %d: El identificador %s no esta declarado\n", yylineno, (yyvsp[(1) - (1)]).lexema);
			else (yyval).tipo = get_tipo((yyvsp[(1) - (1)]).lexema);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 409 "sintactico.y"
    {(yyval).tipo = (yyvsp[(1) - (1)]).tipo;}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 411 "sintactico.y"
    {(yyval).tipo = tipoEnPila((yyvsp[(1) - (1)]).tipo);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 413 "sintactico.y"
    {
				if((yyvsp[(2) - (2)]).tipo!=entero && (yyvsp[(2) - (2)]).tipo!=real){
					printf ("\nError Semantico en la linea %d: El operador %s es incompatible con tipo: %s, se esperaba entero o real. \n", yylineno, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));}
				else{
					(yyval).tipo=(yyvsp[(2) - (2)]).tipo;
				}
			}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 423 "sintactico.y"
    {tipo_pila = (yyvsp[(2) - (2)]).tipo;}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 423 "sintactico.y"
    {(yyval).tipo = tipo_pila;}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 425 "sintactico.y"
    { 
	if((yyvsp[(2) - (2)]).tipo != tipo_pila)
		printf("Error Semantico en la linea %d: La constante %s tiene un tipo diferente al resto de constantes\n", yylineno, (yyvsp[(2) - (2)]).lexema);
	}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 432 "sintactico.y"
    {asignarTipoCascada((yyvsp[(1) - (1)]).tipo);}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 432 "sintactico.y"
    {esPila();asignarTipoCascada((yyvsp[(2) - (2)]).tipo);}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 432 "sintactico.y"
    {asignarTipoCascada(desconocido);}
    break;



/* Line 1806 of yacc.c  */
#line 2130 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 434 "sintactico.y"

/** aqui incluimos el fichero generado por el 'lex'
*** que implementa la funci?n 'yylex'
**/

#ifdef DOSWINDOWS          /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

/**  se debe implementar la funci?n yyerror. En este caso
***  simplemente escribimos el mensaje de error en pantalla
**/

void yyerror( char *msg )
{
  fprintf(stderr,"\n[Linea %d]: %s\n", linea_actual, msg) ;
}

