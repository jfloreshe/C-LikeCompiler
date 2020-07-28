/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "MINICa.Y" /* yacc.c:339  */


#include<stdio.h>
#include<ctype.h>
#include<string.h>

int yylex();
typedef union { int entero;
		float real;
		} tipovalor;
void IS(int , int);
char lexema[80];
typedef struct {char nombre[30];
		int a1,a2;  	// a1: INT/FLOAT	a2: FUN/VAR
		tipovalor a3; 	// guarda valor
	} tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;
int insertaSimbolo(char *, int);
int localizaSimbolo(char *);
void muestraSimbolo();
int tipoVar;

// Definici�n de la tabla de c�digo

typedef struct { int op,a1,a2,a3;}
	tipoCodigo;

tipoCodigo TABCOD[100];
int cx = -1; 		// indice de c�digo actual
int indicevartemp = 0;  	//n�mero de variables temporales
void genCodigo(int ,int ,int ,int );
int genvartemp();
void muestraCodigo();

void interprete();

// Definici�n de las operaciones de lenguaje intermedio

#define MOVER	1
#define SUMAR	2
#define SALTAR	3
#define SALTARV	4
#define SALTARF	5
#define MENOR	6
#define RESTAR       7 
#define MULTIPLICAR  8
#define DIVIDIR      9
#define MAYOR 		10




#line 121 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    FORMATO = 260,
    ID = 261,
    IF = 262,
    ELSE = 263,
    NUM = 264,
    REAL = 265,
    WHILE = 266,
    DO = 267,
    FOR = 268,
    FUNCION = 269,
    LEENUM = 270,
    IMPRINUM = 271,
    CENTERO = 272,
    CFLOAT = 273,
    VAR = 274,
    OR = 275,
    AND = 276,
    NOT = 277,
    IGUAL = 278,
    NOIGUAL = 279,
    MENORIGUAL = 280,
    MAYORIGUAL = 281
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define FORMATO 260
#define ID 261
#define IF 262
#define ELSE 263
#define NUM 264
#define REAL 265
#define WHILE 266
#define DO 267
#define FOR 268
#define FUNCION 269
#define LEENUM 270
#define IMPRINUM 271
#define CENTERO 272
#define CFLOAT 273
#define VAR 274
#define OR 275
#define AND 276
#define NOT 277
#define IGUAL 278
#define NOIGUAL 279
#define MENORIGUAL 280
#define MAYORIGUAL 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    33,    31,    38,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    35,
      29,    20,    30,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    22,    23,    24,    25,    26,
      27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    75,    75,    76,    78,    78,    79,    79,
      82,    82,    82,    83,    83,    83,    84,    85,    85,    86,
      86,    87,    88,    91,    95,    91,   102,   102,   105,   105,
     105,   112,   112,   113,   114,   114,   116,   112,   123,   124,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   141,   142,   141,   144,   145,
     146,   147,   147,   148,   149
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "FORMATO", "ID", "IF",
  "ELSE", "NUM", "REAL", "WHILE", "DO", "FOR", "FUNCION", "LEENUM",
  "IMPRINUM", "CENTERO", "CFLOAT", "VAR", "'='", "'?'", "OR", "AND", "NOT",
  "IGUAL", "NOIGUAL", "MENORIGUAL", "MAYORIGUAL", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "';'", "'('", "')'", "','", "'{'", "'}'", "':'",
  "'['", "']'", "$accept", "programaC", "listaDeclC", "declC", "$@1",
  "Tipo", "listaVar", "$@2", "listaPar", "$@3", "bloque", "listaVarLoc",
  "listaProp", "prop", "@4", "@5", "propif", "@6", "@7", "@8", "@9", "@10",
  "@11", "@12", "$@13", "@14", "expr", "@15", "@16", "@17", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,    63,   275,   276,   277,   278,   279,   280,   281,    60,
      62,    43,    45,    42,    47,    59,    40,    41,    44,   123,
     125,    58,    91,    93
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,     7,    51,   -89,   -89,   -89,   -89,     5,    13,    -5,
     -89,   -89,   -89,    51,    28,    31,    19,    12,   -89,    33,
      23,    27,    51,   -89,    51,    28,   -89,   -89,    44,    29,
      51,   -14,    30,   -89,   -89,    46,    47,    48,    49,    37,
     -89,   -89,   -89,   -89,   159,   -89,   -89,    37,    37,   -89,
      37,    67,    37,   195,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    66,    37,    80,   116,
      37,   172,   -89,   129,   185,   195,   -29,   -29,   -29,   -29,
     -29,   -29,    25,    25,   -89,   -89,    37,   159,    68,   -89,
     142,   -89,    54,   -89,    99,    37,    65,   -89,    37,   -89,
      45,   159,   -89,    65,   159,    37,    84,   -89,   -89,   159,
      23,   -89,    58,   -89,   -89,    37,   159,    57,   -89,    65,
     -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     8,     9,     3,     0,    12,     0,
       6,    10,     5,     0,     0,     0,     0,    12,    11,    13,
       0,     0,    17,     7,     0,     0,    20,    14,     0,     0,
      17,    58,     0,    59,    60,     0,     0,     0,     0,     0,
      21,    16,    22,    19,    41,    18,    61,     0,     0,    28,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    55,
       0,    55,    39,    55,    42,    43,    45,    46,    49,    50,
      47,    48,    51,    52,    53,    54,     0,    62,    63,    23,
      55,    31,     0,    38,    55,     0,     0,    29,     0,    40,
       0,    64,    24,     0,    32,     0,    26,    30,    33,    57,
       0,    25,     0,    27,    34,     0,    35,     0,    36,     0,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,    11,    38,   -89,    71,   -89,
     -20,    69,   -89,   -88,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -38,   -89,   -89,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,    13,    15,     9,    14,    16,    21,
      42,    26,    29,    43,    96,   106,   111,    70,   103,    98,
     108,   112,   115,   117,   119,    92,    44,    66,   100,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    53,    62,    63,    64,    65,    46,     3,   102,    68,
      69,     8,    71,     7,    73,   107,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    47,    87,
      12,   120,    90,    25,    17,    31,    32,    19,    33,    34,
      35,    25,    36,    31,    37,    38,    33,    34,    94,    10,
      11,    11,    18,    39,     4,     5,    20,   101,    64,    65,
     104,    39,    22,    28,    40,    24,    48,   109,    22,    41,
     -15,    31,    32,    72,    33,    34,    35,   116,    36,    30,
      37,    38,    49,    50,    51,    52,   105,    86,    95,    39,
     113,    99,   110,   114,   118,    27,     0,     0,     0,    45,
      40,     0,    54,    55,    22,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    54,    55,    88,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    54,    55,
     -56,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    54,    55,    89,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    54,    55,    93,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    97,
     -55,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    91,    55,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

