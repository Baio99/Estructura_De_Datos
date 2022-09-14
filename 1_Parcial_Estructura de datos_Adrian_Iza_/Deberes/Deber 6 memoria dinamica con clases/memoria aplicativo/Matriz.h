#pragma once
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;
template <typename T>
class Matriz
{
private:
	T** filaColumna;
	T dimension;
public:
	Matriz();
	Matriz(T** fiCo, T newDimension);
	void ingreso(T** fiCo, int d);
	void proceso(T** fiCo1, T** fiCo2, T** fiCo3, int d);
	void imprimir(T** fiCo, int d);
	void encerar(T** fiCo, int d);
	T** memoria(int d);

};

template <typename T>
Matriz<T>::Matriz() {
	
}
template <typename T>
Matriz<T>::Matriz(T** fiCo, T newDimension) {
	filaColumna = fiCo;
	dimension = newDimension;
}
template <typename T>
void Matriz<T>::ingreso(T** fiCo, int d) {
	cout << "Ingrese los elementos de la matriz:" << endl;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			cin>> (*(*(fiCo + i) + j));
		}
	}
}
template <typename T>
void Matriz<T>::imprimir(T** fiCo, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			printf("%d", *(*(fiCo + 1) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}

template <typename T>
void Matriz<T>::encerar(T** fiCo, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(fiCo + i) + j) = 0;
		}
	}
}
template <typename T>
void Matriz<T>::proceso(T** fiCo1, T** fiCo2, T** fiCo3, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			for (int h = 0; h < d; h++) {
				*(*(fiCo3 + i) + j) = *(*(fiCo3 + i) + j) + (*(*(fiCo1 + i) + h)) * (*(*(fiCo2 + h) + j));
			}
		}
	}
}
template <typename T>
T** Matriz<T>::memoria(int d) {
	int j;
	T** mat;
	mat=(T **)malloc(d*sizeof(T*));
	//mat = new T*();
	for (j = 0; j < d; j++) {
		*(mat + j) = (T*)malloc (d * sizeof(T));
	}

	return mat;

}

