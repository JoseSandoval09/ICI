/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa implementea el metodo de punto fijo para la obtencion de raices de la ecuacion
e^-x - x = 0


*/

#include<iostream>
#include<math.h>
#include<iomanip>


using namespace std;

int main(){

    long double aprox{0};
    long double error{0};
    long double x{0};

    int cont{0};
    

    cout<<"Este programa encuentra un valor de raiz de la funcion: ";
    cout<<"e^-x - x = 0"<<endl;
    cout<<"La formula despejada es: x=e^-x";

    cout<<"\nTeclea  el valor de la aproximacion: "; cin>>aprox;
    cout<<"\nTeclea el valor de tolerancia del error: "; cin>>error;

    x=exp(-x);

    cout<<"El valor de x es: "<<x<<endl;

    while(abs(aprox-x)>error){
        cont++;
        aprox=x;
        x=exp(-x);
        
    }

    cout<<fixed;
    cout<<setprecision(9);
    cout<<"El valor de la raiz es: "<<x<<endl;
    cout<<"Iteraciones: "<<cont<<endl;






    return 0;
}