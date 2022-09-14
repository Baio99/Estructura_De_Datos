#include "Persona.h"

Persona::Persona() {
	this->nombre = "";
	this->apellido = "";
	this->cedula = "";
	this->edad = 0;
}

Persona::Persona(std::string nombre, std::string apellido, std::string cedula, int edad) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->cedula = cedula;
	this->edad = edad;
}

std::string Persona::getNombre() {
	return nombre;
}

void Persona::setNombre(std::string nombre) {
	this->nombre = nombre;
}

std::string Persona::getApellido() {
	return apellido;
}

void Persona::setApellido(std::string apellido) {
	this->apellido = apellido;
}

std::string Persona::getCedula() {
	return cedula;
}

void Persona::setCedula(std::string cedula) {
	this->cedula = cedula;
}

std::string Persona::getCorreo() {
	return correo;
}

void Persona::setCorreo(std::string correo) {
	this->correo = correo;
}

int Persona::getEdad() {
	return edad;
}

void Persona::setEdad(int edad) {
	this->edad = edad;
}

std::string Persona::to_string() {
	return nombre + " " + apellido + " (" + correo + ")" + " [" + cedula + "]";
}