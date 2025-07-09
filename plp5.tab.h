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
/* "%code requires" blocks.  */
#line 79 "plp5.y"

#include "comun.h"

#line 53 "plp5.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FN = 258,                      /* FN  */
    ENDFN = 259,                   /* ENDFN  */
    INTKW = 260,                   /* INTKW  */
    REALKW = 261,                  /* REALKW  */
    ARRAYKW = 262,                 /* ARRAYKW  */
    LET = 263,                     /* LET  */
    VAR = 264,                     /* VAR  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    ELIF = 267,                    /* ELIF  */
    FI = 268,                      /* FI  */
    WHILE = 269,                   /* WHILE  */
    LOOP = 270,                    /* LOOP  */
    RANGE = 271,                   /* RANGE  */
    ENDLOOP = 272,                 /* ENDLOOP  */
    BLQ = 273,                     /* BLQ  */
    FBLQ = 274,                    /* FBLQ  */
    READ = 275,                    /* READ  */
    PRINT = 276,                   /* PRINT  */
    PARI = 277,                    /* PARI  */
    PARD = 278,                    /* PARD  */
    CORI = 279,                    /* CORI  */
    CORD = 280,                    /* CORD  */
    COMA = 281,                    /* COMA  */
    DOSP = 282,                    /* DOSP  */
    PYC = 283,                     /* PYC  */
    ASIG = 284,                    /* ASIG  */
    ID = 285,                      /* ID  */
    NUMINT = 286,                  /* NUMINT  */
    NUMREAL = 287,                 /* NUMREAL  */
    OPAS = 288,                    /* OPAS  */
    OPMD = 289                     /* OPMD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "plp5.y"

    char* lexema;
    int num;
    double real;
    unsigned tipo;
    TypeInfo tinfo;
    CodeAttr* code;
    struct {
        int ini; 
        int fin;
    } rango;

#line 117 "plp5.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */
