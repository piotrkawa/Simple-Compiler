/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "gram.ypp" /* yacc.c:339  */


  /* ========================================= */
  /*               NOTATKI                     */
  /* ========================================= */

  /*
    [ ] inicjalizowanie tablic     ----> a := c nie wywala bledu
    [ ] PRECEDENS DLA MODULO
  */

  //code
  #include <cstdlib>
  #include <iostream>

  #include <cstring>
  #include <string>
  #include <map>
  #include <stack>
  #include <vector>
  #include <stdio.h>
  #include <stdlib.h>

  extern "C" int yylex();
  extern "C" int yyparse();

  /*===================================================*/
  /*                      CONSTANTS                    */
  /*===================================================*/

  #define NUMBER_OF_LAST_RESERVED_MEMORY_INDEX 10
  #define ERROR_BUFFER 150
  #define ARRAY_INDEX_OFFSET 1
  #define JUMP_PLACEHOLDER_ADDRESS -3000


  /*===================================================*/
  /*                      VARIABLES                    */
  /*===================================================*/

  int currentMemoryIndex = NUMBER_OF_LAST_RESERVED_MEMORY_INDEX;
  int numberOfCommands   = 0;

  /*===================================================*/
  /*                     STRUCTURES                    */
  /*===================================================*/

  int equationElementAddress;
  int firstElementAddress;
  int secondElementAddress;
  int arrayIdentifierAddress;
  int firstArrayIdentifierAddress;
  int arrayIndexOfFirstElement;


  std::string variableNameGlobal;
  std::string firstElementName;


  bool isDebugOn = false;

  int accumulator;
  int currentArrayIndex;
  int currentArrayIndex_assign;
  char errorMessage[ERROR_BUFFER];
  int currentArrayAssignAddress;

  int iteratorsAddress;


  std::string valueFormat1;
  std::string valueFormat2;
  std::string expressionType[2];
  std::string expressionType2[2];

  /*vector containing commands*/
	std::vector<std::string> commandsVector;

  /* declaredVariables */
  /* <nazwa, adres w pamięci> */
  std::map<std::string, int> variablesAddressesMap;

  /* each initialized variable */
  // <nazwa, czy zainicjalizowane>
  std::map<std::string, bool> initializedVariablesMap;

  /* each array's size */
  /* if a variable is in here then it's an array - useful when determining type of a data*/
  // <nazwa, rozmiar tablicy>
  std::map<std::string, int> arraysMap;

  std::stack<std::pair<int, int>> jumpStack;

  // wrzucam na niego adres powrotu w petlach (adres ponownego wyliczenia warunku petli)
  std::stack<int> returnStack;

  std::stack<int> elseStack;


  // int yylex();
  void yyerror (char* msg);

  /*===================================================*/
  /*                      FUNCTIONS                    */
  /*===================================================*/

  // used for declaring a variable
  void declareAVariable(std::string name);
  // used for declaring an array
  void declareAnArray(std::string name, int arraySize);

  // function used for determining whether variable is declared
  bool isVariableDeclared(std::map<std::string, int> *mapToSearch, std::string name);

  bool isVariableInitialized(std::map<std::string, bool>* initializedMap, std::string variableName);

  // debug function performed at the end of parsing
  void finish();

  void displayMap(std::map<std::string, int>* mapToDisplay);
  void displayInitializedMap(std::map<std::string, bool>* map);
  void displayCommandVector(std::vector<std::string>* commandsVector);

  void showAllocatedMemoryIndexes();

  void pushCodeWithAddress(std::string opCode, int number);
  void pushCode(std::string opCode);

  void generateNumber(std::string);
  int computeRequiredMemoryCell(std::string variableName, int currentArrayIndex);

  std::string determineDataType(std::string, std::string);
  void changeJumpValue();

  void changeJumpValue(int value);
  void changeJumpValueForLoop();
  void changeElseValue(int value);

  void setEquationAttributes();


#line 208 "gram.tab.cpp" /* yacc.c:339  */

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
   by #include "gram.tab.hpp".  */
#ifndef YY_YY_GRAM_TAB_HPP_INCLUDED
# define YY_YY_GRAM_TAB_HPP_INCLUDED
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
    VAR = 258,
    BEG = 259,
    END = 260,
    IF = 261,
    THEN = 262,
    ELSE = 263,
    ENDIF = 264,
    WHILE = 265,
    DO = 266,
    ENDWHILE = 267,
    FOR = 268,
    FROM = 269,
    TO = 270,
    ENDFOR = 271,
    DOWNTO = 272,
    READ = 273,
    WRITE = 274,
    ASSGN = 275,
    EQ = 276,
    NEQ = 277,
    GT = 278,
    GE = 279,
    LT = 280,
    LE = 281,
    ADD = 282,
    SUB = 283,
    MUL = 284,
    DIV = 285,
    MOD = 286,
    num = 287,
    PID = 288,
    SEM = 289,
    LEFT_BR = 290,
    RIGHT_BR = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 143 "gram.ypp" /* yacc.c:355  */

    char* string;
    int   num;

#line 290 "gram.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAM_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 305 "gram.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
       2,     2,    39,    38,     2,    37,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   177,   177,   181,   184,   188,   193,   194,   197,   197,
     253,   256,   260,   253,   281,   285,   285,   298,   309,   327,
     477,   298,   503,   505,   503,   510,   549,   595,   610,   610,
     766,   766,   942,   942,   990,   991,   994,   994,  1288,  1288,
    1373,  1373,  1566,  1566,  1745,  1745,  1923,  1923,  2083,  2088,
    2106,  2119,  2137
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "BEG", "END", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FOR", "FROM", "TO",
  "ENDFOR", "DOWNTO", "READ", "WRITE", "ASSGN", "EQ", "NEQ", "GT", "GE",
  "LT", "LE", "ADD", "SUB", "MUL", "DIV", "MOD", "num", "PID", "SEM",
  "LEFT_BR", "RIGHT_BR", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'",
  "$accept", "program", "vdeclarations", "commands", "command", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "expression", "$@12", "$@13", "$@14", "condition", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "value", "identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    45,    43,    42,
      47,    37,    94
};
# endif

