%{
#include "comun.h"
#include "plp5.tab.h"
#include <string.h>
#include <stdlib.h>

int numlin = 1;
int numcol = 1;
int tokline = 1;
int tokcol = 1;
%}

%x COMMENT

%%
"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"        { BEGIN(INITIAL); }
<COMMENT>\n          { numlin++; numcol = 1; }
<COMMENT>.           { /* ignore comment */ }

[ \t]+              { numcol += yyleng; }
\n                   { numlin++; numcol = 1; }

"fn"                 { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_FN; }
"endfn"              { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ENDFN; }
"int"                { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_INT; }
"real"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_REAL; }
"array"              { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ARRAY; }
"blq"                { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_BLQ; }
"fblq"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_FBLQ; }
"let"                { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_LET; }
"var"                { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_VAR; }
"print"              { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_PRINT; }
"read"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_READ; }
"if"                 { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_IF; }
"else"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ELSE; }
"elif"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ELIF; }
"fi"                 { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_FI; }
"while"              { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_WHILE; }
"loop"               { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_LOOP; }
"range"              { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_RANGE; }
"endloop"            { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ENDLOOP; }

","                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_COMA; }
";"                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_PYC; }
":"                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_DOSP; }
"("                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_PARI; }
")"                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_PARD; }
"+"|"-"             { tokline=numlin; tokcol=numcol; yylval.opi.op = yytext[0]; yylval.opi.fil=numlin; yylval.opi.col=numcol; numcol+=yyleng; return TK_OPAS; }
"*"|"/"             { tokline=numlin; tokcol=numcol; yylval.opi.op = yytext[0]; yylval.opi.fil=numlin; yylval.opi.col=numcol; numcol+=yyleng; return TK_OPMD; }
"="                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_ASIG; }
"["                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_CORI; }
"]"                  { tokline=numlin; tokcol=numcol; yylval.pos.fil=numlin; yylval.pos.col=numcol; numcol+=yyleng; return TK_CORD; }

[0-9]+               {
                        tokline=numlin; tokcol=numcol;
                        yylval.numi.val = atoi(yytext);
                        yylval.numi.fil=numlin; yylval.numi.col=numcol;
                        numcol+=yyleng;
                        return TK_NUMINT;
                     }
[0-9]+"."[0-9]+      {
                        tokline=numlin; tokcol=numcol;
                        yylval.numr.val = atof(yytext);
                        yylval.numr.fil=numlin; yylval.numr.col=numcol;
                        numcol+=yyleng;
                        return TK_NUMREAL;
                     }
[A-Za-z][0-9A-Za-z_]* {
                        tokline=numlin; tokcol=numcol;
                        yylval.id.nombre = strdup(yytext);
                        yylval.id.fil=numlin; yylval.id.col=numcol;
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
