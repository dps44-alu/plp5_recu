/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "plp5.y"

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"
#include <stack>
#include <vector>
using namespace std;

TablaSimbolos *ts = nullptr;
TablaTipos tt;
unsigned dirActual = 0; // direccion libre para variables
std::stack<unsigned> pilaDir;
unsigned baseTipo; // para construir tipos de arrays
int ctemp = 16000;
int etiqueta = 0;
bool enIndices=false;
bool primeraIndice=true;
int corFila=0, corCol=0;
int comaFila=0, comaCol=0;
int indiceDepth=0;
struct SavedIndex { bool en; bool prim; int corF; int corC; int comaF; int comaC; size_t pos; };
std::vector<SavedIndex> idxStack;
std::vector<CodeAttr*> idxExprs;
std::string codigoFinal;
std::stack<unsigned> pilaIf;
std::stack<unsigned> pilaElse;

int nuevaTemp(void){
    if(ctemp>16383){
        errorSemantico(ERR_MAXTEMP,0,0,"");
    }
    return ctemp++;
}

int nuevaEtiqueta(){
    return etiqueta++;
}

int yylex();
void yyerror(const char *s);
extern int yylineno;
extern char *yytext;


#line 120 "plp5.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "plp5.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FN = 3,                         /* FN  */
  YYSYMBOL_ENDFN = 4,                      /* ENDFN  */
  YYSYMBOL_INTKW = 5,                      /* INTKW  */
  YYSYMBOL_REALKW = 6,                     /* REALKW  */
  YYSYMBOL_ARRAYKW = 7,                    /* ARRAYKW  */
  YYSYMBOL_LET = 8,                        /* LET  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ELIF = 12,                      /* ELIF  */
  YYSYMBOL_FI = 13,                        /* FI  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_LOOP = 15,                      /* LOOP  */
  YYSYMBOL_RANGE = 16,                     /* RANGE  */
  YYSYMBOL_ENDLOOP = 17,                   /* ENDLOOP  */
  YYSYMBOL_BLQ = 18,                       /* BLQ  */
  YYSYMBOL_FBLQ = 19,                      /* FBLQ  */
  YYSYMBOL_READ = 20,                      /* READ  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_PARI = 22,                      /* PARI  */
  YYSYMBOL_PARD = 23,                      /* PARD  */
  YYSYMBOL_CORI = 24,                      /* CORI  */
  YYSYMBOL_CORD = 25,                      /* CORD  */
  YYSYMBOL_COMA = 26,                      /* COMA  */
  YYSYMBOL_DOSP = 27,                      /* DOSP  */
  YYSYMBOL_PYC = 28,                       /* PYC  */
  YYSYMBOL_ASIG = 29,                      /* ASIG  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_NUMINT = 31,                    /* NUMINT  */
  YYSYMBOL_NUMREAL = 32,                   /* NUMREAL  */
  YYSYMBOL_OPAS = 33,                      /* OPAS  */
  YYSYMBOL_OPMD = 34,                      /* OPMD  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_S = 36,                         /* S  */
  YYSYMBOL_Fun = 37,                       /* Fun  */
  YYSYMBOL_SType = 38,                     /* SType  */
  YYSYMBOL_Type = 39,                      /* Type  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_Dim = 41,                       /* Dim  */
  YYSYMBOL_Cod = 42,                       /* Cod  */
  YYSYMBOL_I = 43,                         /* I  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_Range = 45,                     /* Range  */
  YYSYMBOL_Blq = 46,                       /* Blq  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_Ip = 48,                        /* Ip  */
  YYSYMBOL_IT = 49,                        /* IT  */
  YYSYMBOL_E = 50,                         /* E  */
  YYSYMBOL_T = 51,                         /* T  */
  YYSYMBOL_F = 52,                         /* F  */
  YYSYMBOL_Ref = 53,                       /* Ref  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_LExpr = 55                      /* LExpr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    89,    90,    93,    94,    94,    97,
     101,   107,   108,   109,   112,   113,   125,   132,   135,   138,
     147,   162,   162,   181,   182,   185,   185,   191,   192,   199,
     202,   203,   206,   207,   211,   214,   215,   218,   219,   220,
     221,   224,   236,   236,   273,   280
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FN", "ENDFN", "INTKW",
  "REALKW", "ARRAYKW", "LET", "VAR", "IF", "ELSE", "ELIF", "FI", "WHILE",
  "LOOP", "RANGE", "ENDLOOP", "BLQ", "FBLQ", "READ", "PRINT", "PARI",
  "PARD", "CORI", "CORD", "COMA", "DOSP", "PYC", "ASIG", "ID", "NUMINT",
  "NUMREAL", "OPAS", "OPMD", "$accept", "S", "Fun", "SType", "Type", "$@1",
  "Dim", "Cod", "I", "$@2", "Range", "Blq", "$@3", "Ip", "IT", "E", "T",
  "F", "Ref", "$@4", "LExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,    13,    28,   -30,    23,   -30,    37,    26,    31,    32,
      20,    20,    38,   -30,    31,    20,    -2,   -30,   -30,    25,
      40,    43,    20,   -30,   -30,    34,    39,    41,   -30,   -30,
       4,    51,    26,   -30,    39,   -30,    26,   -30,    20,     3,
     -30,   -17,    41,    34,    26,    34,   -30,    42,     1,   -30,
      20,    39,   -30,   -30,    49,   -30,   -30,   -30,    41,    19,
     -30,    44,    26,   -30,    39,    33,   -30,    26,    20,   -30,
     -30,    45,    57,   -30,    20,    46,    65,     4,   -30,   -30,
      39,    53,   -30,   -30,    19,    46,   -30,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,    13,    14,    41,
       0,    31,     0,    37,    38,     0,    21,    34,    36,    40,
       0,     0,     0,    18,    17,     3,    12,    42,     0,     0,
      16,     0,    33,     0,     0,     0,    19,     0,     0,    11,
       0,    15,     4,     5,     0,     6,    30,    39,    32,     0,
      35,    24,     0,    26,    45,     0,     7,     0,     0,    29,
      22,     0,     0,    43,     0,     0,     0,     0,    23,    20,
      44,    10,     8,    27,     0,     0,    28,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,    27,   -30,   -30,    -5,    50,   -29,   -30,
     -30,   -30,   -30,    -1,   -30,   -11,   -22,    47,     9,   -30,
     -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    55,    56,    75,    82,    16,    17,    44,
      62,    18,    32,    70,    40,    26,    27,    28,    29,    50,
      65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    46,    35,    42,    34,     1,    57,    49,    52,    53,
      54,    41,     8,     9,    10,    59,    43,    20,    11,    12,
      63,    58,    13,    33,    14,    15,    36,    51,     5,    36,
      67,    68,    69,    72,     8,     9,    10,    43,    76,    64,
      11,    12,    22,     4,    13,     6,    14,    15,    84,    37,
      19,    23,    24,    25,    52,    53,    22,    77,    73,    74,
       7,    19,    21,    80,    19,    23,    24,    47,    31,    38,
      39,    71,    43,    61,    79,    45,    78,    81,    83,    85,
      87,    66,    48,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    60
};

static const yytype_int8 yycheck[] =
{
      11,    30,     4,    25,    15,     3,    23,    36,     5,     6,
       7,    22,     8,     9,    10,    44,    33,     8,    14,    15,
      19,    43,    18,    14,    20,    21,    28,    38,     0,    28,
      11,    12,    13,    62,     8,     9,    10,    33,    67,    50,
      14,    15,    22,    30,    18,    22,    20,    21,    77,    24,
      30,    31,    32,    33,     5,     6,    22,    68,    25,    26,
      23,    30,    30,    74,    30,    31,    32,    16,    30,    29,
      27,    27,    33,    31,    17,    34,    31,    31,    13,    26,
      85,    54,    32,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    36,    37,    30,     0,    22,    23,     8,     9,
      10,    14,    15,    18,    20,    21,    42,    43,    46,    30,
      53,    30,    22,    31,    32,    33,    50,    51,    52,    53,
      50,    30,    47,    53,    50,     4,    28,    24,    29,    27,
      49,    50,    51,    33,    44,    34,    43,    16,    42,    43,
      54,    50,     5,     6,     7,    38,    39,    23,    51,    43,
      52,    31,    45,    19,    50,    55,    38,    11,    12,    13,
      48,    27,    43,    25,    26,    40,    43,    50,    31,    17,
      50,    31,    41,    13,    43,    26,    48,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    38,    39,    40,    39,    41,
      41,    42,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    43,    45,    45,    47,    46,    48,    48,    48,
      49,    49,    50,    50,    50,    51,    51,    52,    52,    52,
      52,    53,    54,    53,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     6,     1,     1,     1,     0,     4,     3,
       1,     3,     2,     1,     1,     4,     3,     2,     2,     3,
       6,     0,     5,     3,     1,     0,     4,     3,     4,     1,
       2,     0,     3,     2,     1,     3,     1,     1,     1,     3,
       1,     1,     0,     5,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: Fun  */
