/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the Principal
 ***********************************************************************/

#include <iostream>
#include"Cola.h"
#include"Nodo.h"

using namespace std;

int main()
{
	Cola* nueva_cola = new Cola();
	int dato, opcion=0;
	char rpt;
	
	do
	{
		cout << "\t PROGRAMA PRINCIPAL COLA\t" << endl;
		cout << "1.Encolar" << endl;
		cout << "2.estaVacia" << endl;
		cout << "3.Desencolar " << endl;
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
				nueva_cola->encolar(dato);

				cout << "Deseas agregar otro elemento a la Pila(s/n)";
				cin >> rpt;

			} while ((rpt == 'S' || rpt == 's'));

			break;
		case 2:

			nueva_cola->estaVacia();
			break;
		case 3:
			cout << "Desencolando......... ";
			nueva_cola->desencolar();
			nueva_cola->mostrar();
			break;

		case 4:

			nueva_cola->mostrar();
			break;
		default:
			break;
		}


	} while (opcion != 5);


	system("pause");
	return 0;

	
	
}

	