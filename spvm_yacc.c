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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         SPVM_yyparse
#define yylex           SPVM_yylex
#define yyerror         SPVM_yyerror
#define yydebug         SPVM_yydebug
#define yynerrs         SPVM_yynerrs


/* Copy the first part of user declarations.  */
#line 5 "yacc/spvm_yacc.y" /* yacc.c:339  */

  #include <stdio.h>
  
  #include "spvm_compiler.h"
  #include "spvm_yacc_util.h"
  #include "spvm_toke.h"
  #include "spvm_op.h"
  #include "spvm_dumper.h"
  #include "spvm_constant.h"

#line 83 "spvm_yacc.tab.c" /* yacc.c:339  */

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
   by #include "spvm_yacc.tab.h".  */
#ifndef YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED
# define YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int SPVM_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MY = 258,
    HAS = 259,
    SUB = 260,
    PACKAGE = 261,
    IF = 262,
    ELSIF = 263,
    ELSE = 264,
    RETURN = 265,
    FOR = 266,
    WHILE = 267,
    USE = 268,
    MALLOC = 269,
    LAST = 270,
    NEXT = 271,
    NAME = 272,
    VAR = 273,
    CONSTANT = 274,
    ENUM = 275,
    DESCRIPTOR = 276,
    CORETYPE = 277,
    UNDEF = 278,
    DIE = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    VOID = 283,
    EVAL = 284,
    EXCEPTION_VAR = 285,
    ASSIGN = 286,
    OR = 287,
    AND = 288,
    BIT_OR = 289,
    BIT_XOR = 290,
    BIT_AND = 291,
    REL = 292,
    SHIFT = 293,
    MULTIPLY = 294,
    DIVIDE = 295,
    REMAINDER = 296,
    NOT = 297,
    ARRAY_LENGTH = 298,
    UMINUS = 299,
    INC = 300,
    DEC = 301,
    ARROW = 302
  };
#endif

/* Value type.  */



int SPVM_yyparse (SPVM_COMPILER* compiler);

