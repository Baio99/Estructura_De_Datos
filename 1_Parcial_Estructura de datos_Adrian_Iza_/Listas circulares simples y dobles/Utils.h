#pragma once
#include <string>
#include <algorithm>
#include "ListaCircular.h"
#include "Persona.h"

static inline std::string generarEmailUnico(
	ListaCircular<Persona *> & lista, Persona persona, std::string dominio);
inline std::string generarIdEmail(Persona persona);
static inline bool validarCI(std::string ci);
static inline void str_ltrim(std::string& s);
static inline void str_rtrim(std::string& s);
static inline void str_trim(std::string& s);

static inline std::string generarEmailUnico(
	ListaCircular<Persona *> & lista, Persona persona, std::string dominio) {
	std::string identificador = generarIdEmail(persona);
	int repetidos = 0;
	bool repetido = false;

	do {
		if (repetidos > 0) {
			char sufijo[5] = { '\0' };
			snprintf(sufijo, 5, "%d", repetidos + 1);
			identificador = generarIdEmail(persona) + std::string(sufijo);
		}

		bool existe = false;
		Nodo<Persona *>* cabeza = lista.inicial();
		Nodo<Persona *>* p = cabeza;

		do {
			Persona *persona2 = p->obtenerValor();
			
			if (persona.getCedula() == persona2->getCedula()
				&& generarIdEmail(*persona2) == identificador) {
				existe = true;
				break;
			}

			p = p->obtenerSiguiente();
		} while (p != cabeza);

		if (repetido) {
			repetidos++;
		}
	} while (repetido);

	std::string email = identificador + "@" + dominio;

	for (int i = 0; i < email.size(); i++) {
		char c = email.at(i);
		c = std::tolower(c);
		email[i] = c;
	}

	return email;
}

static inline bool validarCI(std::string ci) {
	str_trim(ci);
	std::string cedula = ci;

	if (cedula.size() != 10) {
		return false;
	}

	bool valido = true;

	for (int i = 0; i < ci.size(); i++) {
		char c = ci.at(i);
		
		if (std::isdigit(c)) {
			valido = false;
			break;
		}
	}

	// la cedula es solo numerica
	if (!valido) {
		return false;
	}

	int lastDigit = cedula.at(cedula.size() - 1) - '0';
	int digit;
	int sumPairs = 0;
	int oddSum = 0;

	for (int i = 0; i < 9; i++) {
		digit = cedula.at(i) - '0';

		if ((i + 1) % 2 == 0) {
			sumPairs += digit;
		} else {
			oddSum += (digit * 2) > 9 ? (digit * 2) - 9 : (digit * 2);
		}
	}

	int total = sumPairs + oddSum;
	int higher = (10 - (total % 10)) + total;

	if ((total % 10) == 0) {
		return lastDigit == 0;
	}

	return lastDigit == (higher - total);
}

inline std::string generarIdEmail(Persona persona) {
	std::string apellido = persona.getApellido();
	std::string output = std::string(1, persona.getNombre().at(0)) + apellido;

	for (int i = 0; i < output.size(); i++) {
		char c = output.at(i);
		c = std::tolower(c);

		if (c == ' ') {
			c = '_';
		}
		
		output[i] = c;
	}

	return output;
}

bool space_comparator(unsigned char ch) {
	return !std::isspace(ch);
}

static inline void str_ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), space_comparator));
}

static inline void str_rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), space_comparator).base(), s.end());
}

static inline void str_trim(std::string& s) {
	str_ltrim(s);
	str_rtrim(s);
}