#define YYPACT_NINF -28

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -28,    13,    -2,   -28,   129,   -20,   -26,   -28,   -17,
     -15,   -26,   -16,     4,   -28,   -28,   -11,   -28,    28,    20,
     -28,   -26,   -28,     2,     5,   -21,   -28,   -28,     9,    18,
     129,    19,    16,    30,    34,    32,    36,    51,    59,    61,
     -28,   -28,    40,    41,   -26,   -28,    97,   -26,   -26,   -26,
     -26,   -26,   -26,   129,   -26,   -26,   -28,   -28,    44,    22,
     -28,    71,   -28,   -28,   -28,   -28,   -28,   -28,   107,   -28,
      65,   -28,   -26,   -26,    56,    57,    55,   -28,   -28,    78,
     -28,   -28,   -28,   -26,   -26,   -26,   129,   -26,   -26,   -28,
     -28,   -28,   129,   -28,    75,    85,    86,   129,   -28,   -28,
      14,   129,   -28,   118,   -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     1,     0,     3,     0,    15,     0,
       0,     0,    50,     0,     7,     8,     0,    48,     0,    36,
      49,     0,    17,     0,     0,     0,     2,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     4,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    51,     0,    27,
      14,     0,    37,    39,    41,    43,    45,    47,     0,    18,
       0,     9,     0,     0,     0,     0,     0,    11,    16,     0,
      23,    34,    35,     0,     0,     0,     0,     0,     0,    29,
      31,    33,    12,    19,     0,     0,     0,     0,    13,    20,
       0,     0,    24,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -27,   -12,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
      87,   -28,   -28,   -28,   -28,   -28,   -28,    17,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    14,    28,    61,    86,    95,    21,
      38,    79,    96,   101,    39,    88,    58,    74,    75,    76,
      18,    31,    32,    33,    34,    35,    36,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    27,     5,    46,     1,    23,    17,    12,    15,    26,
       7,    42,    43,     4,     8,    16,    22,     9,    12,    25,
       7,    29,    10,    11,     8,    15,    68,     9,    24,    44,
     102,     6,    10,    11,    27,    30,    40,    12,    48,    41,
      47,    15,   -38,   -42,   -46,   -40,   -44,    12,    15,   -28,
     -30,   -32,    72,    73,    45,    49,    27,    50,    51,    92,
      52,    59,    53,    15,    62,    63,    64,    65,    66,    67,
     100,    69,    70,    54,   103,    55,    56,    57,    71,    77,
      27,    15,    80,    83,    85,    84,    97,    15,    27,    81,
      82,    27,    15,    87,    98,    15,    15,    99,    15,     0,
      89,    90,    91,     7,    93,    94,    60,     8,    37,     0,
       9,     0,     0,     7,     0,    10,    11,     8,     0,    78,
       9,     0,     0,     0,     7,    10,    11,     0,     8,     0,
      12,     9,     0,     0,   104,     7,    10,    11,     0,     8,
      12,     0,     9,     0,     0,     0,     0,    10,    11,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12
};

static const yytype_int8 yycheck[] =
{
       5,    13,     4,    30,     3,    10,    32,    33,    13,     5,
       6,    32,    33,     0,    10,    35,    33,    13,    33,    35,
       6,    32,    18,    19,    10,    30,    53,    13,    11,    20,
      16,    33,    18,    19,    46,     7,    34,    33,    22,    34,
      21,    46,    22,    23,    24,    25,    26,    33,    53,    27,
      28,    29,    30,    31,    36,    25,    68,    23,    26,    86,
      24,    44,    11,    68,    47,    48,    49,    50,    51,    52,
      97,    54,    55,    14,   101,    14,    36,    36,    34,     8,
      92,    86,    17,    27,    29,    28,    11,    92,   100,    72,
      73,   103,    97,    15,     9,   100,   101,    11,   103,    -1,
      83,    84,    85,     6,    87,    88,     9,    10,    21,    -1,
      13,    -1,    -1,     6,    -1,    18,    19,    10,    -1,    12,
      13,    -1,    -1,    -1,     6,    18,    19,    -1,    10,    -1,
      33,    13,    -1,    -1,    16,     6,    18,    19,    -1,    10,
      33,    -1,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    45,     0,     4,    33,     6,    10,    13,
      18,    19,    33,    46,    47,    71,    35,    32,    63,    70,
      71,    52,    33,    71,    70,    35,     5,    47,    48,    32,
       7,    64,    65,    66,    67,    68,    69,    63,    53,    57,
      34,    34,    32,    33,    20,    36,    46,    21,    22,    25,
      23,    26,    24,    11,    14,    14,    36,    36,    59,    70,
       9,    49,    70,    70,    70,    70,    70,    70,    46,    70,
      70,    34,    30,    31,    60,    61,    62,     8,    12,    54,
      17,    70,    70,    27,    28,    29,    50,    15,    58,    70,
      70,    70,    46,    70,    70,    51,    55,    11,     9,    11,
      46,    56,    16,    46,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    46,    46,    48,    47,
      49,    50,    51,    47,    47,    52,    47,    53,    54,    55,
      56,    47,    57,    58,    47,    47,    47,    59,    60,    59,
      61,    59,    62,    59,    59,    59,    64,    63,    65,    63,
      66,    63,    67,    63,    68,    63,    69,    63,    70,    70,
      71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     0,     2,     1,     0,     5,
       0,     0,     0,    10,     5,     0,     6,     0,     0,     0,
       0,    13,     0,     0,    11,     3,     3,     1,     0,     4,
       0,     4,     0,     4,     3,     3,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       1,     4,     4
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
        case 2:
#line 177 "gram.ypp" /* yacc.c:1646  */
    {
                  finish();
                }
#line 1468 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 181 "gram.ypp" /* yacc.c:1646  */
    {
                  declareAVariable((yyvsp[0].string));
                }
#line 1476 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 184 "gram.ypp" /* yacc.c:1646  */
    {
                  int arraySize = atoi((yyvsp[-1].string));
                  declareAnArray((yyvsp[-3].string), arraySize);
                }
#line 1485 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 188 "gram.ypp" /* yacc.c:1646  */
    {
                  // std::cout << "No variables declared" << "\n";
                }
#line 1493 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 193 "gram.ypp" /* yacc.c:1646  */
    { }
#line 1499 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "gram.ypp" /* yacc.c:1646  */
    { }
#line 1505 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 197 "gram.ypp" /* yacc.c:1646  */
    {
                expressionType[0]         = valueFormat1;
                expressionType[1]         = valueFormat2;
                currentArrayIndex_assign  = currentArrayIndex;
                currentArrayAssignAddress = arrayIdentifierAddress;
                // std::cout << currentArrayAssignAddress << " XDDDD";

              }
#line 1518 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 204 "gram.ypp" /* yacc.c:1646  */
    {

                std::string variableName = (yyvsp[-4].string);
                int addressToAssign;

                if (!isVariableDeclared(&variablesAddressesMap, variableName)) { //variable is not declared
                  std::cout << "Error [line "<< "]: Variable "<< (yyvsp[-4].string) <<" not declared!" << "\n";
                  exit(1);
                } else { // variable is declared

                  int variableAddress = variablesAddressesMap[variableName];

                  if (expressionType[1] == "array") {

                    int arraySize = arraysMap[variableName];

                    if (expressionType[0] == "array") { // a[n]
                      pushCodeWithAddress("STORE", 7); // zapisz akumulator w pamieci
                      pushCodeWithAddress("LOAD",  currentArrayAssignAddress); // ladujemy adres a
                      pushCodeWithAddress("STORE", 7); // 10

                      pushCodeWithAddress("LOAD",  variableAddress);
                      pushCodeWithAddress("ADD",   7);
                      pushCodeWithAddress("STORE", 1);

                      pushCodeWithAddress("LOAD",   7);
                      pushCodeWithAddress("STOREI", 1); // ladujemy adres

                    } else {

                      if (currentArrayIndex < 0 || currentArrayIndex >= arraySize) {
                        std::cout << "[ERROR] IndexArrayOutOfBoundsException: array " << variableName << " is size: " << arraySize << ", tried to access index " << currentArrayIndex << "\n";
                        exit(1);
                      }
                      addressToAssign = variableAddress + currentArrayIndex_assign + 1;
                      pushCodeWithAddress("STORE", addressToAssign);

                    }
                  } else {
                    initializedVariablesMap[variableName] = true;
                    addressToAssign = variableAddress;
                    pushCodeWithAddress("STORE", addressToAssign);

                  }
                }
             }
#line 1569 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 253 "gram.ypp" /* yacc.c:1646  */
    {


             }
#line 1578 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 256 "gram.ypp" /* yacc.c:1646  */
    {
               pushCodeWithAddress("JUMP", 21373);
               changeJumpValue();

            }
#line 1588 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 260 "gram.ypp" /* yacc.c:1646  */
    {
              elseStack.emplace(numberOfCommands);

            }
#line 1597 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 263 "gram.ypp" /* yacc.c:1646  */
    {
              std::stack<std::pair<int, int>> tempStack = jumpStack;

              for (int i = 0; i < jumpStack.size(); i++) {
                std::pair<int,int> topElement = tempStack.top();
                tempStack.pop();
              }

              int returnA = elseStack.top();
              elseStack.pop();
              // std::cout << returnA << " KNOCK HIM OUT" << "\n";
              changeElseValue(returnA);
            }
#line 1615 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 281 "gram.ypp" /* yacc.c:1646  */
    {
               changeJumpValue();
             }
#line 1623 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 285 "gram.ypp" /* yacc.c:1646  */
    {
               returnStack.emplace(numberOfCommands);
             }
#line 1631 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 287 "gram.ypp" /* yacc.c:1646  */
    {
                int returnAddress = returnStack.top();
                returnStack.pop();
                pushCodeWithAddress("JUMP", returnAddress);
                changeJumpValue();
             }
#line 1642 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 298 "gram.ypp" /* yacc.c:1646  */
    {

               // pętla for moze miec jako iterator tylko i wylacznie nowa zmienna
               std::string iteratorsName = (yyvsp[0].string);
               if (isVariableDeclared(&variablesAddressesMap, iteratorsName)) {
                 std::cout << iteratorsName << " has been used previously in program! \n";
                 exit(1);
               } else {
                 declareAVariable(iteratorsName);
               }

             }
#line 1659 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 309 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);

               if (type == "number") {
                 pushCodeWithAddress("STORE", 8);
               }

             }
