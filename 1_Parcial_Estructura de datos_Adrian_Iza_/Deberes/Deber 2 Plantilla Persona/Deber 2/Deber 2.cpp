/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas, Adrian Iza                                 			*
* Fecha de creación: 13/12/2020                                     *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/


#include <iostream>
#include <string>
#include "Persona.h"
#include "IngresoDatos.h"
using namespace std;

int main()
{
    Persona<string> persona;
    IngresoDatos ingreso;
    string variable;

    variable = ingreso.IngresoTexto("Ingrese su nombre:");
    persona.setNombre(variable);
    variable = ingreso.IngresoTexto("Ingrese su apellido:");
    persona.setApellido(variable);
    variable = ingreso.IngresoTexto("Ingrese su direccion:");
    persona.setDireccion(variable);
    variable = ingreso.IngresoNumero("Ingrese su numero telefonico:");
    persona.setTelefono(variable);
    variable = ingreso.IngresoNumero("Ingrese su sueldo:");
    persona.setSueldo(variable);
    persona.toString();



    
}

