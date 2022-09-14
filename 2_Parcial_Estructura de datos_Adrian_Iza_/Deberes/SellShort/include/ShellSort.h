
#ifndef SHELLSORT_H
#define SHELLSORT_H


#include <iostream>
#include <windows.h>
using namespace std;

class ShellSort{
public:
int Arreglo[100],i,j,k,incremento,aux;//dinamica y encerar etc y modelo
void LeerArreglo(int Numero);
void EscribeArreglo(int Numero);
void Shell(int Numero);

};
void ShellSort::Shell(int Numero){
	incremento=Numero/2;
 while(incremento>0){
        for(i=incremento+1;i<=Numero;i++){
            j=i-incremento;
            while(j>0){
                if(Arreglo[j]>=Arreglo[j+incremento]){
                    aux = Arreglo[j];
                    Arreglo[j] = Arreglo[j+incremento];
                    Arreglo[j+incremento] = aux;
                }
                else{
                        j=0;
                    }
                j=j-incremento;
            }
        }
        incremento=incremento/2;
    }
}

void ShellSort::EscribeArreglo(int Numero){
 int i;
    cout<<"elementos ordenados por metodo Shell sort"<<endl;
    for(i=1;i<=Numero;i++)
    {

        cout<<"\t"<<Arreglo[i];
    }
}

void ShellSort::LeerArreglo(int Numero){
    int i;
    for(i=1;i<=Numero;i++)
    {
        cout<<"Arreglo["<<i<<"]=";
        cin>>Arreglo[i];
    }
}
#endif // SHELLSORT_H