#line 83 "plp5.y"
        { codigoFinal = (yyvsp[0].code)->cod; }
#line 1601 "plp5.tab.c"
    break;

  case 3: /* Fun: FN ID PARI PARD Cod ENDFN  */
#line 86 "plp5.y"
                                { (yyval.code) = (yyvsp[-1].code); }
#line 1607 "plp5.tab.c"
    break;

  case 4: /* SType: INTKW  */
#line 89 "plp5.y"
              { (yyval.tipo) = 0; }
#line 1613 "plp5.tab.c"
    break;

  case 5: /* SType: REALKW  */
#line 90 "plp5.y"
               { (yyval.tipo) = 1; }
#line 1619 "plp5.tab.c"
    break;

  case 6: /* Type: SType  */
#line 93 "plp5.y"
             { (yyval.tinfo).tipo=(yyvsp[0].tipo); (yyval.tinfo).tam=1; (yyval.tinfo).ndim=0; }
#line 1625 "plp5.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 94 "plp5.y"
                     { baseTipo=(yyvsp[0].tipo)==0?0:1; }
#line 1631 "plp5.tab.c"
    break;

  case 8: /* Type: ARRAYKW SType $@1 Dim  */
#line 94 "plp5.y"
                                                 { (yyval.tinfo).tipo=(yyvsp[0].tinfo).tipo; (yyval.tinfo).tam=(yyvsp[0].tinfo).tam; (yyval.tinfo).ndim=(yyvsp[0].tinfo).ndim; }
