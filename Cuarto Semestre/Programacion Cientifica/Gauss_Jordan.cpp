/*
Programa que implemente el metodo de solucion de ecuaciones Gauss-Jordan para la resolucion de un sistema de ecuaciones
*/

#include<math.h>
#include<iostream>

using namespace std;





int main(){

    int tam{0};


    cout<<"M E T O D O      G A U S S       J O R D A N"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Ingrese el tamaño de la matriz: ";
    cin>>tam;

    float Matrix[tam][tam];
    

    cout<<"Ingrese coeficientes por fila: ";
   for(int i=0;i<=tam;i++){
    for(int j=0;j<=tam;j++){
        cout<<"Ingresa coeficiente fila ["<<j<<"]:";
    }
   }
    






    return 0;
}