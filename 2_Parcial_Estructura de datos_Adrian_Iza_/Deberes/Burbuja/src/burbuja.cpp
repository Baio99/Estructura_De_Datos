/******************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE *
* Prorama principal para crear clase      *
* Adrian Iza					  *
* Fecha de creación 31/01/2021			  *
* Fecha de modificación                   *
******************************************/

#include "burbuja.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main(){
	PilaPuntero tope = NULL;
	Orden p;
	int tamanio, numero;
	cout<<"Cuantos numero va a ingresar ?"<<endl;
	cin>>tamanio;

	for(int i=0;i<tamanio;i++){
		cout<<"El numero "<<i<<" es: ";
		cin>>numero;
		p.PushElemento(&tope, numero);
	}
	cout<<"\n"<<endl;
	p.Ordenado(&tope, tamanio);
	cout<<"\nListado orndenado"<<endl;
	p.Mostrar(&tope, tamanio);
}
