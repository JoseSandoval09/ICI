//LISTA CIRCULAR SIMPLE
//PROYECTO 2 parcial II
//PROGRAMA II
//Estructuras Computacionales 2°A (PARCIAL 2)
/*
Ángel David Ortiz Quiroz        ID: 261481
Ximena Rivera Delgadillo        ID: 261261
Erick Ivan Ramirez Reyes        ID: 260806
Diego Emanuel Saucedo Ortega    ID: 261230
Jose Luis Sandoval Perez        ID: 261731
Carlos Daniel Torres Macias     ID: 244543
*/
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
}*inicio,*fin;

void insertar(){
    if(inicio==NULL){
        inicio = new Nodo();
        cout<<"Ingresa el nuevo dato: ";
        cin >> (inicio->dato);
        inicio->sig=inicio;
    }//el nodo esta vacio
    else if(fin==NULL){
        fin = new Nodo();
        cout<<"Ingresa el nuevo dato: ";
        cin >> (fin->dato);
        fin->sig=inicio;
        inicio->sig=fin;
    }
    else{
        Nodo *nuevo= new Nodo();
        cout<<"Ingresa el nuevo dato: ";
        cin >> (nuevo->dato);
        fin->sig=nuevo;
        nuevo->sig=inicio;
        fin=nuevo;
    }

	cout<<"\n Nodo insertado completamente\n\n";
}

void mostrar(){
	Nodo *actual=new Nodo();
	actual=inicio;
	if (inicio!=NULL){
		int op;
		do{
            cout<<"\nLISTA CIRCULAR SIMPLE\n\n";
            cout<<"El dato actual es: "<<actual->dato<<endl;
            cout << "---------------------------------------------------------------------------------\n";
            cout<<"1.Mostrar dato siguiente\n";
            cout<<"2.Salir\nOpcion: ";
            cin>>op;
            switch(op){
                case 1:
                    actual=actual->sig;
                    break;
                case 2:
                    break;
                default:
                    cout<<"No es una opcion valida\n";
                    break;
            }//fin switch

            system("pause");
            system("cls");
		}while(op!=2);
	}
	else{
		cout<<"\n No hay elementos en la lista \n\n";
	}
}

void eliminar(){
    if(inicio==NULL){cout<<"No hay elementos por borrar\n"; return;}
    Nodo *actual= new Nodo();
    if(inicio->sig==fin){
        inicio->sig=inicio;
        actual=fin;
        delete actual;
        fin=NULL;
    }
    else if(inicio->sig==inicio){
        inicio=NULL;
    }
    else{
        actual=inicio;
        fin->sig=inicio->sig;
        inicio=inicio->sig;
        delete actual;
    }
}

int main(){
	int op,nodos;

	inicio=NULL;
	fin=NULL;

	do{
        cout<<"1.Insertar nodo"<<endl;
        cout<<"2.Mostrar lista"<<endl;
        cout<<"3.Eliminar inicio"<<endl;
        cout<<"4.Salir "<<endl;
        cout<<"Opcion: ";
        cin>>op;
        switch (op){
            case 1:
                insertar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                cout<<"Poder decir adios, es crecer...\n";
                cout << "---------------------------------------------------------------------------------\n";
                break;
            default:
                cout<<"No es una opcion\n";
                cout << "---------------------------------------------------------------------------------\n";
                break;
        }//fin switch

        system("pause");
        system("cls");
	}while(op!=4);

    cout << "PROGRAMA HECHO POR:" << endl;
    cout << "Angel David Ortiz Quiroz        ID : 261481" << endl;
    cout << "Ximena Rivera Delgadillo        ID : 261261" << endl;
    cout << "Erick Ivan Ramirez Reyes        ID : 260806" << endl;
    cout << "Diego Emanuel Saucedo Ortega    ID : 261230" << endl;
    cout << "Jose Luis Sandoval Perez        ID : 261731" << endl;
    cout << "Carlos Daniel Torres Macias     ID : 244543" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    system("pause");
	return 0;
}
