/******************************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE *
* Prorama principal para crear clase      *
* Adrian Iza					  *
* Fecha de creación 30/01/2021			  *
* Fecha de modificación                   *
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

