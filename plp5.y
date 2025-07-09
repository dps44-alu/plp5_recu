%{
#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"

#include <string>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

TablaSimbolos *ts = nullptr;        // Tabla de símbolos actual 
TablaTipos tt;                      // Tabla global de tipos 
unsigned dirActual = 0;             // Siguiente dirección libre para variables 
stack<unsigned> pilaDir;            // Para restaurar la dirección al salir de un bloque 
unsigned baseTipo;                  // Tipo base al construir arrays 
int ctemp = 16000;                  // Contador de temporales 
int etiqueta = 0;                   // Contador de etiquetas 
bool enIndices = false;             // Estamos procesando índices de un array 
bool primeraIndice = true;          // Se refiere al primer índice 
int corFila = 0, corCol = 0;        // Posición del '[' inicial 
int comaFila = 0, comaCol = 0;      // Última coma encontrada 
int indiceDepth = 0;                // Nivel de anidamiento de índices 

// Registro para restaurar flags de índices 
struct SavedIndex {                
    bool en; 
    bool prim; 
    int corF; 
    int corC; 
    int comaF; 
    int comaC; 
    size_t pos; 
};

vector<SavedIndex> idxStack;        // Pila de estados de índices 
vector<CodeAttr*> idxExprs;         // Expresiones de cada índice 
string codigoFinal;                 // Código generado por el programa 
stack<unsigned> pilaIf;             // Etiquetas pendientes en if/else 
stack<unsigned> pilaElse;

struct LoopInfo { 
    Simbolo* sym; 
    int ini; 
    int fin; 
    unsigned lc; 
    unsigned le; 
};

vector<LoopInfo> loopStack;         // Información sobre bucles anidados 
extern int col;
extern int commentDepth;

// Reserva una nueva posición de temporal
int nuevaTemp (void)
{
    if (ctemp > 16383)  // Sin espacio para temporales 
    {                       
        errorSemantico(ERR_MAXTEMP,0,0,"");
    }

    return ctemp++;     // Devuelve la posición y avanza 
}

// Proporciona el número de una nueva etiqueta 
int nuevaEtiqueta ()
{
    return etiqueta++;
}

int yylex ();
void yyerror (const char *s);
extern int yylineno;
extern char *yytext;

%}

%code requires {
#include "comun.h"
}

%define parse.error verbose
%locations

