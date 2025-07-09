#ifndef COMUN_H
#define COMUN_H

#include <cstdio>
#include <cstdlib>
#include <string>

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
int nuevaEtiqueta();
extern int etiqueta;

typedef struct { unsigned tipo; unsigned tam; unsigned ndim; } TypeInfo;

struct CodeAttr {
    unsigned tipo;   // tipo del valor (0 int, 1 real)
    int dir;         // direccion de memoria del resultado
    std::string cod; // codigo generado
    CodeAttr():tipo(0),dir(0){}
};

inline CodeAttr mergeCode(const CodeAttr &a,const CodeAttr &b){
    CodeAttr r;
    r.tipo = b.tipo;
    r.dir  = b.dir;
    r.cod  = a.cod + b.cod;
    return r;
}

inline CodeAttr constInt(int v){
    CodeAttr r; r.tipo=0; r.dir=nuevaTemp();
    r.cod="mov #"+std::to_string(v)+" A\nmov A "+std::to_string(r.dir)+"\n";
    return r;
}

inline CodeAttr constReal(double v){
    CodeAttr r; r.tipo=1; r.dir=nuevaTemp();
    r.cod="mov $"+std::to_string(v)+" A\nmov A "+std::to_string(r.dir)+"\n";
    return r;
}

inline CodeAttr loadVal(int dir,unsigned tipo){
    CodeAttr r; r.tipo=tipo; r.dir=nuevaTemp();
    r.cod="mov "+std::to_string(dir)+" A\nmov A "+std::to_string(r.dir)+"\n";
    return r;
}

inline CodeAttr loadFromAddr(const CodeAttr &addr,unsigned tipo){
    CodeAttr r; r.tipo=tipo; r.dir=nuevaTemp();
    r.cod=addr.cod;
    r.cod+="mov @A A\n";
    r.cod+="mov A "+std::to_string(r.dir)+"\n";
    return r;
}

inline CodeAttr convertType(const CodeAttr &a,unsigned tipo){
    if(a.tipo==tipo) return a;
    CodeAttr r; r.tipo=tipo; r.dir=nuevaTemp();
    r.cod=a.cod;
    r.cod+="mov "+std::to_string(a.dir)+" A\n";
    if(tipo==1) r.cod+="itor\n"; else r.cod+="rtoi\n";
    r.cod+="mov A "+std::to_string(r.dir)+"\n";
    return r;
}

inline CodeAttr binOp(const CodeAttr &a,const CodeAttr &b,const std::string &op){
    unsigned t=(a.tipo==1 || b.tipo==1)?1:0;
    CodeAttr l=convertType(a,t), r=convertType(b,t);
    CodeAttr res; res.tipo=t; res.dir=nuevaTemp();
    res.cod=l.cod + r.cod;
    res.cod += "mov "+std::to_string(l.dir)+" A\n";
    if(op=="+") res.cod += (t?"addr ":"addi ")+std::to_string(r.dir)+"\n";
    else if(op=="-") res.cod += (t?"subr ":"subi ")+std::to_string(r.dir)+"\n";
    else if(op=="*") res.cod += (t?"mulr ":"muli ")+std::to_string(r.dir)+"\n";
    else if(op=="/") res.cod += (t?"divr ":"divi ")+std::to_string(r.dir)+"\n";
    res.cod += "mov A "+std::to_string(res.dir)+"\n";
    return res;
}

extern bool enIndices;
extern bool primeraIndice;
extern int corFila;
extern int corCol;
extern int comaFila;
extern int comaCol;
extern int indiceDepth;

#endif
