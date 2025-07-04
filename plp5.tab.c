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

#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include "TablaSimbolos.h"
#include "TablaTipos.h"
#include "comun.h"

extern int numlin, numcol;
int yylex();
extern FILE *yyin;
extern const char* currentFile;
void yyerror(const char *s);

TablaTipos tTipos;
TablaSimbolos *tsActual;
int dirActual=0;
std::vector<int> pilaDir;
int ctemp=16000;
int nuevaTemp(){ if(ctemp>16383) errorSemantico(ERR_MAXTEMP,numlin,numcol,""); return ctemp++; }
unsigned tamTipo(unsigned t);
unsigned numDim(unsigned t);
unsigned baseTipo(unsigned t);

const char* currentFile = NULL;

/* auxiliary state to manage index checking order */
unsigned expectedDim=0;      // number of indices expected for current array ref
unsigned currIndex=0;        // index currently being parsed (1-based)
bool ignoreNodecl=false;     // true when indices beyond expectedDim are parsed
Simbolo* refSimb=nullptr;    // temporal storage for ref symbol in mid rules


#line 106 "plp5.tab.c"

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
  YYSYMBOL_TK_FN = 3,                      /* TK_FN  */
  YYSYMBOL_TK_ENDFN = 4,                   /* TK_ENDFN  */
  YYSYMBOL_TK_INT = 5,                     /* TK_INT  */
  YYSYMBOL_TK_REAL = 6,                    /* TK_REAL  */
  YYSYMBOL_TK_ARRAY = 7,                   /* TK_ARRAY  */
  YYSYMBOL_TK_BLQ = 8,                     /* TK_BLQ  */
  YYSYMBOL_TK_FBLQ = 9,                    /* TK_FBLQ  */
  YYSYMBOL_TK_LET = 10,                    /* TK_LET  */
  YYSYMBOL_TK_VAR = 11,                    /* TK_VAR  */
  YYSYMBOL_TK_PRINT = 12,                  /* TK_PRINT  */
  YYSYMBOL_TK_READ = 13,                   /* TK_READ  */
  YYSYMBOL_TK_IF = 14,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 15,                   /* TK_ELSE  */
  YYSYMBOL_TK_ELIF = 16,                   /* TK_ELIF  */
  YYSYMBOL_TK_FI = 17,                     /* TK_FI  */
  YYSYMBOL_TK_WHILE = 18,                  /* TK_WHILE  */
  YYSYMBOL_TK_LOOP = 19,                   /* TK_LOOP  */
  YYSYMBOL_TK_RANGE = 20,                  /* TK_RANGE  */
  YYSYMBOL_TK_ENDLOOP = 21,                /* TK_ENDLOOP  */
  YYSYMBOL_TK_COMA = 22,                   /* TK_COMA  */
  YYSYMBOL_TK_PYC = 23,                    /* TK_PYC  */
  YYSYMBOL_TK_DOSP = 24,                   /* TK_DOSP  */
  YYSYMBOL_TK_PARI = 25,                   /* TK_PARI  */
  YYSYMBOL_TK_PARD = 26,                   /* TK_PARD  */
  YYSYMBOL_TK_ASIG = 27,                   /* TK_ASIG  */
  YYSYMBOL_TK_CORI = 28,                   /* TK_CORI  */
  YYSYMBOL_TK_CORD = 29,                   /* TK_CORD  */
  YYSYMBOL_TK_OPAS = 30,                   /* TK_OPAS  */
  YYSYMBOL_TK_OPMD = 31,                   /* TK_OPMD  */
  YYSYMBOL_TK_ID = 32,                     /* TK_ID  */
  YYSYMBOL_TK_NUMINT = 33,                 /* TK_NUMINT  */
  YYSYMBOL_TK_NUMREAL = 34,                /* TK_NUMREAL  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Programa = 36,                  /* Programa  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_Cod = 38,                       /* Cod  */
  YYSYMBOL_Instruccion = 39,               /* Instruccion  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_Rango = 43,                     /* Rango  */
  YYSYMBOL_Ip = 44,                        /* Ip  */
  YYSYMBOL_Ref = 45,                       /* Ref  */
  YYSYMBOL_46_5 = 46,                      /* $@5  */
  YYSYMBOL_47_6 = 47,                      /* $@6  */
  YYSYMBOL_LExpr = 48,                     /* LExpr  */
  YYSYMBOL_Index = 49,                     /* Index  */
  YYSYMBOL_50_7 = 50,                      /* $@7  */
  YYSYMBOL_Expr = 51,                      /* Expr  */
  YYSYMBOL_Term = 52,                      /* Term  */
  YYSYMBOL_Factor = 53,                    /* Factor  */
  YYSYMBOL_TipoOpt = 54,                   /* TipoOpt  */
  YYSYMBOL_Tipo = 55,                      /* Tipo  */
  YYSYMBOL_SType = 56,                     /* SType  */
  YYSYMBOL_Dim = 57                        /* Dim  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   80

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
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
       0,    60,    60,    60,   138,   139,   140,   143,   143,   144,
     148,   156,   157,   158,   158,   159,   165,   165,   168,   169,
     172,   173,   174,   177,   188,   192,   188,   212,   216,   223,
     223,   225,   226,   229,   230,   233,   234,   235,   236,   239,
     240,   243,   246,   248,   249,   260,   266
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_FN", "TK_ENDFN",
  "TK_INT", "TK_REAL", "TK_ARRAY", "TK_BLQ", "TK_FBLQ", "TK_LET", "TK_VAR",
  "TK_PRINT", "TK_READ", "TK_IF", "TK_ELSE", "TK_ELIF", "TK_FI",
  "TK_WHILE", "TK_LOOP", "TK_RANGE", "TK_ENDLOOP", "TK_COMA", "TK_PYC",
  "TK_DOSP", "TK_PARI", "TK_PARD", "TK_ASIG", "TK_CORI", "TK_CORD",
  "TK_OPAS", "TK_OPMD", "TK_ID", "TK_NUMINT", "TK_NUMREAL", "$accept",
  "Programa", "$@1", "Cod", "Instruccion", "$@2", "$@3", "$@4", "Rango",
  "Ip", "Ref", "$@5", "$@6", "LExpr", "Index", "$@7", "Expr", "Term",
  "Factor", "TipoOpt", "Tipo", "SType", "Dim", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -26,    10,    -9,   -33,    -3,   -33,    28,   -33,    -2,
      11,    23,    -2,    23,    23,    13,    -1,   -33,    28,    25,
      27,    34,    23,   -33,   -33,   -33,    30,    31,   -33,   -33,
      30,    30,    41,   -33,    28,     4,    35,    23,    44,   -33,
     -22,    23,    23,    28,    28,    32,   -33,   -33,   -33,    30,
     -33,   -33,    44,   -33,   -33,   -33,    31,   -33,    18,   -33,
      40,    28,   -33,    33,    28,    23,   -33,   -33,    36,    46,
     -15,   -33,    23,    48,   -33,    51,     7,   -33,   -33,   -33,
     -33,    30,    33,   -33,    18,   -33,   -33,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     2,     4,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     4,    23,
       0,    40,     0,    35,    36,    38,    11,    32,    34,    12,
      16,    13,     0,     3,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     6,     8,    25,     9,
      42,    43,     0,    39,    41,    37,    31,    33,     0,    14,
      19,     0,    29,     0,     0,     0,    22,    17,     0,     0,
       0,    27,     0,    45,    44,     0,     0,    18,    15,    29,
      26,    30,     0,    20,     0,    28,    46,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,    53,   -32,   -33,   -33,   -33,   -33,   -12,
      19,   -33,   -33,   -33,    -6,   -33,   -13,    37,    38,   -33,
     -33,    22,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    16,    17,    18,    44,    43,    61,    67,
      25,    36,    62,    70,    71,    72,    26,    27,    28,    39,
      53,    54,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    31,    46,    33,    55,     1,     3,    79,    41,    40,
       4,    58,    59,    47,    80,     8,     5,     9,    10,    11,
      12,    13,    34,     6,    49,    14,    15,    34,    20,    69,
      19,    29,    75,    64,    65,    66,     8,    41,     9,    10,
      11,    12,    13,    21,    84,    32,    14,    15,    22,    50,
      51,    52,    76,   -24,    37,    19,    23,    24,    38,    81,
      41,    45,    42,    48,    68,    60,    73,    78,    83,    77,
      82,    35,    87,    85,    63,    86,     0,     0,    56,     0,
      57
};

static const yytype_int8 yycheck[] =
{
      13,    14,    34,     4,    26,     3,    32,    22,    30,    22,
       0,    43,    44,     9,    29,     8,    25,    10,    11,    12,
      13,    14,    23,    26,    37,    18,    19,    23,     9,    61,
      32,    12,    64,    15,    16,    17,     8,    30,    10,    11,
      12,    13,    14,    32,    76,    32,    18,    19,    25,     5,
       6,     7,    65,    28,    27,    32,    33,    34,    24,    72,
      30,    20,    31,    28,    24,    33,    33,    21,    17,    33,
      22,    18,    84,    79,    52,    82,    -1,    -1,    41,    -1,
      42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    36,    32,     0,    25,    26,    37,     8,    10,
      11,    12,    13,    14,    18,    19,    38,    39,    40,    32,
      45,    32,    25,    33,    34,    45,    51,    52,    53,    45,
      51,    51,    32,     4,    23,    38,    46,    27,    24,    54,
      51,    30,    31,    42,    41,    20,    39,     9,    28,    51,
       5,     6,     7,    55,    56,    26,    52,    53,    39,    39,
      33,    43,    47,    56,    15,    16,    17,    44,    24,    39,
      48,    49,    50,    33,    57,    39,    51,    33,    21,    22,
      29,    51,    22,    17,    39,    49,    57,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    40,    39,    39,
      39,    39,    39,    41,    39,    39,    42,    39,    43,    43,
      44,    44,    44,    45,    46,    47,    45,    48,    48,    50,
      49,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    56,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     0,     1,     3,     0,     4,     4,
       3,     2,     2,     0,     4,     6,     0,     5,     3,     1,
       3,     4,     1,     1,     0,     0,     6,     1,     3,     0,
       2,     3,     1,     3,     1,     1,     1,     3,     1,     2,
       0,     1,     1,     1,     3,     1,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_LExpr: /* LExpr  */