#endif /* !YY_SPVM_YY_SPVM_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "spvm_yacc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   867

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      53,    52,     2,    40,    57,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,    46,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    32,    33,    34,    35,
      36,    37,    38,    39,    42,    43,    44,    45,    47,    48,
      49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    62,    65,    78,    92,    95,    96,    99,
     105,   115,   118,   130,   144,   147,   148,   149,   152,   160,
     169,   172,   185,   199,   202,   208,   218,   221,   234,   248,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   262,
     270,   276,   277,   283,   289,   292,   298,   304,   310,   316,
     319,   333,   336,   340,   346,   352,   356,   361,   367,   371,
     377,   378,   379,   382,   386,   390,   394,   398,   402,   409,
     412,   425,   439,   442,   446,   452,   453,   454,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   470,   474,
     480,   486,   490,   494,   500,   505,   523,   528,   533,   538,
     543,   547,   553,   558,   563,   567,   571,   575,   579,   583,
     587,   591,   595,   599,   603,   607,   611,   617,   621,   625,
     631,   635,   639,   644,   648,   656,   659,   672,   686,   689,
     696,   699,   712,   726,   729,   730,   734,   740,   744,   750,
     754,   760,   761,   763,   764,   765,   768
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MY", "HAS", "SUB", "PACKAGE", "IF",
  "ELSIF", "ELSE", "RETURN", "FOR", "WHILE", "USE", "MALLOC", "LAST",
  "NEXT", "NAME", "VAR", "CONSTANT", "ENUM", "DESCRIPTOR", "CORETYPE",
  "UNDEF", "DIE", "SWITCH", "CASE", "DEFAULT", "VOID", "EVAL",
  "EXCEPTION_VAR", "';'", "ASSIGN", "OR", "AND", "BIT_OR", "BIT_XOR",
  "BIT_AND", "REL", "SHIFT", "'+'", "'-'", "MULTIPLY", "DIVIDE",
  "REMAINDER", "NOT", "'~'", "ARRAY_LENGTH", "UMINUS", "INC", "DEC",
  "ARROW", "')'", "'('", "'['", "'{'", "'}'", "','", "':'", "']'",
  "$accept", "grammar", "opt_declarations_in_grammar",
  "declarations_in_grammar", "declaration_in_grammar", "use", "package",
  "opt_declarations_in_package", "declarations_in_package",
  "declaration_in_package", "package_block", "enumeration_block",
  "opt_enumeration_values", "enumeration_values", "enumeration_value",
  "opt_statements", "statements", "statement", "block", "normal_statement",
  "normal_statement_for_end", "for_statement", "while_statement",
  "switch_statement", "case_statement", "default_statement",
  "if_statement", "else_statement", "field", "sub", "enumeration",
  "my_var", "expression", "opt_terms", "terms", "array_length", "term",
  "new_object", "convert_type", "call_field", "unop", "binop",
  "array_elem", "call_sub", "opt_args", "args", "arg", "opt_descriptors",
  "descriptors", "type", "type_name", "type_array",
  "type_array_with_length", "type_or_void", "field_name", "sub_name",
  "package_name", "eval_block", YY_NULLPTR
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
     285,    59,   286,   287,   288,   289,   290,   291,   292,   293,
      43,    45,   294,   295,   296,   297,   126,   298,   299,   300,
     301,   302,    41,    40,    91,   123,   125,    44,    58,    93
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -146

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-146)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,    -6,    -6,    14,  -196,    39,  -196,  -196,  -196,  -196,
     -35,     3,  -196,  -196,    33,  -196,  -196,    47,    51,    17,
      21,    33,  -196,  -196,  -196,  -196,  -196,    22,  -196,    26,
      67,  -196,  -196,  -196,    68,    70,    54,    46,    50,  -196,
    -196,    58,    49,    56,    55,    52,    57,  -196,    93,  -196,
      67,  -196,    65,    72,    68,    75,    70,  -196,  -196,  -196,
    -196,  -196,    95,  -196,  -196,    -9,    77,  -196,  -196,   -24,
     105,  -196,   241,  -196,  -196,   109,    82,   395,    83,    84,
      68,  -196,  -196,    87,   116,  -196,  -196,   395,    96,   395,
      92,   101,   119,  -196,   395,   395,   395,   395,   281,   395,
     395,   435,   106,   241,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   127,   130,  -196,   641,  -196,  -196,   -22,
    -196,  -196,   -11,  -196,   111,   114,  -196,   113,   395,  -196,
     781,    -7,    -4,   329,   395,   120,   123,  -196,   395,   781,
     395,   591,  -196,  -196,   395,     5,     5,     5,     5,   395,
       5,     9,     9,   -36,   681,   115,  -196,  -196,   395,  -196,
    -196,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,  -196,  -196,   -14,   395,   395,    47,   395,
     395,    47,   395,    51,    68,   701,   395,   721,   165,   190,
     781,   741,  -196,   781,   617,  -196,   395,   781,   799,   816,
     103,   103,   274,   428,    79,    32,    32,     5,     5,     5,
     395,    47,   125,   781,   456,   117,   781,   483,   124,   129,
     132,   781,   133,  -196,   101,   662,   101,   510,   537,   101,
    -196,  -196,   564,   131,   395,  -196,  -196,  -196,  -196,  -196,
     395,   395,    53,   370,  -196,  -196,  -196,  -196,  -196,  -196,
     139,   781,   140,   143,   101,  -196,   146,  -196,   781,  -196,
    -196,   395,  -196,   101,   761,  -196,   101,    53,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     2,     4,     6,     7,     8,   145,
       0,     0,     1,     5,    11,    10,     9,     0,     0,     0,
       0,    12,    14,    15,    16,    17,   143,     0,   144,     0,
      20,    57,    18,    13,     0,   125,    24,     0,    21,    23,
     136,     0,   134,   135,     0,     0,   126,   128,     0,    19,
       0,    54,     0,     0,     0,     0,     0,    25,    22,   137,
     138,   129,   130,   127,   133,     0,   131,   142,   141,     0,
       0,    56,    26,    55,   132,     0,     0,    62,     0,     0,
       0,    60,    61,   144,    75,    77,    78,    64,     0,     0,
       0,     0,    76,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    29,    34,    30,    32,    33,    35,
      36,    37,    31,    87,     0,    86,     0,    85,    84,    80,
      81,    82,    83,    79,     0,     0,    38,    59,     0,    76,
      63,    80,    83,     0,     0,    88,     0,    89,     0,    65,
       0,     0,    49,   146,     0,    94,    95,   101,   100,     0,
      73,    96,    98,   136,     0,     0,    39,    28,     0,    41,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    99,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
     113,     0,    48,    68,     0,   114,     0,   112,   115,   116,
     109,   107,   108,   111,   110,   102,   103,   104,   105,   106,
       0,     0,   122,    66,     0,     0,    67,     0,     0,     0,
      70,    72,   124,    58,     0,     0,     0,     0,     0,     0,
      74,    90,     0,     0,    69,   119,    92,   118,    93,   120,
       0,    69,    51,     0,    46,   139,   140,    47,   117,    91,
       0,    71,     0,     0,     0,    50,     0,    44,    43,   121,
     123,     0,    52,     0,     0,    45,     0,    51,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,   194,  -196,  -196,  -196,  -196,   179,
    -196,  -196,  -196,  -196,   151,  -196,  -196,    99,   -69,    86,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   -64,  -196,  -196,
    -196,  -196,   -27,  -195,  -196,  -196,   -71,  -196,  -196,   -68,
    -196,  -196,   -67,  -196,  -196,  -196,   161,  -196,  -196,   -52,
     141,   142,  -196,  -196,  -169,   -17,    69,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    20,    21,    22,
      15,    31,    37,    38,    39,   102,   103,   104,   105,   106,
     256,   107,   108,   109,   110,   111,   112,   255,    23,    24,
      25,   113,   114,   219,   220,   115,   116,   117,   118,   131,
     120,   121,   132,   123,    45,    46,    47,    65,    66,    41,
      42,    43,   137,    69,    27,   124,   125,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    29,    61,    28,   119,   122,   130,    71,    40,   215,
     176,     9,   218,    68,    12,  -145,   139,  -144,   141,    67,
      14,   179,   143,   145,   146,   147,   148,   150,   151,   152,
     154,    72,   177,   178,    16,   119,   122,    17,    18,   250,
     210,   211,   233,   180,   181,     1,   252,   177,   178,   155,
     180,   181,     2,    19,   173,   174,   175,   185,  -146,  -146,
     175,   253,   254,   187,    26,   119,   122,   190,    28,   191,
      10,    11,    30,   193,   170,   171,   172,    32,   194,    35,
      34,   173,   174,   175,    36,    40,    48,   197,    44,    51,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    49,    52,    55,   213,   214,    50,   216,   217,
      53,   221,    57,    54,    56,   225,    64,   227,   228,   168,
     169,   170,   171,   172,    59,   231,    74,   127,   173,   174,
     175,    60,   223,    62,    70,   128,   133,   134,  -145,   232,
     165,   166,   167,   168,   169,   170,   171,   172,   138,   140,
     142,   144,   173,   174,   175,   242,    72,   244,   212,   158,
     247,   159,   156,   221,   182,   183,   222,   196,    75,   251,
     221,   184,   258,   236,   188,   119,   122,   189,   234,    80,
     238,   239,    83,    84,    85,   262,   241,   249,    86,   240,
     264,   259,   260,    75,   265,   129,   261,   267,   263,    13,
      33,    58,   157,   268,    80,    94,    95,    83,    84,    85,
      96,    97,    98,    86,    99,   100,   257,    63,   101,   186,
     129,   135,   136,     0,    59,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,    96,    97,    98,     0,    99,
     100,     0,     0,   101,    75,     0,     0,     0,    76,    60,
       0,    77,    78,    79,     0,    80,    81,    82,    83,    84,
      85,     0,     0,     0,    86,    87,    88,    89,    90,     0,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,    75,     0,    96,    97,    98,     0,
      99,   100,     0,     0,   101,    80,    72,     0,    83,    84,
      85,     0,     0,     0,    86,     0,     0,     0,     0,     0,
       0,   129,   166,   167,   168,   169,   170,   171,   172,     0,
       0,    94,    95,   173,   174,   175,    96,    97,    98,     0,
      99,   100,    75,     0,   101,     0,   149,     0,     0,    77,
       0,     0,     0,    80,    81,    82,    83,    84,    85,     0,
       0,     0,    86,    87,     0,     0,     0,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,    75,    96,    97,    98,     0,    99,   100,
      77,     0,   101,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,    86,    87,     0,     0,     0,    75,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      94,    95,    83,    84,    85,    96,    97,    98,    86,    99,
     100,     0,     0,   101,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,    75,     0,
      96,    97,    98,     0,    99,   100,     0,     0,   101,    80,
       0,     0,   153,    84,    85,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,   129,  -146,   167,   168,   169,
     170,   171,   172,     0,     0,    94,    95,   173,   174,   175,
      96,    97,    98,     0,    99,   100,     0,     0,   101,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   173,   174,   175,     0,     0,
       0,     0,     0,     0,     0,   235,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,     0,
       0,     0,   173,   174,   175,     0,     0,     0,     0,     0,
       0,     0,   237,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,     0,     0,   245,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,   173,   174,   175,     0,
       0,     0,     0,     0,     0,     0,   246,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,   173,   174,   175,     0,     0,     0,     0,
       0,     0,     0,   248,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,     0,     0,     0,     0,     0,     0,   192,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,   173,   174,   175,     0,
       0,     0,   160,   230,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   243,     0,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,   173,   174,   175,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   195,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   224,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   226,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   229,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   266,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   174,   175,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     0,     0,     0,     0,   173,   174,
     175,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
      69,    18,    54,    17,    72,    72,    77,    31,    17,   178,
      32,    17,   181,    65,     0,    51,    87,    53,    89,    28,
      55,    32,    91,    94,    95,    96,    97,    98,    99,   100,
     101,    55,    54,    55,    31,   103,   103,     4,     5,   234,
      54,    55,   211,    54,    55,     6,   241,    54,    55,   101,
      54,    55,    13,    20,    49,    50,    51,   128,    49,    50,
      51,     8,     9,   134,    17,   133,   133,   138,    17,   140,
       1,     2,    55,   144,    42,    43,    44,    56,   149,    53,
      58,    49,    50,    51,    17,    17,    32,   158,    18,    31,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    56,    54,    52,   176,   177,    57,   179,   180,
      54,   182,    19,    58,    57,   186,    21,   188,   189,    40,
      41,    42,    43,    44,    59,   196,    21,    18,    49,    50,
      51,    59,   184,    58,    57,    53,    53,    53,    51,   210,
      37,    38,    39,    40,    41,    42,    43,    44,    32,    53,
      58,    32,    49,    50,    51,   224,    55,   226,   175,    32,
     229,    31,    56,   234,    53,    51,   183,    52,     3,   240,
     241,    58,   243,    56,    54,   243,   243,    54,    53,    14,
      56,    52,    17,    18,    19,   254,    53,    56,    23,    57,
     261,    52,    52,     3,   263,    30,    53,   266,    52,     5,
      21,    50,   103,   267,    14,    40,    41,    17,    18,    19,
      45,    46,    47,    23,    49,    50,   243,    56,    53,   133,
      30,    80,    80,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    -1,    -1,    53,     3,    -1,    -1,    -1,     7,    59,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,     3,    -1,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    53,    14,    55,    -1,    17,    18,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    40,    41,    49,    50,    51,    45,    46,    47,    -1,
      49,    50,     3,    -1,    53,    -1,    55,    -1,    -1,    10,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,     3,    45,    46,    47,    -1,    49,    50,
      10,    -1,    53,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,     3,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      40,    41,    17,    18,    19,    45,    46,    47,    23,    49,
      50,    -1,    -1,    53,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,     3,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    53,    14,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    40,    41,    49,    50,    51,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    53,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    31,    56,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    50,    51,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,    50,
      51,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    13,    61,    62,    63,    64,    65,    66,    17,
     116,   116,     0,    64,    55,    70,    31,     4,     5,    20,
      67,    68,    69,    88,    89,    90,    17,   114,    17,   115,
      55,    71,    56,    69,    58,    53,    17,    72,    73,    74,
      17,   109,   110,   111,    18,   104,   105,   106,    32,    56,
      57,    31,    54,    54,    58,    52,    57,    19,    74,    59,
      59,   109,    58,   106,    21,   107,   108,    28,   109,   113,
      57,    31,    55,    78,    21,     3,     7,    10,    11,    12,
      14,    15,    16,    17,    18,    19,    23,    24,    25,    26,
      27,    29,    30,    31,    40,    41,    45,    46,    47,    49,
      50,    53,    75,    76,    77,    78,    79,    81,    82,    83,
      84,    85,    86,    91,    92,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   115,   116,   117,    18,    53,    30,
      96,    99,   102,    53,    53,   110,   111,   112,    32,    96,
      53,    96,    58,    78,    32,    96,    96,    96,    96,    55,
      96,    96,    96,    17,    96,   109,    56,    77,    32,    31,
      31,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    49,    50,    51,    32,    54,    55,    32,
      54,    55,    53,    51,    58,    96,    79,    96,    54,    54,
      96,    96,    58,    96,    96,    52,    52,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      54,    55,   115,    96,    96,   114,    96,    96,   114,    93,
      94,    96,   115,   109,    52,    96,    52,    96,    96,    52,
      56,    96,    96,   114,    53,    59,    56,    59,    56,    52,
      57,    53,    78,    31,    78,    59,    59,    78,    59,    56,
      93,    96,    93,     8,     9,    87,    80,    92,    96,    52,
      52,    53,    78,    52,    96,    78,    52,    78,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    79,    80,    80,    81,    82,    83,    84,    85,
      86,    87,    87,    87,    88,    89,    89,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   113,   113,   114,   115,   116,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     3,
       3,     0,     1,     2,     1,     1,     1,     1,     3,     3,
       0,     1,     3,     1,     1,     3,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     1,     1,     1,     8,     5,     5,     3,     2,
       6,     0,     2,     6,     5,     9,     9,     2,     4,     2,
       1,     1,     1,     2,     1,     2,     3,     3,     3,     0,
       1,     3,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     5,     4,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     6,     3,     6,     3,     0,     1,     3,     1,     3,
       0,     1,     3,     1,     1,     1,     1,     3,     3,     4,
       4,     1,     1,     1,     1,     1,     2
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
      yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SPVM_COMPILER* compiler)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (compiler);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SPVM_COMPILER* compiler)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, compiler);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, SPVM_COMPILER* compiler)
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
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, SPVM_COMPILER* compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (SPVM_COMPILER* compiler)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, compiler);
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
#line 51 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_grammar(compiler, (yyvsp[0].opval));

      // Syntax error
      if (compiler->error_count) {
        YYABORT;
      }
    }