#line 1683 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 327 "gram.ypp" /* yacc.c:1646  */
    {
               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);

               iteratorsAddress = variablesAddressesMap[(yyvsp[-6].string)];

               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("SUB",  8);

               } else if (types[0] == "number" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCodeWithAddress("SUB",  8);

               } else if (types[0] == "variable" && types[1] == "number") {

                 pushCodeWithAddress("SUB",  8);

              } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("SUB",  firstElementAddress  + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "arrayVar" && types[1] == "number") {

                // pushCodeWithAddress("", );
                pushCodeWithAddress("SUB",  firstElementAddress  + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "number" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress  + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("SUB",  8);

              } else if (types[0] == "array" && types[1] == "variable") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);
                pushCodeWithAddress("STORE", 9);

                pushCodeWithAddress("LOAD", secondElementAddress);
                pushCodeWithAddress("SUB",  9);

              } else if (types[0] == "array" && types[1] == "array") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);
                pushCodeWithAddress("STORE", 9);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOADI", 1);

                pushCodeWithAddress("SUB", 9);

              } else if (types[0] == "array" && types[1] == "number") {

                pushCodeWithAddress("STORE", 9);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);
                pushCodeWithAddress("STORE", 8);

                pushCodeWithAddress("LOAD", 9);
                pushCodeWithAddress("SUB",  8);

              } else if (types[0] == "array" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);
                pushCodeWithAddress("STORE", 8);

                pushCodeWithAddress("LOAD", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("LOAD", 9);
                pushCodeWithAddress("SUB",  8);


              } else if (types[0] == "number" && types[1] == "array") {


                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);

                pushCodeWithAddress("SUB", 8);

              } else if (types[0] == "variable" && types[1] == "array") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);

                pushCodeWithAddress("SUB", firstElementAddress);

              } else if (types[0] == "arrayVar" && types[1] == "array") {


                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 10);
                pushCodeWithAddress("LOADI", 10);
                pushCodeWithAddress("SUB",   firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "variable" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("SUB", firstElementAddress);


              } else if (types[0] == "arrayVar" && types[1] == "variable") {

                pushCodeWithAddress("LOAD", secondElementAddress);
                pushCodeWithAddress("SUB",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "variable" && types[1] == "variable") {

                pushCodeWithAddress("LOAD", secondElementAddress);
                pushCodeWithAddress("SUB", firstElementAddress);
              }

              pushCodeWithAddress("STORE", 8);

              pushCode("ZERO");
              pushCodeWithAddress("STORE", iteratorsAddress);

                // declareAVariable($2);

            }
#line 1839 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 477 "gram.ypp" /* yacc.c:1646  */
    {
              returnStack.emplace(numberOfCommands);

              //zaladuj wartosc i, odejmij
              pushCodeWithAddress("LOAD", iteratorsAddress);
              pushCodeWithAddress("SUB", 8);

              pushCodeWithAddress("JZERO", numberOfCommands + 2);
              pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);

             }
#line 1855 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 487 "gram.ypp" /* yacc.c:1646  */
    {

              pushCodeWithAddress("LOAD", iteratorsAddress);
              pushCode("INC");
              pushCodeWithAddress("STORE",  iteratorsAddress);

               int returnAddress = returnStack.top();
               returnStack.pop();
               pushCodeWithAddress("JUMP", returnAddress);
               changeJumpValue();

               // usun ze zmiennych
               variablesAddressesMap.erase((yyvsp[-11].string));
             }
#line 1874 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 503 "gram.ypp" /* yacc.c:1646  */
    {
                // std::cout << "haha";
             }
#line 1882 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 505 "gram.ypp" /* yacc.c:1646  */
    {
              //  std::cout << "welp";
             }
#line 1890 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 507 "gram.ypp" /* yacc.c:1646  */
    {
              //  std::cout << "welp";
             }
#line 1898 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 510 "gram.ypp" /* yacc.c:1646  */
    {

               std::string variableName = (yyvsp[-1].string);

               if (!isVariableDeclared(&variablesAddressesMap, variableName)) { //variable is not declared
                 std::cout << "Error [line "<< "]: Variable "<< (yyvsp[-1].string) <<" not declared! #READ" << "\n";
                 exit(1);
               } else {

                 int variableAddress = variablesAddressesMap[variableName];
                 pushCode("ZERO");
                 pushCode("GET");

                 if (isVariableDeclared(&arraysMap, variableName)) {
                    int requiredCell;
                    if (valueFormat1 == "number") { // a[1]

                     requiredCell = computeRequiredMemoryCell(variableName, currentArrayIndex);
                     pushCodeWithAddress("STORE", requiredCell);

                   } else { // a[n]

                     pushCodeWithAddress("STORE", 0);

                     pushCodeWithAddress("LOAD", variablesAddressesMap[variableName]);
                     pushCodeWithAddress("ADD",  arrayIdentifierAddress); // we load value n from a[n]
                     pushCodeWithAddress("STORE", 1);

                     pushCodeWithAddress("LOAD",  0);
                     pushCodeWithAddress("STOREI", 1);
                   }
                 } else {
                   int variableAddress = variablesAddressesMap[variableName];

                   pushCodeWithAddress("STORE", variableAddress);
                   initializedVariablesMap[variableName] = true; // just in case we set it as initialized
                 }
               }
             }
