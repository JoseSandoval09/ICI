/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de Newton Rapshon de  f(x) = cos(x)-x
*/


#include<bits/stdc++.h>

using namespace std;


void newthonraphson(double radianes);
double fx(double rad);
double fx1(double rad);




double fx(double x){
    return pow(x,2) - 2*x -3;
}

double fx1(double x){
    return 2*x -2;
}

void newthonraphson(double valorinicial){
    int i=1,N;
    double xm,epsilon,raiz;

    cout<<"\nValor de tolerancia de error: ";
    cin>>epsilon;
    cout<<"Iteraciones maximas: ";
    cin>>N;
    cout<<"\n";

    

    for( i=1;i<=N;i++){  

        cout<<"\n-----------------------------"<<endl;
       
        cout<<" I T E R A C I O N "<<i<<endl;

        xm=valorinicial-(fx(valorinicial)/fx1(valorinicial));
        cout<<"valor de x: "<<valorinicial<<endl;
        cout<<"f(x): "<<fx(valorinicial)<<endl;
        cout<<"f'(x): "<<fx1(valorinicial)<<endl;
        cout<<"xm: "<<xm<<endl;;

        

        if(abs(xm-valorinicial)<epsilon){
            raiz=xm;
            break;
        }

        

        valorinicial=xm;

        
        


    }

   cout<<"\n\nEl valor de la raiz es: "<<raiz;
   cout<<"\nEl valor de iteraciones necesarias fue: "<<i<<endl;

    system("pause");
    system("cls");
}

int main(){


    int op;

    do{

        cout<<"M E T O D O   N E W T O N   R A P H S O N"<<endl;

        cout<<"1.Newton Raphson"<<endl;
        cout<<"2. Salir"<<endl;
       
        cout<<"Opcion: ";cin>>op;

        if(op==1){

            system("cls");
            cout<<"Este programa calcula la raiz de una funcion utilizando el metodo de Newton Rapshon de  f(x) = cos(x)-x"<<endl;

            cout<<"Ingresa el valor inicial en grados: ";
            double valinicial;
            cin>>valinicial;
            newthonraphson(valinicial);
        }
    }while(op!=2);

    system("cls");

    cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
    system("pause");
    system("cls");


    


}
