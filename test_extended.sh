#!/bin/bash

MAXTIME=15
PRINCIPAL=plp5
FNT=pruebas/fuentes
ENT=pruebas/datos-entrada
SAL=pruebas/salida-esperada
OBT=salida-obtenida

echo "Running extended test suite..."
echo "======================================"

npruebas=0
pok=0
pfail=0

for i in `ls $FNT`
do
    echo -n "Testing $i: "
    
    # Run the main program
    timeout $MAXTIME ./$PRINCIPAL $FNT/$i > $OBT/$i.cod 2> $OBT/$i.err
    
    if test -s $OBT/$i.err ; then  # there's an error
        if test -s $SAL/$i.err; then
            # Compare error outputs
            if diff -q $OBT/$i.err $SAL/$i.err > /dev/null; then
                echo "OK (error as expected)"
                let pok++
            else
                echo "FAIL (wrong error message)"
                let pfail++
            fi
        else
            echo "FAIL (unexpected error)"
            let pfail++
        fi
    else  # no errors, run m2r
        if test -s $ENT/$i.ent ; then
            timeout $MAXTIME ./m2r $OBT/$i.cod < $ENT/$i.ent > $OBT/$i.sal 2>&1
        else
            timeout $MAXTIME ./m2r $OBT/$i.cod > $OBT/$i.sal 2>&1
        fi
        
        # Compare outputs
        if test -s $SAL/$i.sal; then
            if diff -q $OBT/$i.sal $SAL/$i.sal > /dev/null; then
                echo "OK"
                let pok++
            else
                echo "FAIL (wrong output)"
                let pfail++
            fi
        else
            echo "FAIL (missing expected output file)"
            let pfail++
        fi
    fi
    
    let npruebas++
done

echo "======================================"
echo "Extended test results: $pok/$npruebas tests passed ($pfail failed)"
echo "Success rate: $(( pok * 100 / npruebas ))%"