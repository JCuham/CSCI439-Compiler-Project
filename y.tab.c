/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"


  /*
    SOURCES:
https://medium.com/codex/building-a-c-compiler-using-lex-and-yacc-446262056aaa
*/
  
  //initial setup
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include "lex.yy.c"
  int yylex();
  int yywrap();

  /*SYNTAX TREE FUNCTIONS*/
  void printSynTree(struct node*n);
  void cleanup(struct node*n);
  /*CODE GENERATION FUNCTIONS*/
  void gencode(struct node*n);
  void gencodevars(struct node*n);
  void gencodestrings(struct node*n);
  void gencodeblock(struct node*n);
  void ifcodeblock(struct node*n);
  /*ERROR GENERATION FUNCTIONS*/
  void no_declaration(char *s);
  void keyword_var(char *s);
  int type_checker(char *s1, char *s2);
  char *get_current_type(char *s);
  /*ERROR CHECKING GLOBAL VARS*/
  int status;
  extern int lineno;
  char errarray[15][128];
  int errindex = 0;
  char keywords[11][10] = {"int","real","string","char","else","if","for","begin","end","start","done"};
  /*CODE GENERATION GLOBAL VARS*/
  char codeblock_array[128][128];
  int codeblockindex = 0;
  char codevar_array[40][40];
  int codevarindex = 0;
  char string_array[40][128];
  int stringindex = 0;
  int numdefinedstr = 0;
  int numdefinedvar = 0;
  int pstmtcounter = 0;
  int loopcounter = 0;
  int scanstmtcounter=0;
  int ifstmtcounter=0;
  int totalifstmt = 0;
  /*SYNTAX TREE NODE CREATION FUNCTION*/
  struct node* createNode(struct node *L, struct node *R, char *tok);
  /*SYNTAX TREE ROOT NODE GLOBAL*/
  struct node *root;
  /*SYNTAX TREE NODE STRUCTURE*/
  struct node {
    struct node *L;
    struct node *R;
    char *token;
  };


 

