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

#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {
    int dato;
    struct node* sig;
};


struct node* inicio, * tmp;


int main() {

    int numnod = 0, op = 0;
    cout << "El siguiente programa nos permitira conocer el funcionamiento de listas simples" << endl;
    cout << "pedirmitiendo crear nodos infinitos en una lista asi como recorrer la lista creada" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");

    while (op != 5) {
        cout << "\tM E N U" << endl;
        cout << "1. Agregar nodos a la LISTA" << endl;
        cout << "2. Recorrer nodos de la LISTA" << endl;
        cout << "3. Buscar un nodo en la LISTA" << endl;
        cout << "4. Eliminar un nodo en l LISTA" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingresa una opcion: "; cin >> op;
        cout << "---------------------------------------------------------------------------------\n";
        system("pause");
        system("cls");
        if (op == 1) {
            cout << "A G R E G A R nodos a la L I S T A" << endl;
            if (numnod == 0) {
                inicio = new struct node();
                cout << "Ingresa el valor que deseas que tenga el nodo en la lista: "; cin >> inicio->dato;
                inicio->sig = NULL;
                numnod++;
            }
            else {
                tmp = new node();
                cout << "Ingresa el valor que deseas que tenga el nodo en la lista: "; cin >> tmp->dato;
                tmp->sig = inicio;
                inicio = tmp;
                numnod++;
            }
            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
        if (op == 2) {
            cout << "R E C O R R E R nodos de la lista" << endl;
            if (numnod == 0) {
                cout << "ERROR, no hay nodos en la lista" << endl;
            }
            else {
                tmp = inicio;
                while (tmp != NULL) {
                    cout << tmp->dato;
                    cout << endl;
                    tmp = tmp->sig;
                }
            }
            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
        if (op == 3) {
            cout << "B U S C A R un nodo en la lista" << endl;
            tmp = inicio;
            int value;
            if(numnod==0){
                cout << "ERROR, no hay nodos en la lista" << endl;
            }
            else{
                cout << "Ingresa el nodo que deseas buscar: "; cin >>value;
                if (tmp->dato!= value && tmp!= NULL)
                {
                   cout << "No existe el nodo "<< value << " en la lista" << endl;

                }
                else {
                    cout << "El nodo "<< value << " si se encuentra en la lista" << endl;
                }
            }

            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
        if (op == 4) {
            cout << "E L I M I N A R un nodo en la lista" << endl;
            tmp = inicio;
            int value;

            if(numnod==0){
                cout << "ERROR, no hay nodos en la lista" << endl;
            }
            else{
                cout << "Ingresa el nodo que deseas eliminar: "; cin >> value;
                if (tmp->dato != value && tmp != NULL)
                {
                    while (tmp->sig->dato != value && tmp->sig != NULL)
                    {
                        tmp = tmp->sig;
                    }

                    if (tmp->sig == NULL)
                    {
                        cout << "No existe el nodo " << value << " en la lista" << endl;
                    }
                    else
                    {
                        node* tmp2, * tmp3;
                        tmp2 = tmp->sig;
                        tmp3 = tmp->sig->sig;

                        tmp->sig = tmp3;
                        delete(tmp2);
                        cout << "El nodo " << value << " ha sido eliminado de la lista" << endl;
                        numnod--;
                    }
                }
                else
                {
                    inicio = inicio->sig;
                    delete(tmp);
                    cout << "El nodo " << value << " ha sido eliminado de la lista" << endl;
                    numnod--;
                }
            }

            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "PROGRAMA HECHO POR:" << endl;
    cout << "Angel David Ortiz Quiroz        ID : 261481" << endl;
    cout << "Ximena Rivera Delgadillo        ID : 261261" << endl;
    cout << "Erick Ivan Ramirez Reyes        ID : 260806" << endl;
    cout << "Diego Emanuel Saucedo Ortega    ID : 261230" << endl;
    cout << "Jose Luis Sandoval Perez        ID : 261731" << endl;
    cout << "Carlos Daniel Torres Macias     ID : 244543" << endl;
    system("pause");
    system("cls");
    return 0;
}

