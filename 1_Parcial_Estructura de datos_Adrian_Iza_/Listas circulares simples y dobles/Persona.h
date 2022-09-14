#pragma once
#include <string>

class Persona {
public:
	Persona();
	Persona(std::string nombre, std::string apellido, std::string cedula, int edad);
	std::string getNombre();
	void setNombre(std::string nombre);
	std::string getApellido();
	void setApellido(std::string apellido);
	std::string getCedula();
	void setCedula(std::string cedula);
	std::string getCorreo();
	void setCorreo(std::string correo);
	int getEdad();
	void setEdad(int edad);

	std::string to_string();
private:
	std::string nombre;
	std::string apellido;
	std::string cedula;
	std::string correo;
	int edad;
};