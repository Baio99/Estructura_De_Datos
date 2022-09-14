#ifndef EDAD_H
#define EDAD_H

class Edad
{
private:
	int dia;
	int mes;
	int anio;
public:
	Edad();
	Edad(int, int, int);
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	void calcularEdad(int, int, int);
};

#endif
