%{
#include "plp5.tab.h"
#include "comun.h"
#include <string.h>
#include <stdlib.h>

int numlin = 1;
int numcol = 1;
%}

%x COMMENT

%%
"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"        { BEGIN(INITIAL); }
<COMMENT>\n          { numlin++; numcol = 1; }
<COMMENT>.           { /* ignore comment */ }

[ \t]+              { numcol += yyleng; }
\n                   { numlin++; numcol = 1; }

"fn"                 { numcol+=yyleng; return TK_FN; }
"endfn"              { numcol+=yyleng; return TK_ENDFN; }
"int"                { numcol+=yyleng; return TK_INT; }
"real"               { numcol+=yyleng; return TK_REAL; }
"array"              { numcol+=yyleng; return TK_ARRAY; }
"blq"                { numcol+=yyleng; return TK_BLQ; }
"fblq"               { numcol+=yyleng; return TK_FBLQ; }
"let"                { numcol+=yyleng; return TK_LET; }
"var"                { numcol+=yyleng; return TK_VAR; }
"print"              { numcol+=yyleng; return TK_PRINT; }
"read"               { numcol+=yyleng; return TK_READ; }
"if"                 { numcol+=yyleng; return TK_IF; }
"else"               { numcol+=yyleng; return TK_ELSE; }
"elif"               { numcol+=yyleng; return TK_ELIF; }
"fi"                 { numcol+=yyleng; return TK_FI; }
"while"              { numcol+=yyleng; return TK_WHILE; }
"loop"               { numcol+=yyleng; return TK_LOOP; }
"range"              { numcol+=yyleng; return TK_RANGE; }
"endloop"            { numcol+=yyleng; return TK_ENDLOOP; }

","                  { numcol+=yyleng; return TK_COMA; }
";"                  { numcol+=yyleng; return TK_PYC; }
":"                  { numcol+=yyleng; return TK_DOSP; }
"("                  { numcol+=yyleng; return TK_PARI; }
")"                  { numcol+=yyleng; return TK_PARD; }
"+"|"-"             { yylval.op = yytext[0]; numcol+=yyleng; return TK_OPAS; }
"*"|"/"             { yylval.op = yytext[0]; numcol+=yyleng; return TK_OPMD; }
"="                  { numcol+=yyleng; return TK_ASIG; }
"["                  { numcol+=yyleng; return TK_CORI; }
"]"                  { numcol+=yyleng; return TK_CORD; }

[0-9]+               {
                        yylval.entero = atoi(yytext);
                        numcol+=yyleng;
                        return TK_NUMINT;
                     }
[0-9]+"."[0-9]+      {
                        yylval.real = atof(yytext);
                        numcol+=yyleng;
                        return TK_NUMREAL;
                     }
[A-Za-z][0-9A-Za-z]* {
                        yylval.cadena = strdup(yytext);
                        numcol+=yyleng;
                        return TK_ID;
                     }

.                    {
                        char s[2]={yytext[0],0};
                        msgError(ERRLEXICO,numlin,numcol,s);
                     }

<<EOF>>              {
                        return 0;
                     }
%%

int yywrap(){ return 1; }