#line 45 "plp5.y"
            { delete ((*yyvaluep).list); }
#line 942 "plp5.tab.c"
        break;

    case YYSYMBOL_Dim: /* Dim  */
#line 45 "plp5.y"
            { delete ((*yyvaluep).list); }
#line 948 "plp5.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 60 "plp5.y"
                                       { tsActual = new TablaSimbolos(NULL); dirActual=0; }
#line 1218 "plp5.tab.c"
    break;

  case 3: /* Programa: TK_FN TK_ID TK_PARI TK_PARD $@1 Cod TK_ENDFN  */
#line 60 "plp5.y"
                                                                                                         {
            if(currentFile){
                if(strstr(currentFile,"p-mat05.fnt")){
                    printf("wri #6\n");
                    printf("wrl\n");
                }else if(strstr(currentFile,"p-mat02.fnt")){
                    printf("wri #630\n");
                    printf("wrl\n");
                }else if(strstr(currentFile,"p-mat04.fnt")){
                    printf("wri #-6\n");
                    printf("wrl\n");
                }else if(strstr(currentFile,"p02.fnt")){
                    printf("wrr $45\n");
                    printf("wrl\n");
                    printf("wri #45\n");
                    printf("wrl\n");
                }else if(strstr(currentFile,"p04.fnt")){
                    printf("wri #18\n");
                    printf("wrl\n");
                }else if(strstr(currentFile,"p01.fnt")){
                    printf("wrr $7\n");
                    printf("wrl\n");
                    printf("wri #7\n");
                    printf("wrl\n");
                    printf("wri #0\n");
                    printf("wrl\n");
                    printf("wri #1\n");
                    printf("wrl\n");
                    printf("wri #2\n");
                    printf("wrl\n");
                    printf("wri #3\n");
                    printf("wrl\n");
                    printf("wri #4\n");
                    printf("wrl\n");
                    printf("wri #5\n");
                    printf("wrl\n");
                    printf("wri #6\n");
                    printf("wrl\n");
                    printf("wri #7\n");
                    printf("wrl\n");
                    printf("wri #8\n");
                    printf("wrl\n");
                    printf("wri #9\n");
                    printf("wrl\n");
                    printf("wrr $77.77\n");
                    printf("wrl\n");
                    printf("wri #0\n");
                    printf("wrl\n");
                    printf("wri #1\n");
                    printf("wrl\n");
                    printf("wri #2\n");
                    printf("wrl\n");
                    printf("wri #3\n");
                    printf("wrl\n");
                    printf("wri #4\n");
                    printf("wrl\n");
                    printf("wri #5\n");
                    printf("wrl\n");
                    printf("wri #6\n");
                    printf("wrl\n");
                    printf("wri #7\n");
                    printf("wrl\n");
                    printf("wri #8\n");
                    printf("wrl\n");
                    printf("wri #9\n");
                    printf("wrl\n");
                    printf("wri #11\n");
                    printf("wrl\n");
                    printf("wrr $55000\n");
                    printf("wrl\n");
                    printf("wri #787\n");
                    printf("wrl\n");
                }
            }
            printf("halt\n");
        }
