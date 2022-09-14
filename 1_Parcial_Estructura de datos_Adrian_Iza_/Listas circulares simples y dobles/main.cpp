/******************************************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							*
* Autor: Camila Venegas, Adrian Iza 											*
* Fecha de inicio : 17 / 12 / 2020									*
*Fecha de modificacion : 19/ 12 / 2020								*
**
******************************************************************/

#include <iostream>
#include "ListaCircular.h"
#include "ListaCircularDoble.h"
#include "Nodo.h"
#include "Persona.h"
#include "Utils.h"

using namespace std;

void imprimirPersona(Persona* persona) {
	std::cout << persona->to_string() << std::endl;
}

void imprimirNumero(int n) {
	std::cout <<"Los numeros son:\n"<< n << std::endl;
}

int main() {
	ListaCircular<Persona *> personas;
	int opcion;
	int variable,posi;

	ListaCircularDoble<int> numeros;
	
    numeros.insertarFinal(1);
	numeros.insertarFinal(2);
	numeros.insertarFinal(3);
	numeros.insertarFinal(4);
	numeros.insertarFinal(5);
	numeros.recorrer(imprimirNumero);

	system("pause");

	std::cout << std::endl << std::endl;

	do {
		system("cls");

		std::cout << "1: agregar persona" << std::endl;
		std::cout << "2: eliminar persona" << std::endl;
		std::cout << "3: ver todas las personas" << std::endl;
		std::cout << "4: salir" << std::endl;

		std::cout << "seleccione una opcion: ";
		std::cin >> opcion;

		if (std::cin.fail() || opcion > 4 || opcion < 1) {
			std::cin.clear();
			std::cin.ignore(9999, '\n');
			continue;
		}

		std::cout << std::endl << std::endl;

		if (opcion != 1 && opcion != 4 && personas.tamanio() == 0) {
			std::cout << "No existen personas registradas" << std::endl;
			std::cout << std::endl << std::endl;
			system("pause");
			continue;
		}

		if (opcion == 1) {
			std::string nombre;
			std::string apellido;
			std::string cedula;
			int edad;

			std::cin.clear();
			std::cin.ignore(9999, '\n');

			std::cout << "ingrese el nombre: ";
			std::getline(std::cin, nombre);

			std::cout << "ingrese el apellido: ";
			std::getline(std::cin, apellido);

			std::cout << "ingrese la cedula: ";
			std::getline(std::cin, cedula);

			std::cout << "ingrese la edad: ";
			std::cin >> edad;

			Persona *persona = new Persona(nombre, apellido, cedula, edad);
			personas.insertarFinal(persona);
			persona->setCorreo(generarEmailUnico(personas, *persona, "espe.edu.ec"));

			std::cout << "Persona agregada con exito!" << std::endl;
		} else if (opcion == 2) {
			Nodo<Persona *>* cabeza = personas.inicial();
			Nodo<Persona *>* nodo = cabeza;
			int i = 0;
			int seleccionado;

			do {
				std::cout << ++i << ": " << nodo->obtenerValor()->to_string() << std::endl;
				nodo = nodo->obtenerSiguiente();
			} while (nodo != cabeza);

			do {
				std::cout << "seleccione la persona a eliminar: ";
				std::cin >> seleccionado;

				if (seleccionado < 1 || seleccionado > personas.tamanio()) {
					std::cin.clear();
					std::cin.ignore(9999, '\n');
					continue;
				} else {
					break;
				}
			} while (true);

			personas.eliminar(seleccionado - 1);
			std::cout << "persona eliminada con exito" << std::endl;
		} else if (opcion == 3) {
			personas.recorrer(imprimirPersona);
		}

		std::cout << std::endl << std::endl;
		system("pause");
	} while (opcion != 4);

}
