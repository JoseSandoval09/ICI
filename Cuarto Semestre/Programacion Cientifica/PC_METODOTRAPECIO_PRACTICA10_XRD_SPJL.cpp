/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa utiliza el metodo del trapecio para obtener una aproximacion a la siguiente integral 

f(x)=sec(x) 0-pi/4

*/

#include<iostream>
#include<math.h>

double SacarF(double x);


using namespace std;

int main(){

    int subin{0};

    cout<<"Ingresa el numero de subintervalos a dividir la funcion: ";
    cin>>subin;

    double n{0},a{0},b{0},h{0},PI{3.141593};

    n=subin;
    a=0;
    b=PI/4;
    h=(b-a)/n;

    double x[subin],fx[subin];
    x[0]=a;
    x[subin]=b;

  

    for(int i=1;i<=subin;i++ ){
        x[i]=x[i-1]+h;   
    }
    for(int i=0;i<=subin;i++){
        fx[i]=SacarF(x[i]);
    }

    double aprox;
    aprox=fx[0]+fx[subin];

    for(int i=1; i<subin;i++){

        aprox+=2*fx[i];

    }

    aprox=h/2*aprox;

    
    

    cout<<"El valor aproximado de la integral definida sec(x) desde 0 a pi/4 es igual a:  "<<aprox;



}

double SacarF(double x){
    return 1/cos(x);
}

