/*
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de ciencias de la computacion
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Luis Fernando Guiterrez Marfileño

Este programa implementea el metodo de punto fijo para la obtencion de la raiz
de la funcion f(x)=0.5sin(x)-x+1=0
*/

#include<iostream>
#include<math.h>



using namespace std;

int main(){

    float inicial{0};
    float error{0};
    float x{0.0};
    int cont{0};
  
    

    cout<<"Este programa encuentra un valor de raiz de la funcion: f(x)=0.5sin(x)-x+1= 0"<<endl;
    cout<<"La formula despejada es: x=0.5sin(x) +1"<<endl;
    cout<<"\nTeclea  el valor inicial: "; cin>>inicial;
    cout<<"\nTeclea el valor de truncamiento: "; cin>>error;

    x=(0.5*sin(x))+1;


    while(abs(inicial-x)>error){
       
        inicial=x;
        x=(0.5*sin(x))+1;
        cont++;
        
    }


    cout<<"El valor de la raiz es: "<<x<<endl;
    cout<<"Iteraciones necesarias para encontar la raiz :"<<cont<<endl;
    
    






    return 0;
}