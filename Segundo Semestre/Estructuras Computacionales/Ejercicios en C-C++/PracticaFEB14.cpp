//JOSE LUIS SANDOVAL PEREZ 2A ICI

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
Linked List
*/
int main(){
    struct estNodo{
        int dato;
        struct estNodo *sig;
    };
    struct estNodo varNodo;
    struct estNodo varNodo2;

    varNodo.dato=5;
    varNodo.sig=&varNodo2;
    varNodo2.dato=10;
    varNodo2.sig=NULL;

    cout<<varNodo.dato<<" "<<varNodo.sig->dato;
return 0;
}