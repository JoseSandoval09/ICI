/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Departamento de ciencias de la computacion
Jose Luis Sandoval Perez
Examen Parcial 2 
Metodo Gauss-Jordan
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de biseccion de la funcion f(x) = x^3-1.412x^2 + 0.098
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double sacarF(double x);

int main(){

    double is,ii,e, fs,fi,xm,fxm, i{0};

    cout<<"Este programa calcula la raiz de una funcion utilizando el metodo de biseccion de la funcion f(x) = x^3-1.412x^2 + 0.098"<<endl;

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
            cout<<"raiz encontrada en: "<<xm<< " con "<<i<<"  iteraciones";
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
    return (x*x*x) - (1.412*(x*x)) + 0.098;
}