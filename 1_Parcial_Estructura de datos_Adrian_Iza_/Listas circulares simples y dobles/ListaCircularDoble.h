/******************************************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							*
* Autor: Camila Venegas, Adrian Iza												*
* Fecha de inicio : 17 / 12 / 2020									*
*Fecha de modificacion : 19/ 12 / 2020								*
**
******************************************************************/



#pragma once
#include "NodoDoble.h"
#include <iostream>

template<typename T>
class ListaCircularDoble {
public:
	ListaCircularDoble();
	NodoDoble<T>* insertarFinal(T valor);
	NodoDoble<T>* insertarInicio(T valor);
	NodoDoble<T>* insertarEn(T valor, int indice);
	void eliminar(int indice);
	void eliminarFinal();
	void eliminarInicio();
	NodoDoble<T>* inicial();
	NodoDoble<T>* final();
	bool estaVacio();
	int tamanio();
	void recorrer(void (*callback)(T));

private:
	NodoDoble<T>* cabeza;
	int _tamanio;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
ListaCircularDoble<T>::ListaCircularDoble() {
	_tamanio = 0;
	cabeza = NULL;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::insertarFinal(T valor) {
	NodoDoble<T>* nodo = new NodoDoble<T>(valor);
	
	if (cabeza == NULL) {
		NodoDoble<T>* temporal = nodo;
		nodo->definirSiguiente(nodo);
		nodo->definirAnterior(nodo);
		cabeza = nodo;
		_tamanio++;
		return nodo;
	}

	NodoDoble<T>* ultimo = cabeza->obtenerAnterior();
	nodo->definirSiguiente(cabeza);
	cabeza->definirAnterior(nodo);
	nodo->definirAnterior(ultimo);
	ultimo->definirSiguiente(nodo);
	_tamanio++;

	return nodo;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::insertarInicio(T valor) {
	NodoDoble<T>* nodo = new NodoDoble<T>(valor);
	NodoDoble<T>* ultimo = cabeza->obtenerAnterior();

	nodo->definirSiguiente(cabeza);
	nodo->definirAnterior(ultimo);

	ultimo->definirSiguiente(nodo);
	cabeza->definirAnterior(nodo);
	cabeza = nodo;
	_tamanio++;

	return nodo;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::insertarEn(T valor, int indice) {
	NodoDoble<T>* nodo = new NodoDoble<T>(valor);
	NodoDoble<T>* temporal = cabeza;
	NodoDoble<T>* ultimo = cabeza->obtenerAnterior();

	if (temporal == NULL||indice<0 || (indice + 1) > _tamanio) {
		return NULL;
	} else {
		for (int i = 1; i < indice - 1; i++) {
			temporal = temporal->obtenerSiguiente();
		}

		nodo->definirSiguiente(temporal->obtenerSiguiente());
		nodo->obtenerSiguiente()->definirAnterior(nodo);
		temporal->definirSiguiente(nodo);
		nodo->definirAnterior(temporal);
	}

	return nodo;
}

template<typename T>
int ListaCircularDoble<T>::tamanio() {
	return _tamanio;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::inicial() {
	return cabeza;
}

template<typename T>
NodoDoble<T>* ListaCircularDoble<T>::final() {
	if (cabeza == NULL) {
		return NULL;
	}

	return cabeza->obtenerAnterior();
}

template<typename T>
void ListaCircularDoble<T>::recorrer(void (*callback)(T)) {
	if (_tamanio == 0 || cabeza == NULL) {
		return;
	}

	NodoDoble<T>* nodo = cabeza;

	do {
		callback(nodo->obtenerValor());
		nodo = nodo->obtenerSiguiente();
	} while (nodo != cabeza);
}

template<typename T>
bool ListaCircularDoble<T>::estaVacio() {
	return _tamanio == 0;
}

template<typename T>
void ListaCircularDoble<T>::eliminar(int indice) {
	NodoDoble<T>* nodo;
	NodoDoble<T>* temporal;

	// si la lista esta vacia
	if (cabeza == NULL) {
		return;
	}

	// si la lista no tiene ese indice
	if ((indice + 1) > _tamanio) {
		return;
	}

	// si la lista tiene solo 1 elemento
	if (cabeza->obtenerSiguiente() == cabeza && indice == 0 && _tamanio == 1) {
		free(cabeza);
		cabeza = NULL;
		_tamanio--;
		return;
	}

	// si el indice es la cabeza
	if (indice == 0) {
		nodo = final(); // ultimo
		nodo->definirSiguiente(cabeza->obtenerSiguiente());
		temporal = cabeza->obtenerSiguiente();
		free(cabeza);
		cabeza = temporal;
		_tamanio--;
		return;
	}

	nodo = cabeza;

	for (int i = 0; i < indice - 1; i++) {
		nodo = nodo->obtenerSiguiente();
	}

	temporal = nodo->obtenerSiguiente();
	nodo->definirSiguiente(temporal->obtenerSiguiente());
	free(temporal);
	_tamanio--;
}

template<typename T>
void ListaCircularDoble<T>::eliminarInicio() {
	eliminar(0);
}

template<typename T>
void ListaCircularDoble<T>::eliminarFinal() {
	eliminar(_tamanio - 1);
}