#line 136 "y.tab.c"

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
    EMPTY = 258,                   /* EMPTY  */
    INT = 259,                     /* INT  */
    CHAR = 260,                    /* CHAR  */
    STRING = 261,                  /* STRING  */
    BOOL = 262,                    /* BOOL  */
    REAL = 263,                    /* REAL  */
    BEGINPROG = 264,               /* BEGINPROG  */
    ENDPROG = 265,                 /* ENDPROG  */
    START = 266,                   /* START  */
    DONE = 267,                    /* DONE  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    FOR = 270,                     /* FOR  */
    PRINT = 271,                   /* PRINT  */
    SCAN = 272,                    /* SCAN  */
    BOOLTRUE = 273,                /* BOOLTRUE  */
    BOOLFALSE = 274,               /* BOOLFALSE  */
    ASGN = 275,                    /* ASGN  */
    LTEQ = 276,                    /* LTEQ  */
    GTEQ = 277,                    /* GTEQ  */
    EQ = 278,                      /* EQ  */
    NEQ = 279,                     /* NEQ  */
    GT = 280,                      /* GT  */
    LT = 281,                      /* LT  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    PLUS = 284,                    /* PLUS  */
    SUB = 285,                     /* SUB  */
    DIV = 286,                     /* DIV  */
    MULT = 287,                    /* MULT  */
    CHARLIT = 288,                 /* CHARLIT  */
    STRLIT = 289,                  /* STRLIT  */
    REALLIT = 290,                 /* REALLIT  */
    INTLIT = 291,                  /* INTLIT  */
    VARNAME = 292,                 /* VARNAME  */
    NEWLINE = 293                  /* NEWLINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define EMPTY 258
#define INT 259
#define CHAR 260
#define STRING 261
#define BOOL 262
#define REAL 263
#define BEGINPROG 264
#define ENDPROG 265
#define START 266
#define DONE 267
#define IF 268
#define ELSE 269
#define FOR 270
#define PRINT 271
#define SCAN 272
#define BOOLTRUE 273
#define BOOLFALSE 274
#define ASGN 275
#define LTEQ 276
#define GTEQ 277
#define EQ 278
#define NEQ 279
#define GT 280
#define LT 281
#define AND 282
#define OR 283
#define PLUS 284
#define SUB 285
#define DIV 286
#define MULT 287
#define CHARLIT 288
#define STRLIT 289
#define REALLIT 290
#define INTLIT 291
#define VARNAME 292
#define NEWLINE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "parser.yacc"

  struct variable {
    char varname[128];
    struct node *n;
  } node_object;

#line 272 "y.tab.c"

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
  YYSYMBOL_EMPTY = 3,                      /* EMPTY  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_BEGINPROG = 9,                  /* BEGINPROG  */
  YYSYMBOL_ENDPROG = 10,                   /* ENDPROG  */
  YYSYMBOL_START = 11,                     /* START  */
  YYSYMBOL_DONE = 12,                      /* DONE  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_SCAN = 17,                      /* SCAN  */
  YYSYMBOL_BOOLTRUE = 18,                  /* BOOLTRUE  */
  YYSYMBOL_BOOLFALSE = 19,                 /* BOOLFALSE  */
  YYSYMBOL_ASGN = 20,                      /* ASGN  */
  YYSYMBOL_LTEQ = 21,                      /* LTEQ  */
  YYSYMBOL_GTEQ = 22,                      /* GTEQ  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_SUB = 30,                       /* SUB  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_MULT = 32,                      /* MULT  */
  YYSYMBOL_CHARLIT = 33,                   /* CHARLIT  */
  YYSYMBOL_STRLIT = 34,                    /* STRLIT  */
  YYSYMBOL_REALLIT = 35,                   /* REALLIT  */
  YYSYMBOL_INTLIT = 36,                    /* INTLIT  */
  YYSYMBOL_VARNAME = 37,                   /* VARNAME  */
  YYSYMBOL_NEWLINE = 38,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_prog = 40,                      /* prog  */
  YYSYMBOL_codeblock = 41,                 /* codeblock  */
  YYSYMBOL_code = 42,                      /* code  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_elsestmt = 45,                  /* elsestmt  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_printstmt = 47,                 /* printstmt  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_scanstmt = 49,                  /* scanstmt  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_cond = 51,                      /* cond  */
  YYSYMBOL_value = 52,                     /* value  */
  YYSYMBOL_condop = 53,                    /* condop  */
  YYSYMBOL_declare = 54,                   /* declare  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_assign = 56,                    /* assign  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_condstmt = 58,                  /* condstmt  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_boolop = 61,                    /* boolop  */
  YYSYMBOL_mathop = 62                     /* mathop  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  98

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    90,    96,   102,   102,   111,   111,   120,
     121,   122,   123,   124,   127,   127,   131,   134,   134,   140,
     140,   147,   148,   149,   152,   153,   154,   155,   156,   159,
     160,   161,   162,   163,   164,   168,   168,   177,   177,   183,
     183,   188,   193,   200,   201,   202,   203,   204,   205,   208,
     209,   212,   213,   214,   215
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
  "\"end of file\"", "error", "\"invalid token\"", "EMPTY", "INT", "CHAR",
  "STRING", "BOOL", "REAL", "BEGINPROG", "ENDPROG", "START", "DONE", "IF",
  "ELSE", "FOR", "PRINT", "SCAN", "BOOLTRUE", "BOOLFALSE", "ASGN", "LTEQ",
  "GTEQ", "EQ", "NEQ", "GT", "LT", "AND", "OR", "PLUS", "SUB", "DIV",
  "MULT", "CHARLIT", "STRLIT", "REALLIT", "INTLIT", "VARNAME", "NEWLINE",
  "$accept", "prog", "codeblock", "code", "$@1", "$@2", "elsestmt", "$@3",
  "printstmt", "$@4", "scanstmt", "$@5", "cond", "value", "condop",
  "declare", "$@6", "assign", "$@7", "condstmt", "$@8", "type", "boolop",
  "mathop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,    10,    12,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,     9,    10,   -24,   -24,   -24,
     -24,   -17,   -24,    37,    46,    51,    51,     4,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -10,   -15,
       5,    37,    -8,     3,    51,    51,    22,    19,   -24,   -24,
     -24,   -24,   -24,   -24,    51,   -24,   -24,   -24,   -24,   -24,
     -24,    51,    51,    46,   -24,   -24,     6,     8,    51,    20,
     -24,   -24,   -24,    21,    40,   -24,   -24,    23,    10,    52,
      51,   -24,    53,    10,   -24,    26,    54,    55,   -24,   -24,
     -24,    30,    64,    38,    10,    65,    56,   -24
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    48,    43,    44,    45,    46,    47,     7,
       5,    17,    19,    37,    13,     0,     3,    10,    11,     9,
      12,     0,     1,     0,     0,     0,     0,     0,     2,     4,
      35,    21,    22,    26,    27,    24,    25,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,     0,    49,    50,    51,    52,    53,
      54,     0,     0,     0,    39,    18,     0,     0,     0,     0,
      23,    41,    42,     0,     0,    20,    38,     0,     0,     0,
       0,    36,     0,     0,    40,     0,     0,    16,     6,    14,
       8,     0,     0,     0,     0,     0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -16,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,    48,   -23,   -24,   -24,   -24,   -24,   -24,    27,
     -24,   -20,   -24,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    15,    16,    24,    23,    90,    91,    17,    25,
      18,    26,    38,    39,    54,    19,    46,    20,    27,    41,
      74,    21,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    40,    43,    44,    42,     1,    48,    49,    50,    51,
      52,    53,    22,     3,     4,     5,     6,     7,     8,    28,
      30,    66,    67,     9,    45,    10,    11,    12,    47,    64,
      69,    70,    55,    56,    57,    58,    59,    60,    71,    72,
      40,    65,    68,    42,    75,    77,    76,    13,    14,     3,
       4,     5,     6,     7,     8,    31,    32,    84,    78,    79,
      80,    81,    82,    83,    87,    85,    88,    86,    92,    89,
      33,    34,    35,    36,    37,    93,    94,    96,    95,    33,
      34,    35,    36,    37,    33,    34,    35,    36,    37,    63,
      73,     0,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      16,    24,    25,    26,    24,     9,    21,    22,    23,    24,
      25,    26,     0,     3,     4,     5,     6,     7,     8,    10,
      37,    44,    45,    13,    20,    15,    16,    17,    38,    37,
      11,    54,    27,    28,    29,    30,    31,    32,    61,    62,
      63,    38,    20,    63,    38,    68,    38,    37,    38,     3,
       4,     5,     6,     7,     8,    18,    19,    80,    38,    38,
      20,    38,    78,    11,    38,    12,    12,    83,    38,    14,
      33,    34,    35,    36,    37,    11,    38,    12,    94,    33,
      34,    35,    36,    37,    33,    34,    35,    36,    37,    41,
      63,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    40,     3,     4,     5,     6,     7,     8,    13,
      15,    16,    17,    37,    38,    41,    42,    47,    49,    54,
      56,    60,     0,    44,    43,    48,    50,    57,    10,    41,
      37,    18,    19,    33,    34,    35,    36,    37,    51,    52,
      52,    58,    60,    52,    52,    20,    55,    38,    21,    22,
      23,    24,    25,    26,    53,    27,    28,    29,    30,    31,
      32,    61,    62,    51,    37,    38,    52,    52,    20,    11,
      52,    52,    52,    58,    59,    38,    38,    52,    38,    38,
      20,    38,    41,    11,    52,    12,    41,    38,    12,    14,
      45,    46,    38,    11,    38,    41,    12,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    43,    42,    44,    42,    42,
      42,    42,    42,    42,    46,    45,    45,    48,    47,    50,
      49,    51,    51,    51,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    55,    54,    57,    56,    59,
      58,    58,    58,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     0,     9,     0,    10,     1,
       1,     1,     1,     1,     0,     8,     0,     0,     4,     0,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     0,     5,     0,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* prog: BEGINPROG codeblock ENDPROG  */
