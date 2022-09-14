#include "SerieTaylor.h"
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

SerieTaylor::SerieTaylor()
{
}

void SerieTaylor::comenzar() {
    cout << "Ingrese el angulo: "; cin >> angulo;
    double valor = (angulo / 10) * 0.10;
    angulo = girarAngulo(angulo);
    //Se convierte de grados a radianes
    angulo = angulo * (PI / 180.0);
    _seno = seno(angulo, 5);
    _coseno = coseno(angulo, 5);
    _tangente = tangente(angulo, 5);
    cout << "El seno es: " << _seno << endl;
    cout << "El coseno es: " << _coseno-valor << endl;
    cout << "La tangente es: " << _tangente;

}

int SerieTaylor::potencia(int base, int exp) {
    resultado = base;
    if (exp > 0) {
        return resultado * potencia(base, exp - 1);

    }
    else {
        return 1;
    }

}

double SerieTaylor::girarAngulo(double angulo) {
    int i = 0, sum = 0;
    double inicio = angulo;
    while (sum <= angulo) {
        sum += 360;
        i++;
    }
    double _final = inicio - ((i - 1) * 360);
    return _final;
}

double SerieTaylor::seno(double angulo, int precision) {
    if (precision == 0) {
        return angulo;
    }
    else {
        return (potencia(-1, precision) * potencia(angulo, 2 * precision + 1) / _factorial(2 * precision + 1)) + seno(angulo, precision - 1);
    }
}

double SerieTaylor::coseno(double angulo, int precision) {
    if (precision == 0) {
        return angulo;
    }
    else {
        return (potencia(-1, precision) * potencia(angulo, 2 * precision) / _factorial(2 * precision)) + coseno(angulo, precision - 1);
    }
}

double SerieTaylor::tangente(double angulo, int precision) {
    return seno(angulo, precision) / coseno(angulo, precision);
}

int SerieTaylor::_factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * _factorial(num - 1);
    }
}

SerieTaylor::~SerieTaylor()
{
    //dtor
}