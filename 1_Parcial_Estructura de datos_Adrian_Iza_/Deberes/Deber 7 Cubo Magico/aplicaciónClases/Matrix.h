#pragma once
#include <stdexcept>
#include "stdlib.h"
#include <iostream>
using std::runtime_error;
using namespace std;
template <typename E>
class Matrix
{
private:
	int rows;
	int columns;
	E** matrix;
public:
	Matrix(int rows, int colums);
	~Matrix();
	void reservamem(int rows, int colums);
	E getValue(int row, int column);
	void setValue(int row, int column, E value);
	int getRows();
	int getColumns();
	void cuboMagico(int tamanio);
};


template <typename E>
Matrix<E>::Matrix(int rows, int colums) {
	this->rows = rows;
	this->columns = colums;
}

template <typename E>
Matrix<E>::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[]matrix;
}

template <typename E>
void Matrix<E>:: reservamem(int rows, int colums) {
	matrix = new E * [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new E[colums];
	}
}

template <typename E>
E Matrix<E>:: getValue(int row, int column) {
	if ((row < 0) || (row > rows))
		throw runtime_error("Fila invalida");
	if (column<0 || column>columns)
		throw runtime_error("Columna invalida");
	return matrix[row][column];
}

template <typename E>
void Matrix<E>::setValue(int row, int column, E value) {
	if (row<0 || row>rows)
		throw runtime_error("Fila invalida");
	if (column<0 || column>columns)
		throw runtime_error("Columna invalida");
	matrix[row][column] = value;
}

template <typename E>
int Matrix<E>:: getRows() {
	return rows;
}

template <typename E>
int Matrix<E>:: getColumns() {
	return columns;
}

template <typename E>
void Matrix<E>::cuboMagico(int tamanio) {
	int contador = 0;
	int x = 0;
	int y = 0;
	int vx = 0;
	int vy = 0;
	int limite = tamanio * tamanio;
	int limitex = tamanio - 1;
	int limitey = tamanio - 1;
	x = tamanio / 2;
	y = 0;
	for (contador = 1; contador <= limite; contador++)
	{
		setValue(y, x, contador);
		vx = x;
		vy = y;

		x++;
		if (x > limitex)
			x = 0;
		y--;
		if (y < 0) y = limitey;
		if (getValue(y, x) > 0)
		{
			x = vx;
			y = vy + 1;
		}
	}
	cout << "\nCUBO MAGICO \n";
	for (x = 0; x < tamanio; x++)
	{
		for (y = 0; y < tamanio; y++)
		{
			cout << getValue(x, y) << " ";
		}
		cout << "\n";
	}
}

