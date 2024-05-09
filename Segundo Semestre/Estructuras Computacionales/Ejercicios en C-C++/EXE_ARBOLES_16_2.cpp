#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

struct Nodo{
    string palabra;
    int frecuencia;
    Nodo *izq;
    Nodo *der;
    Nodo *padre;
};

Nodo *raiz = NULL;

//uso de nodos
Nodo *crearNodo(string,Nodo *);
void insertarNodo(Nodo *&,string,Nodo *);
void recorrerInorden(Nodo *);
bool buscarNodo(Nodo*,string);

int main(){
    string h; char c;
    cout<<"Ingrese texto:\n";
    cout<<"(Para finalizar ingrese SPACE, despues ENTER seguido de ctrl+Z y presione ENTER de nuevo)\n";
    fflush(stdin);
    while(scanf("%c",&c)!=EOF){ h+=c; };
    cout<<endl;

    string act="";
    for(auto x:h){
        if(x!=' '){ act+=x; }
        else{
            bool existe = buscarNodo(raiz,act);
            if(existe == false){
                insertarNodo(raiz,act,NULL);
            }
            act="";
        }
    }
    cout<<"Lista de repeticion:\n";
    recorrerInorden(raiz);

    cout << "\n        .:PROGRAMA REALIZADO POR :.          ";
	cout << "\nAngel David Ortiz Quiroz            ID:261481";
	cout << "\nErick Ivan Ramirez Reyes            ID:260806";
	cout << "\nXimena Rivera Delgadillo            ID:261261";
	cout << "\nJose Luis Sandoval Perez            ID:261731";
	cout << "\nDiego Emanuel Saucedo Ortega        ID:261230";
	cout<< "\nCarlos Daniel Torres Macias 		    ID:244543";
	cout << "\n";



    return 0;
}

Nodo *crearNodo(string n,Nodo *padre){

    Nodo *nuevo = new Nodo();

    nuevo->palabra = n;
    nuevo->frecuencia = 1;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->padre = padre;
    return nuevo;
}

void insertarNodo(Nodo *&arbol,string n, Nodo *padre){
    if(arbol==NULL){
        arbol = new Nodo();
        arbol = crearNodo(n,padre);
    }
    else if(n != arbol->palabra){
        string valorRaiz = arbol->palabra;

        if(n<valorRaiz){ insertarNodo(arbol->izq,n, arbol); }
        else{ insertarNodo(arbol->der, n, arbol); }
    }
}

void recorrerInorden(Nodo *arbol){
    if(arbol==NULL){return;}
    recorrerInorden(arbol->izq);
    cout<<arbol->palabra<<" "<<arbol->frecuencia<<endl;
    recorrerInorden(arbol->der);
}

bool buscarNodo(Nodo *arbol,string busca){
    if(arbol==NULL){ return false; }
    else if(busca==arbol->palabra){ arbol->frecuencia++; return true; }
    else if(busca<arbol->palabra){buscarNodo(arbol->izq,busca);}
    else{ buscarNodo(arbol->der,busca); }//no esta vacio
    return false;
}

