#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){

    struct Nodo{
        int dato;
        Nodo *sig;
    }*inicio,*fin,*tmp;

    fin=new Nodo();
    fin->dato=2;
    fin->sig=NULL;

    inicio=new Nodo();
    inicio->dato=1;
    inicio->sig=fin;

    //Insertar 3
    tmp=new Nodo();
    tmp->dato=3;
    tmp->sig=NULL;
    fin->sig=tmp;
    fin=tmp;
    //insertar 4
    tmp=new Nodo();
    tmp->dato=4;
    tmp->sig=NULL;
    fin->sig=tmp;
    fin=tmp;

    cout<<"Sin eliminar: ";
    //Recorrer lista
    tmp=inicio;
    while(tmp!=NULL){
        cout<<tmp->dato<<", ";
        tmp=tmp->sig;
    }

    //eliminar 1
    tmp=inicio;
    inicio=inicio->sig;
    delete tmp;

    cout<<"\nYa eliminado: ";
    tmp=inicio;
    while(tmp!=NULL){
        cout<<tmp->dato<<", ";
        tmp=tmp->sig;
    }

}