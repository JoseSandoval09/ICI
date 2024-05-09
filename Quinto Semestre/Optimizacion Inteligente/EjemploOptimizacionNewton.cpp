#include<iostream>
#include<math.h>

using namespace std;

int main(){

    double x=0, fx=0,fx1=0,fx2=0,error;

    cout<<"Ingrese el valor inicial: ";cin>>x;
    cout<<"Ingresa el error: ";cin>>error;


    cout<<"x\tfx\tfx1\tfx2"<<endl;

    do{
        
        cout<<x<<"\t"<<fx<<"\t"<<fx1<<"\t"<<fx2<<endl;
        
        fx=2*(x*x)+16/x;
        fx1=4*x-16/(x*x);
        fx2=32/(x*x*x)+4;
        x=x-fx1/fx2;
        //1.54
   }while(abs(fx1)>error);

   cout<<"El valor minimo encontrado en la funcione es: "<<2*(x*x)+16/x;
   





}