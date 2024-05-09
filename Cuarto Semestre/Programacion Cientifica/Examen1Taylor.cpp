/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de ciencias de la computacion
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Luis Fernando Guiterrez Marfileño

Este programa implementara serie de taylor para el calculo 
de la funcion f(x)=e^5x
*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int val_x{0},error_trun{0};
    int contador{1};
    float suma{0}, term{1};

    cout<<"\nEste programa calcula el valor de la funcion f(x)= e^5x)\nmediante Series de taylor"<<endl;
    cout<<"Teclea el valor del exponente x: ";
    cin>>val_x;
    cout<<"\nTeclea el error de truncamiento: ";
    cin>>error_trun;

    float aprox{0};
    aprox=pow(term,(5*val_x));

    while(aprox<=error_trun){
        suma=suma+term;
        term=exp((5*val_x));
        contador=contador+1;

    }

    cout<<"El valor de f(x)= e("<<val_x<<")^5x es: "<<suma<<endl;


    return 0;

}