static const yytype_int8 yycheck[] =
{
      20,    39,    31,    32,    33,    34,    20,     0,    96,    47,
      48,     6,    50,     2,    52,   103,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    42,    67,
      35,   119,    70,    22,     6,     6,     7,     6,     9,    10,
      11,    30,    13,     6,    15,    16,     9,    10,    86,    36,
      38,    38,    14,    24,     3,     4,    37,    95,    33,    34,
      98,    24,    39,    25,    35,    38,    36,   105,    39,    40,
      37,     6,     7,     6,     9,    10,    11,   115,    13,    35,
      15,    16,    36,    36,    36,    36,    41,    21,    20,    24,
     110,    37,     8,    35,    37,    24,    -1,    -1,    -1,    30,
      35,    -1,    22,    23,    39,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    43,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    22,    23,
      41,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    22,    23,    37,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    22,    23,    37,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    37,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     3,     4,    47,    49,     6,    50,
      36,    38,    35,    48,    51,    49,    52,     6,    50,     6,
      37,    53,    39,    54,    38,    49,    55,    52,    50,    56,
      35,     6,     7,     9,    10,    11,    13,    15,    16,    24,
      35,    40,    54,    57,    70,    55,    20,    42,    36,    36,
      36,    36,    36,    70,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    71,    73,    70,    70,
      61,    70,     6,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    21,    70,    43,    37,
      70,    35,    69,    37,    70,    20,    58,    37,    63,    37,
      72,    70,    57,    62,    70,    41,    59,    57,    64,    70,
       8,    60,    65,    54,    35,    66,    70,    67,    37,    68,
      57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    47,    49,    49,
      51,    50,    50,    53,    52,    52,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    57,    60,    60,    61,    62,
      57,    63,    64,    65,    66,    67,    68,    57,    57,    69,
      57,    57,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    72,    70,    70,    70,
      70,    73,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     0,     7,     1,     1,
       0,     4,     1,     0,     5,     2,     4,     0,     4,     2,
       0,     1,     1,     0,     0,     8,     0,     2,     0,     0,
       7,     0,     0,     0,     0,     0,     0,    15,     4,     0,
       5,     1,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     0,     7,     1,     1,
       1,     0,     4,     4,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 78 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-2]),FUNCION);}
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 82 "MINICa.Y" /* yacc.c:1646  */
    { IS(tipoVar,VAR); }
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "MINICa.Y" /* yacc.c:1646  */
    { IS(tipoVar,VAR); }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-1]),VAR); }
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 83 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-1]),VAR); }
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 91 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); 
								(yyval) = cx; 
								}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 95 "MINICa.Y" /* yacc.c:1646  */
    { TABCOD[(yyvsp[-1])].a3 = cx + 1;
									genCodigo(SALTARV,(yyvsp[-3]),0,-1);
									(yyval) = cx;
								}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 99 "MINICa.Y" /* yacc.c:1646  */
    { TABCOD[(yyvsp[-1])].a3 = cx + 1;}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 102 "MINICa.Y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 105 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); /* Destino no resuelto */
	   						                         (yyval) = cx; /* Falta llenar cuarto componente de este salto */}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTAR,0,0,(yyvsp[-4])); /* Ir al comienzo de la expresi�n */
							                         TABCOD[(yyvsp[-1])].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 112 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 112 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARV,(yyvsp[0]),0,-1); (yyval) =cx;}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 113 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); (yyval)=cx;}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 114 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 114 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTAR,0,0,(yyvsp[-6])); (yyval) =cx;}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 116 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-6])].a3 = cx +1;}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 117 "MINICa.Y" /* yacc.c:1646  */
    { 
																				 	TABCOD[(yyvsp[-7])].a3 = cx + 2;
																				 	genCodigo(SALTAR,0,0,(yyvsp[-5]));
																				}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 123 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(IMPRINUM,(yyvsp[-1]),0,0);}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 124 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 124 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(LEENUM,(yyvsp[-1]),0,0);}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 129 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(IGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 130 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(NOIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MENOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();   genCodigo(MAYOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MENORIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 134 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MAYORIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 135 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(SUMAR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 136 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(RESTAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(MULTIPLICAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 138 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(DIVIDIR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 141 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[0]),0,-1); (yyval)=cx; }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 142 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-2])].a3 = cx +1; genCodigo(SALTARV,(yyvsp[-3]),0,-1); (yyval)=cx;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 143 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-2])].a3 = cx + 1;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 144 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 145 "MINICa.Y" /* yacc.c:1646  */
    {int v; IS(INT,VAR);(yyval) = localizaSimbolo(lexema);sscanf(lexema,"%d",&v);TS[(yyval)].a3.entero = v;}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 146 "MINICa.Y" /* yacc.c:1646  */
    {float v; IS(FLOAT,VAR);(yyval) = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[(yyval)].a3.real = v;}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 147 "MINICa.Y" /* yacc.c:1646  */
    { (yyval) = localizaSimbolo(lexema); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 147 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(MOVER,(yyvsp[-1]),(yyvsp[0]),0);}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1651 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 151 "MINICa.Y" /* yacc.c:1906  */


