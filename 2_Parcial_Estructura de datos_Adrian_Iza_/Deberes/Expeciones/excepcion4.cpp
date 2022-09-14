/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial excepciones            *
* bat_alloc-es lanzada cuando queremos   *
* reservar memoria dinamicamente         *
* y no podemos porque nuestra memoria    *
*  esta llena                            *
*Autor Adrian Iza                 *
*Fecha de creacion 20/01/2021            *
*Fecha de modificacion                   *
******************************************/
#include<iostream>
using namespace std;

int main(){
	
	try
	{
		int *p;
		while(true)
		   p= new int [1000000];
	}
	catch (bad_alloc & excep)   //bad_allow es un tipo de excepcion se da cuando no puede asignar el espacio en memoria solicitado
	{
		cout<<"Error: "<<excep.what()<<endl;
	}
	return 0;
}
