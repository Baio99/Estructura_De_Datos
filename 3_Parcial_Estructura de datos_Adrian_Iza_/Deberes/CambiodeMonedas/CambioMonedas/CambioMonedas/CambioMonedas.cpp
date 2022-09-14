/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial Cambio de Monedas      *
*Autor Jonathan Maigua                   *
*Fecha de creacion 30/03/2021            *
*Fecha de modificacion                   *
******************************************/

#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

const int N = 4;
const int INF = 1000000;

int monedas[N] = { 1,25,50,100 };
int memoria[100001];


int cambio(int valor) {
	if (valor < 0) return INF;
	if (valor == 0) return 0;
	if (memoria[valor] != -1) return memoria[valor];

	int res = INF;
	for (int i = 0; i < N; i++)
	{

		res = fmin(res, cambio(valor - monedas[i]));

	}
	return  memoria[valor]=res + 1;
	
}

int main()
{
	int valor=0;

	cout << "PROGRAMA PRINCIPAL CAMBIO DE MONEDA: " << endl;
	cout << "Ingrese la cantidad:"; 
	cin >> valor;
	memset(memoria, -1, sizeof memoria);
	for (int i = 0; i <=valor; i++)
	{
		//cout<< i <<"="<< cambio(i) << endl;
		cout << "El cambio es:" << "=" << cambio(i) << endl;

	}
    
	return 0;
}

