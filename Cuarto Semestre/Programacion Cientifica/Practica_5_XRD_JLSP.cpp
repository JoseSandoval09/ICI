/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de regla/falsa posicion de  f(x) = e^-x - ln x
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void menu();
void falsapos(double is,double ii, double te);
double sacarf(double x){
    double res{0};
    res= exp(-x) - log(x);
    return res;
}

void menu(){

    int op{0};

    do{
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"\tB I E N V E N I D O "<<endl;
        cout<<"---------------------------------------------------------"<<endl;

        cout<<"Este programa calcula la raiz de la funcion f(x)=  e^-x - ln x por el metodo de falsa posicion / regla falsa"<<endl;

        cout<<"---------------------------------------------------------"<<endl;


        cout<<" E L I G E     O P C I O N "<<endl;
        cout<<"(1) Metodo Falsa Posicion"<<endl;
        cout<<"(2) Salir"<<endl;

       cout<<"Opcion: "; cin>>op;

        if(op==1){

            double intS{0}, intI{0}, tolE{0};
                


            cout<<"Ingresa el valor de los intervalos\nSup: ";cin>>intS;
            cout<<"Inf: ";cin>>intI;

            cout<<"Ingresa la toleracia de error: "; cin>>tolE;
        
            falsapos(intS,intI,tolE);
          
            
        }

        system("pause");
        system("cls");






    }while(op!=2);

    cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
    system("pause");
    system("cls");



}

void falsapos(double xs, double xi, double TE){

    double fxs,fxi,xm,fxm;

    int Iter{0}, i{1};

    cout<<"Ingresa numero de iteraciones: "; cin>>Iter;

    

    
   do{
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"\tI T E R A C I O N  "<<i<<endl;

        fxi=sacarf(xi);
        fxs=sacarf(xs);

        xm= xs-(fxs*(xs-xi)/(fxs-fxi));
        cout<<"Valor xm: "<<xm<<setprecision(9)<<endl;
        cout<<"Valor xs: "<<xi<<setprecision(9)<<endl;
        cout<<"valor xi: "<<xs<<setprecision(9)<<endl;
        
        if ((sacarf(xi) * sacarf(xm))<0)
        {
            xs=xm;
        }else{
            xi=xm;
        }

        

        i++;
           
   }while(i<=Iter && abs(fxm)>0);
    
    cout<<endl;

    cout<<"El valor aprox  de la raiz es: "<<xm<<endl;
    


}

int main(){
    menu();

    return 0;
}