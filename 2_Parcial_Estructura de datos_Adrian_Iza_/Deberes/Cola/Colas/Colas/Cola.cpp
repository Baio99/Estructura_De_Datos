/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Cola
 ***********************************************************************/

#include "Nodo.h"
#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola()
{
	cabeza = NULL;
	cola = NULL;
}


bool Cola::estaVacia(void)
{
	if (cabeza == NULL)
		return true;
	else
	{
		return false;
	}
	
}


void Cola::encolar(int n)
{
	Nodo* nuevo_nodo = new Nodo();
	Nodo* aux = new Nodo();
	nuevo_nodo->valor = n;
	nuevo_nodo->siguiente = aux;
	if (estaVacia())
	{
		cabeza = nuevo_nodo;
		cola = nuevo_nodo;
	}
	else {
		cola->siguiente = nuevo_nodo;
		cola = nuevo_nodo;
	}
	
}


int  Cola::desencolar()
{
	if (!estaVacia())
	{
		int dato = cabeza->valor;
		Nodo* borrar = cabeza;
		if (cabeza == cola)
		{
			cabeza = NULL;
			cola = NULL;

		}
		else
		{
			cabeza = cabeza->siguiente;
		}
		delete borrar;
		return dato;

	}
	else
	{
		return -1;
	}
}


void Cola::mostrar(void)
{
	Nodo* recorrer = cabeza;
	cout << "Listado de todos los elementos de la cola. \n";
	while (recorrer !=NULL)
	{
		cout << recorrer->valor << " - ";
		recorrer = recorrer->siguiente;

	}
	cout << "\n";
}
int Cola::tamanio() {

	Nodo* recorrer = cabeza;
	int cant = 0;

	while (recorrer!= NULL)
	{
		cant++;
		recorrer = recorrer->siguiente;

	}
	return cant;

}


