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

#include "utility.h"

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

#line 67 "cpl_parser.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "cpl_parser.h".  */
#ifndef YY_YY_CPL_PARSER_H_INCLUDED
# define YY_YY_CPL_PARSER_H_INCLUDED
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
    STRING = 258,
    INT = 259,
    FLOAT = 260,
    CHAR = 261,
    IntNum = 262,
    FloatNum = 263,
    Identifier = 264,
    FROM = 265,
    TO = 266,
    Mission = 267,
    MissionID = 268,
    MissionName = 269,
    Priority = 270,
    ComponentList = 271,
    Component = 272,
    ComponentID = 273,
    ComponentName = 274,
    Observation = 275,
    Orientation = 276,
    Decision = 277,
    Action = 278,
    LOR = 279,
    LAND = 280,
    LNOT = 281,
    EQ = 282,
    NEQ = 283,
    LE = 284,
    GE = 285,
    LT = 286,
    GT = 287,
    PLUS = 288,
    MINUS = 289,
    TIMES = 290,
    DEVIDE = 291,
    DE_EQ = 292,
    DE_NEQ = 293,
    DE_LE = 294,
    DE_GE = 295,
    DE_LT = 296,
    DE_GT = 297,
    ASGN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "cpl.y" /* yacc.c:355  */

  int i_num;
  float f_num;
  char str[64];
  struct astnode* node;

#line 158 "cpl_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (struct astnode **rootnode);

#endif /* !YY_YY_CPL_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 175 "cpl_parser.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 7 "cpl.y" /* yacc.c:359  */

#include "ast.h"
#include "cpl_lexer.h"
/* yyerror() needs the parse-param's defined aswell */
void yyerror (struct astnode **rootnode, char const *s);

#line 184 "cpl_parser.c" /* yacc.c:359  */

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

