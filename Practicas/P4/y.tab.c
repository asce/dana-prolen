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
#line 1 "semantico.y"


#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "tablaSimbolos.h"


void yyerror(const char *msg) ;





/* Line 268 of yacc.c  */
#line 87 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     MAIN = 258,
     INICIO = 259,
     FINBLO = 260,
     INICIOV = 261,
     FINV = 262,
     PYC = 263,
     COMA = 264,
     TIPOSIMPLE = 265,
     PROCED = 266,
     CORIZ = 267,
     CORDER = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     READ = 272,
     WRITE = 273,
     SWITCH = 274,
     CASE = 275,
     DEFAULT = 276,
     DOSP = 277,
     BREAK = 278,
     CONSTANTE = 279,
     PARDER = 280,
     PARIZ = 281,
     CADENA = 282,
     IDENTIFICADOR = 283,
     CONSTANTE_E = 284,
     CARACTER = 285,
     ASIG = 286,
     OPB_OR = 287,
     OPB_AND = 288,
     OPB_IG = 289,
     OPB_REL = 290,
     OPB_ADD = 291,
     OPB_MUL = 292,
     OPU = 293
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
#line 167 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    10,    11,    12,    20,    23,
      24,    25,    29,    30,    37,    38,    44,    45,    51,    52,
      56,    58,    60,    65,    72,    76,    77,    80,    82,    84,
      85,    86,    92,    96,    98,   100,   103,   105,   107,   109,
     111,   113,   115,   117,   119,   121,   123,   124,   125,   132,
     136,   139,   143,   147,   151,   155,   159,   163,   166,   167,
     170,   172,   174,   176,   178,   180,   181,   182,   190,   191,
     197,   201,   205,   207,   209,   211,   213,   217,   218,   223,
     224,   231,   235,   239,   243,   245,   247,   249,   258,   266,
     267,   269,   271,   275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    -1,    41,    42,    43,    -1,     3,    -1,
      -1,    -1,     4,    44,    56,    45,    46,    62,     5,    -1,
      46,    47,    -1,    -1,    -1,    49,    48,    43,    -1,    -1,
      11,    28,    26,    50,    52,    25,    -1,    -1,    11,    28,
      26,    51,    25,    -1,    -1,    52,     9,    10,    53,    55,
      -1,    -1,    10,    54,    55,    -1,     1,    -1,    28,    -1,
      28,    12,    67,    13,    -1,    28,    12,    67,     9,    67,
      13,    -1,     6,    57,     7,    -1,    -1,    57,    58,    -1,
      58,    -1,     1,    -1,    -1,    -1,    10,    59,    61,    60,
       8,    -1,    61,     9,    55,    -1,    55,    -1,     1,    -1,
      62,    63,    -1,    63,    -1,    43,    -1,    64,    -1,    75,
      -1,    80,    -1,    82,    -1,    83,    -1,    69,    -1,    86,
      -1,     1,    -1,    -1,    -1,    55,    65,    31,    67,    66,
       8,    -1,    26,    67,    25,    -1,    36,    67,    -1,    67,
      32,    67,    -1,    67,    33,    67,    -1,    67,    34,    67,
      -1,    67,    35,    67,    -1,    67,    36,    67,    -1,    67,
      37,    67,    -1,    38,    67,    -1,    -1,    55,    68,    -1,
      24,    -1,    29,    -1,    30,    -1,    73,    -1,     1,    -1,
      -1,    -1,    28,    26,    70,    74,    25,    71,     8,    -1,
      -1,    28,    26,    25,    72,     8,    -1,     4,    74,     5,
      -1,    74,     9,    67,    -1,    67,    -1,    77,    -1,    76,
      -1,    78,    -1,    78,    15,    63,    -1,    -1,    14,    67,
      79,    63,    -1,    -1,    16,    26,    67,    81,    25,    63,
      -1,    17,    61,     8,    -1,    18,    84,     8,    -1,    84,
       9,    85,    -1,    85,    -1,    67,    -1,    27,    -1,    19,
      26,    28,    25,     4,    87,    89,     5,    -1,    87,    20,
      88,    22,    62,    23,     8,    -1,    -1,    29,    -1,    30,
      -1,    21,    22,    62,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    59,    61,    63,    64,    63,    71,    71,
      73,    73,    77,    77,    78,    78,    80,    80,    81,    81,
      82,    85,    91,   101,   114,   114,   115,   116,   116,   118,
     118,   118,   120,   120,   120,   122,   122,   124,   125,   126,
     127,   128,   129,   130,   131,   131,   133,   133,   133,   135,
     136,   145,   150,   155,   160,   169,   174,   184,   189,   189,
     198,   199,   200,   201,   202,   205,   211,   204,   217,   217,
     220,   222,   227,   234,   234,   236,   238,   240,   240,   242,
     242,   244,   246,   248,   248,   250,   250,   252,   254,   254,
     256,   256,   258,   258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "INICIO", "FINBLO", "INICIOV",
  "FINV", "PYC", "COMA", "TIPOSIMPLE", "PROCED", "CORIZ", "CORDER", "IF",
  "ELSE", "WHILE", "READ", "WRITE", "SWITCH", "CASE", "DEFAULT", "DOSP",
  "BREAK", "CONSTANTE", "PARDER", "PARIZ", "CADENA", "IDENTIFICADOR",
  "CONSTANTE_E", "CARACTER", "ASIG", "OPB_OR", "OPB_AND", "OPB_IG",
  "OPB_REL", "OPB_ADD", "OPB_MUL", "OPU", "$accept", "programa", "$@1",
  "cabecera_programa", "bloque", "$@2", "$@3", "declar_de_subprogs",
  "declar_subprog", "$@4", "cabecera_subprograma", "$@5", "$@6",
  "declar_parametros", "$@7", "$@8", "iden", "declar_de_variables_locales",
  "variables_locales", "cuerpo_decla_variables", "$@9", "$@10",
  "lista_variables", "sentencias", "sentencia", "sentencia_asignacion",
  "$@11", "$@12", "expresion", "@13", "procedimiento", "$@14", "$@15",
  "$@16", "agregados", "lista_expresiones", "sentencia_if",
  "alternativa_simple", "alternativa_doble", "if_expresion_sentencia",
  "$@17", "sentencia_while", "$@18", "sentencia_entrada",
  "sentencia_salida", "lista_expresiones_o_cadena", "expresion_o_cadena",
  "sentencia_case", "casos", "opcion", "caso_por_defecto", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    41,    40,    42,    44,    45,    43,    46,    46,
      48,    47,    50,    49,    51,    49,    53,    52,    54,    52,
      52,    55,    55,    55,    56,    56,    57,    57,    57,    59,
      60,    58,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    65,    66,    64,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    67,
      67,    67,    67,    67,    67,    70,    71,    69,    72,    69,
      73,    74,    74,    75,    75,    76,    77,    79,    78,    81,
      80,    82,    83,    84,    84,    85,    85,    86,    87,    87,
      88,    88,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     0,     0,     7,     2,     0,
       0,     3,     0,     6,     0,     5,     0,     5,     0,     3,
       1,     1,     4,     6,     3,     0,     2,     1,     1,     0,
       0,     5,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     6,     3,
       2,     3,     3,     3,     3,     3,     3,     2,     0,     2,
       1,     1,     1,     1,     1,     0,     0,     7,     0,     5,
       3,     3,     1,     1,     1,     1,     3,     0,     4,     0,
       6,     3,     3,     3,     1,     1,     1,     8,     7,     0,
       1,     1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,     0,     5,     3,    25,     0,
       6,    28,    29,     0,    27,     9,     0,    24,    26,     0,
      34,    21,    33,    30,    45,     0,     0,     0,     0,     0,
       0,    21,    37,     8,    10,    46,     0,    36,    38,    43,
      39,    74,    73,    75,    40,    41,    42,    44,     0,     0,
       0,     0,    64,     0,    60,     0,    61,    62,     0,     0,
      58,    77,    63,     0,     0,    86,    85,     0,    84,     0,
      65,     0,     0,     7,    35,     0,     0,    32,    31,    12,
      72,     0,     0,    50,    57,    59,     0,     0,     0,     0,
       0,     0,     0,    79,    81,    82,     0,     0,    68,     0,
      11,     0,    76,     0,    22,     0,     0,    70,     0,    49,
      51,    52,    53,    54,    55,    56,    78,     0,    83,     0,
       0,     0,    47,     0,    20,    18,     0,    15,    71,     0,
      89,    69,    66,     0,    23,     0,     0,    13,    80,    93,
       0,    48,    19,    16,     0,     0,     0,    67,     0,    90,
      91,     0,     0,    87,    17,     0,     0,     0,     0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    32,     8,    15,    19,    33,    71,
      34,   105,   106,   126,   148,   135,    60,    10,    13,    14,
      16,    50,    23,    36,    37,    38,    72,   133,    66,    85,
      39,    99,   140,   120,    62,    81,    40,    41,    42,    43,
      92,    44,   117,    45,    46,    67,    68,    47,   139,   151,
     146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -84
