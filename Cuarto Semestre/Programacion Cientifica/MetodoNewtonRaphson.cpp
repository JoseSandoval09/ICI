/*
Universidad autonoma de Aguascalientes
Computacion Inteligente
Alumno: Jose Luis Sandoval Perez
Profesor: Marfileño
Programa que calcule raiz por metodo de NewtonRaphson
*/


#include <bits/stdc++.h>

using namespace std;


int main(){

    double ValInxO{0},raizAproxM{0},fxM{0},fdxM{0},epsilon{0}, valfxF;

    cout<<"-----METODO NEWTO-RAPHSON-----\n-----x^2-4X+2=0-----\n ";

    cout<<"Ingrese el valor inicial: "; cin>>ValInxO;
    cout<<"\n Ingrese el margen de error: "; cin>>epsilon;
    int cont=0;

    for(int i=0;i<100;i++){

        raizAproxM= (ValInxO) - (pow(ValInxO,2) - (4*ValInxO) + 2 / (2*ValInxO) +4);

        cout<<raizAproxM<<endl;

        if(abs(raizAproxM-ValInxO)>epsilon){
            valfxF=raizAproxM;
            break;
        }else{
            ValInxO=raizAproxM;
        }

       

       
        cont++;

    }

    cout<<"El valor de la raiz es: "<<valfxF<<endl;
    cout<<"Numero de iteraciones: "<<cont<<endl;

    //.5857
    




    


}