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
#line 1 "parser.y"

#include <stdlib.h>
#include "ast.h"
int yyerror();
int yylex();
int getLineNumber();

AST* raiz;
	


#line 83 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_IF = 261,                   /* KW_IF  */
    KW_ELSE = 262,                 /* KW_ELSE  */
    KW_WHILE = 263,                /* KW_WHILE  */
    KW_READ = 264,                 /* KW_READ  */
    KW_PRINT = 265,                /* KW_PRINT  */
    KW_RETURN = 266,               /* KW_RETURN  */
    ASSIGNMENT = 267,              /* ASSIGNMENT  */
    OPERATOR_LE = 268,             /* OPERATOR_LE  */
    OPERATOR_GE = 269,             /* OPERATOR_GE  */
    OPERATOR_EQ = 270,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 271,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 272,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 273,             /* LIT_INTEGER  */
    LIT_FLOAT = 274,               /* LIT_FLOAT  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    TOKEN_ERROR = 277              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_ELSE 262
#define KW_WHILE 263
#define KW_READ 264
#define KW_PRINT 265
#define KW_RETURN 266
#define ASSIGNMENT 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INTEGER 273
#define LIT_FLOAT 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    HASH_NODE *symbol;
    AST* AST;


#line 186 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_IF = 6,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 7,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 8,                   /* KW_WHILE  */
  YYSYMBOL_KW_READ = 9,                    /* KW_READ  */
  YYSYMBOL_KW_PRINT = 10,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 11,                 /* KW_RETURN  */
  YYSYMBOL_ASSIGNMENT = 12,                /* ASSIGNMENT  */
  YYSYMBOL_OPERATOR_LE = 13,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 14,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 15,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 16,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 17,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INTEGER = 18,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_FLOAT = 19,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 22,               /* TOKEN_ERROR  */
  YYSYMBOL_23_ = 23,                       /* '&'  */
  YYSYMBOL_24_ = 24,                       /* '|'  */
  YYSYMBOL_25_ = 25,                       /* '~'  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '.'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_list = 41,                      /* list  */
  YYSYMBOL_dec = 42,                       /* dec  */
  YYSYMBOL_func = 43,                      /* func  */
  YYSYMBOL_type = 44,                      /* type  */
  YYSYMBOL_array = 45,                     /* array  */
  YYSYMBOL_init = 46,                      /* init  */
  YYSYMBOL_literal = 47,                   /* literal  */
  YYSYMBOL_body = 48,                      /* body  */
  YYSYMBOL_cmdl = 49,                      /* cmdl  */
  YYSYMBOL_cmd = 50,                       /* cmd  */
  YYSYMBOL_fassign = 51,                   /* fassign  */
  YYSYMBOL_args = 52,                      /* args  */
  YYSYMBOL_flux = 53,                      /* flux  */
  YYSYMBOL_read = 54,                      /* read  */
  YYSYMBOL_printl = 55,                    /* printl  */
  YYSYMBOL_print = 56,                     /* print  */
  YYSYMBOL_param = 57,                     /* param  */
  YYSYMBOL_expr = 58                       /* expr  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
      33,    34,     2,    28,     2,    29,    30,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      26,     2,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    24,    38,    25,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    80,    81,    82,    85,    86,    89,    92,
      93,    94,    97,   100,   101,   104,   105,   106,   109,   110,
     113,   114,   115,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   130,   133,   134,   137,   138,   139,   142,   143,
     147,   148,   152,   153,   157,   158,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_READ", "KW_PRINT",
  "KW_RETURN", "ASSIGNMENT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INTEGER", "LIT_FLOAT", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'&'", "'|'", "'~'", "'<'", "'>'", "'+'",
  "'-'", "'.'", "'/'", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "$accept", "program", "list", "dec", "func", "type", "array", "init",
  "literal", "body", "cmdl", "cmd", "fassign", "args", "flux", "read",
  "printl", "print", "param", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,   -60,   -60,   -60,    19,   -60,   -12,    87,     7,   -60,
      87,   -60,    23,   -60,    50,     9,   -60,   -60,   -60,   -60,
      14,    -2,    13,    16,    87,   -60,    22,   110,   -60,    56,
     -60,   -60,   110,    30,    42,    61,    -8,   239,    -9,    56,
     -15,   -60,   -60,   239,   239,    44,   -60,    47,   -60,   -60,
     -60,   -60,   239,   -60,    -8,   215,   215,   243,   239,    45,
      95,    56,   -60,   128,   150,   239,   239,   172,   -60,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,    41,   -60,   215,    71,   -60,    40,    74,    56,
      56,    90,   109,   -60,    80,    80,   240,   240,   221,   221,
     221,    80,    80,   -25,   -25,   -60,   -60,   239,    76,   -60,
     -60,   124,   -60,   -60,   -60,   112,   194,   239,    56,   -60,
     -60,   215,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    11,     9,    10,     0,     2,     0,     5,     0,     1,
       5,     4,     0,     3,    45,     0,     7,    15,    16,    17,
       0,     0,     0,     0,    45,     6,     0,    14,    44,    31,
       8,    12,    14,     0,     0,     0,    41,     0,     0,    31,
       0,    30,    13,     0,     0,    39,    27,    50,    46,    47,
      48,    42,     0,    28,    41,    43,    29,     0,     0,     0,
      20,    31,    18,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    24,    25,     0,    23,    22,     0,    31,
      31,     0,     0,    64,    57,    58,    59,    60,    61,    62,
      63,    55,    56,    51,    52,    53,    54,    34,     0,    21,
      19,    35,    37,    38,    49,     0,    34,     0,    31,    32,
      33,    26,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,     8,   -60,   -60,   -10,   -60,   115,   134,   -60,
     -59,   -29,   -60,    33,   -60,   -60,    96,   -60,   136,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    16,    31,    32,    30,
      59,    60,    83,   115,    41,    46,    53,    54,    22,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,    56,    88,    57,    20,    80,    81,    63,    64,    47,
      48,    49,    50,    51,    20,    11,    67,    61,    13,     9,
      10,    84,    85,    62,    12,    52,    58,    23,   109,    91,
      92,    24,    25,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    33,    26,    34,    35,
      36,    37,    27,     1,     2,     3,    14,    38,    15,    29,
     111,   112,    33,    43,    34,    35,    36,    37,    17,    18,
      19,   116,   -31,    38,   107,    44,    66,    39,    45,    65,
     116,   121,    66,    86,    69,    70,    71,    72,   117,   122,
       1,     2,     3,    39,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    69,    70,    71,    72,   108,    78,    79,
      80,    81,   110,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    69,    70,    71,    72,   113,    87,    17,    18,
      19,   118,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    69,    70,    71,    72,   114,   119,    42,    21,   120,
      68,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      28,     0,    89,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    90,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    93,    69,    70,    71,
      72,    47,    48,    49,    50,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,    52,    69,    70,
      71,    72,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    76,    77,    78,
      79,    80,    81,    69,    70,     0,    47,    48,    49,    50,
      82,    48,    49,    50,     0,     0,    76,    77,    78,    79,
      80,    81,    52,     0,     0,     0,    52
};

static const yytype_int8 yycheck[] =
{
      29,    37,    61,    12,    14,    30,    31,    43,    44,    17,
      18,    19,    20,    21,    24,     7,    52,    32,    10,     0,
      32,    57,    58,    38,    17,    33,    35,    18,    87,    65,
      66,    17,    34,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     6,    34,     8,     9,
      10,    11,    36,     3,     4,     5,    33,    17,    35,    37,
      89,    90,     6,    33,     8,     9,    10,    11,    18,    19,
      20,   107,    32,    17,    33,    33,    35,    37,    17,    35,
     116,   117,    35,    38,    13,    14,    15,    16,    12,   118,
       3,     4,     5,    37,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    13,    14,    15,    16,    36,    28,    29,
      30,    31,    38,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    13,    14,    15,    16,    36,    32,    18,    19,
      20,     7,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    13,    14,    15,    16,    36,    34,    32,    14,   116,
      54,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      24,    -1,    34,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    13,    14,
      15,    16,    -1,    -1,    13,    14,    15,    16,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    26,    27,    28,
      29,    30,    31,    13,    14,    -1,    17,    18,    19,    20,
      17,    18,    19,    20,    -1,    -1,    26,    27,    28,    29,
      30,    31,    33,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    40,    41,    42,    43,    44,     0,
      32,    41,    17,    41,    33,    35,    45,    18,    19,    20,
      44,    47,    57,    18,    17,    34,    34,    36,    57,    37,
      48,    46,    47,     6,     8,     9,    10,    11,    17,    37,
      50,    53,    46,    33,    33,    17,    54,    17,    18,    19,
      20,    21,    33,    55,    56,    58,    58,    12,    35,    49,
      50,    32,    38,    58,    58,    35,    35,    58,    55,    13,
      14,    15,    16,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    17,    51,    58,    58,    38,    32,    49,    34,
      34,    58,    58,    34,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    33,    36,    49,
      38,    50,    50,    36,    36,    52,    58,    12,     7,    34,
      52,    58,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    42,    43,    44,
      44,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     5,     3,     6,     1,
       1,     1,     4,     2,     0,     1,     1,     1,     3,     5,
       1,     3,     2,     3,     3,     3,     6,     2,     2,     2,
       1,     0,     4,     2,     0,     5,     7,     5,     4,     1,
       2,     0,     1,     1,     3,     0,     1,     1,     1,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
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
  YY_USE (yykind);
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
  case 2: /* program: list  */
