#include "Edad.h"
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

Edad::Edad(){
    mes = 0;
    anio = 0;
    dia = 0;
}

Edad::Edad(int newDia, int newMes, int newAnio) {
    this->dia = newDia;
    this->mes = newMes;
    this->anio = newAnio;
}

int Edad::getDia() {
	return dia;
}
int Edad::getMes() {
	return mes;
}
int Edad::getAnio() {
	return anio;
}

void Edad::setAnio(int newAnio) {
	anio = newAnio;
}

void Edad::setMes(int newMes) {
	mes = newMes;
}
void Edad::setDia(int newDia) {
	dia = newDia;
}

void Edad::calcularEdad(int dia, int mes, int anio) {

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int _year = timePtr->tm_year + 1900;
    int _month = timePtr->tm_mon;
    int _day = timePtr->tm_mday;
    int edad = _year - anio;
    int meses = mes - _month;
    int dias = dia - _day;
    cout << "Tiene " << edad << " anios con " << meses << " meses y " << dias << " dias";

    
    
}
