#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;
struct Nodo{
	int dato;
	Nodo *anterior,*siguiente;
}

*inicio, *tmp;


int main(){


	inicio=new Nodo ();
	inicio->siguiente=inicio->anterior=NULL;
	inicio->dato=1;

	tmp=new Nodo();
	tmp->siguiente=inicio;
	inicio->anterior=tmp;
	tmp=inicio;
	tmp->anterior=NULL;
	tmp->dato=2;

	tmp=new Nodo();
	tmp->siguiente=inicio;
	inicio->anterior=tmp;
	tmp=inicio;
	tmp->anterior=NULL;
	tmp->dato=3;

	tmp=new Nodo();
	tmp->siguiente=inicio;
	inicio->anterior=tmp;
	tmp=inicio;
	tmp->anterior=NULL;
	tmp->dato=4;

	cout<<"Elementos de inicio a fin"<<endl;
	tmp=inicio;

	
	while (tmp->siguiente!=NULL){
		cout<<tmp->dato<<" , ";
		tmp=tmp->siguiente;
	}
	cout<<tmp->dato<<"\n";
	

	cout<<"Elementos de fin a inicio"<<endl;
	while (tmp!=NULL){
		cout<<tmp->dato<<" , ";
		tmp=tmp->anterior;
	}
	cout<<tmp->dato;

	int datobuscar;

	cout<<"Ingresa dato a buscar";
	cin>>datobuscar;

	tmp=inicio;
	while(tmp->dato!=datobuscar && tmp!=NULL){
		tmp=tmp->siguiente;
	}

	if(tmp->dato==datobuscar){
		cout<<"Dato encontrado";
	}



	return 0;	
}

