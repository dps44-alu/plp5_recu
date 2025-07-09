#ifndef COMUN_H
#define COMUN_H

#include <cstdio>
#include <cstdlib>

const int ERRLEXICO=1,
          ERRSINT=2,
          ERREOF=3,
          ERRLEXEOF=4,

          ERR_YADECL=5,
          ERR_NODECL=6,
          ERR_NOCABE=7,

          ERR_IFWHILE=8,
          ERR_LOOP=9,

          ERR_DIM=10,
          ERR_FALTAN=11,
          ERR_SOBRAN=12,
          ERR_INDICE_ENTERO=13,

          ERR_ASIG=14,
          ERR_MAXTEMP=15;

void errorSemantico(int nerror,int fila,int columna,const char *s);
void msgError(int nerror,int nlin,int ncol,const char *s);

extern int ctemp;
int nuevaTemp(void);

typedef struct { unsigned tipo; unsigned tam; unsigned ndim; } TypeInfo;

extern bool enIndices;
extern bool primeraIndice;
extern int corFila;
extern int corCol;
extern int comaFila;
extern int comaCol;
extern int indiceDepth;

#endif
