/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "syntax_analyzer.y"

#include<bits/stdc++.h>
#include"symbol_info.h"
using namespace std;

#define YYSTYPE symbol_info*

int yyparse(void);
int yylex(void);
void yyerror(const char *s);

extern FILE *yyin;

ofstream outlog;
int lines = 1;

void print_rule(string rule, string text)
{
    outlog << "At line no: " << lines << " " << rule << endl << endl;
    outlog << text << endl << endl;
}

/* Line 371 of yacc.c  */
#line 91 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     DO = 262,
     SWITCH = 263,
     BREAK = 264,
     DEFAULT = 265,
     INT = 266,
     CHAR = 267,
     FLOAT = 268,
     DOUBLE = 269,
     VOID = 270,
     RETURN = 271,
     CONTINUE = 272,
     CASE = 273,
     GOTO = 274,
     PRINTLN = 275,
     ID = 276,
     CONST_INT = 277,
     CONST_FLOAT = 278,
     ADDOP = 279,
     MULOP = 280,
     INCOP = 281,
     DECOP = 282,
     RELOP = 283,
     ASSIGNOP = 284,
     LOGICOP = 285,
     NOT = 286,
     LPAREN = 287,
     RPAREN = 288,
     LCURL = 289,
     RCURL = 290,
     LTHIRD = 291,
     RTHIRD = 292,
     COMMA = 293,
     COLON = 294,
     SEMICOLON = 295,
     LOWER_THAN_ELSE = 296
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define SWITCH 263
#define BREAK 264
#define DEFAULT 265
#define INT 266
#define CHAR 267
#define FLOAT 268
#define DOUBLE 269
#define VOID 270
#define RETURN 271
#define CONTINUE 272
#define CASE 273
#define GOTO 274
#define PRINTLN 275
#define ID 276
#define CONST_INT 277
#define CONST_FLOAT 278
#define ADDOP 279
#define MULOP 280
#define INCOP 281
#define DECOP 282
#define RELOP 283
#define ASSIGNOP 284
#define LOGICOP 285
#define NOT 286
#define LPAREN 287
#define RPAREN 288
#define LCURL 289
#define RCURL 290
#define LTHIRD 291
#define RTHIRD 292
#define COMMA 293
#define COLON 294
#define SEMICOLON 295
#define LOWER_THAN_ELSE 296



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 239 "y.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    21,    27,
      32,    36,    39,    41,    45,    48,    52,    54,    56,    58,
      60,    62,    66,    73,    75,    80,    82,    85,    87,    89,
      91,    99,   105,   113,   119,   125,   129,   131,   134,   136,
     141,   143,   147,   149,   153,   155,   159,   161,   165,   167,
     171,   174,   177,   179,   181,   183,   188,   192,   194,   196,
     199,   202,   204,   205,   209
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    45,    -1,    45,    -1,
      49,    -1,    46,    -1,    50,    21,    32,    47,    33,    48,
      -1,    50,    21,    32,    33,    48,    -1,    47,    38,    50,
      21,    -1,    47,    38,    50,    -1,    50,    21,    -1,    50,
      -1,    34,    52,    35,    -1,    34,    35,    -1,    50,    51,
      40,    -1,    11,    -1,    13,    -1,    15,    -1,    12,    -1,
      14,    -1,    51,    38,    21,    -1,    51,    38,    21,    36,
      22,    37,    -1,    21,    -1,    21,    36,    22,    37,    -1,
      53,    -1,    52,    53,    -1,    49,    -1,    54,    -1,    48,
      -1,     5,    32,    54,    54,    56,    33,    53,    -1,     3,
      32,    56,    33,    53,    -1,     3,    32,    56,    33,    53,
       4,    53,    -1,     6,    32,    56,    33,    53,    -1,    20,
      32,    21,    33,    40,    -1,    16,    56,    40,    -1,    40,
      -1,    56,    40,    -1,    21,    -1,    21,    36,    56,    37,
      -1,    57,    -1,    55,    29,    57,    -1,    58,    -1,    58,
      30,    58,    -1,    59,    -1,    59,    28,    59,    -1,    60,
      -1,    59,    24,    60,    -1,    61,    -1,    60,    25,    61,
      -1,    24,    61,    -1,    31,    61,    -1,    62,    -1,    63,
      -1,    55,    -1,    21,    32,    64,    33,    -1,    32,    56,
      33,    -1,    22,    -1,    23,    -1,    55,    26,    -1,    55,
      27,    -1,    65,    -1,    -1,    65,    38,    57,    -1,    57,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    43,    49,    56,    61,    68,    74,    82,
      88,    94,   100,   107,   113,   121,   129,   134,   139,   144,
     149,   156,   162,   168,   173,   181,   186,   194,   199,   204,
     209,   215,   221,   227,   233,   239,   247,   252,   260,   265,
     273,   278,   286,   291,   299,   304,   312,   317,   325,   330,
     338,   344,   350,   357,   364,   369,   375,   381,   386,   391,
     397,   405,   411,   417,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "SWITCH", "BREAK", "DEFAULT", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID",
  "RETURN", "CONTINUE", "CASE", "GOTO", "PRINTLN", "ID", "CONST_INT",
  "CONST_FLOAT", "ADDOP", "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP",
  "LOGICOP", "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD",
  "RTHIRD", "COMMA", "COLON", "SEMICOLON", "LOWER_THAN_ELSE", "$accept",
  "start", "program", "unit", "func_definition", "param_list",
  "compound_statement", "variable_decl", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor_info", "factor",
  "argument_list", "arguments", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    48,    48,    49,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     5,     4,
       3,     2,     1,     3,     2,     3,     1,     1,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     1,
       7,     5,     7,     5,     5,     3,     1,     2,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     1,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    19,    17,    20,    18,     0,     2,     4,     6,
       5,     0,     1,     3,    23,     0,     0,     0,     0,    15,
       0,     0,    12,     0,    21,     0,     8,     0,     0,    11,
      24,     0,     0,     0,     0,     0,     0,    38,    57,    58,
       0,     0,     0,    14,    36,    29,    27,     0,     0,    25,
      28,    54,     0,    40,    42,    44,    46,    48,    52,    53,
       7,    10,     0,     0,     0,     0,     0,     0,    62,     0,
      54,    50,    51,     0,    23,    13,    26,    59,    60,     0,
      37,     0,     0,     0,     0,     9,    22,     0,     0,     0,
      35,     0,    64,     0,    61,     0,    56,    41,    43,    47,
      45,    49,     0,     0,     0,     0,    55,     0,    39,    31,
       0,    33,    34,    63,     0,     0,    32,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    21,    45,    46,    47,    15,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    93,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
      84,   -68,   -68,   -68,   -68,   -68,     2,    84,   -68,   -68,
     -68,    -6,   -68,   -68,     0,   -24,     8,     5,    29,   -68,
      26,    -9,    41,    30,    28,    70,   -68,    26,    84,   -68,
     -68,    47,    31,    57,    68,    56,    71,     1,   -68,   -68,
      56,    56,    56,   -68,   -68,   -68,   -68,    86,   103,   -68,
     -68,    22,    72,   -68,    81,    15,    88,   -68,   -68,   -68,
     -68,    99,    85,    56,    34,    56,    89,   100,    56,    56,
      27,   -68,   -68,    95,    94,   -68,   -68,   -68,   -68,    56,
     -68,    56,    56,    56,    56,   -68,   -68,    98,    34,   107,
     -68,   111,   -68,   112,   108,    96,   -68,   -68,   -68,    88,
     129,   -68,   136,    56,   136,    92,   -68,    56,   -68,   132,
     121,   -68,   -68,   -68,   136,   136,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   148,   -68,   -68,   -14,    18,    10,   -68,
     -68,   -43,   -53,   -37,   -35,   -67,    80,    79,    82,   -32,
     -68,   -68,   -68,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      66,    92,    12,    70,    70,    76,    26,    73,    71,    72,
      11,    88,    97,    60,    18,    14,    19,    11,    10,     1,
       2,     3,     4,     5,    27,    10,    22,    23,    87,    28,
      89,    70,    16,    68,    95,   103,    17,    69,    61,    82,
     113,    20,    70,    83,    70,    70,    70,    70,    77,    78,
      24,    79,   101,    77,    78,    37,    38,    39,    40,   109,
      25,   111,    29,    63,    31,    41,    42,    30,   110,    62,
      70,   116,   117,    32,    44,    33,    34,    37,    38,    39,
      40,     1,     2,     3,     4,     5,    35,    41,    42,    64,
      36,    37,    38,    39,    40,     1,     2,     3,     4,     5,
      65,    41,    42,    67,    25,    43,    32,    74,    33,    34,
      44,    81,    80,    84,     1,     2,     3,     4,     5,    35,
      85,    91,    86,    36,    37,    38,    39,    40,    96,    90,
      17,   102,   112,   108,    41,    42,   114,    25,    75,    32,
     104,    33,    34,    44,   105,   106,   107,     1,     2,     3,
       4,     5,    35,    82,   115,    13,    36,    37,    38,    39,
      40,    98,   100,     0,    99,     0,     0,    41,    42,     0,
      25,     0,     0,     0,     0,     0,    44
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      35,    68,     0,    40,    41,    48,    20,    42,    40,    41,
       0,    64,    79,    27,    38,    21,    40,     7,     0,    11,
      12,    13,    14,    15,    33,     7,    16,    22,    63,    38,
      65,    68,    32,    32,    69,    88,    36,    36,    28,    24,
     107,    33,    79,    28,    81,    82,    83,    84,    26,    27,
      21,    29,    84,    26,    27,    21,    22,    23,    24,   102,
      34,   104,    21,    32,    36,    31,    32,    37,   103,    22,
     107,   114,   115,     3,    40,     5,     6,    21,    22,    23,
      24,    11,    12,    13,    14,    15,    16,    31,    32,    32,
      20,    21,    22,    23,    24,    11,    12,    13,    14,    15,
      32,    31,    32,    32,    34,    35,     3,    21,     5,     6,
      40,    30,    40,    25,    11,    12,    13,    14,    15,    16,
      21,    21,    37,    20,    21,    22,    23,    24,    33,    40,
      36,    33,    40,    37,    31,    32,     4,    34,    35,     3,
      33,     5,     6,    40,    33,    33,    38,    11,    12,    13,
      14,    15,    16,    24,    33,     7,    20,    21,    22,    23,
      24,    81,    83,    -1,    82,    -1,    -1,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    43,    44,    45,    46,
      49,    50,     0,    45,    21,    51,    32,    36,    38,    40,
      33,    47,    50,    22,    21,    34,    48,    33,    38,    21,
      37,    36,     3,     5,     6,    16,    20,    21,    22,    23,
      24,    31,    32,    35,    40,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      48,    50,    22,    32,    32,    32,    56,    32,    32,    36,
      55,    61,    61,    56,    21,    35,    53,    26,    27,    29,
      40,    30,    24,    28,    25,    21,    37,    56,    54,    56,
      40,    21,    57,    64,    65,    56,    33,    57,    58,    60,
      59,    61,    33,    54,    33,    33,    33,    38,    37,    53,
      56,    53,    40,    57,     4,    33,    53,    53
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
/* Line 1792 of yacc.c  */
#line 37 "syntax_analyzer.y"
    {
          print_rule("start : program", (yyvsp[(1) - (1)])->getnameofsymbol());
          (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "start");
      }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 44 "syntax_analyzer.y"
    {
            string text = (yyvsp[(1) - (2)])->getnameofsymbol() + "\n" + (yyvsp[(2) - (2)])->getnameofsymbol();
            print_rule("program : program unit", text);
            (yyval) = new symbol_info(text, "program");
        }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 50 "syntax_analyzer.y"
    {
            print_rule("program : unit", (yyvsp[(1) - (1)])->getnameofsymbol());
            (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "program");
        }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 57 "syntax_analyzer.y"
    {
         print_rule("unit : variable_decl", (yyvsp[(1) - (1)])->getnameofsymbol());
         (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "unit");
     }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 62 "syntax_analyzer.y"
    {
         print_rule("unit : func_definition", (yyvsp[(1) - (1)])->getnameofsymbol());
         (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "unit");
     }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 69 "syntax_analyzer.y"
    {
                    string text = (yyvsp[(1) - (6)])->getnameofsymbol() + " " + (yyvsp[(2) - (6)])->getnameofsymbol() + "(" + (yyvsp[(4) - (6)])->getnameofsymbol() + ")" + (yyvsp[(6) - (6)])->getnameofsymbol();
                    print_rule("func_definition : type_specifier ID LPAREN param_list RPAREN compound_statement", text);
                    (yyval) = new symbol_info(text, "func_definition");
                }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 75 "syntax_analyzer.y"
    {
                    string text = (yyvsp[(1) - (5)])->getnameofsymbol() + " " + (yyvsp[(2) - (5)])->getnameofsymbol() + "()" + (yyvsp[(5) - (5)])->getnameofsymbol();
                    print_rule("func_definition : type_specifier ID LPAREN RPAREN compound_statement", text);
                    (yyval) = new symbol_info(text, "func_definition");
                }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 83 "syntax_analyzer.y"
    {
               string text = (yyvsp[(1) - (4)])->getnameofsymbol() + "," + (yyvsp[(3) - (4)])->getnameofsymbol() + " " + (yyvsp[(4) - (4)])->getnameofsymbol();
               print_rule("param_list : param_list COMMA type_specifier ID", text);
               (yyval) = new symbol_info(text, "param_list");
           }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 89 "syntax_analyzer.y"
    {
               string text = (yyvsp[(1) - (3)])->getnameofsymbol() + "," + (yyvsp[(3) - (3)])->getnameofsymbol();
               print_rule("param_list : param_list COMMA type_specifier", text);
               (yyval) = new symbol_info(text, "param_list");
           }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 95 "syntax_analyzer.y"
    {
               string text = (yyvsp[(1) - (2)])->getnameofsymbol() + " " + (yyvsp[(2) - (2)])->getnameofsymbol();
               print_rule("param_list : type_specifier ID", text);
               (yyval) = new symbol_info(text, "param_list");
           }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 101 "syntax_analyzer.y"
    {
               print_rule("param_list : type_specifier", (yyvsp[(1) - (1)])->getnameofsymbol());
               (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "param_list");
           }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 108 "syntax_analyzer.y"
    {
                       string text = "{\n" + (yyvsp[(2) - (3)])->getnameofsymbol() + "\n}";
                       print_rule("compound_statement : LCURL statements RCURL", text);
                       (yyval) = new symbol_info(text, "compound_statement");
                   }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 114 "syntax_analyzer.y"
    {
                       string text = "{\n}";
                       print_rule("compound_statement : LCURL RCURL", text);
                       (yyval) = new symbol_info(text, "compound_statement");
                   }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 122 "syntax_analyzer.y"
    {
                  string text = (yyvsp[(1) - (3)])->getnameofsymbol() + " " + (yyvsp[(2) - (3)])->getnameofsymbol() + ";";
                  print_rule("variable_decl : type_specifier declaration_list SEMICOLON", text);
                  (yyval) = new symbol_info(text, "variable_decl");
              }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 130 "syntax_analyzer.y"
    {
                   print_rule("type_specifier : INT", "int");
                   (yyval) = new symbol_info("int", "type_specifier");
               }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 135 "syntax_analyzer.y"
    {
                   print_rule("type_specifier : FLOAT", "float");
                   (yyval) = new symbol_info("float", "type_specifier");
               }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 140 "syntax_analyzer.y"
    {
                   print_rule("type_specifier : VOID", "void");
                   (yyval) = new symbol_info("void", "type_specifier");
               }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 145 "syntax_analyzer.y"
    {
                   print_rule("type_specifier : CHAR", "char");
                   (yyval) = new symbol_info("char", "type_specifier");
               }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 150 "syntax_analyzer.y"
    {
                   print_rule("type_specifier : DOUBLE", "double");
                   (yyval) = new symbol_info("double", "type_specifier");
               }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 157 "syntax_analyzer.y"
    {
                     string text = (yyvsp[(1) - (3)])->getnameofsymbol() + "," + (yyvsp[(3) - (3)])->getnameofsymbol();
                     print_rule("declaration_list : declaration_list COMMA ID", text);
                     (yyval) = new symbol_info(text, "declaration_list");
                 }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 163 "syntax_analyzer.y"
    {
                     string text = (yyvsp[(1) - (6)])->getnameofsymbol() + "," + (yyvsp[(3) - (6)])->getnameofsymbol() + "[" + (yyvsp[(5) - (6)])->getnameofsymbol() + "]";
                     print_rule("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", text);
                     (yyval) = new symbol_info(text, "declaration_list");
                 }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 169 "syntax_analyzer.y"
    {
                     print_rule("declaration_list : ID", (yyvsp[(1) - (1)])->getnameofsymbol());
                     (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "declaration_list");
                 }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 174 "syntax_analyzer.y"
    {
                     string text = (yyvsp[(1) - (4)])->getnameofsymbol() + "[" + (yyvsp[(3) - (4)])->getnameofsymbol() + "]";
                     print_rule("declaration_list : ID LTHIRD CONST_INT RTHIRD", text);
                     (yyval) = new symbol_info(text, "declaration_list");
                 }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 182 "syntax_analyzer.y"
    {
               print_rule("statements : statement", (yyvsp[(1) - (1)])->getnameofsymbol());
               (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "statements");
           }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 187 "syntax_analyzer.y"
    {
               string text = (yyvsp[(1) - (2)])->getnameofsymbol() + "\n" + (yyvsp[(2) - (2)])->getnameofsymbol();
               print_rule("statements : statements statement", text);
               (yyval) = new symbol_info(text, "statements");
           }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 195 "syntax_analyzer.y"
    {
              print_rule("statement : variable_decl", (yyvsp[(1) - (1)])->getnameofsymbol());
              (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "statement");
          }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 200 "syntax_analyzer.y"
    {
              print_rule("statement : expression_statement", (yyvsp[(1) - (1)])->getnameofsymbol());
              (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "statement");
          }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 205 "syntax_analyzer.y"
    {
              print_rule("statement : compound_statement", (yyvsp[(1) - (1)])->getnameofsymbol());
              (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "statement");
          }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 210 "syntax_analyzer.y"
    {
              string text = "for(" + (yyvsp[(3) - (7)])->getnameofsymbol() + (yyvsp[(4) - (7)])->getnameofsymbol() + (yyvsp[(5) - (7)])->getnameofsymbol() + ")" + (yyvsp[(7) - (7)])->getnameofsymbol();
              print_rule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 216 "syntax_analyzer.y"
    {
              string text = "if(" + (yyvsp[(3) - (5)])->getnameofsymbol() + ")" + (yyvsp[(5) - (5)])->getnameofsymbol();
              print_rule("statement : IF LPAREN expression RPAREN statement", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 222 "syntax_analyzer.y"
    {
              string text = "if(" + (yyvsp[(3) - (7)])->getnameofsymbol() + ")" + (yyvsp[(5) - (7)])->getnameofsymbol() + "else" + (yyvsp[(7) - (7)])->getnameofsymbol();
              print_rule("statement : IF LPAREN expression RPAREN statement ELSE statement", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 228 "syntax_analyzer.y"
    {
              string text = "while(" + (yyvsp[(3) - (5)])->getnameofsymbol() + ")" + (yyvsp[(5) - (5)])->getnameofsymbol();
              print_rule("statement : WHILE LPAREN expression RPAREN statement", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 234 "syntax_analyzer.y"
    {
              string text = "printf(" + (yyvsp[(3) - (5)])->getnameofsymbol() + ");";
              print_rule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 240 "syntax_analyzer.y"
    {
              string text = "return " + (yyvsp[(2) - (3)])->getnameofsymbol() + ";";
              print_rule("statement : RETURN expression SEMICOLON", text);
              (yyval) = new symbol_info(text, "statement");
          }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 248 "syntax_analyzer.y"
    {
                         print_rule("expression_statement : SEMICOLON", ";");
                         (yyval) = new symbol_info(";", "expression_statement");
                     }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 253 "syntax_analyzer.y"
    {
                         string text = (yyvsp[(1) - (2)])->getnameofsymbol() + ";";
                         print_rule("expression_statement : expression SEMICOLON", text);
                         (yyval) = new symbol_info(text, "expression_statement");
                     }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 261 "syntax_analyzer.y"
    {
             print_rule("variable : ID", (yyvsp[(1) - (1)])->getnameofsymbol());
             (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "variable");
         }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 266 "syntax_analyzer.y"
    {
             string text = (yyvsp[(1) - (4)])->getnameofsymbol() + "[" + (yyvsp[(3) - (4)])->getnameofsymbol() + "]";
             print_rule("variable : ID LTHIRD expression RTHIRD", text);
             (yyval) = new symbol_info(text, "variable");
         }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 274 "syntax_analyzer.y"
    {
               print_rule("expression : logic_expression", (yyvsp[(1) - (1)])->getnameofsymbol());
               (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "expression");
           }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 279 "syntax_analyzer.y"
    {
               string text = (yyvsp[(1) - (3)])->getnameofsymbol() + "=" + (yyvsp[(3) - (3)])->getnameofsymbol();
               print_rule("expression : variable ASSIGNOP logic_expression", text);
               (yyval) = new symbol_info(text, "expression");
           }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 287 "syntax_analyzer.y"
    {
                     print_rule("logic_expression : rel_expression", (yyvsp[(1) - (1)])->getnameofsymbol());
                     (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "logic_expression");
                 }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 292 "syntax_analyzer.y"
    {
                     string text = (yyvsp[(1) - (3)])->getnameofsymbol() + (yyvsp[(2) - (3)])->getnameofsymbol() + (yyvsp[(3) - (3)])->getnameofsymbol();
                     print_rule("logic_expression : rel_expression LOGICOP rel_expression", text);
                     (yyval) = new symbol_info(text, "logic_expression");
                 }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 300 "syntax_analyzer.y"
    {
                   print_rule("rel_expression : simple_expression", (yyvsp[(1) - (1)])->getnameofsymbol());
                   (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "rel_expression");
               }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 305 "syntax_analyzer.y"
    {
                   string text = (yyvsp[(1) - (3)])->getnameofsymbol() + (yyvsp[(2) - (3)])->getnameofsymbol() + (yyvsp[(3) - (3)])->getnameofsymbol();
                   print_rule("rel_expression : simple_expression RELOP simple_expression", text);
                   (yyval) = new symbol_info(text, "rel_expression");
               }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 313 "syntax_analyzer.y"
    {
                      print_rule("simple_expression : term", (yyvsp[(1) - (1)])->getnameofsymbol());
                      (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "simple_expression");
                  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 318 "syntax_analyzer.y"
    {
                      string text = (yyvsp[(1) - (3)])->getnameofsymbol() + (yyvsp[(2) - (3)])->getnameofsymbol() + (yyvsp[(3) - (3)])->getnameofsymbol();
                      print_rule("simple_expression : simple_expression ADDOP term", text);
                      (yyval) = new symbol_info(text, "simple_expression");
                  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 326 "syntax_analyzer.y"
    {
         print_rule("term : unary_expression", (yyvsp[(1) - (1)])->getnameofsymbol());
         (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "term");
     }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 331 "syntax_analyzer.y"
    {
         string text = (yyvsp[(1) - (3)])->getnameofsymbol() + (yyvsp[(2) - (3)])->getnameofsymbol() + (yyvsp[(3) - (3)])->getnameofsymbol();
         print_rule("term : term MULOP unary_expression", text);
         (yyval) = new symbol_info(text, "term");
     }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 339 "syntax_analyzer.y"
    {
                     string text = (yyvsp[(1) - (2)])->getnameofsymbol() + (yyvsp[(2) - (2)])->getnameofsymbol();
                     print_rule("unary_expression : ADDOP unary_expression", text);
                     (yyval) = new symbol_info(text, "unary_expression");
                 }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 345 "syntax_analyzer.y"
    {
                     string text = "!" + (yyvsp[(2) - (2)])->getnameofsymbol();
                     print_rule("unary_expression : NOT unary_expression", text);
                     (yyval) = new symbol_info(text, "unary_expression");
                 }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 351 "syntax_analyzer.y"
    {
                     print_rule("unary_expression : factor_info", (yyvsp[(1) - (1)])->getnameofsymbol());
                     (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "unary_expression");
                 }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 358 "syntax_analyzer.y"
    {
                print_rule("factor_info : factor", (yyvsp[(1) - (1)])->getnameofsymbol());
                (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "factor_info");
            }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 365 "syntax_analyzer.y"
    {
           print_rule("factor : variable", (yyvsp[(1) - (1)])->getnameofsymbol());
           (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "factor");
       }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 370 "syntax_analyzer.y"
    {
           string text = (yyvsp[(1) - (4)])->getnameofsymbol() + "(" + (yyvsp[(3) - (4)])->getnameofsymbol() + ")";
           print_rule("factor : ID LPAREN argument_list RPAREN", text);
           (yyval) = new symbol_info(text, "factor");
       }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 376 "syntax_analyzer.y"
    {
           string text = "(" + (yyvsp[(2) - (3)])->getnameofsymbol() + ")";
           print_rule("factor : LPAREN expression RPAREN", text);
           (yyval) = new symbol_info(text, "factor");
       }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 382 "syntax_analyzer.y"
    {
           print_rule("factor : CONST_INT", (yyvsp[(1) - (1)])->getnameofsymbol());
           (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "factor");
       }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 387 "syntax_analyzer.y"
    {
           print_rule("factor : CONST_FLOAT", (yyvsp[(1) - (1)])->getnameofsymbol());
           (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "factor");
       }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 392 "syntax_analyzer.y"
    {
           string text = (yyvsp[(1) - (2)])->getnameofsymbol() + "++";
           print_rule("factor : variable INCOP", text);
           (yyval) = new symbol_info(text, "factor");
       }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 398 "syntax_analyzer.y"
    {
           string text = (yyvsp[(1) - (2)])->getnameofsymbol() + "--";
           print_rule("factor : variable DECOP", text);
           (yyval) = new symbol_info(text, "factor");
       }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 406 "syntax_analyzer.y"
    {
                  print_rule("argument_list : arguments", (yyvsp[(1) - (1)])->getnameofsymbol());
                  (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "argument_list");
              }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 411 "syntax_analyzer.y"
    {
                  print_rule("argument_list : ", "");
                  (yyval) = new symbol_info("", "argument_list");
              }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 418 "syntax_analyzer.y"
    {
              string text = (yyvsp[(1) - (3)])->getnameofsymbol() + "," + (yyvsp[(3) - (3)])->getnameofsymbol();
              print_rule("arguments : arguments COMMA logic_expression", text);
              (yyval) = new symbol_info(text, "arguments");
          }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 424 "syntax_analyzer.y"
    {
              print_rule("arguments : logic_expression", (yyvsp[(1) - (1)])->getnameofsymbol());
              (yyval) = new symbol_info((yyvsp[(1) - (1)])->getnameofsymbol(), "arguments");
          }
    break;


/* Line 1792 of yacc.c  */
#line 2148 "y.tab.c"
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


/* Line 2055 of yacc.c  */
#line 430 "syntax_analyzer.y"


void yyerror(const char *s)
{
    outlog << "Error at line no: " << lines << " : " << s << endl << endl;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Please provide input file name" << endl;
        return 0;
    }

    yyin = fopen(argv[1], "r");
    outlog.open("my_log.txt", ios::trunc);

    if(yyin == NULL)
    {
        cout << "Couldn't open file" << endl;
        return 0;
    }

    yyparse();

    outlog << "Total lines: " << lines << endl;

    outlog.close();
    fclose(yyin);

    return 0;
}