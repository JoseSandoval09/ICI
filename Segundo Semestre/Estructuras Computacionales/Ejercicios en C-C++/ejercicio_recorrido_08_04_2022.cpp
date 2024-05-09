#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;


struct arbol{
    arbol *izq=NULL, *der=NULL;
    char dato;
};

using namespace std;
arbol *raiz = new arbol;

void hijoDer(arbol*, char);
void hijoIzq(arbol*, char);
void inorden(arbol *);

int main(){
    raiz->dato='*';
    hijoIzq(raiz,'*');
    hijoIzq(raiz->izq,'A');
    hijoDer(raiz, 'C');
    hijoDer(raiz->izq->der, 'Y');
    hijoIzq(raiz->izq->der, 'X');

    inorden(raiz);
}

void hijoDer(arbol* dir, char val){
    if(dir->der!=NULL)
        dir->der->dato=val;
    else{
        arbol * temp = new arbol;
        dir->der = temp;
        temp->dato=val;
    }
}

void hijoIzq(arbol* dir, char val){
    if(dir->izq!=NULL)
        dir->izq->dato=val;
    else{
        arbol * temp = new arbol;
        dir->izq = temp;
        temp->dato=val;
    }
}

void inorden(arbol *dir){
    if(dir==NULL){
        return;
    } 
    
    inorden(dir->izq);
    inorden(dir->der); 
    cout<<dir->dato<< " ";//raiz   
}