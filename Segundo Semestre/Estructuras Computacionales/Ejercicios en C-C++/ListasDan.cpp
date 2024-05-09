#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


using namespace std;




struct Nodo {
    int dato;
    Nodo* siguiente;
};

void menu();
void inserLista(Nodo*&, int);
void mostLista(Nodo*);
void buscarLista(Nodo*, int);
void eliminarNodo(Nodo*, int);
Nodo* lista = NULL;


int main()
{
    menu();
    return 0;
}
void menu() {
    int op, dato;

    do {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar elementos a la lista de id's\n";
        cout << "2. Mostrar elementos de lista de id's\n";
        cout << "3. Buscar un elemento entre la lista de registros\n";
        cout << "4. Eliminar un elemento de la lista\n";
        cout << "5. Salir\n";
        cin >> op;

        switch (op) {
        case 1: cout << "Digite un numero: ";
            cin >> dato;
            inserLista(lista, dato);
            system("pause");
            break;
        case 2: mostLista(lista);
            cout << "\n";
            system("pause");
            break;
        case 3: cout << "Digite el ID que desea buscar: ";
            cin >> dato;
            buscarLista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 4: cout << "Digite el ID que desea eliminar: ";
            cin >> dato;
            eliminarNodo(lista, dato);
            cout << "\nListo";
            system("pause");
        }
        system("cls");
    } while (op != 5);
}
void inserLista(Nodo*& lista, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo* aux1 = lista;
    Nodo* aux2 = nullptr;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;

    }
    if (lista == aux1) {
        lista = nuevo_nodo;
    }
    else {
        aux2->siguiente = nuevo_nodo;

    }
    nuevo_nodo->siguiente = aux1;

    cout << "Elemento " << n << " insertado correctamente a la lista\n";
}
void mostLista(Nodo* lista) {
    Nodo* actual = new Nodo();
    actual = lista;
    while (actual != NULL) {
        cout << actual->dato << " \n ";
        actual = actual->siguiente;

    }

}
void buscarLista(Nodo* lista, int n) {
    bool band = false;

    Nodo* actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n)) {
        if (actual->dato == n) {
            band = true;
        }
        actual = actual->siguiente;
    }

    if (band == true) {
        cout << "Elemento " << n << " SI ha sido registrado en la lista\n";
    }
    else {
        cout << "Elemento " << n << " NO ha sido registrado en la lista\n";
    
    }
}
void eliminarNodo(Nodo* lista, int n) {
    if (lista != NULL) {
        Nodo* aux_borrar = nullptr;
        Nodo* anterior = NULL;

        aux_borrar = lista;


        //Recorre la lista;
        while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        //Elemento no ha sido encontrado
        if (aux_borrar == NULL) {
            cout << "Elemento no encontrado\n";
        }

        //EL primer elemento es el que se va a eliminar
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux_borrar;
        }

        //El elemento está en la lista, pero no es el primer nodo
        else {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
     }
}