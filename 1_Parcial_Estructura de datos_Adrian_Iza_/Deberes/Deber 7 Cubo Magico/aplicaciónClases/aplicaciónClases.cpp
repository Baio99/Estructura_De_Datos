/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas, Adrian Iza                                			*
* Fecha de creaciÃ³n: 13/12/2020                                    *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/

#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    int tamanio,residuo;
    do{
    cout << "Ingrese el tamanio de la matriz de orden impar: ";
    cin >> tamanio;
    residuo = tamanio % 2;
        if (residuo == 0) {
            cout << "Numero invalido, solo ingresar impares" << endl;
        }
        
    } while (tamanio < 1 || residuo == 0);
    Matrix<int> *matriz=new Matrix<int>(tamanio,tamanio);
    matriz->reservamem(tamanio, tamanio);
    matriz->cuboMagico(tamanio);
    delete matriz;
    return 0;
}


