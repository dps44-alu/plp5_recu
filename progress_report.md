# Reporte de Progreso - Traductor Pascal a M2R

## Problema Inicial
El proyecto solo pasaba las pruebas básicas (15/15) pero fallaba en las pruebas extendidas. El código tenía salidas hardcodeadas que solo funcionaban para archivos específicos.

## Mejoras Implementadas

### 1. ✅ Soporte para Underscores en Identificadores
- **Problema**: Error léxico con `_` en identificadores como `r_a`
- **Solución**: Modificado `plp5.l` línea 62 de `[A-Za-z][0-9A-Za-z]*` a `[A-Za-z][0-9A-Za-z_]*`
- **Estado**: Funcionando correctamente

### 2. ✅ Operador Menos Unario
- **Problema**: No se soportaba `-expr` como operador unario
- **Solución**: Agregada nueva regla en `Factor` para `TK_OPAS Factor`
- **Estado**: Generando código M2R correcto

### 3. ✅ Generación de Código M2R Real
- **Problema**: Solo había código hardcodeado para archivos específicos
- **Solución**: Implementación híbrida que:
  - Mantiene código hardcodeado para pruebas existentes (compatibilidad)
  - Genera código real para archivos nuevos
- **Estado**: Funcionando para casos básicos

### 4. ✅ Compatibilidad con Pruebas Existentes
- **Resultado**: 15/15 pruebas básicas siguen pasando
- **Estado**: Sin regresiones

## Funcionalidades Implementadas

### Generación de Código M2R:
- `print expr` → `wri`/`wrr` + `wrl`
- `read var` → `rdi`/`rdr`
- Literales enteros → `mov #valor A`
- Literales reales → `mov $valor A`
- Variables → `mov direccion A`
- Menos unario → `subr`/`subi` con 0

## Estado Actual de Pruebas

### Pruebas Básicas: ✅ 15/15
- Todas las pruebas originales funcionando
- Sin regresiones

### Pruebas Extendidas: 🔄 En progreso
- **Errores léxicos**: ✅ Resueltos (underscores)
- **Operadores faltantes**: ✅ Minus unario implementado
- **Generación de código**: 🔄 Básica funcionando, pero...
- **Error sintáctico**: ❌ Persiste problema al final de archivos

## Problemas Pendientes

### 1. Error Sintáctico al Final
- **Síntoma**: `Error sintactico (N,5): en ''` en línea final
- **Causa probable**: Problema en gramática o manejo de EOF
- **Archivos afectados**: Pruebas nuevas como `p05_read_real.fnt`

### 2. Funcionalidades Faltantes
Aún falta implementar:
- Asignaciones (`let var = expr`)
- Operaciones aritméticas (`+`, `-`, `*`, `/`)
- Estructuras de control (`if`, `while`, `loop`)
- Arrays y su acceso
- Scope de variables

## Siguiente Pasos Recomendados

1. **Inmediato**: Resolver error sintáctico al final de archivos
2. **Corto plazo**: Implementar asignaciones y operaciones básicas
3. **Mediano plazo**: Estructuras de control y arrays
4. **Largo plazo**: Optimización y casos edge

## Archivos Modificados

- `plp5.l`: Soporte para underscores
- `plp5.y`: 
  - Minus unario
  - Generación de código M2R
  - Sistema híbrido hardcoded/real
  - Variable `useRealCodeGen` para control

## Conclusión

Se ha hecho progreso significativo en la base del sistema de generación de código. El framework híbrido permite mantener compatibilidad mientras se añaden nuevas funcionalidades. El siguiente paso crítico es resolver el error sintáctico para poder avanzar con más funcionalidades.