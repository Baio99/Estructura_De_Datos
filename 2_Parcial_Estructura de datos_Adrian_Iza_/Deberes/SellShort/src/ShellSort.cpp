/******************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE *
* Prorama principal para crear clase      *
* Adrian Iza					  *
* Fecha de creaci�n 30/01/2021			  *
* Fecha de modificaci�n                   *
******************************************/

#include "ShellSort.h"

#include "ShellSort.h"
#include <iostream>
#include <windows.h>

int main(){
	ShellSort SS;
    int Num;
    cout<<"Ingrese dimension del arreglo : ";
    cin>>Num;
    SS.LeerArreglo(Num);
    SS.Shell(Num);
    cout<<endl;
    SS.EscribeArreglo(Num);
    return 0;
}

