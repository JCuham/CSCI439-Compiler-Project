/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 150 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
