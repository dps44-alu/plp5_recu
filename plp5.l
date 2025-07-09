%{
#include "plp5.tab.h"
#include "comun.h"
#include <string.h>
int col = 1;                /* columna actual */
#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.first_column = col; \
    yylloc.last_line = yylineno; \
    yylloc.last_column = col + yyleng - 1; \
    col += yyleng;
%}

%option yylineno
%option noinput nounput

%x COMMENT

DIG [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*
NUMREAL {DIG}+"."{DIG}+
NUMINT {DIG}+
%%
"/*" { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>\n { col=1; }
<COMMENT>. { }

[ \t\r]+ { /* skip blanks, column updated in YY_USER_ACTION */ }
\n { col=1; }

"fn"        { return FN; }
"endfn"     { return ENDFN; }
"int"       { return INTKW; }
"real"      { return REALKW; }
"array"     { return ARRAYKW; }
"let"       { return LET; }
"var"       { return VAR; }
"if"        { return IF; }
"else"      { return ELSE; }
"elif"      { return ELIF; }
"fi"        { return FI; }
"while"     { return WHILE; }
"loop"      { return LOOP; }
"range"     { return RANGE; }
"endloop"   { return ENDLOOP; }
"blq"       { return BLQ; }
"fblq"      { return FBLQ; }
"read"      { return READ; }
"print"     { return PRINT; }

"+"|"-"      { yylval.lexema=strdup(yytext); return OPAS; }
"*"|"/"      { yylval.lexema=strdup(yytext); return OPMD; }
"("         { return PARI; }
")"         { return PARD; }
"["         { return CORI; }
"]"         { return CORD; }
","         { return COMA; }
":"         { return DOSP; }
";"         { return PYC; }
"="         { return ASIG; }

{NUMREAL}   { yylval.real=atof(yytext); return NUMREAL; }
{NUMINT}    { yylval.num=atoi(yytext); return NUMINT; }
{ID}        { yylval.lexema=strdup(yytext); return ID; }

.           { msgError(ERRLEXICO,yylineno,col,yytext); }
%%
int yywrap(){ return 1; }
