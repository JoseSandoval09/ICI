/*
            Programas de arboles de programacion ATS
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//Prototipos
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;

int main(){
	menu();

	getch();
	return 0;
}

//Funcion de menu
void menu(){
	int dato,opcion,contador=0;

	do{
		cout<<"Dentro de los videojuegos actuales el jugador \npuede regresar en el 'tiempo' o misiones y \ncrear guardados desde el 'pasado' de esta \nmanera se crean puntos de guardado con \nramificaciones, el siguiente programa \nes una representacion de ello"<<endl<<endl;



		cout<<"1. Insertar nivel/mision de punto de guardado"<<endl;
		cout<<"2. Mostrar arbol de las partidas guardadas"<<endl;
		cout<<"3. Buscar un nivel desde la partida guardada"<<endl;

		cout<<"4. Eliminar una partida"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;

		switch(opcion){
			case 1: cout<<"\nDigite una nivel/mision de punto de guardado: ";
					cin>>dato;
					insertarNodo(arbol,dato,NULL); //Insertamos un nuevo nodo
					cout<<"\n";
					system("pause");
					break;
			case 2: cout<<"\nMostrando arbol de las partidas guardadas:\n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\nPartida a buscar desde nivel: ";
					cin>>dato;
					if(busqueda(arbol,dato) == true){
						cout<<"\nPartida "<<dato<<" a sido encontrada en la memoria\n";
					}
					else{
						cout<<"\nPartida no encontrada\n";
					}
					cout<<"\n";
					system("pause");
					break;
			case 4: cout<<"\nPartida a eliminar: ";
					cin>>dato;
					eliminar(arbol,dato);
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 5);
}

//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol == NULL){ //Si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol = nuevo_nodo;
	}
	else{ //Si el arbol tiene un nodo o mas
		int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
		if(n < valorRaiz){ //Si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq,n,arbol);
		}
		else{//Si el elemento es mayor a la raiz, insertamos en der
			insertarNodo(arbol->der,n,arbol);
		}
	}
}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){ //Si el arbol esta vacio
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol,int n){
	if(arbol == NULL){ //si el arbol esta vacio
		return false;
	}
	else if(arbol->dato == n){ //Si el nodo es igual al elemento
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}







//Eliminar un nodo del arbol
void eliminar(Nodo *arbol,int n){
	if(arbol == NULL){ //Si el arbol esta vacio
		return; //No haces nada
	}
	else if(n < arbol->dato){ //Si el valor es menor
		eliminar(arbol->izq,n); //Busca por la izq
	}
	else if(n > arbol->dato){ //Si el valor es mayor
		eliminar(arbol->der,n); //Buscar por la der
	}
	else{ //Si ya encontraste el valor
		eliminarNodo(arbol);
	}
}

//Funcion para determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){ //Si el arbol esta vacio
		return NULL; //retornas nulo
	}
	if(arbol->izq){ //Si tiene hijo izq
		return minimo(arbol->izq); //buscamos la parte mas izq posible
	}
	else{ //Si no tiene hijo izq
		return arbol; //retornamos el mismo nodo
	}
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//Procedemos a asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

//Funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;

	delete nodo;
}

//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){ //Si el nodo tiene hijo izq y der
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){ //Si tiene hijo izq
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){ //Si tiene un hijo der
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{ //No tiene hijos
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}
