/***********************************************************************
 * Module:  Pila.cpp
 * Author:  ADRIAN IZA
 * Modified: lunes, 25 de enero de 2021 17:59:13
 * Purpose: Implementation of the class Nodo.h
 ***********************************************************************/

#pragma once
class Nodo
{
public:
    int valor;
    Nodo* siguiente;
    Nodo();

protected:
private:
    
    int obtenerValor();
    void definirValor(int valor);
    Nodo* obtenerSiguiente();
    void  definirSiguiente(Nodo* siguiente);


};