static const yytype_int16 yypact[] =
{
     -84,    11,    35,   -84,   -84,     5,   -84,   -84,    24,     6,
     -84,   -84,   -84,    61,   -84,   -84,     4,   -84,   -84,   133,
     -84,    42,   -84,    51,   -84,    45,    57,    54,     4,    17,
      56,    30,   -84,   -84,   -84,   -84,     9,   -84,   -84,   -84,
     -84,   -84,   -84,    97,   -84,   -84,   -84,   -84,    57,    92,
     115,    99,   -84,    57,   -84,    57,   -84,   -84,    57,    57,
     -84,   158,   -84,    57,   101,   -84,   158,   122,   -84,   105,
     118,     5,   104,   -84,   -84,   161,    65,   -84,   -84,   121,
     158,    10,    71,   -84,   -84,   -84,    57,    57,    57,    57,
      57,    57,   161,   158,   -84,   -84,    17,   123,   -84,    57,
     -84,    57,   -84,    57,   -84,     7,   131,   -84,    57,   -84,
      55,    14,    81,   117,   136,   -84,   -84,   143,   -84,   166,
     168,    -3,   158,   150,   -84,   -84,    27,   -84,   158,   161,
     -84,   -84,   -84,   173,   -84,    92,   164,   -84,   -84,   146,
     180,   -84,   -84,   -84,   142,   174,   192,   -84,    92,   -84,
     -84,   176,   161,   -84,   -84,   161,   110,   141,   191,   -84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -84,    -1,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -16,   -84,   -84,   187,
     -84,   -84,   175,   -83,   -35,   -84,   -84,   -84,   -24,   -84,
     -84,   -84,   -84,   -84,   -84,   102,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   106,   -84,   -84,   -84,
     -84
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      22,    74,    61,    35,     7,    20,   108,    11,   124,     6,
      24,     3,    22,     6,    73,   107,    12,   125,    52,   108,
      35,    53,   132,    26,    76,    27,    28,    29,    30,    80,
       9,    82,    21,    77,    83,    84,   136,    31,     4,    93,
     102,    54,    48,    55,    65,    21,    56,    57,    88,    89,
      90,    91,   137,    58,    48,    59,    70,   116,    52,    35,
      49,    53,   110,   111,   112,   113,   114,   115,    17,   156,
     100,    12,   157,    51,   103,    80,    35,   122,   104,   123,
      63,    54,    69,    55,   128,    21,    56,    57,    87,    88,
      89,    90,    91,    58,   138,    59,   109,    86,    87,    88,
      89,    90,    91,    86,    87,    88,    89,    90,    91,    94,
      49,    24,    75,    35,     6,   -92,    89,    90,    91,   142,
      21,    74,    74,    78,    26,    79,    27,    28,    29,    30,
      95,    96,   154,    97,    24,   101,    35,     6,    31,    35,
      35,    35,    24,    98,    25,     6,   -14,    26,   119,    27,
      28,    29,    30,    90,    91,    26,   127,    27,    28,    29,
      30,    31,    24,   134,   158,     6,   144,   145,   129,    31,
     130,   149,   150,    91,   143,    26,   131,    27,    28,    29,
      30,   141,    86,    87,    88,    89,    90,    91,   147,    31,
      86,    87,    88,    89,    90,    91,   152,   153,   155,   159,
      18,   121,   118,    64
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-84))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      16,    36,    26,    19,     5,     1,     9,     1,     1,     4,
       1,     0,    28,     4,     5,     5,    10,    10,     1,     9,
      36,     4,    25,    14,    48,    16,    17,    18,    19,    53,
       6,    55,    28,    49,    58,    59,     9,    28,     3,    63,
      75,    24,    12,    26,    27,    28,    29,    30,    34,    35,
      36,    37,    25,    36,    12,    38,    26,    92,     1,    75,
       9,     4,    86,    87,    88,    89,    90,    91,     7,   152,
      71,    10,   155,    28,     9,    99,    92,   101,    13,   103,
      26,    24,    26,    26,   108,    28,    29,    30,    33,    34,
      35,    36,    37,    36,   129,    38,    25,    32,    33,    34,
      35,    36,    37,    32,    33,    34,    35,    36,    37,     8,
       9,     1,    15,   129,     4,     5,    35,    36,    37,   135,
      28,   156,   157,     8,    14,    26,    16,    17,    18,    19,
       8,     9,   148,    28,     1,    31,   152,     4,    28,   155,
     156,   157,     1,    25,    11,     4,    25,    14,    25,    16,
      17,    18,    19,    36,    37,    14,    25,    16,    17,    18,
      19,    28,     1,    13,    23,     4,    20,    21,    25,    28,
       4,    29,    30,    37,    10,    14,     8,    16,    17,    18,
      19,     8,    32,    33,    34,    35,    36,    37,     8,    28,
      32,    33,    34,    35,    36,    37,    22,     5,    22,     8,
      13,    99,    96,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     3,    42,     4,    43,    44,     6,
      56,     1,    10,    57,    58,    45,    59,     7,    58,    46,
       1,    28,    55,    61,     1,    11,    14,    16,    17,    18,
      19,    28,    43,    47,    49,    55,    62,    63,    64,    69,
      75,    76,    77,    78,    80,    82,    83,    86,    12,     9,
      60,    28,     1,     4,    24,    26,    29,    30,    36,    38,
      55,    67,    73,    26,    61,    27,    67,    84,    85,    26,
      26,    48,    65,     5,    63,    15,    67,    55,     8,    26,
      67,    74,    67,    67,    67,    68,    32,    33,    34,    35,
      36,    37,    79,    67,     8,     8,     9,    28,    25,    70,
      43,    31,    63,     9,    13,    50,    51,     5,     9,    25,
      67,    67,    67,    67,    67,    67,    63,    81,    85,    25,
      72,    74,    67,    67,     1,    10,    52,    25,    67,    25,
       4,     8,    25,    66,    13,    54,     9,    25,    63,    87,
      71,     8,    55,    10,    20,    21,    89,     8,    53,    29,
      30,    88,    22,     5,    55,    22,    62,    62,    23,     8
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
        case 2:

