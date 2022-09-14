/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial para ejecutar el sudoku*
*Autor Jonathan Maigua y Andrian Iza     *
*Fecha de creacion 25/03/2021            *
*Fecha de modificacion 
******************************************/
#include<iostream>
#include<math.h>
#include "sudoku.h"
int main()
{
    sudoku s;
    s.imprimirSudoku();
    s.inicializarSudoku();
    s.imprimirSudoku();
    std::cout << "\n despues de resolver el problema \n";
    if (s.resolverSudoku())
        s.imprimirSudoku();
    else
        std::cout << "\n solución no existe para este tipo de solución \n";
    return 0;
}