#line 77 "parser.y"
                                                                                        { raiz = (yyvsp[0].AST);}
#line 1328 "y.tab.c"
    break;

  case 3: /* list: dec ';' list  */
#line 80 "parser.y"
                                                                                        { (yyval.AST) = astCreate(AST_LIST, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1334 "y.tab.c"
    break;

  case 4: /* list: func list  */
#line 81 "parser.y"
                                                                                        { (yyval.AST) = astCreate(AST_LIST, 0, (yyvsp[-1].AST), (yyvsp[0].AST), 0, 0);}
#line 1340 "y.tab.c"
    break;

  case 5: /* list: %empty  */
#line 82 "parser.y"
                                                                                                { (yyval.AST) = 0; }
#line 1346 "y.tab.c"
    break;

  case 6: /* dec: type TK_IDENTIFIER '(' literal ')'  */
#line 85 "parser.y"
                                                                        { (yyval.AST) = astCreate(AST_DECP, (yyvsp[-3].symbol), (yyvsp[-4].AST), (yyvsp[-1].AST), 0, 0);}
#line 1352 "y.tab.c"
    break;

  case 7: /* dec: type TK_IDENTIFIER array  */
#line 86 "parser.y"
                                                                                { (yyval.AST) = astCreate(AST_DEC, (yyvsp[-1].symbol), (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1358 "y.tab.c"
    break;

  case 8: /* func: type TK_IDENTIFIER '(' param ')' body  */
#line 89 "parser.y"
                                                                { (yyval.AST) = astCreate(AST_FUNC, (yyvsp[-4].symbol), (yyvsp[-5].AST), (yyvsp[-2].AST), (yyvsp[0].AST), 0);}
#line 1364 "y.tab.c"
    break;

  case 9: /* type: KW_INT  */
#line 92 "parser.y"
                                        { (yyval.AST) = astCreate(AST_INT, 0, 0, 0, 0, 0);}
#line 1370 "y.tab.c"
    break;

  case 10: /* type: KW_FLOAT  */
#line 93 "parser.y"
                                { (yyval.AST) = astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
#line 1376 "y.tab.c"
    break;

  case 11: /* type: KW_CHAR  */
#line 94 "parser.y"
                                        { (yyval.AST) = astCreate(AST_CHAR, 0, 0, 0, 0, 0);}
#line 1382 "y.tab.c"
    break;

  case 12: /* array: '[' LIT_INTEGER ']' init  */
#line 97 "parser.y"
                                        { (yyval.AST) = astCreate(AST_INIT,(yyvsp[-2].symbol),(yyvsp[0].AST),0,0,0);}
#line 1388 "y.tab.c"
    break;

  case 13: /* init: literal init  */
#line 100 "parser.y"
                                                { (yyval.AST) = astCreate(AST_INIT,0,(yyvsp[-1].AST),(yyvsp[0].AST),0,0); }
#line 1394 "y.tab.c"
    break;

  case 14: /* init: %empty  */
#line 101 "parser.y"
                                                        { (yyval.AST) = 0; }
#line 1400 "y.tab.c"
    break;

  case 15: /* literal: LIT_INTEGER  */
#line 104 "parser.y"
                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1406 "y.tab.c"
    break;

  case 16: /* literal: LIT_FLOAT  */
#line 105 "parser.y"
                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1412 "y.tab.c"
    break;

  case 17: /* literal: LIT_CHAR  */
#line 106 "parser.y"
                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1418 "y.tab.c"
    break;

  case 18: /* body: '{' cmd '}'  */
#line 109 "parser.y"
                                        { (yyval.AST) = astCreate(AST_CMD, 0, (yyvsp[-1].AST), 0, 0, 0);}
#line 1424 "y.tab.c"
    break;

  case 19: /* body: '{' cmd ';' cmdl '}'  */
#line 110 "parser.y"
                                { (yyval.AST) = astCreate(AST_LCMD, 0, (yyvsp[-3].AST), (yyvsp[-1].AST), 0, 0);}
#line 1430 "y.tab.c"
    break;

  case 20: /* cmdl: cmd  */
#line 113 "parser.y"
                                        { (yyval.AST) = astCreate(AST_CMD, 0, (yyvsp[0].AST), 0, 0, 0);}
#line 1436 "y.tab.c"
    break;

  case 21: /* cmdl: cmd ';' cmdl  */
#line 114 "parser.y"
                                                { (yyval.AST) = astCreate(AST_LCMD, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1442 "y.tab.c"
    break;

  case 22: /* cmdl: cmd ';'  */
#line 115 "parser.y"
                                                { (yyval.AST) = astCreate(AST_CMD, 0, (yyvsp[-1].AST), 0, 0, 0);}
#line 1448 "y.tab.c"
    break;

  case 23: /* cmd: '{' cmdl '}'  */
#line 119 "parser.y"
                                                                                        { (yyval.AST) = astCreate(AST_CMD, 0, (yyvsp[-1].AST), 0, 0, 0); }
#line 1454 "y.tab.c"
    break;

  case 24: /* cmd: TK_IDENTIFIER ASSIGNMENT fassign  */
#line 120 "parser.y"
                                                                { (yyval.AST) = astCreate(AST_ASSIGN, (yyvsp[-2].symbol), (yyvsp[0].AST), 0, 0, 0);}
#line 1460 "y.tab.c"
    break;

  case 25: /* cmd: TK_IDENTIFIER ASSIGNMENT expr  */
#line 121 "parser.y"
                                                                { (yyval.AST) = astCreate(AST_ASSIGN, (yyvsp[-2].symbol), (yyvsp[0].AST), 0, 0, 0);}
#line 1466 "y.tab.c"
    break;

  case 26: /* cmd: TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr  */
#line 122 "parser.y"
                                                                { (yyval.AST) = astCreate(AST_ASSIGN, (yyvsp[-5].symbol), (yyvsp[-3].AST), (yyvsp[0].AST), 0, 0);}
#line 1472 "y.tab.c"
    break;

  case 27: /* cmd: KW_READ read  */
#line 123 "parser.y"
                                                                                        { (yyval.AST) = astCreate(AST_READ,0, (yyvsp[0].AST), 0, 0, 0); }
#line 1478 "y.tab.c"
    break;

  case 28: /* cmd: KW_PRINT printl  */
#line 124 "parser.y"
                                                                                { (yyval.AST) = astCreate(AST_PRINT,0, (yyvsp[0].AST), 0, 0, 0);}
#line 1484 "y.tab.c"
    break;

  case 29: /* cmd: KW_RETURN expr  */
#line 125 "parser.y"
                                                                                { (yyval.AST) = astCreate(AST_RETURN,0, (yyvsp[0].AST), 0, 0, 0);}
#line 1490 "y.tab.c"
    break;

  case 30: /* cmd: flux  */
#line 126 "parser.y"
                                                                                { (yyval.AST) = (yyvsp[0].AST); }
#line 1496 "y.tab.c"
    break;

  case 31: /* cmd: %empty  */
#line 127 "parser.y"
                                                                                { (yyval.AST) = 0; }
#line 1502 "y.tab.c"
    break;

  case 32: /* fassign: TK_IDENTIFIER '(' args ')'  */
#line 130 "parser.y"
                                                { (yyval.AST) = astCreate(AST_FASSIGN, (yyvsp[-3].symbol), (yyvsp[-1].AST), 0, 0, 0);}
#line 1508 "y.tab.c"
    break;

  case 33: /* args: expr args  */
#line 133 "parser.y"
                                                        { (yyval.AST) = astCreate(AST_ARGS,0, (yyvsp[-1].AST), (yyvsp[0].AST), 0, 0);}
#line 1514 "y.tab.c"
    break;

  case 34: /* args: %empty  */
#line 134 "parser.y"
                                                                { (yyval.AST) = 0;}
#line 1520 "y.tab.c"
    break;

  case 35: /* flux: KW_IF '(' expr ')' cmd  */
#line 137 "parser.y"
                                                        {(yyval.AST) = astCreate(AST_IF, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1526 "y.tab.c"
    break;

  case 36: /* flux: KW_IF '(' expr ')' cmd KW_ELSE cmd  */
#line 138 "parser.y"
                                                {(yyval.AST) = astCreate(AST_IFELSE, 0, (yyvsp[-4].AST), (yyvsp[-2].AST), (yyvsp[0].AST), 0);}
#line 1532 "y.tab.c"
    break;

  case 37: /* flux: KW_WHILE '(' expr ')' cmd  */
#line 139 "parser.y"
                                                                {(yyval.AST) = astCreate(AST_WHILE, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1538 "y.tab.c"
    break;

  case 38: /* read: TK_IDENTIFIER '[' expr ']'  */
#line 142 "parser.y"
                                                { (yyval.AST) = astCreate(AST_IDENT, (yyvsp[-3].symbol), (yyvsp[-1].AST), 0, 0, 0);}
#line 1544 "y.tab.c"
    break;

  case 39: /* read: TK_IDENTIFIER  */
#line 143 "parser.y"
                                                                { (yyval.AST) = astCreate(AST_IDENT, (yyvsp[0].symbol), 0, 0, 0, 0);}
#line 1550 "y.tab.c"
    break;

  case 40: /* printl: print printl  */
#line 147 "parser.y"
                                        { (yyval.AST) = astCreate(AST_PRINTL, 0, (yyvsp[-1].AST), (yyvsp[0].AST), 0, 0); }
#line 1556 "y.tab.c"
    break;

  case 41: /* printl: %empty  */
#line 148 "parser.y"
                                                {(yyval.AST) = 0; }
#line 1562 "y.tab.c"
    break;

  case 42: /* print: LIT_STRING  */
#line 152 "parser.y"
                                                { (yyval.AST) = astCreate(AST_STR, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1568 "y.tab.c"
    break;

  case 43: /* print: expr  */
#line 153 "parser.y"
                                                { (yyval.AST) = (yyvsp[0].AST);}
#line 1574 "y.tab.c"
    break;

  case 44: /* param: type TK_IDENTIFIER param  */
#line 157 "parser.y"
                                        {(yyval.AST) = astCreate(AST_PARAM, (yyvsp[-1].symbol), (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0);}
#line 1580 "y.tab.c"
    break;

  case 45: /* param: %empty  */
#line 158 "parser.y"
                                                {(yyval.AST)=0;}
#line 1586 "y.tab.c"
    break;

  case 46: /* expr: LIT_INTEGER  */
#line 161 "parser.y"
                                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1592 "y.tab.c"
    break;

  case 47: /* expr: LIT_FLOAT  */
#line 162 "parser.y"
                                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1598 "y.tab.c"
    break;

  case 48: /* expr: LIT_CHAR  */
#line 163 "parser.y"
                                        { (yyval.AST) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1604 "y.tab.c"
    break;

  case 49: /* expr: TK_IDENTIFIER '[' expr ']'  */
#line 164 "parser.y"
                                  { (yyval.AST) = astCreate(AST_IDENT, (yyvsp[-3].symbol), (yyvsp[-1].AST), 0, 0, 0); }
#line 1610 "y.tab.c"
    break;

  case 50: /* expr: TK_IDENTIFIER  */
#line 165 "parser.y"
                                  { (yyval.AST) = astCreate(AST_IDENT, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1616 "y.tab.c"
    break;

  case 51: /* expr: expr '+' expr  */
#line 166 "parser.y"
                                  { (yyval.AST) = astCreate(AST_ADD, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1622 "y.tab.c"
    break;

  case 52: /* expr: expr '-' expr  */
#line 167 "parser.y"
                                  { (yyval.AST) = astCreate(AST_SUB, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1628 "y.tab.c"
    break;

  case 53: /* expr: expr '.' expr  */
#line 168 "parser.y"
                                  { (yyval.AST) = astCreate(AST_MULT, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1634 "y.tab.c"
    break;

  case 54: /* expr: expr '/' expr  */
#line 169 "parser.y"
                                  { (yyval.AST) = astCreate(AST_DIV, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1640 "y.tab.c"
    break;

  case 55: /* expr: expr '<' expr  */
#line 170 "parser.y"
                                  { (yyval.AST) = astCreate(AST_LESS, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1646 "y.tab.c"
    break;

  case 56: /* expr: expr '>' expr  */
#line 171 "parser.y"
                                  { (yyval.AST) = astCreate(AST_BIG, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1652 "y.tab.c"
    break;

  case 57: /* expr: expr OPERATOR_LE expr  */
#line 172 "parser.y"
                                        { (yyval.AST) = astCreate(AST_OPLE, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1658 "y.tab.c"
    break;

  case 58: /* expr: expr OPERATOR_GE expr  */
#line 173 "parser.y"
                                        { (yyval.AST) = astCreate(AST_OPGE, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1664 "y.tab.c"
    break;

  case 59: /* expr: expr OPERATOR_EQ expr  */
#line 174 "parser.y"
                                        { (yyval.AST) = astCreate(AST_OPEQ, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1670 "y.tab.c"
    break;

  case 60: /* expr: expr OPERATOR_DIF expr  */
#line 175 "parser.y"
                                        { (yyval.AST) = astCreate(AST_OPDIF, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1676 "y.tab.c"
    break;

  case 61: /* expr: expr '&' expr  */
#line 176 "parser.y"
                                                { (yyval.AST) = astCreate(AST_AND, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1682 "y.tab.c"
    break;

  case 62: /* expr: expr '|' expr  */
#line 177 "parser.y"
                                                { (yyval.AST) = astCreate(AST_OR, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1688 "y.tab.c"
    break;

  case 63: /* expr: expr '~' expr  */
#line 178 "parser.y"
                                                { (yyval.AST) = astCreate(AST_NOT, 0, (yyvsp[-2].AST), (yyvsp[0].AST), 0, 0); }
#line 1694 "y.tab.c"
    break;

  case 64: /* expr: '(' expr ')'  */
#line 179 "parser.y"
                                        { (yyval.AST) = (yyvsp[-1].AST); }
#line 1700 "y.tab.c"
    break;


#line 1704 "y.tab.c"

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

#line 183 "parser.y"


AST* return_node(){
	return raiz;
}
 
int yyerror(){
    fprintf(stderr, " \n Syntax error at line %d.\n", getLineNumber());
    exit(3);
}
