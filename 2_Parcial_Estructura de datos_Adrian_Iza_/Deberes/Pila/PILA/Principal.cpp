/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Principal
 ***********************************************************************/

#include <iostream>
#include"Pila.h"
#include"Nodo.h"
using namespace std;
#include<conio.h>

int main()
{

 Pila* nueva_pila = new Pila();
    
 int dato, opcion=0;
	char rpt;
	
	do
	{
		cout << "\t PROGRAMA PRINCIPAL PILA\t" << endl;
		cout << "1.Apilar" << endl;
		cout << "2.estaVacia" << endl;
		cout << "3.Desapilar " << endl;
		cout << "4.Mostrar" << endl;
		cout << "5.Salir" << endl;

		cout << "Seleccione una opcion" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			
			do
			{
				cout << "DIGITE UN NUMERO: ";
				cin >> dato;
				nueva_pila->apilar(dato);

				cout << "Deseas agregar otro elemento a la Pila(s/n)";
				cin >> rpt;

			} while ((rpt == 'S' || rpt == 's'));

			break;
		case 2:

			nueva_pila->estaVacia();
			break;
		case 3:
			cout << "Desapilando......... ";
			nueva_pila->desapilar();
			nueva_pila->mostrar();
			break;

		case 4:

			nueva_pila->mostrar();
			break;
		default:
			break;
		}


	} while (opcion != 5);


	system("pause");
	return 0;

	
	
}

