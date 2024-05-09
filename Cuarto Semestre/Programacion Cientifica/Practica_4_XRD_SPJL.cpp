/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de biseccion de la funcion f(x) = x * sen(x)-1
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//x debe de estar en radianes, maximo valor de x = 2pi, 6 radianes

void menu();
double SacarF(double x);
void MetodoBiseccion(double is,double ii, double te);

double SacarF(double x){
    return x * sin(x) - 1;
}

void MetodoBiseccion(double intS, double intI, double TE){

    

    int i{0};
    double fS=SacarF(intS);
    double fI=SacarF(intI);
  

     
    

    while(true){

        double xM=(intI+intS) / 2;
        double fxM=SacarF(xM);

        if(abs(fxM) < TE){
            cout<<"La raiz fue encontrada en = "<<setprecision(9)<<xM<<" con "<<i<<" iteraciones :)"<<endl;

            system("pause");
            system("cls");
        
            return;
        }

        i++;

        if(fI*fxM < 0){
            intS=xM;
            fS=fxM;
        }else{
            intI=xM;
            fI=fxM;
        }
        

    }

  

}





void menu(){

    int op{0};

    do{
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"\tB I E N V E N I D O "<<endl;
        cout<<"---------------------------------------------------------"<<endl;

        cout<<"Este programa calcula la raiz de la funcion f(x)= x * sen(x)-1 por el metodo de biseccion"<<endl;

        cout<<"---------------------------------------------------------"<<endl;


        cout<<" E L I G E     O P C I O N "<<endl;
        cout<<"(1) Metodo biseccion"<<endl;
        cout<<"(2) Salir"<<endl;

       cout<<"Opcion: "; cin>>op;

        if(op==1){

            double intS{0}, intI{0}, tolE{0};
                


            cout<<"Ingresa el valor de los intervalos\nSup: ";cin>>intS;
            cout<<"Inf: ";cin>>intI;

            cout<<"Ingresa la toleracia de error: "; cin>>tolE;
        
            MetodoBiseccion(intS,intI,tolE);
          
            
        }

        system("pause");
        system("cls");






    }while(op!=2);

    cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
    system("pause");
    system("cls");

    


}




int main(){

    menu();

    return 0;



}