#line 1942 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 549 "gram.ypp" /* yacc.c:1646  */
    {

               std::string variableName = (yyvsp[-1].string);

               if (isVariableDeclared(&variablesAddressesMap, variableName)) {
                 // at this point we know that variable is declared, what about being initialized?
                 int variableAddress = variablesAddressesMap[variableName];

                 if (valueFormat2 != "array" && !isVariableInitialized(&initializedVariablesMap, variableName)) { //checking if it's initialized
                  std::cout << "Variable " << variableName << " not initialized\n";
                  exit(1);
                } else {

                  if (isVariableDeclared(&arraysMap, variableName)) { // is it an array?
                    if (valueFormat1 == "number") { // a[1]
                      int arraySize = arraysMap[variableName];
                      if (currentArrayIndex < 0 || currentArrayIndex >= arraySize) {
                        std::cout << "[ERROR] IndexArrayOutOfBoundsException: array " << variableName << " is size: " << arraySize << ", tried to access index " << currentArrayIndex << "\n";
                        exit(1);
                      }

                      pushCodeWithAddress("LOAD", variableAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                      pushCode("PUT");

                    } else { // a[b]

                      pushCodeWithAddress("LOAD", variablesAddressesMap[variableName]);
                      pushCodeWithAddress("ADD",  arrayIdentifierAddress); // we load value n from a[n]
                      pushCodeWithAddress("STORE", 0);
                      pushCodeWithAddress("LOADI", 0);
                      pushCode("PUT");

                    }
                  } else {

                    // pushCode("ZERO");
                    pushCodeWithAddress("LOAD", variableAddress);
                    pushCode("PUT");
                  }
                }
               } else { //variable is not declared
                 std::cout << "Error [line "<< "]: Variable "<< (yyvsp[-1].string) <<" not declared! #WRITE" << "\n";
                 exit(1);
               }
             }
#line 1992 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 595 "gram.ypp" /* yacc.c:1646  */
    {

                if (valueFormat1 == "number" && valueFormat2 == "number") {
                    // do nothing
                    // pushCode("WABBA LUBBA DUB DUB ");
                } else if (valueFormat1 == "variable" && valueFormat2 == "variable") {
                  pushCode("ZERO");
                  pushCodeWithAddress("LOAD", equationElementAddress); // todo: do poprawki, wstawiłem tylko dla debuggingu, tutaj znajdz adres zmiennej ktorą teraz przypiszemy
                } else if (valueFormat1 == "number" && valueFormat2 == "array") {

                } else if (valueFormat1 == "array" && valueFormat2 == "array"){

                }

              }
#line 2012 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 610 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;
               firstElementAddress         = equationElementAddress;

               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 0);
               }
             }
#line 2034 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 627 "gram.ypp" /* yacc.c:1646  */
    {

              secondElementAddress             = equationElementAddress;
              int secondArrayIdentifierAddress = arrayIdentifierAddress;
              std::string secondElementName    = variableNameGlobal;

              std::string variableTypes[4];
              variableTypes[0] = expressionType[0];
              variableTypes[1] = expressionType2[0];
              variableTypes[2] = valueFormat1;
              variableTypes[3] = valueFormat2;

              std::string types[2];
              types[0] = determineDataType(variableTypes[0], variableTypes[1]);
              types[1] = determineDataType(variableTypes[2], variableTypes[3]);

              if (types[0] == "number" && types[1] == "number") { // DONE

                pushCodeWithAddress("ADD",   0);

              } else if (types[0] == "number" && types[1] == "variable") { // DONE

                pushCodeWithAddress("LOAD", secondElementAddress);
                pushCodeWithAddress("ADD",  0);

              } else if (types[0] == "variable" && types[1] == "number") { // DONE

                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD",  firstElementAddress);
                pushCodeWithAddress("ADD",   0);

              } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", firstElementAddress  + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("ADD",  secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "arrayVar" && types[1] == "number") { // DONE

                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD",  secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("ADD",   0);

              } else if (types[0] == "number" && types[1] == "arrayVar") { // DONE

                pushCodeWithAddress("LOAD", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("ADD",  0);

              } else if (types[0] == "array" && types[1] == "variable") {

                pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",  firstArrayIdentifierAddress); // we load value n from a[n]
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("ADD", secondElementAddress);

              } else if (types[0] == "variable" && types[1] == "array") { // done

                pushCodeWithAddress("LOAD", firstElementAddress);
                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("ADD",   0);

              } else if (types[0] == "array" && types[1] == "array") { // done

                pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",  firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("STORE", 3);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 4);
                pushCodeWithAddress("LOADI", 4);

                pushCodeWithAddress("ADD", 3);

              } else if (types[0] == "array" && types[1] == "number") { // DONE

                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",  arrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("ADD", 0);

              } else if (types[0] == "array" && types[1] == "arrayVar") { //done

                pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",  firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("ADD", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "number" && types[1] == "array") { // done

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);

                pushCodeWithAddress("ADD", 0);

              } else if (types[0] == "arrayVar" && types[1] == "array") { // done

                pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("STORE", 0);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 3);
                pushCodeWithAddress("LOADI", 3);
                pushCodeWithAddress("ADD",   0);

              } else if (types[0] == "variable" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", firstElementAddress);
                pushCodeWithAddress("ADD",  secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

              } else if (types[0] == "arrayVar" && types[1] == "variable") {

                pushCodeWithAddress("LOAD", firstElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("ADD",  secondElementAddress);

              } else if (types[0] == "variable" && types[1] == "variable") {

                pushCodeWithAddress("LOAD", firstElementAddress);
                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD", secondElementAddress);
                pushCodeWithAddress("ADD", 0);

              }
             }
#line 2175 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 766 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 0);
               }

             }
#line 2198 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 783 "gram.ypp" /* yacc.c:1646  */
    {

               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);


               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "number" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "variable" && types[1] == "number") {

                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOAD",  firstElementAddress);
                  pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", firstElementAddress  + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",  secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOAD",  firstElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "number" && types[1] == "arrayVar") {

                 pushCodeWithAddress("STORE", 0);
                 pushCodeWithAddress("SUB",   secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "array" && types[1] == "variable") { // done

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("SUB",   secondElementAddress);

               } else if (types[0] == "array" && types[1] == "array") { // done

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 1); // value of second element

                 pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",  firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 0);
                 pushCodeWithAddress("LOADI", 0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "array" && types[1] == "number") { // done

                 pushCodeWithAddress("STORE", 0); // store number value

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   arrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("SUB",   0);

               } else if (types[0] == "array" && types[1] == "arrayVar") { // done

                 pushCodeWithAddress("LOAD", variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",  firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 0);
                 pushCodeWithAddress("LOADI", 0);
                 pushCodeWithAddress("SUB", secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "number" && types[1] == "array") { // done

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 1);

                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "variable" && types[1] == "array") { // done

                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCodeWithAddress("STORE", 0);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 1);

                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "arrayVar" && types[1] == "array") { // done

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 1);

                 pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "variable" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  firstElementAddress);
                 pushCodeWithAddress("STORE", 0);
                 pushCodeWithAddress("LOAD",  secondElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  secondElementAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOAD",  firstElementAddress + currentArrayIndex + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("STORE", 0);
                 pushCodeWithAddress("LOAD",  0);
                 pushCodeWithAddress("SUB",   1);

               } else if (types[0] == "variable" && types[1] == "variable") {
                pushCodeWithAddress("LOAD",  firstElementAddress);
                pushCodeWithAddress("STORE", 0);
                pushCodeWithAddress("LOAD",  secondElementAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOAD",  0);
                pushCodeWithAddress("SUB",  1);

               }
             }
#line 2359 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 942 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }

             }
#line 2382 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 959 "gram.ypp" /* yacc.c:1646  */
    {

               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);

               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 /*
                 #######################################
                 #      SPRAWDZENIE CZY JEST TO 0      #
                 #######################################
                 */


               }

             }