#line 82 "parser.yacc"
 {
   struct node *temp1 = createNode((yyvsp[-2].node_object).n,(yyvsp[-1].node_object).n,"BEGIN");
   struct node *temp2 = createNode(NULL,(yyvsp[0].node_object).n,"END");
   (yyval.node_object).n = createNode(temp1,temp2,"codeblock");
   root = (yyval.node_object).n;
 }
#line 1387 "y.tab.c"
    break;

  case 3: /* codeblock: code  */
#line 91 "parser.yacc"
{
  (yyval.node_object).n = createNode((yyvsp[0].node_object).n,NULL,"codeblock");
}
#line 1395 "y.tab.c"
    break;

  case 4: /* codeblock: code codeblock  */
#line 97 "parser.yacc"
{
  (yyval.node_object).n = createNode((yyvsp[-1].node_object).n,(yyvsp[0].node_object).n,"codeblock");
}
#line 1403 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 102 "parser.yacc"
          {insert('K');}
#line 1409 "y.tab.c"
    break;

  case 6: /* code: FOR $@1 condstmt cond condstmt NEWLINE START codeblock DONE  */
#line 103 "parser.yacc"
{
  //Create temp nodes to store conditions and condition statements
  //Root points to conditions as left child and right child is the codeblock inside the loop
  struct node *temp1 = createNode((yyvsp[-5].node_object).n,(yyvsp[-4].node_object).n,"CONDITION");
   struct node *temp2 = createNode((yyvsp[-6].node_object).n,temp1,"CONDITION");
   (yyval.node_object).n = createNode(temp2,(yyvsp[-1].node_object).n,"FORLOOP");
 
}
#line 1422 "y.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 111 "parser.yacc"
     {insert('K');}
