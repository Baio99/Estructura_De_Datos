#pragma once
class SerieTaylor
{
public:
    SerieTaylor();
    void comenzar();
    int potencia(int, int);
    int _factorial(int);
    double seno(double, int);
    double coseno(double, int);
    double tangente(double, int);
    double girarAngulo(double);
    virtual ~SerieTaylor();

protected:

private:
    int resultado;
    double _seno, _coseno, _tangente, angulo;
    double PI = 3.14159;
};