typedef unsigned int YYSIZE_T;

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
#define YYSTACK_ALLOC cpl_malloc
#define EXIT_SUCCESS 0
//# ifdef YYSTACK_USE_ALLOCA
//#  if YYSTACK_USE_ALLOCA
//#   ifdef __GNUC__
//#    define YYSTACK_ALLOC __builtin_alloca
//#   elif defined __BUILTIN_VA_ARG_INCR
//#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
//#   elif defined _AIX
//#    define YYSTACK_ALLOC __alloca
//#   elif defined _MSC_VER
//#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
//#    define alloca _alloca
//#   else
//#    define YYSTACK_ALLOC alloca
//#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
//#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
//#     ifndef EXIT_SUCCESS
//#      define EXIT_SUCCESS 0
//#     endif
//#    endif
//#   endif
//#  endif
//# endif

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
#   define YYMALLOC cpl_malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE cpl_free
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
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
       2,     2,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    64,    73,    81,    89,    99,   108,   118,
     127,   132,   140,   149,   159,   168,   177,   183,   189,   198,
     204,   210,   218,   228,   234,   240,   246,   252,   258,   264,
     270,   276,   282,   288,   294,   303,   312,   321,   327,   333,
     341,   347,   353,   359,   365,   371,   380,   386,   394,   403,
     409,   415,   421,   427,   432,   437,   442,   449,   455,   465,
     473,   485,   489,   495,   505,   515,   525,   535,   541,   550,
     556,   565
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "INT", "FLOAT", "CHAR",
  "IntNum", "FloatNum", "Identifier", "FROM", "TO", "Mission", "MissionID",
  "MissionName", "Priority", "ComponentList", "Component", "ComponentID",
  "ComponentName", "Observation", "Orientation", "Decision", "Action",
  "LOR", "LAND", "LNOT", "EQ", "NEQ", "LE", "GE", "LT", "GT", "PLUS",
  "MINUS", "TIMES", "DEVIDE", "DE_EQ", "DE_NEQ", "DE_LE", "DE_GE", "DE_LT",
  "DE_GT", "ASGN", "'{'", "'}'", "':'", "';'", "','", "'['", "']'",
  "$accept", "input", "mission", "ooda", "missionAttr", "missionID",
  "missionName", "priority", "compList", "comps", "comp", "compID",
  "compName", "observation", "obInsts", "orientation", "orInsts",
  "oneOrInst", "opOr", "opOr1", "decision", "deInsts", "oneDeInst", "opDe",
  "operand", "action", "actInsts", "stmts", "stmtN", "stmtVarDecl",
  "stmtCharArrayDecl", "identifierN", "stmtAssign", "stmtFrom", "stmtTo",
  "num", "type", "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   123,   125,    58,    59,    44,    91,
      93
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,   -21,    30,  -109,    37,  -109,     5,    36,    39,    47,
      11,    38,    10,    42,    12,    43,    17,    18,    41,    61,
      19,    -2,  -109,    22,    -8,  -109,    57,  -109,    24,    48,
    -109,    26,    64,  -109,  -109,    63,    31,  -109,  -109,    -2,
    -109,  -109,  -109,    66,    59,  -109,  -109,    61,    33,    57,
     -14,    40,    58,  -109,    35,    34,    25,  -109,    -5,    44,
      67,    45,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,    49,   -14,    71,
      76,   -13,    52,  -109,  -109,    80,  -109,  -109,    46,    25,
    -109,    79,  -109,    82,    51,    53,    83,  -109,  -109,    54,
      55,  -109,  -109,  -109,  -109,  -109,  -109,    56,   -13,    32,
      88,    50,  -109,    -1,     1,    60,    61,  -109,    62,    95,
      96,  -109,  -109,  -109,    65,  -109,    61,    69,    88,   -12,
    -109,    25,  -109,  -109,    68,  -109,    70,    72,    32,    74,
    -109,  -109,    61,  -109,    -1,  -109,    97,  -109,    75,    99,
      77,  -109,    78,  -109,    81,  -109,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     6,     0,     0,    10,    17,     3,     0,     0,
      71,     0,     0,    69,    70,     0,     0,    56,     5,    52,
      53,    54,    55,     0,     0,     9,    11,     0,     0,    17,
      20,     0,     0,     7,     0,     0,     0,    51,     0,     0,
       0,     0,    15,    16,    27,    28,    35,    29,    30,    32,
      31,    34,    33,    23,    24,    25,    26,     0,    20,     0,
       0,    38,     0,     4,     8,     0,    67,    68,     0,     0,
      61,     0,    57,     0,     0,     0,     0,    18,    19,     0,
       0,    40,    41,    43,    42,    45,    44,     0,    38,     0,
      50,     0,    64,     0,     0,     0,     0,    12,     0,     0,
       0,    36,    37,    46,     0,    47,     0,     0,    50,     0,
      58,     0,    62,    13,     0,    65,     0,     0,     0,     0,
      48,    49,     0,    59,     0,    14,     0,    22,     0,     0,
       0,    63,     0,    39,     0,    60,    21,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
      86,  -109,  -109,  -109,    84,  -109,    73,  -109,  -109,  -109,
    -109,     3,  -109,  -109,   -26,  -109,   -11,    87,  -109,  -109,
    -109,  -108,  -109,  -109,  -109,   -55,  -109,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    17,     7,     8,    13,    21,    11,    24,
      25,    60,    95,    18,    48,    29,    77,    78,    79,    80,
      52,   107,   108,   109,   124,    83,   127,    38,    39,    40,
      41,    92,    42,    49,   128,   125,    43,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    88,    33,    34,    35,   130,   132,    36,     1,    23,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     4,   101,   102,   103,   104,   105,   106,
       5,   142,    86,    87,   113,   143,   151,    45,    89,    86,
      87,   123,    90,    91,   131,    37,    90,    91,    90,    91,
       6,     9,    10,    12,    14,    15,    19,    20,    16,    22,
      23,    26,    28,    27,    30,    32,    44,    47,    50,   134,
      51,    54,    55,    53,    56,    58,   144,    59,    62,   139,
      99,    82,    84,    85,    81,   100,    94,   111,   114,   115,
      93,    96,   118,   112,    97,   150,   110,   116,   117,   126,
     129,   121,   119,   120,   136,   137,   152,   133,   154,   135,
      46,   122,   148,   138,   140,   145,     0,   141,   146,   147,
     149,     0,   153,     0,   155,   156,    57,     0,   157,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98
};