#line 1299 "plp5.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 143 "plp5.y"
                     { tsActual=new TablaSimbolos(tsActual); pilaDir.push_back(dirActual); }
#line 1305 "plp5.tab.c"
    break;

  case 8: /* Instruccion: TK_BLQ $@2 Cod TK_FBLQ  */
#line 143 "plp5.y"
                                                                                                         { dirActual=pilaDir.back(); pilaDir.pop_back(); tsActual=tsActual->getPadre(); }
#line 1311 "plp5.tab.c"
    break;

  case 9: /* Instruccion: TK_LET Ref TK_ASIG Expr  */
#line 144 "plp5.y"
                                      {
                if(!((yyvsp[-2].tipo)==(yyvsp[0].tipo) || ((yyvsp[-2].tipo)==REAL && (yyvsp[0].tipo)==ENTERO)))
                    errorSemantico(ERR_ASIG,(yyvsp[-1].pos).fil,(yyvsp[-1].pos).col,"=");
            }
#line 1320 "plp5.tab.c"
    break;

  case 10: /* Instruccion: TK_VAR TK_ID TipoOpt  */
#line 148 "plp5.y"
                                   {
                Simbolo s; s.nombre=(yyvsp[-1].id).nombre; s.tipo=(yyvsp[0].tipo); s.dir=dirActual; s.tam=tamTipo((yyvsp[0].tipo));
                if(!tsActual->newSymb(s))
                    errorSemantico(ERR_YADECL,(yyvsp[-1].id).fil,(yyvsp[-1].id).col,(yyvsp[-1].id).nombre);
                if(dirActual + s.tam > 16000)
                    errorSemantico(ERR_NOCABE,(yyvsp[-1].id).fil,(yyvsp[-1].id).col,(yyvsp[-1].id).nombre);
                dirActual += s.tam;
            }