/* Line 1806 of yacc.c  */
#line 59 "semantico.y"
    {initTS();}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 59 "semantico.y"
    {printf("\nAnálisis finalizado.\n"); return 0;}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 63 "semantico.y"
    {IntroIniBloq();}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 64 "semantico.y"
    {/*showNewBlock();*/}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 67 "semantico.y"
    {IntroFinBloq();}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 73 "semantico.y"
    { subProg = 1; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 74 "semantico.y"
    { /*subProg = 0;*/ }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 77 "semantico.y"
    {TS_InsertaSUBPROG(&(yyvsp[(2) - (3)]));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 78 "semantico.y"
    {TS_InsertaSUBPROG(&(yyvsp[(2) - (3)]));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 80 "semantico.y"
    {tipoTmp = (yyvsp[(3) - (3)]).tipo;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 80 "semantico.y"
    {TS_InsertaPARAMF(&(yyvsp[(5) - (5)]));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 81 "semantico.y"
    {tipoTmp = (yyvsp[(1) - (1)]).tipo;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 81 "semantico.y"
    {TS_InsertaPARAMF(&(yyvsp[(3) - (3)]));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 86 "semantico.y"
    { 
    atributocpy(&(yyval),&(yyvsp[(1) - (1)]));
    (yyval).tipo = tipoTmp;
}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 92 "semantico.y"
    { 
  atributocpy(&(yyval),&(yyvsp[(1) - (4)]));
  (yyval).tipo = tipoEnArray(tipoTmp);
  (yyval).dimensiones = 1;
  if(checkIndexEntero(&(yyvsp[(4) - (4)])))
    (yyval).TamDimen1 = atoi((yyvsp[(4) - (4)]).lexema); /* revisar */
  
}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 102 "semantico.y"
    { 
  atributocpy(&(yyval),&(yyvsp[(1) - (6)]));
  (yyval).tipo = tipoEnArray(tipoTmp);
  (yyval).dimensiones = 2;
  if(checkIndexEntero(&(yyvsp[(4) - (6)])))
    (yyval).TamDimen1 = atoi((yyvsp[(4) - (6)]).lexema); /* revisar */
  if(checkIndexEntero(&(yyvsp[(6) - (6)])))
    (yyval).TamDimen2 = atoi((yyvsp[(6) - (6)]).lexema); /* revisar */
  
}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 118 "semantico.y"
    {tipoTmp = (yyvsp[(1) - (1)]).tipo;dec_flag=1;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 118 "semantico.y"
    {dec_flag=0;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 120 "semantico.y"
    {if(dec_flag)TS_InsertaVAR(&(yyvsp[(3) - (3)]));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 120 "semantico.y"
    {if(dec_flag)TS_InsertaVAR(&(yyvsp[(1) - (1)]));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 130 "semantico.y"
    {checkProced(&(yyvsp[(1) - (1)]));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 133 "semantico.y"
    {checkScope(&(yyvsp[(1) - (1)])); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 133 "semantico.y"
    {checkEqualTypeAsig(&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 135 "semantico.y"
    {atributocpy(&(yyval),&(yyvsp[(2) - (3)]));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 136 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(2) - (2)]));
  /*AnyCheck?*/
  /* si está activo el flag de array dar error para $1.atrib=2 ( - ) */
  if(array_flag){
    checkSignArray(&(yyvsp[(1) - (2)]));
  }

}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 145 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_OR(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) (yyval).tipo=desconocido;
  (yyval).lexema = "_";
}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 150 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_AND(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) (yyval).tipo=desconocido;
  (yyval).lexema = "_";
}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 155 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_IG(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)(yyval).tipo=desconocido;
  (yyval).lexema = "_";
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 160 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_REL(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)
    (yyval).tipo=desconocido;
  else{
    (yyval).tipo=booleano;
  }
  (yyval).lexema = "_";
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 169 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_ADD(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)(yyval).tipo=desconocido;
  (yyval).lexema = "_";
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 174 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_MUL(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) {(yyval).tipo=desconocido;}
  if((yyvsp[(2) - (3)]).atrib == 1){ /*  **  */
    if(checkArrayMulDimension(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0){(yyval).tipo=desconocido;}
  }else{
    if(checkEqualDimenArray(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)(yyval).tipo=desconocido;
  }
  (yyval).lexema = "_";
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 185 "semantico.y"
    { if(checkBoolean(&(yyvsp[(2) - (2)]))==0)
    (yyval).tipo=desconocido; 
  else (yyval).tipo=(yyvsp[(2) - (2)]).tipo;
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 189 "semantico.y"
    {atributocpy(&(yyval),&(yyvsp[(1) - (1)]));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 190 "semantico.y"
    {
scope_index_TS = checkScope(&(yyvsp[(1) - (2)])); 
 if(scope_index_TS){
   getAttFromTS(&(yyval),scope_index_TS);
 }
 else
   (yyval).tipo = desconocido;
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 198 "semantico.y"
    {atributocpy(&(yyval),&(yyvsp[(1) - (1)]));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 199 "semantico.y"
    {atributocpy(&(yyval),&(yyvsp[(1) - (1)]));}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 200 "semantico.y"
    {atributocpy(&(yyval),&(yyvsp[(1) - (1)]));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 201 "semantico.y"
    { /*que no sea index de array o se pase a proc*/ }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 205 "semantico.y"
    {call_procedure_flag=1;
  /* initAttList(&att_list);*/
  /*atributocpy(&att_list.att,&$1);*/
  /*procedure_att_end_pointer = &att_list;*/
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 211 "semantico.y"
    {
call_procedure_flag=0;
checkCallProc(&(yyvsp[(1) - (5)]));
//deleteAttList();
// showTS();
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 217 "semantico.y"
    {checkCallProcWithoutArgs(&(yyvsp[(1) - (3)]));showTS();}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 223 "semantico.y"
    {if(call_procedure_flag){
    linkAtt(&(yyvsp[(3) - (3)]));
  }
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 228 "semantico.y"
    {if(call_procedure_flag){
    linkAtt(&(yyvsp[(1) - (1)]));
  }
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 240 "semantico.y"
    {checkBoolean(&(yyvsp[(2) - (2)]));}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 242 "semantico.y"
    {checkBoolean(&(yyvsp[(3) - (3)]));}
    break;



/* Line 1806 of yacc.c  */
#line 1956 "y.tab.c"
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
#line 261 "semantico.y"


#include "lex.yy.c"


void yyerror( const char *msg )
{
	printf("\nLinea %d: ERROR-> %s\n", yylineno, msg);
	

}

