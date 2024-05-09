#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{

    int dato;
    Nodo *siguiente;

}

void menu();
void insertarlista(Nodo *&, int);
void mostrarlista(Nodo *);
void buscarlista(Nodo *, int);



int main(){





    
}

void menu(){

    int dato,opcion;

    do{
        cout<<"\t-----MENU-----";
        cout<<"1. Insertar elementos a la lista\n";
        cout<<"2. Mostrar los elementos de la lista \n"
        cout<<"3. Salir\n";
        cout<<"OPCION: \n"; cin>>opcion;

        swtich(opcion){

            case 1:{

                cout<<"Digite un numero: ";
                cin>>dato;
                insertardato(lista,dato);
                cout<<"\n";
                break;


            }
            case 2:{

                mostrarlista(lista);
                cout<<"\n";
                system("pause");
                break;


            }

            system("cls");


        }while (opcion!=3)
    }
}

void insertarlista(Nodo *&lista, int n){

    Nodo *nuevo_nodo= new nodo();

    nuevo_nodo-> = n;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2=aux1;
        aux1= aux1->siguiente;
    }

    if( lista == aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout<<"Elemento "<<n<<"insertado correctamente en la lista\n";

}
void mostrarlista(Nodo *lista){
    Nodo *actual= new nodo();
    actual=lista;

    while(actual != NULL){
        cout<<actual-><<"->";
        actual = actual->siguiente;

    }
}