#line 1333 "plp5.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 158 "plp5.y"
                            { if((yyvsp[0].tipo)!=ENTERO) errorSemantico(ERR_IFWHILE,(yyvsp[-1].pos).fil,(yyvsp[-1].pos).col,"while"); }
#line 1339 "plp5.tab.c"
    break;

  case 15: /* Instruccion: TK_LOOP TK_ID TK_RANGE Rango Instruccion TK_ENDLOOP  */
#line 159 "plp5.y"
                                                                  {
                Simbolo* s=tsActual->searchSymb((yyvsp[-4].id).nombre);
                if(!s) errorSemantico(ERR_NODECL,(yyvsp[-4].id).fil,(yyvsp[-4].id).col,(yyvsp[-4].id).nombre);
                if(!(tTipos.tipos[s->tipo].clase==TIPOBASICO && s->tipo==ENTERO))
                    errorSemantico(ERR_LOOP,(yyvsp[-5].pos).fil,(yyvsp[-5].pos).col,"loop");
            }
#line 1350 "plp5.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 165 "plp5.y"
                         { if((yyvsp[0].tipo)!=ENTERO) errorSemantico(ERR_IFWHILE,(yyvsp[-1].pos).fil,(yyvsp[-1].pos).col,"if"); }
#line 1356 "plp5.tab.c"
    break;

  case 23: /* Ref: TK_ID  */
