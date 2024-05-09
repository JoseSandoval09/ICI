// 16.3 arbol binario caracteres.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Nodo {
	char dato;
	Nodo* der;
	Nodo* izq;
	Nodo *padre;
};
Nodo* arbol = NULL;

Nodo* crearNodo(char ,Nodo *);
void insertarNodo(Nodo*&,char,Nodo *);
bool busqueda(Nodo*,char);
void preorden(Nodo*);
void inorden(Nodo*);
void postorden(Nodo*);
void menu();

int main() {
	menu();

	getchar();
	return 0;
}

Nodo *crearNodo(char n,Nodo *padre){

    Nodo *nuevo = new Nodo();

    nuevo->dato = n;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->padre = padre;
    return nuevo;
}

void insertarNodo(Nodo *&arbol,char n, Nodo *padre){
    if(arbol==NULL){
        arbol = new Nodo();
        arbol = crearNodo(n,padre);
    }
    else{
        char valorRaiz = arbol->dato;

        if(n<valorRaiz){ insertarNodo(arbol->izq,n, arbol); }
        else{ insertarNodo(arbol->der, n, arbol); }
    }
}

bool busqueda(Nodo *arbol,char busca){
    if(arbol==NULL){ return false; }
    else if(busca==arbol->dato){ return true; }
    else if(busca<arbol->dato){busqueda(arbol->izq,busca);}
    else{ busqueda(arbol->der,busca); }//no esta vacio
    return false;
}
void preorden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout << arbol->dato << " - ";
		preorden(arbol->izq);
		preorden(arbol->der);
	}
}
void inorden(Nodo* arbol) {
	if (arbol = NULL) {
		return;
	}
	else {
		inorden(arbol->izq);
		cout << arbol->dato << " - ";
		inorden(arbol->der);
	}
}
void postorden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		postorden(arbol->izq);
		postorden(arbol->der);
		cout << arbol->dato << " - ";
	}
}
void menu() {
	int cont = 0;
	string op;
	do {
		cout << "\t.:MENU:." << endl;
		cout << "I: Insertar un nuevo nodo" << endl;
		cout << "B: Buscar un elemento en el arbol" << endl;
		cout << "RE: Recorrer el arbol en INORDEN" << endl;
		cout << "RP: Recorrer el arbol en PREORDEN" << endl;
		cout << "RT: Recorrer el arbol en POSTORDEN" << endl;
		cout << "SA: Salir" << endl;
		cout << "Seleccion--->";
		cin >> op;

		if(op=="I"){
            char c;
            cout << "\nInserte un caracter: ";
			cin >> c;
			insertarNodo(arbol,c,NULL);
			cout << "\n";
		}//caso insertar

		if(op=="B"){
            char c;
			cout << "\nIngresa caracter a buscar: ";
			cin >> c;
			if (busqueda(arbol, c) == true) {
				cout << "\n" << c << " ha sido encontrado." << endl;
			}
			else {
				cout << "\nElemento no encontrado." << endl;
			}
		}//caso buscar

        if(op=="RE"){
            cout << "\nRecorriendo en Preorden: \n";
			preorden(arbol);
			cout << "\n\n";
        }//recorrido en orden


		if(op=="RP"){
            cout << "\nRecorriendo en Inorden: \n";
			inorden(arbol);
			cout << "\n\n";
		}//recorrido en preorden

		if(op=="RT"){
            cout << "\nRecorrido en Postorden: \n";
			postorden(arbol);
			cout << "\n\n";
		}//recorrido en postorden

		if(op=="SA"){
			cout << "\n        .:PROGRAMA REALIZADO POR :.          ";
			cout << "\nAngel David Ortiz Quiroz            ID:261481";
			cout << "\nErick Ivan Ramirez Reyes            ID:260806";
			cout << "\nXimena Rivera Delgadillo            ID:261261";
			cout << "\nJose Luis Sandoval Perez            ID:261731";
			cout << "\nDiego Emanuel Saucedo Ortega        ID:261230";
			cout << "\n";
		}//Salir

		system("pause");
		system("cls");
	} while (op != "SA");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