#line 1637 "plp5.tab.c"
    break;

  case 9: /* Dim: NUMINT COMA Dim  */
#line 97 "plp5.y"
                      {
        if((yyvsp[-2].num)<=0) errorSemantico(ERR_DIM,(yylsp[-2]).first_line,(yylsp[-2]).first_column,"");
        unsigned t=tt.nuevoTipoArray((yyvsp[-2].num),(yyvsp[0].tinfo).tipo); (yyval.tinfo).tipo=t; (yyval.tinfo).tam=(yyvsp[-2].num)*(yyvsp[0].tinfo).tam; (yyval.tinfo).ndim=(yyvsp[0].tinfo).ndim+1;
    }
#line 1646 "plp5.tab.c"
    break;

  case 10: /* Dim: NUMINT  */
#line 101 "plp5.y"
             {
        if((yyvsp[0].num)<=0) errorSemantico(ERR_DIM,(yylsp[0]).first_line,(yylsp[0]).first_column,"");
        unsigned t=tt.nuevoTipoArray((yyvsp[0].num),baseTipo); (yyval.tinfo).tipo=t; (yyval.tinfo).tam=(yyvsp[0].num); (yyval.tinfo).ndim=1;
    }
#line 1655 "plp5.tab.c"
    break;

  case 11: /* Cod: Cod PYC I  */
#line 107 "plp5.y"
                { (yyval.code) = new CodeAttr( mergeCode(*(yyvsp[-2].code),*(yyvsp[0].code)) ); }
#line 1661 "plp5.tab.c"
    break;

  case 12: /* Cod: Cod PYC  */
#line 108 "plp5.y"
              { (yyval.code) = (yyvsp[-1].code); }
#line 1667 "plp5.tab.c"
    break;

  case 13: /* Cod: I  */
#line 109 "plp5.y"
        { (yyval.code) = (yyvsp[0].code); }
#line 1673 "plp5.tab.c"
    break;

  case 14: /* I: Blq  */
#line 112 "plp5.y"
        { (yyval.code) = (yyvsp[0].code); }
#line 1679 "plp5.tab.c"
    break;

  case 15: /* I: LET Ref ASIG E  */
