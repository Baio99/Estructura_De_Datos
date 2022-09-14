#include <cassert>

int suma(int a, int b) {
    return a + b;
}

float suma(float a, float b) {
    return a + b;
}

double suma(double a, double b) {
    return a + b;
}

int resta(int a, int b) {
    return suma(a, -b);
}

float resta(float a, float b) {
    return suma(a, -b);
}

double resta(double a, double b) {
    return suma(a, -b);
}

int multiplicacion(int a, int b) {
    return a * b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

int division(int dividendo, int divisor) {
    assert(divisor != 0 && "division por cero");
    return dividendo / divisor;
}

float division(float dividendo, float divisor) {
    assert(divisor != 0 && "division por cero");
    return dividendo / divisor;
}

double division(double dividendo, double divisor) {
    assert(divisor != 0 && "division por cero");
    return dividendo / divisor;
}