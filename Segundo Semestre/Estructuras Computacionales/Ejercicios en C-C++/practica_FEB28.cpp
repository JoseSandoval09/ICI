
//LISTAS DOBLEMENTE LIGADA

#include<iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

int main(){

    struct Nodo{

        Nodo *ant;
        int dato;
        Nodo *sig;


    };

    Nodo *inicio= new Nodo();
    inicio->sig=NULL;
    inicio->ant=NULL;
    inicio->dato=1;
    

    







}