#line 113 "plp5.y"
                    {
        if(!(( (yyvsp[-2].code)->tipo==1 && (yyvsp[0].code)->tipo==0) || (yyvsp[-2].code)->tipo==(yyvsp[0].code)->tipo ))
             errorSemantico(ERR_ASIG,(yylsp[-1]).first_line,(yylsp[-1]).first_column,"");
        CodeAttr tmp = convertType(*(yyvsp[0].code),(yyvsp[-2].code)->tipo);
        CodeAttr *res = new CodeAttr();
        res->cod = tmp.cod;
        res->cod += "mov "+std::to_string(tmp.dir)+" B\n";
        res->cod += (yyvsp[-2].code)->cod;
        res->cod += "mov B @A\n";
        res->tipo = 0; res->dir=0;
        (yyval.code)=res;
      }
#line 1696 "plp5.tab.c"
    break;

  case 16: /* I: VAR ID IT  */
#line 125 "plp5.y"
               {
        Simbolo s; s.nombre=(yyvsp[-1].lexema); s.tipo=(yyvsp[0].tinfo).tipo; s.dir=dirActual; s.tam=(yyvsp[0].tinfo).tam;
        if(!ts->newSymb(s)) errorSemantico(ERR_YADECL,(yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-1].lexema));
        if(dirActual + s.tam > 16000) errorSemantico(ERR_NOCABE,(yylsp[-1]).first_line,(yylsp[-1]).first_column,(yyvsp[-1].lexema));
        dirActual += s.tam;
        (yyval.code) = new CodeAttr();
      }
#line 1708 "plp5.tab.c"
    break;

  case 17: /* I: PRINT E  */
#line 132 "plp5.y"
             {
        CodeAttr e=*((yyvsp[0].code)); CodeAttr *r=new CodeAttr(); r->cod=e.cod; r->cod+="mov "+std::to_string(e.dir)+" A\n"; r->cod+=(e.tipo?"wrr A\n":"wri A\n"); r->cod+="wrl\n"; (yyval.code)=r;
      }
#line 1716 "plp5.tab.c"
    break;

  case 18: /* I: READ Ref  */
#line 135 "plp5.y"
              {
        CodeAttr *r=(yyvsp[0].code); CodeAttr *res=new CodeAttr(); res->cod=r->cod; res->cod+=(r->tipo?"rdr @A\n":"rdi @A\n"); (yyval.code)=res;
      }
#line 1724 "plp5.tab.c"
    break;

  case 19: /* I: WHILE E I  */
#line 138 "plp5.y"
               {
        if((yyvsp[-1].code)->tipo!=0) errorSemantico(ERR_IFWHILE,(yylsp[-2]).first_line,(yylsp[-2]).first_column,"while");
        unsigned L1=nuevaEtiqueta(), L2=nuevaEtiqueta();
        string lab1="L"+to_string(L1), lab2="L"+to_string(L2);
        CodeAttr cond=*((yyvsp[-1].code)); CodeAttr body=*((yyvsp[0].code)); CodeAttr *res=new CodeAttr();
        res->cod=lab1+"\n"+cond.cod+"mov "+to_string(cond.dir)+" A\n"+
                 "jz "+lab2+"\n"+body.cod+"jmp "+lab1+"\n"+lab2+"\n";
        (yyval.code)=res;
      }
#line 1738 "plp5.tab.c"
    break;

  case 20: /* I: LOOP ID RANGE Range I ENDLOOP  */
#line 147 "plp5.y"
                                   {
        Simbolo *s = ts->searchSymb((yyvsp[-4].lexema));
        if(!s) errorSemantico(ERR_NODECL,(yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-4].lexema));
        else if(!(tt.tipos[s->tipo].clase==TIPOBASICO && s->tipo==0))
            errorSemantico(ERR_LOOP,(yylsp[-5]).first_line,(yylsp[-5]).first_column,"loop");
        unsigned Lc=nuevaEtiqueta(),Le=nuevaEtiqueta();
        string lc="L"+to_string(Lc), le="L"+to_string(Le);
        CodeAttr body=*((yyvsp[-1].code)); CodeAttr *res=new CodeAttr();
        res->cod="mov #"+to_string((yyvsp[-2].rango).ini)+" A\nmov A "+to_string(s->dir)+"\n";
        res->cod+=lc+"\nmov "+to_string(s->dir)+" A\nsubi #"+to_string((yyvsp[-2].rango).fin+1)+"\njz "+le+"\n";
        res->cod+=body.cod;
        res->cod+="mov "+to_string(s->dir)+" A\naddi #1\nmov A "+to_string(s->dir)+"\n";
        res->cod+="jmp "+lc+"\n"+le+"\n";
        (yyval.code)=res;
      }