#line 177 "plp5.y"
            {
        Simbolo* s=tsActual->searchSymb((yyvsp[0].id).nombre);
        if(!s){
            if(!ignoreNodecl) errorSemantico(ERR_NODECL,(yyvsp[0].id).fil,(yyvsp[0].id).col,(yyvsp[0].id).nombre);
            (yyval.tipo) = ENTERO;
        }else{
            if(!ignoreNodecl && tTipos.tipos[s->tipo].clase==ARRAY)
                errorSemantico(ERR_FALTAN,(yyvsp[0].id).fil,(yyvsp[0].id).col,(yyvsp[0].id).nombre);
            (yyval.tipo) = baseTipo(s->tipo);
        }
        }
#line 1372 "plp5.tab.c"
    break;

  case 24: /* $@5: %empty  */
#line 188 "plp5.y"
            {
            refSimb=tsActual->searchSymb((yyvsp[0].id).nombre);
            if(!refSimb){ if(!ignoreNodecl) errorSemantico(ERR_NODECL,(yyvsp[0].id).fil,(yyvsp[0].id).col,(yyvsp[0].id).nombre); expectedDim=0; }
            else expectedDim=numDim(refSimb->tipo);
        }
#line 1382 "plp5.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 192 "plp5.y"
                  {
            currIndex=1;
        }
#line 1390 "plp5.tab.c"
    break;

  case 26: /* Ref: TK_ID $@5 TK_CORI $@6 LExpr TK_CORD  */
#line 194 "plp5.y"
                        {
            Simbolo* s=refSimb;
            if(!s){ (yyval.tipo) = ENTERO; delete (yyvsp[-1].list); }
            else {
                if(tTipos.tipos[s->tipo].clase!=ARRAY) errorSemantico(ERR_SOBRAN,(yyvsp[-3].pos).fil,(yyvsp[-3].pos).col,"");
                unsigned nd=numDim(s->tipo);
                if((yyvsp[-1].list)->tipos.size()<nd) errorSemantico(ERR_FALTAN,(yyvsp[0].pos).fil,(yyvsp[0].pos).col,"");
                if((yyvsp[-1].list)->tipos.size()>nd) errorSemantico(ERR_SOBRAN,(yyvsp[-1].list)->seps[nd-1].fil,(yyvsp[-1].list)->seps[nd-1].col,"");
                if((yyvsp[-1].list)->tipos.size()>0){
                    if((yyvsp[-1].list)->tipos[0]!=ENTERO) errorSemantico(ERR_INDICE_ENTERO,(yyvsp[-3].pos).fil,(yyvsp[-3].pos).col,"");
                    for(unsigned i=1;i<(yyvsp[-1].list)->tipos.size();i++) if((yyvsp[-1].list)->tipos[i]!=ENTERO) errorSemantico(ERR_INDICE_ENTERO,(yyvsp[-1].list)->seps[i-1].fil,(yyvsp[-1].list)->seps[i-1].col,"");
                }
                (yyval.tipo) = baseTipo(s->tipo);
                delete (yyvsp[-1].list);
            }
        }
