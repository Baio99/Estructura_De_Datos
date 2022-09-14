/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas,Adrian Iza                                 			*
* Fecha de creación: 13/12/2020                                     *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/

#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    Matriz <int> matrix;
    int dimension;
    int** matriz1;
    int** matriz2;
    int** matrizr;

    matriz1 = new int*();
    do {
        cout << "Ingrese una dimension" << endl;
        cin >> dimension;
    } while (dimension <= 1);
   
    matriz1=matrix.memoria(dimension);
    matrix.ingreso(matriz1, dimension);
    matriz2=matrix.memoria(dimension);
    matrix.ingreso(matriz2, dimension);
    matrizr = matrix.memoria(dimension);
    matrix.encerar(matrizr,dimension);
    matrix.proceso(matriz1, matriz2, matrizr, dimension);
    matrix.imprimir(matrizr, dimension);

   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
