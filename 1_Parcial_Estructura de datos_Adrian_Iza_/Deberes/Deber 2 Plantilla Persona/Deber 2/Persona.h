#pragma once
#include <iostream>
using namespace std;
template<typename T>

class Persona
{
private:
	
	T nombre;
	T apellido;
	T telefono;
	T direccion;
	T sueldo;
public:
	Persona();
	Persona(T, T, T, T,T);
	T getNombre();
	T getTelefono();
	T getApellido();
	T getDireccion();
	T getSueldo();
	void setNombre(T);
	void setApellido(T);
	void setTelefono(T);
	void setDireccion(T);
	void setSueldo(T);
	void toString();

};

template<typename T>
Persona<T>::Persona(){}

template<typename T>
Persona<T>::Persona(T newNombre, T newApellido, T newTelefono, T newDireccion,T newSueldo) {
	this->nombre = newNombre;
	this->apellido = newApellido;
	this->telefono = newTelefono;
	this->apellido = newDireccion;
	this->sueldo = newSueldo;
}

template<typename T>
T Persona<T>::getNombre() {
	return nombre;
}
template<typename T>
T Persona<T>::getApellido() {
	return apellido;
}

template<typename T>
T Persona<T>::getTelefono() {
	return telefono;
}

template<typename T>
T Persona<T>::getDireccion() {
	return direccion;
}
template<typename T>
T Persona<T>::getSueldo() {
	return sueldo;
}

template <typename T>
void Persona<T>::setNombre(T newNombre) {
	nombre = newNombre;
}
template <typename T>
void Persona<T>::setApellido(T newApellido) {
	apellido = newApellido;
}
template <typename T>
void Persona<T>::setTelefono(T newTelefono) {
	telefono = newTelefono;
}

template <typename T>
void Persona<T>::setDireccion(T newDireccion) {
	direccion = newDireccion;
}

template <typename T>
void Persona<T>::setSueldo(T newSueldo) {
	sueldo = newSueldo;
}

template <typename T>
void Persona<T>::toString() {
	cout << "\nNombre:" << getNombre() << endl;
	cout << "Apellido:" << getApellido() << endl;
	cout << "Direccion:" << getDireccion() << endl;
	cout << "Telefono:" << getTelefono() << endl;
	cout << "Sueldo:" << getSueldo() << endl;
}





