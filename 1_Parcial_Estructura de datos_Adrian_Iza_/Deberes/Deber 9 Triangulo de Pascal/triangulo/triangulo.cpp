/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas, Adrian Iza                                 			*
* Fecha de creación: 20/12/2020                                     *
* Fecha de modificacion: 13/01/2021                                 *
*                                                       			*
******************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

int Ingreso() {
	int n;
	cout << "¿Ingrese el numero de niveles?\n" << endl;
	cin >> n;
	return n;
}

int main()
{
	
	int triangulo[100];
	
	int x, i, j, n;

	n = Ingreso();
	
	x = 0;
	for (i = 1; i <= n; i++) {
		for (j = x; j >= 0; j--) {
			if (j == x || j == 0) {
				triangulo[j] = 1;
			}
			else
			{
				triangulo[j] = triangulo[j] + triangulo[j - 1];
			}
		}
		x++;
		printf("\n");
	
		for (j = 1; j <= n - i; j++)
			printf("   ");

		for (j = 0; j < x; j++) {
			printf("%3d   ", triangulo[j]);
		}
	}
	return 0;
}


