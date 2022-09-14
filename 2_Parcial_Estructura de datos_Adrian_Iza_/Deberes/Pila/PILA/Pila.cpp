/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Pila.cpp
 ***********************************************************************/

#include "Nodo.h"
#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila()
{
	cab = NULL;
}

bool Pila::estaVacia()
{
	if (cab == NULL)
		return true;
	else
	{
		return false;
	}
}

void Pila::apilar(int n)
{
	Nodo* nuevo_nodo = new Nodo();
	Nodo* aux = new Nodo();
	nuevo_nodo->valor = n;
	if (cab == aux) {
		cab = nuevo_nodo;
		nuevo_nodo->siguiente = aux;

	}
	else
	{
		nuevo_nodo->siguiente = cab;
		cab = nuevo_nodo;
	}
	
}

int  Pila::desapilar()
{
	Nodo* aux = new Nodo();
	if (cab != aux)
	{
		int dato = cab->valor;
		Nodo* borrar=cab;
		cab = cab->siguiente;
		delete borrar;

		return dato;
	}
	else
	{
		return -1;
	}
}


void Pila::mostrar(void)
{
	Nodo* recorrer = cab;
	cout << "Listado de todos los elementos de la pila.\n";
	while (recorrer != NULL)
	{
		cout << recorrer->valor << "-";
		recorrer = recorrer->siguiente;
	}
	cout << "\n";
}

