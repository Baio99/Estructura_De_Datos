#pragma once
#include "Nodo.h"
#include <iostream>

template<typename T>
class ListaCircular {
public:
	ListaCircular();
	Nodo<T>* insertarFinal(T valor);
	Nodo<T>* insertarInicio(T valor);
	Nodo<T>* insertarEn(T valor, int indice);
	void eliminar(int indice);
	void eliminarFinal();
	void eliminarInicio();
	Nodo<T>* inicial();
	Nodo<T>* final();
	bool estaVacio();
	int tamanio();
	void recorrer(void (*callback)(T));

private:
	Nodo<T>* cabeza;
	int _tamanio;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
ListaCircular<T>::ListaCircular() {
	_tamanio = 0;
	cabeza = NULL;
}

template<typename T>
Nodo<T>* ListaCircular<T>::insertarFinal(T valor) {
	Nodo<T>* nodo = new Nodo<T>(valor);
	Nodo<T>* ultimo = final();

	if (ultimo == NULL) {
		cabeza = nodo;
		ultimo = cabeza;
	}

	ultimo->definirSiguiente(nodo);
	nodo->definirSiguiente(cabeza);
	_tamanio++;

	return nodo;
}

template<typename T>
Nodo<T>* ListaCircular<T>::insertarInicio(T valor) {
	cabeza = insertarFinal(valor);
	return cabeza;
}

template<typename T>
Nodo<T>* ListaCircular<T>::insertarEn(T valor, int indice) {
	Nodo<T>* nodo;
	Nodo<T>* actual;

	if ((indice + 1 ) > _tamanio) {
		if (_tamanio == 0) {
			return insertarFinal(valor);
		}

		// TODO: arrojar una excepcion aqui podria ser una mejor opcion
		return NULL;
	}

	nodo = new Nodo<T>(valor);
	actual = cabeza;

	for (int i = 0; i < indice - 1; i++) {
		actual = actual->obtenerSiguiente();
	}

	nodo->definirSiguiente(actual->obtenerSiguiente());
	actual->definirSiguiente(nodo);
	_tamanio++;

	return nodo;
}

template<typename T>
int ListaCircular<T>::tamanio() {
	return _tamanio;
}

template<typename T>
Nodo<T>* ListaCircular<T>::inicial() {
	return cabeza;
}

template<typename T>
Nodo<T>* ListaCircular<T>::final() {
	if (cabeza == NULL) {
		return NULL;
	}

	Nodo<T>* ultimo = cabeza;

	while (ultimo->obtenerSiguiente() != cabeza) {
		ultimo = ultimo->obtenerSiguiente();
	}

	return ultimo;
}

template<typename T>
void ListaCircular<T>::recorrer(void (*callback)(T)) {
	if (_tamanio == 0 || cabeza == NULL) {
		return;
	}

	Nodo<T>* nodo = cabeza;

	do {
		callback(nodo->obtenerValor());
		nodo = nodo->obtenerSiguiente();
	} while (nodo != cabeza);
}

template<typename T>
bool ListaCircular<T>::estaVacio() {
	return _tamanio == 0;
}

template<typename T>
void ListaCircular<T>::eliminar(int indice) {
	Nodo<T>* nodo;
	Nodo<T>* temporal;

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
void ListaCircular<T>::eliminarInicio() {
	eliminar(0);
}

template<typename T>
void ListaCircular<T>::eliminarFinal() {
	eliminar(_tamanio - 1);
}