void genCodigo(int op,int a1,int a2,int a3)
{
	tipoCodigo *p;

	cx++;
	p = &TABCOD[cx];
	p->op = op;
	p->a1 = a1;
	p->a2 = a2;
	p->a3 = a3;
}

int genvartemp()
{
	char t[30];
	sprintf(t,"_T%-2d",indicevartemp++);
	strcpy(TS[nTS].nombre,t);
	TS[nTS].a1 = FLOAT;
	TS[nTS].a2 = VAR;
	return nTS++;
}

void muestraCodigo()
{
	int i,op,a1,a2,a3;
	for(i=0;i<=cx;i++) {
		op = TABCOD[i].op; a1 = TABCOD[i].a1;
		a2 = TABCOD[i].a2; a3 = TABCOD[i].a3;
		printf("%2d) ",i);
		switch(op)
		{		
		case MENOR: printf("MENOR %s = %s < %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MENORIGUAL: printf("MENORIGUAL %s = %s <= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR: printf("MAYOR %s = %s > %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYORIGUAL: printf("MAYORIGUAL %s = %s >= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case IGUAL: printf("IGUAL %s = %s == %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case NOIGUAL: printf("NOIGUAL %s = %s != %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case SALTAR: printf("SALTAR %d \n",a3);break;
		case SALTARV: printf("SALTARV %s %d \n",TS[a1].nombre,a3);break;
		case SALTARF: printf("SALTARF %s %d \n",TS[a1].nombre,a3);break;
		case MOVER: printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);break;
		case IMPRINUM: printf("IMPRINUM %s \n",TS[a1].nombre);break;
		case LEENUM: printf("LEENUM %s \n",TS[a1].nombre);break;
		case SUMAR: printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case RESTAR      : printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MULTIPLICAR : printf("MULTIPLICAR %s = %s * %s\n", TS[a1].nombre,TS[a2].nombre,TS[a3].nombre); break;
		case DIVIDIR     : printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		
		// Los dem�s casos
		}
	}
	return;
}

int localizaSimbolo(char *n)
{
	int i;
	for(i=0;i<nTS;i++) if(strcmp(n,TS[i].nombre) == 0) return i;
	return -1;
}
int insertaSimbolo(char *n, int t)
{
	if(localizaSimbolo(n)>=0) return -1;
	strcpy(TS[nTS].nombre,n);
	TS[nTS].a1 = t;
	TS[nTS].a2 = TS[nTS].a3.real = 0;
	return nTS++;	
}

void IS(int tipo,int clase)
{
	int i;
	i = insertaSimbolo(lexema, tipo); TS[i].a2=clase;
	//printf("*** %d %s\n",tipo,TS[i].nombre);
	//if(i<0) yyerror("Identifiador ya declarado.");
}

void muestraSimbolo()
{
	int i;
	printf("int=%d,float=%d\n",INT,FLOAT);
	for(i=0,pTS=TS;i<nTS;i++,pTS++)
		printf("%20s %d %d %g\n",pTS->nombre,pTS->a1,pTS->a2,pTS->a3.real);
} 


int yylex()

{
  int c;  char *p;
  do  c=getchar(); while(isspace(c));
  ;
  if (isalpha(c))
    { p=lexema;
      do  { *p++=c; c=getchar(); } while (isalpha(c));
      ungetc(c,stdin); *p=0;
      if (strcmp(lexema,"if")==0) return IF;
      if (strcmp(lexema,"else")==0) return ELSE;
      if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
      if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
      if (strcmp(lexema,"while")==0) return WHILE;
      if (strcmp(lexema,"for")==0) return FOR;
      if (strcmp(lexema,"do")==0) return DO;
      if (strcmp(lexema,"print")==0) return IMPRINUM;
	  if (strcmp(lexema,"read")==0) return LEENUM;
      if (strcmp(lexema,"chao")==0) return EOF;
      
      /* van otras palabras reservadas */
      
      return yylval=ID;
    }
/*    if (c=='\"') {
      p=lexema;
      do  { *p++=c; c=getchar(); } while (c!='\"');
      ungetc(c,stdin); *p=0;
      return yylval=FORMATO;
    }*/
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c==',' || c=='*' || c=='/' || c=='+' || c=='-' || c=='?' ||
         c=='[' || c==']' || c==':') return yylval=c;

    if ( c=='!') { 
    	c=getchar();
    	if(c=='=') return NOIGUAL;
    	ungetc(c,stdin); return NOT;
    	}
    	
    if ( c=='=' ) {
    	c=getchar();
    	if(c=='=') return IGUAL;
    	ungetc(c,stdin); return '=';
    	}
    	
    if ( c=='>' ) {
    	c=getchar();
    	if(c=='=') return MAYORIGUAL;
    	ungetc(c,stdin); return '>';
    	}
    	
    if ( c=='<' ) {
    	c=getchar();
    	if(c=='=') return MENORIGUAL;
    	ungetc(c,stdin); return '<';
    	}

    if ( c=='&' ) {
    	c=getchar();
    	if(c=='&') return AND;
    	ungetc(c,stdin); return '&';
    	}

	if ( c=='|' ) {
    	c=getchar();
    	if(c=='|') return OR;
    	ungetc(c,stdin); return '|';
    	}

    if (isdigit(c)) { 
    	p=lexema;
      	do  { *p++=c; c=getchar(); } while (isdigit(c))
      	;
      	if(c=='.') { do  { *p++=c; c=getchar(); } while (isdigit(c));
      			 ungetc(c,stdin); *p=0; return yylval=REAL;}
      	ungetc(c,stdin); *p=0;
    	return yylval=NUM;
    	}
    	
    yyerror("��� caracter ilegal !!!");
}

yyerror(char *m)  { 
	fprintf(stderr,"error de sintaxis %s\n",m); 
	getchar(); 
	exit(0);
	}

void interprete(){
	int icx,op,a1,a2,a3;
	
  char   ch;
  int c;
  
	float v;
	printf("Programa en ejecuci�n: \n");
	icx = 0;
	while(1){
		if(icx==cx+1) break;
		op = TABCOD[icx].op;
		a1 = TABCOD[icx].a1;
		a2 = TABCOD[icx].a2;
		a3 = TABCOD[icx].a3;
		switch(op)
		{
		case SALTAR : icx = a3; continue;
		case SALTARF : if(!TS[a1].a3.entero) { icx = a3; continue;}
				else break;
		case SALTARV : if(TS[a1].a3.entero) { icx = a3; continue;}
				else break;
		case IMPRINUM : if(TS[a1].a1==INT){
							printf("%d\n",TS[a1].a3.entero);
						}
						else if(TS[a1].a1==FLOAT){
							printf("%8.2f\n",TS[a1].a3.real);
						}
			 break;
		case LEENUM :   						
							printf("%d",c);	
						    scanf(" %c",&ch);
                      		printf("%d",c);
           				 
						printf("done");
						break;
		case MOVER : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1 == INT)
							TS[a1].a3.entero = TS[a2].a3.entero;
						else if(TS[a2].a1 == FLOAT)
							TS[a1].a3.entero = TS[a2].a3.real;
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1 == INT)
							TS[a1].a3.real = TS[a2].a3.entero;
						else if(TS[a2].a1 == FLOAT)
							TS[a1].a3.real = TS[a2].a3.real;
					}
					break;
		case SUMAR : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero + TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero + TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real + TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real + TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero + TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero + TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real + TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real + TS[a3].a3.entero);
						}
					}
					break;
		case RESTAR      : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero - TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero - TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real - TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real - TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero - TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero - TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real - TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real - TS[a3].a3.entero);
						}
					}
					break;
		case MULTIPLICAR : 
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero * TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero * TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real * TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real * TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero * TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero * TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real * TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real * TS[a3].a3.entero);
						}
					}
					break;
		case DIVIDIR :
					if(TS[a1].a1 == INT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.entero / TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.entero / TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.entero = (TS[a2].a3.real / TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.entero = (TS[a2].a3.real / TS[a3].a3.entero);
						}
					}
					else if(TS[a1].a1 == FLOAT){
						if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.entero / TS[a3].a3.real);	
						}
						else if(TS[a2].a1==INT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.entero / TS[a3].a3.entero);
						} 
						else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
							TS[a1].a3.real = (TS[a2].a3.real / TS[a3].a3.real);
						}
						else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
							TS[a1].a3.real = (TS[a2].a3.real / TS[a3].a3.entero);
						}
					}
					break; 
		case MENOR : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero < TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero < TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.entero);
					}
					break;
		case MENORIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero <= TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero <= TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real <= TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real < TS[a3].a3.entero);
					}
					break;
		case MAYOR :
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero > TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero > TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real > TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real > TS[a3].a3.entero);
					}
					break;
		case MAYORIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero >= TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero >= TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real >= TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real >= TS[a3].a3.entero);
					}
					break;
		case IGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero == TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero == TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real == TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real == TS[a3].a3.entero);
					}
					break;
		case NOIGUAL : 
					if(TS[a2].a1==INT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.entero != TS[a3].a3.real);	
					}
					else if(TS[a2].a1==INT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.entero != TS[a3].a3.entero);
					} 
					else if(TS[a2].a1==FLOAT && TS[a3].a1==FLOAT){
						TS[a1].a3.entero = (TS[a2].a3.real != TS[a3].a3.real);
					}
					else if(TS[a2].a1==FLOAT && TS[a3].a1==INT){
						TS[a1].a3.entero = (TS[a2].a3.real != TS[a3].a3.entero);
					}
					break;
		}
	icx++;
	}  //Fin de 'while'
	}  //Fin de funcion
	
main()  {
	
	yyparse();
	muestraSimbolo();
	muestraCodigo();
	interprete();
	}
