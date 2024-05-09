/* 
JOSE LUIS SANDOVAL PEREZ
2A ICI
ARBOLES PRIMER EJERCICIO
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct Arbol{
    int dato;
    Arbol *izq, *der;

};




int main(){

    Arbol *raiz, *tmp, *tmp2;
    cout<<"---Creacion del arbol---";
    raiz = new Arbol();
    raiz-> dato= 1;
    raiz->izq = raiz ->der = NULL;
    //Hijo 1
    tmp= new Arbol();
    tmp->dato=2;
    tmp->izq=tmp;
    //Hijo 2
    tmp= new Arbol();
    tmp->dato=3;
    tmp->izq = tmp->der = NULL;
    raiz->der =tmp;

    //hijo de raiz izq(2);

    tmp=new Arbol;
    tmp->dato=4;
    tmp->izq=tmp->der=NULL;
    tmp2=raiz;
    tmp2=tmp2->izq;
    tmp2->der=tmp;

    cout<<"\nImprimir nodo 3";
    tmp=raiz;
    tmp=tmp->der;
    cout<<tmp->dato<<": ";





}
