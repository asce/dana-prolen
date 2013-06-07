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

#include "traduccion.h"

void yyerror(const char *msg) ;





/* Line 268 of yacc.c  */
#line 86 "y.tab.c"

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
#line 166 "y.tab.c"

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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

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
       0,     0,     3,     4,     8,    10,    11,    12,    13,    22,
      25,    26,    27,    28,    33,    34,    41,    42,    48,    49,
      55,    56,    60,    62,    64,    69,    76,    80,    81,    84,
      86,    88,    89,    90,    96,    97,   102,   104,   106,   109,
     111,   113,   115,   117,   119,   121,   123,   125,   127,   129,
     130,   131,   138,   142,   145,   149,   153,   157,   161,   165,
     169,   172,   174,   176,   178,   180,   182,   184,   185,   186,
     194,   195,   201,   205,   209,   211,   213,   215,   217,   221,
     222,   223,   229,   230,   231,   239,   240,   241,   247,   251,
     255,   257,   259,   261,   262,   272,   273,   274,   284,   285,
     287,   289,   293
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    -1,    41,    42,    43,    -1,     3,    -1,
      -1,    -1,    -1,     4,    44,    58,    45,    47,    46,    65,
       5,    -1,    47,    48,    -1,    -1,    -1,    -1,    49,    51,
      50,    43,    -1,    -1,    11,    28,    26,    52,    54,    25,
      -1,    -1,    11,    28,    26,    53,    25,    -1,    -1,    54,
       9,    10,    55,    57,    -1,    -1,    10,    56,    57,    -1,
       1,    -1,    28,    -1,    28,    12,    70,    13,    -1,    28,
      12,    70,     9,    70,    13,    -1,     6,    59,     7,    -1,
      -1,    59,    60,    -1,    60,    -1,     1,    -1,    -1,    -1,
      10,    61,    63,    62,     8,    -1,    -1,    63,     9,    64,
      57,    -1,    57,    -1,     1,    -1,    65,    66,    -1,    66,
      -1,    43,    -1,    67,    -1,    77,    -1,    83,    -1,    86,
      -1,    89,    -1,    71,    -1,    92,    -1,     1,    -1,    -1,
      -1,    57,    68,    31,    70,    69,     8,    -1,    26,    70,
      25,    -1,    36,    70,    -1,    70,    32,    70,    -1,    70,
      33,    70,    -1,    70,    34,    70,    -1,    70,    35,    70,
      -1,    70,    36,    70,    -1,    70,    37,    70,    -1,    38,
      70,    -1,    57,    -1,    24,    -1,    29,    -1,    30,    -1,
      75,    -1,     1,    -1,    -1,    -1,    28,    26,    72,    76,
      25,    73,     8,    -1,    -1,    28,    26,    25,    74,     8,
      -1,     4,    76,     5,    -1,    76,     9,    70,    -1,    70,
      -1,    79,    -1,    78,    -1,    80,    -1,    80,    15,    66,
      -1,    -1,    -1,    81,    14,    70,    82,    66,    -1,    -1,
      -1,    16,    26,    84,    70,    85,    25,    66,    -1,    -1,
      -1,    17,    87,    63,    88,     8,    -1,    18,    90,     8,
      -1,    90,     9,    91,    -1,    91,    -1,    70,    -1,    27,
      -1,    -1,    19,    26,    57,    93,    25,     4,    94,    98,
       5,    -1,    -1,    -1,    94,    20,    97,    22,    95,    65,
      96,    23,     8,    -1,    -1,    29,    -1,    30,    -1,    21,
      22,    65,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    59,    71,    73,    75,    85,    73,    94,
      94,    97,    99,    97,   105,   104,   118,   118,   129,   128,
     138,   137,   144,   147,   161,   187,   219,   219,   220,   221,
     221,   225,   235,   224,   246,   245,   266,   276,   278,   278,
     280,   281,   282,   283,   284,   285,   286,   287,   287,   289,
     289,   289,   312,   318,   330,   336,   346,   355,   367,   384,
     417,   425,   437,   443,   447,   451,   452,   455,   459,   454,
     470,   469,   478,   480,   490,   499,   499,   501,   503,   506,
     508,   506,   521,   526,   520,   537,   537,   537,   539,   541,
     541,   544,   551,   555,   554,   564,   569,   563,   575,   577,
     577,   579,   579
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
  "cabecera_programa", "bloque", "$@2", "$@3", "$@4", "declar_de_subprogs",
  "declar_subprog", "$@5", "$@6", "cabecera_subprograma", "$@7", "$@8",
  "declar_parametros", "$@9", "$@10", "iden",
  "declar_de_variables_locales", "variables_locales",
  "cuerpo_decla_variables", "$@11", "$@12", "lista_variables", "$@13",
  "sentencias", "sentencia", "sentencia_asignacion", "$@14", "$@15",
  "expresion", "procedimiento", "$@16", "@17", "@18", "agregados",
  "lista_expresiones", "sentencia_if", "alternativa_simple",
  "alternativa_doble", "if_expresion_sentencia", "$@19", "$@20",
  "sentencia_while", "$@21", "$@22", "sentencia_entrada", "$@23", "$@24",
  "sentencia_salida", "lista_expresiones_o_cadena", "expresion_o_cadena",
  "sentencia_case", "$@25", "casos", "$@26", "$@27", "opcion",
  "caso_por_defecto", 0
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
       0,    39,    41,    40,    42,    44,    45,    46,    43,    47,
      47,    49,    50,    48,    52,    51,    53,    51,    55,    54,
      56,    54,    54,    57,    57,    57,    58,    58,    59,    59,
      59,    61,    62,    60,    64,    63,    63,    63,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    68,
      69,    67,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    72,    73,    71,
      74,    71,    75,    76,    76,    77,    77,    78,    79,    81,
      82,    80,    84,    85,    83,    87,    88,    86,    89,    90,
      90,    91,    91,    93,    92,    95,    96,    94,    94,    97,
      97,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     0,     0,     0,     8,     2,
       0,     0,     0,     4,     0,     6,     0,     5,     0,     5,
       0,     3,     1,     1,     4,     6,     3,     0,     2,     1,
       1,     0,     0,     5,     0,     4,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     6,     3,     2,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       0,     5,     3,     3,     1,     1,     1,     1,     3,     0,
       0,     5,     0,     0,     7,     0,     0,     5,     3,     3,
       1,     1,     1,     0,     9,     0,     0,     9,     0,     1,
       1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,     0,     5,     3,    27,     0,
       6,    30,    31,     0,    29,    10,     0,    26,    28,     7,
      37,    23,    36,    32,     0,     9,     0,     0,    34,     0,
      48,     0,    85,     0,     0,    23,    40,    49,     0,    39,
      41,    46,    42,    76,    75,    77,     0,    43,    44,    45,
      47,     0,    12,    66,     0,    62,     0,    63,    64,     0,
       0,    61,     0,    65,     0,    33,    82,     0,    92,    91,
       0,    90,     0,    67,     0,     8,    38,     0,     0,     0,
       0,    74,     0,     0,    53,    60,     0,    24,     0,     0,
       0,     0,     0,     0,    35,     0,    86,    88,     0,    93,
      70,     0,     0,    78,    80,    14,    13,    72,     0,    52,
       0,    54,    55,    56,    57,    58,    59,    83,     0,    89,
       0,     0,     0,    50,     0,     0,     0,    73,    25,     0,
      87,     0,    71,    68,     0,    81,    22,    20,     0,    17,
       0,    98,     0,    51,     0,     0,    15,    84,   102,    69,
      21,    18,     0,     0,     0,     0,    99,   100,     0,     0,
      94,    19,    95,     0,     0,     0,     0,     0,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    36,     8,    15,    24,    19,    25,
      26,    80,    52,   125,   126,   138,   155,   144,    61,    10,
      13,    14,    16,    29,    23,    64,    38,    39,    40,    74,
     134,    69,    41,   101,   142,   121,    63,    82,    42,    43,
      44,    45,    46,   124,    47,    95,   129,    48,    67,   118,
      49,    70,    71,    50,   120,   148,   164,   166,   158,   154
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
    -139,    24,    15,  -139,  -139,    25,  -139,  -139,    53,     5,
    -139,  -139,  -139,     7,  -139,  -139,     4,  -139,  -139,    20,
    -139,    58,  -139,    68,   116,  -139,    63,    83,  -139,    73,
    -139,    57,  -139,    67,    59,     1,  -139,  -139,   136,  -139,
    -139,  -139,  -139,  -139,  -139,    71,    75,  -139,  -139,  -139,
    -139,    62,  -139,  -139,    83,  -139,    83,  -139,  -139,    83,
      83,  -139,     3,  -139,    64,  -139,  -139,     4,  -139,   166,
      41,  -139,    64,    81,    79,  -139,  -139,   116,    83,    88,
      25,   166,     2,   160,  -139,  -139,    83,  -139,    83,    83,
      83,    83,    83,    83,  -139,    83,    68,  -139,    67,  -139,
    -139,    83,    83,  -139,   166,    90,  -139,  -139,    83,  -139,
      10,    65,   170,    18,    21,    85,  -139,   166,   108,  -139,
      93,   115,    -5,   166,   116,     9,   100,   166,  -139,   101,
    -139,   127,  -139,  -139,   128,  -139,  -139,  -139,     0,  -139,
     116,  -139,   130,  -139,    64,   132,  -139,  -139,    52,  -139,
    -139,  -139,    50,   123,   141,    64,  -139,  -139,   129,   116,
    -139,  -139,  -139,   155,   116,   161,   134,   150,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,    -2,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   -16,  -139,
    -139,   148,  -139,  -139,    96,  -139,  -138,   -36,  -139,  -139,
    -139,   -26,  -139,  -139,  -139,  -139,  -139,    66,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,    70,  -139,  -139,  -139,  -139,  -139,  -139,  -139
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
      22,    62,    76,     7,   108,    20,    11,   107,    37,   145,
     136,   108,    86,    27,    17,    12,    87,    12,     4,   137,
     133,   163,    37,   128,     3,   146,   165,    73,    81,     6,
      83,   -11,    21,    84,    85,    88,    89,    90,    91,    92,
      93,   103,    88,    89,    90,    91,    92,    93,    94,    97,
      98,    22,   104,    91,    92,    93,    99,    92,    93,     9,
     110,    37,   111,   112,   113,   114,   115,   116,    53,   117,
      27,    54,   152,   153,    51,    81,   123,    28,   106,   156,
     157,    65,   127,    66,    53,    72,    77,    54,   135,    78,
      79,    55,    21,    56,    68,    21,    57,    58,    89,    90,
      91,    92,    93,    59,   147,    60,   100,    55,    37,    56,
     102,    21,    57,    58,   105,   -16,   130,    30,   131,    59,
       6,    60,    93,   132,    37,   139,   140,    76,   150,    76,
     -79,   141,    31,    32,    33,    34,   143,    30,   149,   161,
       6,    75,   151,    37,    35,   159,   160,    37,    37,    37,
     -79,   162,    31,    32,    33,    34,    30,   167,   168,     6,
    -101,    18,    30,    96,    35,     6,     0,   122,   119,   -79,
       0,    31,    32,    33,    34,   -79,     0,    31,    32,    33,
      34,     0,     0,    35,   -96,   109,     0,     0,     0,    35,
       0,     0,    88,    89,    90,    91,    92,    93,    88,    89,
      90,    91,    92,    93,    90,    91,    92,    93
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-139))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      16,    27,    38,     5,     9,     1,     1,     5,    24,     9,
       1,     9,     9,    12,     7,    10,    13,    10,     3,    10,
      25,   159,    38,    13,     0,    25,   164,    26,    54,     4,
      56,    11,    28,    59,    60,    32,    33,    34,    35,    36,
      37,    77,    32,    33,    34,    35,    36,    37,    64,     8,
       9,    67,    78,    35,    36,    37,    72,    36,    37,     6,
      86,    77,    88,    89,    90,    91,    92,    93,     1,    95,
      12,     4,    20,    21,    11,   101,   102,     9,    80,    29,
      30,     8,   108,    26,     1,    26,    15,     4,   124,    14,
      28,    24,    28,    26,    27,    28,    29,    30,    33,    34,
      35,    36,    37,    36,   140,    38,    25,    24,   124,    26,
      31,    28,    29,    30,    26,    25,     8,     1,    25,    36,
       4,    38,    37,     8,   140,    25,    25,   163,   144,   165,
      14,     4,    16,    17,    18,    19,     8,     1,     8,   155,
       4,     5,    10,   159,    28,    22,     5,   163,   164,   165,
      14,    22,    16,    17,    18,    19,     1,    23,     8,     4,
       5,    13,     1,    67,    28,     4,    -1,   101,    98,    14,
      -1,    16,    17,    18,    19,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    28,    23,    25,    -1,    -1,    -1,    28,
      -1,    -1,    32,    33,    34,    35,    36,    37,    32,    33,
      34,    35,    36,    37,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     3,    42,     4,    43,    44,     6,
      58,     1,    10,    59,    60,    45,    61,     7,    60,    47,
       1,    28,    57,    63,    46,    48,    49,    12,     9,    62,
       1,    16,    17,    18,    19,    28,    43,    57,    65,    66,
      67,    71,    77,    78,    79,    80,    81,    83,    86,    89,
      92,    11,    51,     1,     4,    24,    26,    29,    30,    36,
      38,    57,    70,    75,    64,     8,    26,    87,    27,    70,
      90,    91,    26,    26,    68,     5,    66,    15,    14,    28,
      50,    70,    76,    70,    70,    70,     9,    13,    32,    33,
      34,    35,    36,    37,    57,    84,    63,     8,     9,    57,
      25,    72,    31,    66,    70,    26,    43,     5,     9,    25,
      70,    70,    70,    70,    70,    70,    70,    70,    88,    91,
      93,    74,    76,    70,    82,    52,    53,    70,    13,    85,
       8,    25,     8,    25,    69,    66,     1,    10,    54,    25,
      25,     4,    73,     8,    56,     9,    25,    66,    94,     8,
      57,    10,    20,    21,    98,    55,    29,    30,    97,    22,
       5,    57,    22,    65,    95,    65,    96,    23,     8
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
    {
initTS();
  openFiles("out.c");
}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 65 "semantico.y"
    {
printf("\nAnálisis finalizado.\n");
 closeFiles(); 
return 0;
}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 73 "semantico.y"
    {IntroIniBloq();if(main_flag==0)writeFout("\n{\n");}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 75 "semantico.y"
    {
  if(main_flag==1){
    writeMain();
    main_flag=0;
  }

  if(actual_file==MAIN_FILE)
    switch_actual_file(); 
}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 85 "semantico.y"
    {
  if(actual_file==FUN_FILE && fun_level == 0)
    switch_actual_file(); 
}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 90 "semantico.y"
    {IntroFinBloq();writeFout("\n}\n");}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 97 "semantico.y"
    {iden_fun_flag=1;fun_level++;}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 99 "semantico.y"
    { subProg = 1; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 101 "semantico.y"
    { /*subProg = 0;*/ fun_level--;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 105 "semantico.y"
    {
TS_InsertaSUBPROG(&(yyvsp[(2) - (3)]));
 char str_proce_dec[255];
 sprintf(str_proce_dec,"void %s ( ",(yyvsp[(2) - (3)]).lexema);

 writeFout(str_proce_dec);
 dec_flag=1;
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 114 "semantico.y"
    {
  dec_flag=0;
  writeFout(")\n");
}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 118 "semantico.y"
    {TS_InsertaSUBPROG(&(yyvsp[(2) - (3)]));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 119 "semantico.y"
    {
  char str_proce_dec[255];
  sprintf(str_proce_dec,"void %s ()",(yyvsp[(2) - (5)]).lexema);
  writeFout(str_proce_dec);

}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 129 "semantico.y"
    {
  writeFout(",");
  writeFout(dtipo2ctipostr((yyvsp[(3) - (3)]).tipo));
  //printf("%i : %s\n",$3.tipo,dtipo2ctipostr($3.tipo));
  //getchar();
tipoTmp = (yyvsp[(3) - (3)]).tipo;

}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 136 "semantico.y"
    {/*writeFout($5.lexema);*/TS_InsertaPARAMF(&(yyvsp[(5) - (5)]));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 138 "semantico.y"
    {tipoTmp = (yyvsp[(1) - (1)]).tipo;writeFout(dtipo2ctipostr((yyvsp[(1) - (1)]).tipo));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 139 "semantico.y"
    {
   
TS_InsertaPARAMF(&(yyvsp[(3) - (3)]));

}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 148 "semantico.y"
    { 
    atributocpy(&(yyval),&(yyvsp[(1) - (1)]));
    (yyval).tipo = tipoTmp;
    if(dec_flag==1){
      if(main_flag==0)
      writeFout((yyvsp[(1) - (1)]).lexema);
      else writeGlobal((yyvsp[(1) - (1)]).lexema);
      
    }

    //en principio es lo mismo dec_flag o no ya que en sentencia se sobreescribe
}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 162 "semantico.y"
    { 
  if(dec_flag==1){
    atributocpy(&(yyval),&(yyvsp[(1) - (4)]));
    (yyval).tipo = tipoEnArray(tipoTmp);
    (yyval).dimensiones = 1;
    if(checkIndexEntero(&(yyvsp[(3) - (4)])))
      (yyval).TamDimen1 = atoi((yyvsp[(3) - (4)]).lexema); /* revisar */
    char tmp[256];
    sprintf(tmp,"%s[%i]",(yyvsp[(1) - (4)]).lexema,(yyval).TamDimen1);
    if(main_flag==0)
      writeFout(tmp);
    else writeGlobal(tmp);
    //showAtt(&$$);
    //getchar();
  }else{
    atributocpy(&(yyval),&(yyvsp[(1) - (4)]));
    (yyval).tipo = tipoEnArray(tipoTmp);
    (yyval).dimensiones = 1;
  if(checkIndexEntero(&(yyvsp[(3) - (4)])))
    (yyval).TamDimen1 = atoi((yyvsp[(3) - (4)]).lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
  }
}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 188 "semantico.y"
    { 
  if(dec_flag){
    atributocpy(&(yyval),&(yyvsp[(1) - (6)]));
    (yyval).tipo = tipoEnArray(tipoTmp);
    (yyval).dimensiones = 2;
    //if(checkIndexEntero(&$3))
    (yyval).TamDimen1 = atoi((yyvsp[(3) - (6)]).lexema); /* revisar */
    //if(checkIndexEntero(&$5))
    (yyval).TamDimen2 = atoi((yyvsp[(5) - (6)]).lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
    char tmp[256];
    sprintf(tmp,"%s[%i][%i]",(yyvsp[(1) - (6)]).lexema,(yyval).TamDimen1,(yyval).TamDimen2);
  if(main_flag==0)
    writeFout(tmp);
  else writeGlobal(tmp);

  }else{
    atributocpy(&(yyval),&(yyvsp[(1) - (6)]));
    (yyval).tipo = tipoEnArray(tipoTmp);
    (yyval).dimensiones = 2;
    //if(checkIndexEntero(&$3))
    (yyval).TamDimen1 = atoi((yyvsp[(3) - (6)]).lexema); /* revisar */
    //if(checkIndexEntero(&$5))
    (yyval).TamDimen2 = atoi((yyvsp[(5) - (6)]).lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
  }
}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 225 "semantico.y"
    {
  tipoTmp = (yyvsp[(1) - (1)]).tipo;
  dec_flag=1;
  if(main_flag==0)
    writeFout(dtipo2ctipostr((yyvsp[(1) - (1)]).tipo));
  else
    writeGlobal(dtipo2ctipostr((yyvsp[(1) - (1)]).tipo)); 

}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 235 "semantico.y"
    {
  dec_flag=0;
  if(main_flag==0)
    writeFout(";\n");
  else
    writeGlobal(";\n");

}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 246 "semantico.y"
    {
  if(dec_flag ){
    if(main_flag==0)
    writeFout(",");
    else
      writeGlobal(",");


  }
}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 257 "semantico.y"
    {
  if(dec_flag){
    TS_InsertaVAR(&(yyvsp[(4) - (4)]));
  }
  if(read_flag){
    checkScope(&(yyvsp[(4) - (4)]),&(yyvsp[(4) - (4)]));
    write_scanf(&(yyvsp[(4) - (4)]));//
  }
}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 267 "semantico.y"
    {
  if(dec_flag){
  TS_InsertaVAR(&(yyvsp[(1) - (1)]));
  }
  if(read_flag){
    checkScope(&(yyvsp[(1) - (1)]),&(yyvsp[(1) - (1)]));
    write_scanf(&(yyvsp[(1) - (1)]));//
  }
}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 286 "semantico.y"
    {checkProced(&(yyvsp[(1) - (1)]),&(yyval));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 289 "semantico.y"
    {atributocpy(&att_tmp,&(yyvsp[(1) - (1)]));checkScope(&(yyvsp[(1) - (1)]),&(yyvsp[(1) - (1)]));writeFout("{//Inicio asignacion\n"); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 289 "semantico.y"
    {
checkEqualTypeAsig(&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]));
 if(es_array((yyvsp[(1) - (4)]).tipo) && es_array((yyvsp[(4) - (4)]).tipo)){
   checkEqualDimenArray(&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]));
   writeAsigArray(&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]));
   writeFout(";\n}//Fin asignacion\n");
   //showAtt(&$1);
   //showAtt(&$4);
 }
 if(es_array((yyvsp[(1) - (4)]).tipo) && es_array((yyvsp[(4) - (4)]).tipo)==0){//Asignacion array
   writeAsigArrayPosition(&att_tmp,&(yyvsp[(4) - (4)]));
      writeFout(";\n}//Fin asignacion\n");

 
 }else if(es_array((yyvsp[(1) - (4)]).tipo)==0){//Asignacion normal
   writeFout((yyvsp[(1) - (4)]).lexema); //TODO ARRAYS
   writeFout(" = ");
   writeFout((yyvsp[(4) - (4)]).expr_tmp);
   writeFout(";\n}//Fin asignacion\n");
 }
}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 313 "semantico.y"
    {

atributocpy(&(yyval),&(yyvsp[(2) - (3)]));
//getchar
}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 318 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(2) - (2)]));
  /*AnyCheck?*/
  /* si está activo el flag de array dar error para $1.atrib=2 ( - ) */
  if(array_flag){
    checkSignArray(&(yyvsp[(1) - (2)]));//TODO
  }
  writeOpuExpr(&(yyval),(yyvsp[(1) - (2)]).lexema,&(yyvsp[(2) - (2)]));
  //TODO writeExpr
  //printf("OPU_ADD\n");
  getchar();
}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 330 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_OR(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) (yyval).tipo=desconocido;
  (yyval).lexema = "_";
  writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 336 "semantico.y"
    {
 

  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));

  if(check_OPB_AND(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) (yyval).tipo=desconocido;
  (yyval).lexema = "_";
 
  writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 346 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_IG(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)
    (yyval).tipo=desconocido;
  else
    (yyval).tipo=booleano;
  (yyval).lexema = "_";
  writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 355 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_REL(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)
    (yyval).tipo=desconocido;
  else{
    (yyval).tipo=booleano;
  }
  (yyval).lexema = "_";
 
  writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
  
}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 367 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_ADD(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0 ||checkEqualDimenArray(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)
    (yyval).tipo=desconocido;
  (yyval).lexema = "_";
  if(att_is_array(&(yyvsp[(1) - (3)]))){
    printf("Att1 es array, en linea %i\n",yylineno);
    //    writeArrayExpr(&$$,&$1,$2.lexema,&$3);
    getchar();
  }else if(att_is_array(&(yyvsp[(3) - (3)]))){
    printf("Att2 es array, en linea %i\n",yylineno);
    //writeArrayExpr(&$$,&$3,$2.lexema,&$1);
    getchar();
  }else
    writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
  //  printf("%s = %s OPB_ADD %s\n",$$.expr_tmp,$1.expr_tmp,$3.expr_tmp);
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 384 "semantico.y"
    {
  atributocpy(&(yyval),&(yyvsp[(1) - (3)]));
  if(check_OPB_MUL(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0) {(yyval).tipo=desconocido;}
  if((yyvsp[(2) - (3)]).atrib == 1){ /*  **  */
    if(checkArrayMulDimension(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0)
      {(yyval).tipo=desconocido;}
    (yyval).TamDimen1 = (yyvsp[(1) - (3)]).TamDimen1;
    (yyval).TamDimen2 = (yyvsp[(3) - (3)]).TamDimen2;
    writeMul(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
    //showAtt(&$$);
    //getchar();
  }else{
    if(checkEqualDimenArray(&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]))==0){
      (yyval).tipo=desconocido;
    }else{
      //printf("Opp entre arrays\n");
      (yyval).TamDimen1 = (yyvsp[(1) - (3)]).TamDimen1;
      (yyval).TamDimen2 = (yyvsp[(1) - (3)]).TamDimen2;
      //showAtt(&$$);getchar();
    }
  }
  (yyval).lexema = "_";
  if(att_is_array(&(yyvsp[(1) - (3)]))){;
    //printf("Att1 es array, en linea %i\n",yylineno);
    //writeArrayExpr(&$$,&$1,$2.lexema,&$3);
    //getchar();
  }else if(att_is_array(&(yyvsp[(3) - (3)]))){;
    //printf("Att2 es array, en linea %i\n",yylineno);
    //writeArrayExpr(&$$,&$3,$2.lexema,&$1);
    //getchar();
  }else
    writeExpr(&(yyval),&(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]).lexema,&(yyvsp[(3) - (3)]));
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 418 "semantico.y"
    { if(checkBoolean(&(yyvsp[(2) - (2)]))==0)
    (yyval).tipo=desconocido; 
  else (yyval).tipo=(yyvsp[(2) - (2)]).tipo;
  //TODO writeExpr
  writeOpuExpr(&(yyval),(yyvsp[(1) - (2)]).lexema,&(yyvsp[(2) - (2)]));

}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 426 "semantico.y"
    {
 checkScope(&(yyvsp[(1) - (1)]),&(yyval));
 if((yyval).dimensiones == (yyvsp[(1) - (1)]).dimensiones){
   (yyval).tipo=tipoArray((yyval).tipo);
 }//else if($$.dimensiones == $1.dimensiones+1){
   //
 //}

 // $$.expr_tmp = strdup($1.lexema); OJO ****
 
}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 438 "semantico.y"
    {
atributocpy(&(yyval),&(yyvsp[(1) - (1)])); 
 if((yyval).tipo != booleano)
   (yyval).expr_tmp = strdup((yyvsp[(1) - (1)]).lexema);
}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 444 "semantico.y"
    {
atributocpy(&(yyval),&(yyvsp[(1) - (1)])); (yyval).expr_tmp = strdup((yyvsp[(1) - (1)]).lexema);
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 448 "semantico.y"
    {
atributocpy(&(yyval),&(yyvsp[(1) - (1)])); (yyval).expr_tmp = strdup((yyvsp[(1) - (1)]).lexema);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 451 "semantico.y"
    { /*que no sea index de array o se pase a proc*/ }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 455 "semantico.y"
    {call_procedure_flag=1;

}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 459 "semantico.y"
    {
  writeFout((yyvsp[(1) - (5)]).lexema);
  writeFout("(");
  writeFout(expr_params);
  writeFout(");\n");
  expr_params[0]='\0';
call_procedure_flag=0;
 checkCallProc(&(yyvsp[(1) - (5)]),&(yyval));

}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 470 "semantico.y"
    {
  writeFout((yyvsp[(1) - (3)]).lexema);
  writeFout("();");
checkCallProcWithoutArgs(&(yyvsp[(1) - (3)]),&(yyval));

}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 481 "semantico.y"
    {if(call_procedure_flag){
    linkAtt(&(yyvsp[(3) - (3)]));
    strcat(expr_params,",");//
    strcat(expr_params,(yyvsp[(3) - (3)]).expr_tmp);//

    //writeFout(",");
    //writeFout($3.expr_tmp);
  }
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 491 "semantico.y"
    {if(call_procedure_flag){
    linkAtt(&(yyvsp[(1) - (1)]));
    strcat(expr_params,(yyvsp[(1) - (1)]).expr_tmp);//
    //writeFout($1.expr_tmp);
  }
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 499 "semantico.y"
    {write_close_if();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 499 "semantico.y"
    {write_close_if();}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 501 "semantico.y"
    {writeFout("} //Fin Sentencia IF\n");}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 503 "semantico.y"
    {writeFout("} //Fin Sentencia IF-ELSE\n");}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 506 "semantico.y"
    {writeFout("{ //Sentencia IF\n");}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 508 "semantico.y"
    {
  write_init_if();
  write_conditional_jump_to_else_tag(&(yyvsp[(3) - (3)]));
checkBoolean(&(yyvsp[(3) - (3)]));
}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 514 "semantico.y"
    {
write_go_to_exit_tag();
write_else_tag();
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 521 "semantico.y"
    { 
write_init_while();
 write_entry_tag();
}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 526 "semantico.y"
    {
  write_conditional_jump_to_exit(&(yyvsp[(4) - (4)]));
checkBoolean(&(yyvsp[(4) - (4)]));
}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 531 "semantico.y"
    {
  write_go_to_entry_tag();
  write_close_while();
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 537 "semantico.y"
    {read_flag = 1;}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 537 "semantico.y"
    {read_flag = 0;}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 544 "semantico.y"
    {
  //checkScope(&$1,&$1);
write_printf(&(yyvsp[(1) - (1)])); // TODO OJO, TESTEAR
//SOLO iden??
  //nuevo OJO
  

}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 551 "semantico.y"
    {write_printf_str(&(yyvsp[(1) - (1)]));}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 555 "semantico.y"
    {
checkScope(&(yyvsp[(3) - (3)]),&(yyvsp[(3) - (3)]));
checkIntOrChar(&(yyvsp[(3) - (3)]));
write_init_switch(&(yyvsp[(3) - (3)]));
}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 560 "semantico.y"
    {write_exit_switch();}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 564 "semantico.y"
    {
  write_init_case();
  write_compare_case(&(yyvsp[(3) - (4)]));
}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 569 "semantico.y"
    {
  write_go_to_exit_switch();
  write_exit_case_tag();
  write_close_case();

}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 579 "semantico.y"
    {/* popTSIC();*/}
    break;



/* Line 1806 of yacc.c  */
#line 2378 "y.tab.c"
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
#line 582 "semantico.y"


#include "lex.yy.c"


void yyerror( const char *msg )
{
	printf("\nLinea %d: ERROR-> %s\n", yylineno, msg);
	

}

