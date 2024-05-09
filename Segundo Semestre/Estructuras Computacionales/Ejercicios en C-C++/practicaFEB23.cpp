#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){

struct Nodo{

    int dato;
    Nodo *sig;

};

//Variables
Nodo *inicio, *tmp;
int cantidad;
inicio=NULL;


cout<<"Cuantos nodos deseas crear: ";
cin>>cantidad;

for(int cont=1;cont<=cantidad;cont++){

tmp=new Nodo();
tmp->dato=cont;
tmp->sig=inicio;
inicio=tmp;




}



/*
//crear nodo
tmp=new Nodo();
tmp->dato=1;
tmp->sig=inicio;
inicio=tmp;

//crear nodo2
tmp=new Nodo();
tmp->dato=2;
tmp->sig=inicio;
inicio=tmp;
//crear nodo 3
tmp=new Nodo();
tmp->dato=3;
tmp->sig=inicio;
inicio=tmp;
*/

//recorrer lista
tmp=inicio;
while(tmp!=NULL){
    cout<<tmp->dato<<", ";
    tmp=tmp->sig;
}

return 0;








}