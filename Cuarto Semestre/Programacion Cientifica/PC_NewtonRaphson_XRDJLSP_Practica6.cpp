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


double aradianes(double grad);
void newthonraphson(double radianes);
double fx(double rad);
double fx1(double rad);


double aradianes(double grad){
    float pi= 3.14159265;
    return grad * (pi/180);
}

double fx(double rad){
    return cos(rad)-rad;
}

double fx1(double rad){
    return -sin(rad)-1;
}

void newthonraphson(double radianes){
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

        xm=radianes-(fx(radianes)/fx1(radianes));
        cout<<"valor de x: "<<radianes<<endl;
        cout<<"f(x): "<<fx(radianes)<<endl;
        cout<<"f'(x): "<<fx1(radianes)<<endl;
        cout<<"xm: "<<xm<<endl;;

        

        if(abs(xm-radianes)<epsilon){
            raiz=xm;
            break;
        }

        

        radianes=xm;

        
        


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

            cout<<"\nEl valor equivalente en radianes es: "<<setprecision(9)<<aradianes(valinicial);

            double valorrad=aradianes(valinicial);

            

            newthonraphson(valorrad);
        }
    }while(op!=2);

    system("cls");

    cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
    system("pause");
    system("cls");


    


}
