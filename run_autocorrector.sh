#!/bin/bash
mkdir -p salida-obtenida
bash autocorrector-plp5.sh "$@"

# Run additional tests from the 'pruebas' folder if it exists.
if [ -d pruebas ]; then
    FNT=pruebas \
    ENT=pruebas/datos-entrada \
    SAL=pruebas/salida-esperada \
    bash autocorrector-plp5.sh "$@"
fi
