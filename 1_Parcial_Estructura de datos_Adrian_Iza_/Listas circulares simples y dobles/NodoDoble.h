#pragma once

template <typename T>
class NodoDoble {
public:
	NodoDoble(T valor, NodoDoble<T>* anterior, NodoDoble<T>* siguiente);
	NodoDoble(T valor);
	T obtenerValor();
	void definirValor(T valor);
	NodoDoble<T>* obtenerSiguiente();
	NodoDoble<T>* obtenerAnterior();
	void definirSiguiente(NodoDoble<T>* siguiente);
	void definirAnterior(NodoDoble<T>* anterior);

private:
	T valor;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
NodoDoble<T>::NodoDoble(T valor, NodoDoble<T>* anterior, NodoDoble<T>* siguiente) {
	this->valor = valor;
	this->anterior = anterior;
	this->siguiente = siguiente;
}

template<typename T>
NodoDoble<T>::NodoDoble(T valor) {
	this->valor = valor;
}

template<typename T>
T NodoDoble<T>::obtenerValor() {
	return valor;
}

template<typename T>
void NodoDoble<T>::definirValor(T valor) {
	this->valor = valor;
}

template<typename T>
NodoDoble<T>* NodoDoble<T>::obtenerSiguiente() {
	return siguiente;
}

template<typename T>
void NodoDoble<T>::definirSiguiente(NodoDoble<T>* siguiente) {
	this->siguiente = siguiente;
}

template<typename T>
NodoDoble<T>* NodoDoble<T>::obtenerAnterior() {
	return anterior;
}

template<typename T>
void NodoDoble<T>::definirAnterior(NodoDoble<T>* anterior) {
	this->anterior = anterior;
}