#line 1758 "plp5.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 162 "plp5.y"
          {
        if((yyvsp[0].code)->tipo!=0) errorSemantico(ERR_IFWHILE,(yylsp[-1]).first_line,(yylsp[-1]).first_column,"if");
        unsigned lend = nuevaEtiqueta();
        unsigned lelse = nuevaEtiqueta();
        pilaIf.push(lend);
        pilaElse.push(lelse);
      }
#line 1770 "plp5.tab.c"
    break;

  case 22: /* I: IF E $@2 I Ip  */
#line 168 "plp5.y"
             {
        unsigned lend = pilaIf.top(); pilaIf.pop();
        unsigned lelse = pilaElse.top(); pilaElse.pop();
        CodeAttr cond=*((yyvsp[-3].code)), thenCode=*((yyvsp[-1].code)), elsePart=*((yyvsp[0].code)); CodeAttr *res=new CodeAttr();
        string sElse="L"+to_string(lelse), sEnd="L"+to_string(lend);
        res->cod=cond.cod+"mov "+to_string(cond.dir)+" A\n"+
                "jz "+sElse+"\n"+thenCode.cod+
                "jmp "+sEnd+"\n"+sElse+"\n"+
                elsePart.cod+sEnd+"\n";
        (yyval.code)=res;
      }
#line 1786 "plp5.tab.c"
    break;

  case 23: /* Range: NUMINT DOSP NUMINT  */
#line 181 "plp5.y"
                           { (yyval.rango).ini=(yyvsp[-2].num); (yyval.rango).fin=(yyvsp[0].num); }
#line 1792 "plp5.tab.c"
    break;

  case 24: /* Range: NUMINT  */
#line 182 "plp5.y"
               { (yyval.rango).ini=0; (yyval.rango).fin=(yyvsp[0].num); }
#line 1798 "plp5.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 185 "plp5.y"
          { ts=new TablaSimbolos(ts); pilaDir.push(dirActual); }
#line 1804 "plp5.tab.c"
    break;

  case 26: /* Blq: BLQ $@3 Cod FBLQ  */
#line 185 "plp5.y"
                                                                          {
        dirActual=pilaDir.top(); pilaDir.pop(); ts=ts->getPadre();
        (yyval.code) = (yyvsp[-1].code);
    }
#line 1813 "plp5.tab.c"
    break;

  case 27: /* Ip: ELSE I FI  */
#line 191 "plp5.y"
               { (yyval.code) = (yyvsp[-1].code); }
#line 1819 "plp5.tab.c"
    break;

  case 28: /* Ip: ELIF E I Ip  */
#line 192 "plp5.y"
                 {
        unsigned lnext = nuevaEtiqueta();
        CodeAttr cond=*((yyvsp[-2].code)), body=*((yyvsp[-1].code)), tail=*((yyvsp[0].code)); CodeAttr *res=new CodeAttr();
        string snext="L"+to_string(lnext); string send="L"+to_string(pilaIf.top());
        res->cod=cond.cod+"mov "+to_string(cond.dir)+" A\n"+"jz "+snext+"\n"+body.cod+"jmp "+send+"\n"+snext+"\n"+tail.cod;
        (yyval.code)=res;
      }
#line 1831 "plp5.tab.c"
    break;

  case 29: /* Ip: FI  */
#line 199 "plp5.y"
        { (yyval.code) = new CodeAttr(); }
#line 1837 "plp5.tab.c"
    break;

  case 30: /* IT: DOSP Type  */
#line 202 "plp5.y"
               { (yyval.tinfo) = (yyvsp[0].tinfo); }
#line 1843 "plp5.tab.c"
    break;

  case 31: /* IT: %empty  */
#line 203 "plp5.y"
                 { (yyval.tinfo).tipo=0; (yyval.tinfo).tam=1; (yyval.tinfo).ndim=0; }
#line 1849 "plp5.tab.c"
    break;

  case 32: /* E: E OPAS T  */
