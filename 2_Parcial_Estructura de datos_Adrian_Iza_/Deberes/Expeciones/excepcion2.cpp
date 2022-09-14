/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial excepciones            *
*Autor Adrian Iza                   *
*Fecha de creacion 20/01/2021            *
*Fecha de modificacion                   *
******************************************/
#include <iostream>
using namespace std;

int main(){
	try {
		int num=-2;
		if(num<0)
		  throw "Error en el sistema";
		  
		  cout << num << endl;

	}
	catch(const char * dato)
	{
		cout<< dato << endl;
	}
	return 0;
}
