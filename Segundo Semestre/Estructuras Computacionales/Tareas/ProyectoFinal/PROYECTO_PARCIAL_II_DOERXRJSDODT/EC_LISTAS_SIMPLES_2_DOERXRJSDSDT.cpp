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
    string name;
    struct node* sig;
};


struct node* inicio, * tmp;


int main() {

    int numnod = 0;
   
    cout << "El siguiente programa nos permitira conocer el funcionamiento de listas simples" << endl;
    cout << "permitiendo crear nodos infinitos en una lista asi como recorrer la lista creada" << endl;
    cout << "Este programa simulara una base de datos de nombres de trabajadores" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");
    int op=0;
    while (op != 4) {
        op=0;
        cout << "\tM E N U" << endl;
        cout << "1. Agregar Trabajadores a la LISTA" << endl;
        cout << "2. Desplegar trabajadores de la LISTA" << endl;
        cout << "3. Eliminar un trabajador en l LISTA" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingresa una opcion: "; 
        cin >> op;
        cout << "---------------------------------------------------------------------------------\n";
        system("pause");
        system("cls");
        if (op == 1) {
            cout << "A G R E G A R trabajadores a la L I S T A" << endl;
            if (numnod == 0) {
                inicio = new struct node();
                cout << "Ingresa el nombre del trabajador que deseas que tenga el en la lista(nombre seguido de un _ para ingresar apellido): "; cin >> inicio->name;
                inicio->sig = NULL;
                numnod++;
            }
            else {
                tmp = new node();
                cout << "Ingresa el nombre del trabajador que deseas que tenga el en la lista(nombre seguido de un _ para ingresar apellido): "; cin >> tmp->name;
                tmp->sig = inicio;
                inicio = tmp;
                numnod++;
            }
            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
        if (op == 2) {
            cout << "D E S P L E G A R  trabajadores de la lista" << endl;
            if (numnod == 0) {
                cout << "ERROR, no hay trabajadores en la lista" << endl;
            }
            else {
                tmp = inicio;
                while (tmp != NULL) {
                    cout << tmp->name;
                    cout << endl;
                    tmp = tmp->sig;
                }
            }
            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        }
        if (op == 3) {
            cout << "E L I M I N A R un trabajador en la lista" << endl;
            cout << "---------------------------------------------------------------------------------\n";
            if (numnod == 0) {
                cout << "ERROR, no hay trabajadores en la lista" << endl;
            }
            else{
            tmp = inicio;
            cout << "L I S T A E X I S T E N T E " << endl;
            for(int i=0; i<numnod;i++){
                
                while (tmp != NULL) {
                    cout << tmp->name;
                    cout << endl;
                    tmp = tmp->sig;
                }
            }
            
            string deletedname;
            cout << "Ingresa el nombre del trabajador que deseas eliminar: "; cin >> deletedname;
            if (tmp->name!= deletedname && tmp != NULL)
            {
                while (tmp->sig->name != deletedname && tmp->sig != NULL)
                {
                    tmp = tmp->sig;
                }

                if (tmp->sig == NULL)
                {
                    cout << "No existe el trabajador " << deletedname << " en la lista" << endl;
                }
                else
                {
                    node* tmp2, * tmp3;
                    tmp2 = tmp->sig;
                    tmp3 = tmp->sig->sig;

                    tmp->sig = tmp3;
                    delete(tmp2);
                    cout << "El trabajador " << deletedname << " ha sido eliminado de la lista" << endl;
                    numnod--;
                }
            }
            else
            {
                inicio = inicio->sig;
                delete(tmp);
                cout << "El trabajador " << deletedname << " ha sido eliminado de la lista" << endl;
                numnod--;
            }
            cout << "---------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
            }
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
