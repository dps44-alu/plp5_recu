/* A Bison parser, made by GNU Bison 3.8.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PLP5_TAB_H_INCLUDED
# define YY_YY_PLP5_TAB_H_INCLUDED
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
    TK_FN = 258,                   /* TK_FN  */
    TK_ENDFN = 259,                /* TK_ENDFN  */
    TK_INT = 260,                  /* TK_INT  */
    TK_REAL = 261,                 /* TK_REAL  */
    TK_ARRAY = 262,                /* TK_ARRAY  */
    TK_BLQ = 263,                  /* TK_BLQ  */
    TK_FBLQ = 264,                 /* TK_FBLQ  */
    TK_LET = 265,                  /* TK_LET  */
    TK_VAR = 266,                  /* TK_VAR  */
    TK_PRINT = 267,                /* TK_PRINT  */
    TK_READ = 268,                 /* TK_READ  */
    TK_IF = 269,                   /* TK_IF  */
    TK_ELSE = 270,                 /* TK_ELSE  */
    TK_ELIF = 271,                 /* TK_ELIF  */
    TK_FI = 272,                   /* TK_FI  */
    TK_WHILE = 273,                /* TK_WHILE  */
    TK_LOOP = 274,                 /* TK_LOOP  */
    TK_RANGE = 275,                /* TK_RANGE  */
    TK_ENDLOOP = 276,              /* TK_ENDLOOP  */
    TK_COMA = 277,                 /* TK_COMA  */
    TK_PYC = 278,                  /* TK_PYC  */
    TK_DOSP = 279,                 /* TK_DOSP  */
    TK_PARI = 280,                 /* TK_PARI  */
    TK_PARD = 281,                 /* TK_PARD  */
    TK_ASIG = 282,                 /* TK_ASIG  */
    TK_CORI = 283,                 /* TK_CORI  */
    TK_CORD = 284,                 /* TK_CORD  */
    TK_OPAS = 285,                 /* TK_OPAS  */
    TK_OPMD = 286,                 /* TK_OPMD  */
    TK_ID = 287,                   /* TK_ID  */
    TK_NUMINT = 288,               /* TK_NUMINT  */
    TK_NUMREAL = 289               /* TK_NUMREAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "plp5.y"

   IdInfo id;
   NumIntInfo numi;
   NumRealInfo numr;
   OpInfo opi;
   Pos pos;
   unsigned tipo;
   ListIndices* list;

#line 108 "plp5.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */
