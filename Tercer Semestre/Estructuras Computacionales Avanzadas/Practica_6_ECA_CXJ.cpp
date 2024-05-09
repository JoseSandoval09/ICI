/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Se va a crear un programa que determine si un grafo dado es un árbol, para ello el máximo
numero de nodos que puede contener el grafo es de 10.


*/

#include<iostream>

using namespace std;


int main(){

const int tammax=10;
int i=0,j=0;
int nodos;
int matriz_adyacencia[tammax][tammax];

cout<<" A R B O L     O    N O  A R B O L"<<endl;

cout<<"Ingresa el numero de nodos del grafo (MAX=10): ";
cin>>nodos;

//llenado de matriz de adyacencia

for(i=0;i<nodos;i++){
    for(j=0;j<nodos;j++){

        cout<<"Existe adyacencia entre nodos ";
        cout<< i + j + "[1=SI - 0=NO]"<<endl;
        cin>>matriz_adyacencia[i][j];

    }
}





}