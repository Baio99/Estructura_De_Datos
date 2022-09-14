/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial para calcular el valor *
absoluto de un numero                    *
*Autor Jonathan Maigua y Andrian Iza     *
*Fecha de creacion 25/03/2021            *
*Fecha de modificacion 
******************************************/
#include "MagicSquare.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>

MagicSquare::MagicSquare() {
	square = 0;
}

void MagicSquare::create(int size) {
	if (square) {
		delete[] square;
	}

	square = new int[size * size];
	this->size = size;
	
	if (size <= 0 || size == 2) {
		throw "Tamaño no válido para el cuadrado mágico ";
		return;
	}

	if (size % 4 != 0) {
		memset(square, 0, size * size * sizeof(int));
	}

	if (size % 4 == 0) {
		fillDoubleEven();
	} else if (size % 2 == 0) {
		fillSinglyEven();
	} else {
		fillOdd();
	}
}


void MagicSquare::siamese(int from, int to) {
	int oneSide = to - from, curCol = oneSide / 2, curRow = 0, count = oneSide * oneSide, s = 1;

	while (count > 0) {
		bool done = false;
		while (false == done) {
			if (curCol >= oneSide) curCol = 0;
			if (curRow < 0) curRow = oneSide - 1;
			done = true;
			if (square[curCol + size * curRow] != 0) {
				curCol -= 1; curRow += 2;
				if (curCol < 0) curCol = oneSide - 1;
				if (curRow >= oneSide) curRow -= oneSide;

				done = false;
			}
		}

		square[curCol + size * curRow] = s;
		s++; count--; curCol++; curRow--;
	}
}

void MagicSquare::fillSinglyEven() {
	int n = this->size / 2,
		ns = n * size,
		size2 = size * size,
		add1 = size2 / 2,
		add3 = size2 / 4,
		add2 = 3 * add3;

	siamese(0, n);

	for (int r = 0; r < n; r++) {
		int row = r * size;
		for (int c = n; c < size; c++) {
			int m = square[c - n + row];

			square[c + row] = m + add1;
			square[c + row + ns] = m + add3;
			square[c - n + row + ns] = m + add2;
		}
	}

	int lc = (size - 2) / 4, co = size - (lc - 1);
	for (int r = 0; r < n; r++) {
		int row = r * size;
		for (int c = co; c < size; c++) {
			square[c + row] -= add3;
			square[c + row + ns] += add3;
		}
	}

	for (int r = 0; r < n; r++) {
		int row = r * size;
		for (int c = 0; c < lc; c++) {
			int cc = c;
			if (r == lc) cc++;
			square[cc + row] += add2;
			square[cc + row + ns] -= add2;
		}
	}
}

void MagicSquare::fillOdd() {
	int sx = size / 2, sy = 0, c = 0;
	while (c < size * size)
	{
		if (!square[sx + sy * size])
		{
			square[sx + sy * size] = c + 1;

			if (++sx == size) sx = 0;
			if (--sy < 0) sy = size - 1;
			c++;
		}
		else
		{
			if (--sx < 0) sx = size - 1;
			if (++sy == size) sy = 0;
			if (++sy == size) sy = 0;
		}
	}
}

void MagicSquare::display() {
	std::cout << "Cuadrado magico de " << size << "x" << size << std::endl;

	if (size == 1) {
		std::cout << 1 << std::endl;
		return;
	}

	std::ostringstream cvr; 
	cvr << size * size;
	int l = cvr.str().size();

	for (int y = 0; y < size; y++) {
		int yy = y * size;
		for (int x = 0; x < size; x++) {
			std::cout << std::setw(l + 2) << square[yy + x];
		}

		std::cout << "\n";
	}

	std::cout << "\n\n";
}

void MagicSquare::fillDoubleEven() {
	static const bool tempAll[4][4] = { { 1, 0, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 1, 0, 0, 1 } };
	int i = 0;

	for (int curRow = 0; curRow < size; curRow++) {
		for (int curCol = 0; curCol < size; curCol++) {
			square[curCol + size * curRow] = tempAll[curRow % 4][curCol % 4] ? i + 1 : size * size - i;
			i++;
		}
	}
}