#line 1428 "y.tab.c"
    break;

  case 8: /* code: IF $@2 cond NEWLINE START NEWLINE codeblock DONE NEWLINE elsestmt  */
#line 112 "parser.yacc"
{
  //Constructs a node to store condtitions and sets root to point to conditions and codeblock
  //as left child
  //right child is the else condition if it exists
  struct node *elif = createNode((yyvsp[-7].node_object).n,(yyvsp[-3].node_object).n,(yyvsp[-9].node_object).varname);
  (yyval.node_object).n = createNode(elif,(yyvsp[-1].node_object).n,"elif");
  totalifstmt++;
}
#line 1441 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 127 "parser.yacc"
               {insert('K');}
#line 1447 "y.tab.c"
    break;

  case 15: /* elsestmt: ELSE $@3 NEWLINE START NEWLINE codeblock DONE NEWLINE  */
#line 128 "parser.yacc"
{
  (yyval.node_object).n = createNode(NULL,(yyvsp[-2].node_object).n,(yyvsp[-7].node_object).varname);
}
#line 1455 "y.tab.c"
    break;

  case 16: /* elsestmt: %empty  */
#line 131 "parser.yacc"
 {(yyval.node_object).n = NULL;}
#line 1461 "y.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 134 "parser.yacc"
                 {insert('K');}
#line 1467 "y.tab.c"
    break;

  case 18: /* printstmt: PRINT $@4 value NEWLINE  */
#line 135 "parser.yacc"
{
  (yyval.node_object).n = createNode((yyvsp[-3].node_object).n,(yyvsp[-1].node_object).n,"PRINTSTMT");
}
#line 1475 "y.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 140 "parser.yacc"
               {insert('K');}
#line 1481 "y.tab.c"
    break;

  case 20: /* scanstmt: SCAN $@5 value value NEWLINE  */
#line 141 "parser.yacc"
{
  struct node *scan = createNode((yyvsp[-2].node_object).n,(yyvsp[-1].node_object).n,"SCANVARS");
  (yyval.node_object).n = createNode((yyvsp[-4].node_object).n,scan,"SCANSTMT");
}
#line 1490 "y.tab.c"
    break;

  case 21: /* cond: BOOLTRUE  */
