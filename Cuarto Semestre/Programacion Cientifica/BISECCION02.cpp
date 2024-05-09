/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de biseccion de la funcion f(x) = f(x)= 4x^2 -5x
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double sacarF(double x);

int main(){

    double is,ii,e, fs,fi,xm,fxm, i{0};

    cout<<"Ingrese intervalo superior: ";
    cin>>is;
    cout<<"\nIngrese intervalo inferior: ";
    cin>>ii;
    cout<<"\nIngresa toleracia de error: ";
    cin>>e;

    fs=sacarF(is);
    fi=sacarF(ii);

    while(true){

        xm=(is+ii)/2;
        fxm=sacarF(xm);

        if(abs(fxm)<e){
            cout<<"raiz encontrada en: "<<xm<< "con "<<i<<"  iteraciones";
            return xm;

        }

        i++;

        if(fi*fxm < 0){
            is=xm;
            fs=fxm;
        }else{
            ii=xm;
            fi=fxm;
        }


    }



    return 0;

}

double sacarF(double x){
    return 4*(x*x)-5*x;
}