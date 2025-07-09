%{
#include <string>
#include <iostream>
#include <sstream>
#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"
#include <stack>
#include <vector>
using namespace std;

TablaSimbolos *ts = nullptr;
TablaTipos tt;
unsigned dirActual = 0; // direccion libre para variables
std::stack<unsigned> pilaDir;
unsigned baseTipo; // para construir tipos de arrays
int ctemp = 16000;
bool enIndices=false;
bool primeraIndice=true;
int corFila=0, corCol=0;
int comaFila=0, comaCol=0;
int indiceDepth=0;
struct SavedIndex { bool en; bool prim; int corF; int corC; int comaF; int comaC; };
std::vector<SavedIndex> idxStack;

int nuevaTemp(void){
    if(ctemp>16383){
        errorSemantico(ERR_MAXTEMP,0,0,"");
    }
    return ctemp++;
}

int yylex();
void yyerror(const char *s);
extern int yylineno;
extern char *yytext;

%}

%code requires {
#include "comun.h"
}

%define parse.error verbose
%locations

%union{
    char* lexema;
    int num;
    double real;
    unsigned tipo;
    TypeInfo tinfo;
}

%token FN ENDFN INTKW REALKW ARRAYKW LET VAR IF ELSE ELIF FI WHILE LOOP RANGE ENDLOOP BLQ FBLQ READ PRINT
%token PARI PARD CORI CORD COMA DOSP PYC ASIG
%token <lexema> ID
%token <num> NUMINT
%token <real> NUMREAL
%token <lexema> OPAS
%token <lexema> OPMD

%type <tipo> SType
%type <tinfo> Type IT Dim
%type <tipo> E T F Ref
%type <num> LExpr

%%
S : Fun { }
  ;

Fun : FN ID PARI PARD Cod ENDFN { }
    ;

SType : INTKW { $$ = 0; }
      | REALKW { $$ = 1; }
      ;

Type : SType { $$.tipo=$1; $$.tam=1; $$.ndim=0; }
     | ARRAYKW SType { baseTipo=$2==0?0:1; } Dim { $$.tipo=$4.tipo; $$.tam=$4.tam; $$.ndim=$4.ndim; }
     ;

Dim : NUMINT COMA Dim {
        if($1<=0) errorSemantico(ERR_DIM,@1.first_line,@1.first_column,"");
        unsigned t=tt.nuevoTipoArray($1,$3.tipo); $$.tipo=t; $$.tam=$1*$3.tam; $$.ndim=$3.ndim+1;
    }
    | NUMINT {
        if($1<=0) errorSemantico(ERR_DIM,@1.first_line,@1.first_column,"");
        unsigned t=tt.nuevoTipoArray($1,baseTipo); $$.tipo=t; $$.tam=$1; $$.ndim=1;
    }
    ;

Cod : Cod PYC I
    | Cod PYC
    | I
    ;

I : Blq
   | LET Ref ASIG E {
        if(!(( $2==1 && $4==0) || $2==$4 ))
             errorSemantico(ERR_ASIG,@3.first_line,@3.first_column,"");
      }
   | VAR ID IT {
        Simbolo s; s.nombre=$2; s.tipo=$3.tipo; s.dir=dirActual; s.tam=$3.tam;
        if(!ts->newSymb(s)) errorSemantico(ERR_YADECL,@2.first_line,@2.first_column,$2);
        if(dirActual + s.tam > 16000) errorSemantico(ERR_NOCABE,@2.first_line,@2.first_column,$2);
        dirActual += s.tam;
      }
   | PRINT E
   | READ Ref
   | WHILE E { if($2!=0) errorSemantico(ERR_IFWHILE,@1.first_line,@1.first_column,"while"); } I
   | LOOP ID RANGE Range I ENDLOOP {
        Simbolo *s = ts->searchSymb($2);
        if(!s) errorSemantico(ERR_NODECL,@2.first_line,@2.first_column,$2);
        else if(!(tt.tipos[s->tipo].clase==TIPOBASICO && s->tipo==0))
            errorSemantico(ERR_LOOP,@1.first_line,@1.first_column,"loop");
      }
   | IF E { if($2!=0) errorSemantico(ERR_IFWHILE,@1.first_line,@1.first_column,"if"); } I Ip
   ;

Range : NUMINT DOSP NUMINT
      | NUMINT
      ;

Blq : BLQ { ts=new TablaSimbolos(ts); pilaDir.push(dirActual); } Cod FBLQ { dirActual=pilaDir.top(); pilaDir.pop(); ts=ts->getPadre(); }
    ;

