/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas,Adrian Iza                              			*
* Fecha de creación: 13/12/2020                                     *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/

#include <iostream>
#include <string>
#include "IngresoDatos.h"

using namespace std;

int main()
{
    string nombre;
    string cedula;

    IngresoDatos ingreso;
    cedula=ingreso.IngresoNumero("Ingrese la cedula\n");
    cout << "La cedula es->" << cedula<<endl;

    nombre = ingreso.IngresoTexto("Ingrese su nombre\n");
    cout << "El nombre es->" << nombre << endl;
}

