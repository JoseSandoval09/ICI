/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Departamento de ciencias de la computacion
Jose Luis Sandoval Perez
Examen Parcial 3
Luis Fernando Guiterrez Marfileño

Este programa utiliza el metodo del trapecio para obtener una aproximacion a la siguiente integral 

f(x)=cos^3(x)dx en un intervalo de pi/2 a 0

*/

#include<iostream>
#include<math.h>

double SacarF(double x);


using namespace std;

int main(){

    int op=0;

    do{

        cout<<"METODO DE TRAPEZOIDE TERCER PARCIAL EXAMEN"<<endl<<endl;

        cout<<""<<endl<<endl;

        cout<<"Selecciona una opcion: \n1.Metodo de trapezoide\n2.Salir"<<endl;
        cout<<"Opcion: "; cin>>op;

        system("cls");

        switch(op){

            case 1:{
           cout<<"Este programa utiliza el metodo del trapecio para obtener una aproximacion a la siguiente integral f(x)=cos^3(x)dx en un intervalo de pi/2 a 0\n"<<endl;


            int subin{0};

            cout<<"Ingresa el numero de subintervalos a dividir la funcion: ";
            cin>>subin;

            double n=0,a=0,b=0,h=0,PI=3.141593;

            n=subin;
            a=0;
            b=PI/2;
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

            
            

            cout<<"\nEl valor aproximado de la integral definida cos^3(x)dx en un intervalo de pi/2 a 0 es :  "<<aprox<<endl;

            system("pause");
            system("cls");

            break;
        }

        
        default :
            system("pause");
            system("cls");
        }






    }while(op!=2);

    cout<<"DECIDISTE SALIR!!! ES TODO!!\n Jose Luis Sandoval Perez";


    



}

double SacarF(double x){
    return pow(cos(x),3);
}

