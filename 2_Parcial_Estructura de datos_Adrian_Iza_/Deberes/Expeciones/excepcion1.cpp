/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Programa princial excepciones            *
* My excepcion                           *
*Autor Adrian Iza                   *
*Fecha de creacion 20/01/2021            *
*Fecha de modificacion 
******************************************/
#include<iostream>

using namespace std;

int main(){
	double numerador,denominador,resl;
	try{
		cout<<"Ingrese valor de Numerador= ";
		cin>>numerador;
		
		cout<<"Ingrese valor de Denominador= ";
		cin>>denominador;
		
		if(denominador==0){
			throw denominador;
		}else
		    cout<<"El resultado es:"<<numerador/denominador<<endl;
		
			
	} catch (double e){
		cout<<"El denominador no es valido:"<<endl;
	}
	system("pause");
	return 0;
}