#line 1587 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 1595 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 1610 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-1].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-1].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-1].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 1628 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_use(compiler, (yyvsp[-2].opval), (yyvsp[-1].opval));
    }
#line 1636 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_package(compiler, (yyvsp[-2].opval), (yyvsp[-1].opval), (yyvsp[0].opval));
      if (compiler->fatal_error) {
        YYABORT;
      }
    }
#line 1647 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 1655 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        (yyval.opval) = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, (yyval.opval), (yyval.opval)->last, (yyvsp[0].opval));
      }
    }
#line 1669 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-1].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-1].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-1].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 1687 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_class_block = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_CLASS_BLOCK, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
      SPVM_OP_insert_child(compiler, op_class_block, op_class_block->last, (yyvsp[-1].opval));
      (yyval.opval) = op_class_block;
    }
#line 1697 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 161 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_enum_block = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_ENUM_BLOCK, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
      SPVM_OP_insert_child(compiler, op_enum_block, op_enum_block->last, (yyvsp[-1].opval));
      (yyval.opval) = op_enum_block;
    }
#line 1707 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 1715 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 1730 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-2].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-2].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-2].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 1748 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 203 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_enumeration_value = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_ENUMERATION_VALUE, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
      SPVM_OP_insert_child(compiler, op_enumeration_value, op_enumeration_value->last, (yyvsp[0].opval));
      (yyval.opval) = op_enumeration_value;
    }
