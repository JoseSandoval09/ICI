/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4°A
Ximena Rivera Delgadillo
Jose Luis Sandoval Perez
PRACTICA 3
Luis Fernando Guiterrez Marfileño

f(x)= 4x^3 + 2x^2+3x-5

Obtencion de raices metodo grafico

*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int main(){

    /*Declaracion de variables de intervalos*/
    int inSup{};
    int inInf{};
   
    float raiz{0};
    int cont{0};
    int indice{0};
    int error{1};
    float raizr{0};

    cout<<"Este programa calcula el valor de las raices de la funcion: f(x)= 4x^3 + 2x^2+3x-5 por el metodo grafico"<<endl;

    cout<<"Teclea el intervalo deseado\n limite inferior: "; cin>>inInf;
    cout<<"\nLimite superior: "; cin>>inSup; 
    


    float f_x[inSup - inInf];
    float valx[inSup - inInf];

    //ciclo for para valores de f(x)
    for(cont=inInf;cont<=inSup;cont++){
        f_x[indice]= pow(cont,3)+(2*pow(cont,2)+3*cont-5);
         cout<<"f("<<cont<<")= "<<f_x[indice]<<endl;
        indice++;
    }

    //ciclo for
    for(cont=0;cont<=(inSup-inInf);cont++){
        valx[cont]=inInf+cont;
        //cout<<"El valor de x es: "<<valx[cont]<<endl;
    }

    for(cont=0;cont<(inSup-inInf);cont++){

        if(f_x[cont]*f_x[cont+1]<=0){
            raiz=(valx[cont]+valx[cont+1])/2;
            cout<<"Hay una raiz en: "<<raiz<<endl;
        }

    }

    while(abs(raizr-raiz)>error){
        
        raizr=raiz;
        raiz=(valx[cont]+valx[cont+1])/2;
        
    }

    cout<<"raiz real: "<<raizr<<endl;;
    cout<<"raiz aprox: "<<raiz<<endl; 

    







}





