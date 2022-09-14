/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Nodo.cpp
 ***********************************************************************/

#include "Nodo.h"


Nodo::Nodo() {

	this->siguiente = siguiente;
	this->valor = valor;
}

int Nodo::obtenerValor(void)
{
	return valor;
}

void Nodo::definirValor(int valor)
{
	this->valor = valor;
}

Nodo* Nodo::obtenerSiguiente(void)
{
	return siguiente;
}

void Nodo::definirSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}