#line 1758 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 209 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_enumeration_value = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_ENUMERATION_VALUE, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
      SPVM_OP_insert_child(compiler, op_enumeration_value, op_enumeration_value->last, (yyvsp[-2].opval));
      SPVM_OP_insert_child(compiler, op_enumeration_value, op_enumeration_value->last, (yyvsp[0].opval));
      (yyval.opval) = op_enumeration_value;
    }
#line 1769 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 218 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 1777 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 222 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 1792 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 235 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-1].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-1].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-1].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 1810 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 263 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_code_block = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_BLOCK, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
      SPVM_OP_insert_child(compiler, op_code_block, op_code_block->last, (yyvsp[-1].opval));
      (yyval.opval) = op_code_block;
    }
#line 1820 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 271 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_pop = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_POP, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      SPVM_OP_insert_child(compiler, op_pop, op_pop->last, (yyvsp[-1].opval));
      (yyval.opval) = op_pop;
    }
#line 1830 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 278 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_NULL, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
    }
#line 1838 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 284 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_pop = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_POP, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
      SPVM_OP_insert_child(compiler, op_pop, op_pop->last, (yyvsp[0].opval));
      (yyval.opval) = op_pop;
    }
#line 1848 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 293 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_for_statement(compiler, (yyvsp[-7].opval), (yyvsp[-5].opval), (yyvsp[-4].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 1856 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 299 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_while_statement(compiler, (yyvsp[-4].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 1864 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 305 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_switch_statement(compiler, (yyvsp[-4].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 1872 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 311 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_case_statement(compiler, (yyvsp[-2].opval), (yyvsp[-1].opval));
    }
