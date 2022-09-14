/******************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE *
* Prorama principal para crear clase      *
* Adrian Iza y jhonathan maigua					  *
* Fecha de creación 10/02/2021			  *
* Fecha de modificación 15/02/2021	                  *
******************************************/


#include <iostream>
//#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include "Ordenamiento.h"
//#include <ctime>

int main(){
	int op=0;
	int n, i=1;
	Persona p;
	//archivo.open("informacion.txt", ios::out);
	//archivo<<"\t\t\t\t\tLISTADO"<<endl;
	
	//time_t now = time(0);
	//tm * time = localtime(&now);
	//int year=1900+time->tm_year;
	//int h=time->tm_hour;
	//int m=time->tm_min;
	//int s=time->tm_sec;
	//string nombre_bcp;
	//cout<<"Nombre del backup"<<endl;
	//getline(cin, nombre_bcp);
	//backup.open(nombre_bcp.c_str(), ios::out);
	//backup<<"\t\t\t\t\tLISTADO"<<endl;
	//backup<<year<<"/"<<h<<":"<<m<<":"<<s<<endl;
do{	
	cout<<"\t\t\t\t\t------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t||1. Insertar  		                ||"<<endl;
	cout<<"\t\t\t\t\t||2. Listado    		 	||"<<endl;
	cout<<"\t\t\t\t\t||3. Ordenar  por cedula  		 	||"<<endl;
	cout<<"\t\t\t\t\t||4. Ordenar  por Edad		 	||"<<endl;
	cout<<"\t\t\t\t\t||5. Ordenar  por Nombre 		 	||"<<endl;
	cout<<"\t\t\t\t\t||6. Mostrar Lista Ordenada    		||"<<endl;
	cout<<"\t\t\t\t\t||7. Eliminar    		||"<<endl;
	cout<<"\t\t\t\t\t||8. Salir      		 	||"<<endl;
	cout<<"\t\t\t\t\t------------------------------------------"<<endl;
	cout<<"\t\t\t\t\tEscogar una opcion:";
	cin>>op;
	switch (op){
		case 1:
			system("cls");
			//archivo<<"PESONA "<<i<<": "<<endl;
			cout<< "\t\t\t\t\tInsertar un numero al inicio"<<endl;
			p.Insertar();
			i++;
			n++;
			break;
		case 2:
			system("cls");
			cout<<"\t\t\t\t\tMostrar lista"<<endl;
			p.listado(n);
			break;
		case 3:
			system("cls");
			p.Ordenamiento(n);
			cout<< "\t\t\t\t\tOrdenado"<<endl;
			break;
		case 4:
			system("cls");
			p.OrdenamientoEdad(n);
			cout<< "\t\t\t\t\tOrdenado"<<endl;
			break;
		case 5: 
			system("cls");
			p.OrdenamientoNom(n);
			cout<< "\t\t\t\t\tOrdenado"<<endl;
			break;
		
		case 6:
			system("cls");
			p.listado(n);
			break;
		case 7:
			system("cls");
			cout<<"\t\t\t\t\tEliminar..."<<endl;
			p.Eliminar();
			break;
		case 8:
			cout<<"\t\t\t\t\tGracias..."<<endl;
			break;
	}
}while(op != 8);
	system("pause");
	return 0;
}

