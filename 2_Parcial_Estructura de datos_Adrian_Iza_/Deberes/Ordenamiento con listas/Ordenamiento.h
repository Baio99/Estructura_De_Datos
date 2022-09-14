#include <iostream>
//#include <fstream>
#include <stdlib.h>
#include <locale.h>
//#include <ctime>

using namespace std;

//ofstream archivo;
//ofstream backup;
struct nodo{
	string datos;
	int dato;
	nodo* siguiente;
}*primero, *ultimo, *primeroN, *ultimoN, *primeroA, *ultimoA, *primeroE, *ultimoE;

class Persona{
	private:
		string nombre;
		string apellido;
		int cedula;
	public:
		void Insertar();
		void listado(int tamanio);
		void Ordenamiento(int tamanio);
		void OrdenamientoEdad(int tamanio);
		void OrdenamientoNom(int tamanio);
		void Eliminar();
};

void Persona::Insertar(){
	
	setlocale(LC_CTYPE, "Spanish");
	
	nodo* nuevo=new nodo();
	nodo* nombre_persona= new nodo();
	nodo* apellido_persona= new nodo();
	nodo* edad_persona=new nodo();

	int anio,mes,dia;
	int nacimiento, edad;
	    
	cout<<"\t\t\t\t\tIngrese el nombre          : ";
	cin>>nombre;
	nombre_persona->datos=nombre;;
	//archivo<<"Nombre y apellido: "<<nombre;
	//backup<<"Nombre y apellido: "<<nombre;
	
	cout<<"\t\t\t\t\tIngrese el apellido        : ";
	cin>> apellido;
	apellido_persona->datos=apellido;
	//archivo<<" "<<apellido<<endl;
	//backup<<" "<<apellido<<endl;

	cout<<"\t\t\t\t\tIngrese el numero de cedula: ";
	cin >>cedula;
	nuevo->dato=cedula;
	//archivo<<"Cedula: "<<cedula<<endl;
	//backup<<"Cedula: "<<cedula<<endl;
	
	cout<<"\t\t\t\t\tIngrese fecha de nacimiento: "<<endl;
	cin>>anio;
	cin>>mes;
	cin>>dia;
	
	edad=2021-anio;
	nacimiento= (anio*10000)+(mes*100)+dia;
	cout<<"\t\t\t\t\tTiene la edad de           : ";
	cout<<edad<<"años"<<endl;
	edad_persona->dato=edad;
	//archivo<<"Edad: "<<edad<<endl;
	//backup<<"Edad: "<<edad<<endl;
	
	if(primero == NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		
		primeroN=nombre_persona;
		primeroN->siguiente=NULL;
		
		primeroA=apellido_persona;
		primeroA->siguiente=NULL;
		
		primeroE=edad_persona;
		primeroE->siguiente=NULL;
		
		ultimo=nuevo;
		ultimoN=nombre_persona;
		ultimoA=apellido_persona;
		ultimoE=edad_persona;
		
	}else{
		
		ultimo->siguiente=nuevo;
		ultimoN->siguiente=nombre_persona;
		ultimoA->siguiente=apellido_persona;
		ultimoE->siguiente=edad_persona;
		
		nuevo->siguiente=NULL;
		nombre_persona->siguiente=NULL;
		apellido_persona->siguiente=NULL;
		edad_persona->siguiente=NULL;
		
		ultimo=nuevo;
		ultimoN=nombre_persona;
		ultimoA=apellido_persona;
		ultimoE=edad_persona;	
	}
}

void Persona::listado(int tamanio){
	nodo* lista=new nodo();
	nodo* listaA=new nodo();
	nodo* listaN=new nodo();
	nodo* listaE=new nodo();

	lista=primero;
	listaN=primeroN;
	listaA=primeroA;
	listaE=primeroE;
	
	if(primero != NULL){
		cout<<"\t\t\t\t\t-----------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t-N°--CEDULA--------NOMBRE Y APELLIDO--------EDAD-----"<<endl;
		cout<<"\t\t\t\t\t-----------------------------------------------------"<<endl;
		while(lista != NULL){
			cout<< "\t\t\t\t\t-|"<<tamanio<<"|| "<<lista->dato <<" || "<<listaN->datos<<" "<<listaA->datos<<"   	||"<<listaE->dato<<" AÑOS ||-"<< endl;
			lista  = lista->siguiente;
			listaN = listaN->siguiente;
			listaA = listaA->siguiente;
			listaE = listaE->siguiente;	
		}
		cout<<"\t\t\t\t\t-----------------------------------------------------"<<endl;
		
	}
	
}

void Persona::Ordenamiento(int tamanio){
	nodo* aux=new nodo();
	nodo* auxN=new nodo();
	nodo* auxA=new nodo();
	nodo* auxE=new nodo();
	
	int ints, ayuda, ayudaE;
	string ayudaN, ayudaA;
	bool band;
	
	ints=tamanio;
	
	while(ints>1){
		ints=(ints/2);
		band=true;
		while(band==true){
			band=false;
			aux=primero;
			auxN=primeroN;
			auxA=primeroA;
			auxE=primeroE;
			while(aux->siguiente!=NULL){//aqui utilizamos el auxiliar de la cedula, que recorrerar todos los datos del nodo por cedula
				
				if(aux->dato > aux->siguiente->dato){
					ayuda=aux->dato;
					aux->dato = aux->siguiente->dato;
					aux->siguiente->dato=ayuda;	
					
					ayudaE=auxE->dato;
					auxE->dato = auxE->siguiente->dato;
					auxE->siguiente->dato=ayudaE;
				
					ayudaN=auxN->datos;
					auxN->datos = auxN->siguiente->datos;
					auxN->siguiente->datos=ayudaN;
				
					ayudaA=auxA->datos;
					auxA->datos = auxA->siguiente->datos;
					auxA->siguiente->datos=ayudaA;
					
					band=true;
				}
				aux=aux->siguiente;
				
			}
		}
	}
}