Ip : ELSE I FI
   | ELIF E I Ip
   | FI
   ;

IT : DOSP Type { $$ = $2; }
   | /* empty */ { $$.tipo=0; $$.tam=1; $$.ndim=0; }
   ;

E : E OPAS T { $$ = ($1==1 || $3==1)?1:0; }
  | OPAS T { $$ = $2; }
  | T { $$ = $1; }
  ;

T : T OPMD F { $$ = ($1==1 || $3==1)?1:0; }
  | F { $$ = $1; }
  ;

F : NUMINT { $$=0; }
  | NUMREAL { $$=1; }
  | PARI E PARD { $$=$2; }
  | Ref { $$=$1; }
  ;

Ref : ID {
        Simbolo *s = ts->searchSymb($1);
        if(!s){
            if(indiceDepth==0) errorSemantico(ERR_NODECL,@1.first_line,@1.first_column,$1);
            $$=0;
        }else $$ = s->tipo;
    }
    | ID CORI {
        SavedIndex tmp{enIndices,primeraIndice,corFila,corCol,comaFila,comaCol};
        idxStack.push_back(tmp);
        enIndices=true; primeraIndice=true;
        corFila=@2.first_line; corCol=@2.first_column;
        comaFila=corFila; comaCol=corCol;
        indiceDepth++;
    } LExpr CORD {
        indiceDepth--;
        Simbolo *s = ts->searchSymb($1);
        if(!s){
            errorSemantico(ERR_NODECL,@1.first_line,@1.first_column,$1);
            $$=0;
        }else{
            unsigned t=s->tipo; unsigned dims=0;
            while(tt.tipos[t].clase==ARRAY){ dims++; t=tt.tipos[t].tipoBase; }
            if($4<dims) errorSemantico(ERR_FALTAN,@5.first_line,@5.first_column,"");
            if($4>dims) errorSemantico(ERR_SOBRAN,comaFila,comaCol,"");
            t=s->tipo;
            for(int i=0;i<$4 && tt.tipos[t].clase==ARRAY;i++) t=tt.tipos[t].tipoBase;
            $$=t;
        }
        SavedIndex rec=idxStack.back();
        idxStack.pop_back();
        enIndices=rec.en;
        primeraIndice=rec.prim;
        corFila=rec.corF; corCol=rec.corC; comaFila=rec.comaF; comaCol=rec.comaC;
    }
    ;

LExpr : LExpr COMA E {
          if(enIndices && $3!=0) errorSemantico(ERR_INDICE_ENTERO,@2.first_line,@2.first_column,"");
          $$=$1+1;
          primeraIndice=false;
          comaFila=@2.first_line; comaCol=@2.first_column;
       }
      | E {
          if(enIndices && $1!=0){
              if(primeraIndice) errorSemantico(ERR_INDICE_ENTERO,corFila,corCol,"");
              else errorSemantico(ERR_INDICE_ENTERO,@1.first_line,@1.first_column,"");
          }
          $$=1;
          primeraIndice=false;
       }
      ;
%%

extern FILE *yyin;

int main(int argc,char *argv[]){
    ts = new TablaSimbolos(nullptr);
    if(argc>1){
        yyin=fopen(argv[1],"r");
        if(!yyin){
            fprintf(stderr,"No puedo abrir %s\n",argv[1]);
            return 1;
        }
    }
    yyparse();
    printf("halt\n");
    return 0;
}

void yyerror(const char *s){
    msgError(ERRSINT,yylineno,0,yytext);
}

void errorSemantico(int nerror,int fila,int columna,const char *s)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    switch (nerror) {
        case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s); break;
        case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s); break;
        case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s); break;
        case ERR_IFWHILE:fprintf(stderr,"la expresion del '%s' debe ser de tipo entero",s); break;
        case ERR_LOOP:fprintf(stderr,"la variable del '%s' debe ser de tipo entero",s); break;
        case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que 0\n"); break;
        case ERR_FALTAN: fprintf(stderr,"faltan indices\n"); break;
        case ERR_SOBRAN: fprintf(stderr,"sobran indices\n"); break;
        case ERR_INDICE_ENTERO: fprintf(stderr,"el indice de un array debe ser de tipo entero\n"); break;
        case ERR_ASIG: fprintf(stderr,"tipos incompatibles en la asignacion\n"); break;
        case ERR_MAXTEMP:fprintf(stderr,"no hay espacio para variables temporales\n"); break;
    }
    exit(-1);
}

void msgError(int nerror,int nlin,int ncol,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s); break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s); break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n"); break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n"); break;
     }
     exit(1);
}
