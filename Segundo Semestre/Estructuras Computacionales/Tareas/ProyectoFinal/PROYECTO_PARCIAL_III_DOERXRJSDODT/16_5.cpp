#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};


Nodo *arbol=NULL;




Nodo *crearNodo (int, Nodo *);
void insertar(Nodo *&,int,Nodo *);
void mostrar(Nodo *,int);
bool busqueda(Nodo *, int);
void preorden(Nodo *);
void inorden(Nodo *);
void postorden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo* );
void destruir(Nodo *);
void menu();



int main(){
	menu();
	
	cout << "\n        .:PROGRAMA REALIZADO POR :.          ";
	cout << "\nAngel David Ortiz Quiroz            ID:261481";
	cout << "\nErick Ivan Ramirez Reyes            ID:260806";
	cout << "\nXimena Rivera Delgadillo            ID:261261";
	cout << "\nJose Luis Sandoval Perez            ID:261731";
	cout << "\nDiego Emanuel Saucedo Ortega        ID:261230";
	cout << "\n";


	getchar();
	return 0;
}
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre;
	return nuevo_nodo;
}
void insertar(Nodo *&arbol, int n,Nodo *padre){
	if (arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n,padre);
		arbol=nuevo_nodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if (n<valorRaiz){
			insertar(arbol->izq,n,padre);
		}
		else{
			insertar(arbol->der,n,padre);
		}
	}
}

void mostrar(Nodo *arbol,int cont){
	if (arbol==NULL){
		return;
	}
	else{
		mostrar(arbol->der,cont+1);
		for (int i=0;i<cont;i++){
			cout<<"  ";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq,cont+1);
	}
}

bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if (arbol->dato==n){
		return true;
	}
	else if (n<arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

void preorden(Nodo *arbol){
	if (arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preorden(arbol->izq);
		preorden(arbol->der);
	}
}

void inorden(Nodo *arbol){
	if (arbol=NULL){
		return;
	}
	else{
		inorden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inorden(arbol->der);
	}
}
void postorden(Nodo *arbol){
	if (arbol==NULL){
		return;
	}
	else{
		postorden(arbol->izq);
		postorden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}
void eliminar(Nodo *arbol,int n){
	if (arbol==NULL){
		return;
	}
	else if(n<arbol->dato){
		eliminar(arbol->izq,n);
	}
	else if(n>arbol->dato){
		eliminar(arbol->der,n);
	}
	else{
		eliminar(arbol,n);
	}
}
Nodo *minimo(Nodo *arbol){
	if (arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}
void eliminarNodo(Nodo *nodoEliminar){
	if (nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruir(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruir(nodoEliminar);
	}
}
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq=nuevoNodo;
		}
		else if(arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre=arbol->padre;
	}
}
void destruir(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}

int Minimo(Nodo * raiz){

	if(raiz == NULL){
		cout<<" EL ARBOL ESTA VACIO";
	}

	Nodo* aux= raiz;
	aux=aux->izq;

	while(aux->izq !=NULL){
		aux=aux->izq;
	}


	cout<<"El nodo minimo es: "<<aux->dato<<endl;

	return aux->dato;

	cout<<"El nodo minimo es: "<<aux->dato<<endl;


}

int Maximo(Nodo * raiz){

	if(raiz == NULL){
		cout<<" EL ARBOL ESTA VACIO";
	}

	Nodo* aux= raiz;
	aux=aux->der;

	while(aux->der !=NULL){
		aux=aux->der;
	}

	cout<<"El nodo maximo es: "<<aux->dato<<endl;

	return aux->dato;

	cout<<"El nodo maximo es: "<<aux->dato<<endl;

}




void menu(){
	int dato,cont=0,op;
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en PREORDEN"<<endl;
		cout<<"5. Recorrer el arbol en INORDEN"<<endl;
		cout<<"6. Recorrer el arbol en POSTORDEN"<<endl;
		cout<<"7. Eliminar un nodo del arbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"9. Obtener nodo minimo"<<endl;
		cout<<"10. Obtener nodo maximo"<<endl;
		cout<<"Opcion: ";
		cin>>op;
			
	    switch (op){
		case 1:
			cout<<"\nInserte un numero: ";
			cin>>dato;
			insertar(arbol,dato,NULL);
			cout<<"\n";
			system("pause");
			break;
		case 2:
			cout<<"\nMostrando el arbol completo:\n\n";
			mostrar(arbol,cont);
			cout<<"\n";
			system("pause");
			break;
		case 3:
			cout<<"\nIngresa el elemento a buscar: ";
			cin>>dato;
			if (busqueda(arbol,dato)==true){
				cout<<"\nElemento "<<dato<<" ha sido encontrado."<<endl;
			}
			else{
				cout<<"\nElemento no encontrado."<<endl;
			}
			break;
		case 4:
			cout<<"\nRecorriendo en Preorden: \n";
			preorden(arbol);
			cout<<"\n\n";
			system("pause");
			break;
		case 5:
			cout<<"\nRecorriendo en Inorden: \n";
			inorden(arbol);
			cout<<"\n\n";
			system("pause");
			break;
		case 6:{
			cout<<"\nRecorrido en Postorden: \n";
			postorden(arbol);
			cout<<"\n\n";
			system("pause");
			break;
		}
		case 7:{
			cout<<"\nDigite el numero a eliminar: ";
			cin>>dato;
			eliminar(arbol,dato);
			cout<<"\n";
			system ("pause");
			break;
		}
		case 8:{
			cout<<"\nAdios";
			cout<<"\n";
			system ("pause");
			break;
		}
		case 9:{
			Minimo(arbol);
			system("pause");
			break;
		}
		case 10:{
			Maximo(arbol);
			system("pause");
			break;
		}	
	   }
	   
	   system ("cls");
	}while(op!=8);

}
