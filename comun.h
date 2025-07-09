#ifndef COMUN_H
#define COMUN_H

#include <cstdio>   
#include <cstdlib> 
#include <string>   

// Códigos de error utilizados por el compilador
const int   ERRLEXICO           = 1,    // Carácter no reconocido
            ERRSINT             = 2,    // Error sintáctico
            ERREOF              = 3,    // Fin de fichero inesperado
            ERRLEXEOF           = 4,    // Comentario sin cerrar al final

            ERR_YADECL          = 5,    // Variable ya declarada
            ERR_NODECL          = 6,    // Variable no declarada
            ERR_NOCABE          = 7,    // No hay memoria para la variable

            ERR_IFWHILE         = 8,    // Condición no entera en if/while
            ERR_LOOP            = 9,    // Variable de loop no entera

            ERR_DIM             = 10,   // Dimensión de array incorrecta
            ERR_FALTAN          = 11,   // Faltan índices
            ERR_SOBRAN          = 12,   // Sobran índices
            ERR_INDICE_ENTERO   = 13,   // Índice no es entero

            ERR_ASIG            = 14,   // Tipos incompatibles en asignación
            ERR_MAXTEMP         = 15;   // Se excede el espacio de temporales

void errorSemantico (int nerror, int fila, int columna, const char *s);
void msgError (int nerror, int nlin, int ncol, const char *s);

// Contador de direcciones de temporales (16000..16383)
extern int ctemp;

// Reserva la siguiente posición de temporal y la devuelve
int nuevaTemp(void);

// Genera un nuevo identificador para etiquetas de salto
int nuevaEtiqueta();

// Última etiqueta asignada
extern int etiqueta;

// Descriptor de tipos manejados por la tabla de tipos
typedef struct { 
    unsigned tipo;  // Identificador en la tabla de tipos
    unsigned tam;   // Tamaño en palabras
    unsigned ndim;  // Número de dimensiones si es un array
} TypeInfo;

struct CodeAttr {
    unsigned tipo;                  // 0 -> int, 1 -> real
    int dir;                        // dirección de memoria del resultado
    std::string cod;                // código m2r asociado
    CodeAttr():tipo(0),dir(0){}
};

// Une dos fragmentos de código manteniendo la información del segundo
inline CodeAttr mergeCode (const CodeAttr &a,const CodeAttr &b)
{
    CodeAttr r;
    r.tipo = b.tipo;            // El tipo y la dirección del resultado final
    r.dir  = b.dir;
    r.cod  = a.cod + b.cod;     // Unión del código de ambos
    return r;
}

// Carga la constante entera 'v' en una nueva temporal
inline CodeAttr constInt (int v)
{
    CodeAttr r; 
    r.tipo = 0; 
    r.dir = nuevaTemp();

    r.cod = "mov #" + std::to_string(v) + " A\nmov A " + std::to_string(r.dir) + "\n";

    return r;
}

// Carga la constante real 'v' en una nueva temporal
inline CodeAttr constReal (double v)
{
    CodeAttr r; 
    r.tipo = 1; 
    r.dir = nuevaTemp();

    r.cod = "mov $" + std::to_string(v) + " A\nmov A " + std::to_string(r.dir) + "\n";

    return r;
}


// Etiqueta numérica para el código m2r
inline std::string label (unsigned n) { return "L" + std::to_string(n); }

// Carga en una temporal el valor almacenado en la dirección
// apuntada por 'addr'. El tipo indica si el valor es entero o real
inline CodeAttr loadFromAddr (const CodeAttr &addr, unsigned tipo)
{
    CodeAttr r; 
    r.tipo = tipo; 
    r.dir = nuevaTemp();

    r.cod = addr.cod;                                   // Deja la dirección en A
    r.cod += "mov @A A\n";                              // Lee el valor
    r.cod += "mov A " + std::to_string(r.dir) + "\n";   // Guarda en la temporal

    return r;
}

// Convierte el valor representado por 'a' al tipo dado
inline CodeAttr convertType (CodeAttr a, unsigned tipo)
{
    if (a.tipo == tipo) return a;                       // Ya es del tipo deseado

    a.cod += "mov " + std::to_string(a.dir) + " A\n";

    if      (tipo == 1) a.cod += "itor\n";              // Entero -> Real
    else                a.cod += "rtoi\n";              // Real -> Entero

    a.cod += "mov A " + std::to_string(a.dir) + "\n";
    a.tipo = tipo;

    return a;
}

// Genera el código para aplicar una operación aritmética entre 'a' y 'b'.
// Se hace entre reales si alguno es real y reutiliza la temporal del
// primer operando para almacenar el resultado
inline CodeAttr binOp (const CodeAttr &a, const CodeAttr &b, const std::string &op)
{
    unsigned t = (a.tipo == 1 || b.tipo == 1) ? 1:0;    // Tipo del resultado
    CodeAttr l = convertType(a, t);
    CodeAttr r = convertType(b, t);
    CodeAttr res; 
    res.tipo = t; 
    res.dir = l.dir;
    res.cod = l.cod + r.cod;                            // Código de ambos operandos

    res.cod += "mov " + std::to_string(l.dir) + " A\n";

    if      (op == "+") res.cod += (t ? "addr " : "addi ") + std::to_string(r.dir) + "\n";
    else if (op == "-") res.cod += (t ? "subr " : "subi ") + std::to_string(r.dir) + "\n";
    else if (op == "*") res.cod += (t ? "mulr " : "muli ") + std::to_string(r.dir) + "\n";
    else if (op == "/") res.cod += (t ? "divr " : "divi ") + std::to_string(r.dir) + "\n";

    res.cod += "mov A " + std::to_string(res.dir) + "\n";

    return res;
}

// Variables globales usadas durante el análisis de referencias a arrays
extern bool enIndices;      // Indica si estamos procesando índices
extern bool primeraIndice;  // Marca el primer índice
extern int corFila;         // Posición del '['
extern int corCol;
extern int comaFila;        // Posición de la última ','
extern int comaCol;
extern int indiceDepth;     // Profundidad de índices anidados

// Nivel de anidamiento de comentarios en el lexer
extern int commentDepth;

#endif /* COMUN_H */