static const yytype_int16 yycheck[] =
{
      47,    56,     4,     5,     6,   113,   114,     9,    12,    17,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    44,    37,    38,    39,    40,    41,    42,
       0,    43,     7,     8,    89,    47,   144,    45,    43,     7,
       8,     9,    47,    48,    43,    47,    47,    48,    47,    48,
      13,    46,    16,    14,     7,    44,    46,    15,    20,    47,
      17,    44,    21,    45,     3,    46,    44,    10,    44,   116,
      22,     7,     9,    47,    43,     9,   131,    18,    45,   126,
       9,    23,    47,    49,    44,     9,    19,     7,     9,     7,
      46,    46,     9,    47,    45,   142,    44,    46,    45,    11,
      50,    45,    48,    48,     9,     9,     9,    47,     9,    47,
      24,   108,   138,    48,    45,    47,    -1,   128,    48,    47,
      46,    -1,    47,    -1,    47,    47,    39,    -1,    47,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    52,    53,    44,     0,    13,    55,    56,    46,
      16,    59,    14,    57,     7,    44,    20,    54,    64,    46,
      15,    58,    47,    17,    60,    61,    44,    45,    21,    66,
       3,    88,    46,     4,     5,     6,     9,    47,    78,    79,
      80,    81,    83,    87,    44,    45,    61,    10,    65,    84,
      44,    22,    71,    47,     7,     9,    43,    78,     9,    18,
      62,    88,    45,    65,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    67,    68,    69,
      70,    44,    23,    76,    47,    49,     7,     8,    86,    43,
      47,    48,    82,    46,    19,    63,    46,    45,    67,     9,
       9,    37,    38,    39,    40,    41,    42,    72,    73,    74,
      44,     7,    47,    86,     9,     7,    46,    45,     9,    48,
      48,    45,    72,     9,    75,    86,    11,    77,    85,    50,
      82,    43,    82,    47,    88,    47,     9,     9,    48,    88,
      45,    77,    43,    47,    86,    47,    48,    47,    75,    46,
      88,    82,     9,    47,     9,    47,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    60,    61,    62,    63,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    71,    72,    72,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    83,    84,    85,    86,    86,    87,
      87,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     4,     4,     4,     4,     4,
       1,     2,     5,     4,     4,     4,     2,     0,     4,     2,
       0,     7,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     3,     5,     6,
       8,     1,     3,     5,     4,     5,     5,     1,     1,     1,
       1,     1
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
      yyerror (rootnode, YY_("syntax error: cannot back up")); \
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
                  Type, Value, rootnode); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct astnode **rootnode)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (rootnode);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct astnode **rootnode)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, rootnode);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, struct astnode **rootnode)
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
                                              , rootnode);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, rootnode); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct astnode **rootnode)
{
  YYUSE (yyvaluep);
  YYUSE (rootnode);
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
yyparse (struct astnode **rootnode)
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
        case 2:
#line 58 "cpl.y" /* yacc.c:1646  */
    {
      *rootnode = (yyvsp[0].node);
    }
#line 1376 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_mission);
      node * Mission = new_Tnode(T_Mission, -1, -1, (yyvsp[-5].str));
      (yyval.node) = add_nodes((yyval.node), Mission, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), NULL);;
    }
#line 1386 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_ooda);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), NULL);;
    }
#line 1395 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_missionAttr);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), NULL);;
    }
