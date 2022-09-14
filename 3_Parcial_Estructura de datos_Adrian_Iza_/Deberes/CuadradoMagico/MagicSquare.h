/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Clase Cuadrado Magico                   *
*Autor Jonathan Maigua y Andrian Iza     *
*Fecha de creacion 25/03/2021            *
*Fecha de modificacion 
******************************************/
#pragma once

class MagicSquare {
public:
	MagicSquare();
	void create(int size);
	void display();
private:
	void fillSinglyEven();
	void fillDoubleEven();
	void fillOdd();
	void siamese(int from, int to);

	int *square;
	int size;
};
