/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Cola
 ***********************************************************************/

#pragma once
class Nodo;

#include "Nodo.h"

class Cola
{
public:
	Cola();
	bool estaVacia(void);
	void encolar(int valor);
	int desencolar();
	void mostrar(void);
	int  tamanio();


protected:
private:
	Nodo* cabeza;
	Nodo* cola;



};