%union {
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
%type <code> E T F Ref
%type <code> Cod I Instr Blq Ip Fun S
%type <rango> Range
%type <num> LExpr Mark

%%

S : Fun 
    { 
        codigoFinal = $1->cod; 
    }
;

Fun : FN ID PARI PARD Cod ENDFN 
    { 
        $$ = $5; 
    }
;

SType : INTKW 
    { 
        $$ = 0; 
    }
    | REALKW 
    { 
        $$ = 1; 
    }
;

// Tipos básicos o construidos mediante 'array' 
Type : SType 
    { 
        $$.tipo=$1; 
        $$.tam=1; 
        $$.ndim=0; 
    }
    | ARRAYKW SType 
    { 
        baseTipo = $2 == 0 ? 0 : 1; 
    } 
    Dim 
    { 
        $$.tipo = $4.tipo; 
        $$.tam = $4.tam; 
        $$.ndim = $4.ndim; 
    }
;

// Lista de dimensiones de un array 
Dim : NUMINT COMA Dim 
    {
        if ($1 <= 0) errorSemantico(ERR_DIM, @1.first_line, @1.first_column, "");

        unsigned t = tt.nuevoTipoArray($1, $3.tipo); 

        $$.tipo = t; 
        $$.tam = $1 * $3.tam; 
        $$.ndim = $3.ndim + 1;
    }
    | NUMINT 
    {
        if($1 <= 0) errorSemantico(ERR_DIM, @1.first_line, @1.first_column, "");

        unsigned t = tt.nuevoTipoArray($1, baseTipo); 

        $$.tipo = t; 
        $$.tam = $1; 
        $$.ndim = 1;
    }
;

// Secuencia de instrucciones separadas por ';' 
Cod : Cod PYC I 
    { 
        $$ = new CodeAttr(mergeCode(*$1, *$3)); 
    }
    | Cod PYC 
    { 
        $$ = $1; 
    }
    | I 
    { 
        $$ = $1; 
    }
;

// Instrucción con salvado y restauración del contador de temporales
I : Mark Instr 
    { 
        ctemp = $1; 
        $$ = $2; 
    }
;

// Punto de guarda para el valor actual de 'ctemp' 
Mark :  // Vacío  
    { 
        $$ = ctemp; 
    }
;

// Implementación de cada tipo de instrucción 
Instr : Blq 
    { 
        $$ = $1; 
    }
    | LET Ref ASIG E 
    {
        if (!(($2->tipo == 1 && $4->tipo == 0) || $2->tipo == $4->tipo ))
        {
            errorSemantico(ERR_ASIG, @3.first_line, @3.first_column, "");
        }

        CodeAttr tmp = convertType(*$4, $2->tipo);
        CodeAttr *res = new CodeAttr();

        res->cod = tmp.cod;
        res->cod += "mov " + to_string(tmp.dir) + " B\n";
        res->cod += $2->cod;
        res->cod += "mov B @A\n";
        res->tipo = 0; 
        res->dir = 0;
        $$ = res;
    }
    | VAR ID IT 
    {
        Simbolo s; 
        s.nombre = $2; 
        s.tipo = $3.tipo; 
        s.dir = dirActual; 
        s.tam = $3.tam;

        if (!ts->newSymb(s)) errorSemantico(ERR_YADECL, @2.first_line, @2.first_column, $2);

        if (dirActual + s.tam > 16000) errorSemantico(ERR_NOCABE, @2.first_line, @2.first_column, $2);
        
        dirActual += s.tam;
        
        $$ = new CodeAttr();
    }
    | PRINT E 
    {
        CodeAttr e = *($2); 
        CodeAttr *r = new CodeAttr(); 

        r->cod = e.cod; 
        r->cod += "mov " + to_string(e.dir) + " A\n"; 
        r->cod += (e.tipo ? "wrr A\n" : "wri A\n"); 
        r->cod += "wrl\n"; 

        $$ = r;
    }
    | READ Ref 
    {
        CodeAttr *r = $2; 
        CodeAttr *res = new CodeAttr();

        res->cod = r->cod; 
        res->cod += (r->tipo ? "rdr @A\n" : "rdi @A\n"); 

        $$ = res;
    }
    | WHILE E I 
    {
        if ($2->tipo != 0) errorSemantico(ERR_IFWHILE, @1.first_line, @1.first_column, "while");

        unsigned L1 = nuevaEtiqueta(), L2 = nuevaEtiqueta();
        string lab1 = label(L1), lab2 = label(L2);
        CodeAttr cond = *($2); 
        CodeAttr body = *($3); 
        CodeAttr *res = new CodeAttr();

        res->cod = lab1 + "\n" + 
                    cond.cod + "mov " + to_string(cond.dir) + " A\n" +
                    "jz " + lab2 + "\n" + body.cod + 
                    "jmp " + lab1 + "\n" + 
                    lab2 + "\n";
        
        $$ = res;
    }
    | LOOP ID RANGE Range 
    {
        Simbolo *s = ts->searchSymb($2);

        if (!s) 
        {
            errorSemantico(ERR_NODECL, @2.first_line, @2.first_column, $2);
        }
        else if (!(tt.tipos[s->tipo].clase == TIPOBASICO && s->tipo == 0))
        {
            errorSemantico(ERR_LOOP, @1.first_line, @1.first_column, "loop");
        }

        LoopInfo info; 
        info.sym = s; 
        info.ini = $4.ini; 
        info.fin = $4.fin;
        info.lc = nuevaEtiqueta(); 
        info.le = nuevaEtiqueta();
        loopStack.push_back(info);
    } 
    I ENDLOOP 
    {
        LoopInfo info = loopStack.back(); 
        loopStack.pop_back();

        CodeAttr body = *($6); 
        CodeAttr *res = new CodeAttr();
        string lc = label(info.lc), le = label(info.le);
        int step = (info.ini <= info.fin) ? 1 : -1;
        int limite = (step == 1) ? info.fin +1 : info.fin -1;

        res->cod = "mov #" + to_string(info.ini) + " A\nmov A " + to_string(info.sym->dir) + "\n";
        res->cod += lc + "\nmov " + to_string(info.sym->dir) + " A\nsubi #" + to_string(limite);
        res->cod += "\njz " + le + "\n"; 
        res->cod += body.cod;
        res->cod += "mov " + to_string(info.sym->dir) + " A\n";

        if      (step == 1) res->cod += "addi #1\n"; 
        else                res->cod += "subi #1\n";

        res->cod += "mov A " + to_string(info.sym->dir) + "\n";
        res->cod += "jmp " + lc + "\n" + le + "\n";
        
        $$ = res;
    }
    | IF E 
    {
        if ($2->tipo != 0) errorSemantico(ERR_IFWHILE, @1.first_line, @1.first_column, "if");

        unsigned lend = nuevaEtiqueta();
        unsigned lelse = nuevaEtiqueta();
        pilaIf.push(lend);
        pilaElse.push(lelse);
    } 
    I Ip 
    {
        unsigned lend = pilaIf.top(); 
        pilaIf.pop();

        unsigned lelse = pilaElse.top(); 
        pilaElse.pop();

        CodeAttr cond = *($2), thenCode = *($4), elsePart = *($5); 
        CodeAttr *res = new CodeAttr();
        string sElse = label(lelse), sEnd = label(lend);
        
        res->cod = cond.cod + "mov " + to_string(cond.dir) + " A\n" +
                    "jz " + sElse + "\n" + thenCode.cod +
                    "jmp " + sEnd + "\n" + sElse + "\n" +
                    elsePart.cod + sEnd + "\n";

        $$ = res;
    }
;

Range : NUMINT DOSP NUMINT 
    { 
        $$.ini = $1; 
        $$.fin = $3; 
    }
    | NUMINT 
    { 
        $$.ini = 0; 
        $$.fin = $1; 
    }
;

Blq : BLQ 
    { 
        ts = new TablaSimbolos(ts); 
        pilaDir.push(dirActual); 
    } 
    Cod FBLQ 
    {
        dirActual = pilaDir.top(); 
        pilaDir.pop(); 
        ts = ts->getPadre();

        $$ = $3;
    }
;

Ip : ELSE I FI 
    { 
        $$ = $2; 
    }
    | ELIF E I Ip 
    {
        unsigned lnext = nuevaEtiqueta();
        CodeAttr cond = *($2), body = *($3), tail = *($4); 
        CodeAttr *res = new CodeAttr();
        string snext = label(lnext); 
        string send = label(pilaIf.top());

        res->cod = cond.cod + "mov " + to_string(cond.dir) + " A\n" + 
                    "jz " + snext + "\n" + body.cod + 
                    "jmp " + send + "\n" + 
                    snext + "\n" + tail.cod;

        $$ = res;
    }
    | FI 
    { 
        $$ = new CodeAttr(); 
    }
;

IT : DOSP Type 
    { 
        $$ = $2; 
    }
    |   // Vacío 
    { 
        $$.tipo = 0; 
        $$.tam = 1; 
        $$.ndim = 0; 
    }
;

E : E OPAS T 
    { 
        $$ = new CodeAttr(binOp(*$1, *$3, $2)); 
    }
    | OPAS T 
    {
        if (strcmp($1, "-") == 0)
        { 
            CodeAttr zero = constInt(0); 
            $$ = new CodeAttr(binOp(zero, *$2, "-")); 
        }
        else 
        {
            $$ = $2;
        }
    }
    | T 
    { 
        $$ = $1; 
    }
;

T : T OPMD F 
    { 
        $$ = new CodeAttr(binOp(*$1, *$3, $2)); 
    }
    | F 
    { 
        $$ = $1; 
    }
;

F : NUMINT 
    { 
        $$ = new CodeAttr(constInt($1)); 
    }
    | NUMREAL 
    {   
        $$ = new CodeAttr(constReal($1)); 
    }
    | PARI E PARD 
    { 
        $$ = $2; 
    }
    | Ref 
    { 
        $$ = new CodeAttr(loadFromAddr(*$1, $1->tipo)); 
    }
;

Ref : ID 
    {
        Simbolo *s = ts->searchSymb($1);
        CodeAttr *r = new CodeAttr(); 

        r->cod = ""; 
        r->dir = 0; 
        r->tipo = 0;

        if (!s)
        {
            if (indiceDepth == 0) errorSemantico(ERR_NODECL, @1.first_line, @1.first_column, $1);
            
            r->cod = "mov #0 A\n";
        }
        else
        {
            r->tipo = s->tipo;
            r->cod = "mov #" + to_string(s->dir) + " A\n";
        }

        $$ = r;
    }
    | ID CORI 
    {
        SavedIndex tmp {
            enIndices,
            primeraIndice,
            corFila,
            corCol,
            comaFila,
            comaCol,
            idxExprs.size()
        };

        idxStack.push_back(tmp);
        
        enIndices = true; 
        primeraIndice = true;
        corFila = @2.first_line; 
        corCol = @2.first_column;
        comaFila = corFila; 
        comaCol = corCol;
        indiceDepth++;
    } 
    LExpr CORD 
    {
        indiceDepth--;
        Simbolo *s = ts->searchSymb($1);
        CodeAttr *r = new CodeAttr(); 

        r->cod = ""; 
        r->dir = 0; 
        r->tipo = 0;

        if (!s)
        {
            errorSemantico(ERR_NODECL, @1.first_line, @1.first_column, $1);
        }
        else
        {
            unsigned t = s->tipo; 
            unsigned dims = 0; 
            vector<unsigned> dsz;

            while (tt.tipos[t].clase == ARRAY)
            { 
                dsz.push_back(tt.tipos[t].tamano); 
                dims++; 

                t = tt.tipos[t].tipoBase; 
            }

            if ($4 < dims) errorSemantico(ERR_FALTAN, @5.first_line, @5.first_column, "");
            if ($4 > dims) errorSemantico(ERR_SOBRAN, comaFila, comaCol, "");

            t = s->tipo; 
            
            for (int i = 0; i < $4 && tt.tipos[t].clase == ARRAY; i++) 
            {
                t = tt.tipos[t].tipoBase;
            }

            r->tipo = t;

            size_t pos = idxStack.back().pos; 
            vector<CodeAttr*> exprs(idxExprs.begin() + pos, idxExprs.end()); 
            idxExprs.resize(pos);
            vector<unsigned> mult(dims); 
            unsigned prod = 1; 
            
            for (int i = dims; i > 0; --i)
            { 
                mult[i-1] = prod; 
                prod *= dsz[i-1]; 
            }

            CodeAttr off = constInt(s->dir);

            for (size_t i = 0; i < exprs.size() ; i++)
            {
                CodeAttr idx = convertType(*exprs[i], 0);

                if (mult[i] != 1)
                { 
                    CodeAttr m = constInt(mult[i]); 
                    idx = binOp(idx, m, "*"); 
                }

                off = binOp(off, idx, "+");
            }

            r->cod = off.cod + "mov " + to_string(off.dir) + " A\n";
        }

        SavedIndex rec = idxStack.back();
        idxStack.pop_back();

        enIndices = rec.en; 
        primeraIndice = rec.prim; 
        corFila = rec.corF; 
        corCol = rec.corC; 
        comaFila = rec.comaF; 
        comaCol = rec.comaC;

        $$ = r;
    }
;

LExpr : LExpr COMA E 
    {
        if (enIndices && $3->tipo != 0) errorSemantico(ERR_INDICE_ENTERO, @2.first_line, @2.first_column, "");

        $$ = $1 + 1;

        primeraIndice = false;
        comaFila = @2.first_line; 
        comaCol = @2.first_column;
        idxExprs.push_back($3);
    }
    | E 
    {
        if (enIndices && $1->tipo != 0)
        {
            if      (primeraIndice) errorSemantico(ERR_INDICE_ENTERO, corFila, corCol, "");
            else                    errorSemantico(ERR_INDICE_ENTERO, @1.first_line, @1.first_column, "");
        }

        $$ = 1;

        primeraIndice = false;
        idxExprs.push_back($1);
    }
;

%%

extern FILE *yyin;

// Punto de entrada del compilador. Abre el fichero fuente si se
// proporciona como argumento y lanza el análisis sintáctico. 
// Al finalizar se imprime el código generado seguido de la instrucción 'halt'.
int main (int argc, char *argv[])
{
    ts = new TablaSimbolos(nullptr);

    if (argc > 1) 
    {
        yyin = fopen(argv[1], "r");

        if (!yyin)
        {
            fprintf(stderr, "No puedo abrir %s\n", argv[1]);
            return 1;
        }
    }
    
    commentDepth = 0;
    col = 1;

    yyparse();
    printf("%s", codigoFinal.c_str());
    printf("halt\n");

    return 0;
}

// Informa de un error sintáctico a partir de la localización actual 
void yyerror (const char *s)
{
    msgError(ERRSINT, yylineno, 0, yytext);
}

// Muestra un mensaje de error semántico y aborta la compilación 
void errorSemantico (int nerror, int fila, int columna, const char *s)
{
    fprintf (stderr, "Error semantico (%d,%d): ", fila, columna);

    switch (nerror) 
    {
        case ERR_YADECL:        fprintf(stderr, "variable '%s' ya declarada\n", s);                     break;
        case ERR_NODECL:        fprintf(stderr, "variable '%s' no declarada\n", s);                     break;
        case ERR_NOCABE:        fprintf(stderr, "la variable '%s' ya no cabe en memoria\n", s);         break;
        case ERR_IFWHILE:       fprintf(stderr, "la expresion del '%s' debe ser de tipo entero", s);    break;
        case ERR_LOOP:          fprintf(stderr, "la variable del '%s' debe ser de tipo entero", s);     break;
        case ERR_DIM:           fprintf(stderr, "la dimension debe ser mayor que 0\n");                 break;
        case ERR_FALTAN:        fprintf(stderr, "faltan indices\n");                                    break;
        case ERR_SOBRAN:        fprintf(stderr, "sobran indices\n");                                    break;
        case ERR_INDICE_ENTERO: fprintf(stderr, "el indice de un array debe ser de tipo entero\n");     break;
        case ERR_ASIG:          fprintf(stderr, "tipos incompatibles en la asignacion\n");              break;
        case ERR_MAXTEMP:       fprintf(stderr, "no hay espacio para variables temporales\n");          break;
    }

    exit(-1);
}

// Imprime los distintos mensajes de error léxico y sintáctico 
void msgError (int nerror, int nlin, int ncol, const char *s)
{
    switch (nerror) 
    {
        case ERRLEXICO: fprintf(stderr, "Error lexico (%d,%d): caracter '%s' incorrecto\n", nlin, ncol, s); break;
        case ERRSINT:   fprintf(stderr, "Error sintactico (%d,%d): en '%s'\n", nlin, ncol, s);              break;
        case ERREOF:    fprintf(stderr, "Error sintactico: fin de fichero inesperado\n");                   break;
        case ERRLEXEOF: fprintf(stderr, "Error lexico: fin de fichero inesperado\n");                       break;
    }
    exit(1);
}