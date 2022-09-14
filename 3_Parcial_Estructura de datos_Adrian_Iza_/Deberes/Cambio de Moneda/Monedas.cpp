/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Progrma princial Cambio de Monedas      *
*Autor Jonathan Maigua y Adrian Iza      *
*Fecha de creacion 30/03/2021            *
*Fecha de modificacion                   *
******************************************/

#include <iostream>

using namespace std;

int main()
{
 int moneda[] = {100,25,10,5,1};
 int veces[] = { 0, 0, 0, 0, 0};
 int n = 5;
 int i,monto;
 cout<<"PROGRAMA PRINCIPAL CAMBIO DE MONEDA: "<<endl;
 cout<<"Monto: ";
 cin>>monto;
 
 for(i=0;i<n;i++)
 {
  veces[i] = monto/moneda[i];
  monto = monto%moneda[i];
 }
 for(i=0;i<n;i++)
 {
  cout<<"Monedas "<<moneda[i]<<" cantidad "<<veces[i]<<endl;
 }
}
