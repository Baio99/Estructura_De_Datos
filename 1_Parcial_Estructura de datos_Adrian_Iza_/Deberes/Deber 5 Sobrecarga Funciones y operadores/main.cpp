/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas,Adrian Iza                                			*
* Fecha de creación: 15/12/2020                                     *
* Fecha de modificacion: 16/12/2020                                 *
*                                                       			*
******************************************************************/
#include <iostream>
#include "math_utils.h"

using namespace std;

int main() {
    cout << "suma de 5 + 5 = " << suma(5, 5) << endl;
    cout << "suma de 4.6 + 2.4 = " << suma(4.6, 2.4) << endl << endl;

    cout << "resta de 8 - 7 = " << resta(8, 7) << endl;
    cout << "resta de 5.5 - 0.5 = " << resta(5.5, 0.5) << endl << endl;

    cout << "multiplicacion de 12 * 12 = " << multiplicacion(12, 12) << endl;
    cout << "multiplicacion de 0.2 * 10 = " << multiplicacion(0.2, 10.0) << endl << endl;

    cout << "division de 100 / 25 = " << division(100, 25) << endl;
    cout << "division de 20 / 4.5 = " << division(20.0, 4.5) << endl << endl;
}