#line 147 "parser.yacc"
               {(yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1496 "y.tab.c"
    break;

  case 22: /* cond: BOOLFALSE  */
#line 148 "parser.yacc"
            {(yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1502 "y.tab.c"
    break;

  case 23: /* cond: value condop value  */
#line 149 "parser.yacc"
                     {(yyvsp[-2].node_object).n = createNode(NULL,NULL,(yyvsp[-2].node_object).varname); (yyval.node_object).n = createNode((yyvsp[-2].node_object).n,(yyvsp[0].node_object).n,(yyvsp[-1].node_object).varname);}
#line 1508 "y.tab.c"
    break;

  case 24: /* value: REALLIT  */
#line 152 "parser.yacc"
               {insert_type("real"); insert('L'); (yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1514 "y.tab.c"
    break;

  case 25: /* value: INTLIT  */
#line 153 "parser.yacc"
         {insert_type("int"); insert('L'); (yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1520 "y.tab.c"
    break;

  case 26: /* value: CHARLIT  */
#line 154 "parser.yacc"
          {insert_type("char"); insert('L'); (yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1526 "y.tab.c"
    break;

  case 27: /* value: STRLIT  */
#line 155 "parser.yacc"
         {insert_type("string"); insert('L'); (yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1532 "y.tab.c"
    break;

  case 28: /* value: VARNAME  */
#line 156 "parser.yacc"
          {insert_type(yytext); insert('V'); (yyval.node_object).n = createNode(NULL,NULL,(yyvsp[0].node_object).varname);}
#line 1538 "y.tab.c"
    break;

  case 35: /* $@6: %empty  */
#line 168 "parser.yacc"
                      {insert('V');}
#line 1544 "y.tab.c"
    break;

  case 36: /* declare: type VARNAME $@6 ASGN value NEWLINE  */
#line 169 "parser.yacc"
{
  //Creates a child node with the variable name and sets root to have it as leftmost child
  //rightmost child is the value
  (yyvsp[-4].node_object).n = createNode(NULL,NULL,(yyvsp[-4].node_object).varname);
  (yyval.node_object).n = createNode((yyvsp[-4].node_object).n,(yyvsp[-1].node_object).n,"DECLARATION");
}
#line 1555 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 177 "parser.yacc"
                { no_declaration((yyvsp[0].node_object).varname); insert('V');}
#line 1561 "y.tab.c"
    break;

  case 38: /* assign: VARNAME $@7 ASGN value NEWLINE  */
#line 178 "parser.yacc"
{
  (yyval.node_object).n = createNode((yyvsp[-4].node_object).n,(yyvsp[-2].node_object).n,"ASSIGNMENT");
}
#line 1569 "y.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 183 "parser.yacc"
                       { insert('V');}
#line 1575 "y.tab.c"
    break;

  case 40: /* condstmt: type VARNAME $@8 ASGN value  */
#line 184 "parser.yacc"
{
  (yyvsp[-3].node_object).n = createNode(NULL,NULL,(yyvsp[-3].node_object).varname);
  (yyval.node_object).n = createNode((yyvsp[-3].node_object).n,(yyvsp[0].node_object).n,(yyvsp[-1].node_object).varname);
}
#line 1584 "y.tab.c"
    break;

  case 41: /* condstmt: value boolop value  */
#line 189 "parser.yacc"
{
  no_declaration((yyvsp[-2].node_object).varname);
  (yyval.node_object).n = createNode((yyvsp[-2].node_object).n,(yyvsp[0].node_object).n,(yyvsp[-1].node_object).varname);
}
#line 1593 "y.tab.c"
    break;

  case 42: /* condstmt: value mathop value  */
#line 194 "parser.yacc"
{
  no_declaration((yyvsp[-2].node_object).varname);
  (yyval.node_object).n = createNode((yyvsp[-2].node_object).n,(yyvsp[0].node_object).n,(yyvsp[-1].node_object).varname);
}
#line 1602 "y.tab.c"
    break;

  case 43: /* type: INT  */
#line 200 "parser.yacc"
          {insert_type("int");}
#line 1608 "y.tab.c"
    break;

  case 44: /* type: CHAR  */
#line 201 "parser.yacc"
       {insert_type("char");}
#line 1614 "y.tab.c"
    break;

  case 45: /* type: STRING  */
#line 202 "parser.yacc"
         {insert_type("string");}
#line 1620 "y.tab.c"
    break;

  case 46: /* type: BOOL  */
#line 203 "parser.yacc"
       {insert_type("bool");}
#line 1626 "y.tab.c"
    break;

  case 47: /* type: REAL  */
#line 204 "parser.yacc"
       {insert_type("real");}
#line 1632 "y.tab.c"
    break;

  case 48: /* type: EMPTY  */
#line 205 "parser.yacc"
        {insert_type("empty");}
#line 1638 "y.tab.c"
    break;


#line 1642 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 218 "parser.yacc"


void printSynTree(struct node*n){

  if(n->L){
    printSynTree(n->L);
  }
  printf("%s | ",n->token);

  if(n->R){
    printSynTree(n->R);
  }
  
  
}

void gencodevars(struct node*n){

  //traverse SynTree in order and store declared variables in var array
  if(n->L){
    gencodevars(n->L);
  }
  //Variable Declaration
  if(strcmp(n->token,"DECLARATION")==0){
    //grab l child varaible and r child value convert to asm and store in array with newline
    //check for string declaration
    if((memcmp(n->R->token,"\"",1))){
    snprintf(codevar_array[codevarindex],39,"%s DQ %s\n",n->L->token,n->R->token);
    codevarindex++;
    numdefinedvar++;
    }else if(!(memcmp(n->R->token,"\"",1))){
      //is a string declaration need to place in string vars array
      //need to store string number for determining right string and length
      int strnum = stringindex;
      snprintf(string_array[stringindex],127,"msg%i DQ %s, 0 \nlen%i equ $ - %s\n",stringindex,n->R->token,stringindex,n->L->token);
      stringindex++;
      numdefinedstr++;
    }
    
  }

  //Scan variable declaration scanstmtcounter
  if(strcmp(n->token,"SCANSTMT")==0){
    
  }
  
  if(n->R){
    gencodevars(n->R);
  }
  
}

void gencodestrings(struct node*n){
  //traverse SynTree in order and store declared strings in var array
  //and print stmt strings
}

void ifcodeblock(struct node*n){

  //iterate tree recursively in order
  if(n->L){
    ifcodeblock(n->L);
  }

  //IF PRINTSTMT is current node
   if(strcmp(n->token,"PRINTSTMT")==0){
  
    //PRINT LITERAL DECLARED INLINE
    if(!(memcmp(n->R->token,"\"",1))){
      // snprintf(codeblock_array[codeblockindex],127,"")
      //print stmt R node is literal
      snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store string to print in ecx\nint 0x80\t;print value stored in ecx\n",n->R->token);
      codeblockindex++;
	}else{
      //print predefined string
      if(pstmtcounter < numdefinedstr){
	snprintf(codeblock_array[codeblockindex],127,"mov edx,len%i\nmov dx,msg%i\nmov ebx,1\nmov dx,4\nint 0x80\n\n",
		 pstmtcounter,pstmtcounter);
	pstmtcounter++;
	codeblockindex++;
      }
    }
  }

   //right node iteration
  if(n->R){
    ifcodeblock(n->R);
  }
  
}

void gencodeblock(struct node*n){

  if(n->L){
    gencodeblock(n->L);
  }

  /*FOR LOOP GENERATION*/
  
  if(strcmp(n->token,"FORLOOP")==0){
    //loopcounter var counts loop number
    // push number for index onto stack
    // jump to loop cond
    //left subtree first condition n->L->L->token number at n->L->L->R->token
    snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store loop index var on stack\njmp loop%i\n",n->L->L->R->token,loopcounter);
    codeblockindex++;
    //print loop label and push ecx onto the stack
    snprintf(codeblock_array[codeblockindex],127,"loop%i:\npush ecx\t;save loop index on stack\n",loopcounter);
    
    codeblockindex++;

    /*RECURSIVE CALL TO GENERATE CODE WITHIN LOOP*/
    gencodeblock(n->R);
    
    //left subtree comparison cond n->L->R->L comp cond op is n->L->R->L.varname
       //get number value from cond
      int condnum = atoi(n->L->R->L->R->token);
      /*LOOP COUNTER AND END CONDITIONS (!= and == only add to counter and perform comparison)*/
    if(strchr(n->L->R->L->token,'<')!=NULL){
      
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njl loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if(strchr(n->L->R->L->token,'>')!=NULL){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\njg loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'<')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njle loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'>')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\njge loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'!')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nadd ecx, 1\ncmp ecx, %i\njne loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }else if((strchr(n->L->R->L->token,'=')!=NULL) && (strchr(n->L->R->L->token,'=')!=NULL)){ 
      snprintf(codeblock_array[codeblockindex],127,
	       "pop ecx\t;get loop index\nsub ecx, 1\ncmp ecx, %i\nje loop%i\n\n",
	       condnum,loopcounter);
      codeblockindex++;
	loopcounter++;
    }
    

    
  }
  /*IF STATEMENT CODE GENERATION*/
  else if(strcmp(n->token,"elif")==0){

    //store first comp value in reg
    snprintf(codeblock_array[codeblockindex],127,"mov ax, %s\t;store if LHS COND var in reg\n",n->L->L->L->token);
    codeblockindex++;

    //store second comp value in reg
    snprintf(codeblock_array[codeblockindex],127,"mov bx, %s\t;store if RHS cond var in reg\n",n->L->L->R->token);
    codeblockindex++;
    //check comparison
     if(strchr(n->L->L->token,'<')!=NULL && totalifstmt > 0){
      snprintf(codeblock_array[codeblockindex],127,
	       "cmp ax, bx\t;compare if stmt conditions\n");
      codeblockindex++;
      //jump to ifstmt
      snprintf(codeblock_array[codeblockindex],127,"jl ifstmt%i\t;jump if lessthan\n",ifstmtcounter);
      codeblockindex++;
      ifstmtcounter++;
      totalifstmt--;
      //generate inside ifblock recursivly
       gencodeblock(n->L->R);
      ifcodeblock(n->L->R);
      //check for else
      if(n->R != NULL){
	//gen code for else block recursivly
	//	gencodeblock(n->R);
	ifcodeblock(n->R);
      }
     }else if(strchr(n->L->L->token,'>')!=NULL && totalifstmt > 0){
      snprintf(codeblock_array[codeblockindex],127,
	       "cmp ax, bx\t;compare if stmt conditions\n");
      codeblockindex++;
      //jump to ifstmt
      snprintf(codeblock_array[codeblockindex],127,"jg ifstmt%i\t;jump if greater than\n",ifstmtcounter);
      ifstmtcounter++;
      codeblockindex++;
      totalifstmt--;
      
      //print ifstmt label
      snprintf(codeblock_array[codeblockindex],127,"ifstmt%i:\t ifstmt start label\n",ifstmtcounter);
      codeblockindex++;
      //generate ifblock content recursivly
      // gencodeblock(n->L->R);
      ifcodeblock(n->L->R);
      //check for else
      if(n->R != NULL){
	//gen code for else block recursivly
	gencodeblock(n->R);
	ifcodeblock(n->R);
      }
     }

     
  }
  
  /*PRINT STATEMENT CODE GENERATION*/
  if(strcmp(n->token,"PRINTSTMT")==0){
    //codeblock_array[codeblockindex]
    //PRINT LITERAL DECLARED INLINE
    if((memcmp(n->R->token,"\"",1))){
      // snprintf(codeblock_array[codeblockindex],127,"")
      //print stmt R node is literal
      snprintf(codeblock_array[codeblockindex],127,"mov ecx, %s\t;store string to print in ecx\nint 0x80\t;print value stored in ecx\n",n->R->token);
      codeblockindex++;
	}else{
      //print predefined string
      if(pstmtcounter < numdefinedstr){
	snprintf(codeblock_array[codeblockindex],127,"mov edx,len%i\nmov dx,msg%i\nmov ebx,1\nmov dx,4\nint 0x80\n\n",
		 pstmtcounter,pstmtcounter);
	pstmtcounter++;
	codeblockindex++;
      }
    }
  }
  //check for scanstmt
  
  //check for assignment

    if(n->R){
      gencodeblock(n->R);
    }

}

void gencode(struct node*n){

  //open and create file to write to
  FILE *fp;
  fp = fopen("output.s","w+a");
  //gen variables
  gencodevars(n);
  //generate strings
  gencodestrings(n);
  printf("section .text\n\n");
  fprintf(fp,"section .text\n\n");
  //global vars here

  //assigning entrypoint
  printf("global_start\n\n");
  fprintf(fp,"global_start\n\n");
  //string section and predefined locals
  printf("section .data\n\n");
  fprintf(fp,"section .data\n\n");
  for(int i = 0; i < 40; i++){
    printf("%s",codevar_array[i]);
    fprintf(fp,"%s",codevar_array[i]);
  }
  for(int i = 0; i < 40; i++){
    printf("%s",string_array[i]);
    fprintf(fp,"%s",string_array[i]);
  }
  //code start section
  printf("\nsection .text\n\n");
  fprintf(fp,"\nsection .text\n\n");

  //start of program
  printf("_start:\n");
  fprintf(fp,"_start:\n");
  //generated code here

  //gencodeblock call
  gencodeblock(n);
  //print codeblock generation
  for(int i = 0; i < 128; i++){
    printf("%s",codeblock_array[i]);
    fprintf(fp,"%s",codeblock_array[i]);
  }
  //exit via kernel syscall
  fprintf(fp,"\nint 0x80\t;END PROGRAM CALLS\nmov ebx,0\nmov eax,1\nint 0x80\n");
  //call kernel
  printf("\nint 0x80\t;END PROGRAM CALLS\n");
  //process exit
  printf("mov ebx,0\n");
  printf("mov eax,1\n");
  //final kernel call
  printf("int 0x80\n");

  //cleanup
  //free tree memory
  cleanup(root);
  //close file
  fclose(fp);
  
}

struct node* createNode(struct node *L, struct node *R, char *tok){
  //allocate memory and set leaf nodes
  struct node* leaf = (struct node*)malloc(sizeof(struct node));
  char *data = (char*)malloc(strlen(tok)+1);
  strcpy(data,tok);
  leaf->L = L;
  leaf->R = R;
  leaf->token = data;
  return leaf;
}

void cleanup(struct node* n){
  //Recursivly delete syntax tree
  if(n == NULL){
    return;
  }
  //delete l child
  cleanup(n->L);
  //delete r child
  cleanup(n->R);
  //delete current node and token data
  free(n->token);
  free(n);
  return;
}

void no_declaration(char *s){
  //check symtable for declared variable if none exists output error
  status = lookup(s);
  if(!status){
    sprintf(errarray[errindex],"ERROR: Line: %i Variable (%s) undeclared before usage.\n",lineno+1,s);
    errindex++;
  }
}

void mult_declaration(char *s){
  /*TODO*/
}

void keyword_var(char *s){
  for(int i = 0; i < 11; i++){
  if(strcmp(s,"begin")==0){
    sprintf(errarray[errindex],"ERROR: Line: %i Variable (%s) cannot be a key word.\n",lineno+1,s);
    errindex++;
  }
  }
}

int type_checker(char *s1, char *s2){
  /*TODO*/
}

char *get_current_type(char *s){
  /*TODO*/
}


int main() {

  printf("Parsing...\n");
  int res = yyparse();

  //ERROR CHECK
  if(errindex > 0){
    //errors detected
    printf("ERRORS OCCURED:\n");
    for(int i = 0; i < errindex; i++){
      printf("%s\n",errarray[i]);
      
    }
    exit(1);
  }
  
  printf("DONE\n");
  printf("DUMPING SYM TABLE\n");
  dumpsymtbl();
  printf("----------PRINTING SYNTAX TREE----------\n");
  printSynTree(root);
  printf("\n------------------DONE------------------\n");
  printf("-------------GENERATING CODE------------\n");
  gencode(root);
  printf("---------DONE CODE GENERATION-----------\n");
  printf("--[Generated code saved to \"output.s\"]--\n");
  return(res);
  
}