#line 2418 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 990 "gram.ypp" /* yacc.c:1646  */
    { }
#line 2424 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 991 "gram.ypp" /* yacc.c:1646  */
    { }
#line 2430 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 994 "gram.ypp" /* yacc.c:1646  */
    {
                expressionType[0]  = valueFormat1;
                expressionType2[0] = valueFormat2;

                firstElementAddress         = equationElementAddress;
                arrayIndexOfFirstElement    = currentArrayIndex;
                firstElementName            = variableNameGlobal;
                firstArrayIdentifierAddress = arrayIdentifierAddress;

                std::string variableTypes[4];
                variableTypes[0] = expressionType[0];
                variableTypes[1] = expressionType2[0];
                std::string type = determineDataType(variableTypes[0], variableTypes[1]);
                if (type == "number") {
                  pushCodeWithAddress("STORE", 2);
                }

              }
#line 2453 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 1011 "gram.ypp" /* yacc.c:1646  */
    {

                secondElementAddress             = equationElementAddress;
                int secondArrayIdentifierAddress = arrayIdentifierAddress;
                std::string secondElementName    = variableNameGlobal;
                int arrayIndexOfSecondElement    = currentArrayIndex;

                std::string variableTypes[4];
                variableTypes[0] = expressionType[0];
                variableTypes[1] = expressionType2[0];
                variableTypes[2] = valueFormat1;
                variableTypes[3] = valueFormat2;

                std::string types[2];
                types[0] = determineDataType(variableTypes[0], variableTypes[1]);
                types[1] = determineDataType(variableTypes[2], variableTypes[3]);

                if (types[0] == "number" && types[1] == "number") {

                  pushCodeWithAddress("STORE", 3); // na wszelki wypadek zapisuje do 3 komorki wartosc dugiej zmiennej
                  //checking a - b
                  pushCodeWithAddress("LOAD",  2);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);
                  // result of a - b is now in cell no. 0

                  //computing b - a
                  pushCodeWithAddress("LOAD", 3);
                  pushCodeWithAddress("SUB",  2);

                  pushCodeWithAddress("ADD",   0);

                } else if (types[0] == "number" && types[1] == "variable") {

                  //checking a - b
                  pushCodeWithAddress("LOAD",  2);
                  pushCodeWithAddress("SUB",   secondElementAddress);
                  pushCodeWithAddress("STORE", 0);
                  // result of a - b is now in cell no. 0

                  //computing b - a
                  pushCodeWithAddress("LOAD", secondElementAddress);
                  pushCodeWithAddress("SUB",  2);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "variable" && types[1] == "number") {

                  pushCodeWithAddress("STORE", 3);
                  //checking a - b
                  pushCodeWithAddress("LOAD",  firstElementAddress);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);
                  // result of a - b is now in cell no. 0

                  //computing b - a
                  pushCodeWithAddress("LOAD", 3);
                  pushCodeWithAddress("SUB",  firstElementAddress);

                  pushCodeWithAddress("ADD", 0);



                } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {
                  // compute a - b
                  pushCodeWithAddress("LOAD",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("STORE", 0);

                  //compute b - a
                  pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);

                  pushCodeWithAddress("ADD", 0);



                } else if (types[0] == "arrayVar" && types[1] == "number") {

                  pushCodeWithAddress("STORE", 3); // zapisz drugi argument (liczba)

                  pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);


                  pushCodeWithAddress("LOAD", 3); //zaladuj b
                  pushCodeWithAddress("SUB",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET); //odejmij a

                  pushCodeWithAddress("ADD", 0);


                } else if (types[0] == "number" && types[1] == "arrayVar") {

                  pushCodeWithAddress("LOAD",  2);
                  pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("STORE", 0);

                  pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB", 2);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "array" && types[1] == "variable") {

                  //compute a - b
                  pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                  pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym
                  pushCodeWithAddress("LOAD",  3);  //pewnie zbedne

                  pushCodeWithAddress("SUB",   secondElementAddress);
                  pushCodeWithAddress("STORE", 0);

                  //compute b - a
                  pushCodeWithAddress("LOAD", secondElementAddress);
                  pushCodeWithAddress("SUB",  3);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "array" && types[1] == "array") {

                  //compute a - b
                  pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                  pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 2);
                  pushCodeWithAddress("LOADI", 2); // w tym momencie mam dostęp do wartości b[n]
                  pushCodeWithAddress("STORE", 4); // zapisuje ja sobie w rejestrze podrecznym

                  pushCodeWithAddress("LOAD",  3);  //pewnie zbedne
                  pushCodeWithAddress("SUB",   4);
                  pushCodeWithAddress("STORE", 0);

                  //compute b - a
                  pushCodeWithAddress("LOAD", 4);
                  pushCodeWithAddress("SUB",  3);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "array" && types[1] == "number") {

                  pushCodeWithAddress("STORE", 4);
                  //compute a - b
                  pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                  pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym
                  pushCodeWithAddress("LOAD",  3); // niepotrzebne

                  pushCodeWithAddress("SUB",   4);
                  pushCodeWithAddress("STORE", 0);


                  pushCodeWithAddress("LOAD", 4);
                  pushCodeWithAddress("SUB",  3);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "array" && types[1] == "arrayVar") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                  pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym
                  pushCodeWithAddress("LOAD",  3); // niepotrzebne
                  pushCodeWithAddress("SUB",  secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("STORE", 0);

                  pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",  3);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "number" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym

                  pushCodeWithAddress("LOAD",  2);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);


                  pushCodeWithAddress("LOAD",  3);
                  pushCodeWithAddress("SUB",   2);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "variable" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym

                  pushCodeWithAddress("LOAD",  firstElementAddress);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);

                  pushCodeWithAddress("LOAD",  3);
                  pushCodeWithAddress("SUB",   firstElementAddress);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "arrayVar" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym

                  pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",   3);
                  pushCodeWithAddress("STORE", 0);

                  pushCodeWithAddress("LOAD",  3);
                  pushCodeWithAddress("SUB",   firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "variable" && types[1] == "arrayVar") {

                  pushCodeWithAddress("LOAD", firstElementAddress);
                  pushCodeWithAddress("SUB",  secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("STORE", 0);


                  pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",  firstElementAddress);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "arrayVar" && types[1] == "variable") {

                  pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                  pushCodeWithAddress("SUB",   secondElementAddress);
                  pushCodeWithAddress("STORE", 0);


                  pushCodeWithAddress("LOAD", secondElementAddress);
                  pushCodeWithAddress("SUB",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

                  pushCodeWithAddress("ADD", 0);

                } else if (types[0] == "variable" && types[1] == "variable") {

                  pushCodeWithAddress("LOAD",  firstElementAddress);
                  pushCodeWithAddress("SUB",   secondElementAddress);
                  pushCodeWithAddress("STORE", 0);

                  pushCodeWithAddress("LOAD",  secondElementAddress);
                  pushCodeWithAddress("SUB",   firstElementAddress);

                  pushCodeWithAddress("ADD", 0);
                }

                pushCodeWithAddress("JZERO", numberOfCommands + 2);
                pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);
              }
#line 2735 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 1288 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }
             }
