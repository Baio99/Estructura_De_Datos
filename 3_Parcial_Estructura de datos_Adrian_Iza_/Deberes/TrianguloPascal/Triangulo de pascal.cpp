/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial Triangulo de Pascal    *                    
*Autor Jonathan Maigua,Adrian Iza        *
*Fecha de creacion 25/03/2021            *
*Fecha de modificacion 
******************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
int factorial(int);
int combinacion(int, int);

int main (){
	int n;
	cout<<"\n Programa Principal Triangulo de Pascal n:"<<endl;
	cout<<"\n Ingrese el valor del coeficiente binomial n:"<<endl;
	cin>>n;
	for(int i=0;i<=n;i++){
		cout<<"Fila"<<i<<": ";
		for(int j=0;j<=i;j++){
		
			cout<<combinacion(i,j)<< " ";
		}
		cout<<endl;
	}
}

int factorial(int n){
	int resultado=1;
	for(int i=1;i<=n;i++)
	resultado*=i;
	return resultado;
}
int combinacion (int n , int k){
	return (factorial(n))/(factorial(k)*factorial(n-k));
}
