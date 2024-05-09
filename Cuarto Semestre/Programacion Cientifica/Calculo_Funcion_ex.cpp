/*
Universidad autonoma de Aguascalientes
Computacion Inteligente
Alumno: Jose Luis Sandoval Perez
Profesor: Marfileño
Programa que calcula valores para la funcion e(x)
mediante series de Taylor
*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int val_x{0},num_ter{0};
    int contador{1};
    float suma{0}, term{1};

    cout<<"\nEste programa calcula el valor de la funcion e(x)\nmediante Series de taylor"<<endl;
    cout<<"Teclea el valor del exponente x: ";
    cin>>val_x;
    cout<<"\nTeclea el numero de terminos: ";
    cin>>num_ter;

    while(contador<=num_ter){
        suma=suma+term;
        term=term*val_x / contador;
        contador=contador+1;

    }

    cout<<"El valor de la funcion e("<<val_x<<") es: "<<suma<<endl;

    return 0;

}