#line 2757 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 1304 "gram.ypp" /* yacc.c:1646  */
    {


               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);

               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);
                 //checking a - b
                 pushCodeWithAddress("LOAD",  2);
                 pushCodeWithAddress("SUB",   3);
                 pushCodeWithAddress("STORE", 0);
                 // result of a - b is now in cell no. 0

                 //computing b - a
                 pushCodeWithAddress("LOAD", 3);
                 pushCodeWithAddress("SUB",  2);

                 pushCodeWithAddress("ADD",   0);

               } else if (types[0] == "number" && types[1] == "variable") {

               } else if (types[0] == "variable" && types[1] == "number") {

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

               } else if (types[0] == "arrayVar" && types[1] == "number") {

               } else if (types[0] == "number" && types[1] == "arrayVar") {

               } else if (types[0] == "array" && types[1] == "variable") {

               } else if (types[0] == "array" && types[1] == "array") {

               } else if (types[0] == "array" && types[1] == "number") {

               } else if (types[0] == "array" && types[1] == "arrayVar") {

               } else if (types[0] == "number" && types[1] == "array") {

               } else if (types[0] == "variable" && types[1] == "array") {

               } else if (types[0] == "arrayVar" && types[1] == "array") {

               } else if (types[0] == "variable" && types[1] == "arrayVar") {

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

               } else if (types[0] == "variable" && types[1] == "variable") {

               }

               pushCodeWithAddress("JZERO", numberOfCommands + 2);
               pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);

             }
#line 2831 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 1373 "gram.ypp" /* yacc.c:1646  */
    {

               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }
             }
#line 2854 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 1390 "gram.ypp" /* yacc.c:1646  */
    {
               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);

               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3); // saving second number to cell

                 pushCodeWithAddress("LOAD", 2); // a
                 pushCode("INC");                // a + 1
                 pushCodeWithAddress("SUB",  3); // (a+1) - b

               } else if (types[0] == "number" && types[1] == "variable") {


                pushCodeWithAddress("LOAD", firstElementAddress);
                pushCode("INC"); // a + 1

                pushCodeWithAddress("SUB", secondElementAddress);

               } else if (types[0] == "variable" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);


                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCode("INC"); // a + 1

                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);
                 pushCode("INC");
                 pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);
                 pushCode("INC");
                 pushCodeWithAddress("SUB", 3);


               } else if (types[0] == "number" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", 2);
                 pushCode("INC");
                 pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "array" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCode("INC");

                 pushCodeWithAddress("SUB", secondElementAddress);



               } else if (types[0] == "array" && types[1] == "array") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCode("INC");

                 pushCodeWithAddress("SUB",   3);

               } else if (types[0] == "array" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 //pushCodeWithAddress("STORE", 2); // zapisuje ja sobie w rejestrze podrecznym
                 pushCode("INC");

                 pushCodeWithAddress("SUB",   3);


               } else if (types[0] == "array" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCode("INC");

                 pushCodeWithAddress("SUB", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "number" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);


                 pushCodeWithAddress("LOAD",  2);
                 pushCode("INC");
                 pushCodeWithAddress("SUB", 3);

               } else if (types[0] == "variable" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3);

                  pushCodeWithAddress("LOAD", firstElementAddress);
                  pushCode("INC");
                  pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "arrayVar" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                 pushCode("INC");

                 pushCodeWithAddress("SUB",  3);


               } else if (types[0] == "variable" && types[1] == "arrayVar") {


                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCode("INC");

                 pushCodeWithAddress("SUB",  secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
                 pushCode("INC");

                 pushCodeWithAddress("SUB",  secondElementAddress);


               } else if (types[0] == "variable" && types[1] == "variable") {
                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCode("INC");

                 pushCodeWithAddress("SUB", secondElementAddress);
               }

               pushCodeWithAddress("JZERO", numberOfCommands + 2);
               pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);
             }
#line 3035 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 1566 "gram.ypp" /* yacc.c:1646  */
    {


               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }
             }
#line 3059 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 1584 "gram.ypp" /* yacc.c:1646  */
    {


               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);


               if (types[0] == "number" && types[1] == "number") {

                 pushCode("INC");
                 pushCodeWithAddress("SUB", 2); // (a+1) - b

               } else if (types[0] == "number" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCode("INC");
                 pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "variable" && types[1] == "number") {

                 pushCode("INC");
                 pushCodeWithAddress("SUB", firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCode("INC");

                 pushCodeWithAddress("SUB",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "number") {

                 pushCode("INC");
                 pushCodeWithAddress("SUB", firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "number" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                pushCode("INC");

                pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "array" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCode("INC");
                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "array" && types[1] == "array") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                pushCodeWithAddress("STORE", 3);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                pushCode("INC");

                pushCodeWithAddress("SUB",   3);

               } else if (types[0] == "array" && types[1] == "number") {

                 pushCode("INC");
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 4);

                 pushCodeWithAddress("LOAD",  3);
                 pushCodeWithAddress("SUB",   4);

               } else if (types[0] == "array" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCode("INC");
                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "number" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCode("INC");

                 pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "variable" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCode("INC");

                  pushCodeWithAddress("SUB",  firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCode("INC");

                 pushCodeWithAddress("SUB", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "variable" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                pushCode("INC");
                pushCodeWithAddress("SUB", firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  secondElementAddress);
                 pushCode("INC");
                 pushCodeWithAddress("SUB", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "variable" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCode("INC");
                 pushCodeWithAddress("SUB",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
               }

               pushCodeWithAddress("JZERO", numberOfCommands + 2);
               pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);

             }
#line 3225 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 1745 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }
              }
#line 3247 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 1761 "gram.ypp" /* yacc.c:1646  */
    {

               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);

               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3); // saving second number to cell

                 pushCodeWithAddress("LOAD", 2); // a
                 pushCodeWithAddress("SUB",  3); // (a+1) - b

               } else if (types[0] == "number" && types[1] == "variable") {


                pushCodeWithAddress("LOAD", firstElementAddress);

                pushCodeWithAddress("SUB", secondElementAddress);

               } else if (types[0] == "variable" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);


                 pushCodeWithAddress("LOAD", firstElementAddress);

                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB", 3);


               } else if (types[0] == "number" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", 2);
                 pushCodeWithAddress("SUB",   secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "array" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 //pushCodeWithAddress("STORE", 3); // zapisuje ja sobie w rejestrze podrecznym
                 //pushCodeWithAddress("LOAD", 3);

                 pushCodeWithAddress("SUB", secondElementAddress);



               } else if (types[0] == "array" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                 pushCodeWithAddress("SUB",   3);

               } else if (types[0] == "array" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);

                 pushCodeWithAddress("SUB",   3);

               } else if (types[0] == "array" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                 pushCodeWithAddress("SUB", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "number" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  2);
                 pushCodeWithAddress("SUB", 3);

               } else if (types[0] == "variable" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                  pushCodeWithAddress("STORE", 3);

                  pushCodeWithAddress("LOAD", firstElementAddress);
                  pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "arrayVar" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

                 pushCodeWithAddress("SUB",  3);


               } else if (types[0] == "variable" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCodeWithAddress("SUB",  secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

                 pushCodeWithAddress("SUB",  secondElementAddress);


               } else if (types[0] == "variable" && types[1] == "variable") {
                 pushCodeWithAddress("LOAD", firstElementAddress);
                 pushCodeWithAddress("SUB", secondElementAddress);
               }

               pushCodeWithAddress("JZERO", numberOfCommands + 2);
               pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);
             }
#line 3413 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 1923 "gram.ypp" /* yacc.c:1646  */
    {
               expressionType[0]  = valueFormat1;
               expressionType2[0] = valueFormat2;

               firstElementAddress         = equationElementAddress;
               arrayIndexOfFirstElement    = currentArrayIndex;
               firstElementName            = variableNameGlobal;
               firstArrayIdentifierAddress = arrayIdentifierAddress;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               std::string type = determineDataType(variableTypes[0], variableTypes[1]);
               if (type == "number") {
                 pushCodeWithAddress("STORE", 2);
               }
             }
