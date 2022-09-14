/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas,Adrian Iza                                			*
* Fecha de creación: 13/12/2020                                     *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/

#include <iostream>
#include "Edad.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Edad edad;
	int anio,mes,dia;
	cout<<"Ingrese su anio de nacimiento"<<endl;
	cin>>anio;
	cout<<"Ingrese su mes de nacimiento"<<endl;
	cin>>mes;
	cout<<"Ingrese su dia de nacimiento"<<endl;
	cin>>dia;
	edad.calcularEdad(dia,mes,anio);
	
	return 0;
}
