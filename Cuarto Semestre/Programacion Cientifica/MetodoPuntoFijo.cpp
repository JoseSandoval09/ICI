/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Luis Fernando Guiterrez Marfileño

Este programa implementea el metodo de punto medio para la obtencion de raices

*/

#include<iostream>
#include<math.h>



using namespace std;

int main(){

    float aprox{0};
    float error{0};
    float x{0};
    int cont{0};
    

    cout<<"Este programa encuentra un valor de raiz de la funcion: ";
    cout<<"x^3 + 4x^2 - 10 = 0"<<endl;

    cout<<"\nTeclea  el valor de la aproximacion: "; cin>>aprox;
    cout<<"\nTeclea el valor de tolerancia del error: "; cin>>error;

    x=sqrt(10/(aprox+4));

    cout<<"El valor de x es: "<<x<<endl;

    while(abs(aprox-x)>error){
        cont=cont+1;
        aprox=x;
        x=sqrt(10/(aprox+4));
        
    }

    
    cout<<"El valor de la raiz es: "<<x<<endl;
    cout<<"Iteraciones: "<<cont<<endl;






    return 0;
}