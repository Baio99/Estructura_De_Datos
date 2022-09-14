/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              	*
* Autor: Camila Venegas                                 			*
* Fecha de creación: 13/12/2020                                     *
* Fecha de modificacion: 14/12/2020                                 *
*                                                       			*
******************************************************************/
#pragma once
#include <stdexcept>
using std::runtime_error;
template <typename E>
class Matrix
{
private:
	int rows;
	int columns;
	E** matrix;
public:
	Matrix(int rows, int columns);
	void reservarMemoria();
	~Matrix();
	E getValue(int row, int column);
	void setValue(int row, int column, E value);
	int getRows();
	int getColumns();
};

template <typename E>

Matrix<E>::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
}

template <typename E>
void Matrix<E>::reservarMemoria() {
	matrix = new E * [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new E[columns];
	}
}

template <typename E>
Matrix<E>::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[]matrix;
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
int Matrix<E>::getColumns() {
	return columns;
}
