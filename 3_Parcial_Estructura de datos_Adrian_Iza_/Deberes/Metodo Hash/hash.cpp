/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial funcion hash           *
RESTAS SUCESIVAS  y ARITMETICA MODULAR   *
*Autor Adrian Iza                  *
*Fecha de creacion 30/03/2021            *
*Fecha de modificacion                   *
******************************************/
#include<iostream>

using namespace std;
int hash_restas_sucesivas (int n,int size);
int hash_Modular(int n, int size);

int main(){
	
		int size=4,n,clave,clave2;
	
	printf("\t PROGRAMA\n");
	
	//cout<<"Ingrese tamaño del vector:";
	//cin>>size;
	
	cout<<"Ingrese un numero entero:";
	cin>> n;
	clave= hash_restas_sucesivas(n,size);
	
	cout<<"RESTAS SUCESIVAS:"<<endl;
	cout<<"El numero es:"<<n<<endl<<"La clave es:" <<clave<<endl;
	
	cout<<"ARITMETICA MODULAR:"<<endl;
	clave2= hash_Modular(n,size);

	cout<<"El numero es:"<<n<<endl<<"La clave es:" <<clave<<endl;
	
	
	
	return 0;
}
int hash_restas_sucesivas (int n,int size){	
int cont;
 if(n==0 || n< size)
 return n;
 else
  n=n-size;
 while(n>=0){
 	cont=cont+1;
 	n=n-size;
 }
 return hash_restas_sucesivas(cont,size);
}
int hash_Modular(int n, int size){
	if(n<size){
		return n;
	}else {
		n=n%size;
		hash_Modular(n,size);
	}
}