#line 1404 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_missionID);
      node * MissionID = new_Tnode(T_MissionID, -1, -1, (yyvsp[-3].str));
      node * IntNum = new_Tnode(T_IntNum, (yyvsp[-1].i_num), -1, "");
      (yyval.node) = add_nodes((yyval.node), MissionID, IntNum, NULL, NULL, NULL);
    }
#line 1415 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_missionName);
      node * MissionName = new_Tnode(T_MissionName, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), MissionName, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1425 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_priority);
      node * Priority = new_Tnode(T_Priority, -1, -1, (yyvsp[-3].str));
      node * IntNum = new_Tnode(T_IntNum, (yyvsp[-1].i_num), -1, "");
      (yyval.node) = add_nodes((yyval.node), Priority, IntNum, NULL, NULL, NULL);
    }
#line 1436 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_compList);
      node * ComponentList = new_Tnode(T_ComponentList, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), ComponentList, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1446 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_comps);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[0].node), NULL, NULL, NULL, NULL);
    }
#line 1455 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_comps);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1464 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_comp);
      node * Component = new_Tnode(T_Component, -1, -1, (yyvsp[-4].str));
      (yyval.node) = add_nodes((yyval.node), Component, (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 1474 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_compID);
      node * ComponentID = new_Tnode(T_ComponentID, -1, -1, (yyvsp[-3].str));
      node * IntNum = new_Tnode(T_IntNum, (yyvsp[-1].i_num), -1, "");
      (yyval.node) = add_nodes((yyval.node), ComponentID, IntNum, NULL, NULL, NULL);
    }
#line 1485 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_compName);
      node * ComponentName = new_Tnode(T_ComponentName, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), ComponentName, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1495 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_observation);
      node * Observation = new_Tnode(T_Observation, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), Observation, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1505 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 178 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_obInsts);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1514 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1522 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 190 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_orientation);
      node * Orientation = new_Tnode(T_Orientation, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), Orientation, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1532 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 199 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_orInsts);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1541 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 204 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1549 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 211 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_oneOrInst);
      node* Identifier1 = new_Tnode(T_Identifier, -1, -1, (yyvsp[-5].str));
      node* Identifier2 = new_Tnode(T_Identifier, -1, -1, (yyvsp[-3].str));
      node* Identifier3 = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-6].node), Identifier1, Identifier2, Identifier3, NULL);;
    }
#line 1561 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 219 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_oneOrInst);
      node* Identifier1 = new_Tnode(T_Identifier, -1, -1, (yyvsp[-3].str));
      node* Identifier2 = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-4].node), Identifier1, Identifier2, NULL, NULL);
    }
#line 1572 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 229 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * PlUS = new_Tnode(T_PLUS, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), PlUS, NULL, NULL, NULL, NULL);
    }
#line 1582 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * MINUS = new_Tnode(T_MINUS, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), MINUS, NULL, NULL, NULL, NULL);
    }
#line 1592 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 241 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * TIMES = new_Tnode(T_TIMES, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), TIMES, NULL, NULL, NULL, NULL);
    }
#line 1602 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * DEVIDE = new_Tnode(T_DEVIDE, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DEVIDE, NULL, NULL, NULL, NULL);
    }
#line 1612 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 253 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * LOR = new_Tnode(T_LOR, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), LOR, NULL, NULL, NULL, NULL);
    }
#line 1622 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 259 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * LAND = new_Tnode(T_LAND, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), LAND, NULL, NULL, NULL, NULL);
    }
#line 1632 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 265 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * EQ = new_Tnode(T_EQ, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), EQ, NULL, NULL, NULL, NULL);
    }
#line 1642 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 271 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * NEQ = new_Tnode(T_NEQ, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), NEQ, NULL, NULL, NULL, NULL);
    }
#line 1652 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 277 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_opOr);
     node * GE = new_Tnode(T_GE, -1, -1, (yyvsp[0].str));
     (yyval.node) = add_nodes((yyval.node), GE, NULL, NULL, NULL, NULL);
    }
