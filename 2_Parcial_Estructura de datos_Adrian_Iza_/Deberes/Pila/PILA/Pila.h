/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Pila.h
 ***********************************************************************/

#pragma once


#include "Nodo.h"

class Pila
{
public:
	Pila();
	bool estaVacia(void);
	void apilar( int valor);
	int desapilar();
	void mostrar(void);


protected:
private:
	Nodo* cab;
	int tamanio;
	


};