void Persona::OrdenamientoEdad(int tamanio){
	nodo* aux=new nodo();
	nodo* auxN=new nodo();
	nodo* auxA=new nodo();
	nodo* auxE=new nodo();
	
	int ints, ayuda, ayudaE;
	string ayudaN, ayudaA;
	bool band;
	
	ints=tamanio;
	
	while(ints>1){
		ints=(ints/2);
		band=true;
		while(band==true){
			band=false;
			aux=primero;
			auxN=primeroN;
			auxA=primeroA;
			auxE=primeroE;
			
			while(auxE->siguiente!=NULL){//aqui utilizamos el auxiliar de la edad, que recorrerar todos los datos del nodo por edad
				
				if(auxE->dato > auxE->siguiente->dato){
					ayuda=aux->dato;
					aux->dato = aux->siguiente->dato;
					aux->siguiente->dato=ayuda;	
					
					ayudaE=auxE->dato;
					auxE->dato = auxE->siguiente->dato;
					auxE->siguiente->dato=ayudaE;
				
					ayudaN=auxN->datos;
					auxN->datos = auxN->siguiente->datos;
					auxN->siguiente->datos=ayudaN;
				
					ayudaA=auxA->datos;
					auxA->datos = auxA->siguiente->datos;
					auxA->siguiente->datos=ayudaA;
					
					band=true;
				}
				auxE=auxE->siguiente;
				
			}
		}
	}
}

void Persona::OrdenamientoNom(int tamanio){
	nodo* aux=new nodo();
	nodo* auxN=new nodo();
	nodo* auxA=new nodo();
	nodo* auxE=new nodo();
	
	int ints, ayuda, ayudaE;
	string ayudaN, ayudaA;
	bool band;
	
	ints=tamanio;
	
	while(ints>1){
		ints=(ints/2);
		band=true;
		while(band==true){
			band=false;
			aux=primero;
			auxN=primeroN;
			auxA=primeroA;
			auxE=primeroE;
			
			while(auxN->siguiente!=NULL && auxA->siguiente!=NULL){//aqui utilizamos el auxiliar de la edad, que recorrerar todos los datos del nodo por edad
				
				if(auxN->datos > auxN->siguiente->datos && auxA->datos > auxA->siguiente->datos ){
					ayuda=aux->dato;
					aux->dato = aux->siguiente->dato;
					aux->siguiente->dato=ayuda;	
					
					ayudaE=auxE->dato;
					auxE->dato = auxE->siguiente->dato;
					auxE->siguiente->dato=ayudaE;
				
					ayudaN=auxN->datos;
					auxN->datos = auxN->siguiente->datos;
					auxN->siguiente->datos=ayudaN;
				
					ayudaA=auxA->datos;
					auxA->datos = auxA->siguiente->datos;
					auxA->siguiente->datos=ayudaA;
					
					band=true;
				}
				auxN=auxN->siguiente;
				auxA=auxA->siguiente;
				
			}
		}
	}
}

void Persona::Eliminar(){
	nodo* lista=new nodo();
	nodo* listaA=new nodo();
	nodo* listaN=new nodo();
	nodo* listaE=new nodo();

	lista=primero;
	listaN=primeroN;
	listaA=primeroA;
	listaE=primeroE;
	
	nodo* anterior=new nodo();
	nodo* anteriorN=new nodo();
	nodo* anteriorA=new nodo();
	nodo* anteriorE=new nodo();
	
	anterior=NULL; 
	anteriorN=NULL;
	anteriorA=NULL; 
	anteriorE=NULL; 
	
	bool encontrado=false;
	int busqueda=0;
	cout<<"\t\t\t\t\tEliminacion por numero de cedula: ";
	cout<<"\t\t\t\t\tIngrese el numero de cedula que desee eliminar: ";
	cin>>busqueda;
	if(primero != NULL){
		while(lista != NULL  && encontrado != true){
			if(lista->dato == busqueda){
				cout<<"\t\t\t\t\tEl numero de cedula:  "<<busqueda<<" encontrado en la lista"<<endl;
				if(lista == primero){
					primero=primero->siguiente;
					primeroN=primeroN->siguiente;
					primeroA=primeroA->siguiente;
					primeroE=primeroE->siguiente;
				}else if(lista == ultimo){
					anterior->siguiente=NULL;
					anteriorN->siguiente=NULL;
					anteriorA->siguiente=NULL;
					anteriorE->siguiente=NULL;
					ultimo=anterior;
					ultimo=anteriorN;
					ultimo=anteriorA;
					ultimo=anteriorE;
				}else{
					anterior->siguiente=lista->siguiente;
					anteriorN->siguiente=listaN->siguiente;
					anteriorA->siguiente=listaA->siguiente;
					anteriorE->siguiente=listaE->siguiente;						
				}
				cout<<"\t\t\t\t\t\t\tElimando"<<endl;
				encontrado=true;
			}
			anterior=lista;
			lista = lista->siguiente;
		}
		if(!encontrado){
			cout<<"\t\t\t\t\tno se encontro el dato";
		}
	}
}