#line 1880 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 320 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_if = SPVM_OP_build_if_statement(compiler, (yyvsp[-5].opval), (yyvsp[-3].opval), (yyvsp[-1].opval), (yyvsp[0].opval));
      
      // if is wraped with block to allow the following syntax
      //  if (my $var = 3) { ... }
      SPVM_OP* op_block = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_BLOCK, (yyvsp[-5].opval)->file, (yyvsp[-5].opval)->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, op_if);
      
      (yyval.opval) = op_block;
    }
#line 1895 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 333 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_NULL, compiler->cur_file, compiler->cur_line);
    }
#line 1903 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 337 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = (yyvsp[0].opval);
    }
#line 1911 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 341 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_if_statement(compiler, (yyvsp[-5].opval), (yyvsp[-3].opval), (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 1919 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 347 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_field(compiler, (yyvsp[-4].opval), (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 1927 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 353 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[-8].opval), (yyvsp[-7].opval), (yyvsp[-5].opval), (yyvsp[-2].opval), (yyvsp[-1].opval), (yyvsp[0].opval));
     }
#line 1935 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 357 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[-8].opval), (yyvsp[-7].opval), (yyvsp[-5].opval), (yyvsp[-2].opval), (yyvsp[-1].opval), NULL);
     }
#line 1943 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 362 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_enumeration(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 1951 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 368 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_my_var(compiler, (yyvsp[-3].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 1959 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 372 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_my_var(compiler, (yyvsp[-1].opval), (yyvsp[0].opval), NULL);
    }
