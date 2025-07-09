%{
/*
 * Analizador léxico construido con Flex. Se encarga de traducir
 * la entrada en tokens para el parser generado con Bison y de
 * mantener la posición (línea y columna) de cada lexema.
 */
#include "plp5.tab.h"
#include "comun.h"
#include <string.h>

int col = 1;                /* columna actual de la entrada */
int commentDepth = 0;       /* nivel de anidamiento de comentarios */

/*
 * Macro que actualiza la información de localización de cada token
 * utilizando las variables proporcionadas por Flex.
 */
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
"/*" {                      /* inicio de comentario */
    if(commentDepth==0) BEGIN(COMMENT);
    commentDepth++; }
<COMMENT>"/*" { commentDepth++; }       /* comentario anidado */
<COMMENT>"*/" {                         /* fin de comentario */
    if(--commentDepth==0) BEGIN(INITIAL);
}
<COMMENT>\r\n { yylineno++; col=1; }
<COMMENT>\r    { yylineno++; col=1; }
<COMMENT>\n    { col=1; }
<COMMENT><<EOF>> {                 /* EOF sin cerrar comentario */
    msgError(ERRLEXEOF,yylineno,col,"EOF");
}
<COMMENT>. { }

[ \t]+ { /* ignorar espacios, columna actualizada en YY_USER_ACTION */ }
\r\n { yylineno++; col=1; }
\r   { yylineno++; col=1; }
\n   { col=1; }

"fn"        { return FN; }       /* palabras clave */
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

"+"|"-"      { yylval.lexema=strdup(yytext); return OPAS; } /* operadores */
"*"|"/"      { yylval.lexema=strdup(yytext); return OPMD; }
"("         { return PARI; }
")"         { return PARD; }
"["         { return CORI; }
"]"         { return CORD; }
","         { return COMA; }
":"         { return DOSP; }
";"         { return PYC; }
"="         { return ASIG; }

{NUMREAL}   { yylval.real=atof(yytext); return NUMREAL; }    /* literales */
{NUMINT}    { yylval.num=atoi(yytext); return NUMINT; }
{ID}        { yylval.lexema=strdup(yytext); return ID; }

.           { msgError(ERRLEXICO,yylineno,col,yytext); }    /* cualquier otro */
%%
/* Solicita a Flex que finalice al alcanzar EOF */
int yywrap(){ return 1; }