#line 1662 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 283 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * LE = new_Tnode(T_LE, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), LE, NULL, NULL, NULL, NULL);
    }
#line 1672 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 289 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * GT = new_Tnode(T_GT, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), GT, NULL, NULL, NULL, NULL);
    }
#line 1682 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 295 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr);
      node * LT = new_Tnode(T_LT, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), LT, NULL, NULL, NULL, NULL);
    }
#line 1692 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 304 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opOr1);
      node * LNOT = new_Tnode(T_LNOT, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), LNOT, NULL, NULL, NULL, NULL);
    }
#line 1702 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 313 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_decision);
     node * Decision = new_Tnode(T_Decision, -1, -1, (yyvsp[-3].str));
     (yyval.node) = add_nodes((yyval.node), Decision, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1712 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 322 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_deInsts);                      
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1721 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 327 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1729 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 334 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_oneDeInst);             
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 1738 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 342 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_EQ = new_Tnode(T_DE_EQ, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_EQ, NULL, NULL, NULL, NULL);
    }
#line 1748 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 348 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_NEQ = new_Tnode(T_DE_NEQ, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_NEQ, NULL, NULL, NULL, NULL);
    }
#line 1758 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 354 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_GE = new_Tnode(T_DE_GE, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_GE, NULL, NULL, NULL, NULL);
    }
#line 1768 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 360 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_LE = new_Tnode(T_DE_LE, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_LE, NULL, NULL, NULL, NULL);
    }
#line 1778 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 366 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_GT = new_Tnode(T_DE_GT, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_GT, NULL, NULL, NULL, NULL);
    }
#line 1788 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 372 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_opDe);
      node * DE_LT = new_Tnode(T_DE_LT, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), DE_LT, NULL, NULL, NULL, NULL);
    }
#line 1798 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 381 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_operand);
      node* Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), Identifier, NULL, NULL, NULL, NULL);
    }
#line 1808 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 387 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_operand);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[0].node), NULL, NULL, NULL, NULL);
    }
#line 1817 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 395 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_action);
      node * Action = new_Tnode(T_Action, -1, -1, (yyvsp[-3].str));
      (yyval.node) = add_nodes((yyval.node), Action, (yyvsp[-1].node), NULL, NULL, NULL);
    }
#line 1827 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 404 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_actInsts);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1836 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 409 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1844 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 416 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmts);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1853 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 421 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1861 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 428 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtN);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[0].node), NULL, NULL, NULL, NULL);
    }
#line 1870 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 433 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtN);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[0].node), NULL, NULL, NULL, NULL);
    }
#line 1879 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 438 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtN);
      (yyval.node) = add_nodes((yyval.node), (yyvsp[0].node), NULL, NULL, NULL, NULL);
    }
#line 1888 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 443 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1896 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 450 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtVarDecl);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-2].node), Identifier, (yyvsp[0].node), NULL, NULL);
    }
#line 1906 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 456 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtVarDecl);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-3].str));
      node * ASGN = new_Tnode(T_ASGN, -1, -1, (yyvsp[-2].str));
      (yyval.node) = add_nodes((yyval.node), (yyvsp[-4].node), Identifier, ASGN, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1917 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 466 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtCharArrayDecl);
      node * CHAR = new_Tnode(T_CHAR, -1, -1, (yyvsp[-5].str));
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-4].str));
      node * IntNum = new_Tnode(T_IntNum, (yyvsp[-2].i_num), -1, "");
      (yyval.node) = add_nodes((yyval.node), CHAR, Identifier, IntNum, NULL, NULL);
    }
