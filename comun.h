// Common definitions and prototypes

#ifndef COMUN_H
#define COMUN_H
#include <vector>

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

typedef struct {int fil; int col;} Pos;
typedef struct {char *nombre; int fil; int col;} IdInfo;
typedef struct {int val; int fil; int col;} NumIntInfo;
typedef struct {double val; int fil; int col;} NumRealInfo;
typedef struct {char op; int fil; int col;} OpInfo;
struct ListIndices { std::vector<unsigned> tipos; std::vector<Pos> seps; };

#endif
