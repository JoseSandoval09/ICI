/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Luis Fernando Guiterrez Marfileño

f(x)= 4x*2 -10

Obtencion de raices metodo grafico

*/

#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;




int main(){

    /*Declaracion de variables de intervalos*/
    int inSup{};
    int inInf{};
   
    float raiz{0};
    int cont{0};
    int indice{0};

    cout<<"Este programa calcula el valor de las raices de la funcion: 4x*2-10 por el metodo grafico"<<endl;

    cout<<"Teclea el intervalo deseado\n limite inferior: "; cin>>inInf;
    cout<<"\nLimite superior: "; cin>>inSup; 


    float f_x[inSup - inInf];
    float valx[inSup - inInf];

    //ciclo for para valores de f(x)
    for(cont=inInf;cont<=inSup;cont++){
        f_x[indice]= 4*cont*cont - 10;
         cout<<"f(x)= "<<f_x[indice]<<endl;
        indice++;
    }

    //ciclo for
    for(cont=0;cont<=(inSup-inInf);cont++){
        valx[cont]=inInf+cont;
        cout<<"El valor de x es: "<<valx[cont]<<endl;
    }

    for(cont=0;cont<(inSup-inInf);cont++){

        if(f_x[cont]*f_x[cont+1]<0){
            raiz=(valx[cont]+valx[cont+1])/2;
            cout<<"Hay una raiz en: "<<raiz<<endl;
        }




    }

    







}
