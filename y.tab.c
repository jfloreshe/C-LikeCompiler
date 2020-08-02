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
#include<stdlib.h>

int yylex();
typedef union { int entero;
		float real;
		char cadena[30];
		} tipovalor;
void IS(int , int);
void IBP(int );
void asignarParametros(int);
char lexema[80];
typedef struct {char nombre[30];
		int a1,a2,a4,a5,a6;  	// a1: INT/FLOAT	a2: FUN/VAR		a4: inicio de FUN a5:fin de FUN a6:nro parametros en FUN
		tipovalor a3; 	// guarda valor
	} tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;
int bufferParametros[100];
int iBP = -1;//indiceactual del buffer de parametros
int insertaSimbolo(char *, int);
int localizaSimbolo(char *);
void muestraSimbolo();
void imprimirCadena(char *);
int encontrarFuncionAsociada();
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
#define SALTARYREGRESAR 11


#line 128 "y.tab.c" /* yacc.c:339  */

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
    STRING = 260,
    FORMATO = 261,
    ID = 262,
    IF = 263,
    ELSE = 264,
    NUM = 265,
    REAL = 266,
    CADENA = 267,
    WHILE = 268,
    DO = 269,
    FOR = 270,
    FUNCION = 271,
    RETURN = 272,
    LEER = 273,
    IMPRIMIR = 274,
    CENTERO = 275,
    CFLOAT = 276,
    VAR = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    IGUAL = 281,
    NOIGUAL = 282,
    MENORIGUAL = 283,
    MAYORIGUAL = 284
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define FORMATO 261
#define ID 262
#define IF 263
#define ELSE 264
#define NUM 265
#define REAL 266
#define CADENA 267
#define WHILE 268
#define DO 269
#define FOR 270
#define FUNCION 271
#define RETURN 272
#define LEER 273
#define IMPRIMIR 274
#define CENTERO 275
#define CFLOAT 276
#define VAR 277
#define OR 278
#define AND 279
#define NOT 280
#define IGUAL 281
#define NOIGUAL 282
#define MENORIGUAL 283
#define MAYORIGUAL 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 234 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      39,    40,    36,    34,    41,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    38,
      32,    23,    33,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    82,    82,    83,    85,    85,    86,    85,
      87,    87,    87,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    93,    94,    94,    95,    95,    95,
      96,    97,   100,   104,   100,   111,   111,   114,   114,   114,
     122,   122,   123,   124,   124,   126,   122,   133,   134,   134,
     135,   136,   137,   138,   139,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   153,   154,   153,   156,   157,   158,
     159,   163,   163,   163,   166,   167,   167,   168,   169
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "FORMATO",
  "ID", "IF", "ELSE", "NUM", "REAL", "CADENA", "WHILE", "DO", "FOR",
  "FUNCION", "RETURN", "LEER", "IMPRIMIR", "CENTERO", "CFLOAT", "VAR",
  "'='", "'?'", "OR", "AND", "NOT", "IGUAL", "NOIGUAL", "MENORIGUAL",
  "MAYORIGUAL", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "';'", "'('",
  "')'", "','", "'{'", "'}'", "':'", "'['", "']'", "$accept", "programaC",
  "listaDeclC", "declC", "@1", "$@2", "@3", "Tipo", "listaVar", "$@4",
  "listaPar", "$@5", "listaParCall", "$@6", "bloque", "listaVarLoc",
  "listaProp", "prop", "@7", "@8", "propif", "@9", "@10", "@11", "@12",
  "@13", "@14", "@15", "$@16", "@17", "expr", "@18", "@19", "@20", "$@21",
  "@22", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    63,   278,   279,   280,   281,   282,
     283,   284,    60,    62,    43,    45,    42,    47,    59,    40,
      41,    44,   123,   125,    58,    91,    93
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -103,    18,    38,  -103,  -103,  -103,  -103,  -103,    14,     5,
      -2,  -103,  -103,  -103,    38,    30,    40,     8,     4,  -103,
      12,  -103,    26,  -103,    38,    28,  -103,    38,  -103,    30,
    -103,    33,    46,    38,    -6,    29,  -103,  -103,  -103,    35,
      36,  -103,   134,    37,    39,   134,  -103,  -103,  -103,  -103,
    -103,   210,  -103,  -103,   134,   134,  -103,   134,    42,   210,
      70,   134,   246,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,    59,   134,   103,   167,   134,
     223,   134,  -103,   180,   236,   246,   -27,   -27,   -27,   -27,
     -27,   -27,   -34,   -34,  -103,  -103,   134,   210,    62,  -103,
     193,  -103,    47,   154,    50,  -103,   137,   134,    88,  -103,
     134,  -103,    45,  -103,    48,   210,  -103,    88,   210,  -103,
     134,   134,    84,  -103,  -103,  -103,   210,    28,  -103,    56,
    -103,  -103,   134,   210,    57,  -103,    88,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    10,    11,    12,     3,     0,    15,
       0,     6,    13,     5,    19,     0,     0,     0,    15,    14,
      16,     7,     0,     8,    19,     0,    17,    25,     9,     0,
      27,     0,     0,    25,    67,     0,    68,    69,    70,     0,
       0,    71,     0,     0,     0,     0,    30,    24,    31,    29,
      28,    50,    26,    75,     0,     0,    37,     0,     0,    74,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    64,     0,
      64,    23,    48,    64,    51,    52,    54,    55,    58,    59,
      56,    57,    60,    61,    62,    63,     0,    76,    77,    32,
      64,    40,     0,    20,     0,    47,    64,     0,     0,    38,
       0,    72,     0,    49,     0,    78,    33,     0,    41,    73,
      23,     0,    35,    39,    42,    21,    66,     0,    34,     0,
      36,    43,     0,    44,     0,    45,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,  -103,  -103,  -103,  -103,    58,   -10,  -103,
      85,  -103,   -12,  -103,   -25,   -21,  -103,  -102,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     -41,  -103,  -103,  -103,  -103,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    14,    23,    25,    29,    10,    15,
      17,    22,   102,   112,    48,    30,    32,    50,   108,   122,
     128,    79,   117,   110,   124,   129,   132,   134,   136,   104,
      51,    75,   114,    58,   119,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    59,    73,    74,    62,    19,   116,    71,    72,    73,
      74,    49,    52,    77,    78,   123,    80,    53,     3,    31,
      83,     9,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   137,    97,    13,    18,   100,    54,
     103,     4,     5,     6,    11,    12,    12,    20,    21,     4,
       5,     6,   -18,    34,    35,   106,    36,    37,    38,    39,
       8,    40,    41,    42,    43,    44,   115,    24,    55,   118,
      27,    33,    16,    45,    56,    57,    60,    82,    61,   103,
     126,    81,    16,    96,    46,   107,   120,   111,    27,    47,
     113,   133,   121,   127,   131,    34,    35,   135,    36,    37,
      38,    39,   130,    40,    41,    42,    43,    44,   125,    26,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    63,    64,
      27,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    34,     0,     0,    36,    37,    38,     0,     0,    98,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,   -64,    63,
      64,   -65,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    63,    64,   -22,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    63,    64,    99,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    63,    64,
     105,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,   109,   -64,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   101,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      25,    42,    36,    37,    45,    15,   108,    34,    35,    36,
      37,    32,    33,    54,    55,   117,    57,    23,     0,    29,
      61,     7,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   136,    76,    38,     7,    79,    45,
      81,     3,     4,     5,    39,    41,    41,     7,    40,     3,
       4,     5,    40,     7,     8,    96,    10,    11,    12,    13,
       2,    15,    16,    17,    18,    19,   107,    41,    39,   110,
      42,    38,    14,    27,    39,    39,    39,     7,    39,   120,
     121,    39,    24,    24,    38,    23,    41,    40,    42,    43,
      40,   132,    44,     9,    38,     7,     8,    40,    10,    11,
      12,    13,   127,    15,    16,    17,    18,    19,   120,    24,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    25,    26,
      42,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     7,    -1,    -1,    10,    11,    12,    -1,    -1,    46,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    24,    25,
      26,    44,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    25,    26,    40,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    25,    26,    40,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    25,    26,
      40,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,     3,     4,     5,    50,    54,     7,
      55,    39,    41,    38,    51,    56,    54,    57,     7,    55,
       7,    40,    58,    52,    41,    53,    57,    42,    61,    54,
      62,    55,    63,    38,     7,     8,    10,    11,    12,    13,
      15,    16,    17,    18,    19,    27,    38,    43,    61,    62,
      64,    77,    62,    23,    45,    39,    39,    39,    80,    77,
      39,    39,    77,    25,    26,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    78,    82,    77,    77,    68,
      77,    39,     7,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    24,    77,    46,    40,
      77,    38,    59,    77,    76,    40,    77,    23,    65,    40,
      70,    40,    60,    40,    79,    77,    64,    69,    77,    81,
      41,    44,    66,    64,    71,    59,    77,     9,    67,    72,
      61,    38,    73,    77,    74,    40,    75,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    52,    53,    50,
      54,    54,    54,    56,    55,    55,    58,    57,    57,    57,
      60,    59,    59,    59,    61,    62,    62,    63,    63,    63,
      64,    64,    65,    66,    64,    67,    67,    68,    69,    64,
      70,    71,    72,    73,    74,    75,    64,    64,    76,    64,
      64,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    77,    77,    77,    77,
      77,    80,    81,    77,    77,    82,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     0,     0,     0,     9,
       1,     1,     1,     0,     4,     1,     0,     5,     2,     0,
       0,     4,     1,     0,     4,     0,     4,     0,     2,     2,
       1,     1,     0,     0,     8,     0,     2,     0,     0,     7,
       0,     0,     0,     0,     0,     0,    15,     4,     0,     5,
       1,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     0,     7,     1,     1,     1,
       1,     0,     0,     6,     2,     0,     4,     4,     6
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
#line 85 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-2]),FUNCION); (yyval)=localizaSimbolo(lexema);}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARV,(yyvsp[-2]),0,0);}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "MINICa.Y" /* yacc.c:1646  */
    {TS[(yyvsp[-3])].a4=cx+1;TS[(yyvsp[-3])].a6 = nTS - (yyvsp[-3]) -1;;(yyval)=cx+1;}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "MINICa.Y" /* yacc.c:1646  */
    { TS[(yyvsp[-5])].a5=cx;(yyval)=cx;}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "MINICa.Y" /* yacc.c:1646  */
    { IS(tipoVar,VAR); }
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "MINICa.Y" /* yacc.c:1646  */
    { IS(tipoVar,VAR); }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-1]),VAR); }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "MINICa.Y" /* yacc.c:1646  */
    { IS((yyvsp[-1]),VAR); }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 92 "MINICa.Y" /* yacc.c:1646  */
    {IBP((yyvsp[0]));}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 92 "MINICa.Y" /* yacc.c:1646  */
    {IBP((yyvsp[0]));IBP(-1);}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); 
								(yyval) = cx; 
								}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "MINICa.Y" /* yacc.c:1646  */
    { TABCOD[(yyvsp[-1])].a3 = cx + 1;
									genCodigo(SALTARV,(yyvsp[-3]),0,-1);
									(yyval) = cx;
								}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "MINICa.Y" /* yacc.c:1646  */
    { TABCOD[(yyvsp[-1])].a3 = cx + 1;}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 111 "MINICa.Y" /* yacc.c:1646  */
    {(yyval)=cx;}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 114 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); /* Destino no resuelto */
	   						                         (yyval) = cx; /* Falta llenar cuarto componente de este salto */}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTAR,0,0,(yyvsp[-4])); /* Ir al comienzo de la expresi�n */
							                         TABCOD[(yyvsp[-1])].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 122 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARV,(yyvsp[0]),0,-1); (yyval) =cx;}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 123 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); (yyval)=cx;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 124 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTAR,0,0,(yyvsp[-6])); (yyval) =cx;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 126 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-6])].a3 = cx +1;}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 127 "MINICa.Y" /* yacc.c:1646  */
    { 
																				 	TABCOD[(yyvsp[-7])].a3 = cx + 2;
																				 	genCodigo(SALTAR,0,0,(yyvsp[-5]));
																				}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 133 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(IMPRIMIR,(yyvsp[-1]),0,0);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(LEER,(yyvsp[-1]),0,0);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 139 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	
							genCodigo(IGUAL,n,(yyvsp[-2]),(yyvsp[0]));
							  (yyval)=n;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 142 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(NOIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 143 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MENOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 144 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();   genCodigo(MAYOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 145 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MENORIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 146 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(MAYORIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 147 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp();	genCodigo(SUMAR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 148 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(RESTAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 149 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(MULTIPLICAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 150 "MINICa.Y" /* yacc.c:1646  */
    {int n = genvartemp(); genCodigo(DIVIDIR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 153 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[0]),0,-1); (yyval)=cx; }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 154 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-2])].a3 = cx +1; genCodigo(SALTARV,(yyvsp[-3]),0,-1); (yyval)=cx;}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 155 "MINICa.Y" /* yacc.c:1646  */
    {TABCOD[(yyvsp[-2])].a3 = cx + 1;}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 156 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 157 "MINICa.Y" /* yacc.c:1646  */
    {int v; IS(INT,VAR);(yyval) = localizaSimbolo(lexema);sscanf(lexema,"%d",&v);TS[(yyval)].a3.entero = v;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 158 "MINICa.Y" /* yacc.c:1646  */
    {float v; IS(FLOAT,VAR);(yyval) = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[(yyval)].a3.real = v;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 159 "MINICa.Y" /* yacc.c:1646  */
    {IS(STRING,VAR); 
					(yyval) = localizaSimbolo(lexema);					
					strcpy(TS[(yyval)].a3.cadena,lexema);
					}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 163 "MINICa.Y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 163 "MINICa.Y" /* yacc.c:1646  */
    {asignarParametros((yyvsp[-3]));}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 165 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(SALTARYREGRESAR, TS[(yyvsp[-4])].a4,TS[(yyvsp[-4])].a5,cx+2); (yyval)=(yyvsp[-4]);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 166 "MINICa.Y" /* yacc.c:1646  */
    {int n,n2; n=encontrarFuncionAsociada(); n2 = localizaSimbolo(lexema);genCodigo(MOVER,n,n2,0); genCodigo(RETURN,0,0,0);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 167 "MINICa.Y" /* yacc.c:1646  */
    { (yyval) = localizaSimbolo(lexema); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 167 "MINICa.Y" /* yacc.c:1646  */
    {genCodigo(MOVER,(yyvsp[-1]),(yyvsp[0]),0);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1751 "y.tab.c" /* yacc.c:1646  */
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
#line 171 "MINICa.Y" /* yacc.c:1906  */


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
	sprintf(t,"_T%d",nTS);
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
		case SALTARYREGRESAR: printf("SALTARYREGRESAR inicio %d, final %d, regresar a %d\n",a1,a2,a3);break;
		case SALTAR: printf("SALTAR %d\n",a3);break;
		case SALTARV: printf("SALTARV %s %d \n",TS[a1].nombre,a3);break;
		case SALTARF: printf("SALTARF %s %d \n",TS[a1].nombre,a3);break;
		case MOVER: printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);break;
		case IMPRIMIR: printf("IMPRIMIR %s \n",TS[a1].nombre);break;
		case LEER: printf("LEER %s \n",TS[a1].nombre);break;
		case SUMAR: printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case RESTAR      : printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MULTIPLICAR : printf("MULTIPLICAR %s = %s * %s\n", TS[a1].nombre,TS[a2].nombre,TS[a3].nombre); break;
		case DIVIDIR     : printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case RETURN		 : printf("RETURN\n");
		
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
	TS[nTS].a2 = TS[nTS].a3.real = TS[nTS].a4 = 0;
	return nTS++;	
}
void IBP(int isimbolo){
	bufferParametros[++iBP] = isimbolo;
}
void asignarParametros(int ifuncion){
	
	if(TS[ifuncion].a6 != iBP){
		yyerror("parametros fuera de rango");
	}
	int iParametro = ifuncion + 1;
	for(int i = 0; i < iBP; ++i){
		int simboloEnBuffer = bufferParametros[i];
		genCodigo(MOVER,iParametro,simboloEnBuffer,0);
		iParametro++;
	}
	iBP = -1;
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
	printf("int=%d,float=%d,string=%d\n",INT,FLOAT,STRING);
	for(i=0,pTS=TS;i<nTS;i++,pTS++)
		printf("%20s %d %d %g\n",pTS->nombre,pTS->a1,pTS->a2,pTS->a3.real);
} 

int encontrarFuncionAsociada(){
	int i;
	for(i=nTS-1; i>=0 ; --i){
		if(TS[i].a2 == FUNCION)
			break;
	}
	return i;
}
void imprimirCadena(char *str){
	char *character;
	character = str;
	char value;
	int i =0;
	while(*character != '\0'){
		if(str[i] == '\\'){
			++i;
			if(str[i] == 'n'){
				printf("\n");
			}
			else if(str[i] == 't'){
				printf("\t");
			}
			else
				printf("%c",str[--i]);
		}
		else
			printf("%c",str[i]);
		i++;
		character++;
	}
}


int yylex()
//TODO FIX HOW IT gets everything
{
  int c;  char *p;
  do c=getchar();while(isspace(c));
  if (isalpha(c))
    { p=lexema;
      do  { 
		  *p++=c; 
		  c=getchar();
	  } 
	  while (isalpha(c));
	  ungetc(c,stdin);
	  *p=0;
	  int simboloPos = localizaSimbolo(lexema);
	  if(simboloPos >= 0){
		  if(TS[simboloPos].a2 == FUNCION){
		  	return FUNCION;
		  }	
	  }
      if (strcmp(lexema,"if")==0) return IF;
      if (strcmp(lexema,"else")==0) return ELSE;
      if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
      if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
	  if (strcmp(lexema,"string")==0) return tipoVar=yylval=STRING;
      if (strcmp(lexema,"while")==0) return WHILE;
      if (strcmp(lexema,"for")==0) return FOR;
      if (strcmp(lexema,"do")==0) return DO;
      if (strcmp(lexema,"print")==0) return IMPRIMIR;
	  if (strcmp(lexema,"read")==0) return LEER;
	  if (strcmp(lexema,"return")==0) return RETURN;
      if (strcmp(lexema,"chao")==0) {		  
		  return EOF;							
	  }
      
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
      	do  { *p++=c; c=getchar(); } while (isdigit(c));
      	if(c=='.') { do  { *p++=c; c=getchar(); } while (isdigit(c));
      			 ungetc(c,stdin); *p=0; return yylval=REAL;}
      	ungetc(c,stdin); *p=0;
    	return yylval=NUM;
    	}
    if ( c == '"') {
		p=lexema;
		do {c=getchar(); *p++=c;} while(c!='"');
		*(p-1)=0;
		return yylval = CADENA;
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
	tipovalor entrada;
	int enSaltarRegresar = 0;
	//usar como un stack para poder utilizar con funciones nested 
	int numeroOperacionesParaRegresar = 0;
	int regresarA = -1;
	FILE *tty;	
	tty = freopen("/dev/tty", "r", stdin);
	if (tty == NULL) {
		perror("Unable to open terminal for reading");
	}
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
		case RETURN :
			if(enSaltarRegresar){
				numeroOperacionesParaRegresar = 0;
				icx = regresarA;
				regresarA = -1;
				enSaltarRegresar = 0;
				continue;
			}
			break;
		case SALTARYREGRESAR :
			enSaltarRegresar = 1;
			numeroOperacionesParaRegresar = a2 - a1 
			+1;
			regresarA = a3;
			icx = a1;
			continue;
		case SALTAR :	
						icx = a3; 
						continue;
		case SALTARF : if(!TS[a1].a3.entero) { icx = a3; continue;}
				else break;
		case SALTARV : 
				if(TS[a1].a2 == VAR){
					if(TS[a1].a3.entero) { 
						icx = a3; continue;
					}
					else break;
				}
				else if(TS[a1].a2 == FUNCION){
					if(strcmp(TS[a1].nombre,"main")!=0){
						icx = TS[a1].a5 +1;
						continue;
					}
					else if (strcmp(TS[a1].nombre,"main")==0){
						break;
					}
				}
		case IMPRIMIR : if(TS[a1].a1==INT){
							printf("%d\n",TS[a1].a3.entero);
						}
						else if(TS[a1].a1==FLOAT){
							printf("%f\n",TS[a1].a3.real);
						}
						else if(TS[a1].a1==STRING){
							imprimirCadena(TS[a1].a3.cadena);
						}
			 break;
		case LEER :   
						if(TS[a1].a1 == INT){
							scanf(" %d", &entrada.entero);
							TS[a1].a3.entero = entrada.entero;
						}
						else if(TS[a1].a1 == FLOAT){
							scanf(" %f", &entrada.real);
							TS[a1].a3.real = entrada.real;
						}					
						else if(TS[a1].a1 == STRING){
							scanf("%s",&entrada.cadena);
							strcpy(TS[a1].a3.cadena,&entrada.cadena);
						}
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
					else if(TS[a1].a1 == STRING){
						if(TS[a2].a1 == STRING)
							strcpy(TS[a1].a3.cadena,TS[a2].a3.cadena);
						else if(TS[a2].a1 == INT)
							snprintf(TS[a1].a3.cadena,30,"%d",TS[a2].a3.entero);
						else if(TS[a2].a1 == FLOAT)
							snprintf(TS[a1].a3.cadena,30,"%f",TS[a2].a3.real);
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
	
main(int argc, char *argv[])  {
	yyparse();
	muestraSimbolo();
	muestraCodigo();
	interprete();
	}
