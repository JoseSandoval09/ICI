

#include<iostream>


#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{        //#1 declaración del nodo base
    int dato;
    struct Nodo *sig;
};

    //#2
                               

int main(){
    struct Nodo *inicio,*tmp;

    inicio = new struct Nodo();            
                                                         
    inicio->dato = 5;      
    inicio->sig = NULL;    //#3    
                               

    tmp = new Nodo();  //#6    
    tmp->dato=10;      //#7
    tmp->sig = inicio;    //#8    
    inicio = tmp;  //#9
                           
    tmp = new Nodo();  //#6
    cout<<"Ingresa un numero ---> ";cin>>tmp->dato;      
    tmp->sig = inicio;        
    inicio = tmp;          
                           
    //RECORRIDO

    tmp=inicio;
    while(tmp != NULL){
        cout<<tmp->dato<<", ";
        tmp = tmp->sig;
    }

    getch();
    return 0;
}