#line 1967 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 379 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_return(compiler, (yyvsp[0].opval), NULL);
    }
#line 1975 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 383 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_return(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 1983 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 387 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_die(compiler, (yyvsp[0].opval), NULL);
    }
#line 1991 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 391 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_die(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 1999 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 395 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_assignop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2007 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 399 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_assignop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2015 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 403 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_assignop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2023 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 409 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 2031 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 413 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 2046 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 426 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-2].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-2].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-2].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 2064 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 443 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_array_length(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2072 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 447 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_array_length(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2080 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 455 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_constant(compiler, (yyvsp[0].opval));
    }
#line 2088 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 471 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_malloc_object(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2096 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 475 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_malloc_object(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2104 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 481 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_convert_type(compiler, (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2112 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 487 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_field(compiler, (yyvsp[-4].opval), (yyvsp[-1].opval));
    }
#line 2120 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 491 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_field(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2128 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 495 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_field(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2136 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 501 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_PLUS, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[0].opval));
    }
#line 2145 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 506 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_CONSTANT) {
        SPVM_CONSTANT* constant = (yyvsp[0].opval)->uv.constant;
        if (constant->code == SPVM_CONSTANT_C_CODE_INT || constant->code == SPVM_CONSTANT_C_CODE_LONG) {
          constant->sign = 1;
          (yyval.opval) = (yyvsp[0].opval);
        }
        else {
          SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_NEGATE, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
          (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[0].opval));
        }
      }
      else {
        SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_NEGATE, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
        (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[0].opval));
      }
    }