#line 206 "plp5.y"
             { (yyval.code) = new CodeAttr(binOp(*(yyvsp[-2].code),*(yyvsp[0].code),(yyvsp[-1].lexema))); }
#line 1855 "plp5.tab.c"
    break;

  case 33: /* E: OPAS T  */
#line 207 "plp5.y"
           {
        if(strcmp((yyvsp[-1].lexema),"-")==0){ CodeAttr zero=constInt(0); (yyval.code)= new CodeAttr(binOp(zero,*(yyvsp[0].code),"-")); }
        else (yyval.code)=(yyvsp[0].code);
    }
#line 1864 "plp5.tab.c"
    break;

  case 34: /* E: T  */
#line 211 "plp5.y"
      { (yyval.code) = (yyvsp[0].code); }
#line 1870 "plp5.tab.c"
    break;

  case 35: /* T: T OPMD F  */
#line 214 "plp5.y"
             { (yyval.code) = new CodeAttr(binOp(*(yyvsp[-2].code),*(yyvsp[0].code),(yyvsp[-1].lexema))); }
#line 1876 "plp5.tab.c"
    break;

  case 36: /* T: F  */
#line 215 "plp5.y"
      { (yyval.code) = (yyvsp[0].code); }
#line 1882 "plp5.tab.c"
    break;

  case 37: /* F: NUMINT  */
#line 218 "plp5.y"
           { (yyval.code) = new CodeAttr(constInt((yyvsp[0].num))); }
#line 1888 "plp5.tab.c"
    break;

  case 38: /* F: NUMREAL  */
#line 219 "plp5.y"
            { (yyval.code) = new CodeAttr(constReal((yyvsp[0].real))); }
#line 1894 "plp5.tab.c"
    break;

  case 39: /* F: PARI E PARD  */
#line 220 "plp5.y"
                { (yyval.code)=(yyvsp[-1].code); }
#line 1900 "plp5.tab.c"
    break;

  case 40: /* F: Ref  */
#line 221 "plp5.y"
        { (yyval.code)= new CodeAttr(loadFromAddr(*(yyvsp[0].code),(yyvsp[0].code)->tipo)); }
#line 1906 "plp5.tab.c"
    break;

  case 41: /* Ref: ID  */
#line 224 "plp5.y"
         {
        Simbolo *s = ts->searchSymb((yyvsp[0].lexema));
        CodeAttr *r=new CodeAttr(); r->cod=""; r->dir=0; r->tipo=0;
        if(!s){
            if(indiceDepth==0) errorSemantico(ERR_NODECL,(yylsp[0]).first_line,(yylsp[0]).first_column,(yyvsp[0].lexema));
            r->cod="mov #0 A\n";
        }else{
            r->tipo=s->tipo;
            r->cod="mov #"+to_string(s->dir)+" A\n";
        }
        (yyval.code)=r;
    }
#line 1923 "plp5.tab.c"
    break;

  case 42: /* $@4: %empty  */
#line 236 "plp5.y"
              {
        SavedIndex tmp{enIndices,primeraIndice,corFila,corCol,comaFila,comaCol,idxExprs.size()};
        idxStack.push_back(tmp);
        enIndices=true; primeraIndice=true;
        corFila=(yylsp[0]).first_line; corCol=(yylsp[0]).first_column;
        comaFila=corFila; comaCol=corCol;
        indiceDepth++;
    }
#line 1936 "plp5.tab.c"
    break;

  case 43: /* Ref: ID CORI $@4 LExpr CORD  */