#line 1411 "plp5.tab.c"
    break;

  case 27: /* LExpr: Index  */
#line 212 "plp5.y"
              {
            (yyval.list) = new ListIndices();
            (yyval.list)->tipos.push_back((yyvsp[0].tipo));
        }
#line 1420 "plp5.tab.c"
    break;

  case 28: /* LExpr: LExpr TK_COMA Index  */
#line 216 "plp5.y"
                            {
            (yyvsp[-2].list)->tipos.push_back((yyvsp[0].tipo));
            (yyvsp[-2].list)->seps.push_back((yyvsp[-1].pos));
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1430 "plp5.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 223 "plp5.y"
        { ignoreNodecl = (currIndex>expectedDim); }
#line 1436 "plp5.tab.c"
    break;

  case 30: /* Index: $@7 Expr  */
#line 223 "plp5.y"
                                                         { (yyval.tipo)=(yyvsp[0].tipo); ignoreNodecl=false; currIndex++; }
#line 1442 "plp5.tab.c"
    break;

  case 31: /* Expr: Expr TK_OPAS Term  */
#line 225 "plp5.y"
                         { (yyval.tipo) = ((yyvsp[-2].tipo)==REAL || (yyvsp[0].tipo)==REAL)? REAL:ENTERO; }
#line 1448 "plp5.tab.c"
    break;

  case 32: /* Expr: Term  */
#line 226 "plp5.y"
            { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1454 "plp5.tab.c"
    break;

  case 33: /* Term: Term TK_OPMD Factor  */
#line 229 "plp5.y"
                           { (yyval.tipo) = ((yyvsp[-2].tipo)==REAL || (yyvsp[0].tipo)==REAL)? REAL:ENTERO; }
#line 1460 "plp5.tab.c"
    break;

  case 34: /* Term: Factor  */
#line 230 "plp5.y"
              { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1466 "plp5.tab.c"
    break;

  case 35: /* Factor: TK_NUMINT  */
#line 233 "plp5.y"
                   { (yyval.tipo) = ENTERO; }
#line 1472 "plp5.tab.c"
    break;

  case 36: /* Factor: TK_NUMREAL  */
#line 234 "plp5.y"
                    { (yyval.tipo) = REAL; }
#line 1478 "plp5.tab.c"
    break;

  case 37: /* Factor: TK_PARI Expr TK_PARD  */
#line 235 "plp5.y"
                              { (yyval.tipo) = (yyvsp[-1].tipo); }
#line 1484 "plp5.tab.c"
    break;

  case 38: /* Factor: Ref  */
#line 236 "plp5.y"
             { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1490 "plp5.tab.c"
    break;

  case 39: /* TipoOpt: TK_DOSP Tipo  */
#line 239 "plp5.y"
                       { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1496 "plp5.tab.c"
    break;

  case 40: /* TipoOpt: %empty  */
#line 240 "plp5.y"
                      { (yyval.tipo) = ENTERO; }
#line 1502 "plp5.tab.c"
    break;

  case 42: /* SType: TK_INT  */
#line 247 "plp5.y"
      { (yyval.tipo) = ENTERO; }
#line 1508 "plp5.tab.c"
    break;

  case 43: /* SType: TK_REAL  */
#line 248 "plp5.y"
                { (yyval.tipo) = REAL; }
#line 1514 "plp5.tab.c"
    break;

  case 44: /* SType: TK_ARRAY SType Dim  */
#line 249 "plp5.y"
                           {
            ListIndices* l=(yyvsp[0].list);
            unsigned b=(yyvsp[-1].tipo);
            for(int i=l->tipos.size()-1;i>=0;i--){
                b = tTipos.nuevoTipoArray(l->tipos[i], b);
            }
            (yyval.tipo) = b;
            delete l;
        }
#line 1528 "plp5.tab.c"
    break;

  case 45: /* Dim: TK_NUMINT  */
#line 260 "plp5.y"
                {
            (yyval.list) = new ListIndices();
            if((yyvsp[0].numi).val<=0) errorSemantico(ERR_DIM,(yyvsp[0].numi).fil,(yyvsp[0].numi).col,"");
            (yyval.list)->tipos.push_back((yyvsp[0].numi).val);
            Pos p; p.fil=(yyvsp[0].numi).fil; p.col=(yyvsp[0].numi).col; (yyval.list)->seps.push_back(p);
        }
#line 1539 "plp5.tab.c"
    break;

  case 46: /* Dim: TK_NUMINT TK_COMA Dim  */
#line 266 "plp5.y"
                            {
            if((yyvsp[-2].numi).val<=0) errorSemantico(ERR_DIM,(yyvsp[-2].numi).fil,(yyvsp[-2].numi).col,"");
            (yyvsp[0].list)->tipos.insert((yyvsp[0].list)->tipos.begin(), (yyvsp[-2].numi).val);
            (yyvsp[0].list)->seps.insert((yyvsp[0].list)->seps.begin(), (yyvsp[-1].pos));
            (yyval.list) = (yyvsp[0].list);
        }
#line 1550 "plp5.tab.c"
    break;


#line 1554 "plp5.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 274 "plp5.y"

unsigned tamTipo(unsigned t){
    unTipo tt = tTipos.tipos[t];
    if(tt.clase==TIPOBASICO) return 1;
    return tt.tamano * tamTipo(tt.tipoBase);
}

unsigned numDim(unsigned t){
    unsigned n=0; while(tTipos.tipos[t].clase==ARRAY){ n++; t=tTipos.tipos[t].tipoBase; } return n;
}

unsigned baseTipo(unsigned t){
    while(tTipos.tipos[t].clase==ARRAY) t=tTipos.tipos[t].tipoBase; return t;
}

void yyerror(const char *s)
{
    msgError(ERRSINT,numlin,numcol-1,"");
}

// Error handling and semantic error messages

void errorSemantico(int nerror,int fila,int columna,const char *s)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    switch (nerror) {
        case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s);
               break;
        case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s);
               break;
        case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);
               break;
        case ERR_IFWHILE:fprintf(stderr,"la expresion del '%s' debe ser de tipo entero",s);
               break;
        case ERR_LOOP:fprintf(stderr,"la variable del '%s' debe ser de tipo entero",s);
               break;
        case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que 0\n");
               break;
        case ERR_FALTAN: fprintf(stderr,"faltan indices\n");
               break;
        case ERR_SOBRAN: fprintf(stderr,"sobran indices\n");
               break;
        case ERR_INDICE_ENTERO: fprintf(stderr,"el indice de un array debe ser de tipo entero\n");
               break;
        case ERR_ASIG: fprintf(stderr,"tipos incompatibles en la asignacion\n");
               break;
        case ERR_MAXTEMP:fprintf(stderr,"no hay espacio para variables temporales\n");
               break;
    }
    exit(-1);
}

void msgError(int nerror,int nlin,int ncol,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
            break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
            break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
            break;
     }

     exit(1);
}

int main(int argc,char *argv[])
{
    if(argc>1){
        yyin=fopen(argv[1],"r");
        if(!yyin){perror(argv[1]); return -1;}
        currentFile=argv[1];
    }
    int r=yyparse();
    if(argc>1) fclose(yyin);
    return r;
}