#line 3435 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1939 "gram.ypp" /* yacc.c:1646  */
    {

               secondElementAddress             = equationElementAddress;
               int secondArrayIdentifierAddress = arrayIdentifierAddress;
               std::string secondElementName    = variableNameGlobal;
               int arrayIndexOfSecondElement    = currentArrayIndex;

               std::string variableTypes[4];
               variableTypes[0] = expressionType[0];
               variableTypes[1] = expressionType2[0];
               variableTypes[2] = valueFormat1;
               variableTypes[3] = valueFormat2;

               std::string types[2];
               types[0] = determineDataType(variableTypes[0], variableTypes[1]);
               types[1] = determineDataType(variableTypes[2], variableTypes[3]);



               if (types[0] == "number" && types[1] == "number") {

                 pushCodeWithAddress("SUB", 2); // (a+1) - b

               } else if (types[0] == "number" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "variable" && types[1] == "number") {

                 pushCodeWithAddress("SUB", firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",  firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "arrayVar" && types[1] == "number") {

                 pushCodeWithAddress("SUB", firstElementAddress  + arrayIndexOfFirstElement  + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "number" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "array" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", secondElementAddress);
                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "array" && types[1] == "array") {

                pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                pushCodeWithAddress("STORE", 3);

                pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                pushCodeWithAddress("STORE", 1);
                pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                pushCodeWithAddress("SUB",   3);

               } else if (types[0] == "array" && types[1] == "number") {

                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1);
                 pushCodeWithAddress("STORE", 4);

                 pushCodeWithAddress("LOAD",  3);
                 pushCodeWithAddress("SUB",   4);

               } else if (types[0] == "array" && types[1] == "arrayVar") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[firstElementName]);
                 pushCodeWithAddress("ADD",   firstArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]
                 pushCodeWithAddress("STORE", 3);

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",  3);

               } else if (types[0] == "number" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                 pushCodeWithAddress("SUB", 2);

               } else if (types[0] == "variable" && types[1] == "array") {

                  pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                  pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                  pushCodeWithAddress("STORE", 1);
                  pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                  pushCodeWithAddress("SUB",  firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "array") {

                 pushCodeWithAddress("LOAD",  variablesAddressesMap[secondElementName]);
                 pushCodeWithAddress("ADD",   secondArrayIdentifierAddress);
                 pushCodeWithAddress("STORE", 1);
                 pushCodeWithAddress("LOADI", 1); // w tym momencie mam dostęp do wartości a[n]

                 pushCodeWithAddress("SUB", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "variable" && types[1] == "arrayVar") {

                pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                pushCodeWithAddress("SUB", firstElementAddress);

               } else if (types[0] == "arrayVar" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD",  secondElementAddress);
                 pushCodeWithAddress("SUB", firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);

               } else if (types[0] == "variable" && types[1] == "variable") {

                 pushCodeWithAddress("LOAD", secondElementAddress + arrayIndexOfSecondElement + ARRAY_INDEX_OFFSET);
                 pushCodeWithAddress("SUB",  firstElementAddress + arrayIndexOfFirstElement + ARRAY_INDEX_OFFSET);
               }

               pushCodeWithAddress("JZERO", numberOfCommands + 2);
               pushCodeWithAddress("JUMP",  JUMP_PLACEHOLDER_ADDRESS);

             }
#line 3583 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 2083 "gram.ypp" /* yacc.c:1646  */
    {
                generateNumber((yyvsp[0].string));
                valueFormat1 = "number";
                valueFormat2 = "number";
             }
#line 3593 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 2088 "gram.ypp" /* yacc.c:1646  */
    {
               std::string variableName = (yyvsp[0].string);

               if (!isVariableDeclared(&variablesAddressesMap, variableName)) {
                 // not declared
                  std::cout << "variable " << variableName << " is not declared! \n";
                  exit(1);
               } else { // variable is declared

                if(valueFormat2 != "array" && !isVariableInitialized(&initializedVariablesMap, variableName)) {
                  std::cout << "Variable " << variableName << " declared but not initialized\n";
                  exit(1);
                } else {

                }
               }
             }
#line 3615 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 2106 "gram.ypp" /* yacc.c:1646  */
    {
              valueFormat1 = "variable";
              valueFormat2 = "variable";
              std::string variableName = (yyvsp[0].string);
              variableNameGlobal = (yyvsp[0].string);

              if (!isVariableDeclared(&variablesAddressesMap, variableName)) {
                std::cout << "variable " << variableName << " is not declared! \n";
                exit(1);
              } else {
                equationElementAddress = variablesAddressesMap[(yyvsp[0].string)];
              }
            }
#line 3633 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 2119 "gram.ypp" /* yacc.c:1646  */
    {

              std::string variableName = (yyvsp[-3].string);

              if (!isVariableDeclared(&variablesAddressesMap, variableName)) {
                std::cout << "variable " << variableName << " is not declared! \n";
                exit(1);
              } else {
                valueFormat1            = "array";
                valueFormat2            = "array";

                variableNameGlobal = (yyvsp[-3].string);

                equationElementAddress  = variablesAddressesMap[(yyvsp[-3].string)];
                arrayIdentifierAddress  = variablesAddressesMap[(yyvsp[-1].string)]; // is only an address of a variable, not a value!!!
              }

           }
#line 3656 "gram.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 2137 "gram.ypp" /* yacc.c:1646  */
    {

              std::string variableName = (yyvsp[-3].string);

              if (!isVariableDeclared(&variablesAddressesMap, variableName)) {
                std::cout << "variable " << variableName << " is not declared! \n";
                exit(1);
              } else {

                valueFormat1 = "number";
                valueFormat2 = "array";

                variableNameGlobal = (yyvsp[-3].string);

                currentArrayIndex = atoi((yyvsp[-1].string));

                equationElementAddress = variablesAddressesMap[(yyvsp[-3].string)];
                int searchedIndex = variablesAddressesMap[(yyvsp[-3].string)] + currentArrayIndex;
                equationElementAddress  = variablesAddressesMap[(yyvsp[-3].string)];
                arrayIdentifierAddress  = variablesAddressesMap[(yyvsp[-1].string)]; // is only an address of a variable, not a value!!!
              }
             }
#line 3683 "gram.tab.cpp" /* yacc.c:1646  */
    break;


#line 3687 "gram.tab.cpp" /* yacc.c:1646  */
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
#line 2160 "gram.ypp" /* yacc.c:1906  */


void declareAVariable(std::string name) {
  if (!isVariableDeclared(&variablesAddressesMap, name)) {
    currentMemoryIndex++;
    variablesAddressesMap[name] = currentMemoryIndex;
    initializedVariablesMap[name] = false;

  } else {
    //throw an error
    std::cout << "Variable " << name << " already defined!" << "\n";
    exit(1);
  }
}

void displayArraySizesMap(std::map<std::string, int>* arraySizesMap) {
  for(auto elem : *arraySizesMap) {
     std::cout << elem.first << " " << elem.second << "\n";
  }
}

void declareAnArray(std::string name, int arraySize) {
  if (!isVariableDeclared(&variablesAddressesMap, name)) {

    currentMemoryIndex++;

    int arrayStartPoint = ++currentMemoryIndex;
    generateNumber(std::to_string(arrayStartPoint));
    pushCodeWithAddress("STORE", --arrayStartPoint);

    currentMemoryIndex = currentMemoryIndex -1;
    variablesAddressesMap[name] = currentMemoryIndex; // the beggining of an array
    arraysMap[name] = arraySize;
    currentMemoryIndex =  currentMemoryIndex + arraySize; //without the first one

  } else {
    std::cout << "Array " << name << " already defined!" << "\n";
    exit(1);
  }
}

bool isVariableDeclared(std::map<std::string, int> *mapToSearch, std::string name) {
  if ( (*mapToSearch).find(name) == (*mapToSearch).end() ) {
    return false;
  } else {
    return true;
  }
}

void showAllocatedMemoryIndexes() {
  for (int i = 0; i < 10; i++) {
    std::cout << "index: " << i << " allocated for computing variables\n";
  }
  std::cout << "###################\n\n\n\n";
}

void finish() {
  pushCode("HALT");
  // std::stack<std::pair<int, int>> temp = jumpStack;
  // std::cout << jumpStack.size() << "\n\n\n\n\n\n\n";
  // for (int i = 0; i < jumpStack.size(); i++) {
  //   std::pair<int, int> abc = temp.top();
  //   temp.pop();
  //   // std::cout << " SIZE " << temp.size() << "\n";
  //   std::cout << abc.first << " " << abc.second << "\n";
  // }
  // changeJumpValue();
  displayCommandVector(&commandsVector);
}

void displayMap(std::map<std::string, int>* mapToDisplay) {
  for(auto elem : *mapToDisplay) {
     std::cout << elem.first << " " << elem.second << "\n";
  }
}

void displayInitializedMap(std::map<std::string, bool>* map) {
  for(auto elem : *map) {
     std::cout << elem.first << " " << elem.second << "\n";
  }
}

bool isVariableInitialized(std::map<std::string, bool>* initializedMap, std::string variableName) {
  if ( (*initializedMap).find(variableName) == (*initializedMap).end() ) { // not found
    return false;
  } else { // found
    if ((*initializedMap)[variableName] == true) { //initialized
      return true;
    } else { // not initialized
      return false;
    }
  }
}

void displayCommandVector(std::vector<std::string> *commands) {
  int vectorSize = commands->size();
  for (int i=0; i < vectorSize; i++) {
    std::cout << commands->at(i) << "\n";
  }
}

/*===================================================*/
/*                 GENERATING CODE                   */
/*===================================================*/

void pushCode(std::string opCode) {
  commandsVector.push_back(opCode);
  // if (opCode != "HALT") {
    numberOfCommands++;
  // }
}

void pushCodeWithAddress(std::string opCode, int number) {
  std::string space = " ";
  std::string whole = opCode + space + std::to_string(number);
  commandsVector.push_back(whole);
  if (opCode == "JUMP" ) {
    if (number == JUMP_PLACEHOLDER_ADDRESS) {
      std::pair<int, int> newJumpPosition = std::make_pair(numberOfCommands, numberOfCommands);
      jumpStack.emplace(newJumpPosition);
    } else if (number == 21373) {
      // std::pair<int, int> newJumpPosition = std::make_pair(numberOfCommands, numberOfCommands);
      elseStack.emplace(numberOfCommands);
    }

  }
  numberOfCommands++;
}

void changeJumpValue() {
  std::string placeholder = std::to_string(JUMP_PLACEHOLDER_ADDRESS);
  int jumpStackSize = jumpStack.size();

  std::pair<int,int> topElement = jumpStack.top();
  jumpStack.pop();
  int destinationAddress = topElement.first;
  int destinationValue   = numberOfCommands;
  // std::cout << "1: " << topElement.first << " 2: " << topElement.second << " dest: "<< destinationValue << "\n";

  int finishIndex                    = commandsVector[destinationAddress].length() - placeholder.length(); // JUMP_-3000, usuwam 5 ostatnich znaków i mam JUMP_[   ]
  std::string address                = std::to_string(destinationValue);
  commandsVector[destinationAddress] = commandsVector[destinationAddress].substr(0, finishIndex) + address;

}

void changeJumpValue(int value) {
  std::string placeholder = std::to_string(JUMP_PLACEHOLDER_ADDRESS);

  if (jumpStack.size() > 0) {
    std::pair<int,int> topElement = jumpStack.top();
    jumpStack.pop();
    int destinationAddress = topElement.first;
    int destinationValue   = value;
    // std::cout << "1: " << topElement.first << " 2: " << topElement.second << " dest: "<< destinationValue << "\n";

    int finishIndex                    = commandsVector[destinationAddress].length() - placeholder.length(); // JUMP_-3000, usuwam 5 ostatnich znaków i mam JUMP_[   ]
    std::string address                = std::to_string(destinationValue);
    commandsVector[destinationAddress] = commandsVector[destinationAddress].substr(0, finishIndex) + address;
  }

}

void changeElseValue(int value) {
  std::string placeholder = std::to_string(JUMP_PLACEHOLDER_ADDRESS);

  if (elseStack.size() > 0) {
    // std::cout << "XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDd";
    int topElement = elseStack.top();
    elseStack.pop();
    int destinationAddress = topElement;
    int destinationValue   = value;
    // std::cout << "1: " << topElement.first << " 2: " << topElement.second << " dest: "<< destinationValue << "\n";

    int finishIndex                    = commandsVector[destinationAddress].length() - placeholder.length(); // JUMP_-3000, usuwam 5 ostatnich znaków i mam JUMP_[   ]
    std::string address                = std::to_string(destinationValue);
    commandsVector[destinationAddress] = commandsVector[destinationAddress].substr(0, finishIndex) + address;
  }
}



void generateNumber(std::string number) {

  std::vector<int> binaryRepresentationStack;
  long long decimalNumber2 = std::stoi(number);
  long long decimalNumber  = std::stoi(number);

  while(decimalNumber > 0) {
    if (decimalNumber % 2 == 0) {
      binaryRepresentationStack.insert(binaryRepresentationStack.begin(), 0);
    } else {
      binaryRepresentationStack.insert(binaryRepresentationStack.begin(), 1);
    }
    decimalNumber = decimalNumber / 2;
  }

  pushCode("ZERO");

  int binaryNumberLength = binaryRepresentationStack.size();

  for(int i = 0; i < binaryNumberLength; i++) {
    if (binaryRepresentationStack[i] == 1) {
      pushCode("INC");
    }
    if (i < binaryNumberLength -1) {
      pushCode("SHL");
    }
  }
}

std::string determineDataType(std::string a, std::string b) {
  if (a == "number" && b == "number") {
    return "number";
  } else if(a == "variable" && b == "variable") {
    return "variable";
  } else if(a == "array" && b == "array") {
    return "array";
  } else {
    return "arrayVar"; //array with a variable
  }
}

int computeRequiredMemoryCell(std::string variableName, int currentArrayIndex) {

  int startingIndex = variablesAddressesMap[variableName];
  int searchedIndex = startingIndex + currentArrayIndex;
  if (isDebugOn) {
    std::cout << "We start at index " << startingIndex << " looking for index " << searchedIndex << "\n";
  }
  return searchedIndex + ARRAY_INDEX_OFFSET;
}

/*===================================================*/
/*                     STRUCTURES                    */
/*===================================================*/

void freeAll() {

}

int main() {
  yyparse();
  return 0;
}

void yyerror (char *msg) {
    printf("ERROR\n");
}