#line 243 "plp5.y"
                 {
        indiceDepth--;
        Simbolo *s = ts->searchSymb((yyvsp[-4].lexema));
        CodeAttr *r=new CodeAttr(); r->cod=""; r->dir=0; r->tipo=0;
        if(!s){
            errorSemantico(ERR_NODECL,(yylsp[-4]).first_line,(yylsp[-4]).first_column,(yyvsp[-4].lexema));
        }else{
            unsigned t=s->tipo; unsigned dims=0; std::vector<unsigned> dsz;
            while(tt.tipos[t].clase==ARRAY){ dsz.push_back(tt.tipos[t].tamano); dims++; t=tt.tipos[t].tipoBase; }
            if((yyvsp[-1].num)<dims) errorSemantico(ERR_FALTAN,(yylsp[0]).first_line,(yylsp[0]).first_column,"");
            if((yyvsp[-1].num)>dims) errorSemantico(ERR_SOBRAN,comaFila,comaCol,"");
            t=s->tipo; for(int i=0;i<(yyvsp[-1].num) && tt.tipos[t].clase==ARRAY;i++) t=tt.tipos[t].tipoBase;
            r->tipo=t;
            size_t pos=idxStack.back().pos; std::vector<CodeAttr*> exprs(idxExprs.begin()+pos,idxExprs.end()); idxExprs.resize(pos);
            std::vector<unsigned> mult(dims); unsigned prod=1; for(int i=dims; i>0; --i){ mult[i-1]=prod; prod*=dsz[i-1]; }
            CodeAttr off=constInt(s->dir);
            for(size_t i=0;i<exprs.size();i++){
                CodeAttr idx=convertType(*exprs[i],0);
                if(mult[i]!=1){ CodeAttr m=constInt(mult[i]); idx=binOp(idx,m,"*"); }
                off=binOp(off,idx,"+");
            }
            r->cod=off.cod+"mov "+to_string(off.dir)+" A\n";
        }
        SavedIndex rec=idxStack.back();
        idxStack.pop_back();
        enIndices=rec.en; primeraIndice=rec.prim; corFila=rec.corF; corCol=rec.corC; comaFila=rec.comaF; comaCol=rec.comaC;
        (yyval.code)=r;
    }
#line 1969 "plp5.tab.c"
    break;

  case 44: /* LExpr: LExpr COMA E  */
#line 273 "plp5.y"
                     {
          if(enIndices && (yyvsp[0].code)->tipo!=0) errorSemantico(ERR_INDICE_ENTERO,(yylsp[-1]).first_line,(yylsp[-1]).first_column,"");
          (yyval.num)=(yyvsp[-2].num)+1;
          primeraIndice=false;
          comaFila=(yylsp[-1]).first_line; comaCol=(yylsp[-1]).first_column;
          idxExprs.push_back((yyvsp[0].code));
       }
#line 1981 "plp5.tab.c"
    break;

  case 45: /* LExpr: E  */
#line 280 "plp5.y"
          {
          if(enIndices && (yyvsp[0].code)->tipo!=0){
              if(primeraIndice) errorSemantico(ERR_INDICE_ENTERO,corFila,corCol,"");
              else errorSemantico(ERR_INDICE_ENTERO,(yylsp[0]).first_line,(yylsp[0]).first_column,"");
          }
          (yyval.num)=1;
          primeraIndice=false;
          idxExprs.push_back((yyvsp[0].code));
       }
#line 1995 "plp5.tab.c"
    break;


#line 1999 "plp5.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 290 "plp5.y"


extern FILE *yyin;

int main(int argc,char *argv[]){
    ts = new TablaSimbolos(nullptr);
    if(argc>1){
        yyin=fopen(argv[1],"r");
        if(!yyin){
            fprintf(stderr,"No puedo abrir %s\n",argv[1]);
            return 1;
        }
    }
    yyparse();
    printf("%s",codigoFinal.c_str());
    printf("halt\n");
    return 0;
}

void yyerror(const char *s){
    msgError(ERRSINT,yylineno,0,yytext);
}

void errorSemantico(int nerror,int fila,int columna,const char *s)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    switch (nerror) {
        case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s); break;
        case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s); break;
        case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s); break;
        case ERR_IFWHILE:fprintf(stderr,"la expresion del '%s' debe ser de tipo entero",s); break;
        case ERR_LOOP:fprintf(stderr,"la variable del '%s' debe ser de tipo entero",s); break;
        case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que 0\n"); break;
        case ERR_FALTAN: fprintf(stderr,"faltan indices\n"); break;
        case ERR_SOBRAN: fprintf(stderr,"sobran indices\n"); break;
        case ERR_INDICE_ENTERO: fprintf(stderr,"el indice de un array debe ser de tipo entero\n"); break;
        case ERR_ASIG: fprintf(stderr,"tipos incompatibles en la asignacion\n"); break;
        case ERR_MAXTEMP:fprintf(stderr,"no hay espacio para variables temporales\n"); break;
    }
    exit(-1);
}

void msgError(int nerror,int nlin,int ncol,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s); break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s); break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n"); break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n"); break;
     }
     exit(1);
}
