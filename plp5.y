%{
#include <stdio.h>
#include <string>
#include "TablaSimbolos.h"
#include "TablaTipos.h"
#include "comun.h"

extern int numlin, numcol;
int yylex();
extern FILE *yyin;
void yyerror(const char *s);

%}

%union {
   int entero;
   double real;
   char op;
   char *cadena;
}

%token TK_FN TK_ENDFN TK_INT TK_REAL TK_ARRAY TK_BLQ TK_FBLQ TK_LET TK_VAR TK_PRINT TK_READ TK_IF TK_ELSE TK_ELIF TK_FI TK_WHILE TK_LOOP TK_RANGE TK_ENDLOOP
%token TK_COMA TK_PYC TK_DOSP TK_PARI TK_PARD TK_OPAS TK_OPMD TK_ASIG TK_CORI TK_CORD
%token <cadena> TK_ID
%token <entero> TK_NUMINT
%token <real> TK_NUMREAL

%start Programa

%%
Programa : TK_FN TK_ID TK_PARI TK_PARD Cod TK_ENDFN { printf("stop\n"); }
         ;

Cod : /* empty */
    | Cod Instruccion
    ;

Instruccion : TK_BLQ Cod TK_FBLQ
            | TK_LET Ref TK_ASIG Expr
            | TK_VAR TK_ID TipoOpt
            | TK_PRINT Expr
            | TK_READ Ref
            | TK_WHILE Expr Instruccion
            | TK_LOOP TK_ID TK_RANGE Rango Instruccion TK_ENDLOOP
            | TK_IF Expr Instruccion Ip
            ;

Rango : TK_NUMINT TK_DOSP TK_NUMINT
      | TK_NUMINT
      ;

Ip : TK_ELSE Instruccion TK_FI
   | TK_ELIF Expr Instruccion Ip
   | TK_FI
   ;

Ref : TK_ID
    | TK_ID TK_CORI LExpr TK_CORD
    ;

LExpr : Expr
      | LExpr TK_COMA Expr
      ;

Expr : Expr TK_OPAS Term
     | Term
     ;

Term : Term TK_OPMD Factor
     | Factor
     ;

Factor : TK_NUMINT
       | TK_NUMREAL
       | TK_PARI Expr TK_PARD
       | Ref
       ;

TipoOpt : TK_DOSP Tipo
        | /* empty */
        ;

Tipo : SType
     ;

SType : TK_INT
      | TK_REAL
      | TK_ARRAY SType Dim
      ;

Dim : TK_NUMINT
    | TK_NUMINT TK_COMA Dim
    ;
%%

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
    if(argc>1){yyin=fopen(argv[1],"r"); if(!yyin){perror(argv[1]); return -1;}} int r=yyparse(); if(argc>1) fclose(yyin); return r;
}
