/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial para calcular el valor *
absoluto de un numero                    *
*Autor Jonathan Maigua                   *
*Fecha de creacion 21/12/2020            *
*Fecha de modificacion 
******************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "MagicSquare.h"
using namespace std;

int main() {
	MagicSquare square;
	int n;
	cout<<"Cuadrado Magico:"<<endl;
	cout<<"Ingrese el tamaño de la matriz:"<<endl;
	cin>>n;

	for (int i = n; i <= n; i++) {
		square.create(i);
		square.display();
	}
}

