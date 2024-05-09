//Jose Luis Sandoval Perez 2A ICI
//Practica FEB 14

#include<stdio.h>
#include<iostream>
#include<Windows.h>

struct estructuraNodo{

    int dato;
    
    struct estructura *sig;
};

using namespace std;


int main() {

    struct estructuraNodo varNodo;
    struct estructuraNodo varNodo2;


    varNodo.dato =5 ;
    varNodo2.dato = 10;

    cout<<varNodo.dato;
    cout<<varNodo2.dato;

    varNodo.sig= NULL;
    varNodo2.sig= NULL;

    varNodo.sig = &varNodo2;

    cout<<varNodo.sig->dato;





}