#line 2167 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 524 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_PRE_INC, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[0].opval));
    }
#line 2176 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 529 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_POST_INC, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[-1].opval));
    }
#line 2185 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 534 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_PRE_DEC, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[0].opval));
    }
#line 2194 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 539 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_POST_DEC, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[-1].opval));
    }
#line 2203 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 544 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_unop(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2211 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 548 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_unop(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2219 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 554 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_ADD, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_binop(compiler, op, (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2228 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 559 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_SUBTRACT, (yyvsp[-1].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_binop(compiler, op, (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2237 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 564 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2245 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 568 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2253 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 572 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2261 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 576 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2269 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 580 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2277 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 584 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2285 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 588 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2293 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 592 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2301 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 596 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_assignop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2309 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 600 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_assignop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2317 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 604 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = (yyvsp[-1].opval);
    }
#line 2325 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 608 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2333 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 612 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[-1].opval), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2341 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 618 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_array_elem(compiler, (yyvsp[-4].opval), (yyvsp[-1].opval));
    }
#line 2349 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 622 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_array_elem(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2357 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 626 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_array_elem(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2365 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 632 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_NULL, (yyvsp[-3].opval)->file, (yyvsp[-3].opval)->line), (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2373 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 636 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[-5].opval), (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2381 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 640 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_terms = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[-2].opval), (yyvsp[0].opval), op_terms);
    }
#line 2390 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 645 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[-5].opval), (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2398 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 649 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_terms = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-1].opval)->line);
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[-2].opval), (yyvsp[0].opval), op_terms);
    }
#line 2407 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 656 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 2415 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 660 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 2430 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 673 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-2].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-2].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-2].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 2448 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 690 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_my_var(compiler, SPVM_OP_new_op(compiler, SPVM_OP_C_CODE_MY, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line), (yyvsp[-2].opval), (yyvsp[0].opval));
    }
#line 2456 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 696 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    }
#line 2464 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 700 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].opval)->code == SPVM_OP_C_CODE_LIST) {
        (yyval.opval) = (yyvsp[0].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[0].opval)->file, (yyvsp[0].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->first, (yyvsp[0].opval));
        (yyval.opval) = op_list;
      }
    }
#line 2479 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 713 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      SPVM_OP* op_list;
      if ((yyvsp[-2].opval)->code == SPVM_OP_C_CODE_LIST) {
        op_list = (yyvsp[-2].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[-2].opval)->file, (yyvsp[-2].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[-2].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[0].opval));
      
      (yyval.opval) = op_list;
    }
#line 2497 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 735 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_type_name(compiler, (yyvsp[0].opval));
    }
#line 2505 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 741 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_type_array(compiler, (yyvsp[-2].opval), NULL);
    }
#line 2513 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 745 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_type_array(compiler, (yyvsp[-2].opval), NULL);
    }
#line 2521 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 751 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_type_array(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2529 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 755 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_type_array(compiler, (yyvsp[-3].opval), (yyvsp[-1].opval));
    }
#line 2537 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 769 "yacc/spvm_yacc.y" /* yacc.c:1646  */
    {
      (yyval.opval) = SPVM_OP_build_eval(compiler, (yyvsp[-1].opval), (yyvsp[0].opval));
    }
#line 2545 "spvm_yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2549 "spvm_yacc.tab.c" /* yacc.c:1646  */
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
      yyerror (compiler, YY_("syntax error"));
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
        yyerror (compiler, yymsgp);
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
                      yytoken, &yylval, compiler);
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
                  yystos[yystate], yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, compiler);
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
#line 773 "yacc/spvm_yacc.y" /* yacc.c:1906  */


