#ifndef BURBUJA_H
#define BURBUJA_H


#include <iostream>
#include <cstdlib>
#include <conio.h>


using namespace std;
typedef struct pila {
	int valorDato;
	struct pila* siguiente;
}Pila;

typedef Pila* PilaPuntero;

class Orden{
	public:
	void PushElemento(PilaPuntero* tope, int valorDato);
	void Ordenado(PilaPuntero *, int maximo);
	void Mostrar(PilaPuntero *, int maximo);
};
void Orden::PushElemento(PilaPuntero* tope, int valorDato){
	PilaPuntero nuevoDato;
	nuevoDato = (PilaPuntero)malloc(sizeof(Pila));
	if(nuevoDato == NULL){
		cout<<"No existe Memoria";
	}else{
		nuevoDato->valorDato = valorDato;
		nuevoDato->siguiente = *tope;
		*tope = nuevoDato;
	}
}

void Orden::Ordenado(PilaPuntero *pila, int maximo){
	PilaPuntero aux = *pila;
	int ayuda;
	int i=maximo;
	while(i>0){
		aux=*pila;
		while(aux->siguiente!= NULL){
			if(aux->valorDato > aux->siguiente->valorDato){
				ayuda=aux->valorDato;
				aux->valorDato = aux->siguiente->valorDato;
				aux->siguiente->valorDato =ayuda;
			}
			aux=aux->siguiente;
		}
		i--;
	}
}

void Orden::Mostrar(PilaPuntero *pila, int maximo){
	PilaPuntero aux = *pila;
	aux=*pila;
	for(int i=0; i<=maximo;i++){
		cout<<""<<aux->valorDato<<endl;
		aux=aux->siguiente;
	}
}

#endif // BURBUJA_H