#line 1929 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 474 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtCharArrayDecl);
      node * CHAR = new_Tnode(T_CHAR, -1, -1, (yyvsp[-7].str));
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-6].str));
      node * IntNum = new_Tnode(T_IntNum, (yyvsp[-4].i_num), -1, "");
      node * ASGN = new_Tnode(T_ASGN, -1, -1, (yyvsp[-2].str));
      (yyval.node) = add_nodes((yyval.node), CHAR, Identifier, IntNum, ASGN, (yyvsp[-1].node));
    }
#line 1942 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 486 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = NULL;
    }
#line 1950 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 490 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_identifierN);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), Identifier, (yyvsp[0].node), NULL, NULL, NULL);
    }
#line 1960 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 496 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_identifierN);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-3].str));
      node * ASGN = new_Tnode(T_ASGN, -1, -1, (yyvsp[-2].str));
      (yyval.node) = add_nodes((yyval.node), Identifier, ASGN, (yyvsp[-1].node), (yyvsp[0].node), NULL);
    }
#line 1971 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 506 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtAssign);
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-3].str));
      node * ASGN = new_Tnode(T_ASGN, -1, -1, (yyvsp[-2].str));
      (yyval.node) = add_nodes((yyval.node), Identifier, ASGN, (yyvsp[-1].node), NULL, NULL);
    }
#line 1982 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 516 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtFrom);
      node * FROM = new_Tnode(T_FROM, -1, -1, (yyvsp[-4].str));
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), FROM, (yyvsp[-3].node), Identifier, NULL, NULL);
    }
#line 1993 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 526 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_stmtTo);
      node * TO = new_Tnode(T_TO, -1, -1, (yyvsp[-4].str));
      node * Identifier = new_Tnode(T_Identifier, -1, -1, (yyvsp[-1].str));
      (yyval.node) = add_nodes((yyval.node), TO, (yyvsp[-3].node), Identifier, NULL, NULL);
    }
#line 2004 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 536 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_num);
     node * IntNum = new_Tnode(T_IntNum, (yyvsp[0].i_num), -1, "");
     (yyval.node) = add_nodes((yyval.node), IntNum, NULL, NULL, NULL, NULL);
   }
#line 2014 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 542 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_num);
     node * FloatNum = new_Tnode(T_FloatNum, -1, (yyvsp[0].f_num), "");
     (yyval.node) = add_nodes((yyval.node), FloatNum, NULL, NULL, NULL, NULL);
   }
#line 2024 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 551 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_type);
     node * INT = new_Tnode(T_INT, -1, -1, (yyvsp[0].str));
     (yyval.node) = add_nodes((yyval.node), INT, NULL, NULL, NULL, NULL);
   }
#line 2034 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 557 "cpl.y" /* yacc.c:1646  */
    {
     (yyval.node) = new_NTnode(NT_type);
     node * FLOAT = new_Tnode(T_FLOAT, -1, -1, (yyvsp[0].str));
     (yyval.node) = add_nodes((yyval.node), FLOAT, NULL, NULL, NULL, NULL);
   }
#line 2044 "cpl_parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 566 "cpl.y" /* yacc.c:1646  */
    {
      (yyval.node) = new_NTnode(NT_string);
      node * STRING = new_Tnode(T_STRING, -1, -1, (yyvsp[0].str));
      (yyval.node) = add_nodes((yyval.node), STRING, NULL, NULL, NULL, NULL);
    }
#line 2054 "cpl_parser.c" /* yacc.c:1646  */
    break;


#line 2058 "cpl_parser.c" /* yacc.c:1646  */
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
      yyerror (rootnode, YY_("syntax error"));
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
        yyerror (rootnode, yymsgp);
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
                      yytoken, &yylval, rootnode);
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
                  yystos[yystate], yyvsp, rootnode);
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
  yyerror (rootnode, YY_("memory exhausted"));
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
                  yytoken, &yylval, rootnode);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, rootnode);
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
#line 574 "cpl.y" /* yacc.c:1906  */

         
void yyerror (struct astnode **rootnode, char const *s){
	//printf("Syntex Error in line number : %d : %s %s\n", yylineno, s, yytext );
}
