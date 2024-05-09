#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){

    struct Nodo{
        int dato;
        struct Nodo*sig; 
    };

    Nodo *inicio,*tmp;

    
    

    tmp= new Nodo();
    int op;

    do{

        cin >> tmp->dato;
        tmp->sig=inicio;
        inicio=tmp;
        
        cout<<"repetir ciclo, 1=si,0=no";
        cin >> op;



    }while(op==1);





    







}