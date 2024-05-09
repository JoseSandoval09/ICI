//PROYECTO 2 parcial II
//PROGRAMA LISTAS CIRCULAR DOBLEMENTE ENLAZADAS
//Estructuras Computacionales 2°A (PARCIAL 2)
/*
Ángel David Ortiz Quiroz        ID: 261481
Ximena Rivera Delgadillo        ID: 261261
Erick Ivan Ramirez Reyes        ID: 260806
Diego Emanuel Saucedo Ortega    ID: 261230
Jose Luis Sandoval Perez        ID: 261731
Carlos Daniel Torres Macias     ID: 244543
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

void insertarDespues();
void insertarAntes();
void eliminarNodo();
void mostrarLista();

nodo *inicio,*fin,*tmp;

int main(){

    inicio=NULL;
    fin=NULL;

    int op=-1;
    do{
        cout << "\tM E N U" << endl;
        cout<<"1.Insertar dato\n";
        cout<<"2.Borrar dato\n";
        cout<<"3.Mostrar lista\n";
        cout<<"4.Salir\nSeleccion--->";
        cout << "Ingresa una opcion: "; cin >> op;
        cout << "---------------------------------------------------------------------------------\n";
        system("pause");
        system("cls");

        if(op==1){
            if(inicio==NULL){
                inicio=new nodo();
                cout<<"Ingrese nuevo dato inicio--->";
                cin>>inicio->dato;
                inicio->ant=inicio;
                inicio->sig=inicio;
            }//no hay elementos en la pila

            else if(inicio->sig==inicio && inicio->ant==inicio){
                fin=new nodo();
                cout<<"Ingrese nuevo dato final--->";
                cin>>fin->dato;
                inicio->sig=fin;
                inicio->ant=fin;
                fin->sig=inicio;
                fin->ant=inicio;
            }//solo hay un elemento, se crea nodo de fin

            else{
                int opp=-1;
                tmp=inicio;
                do{
                    cout<<"Dato Actual: "<<tmp->dato<<endl;
                    cout<<"1.Mostrar dato siguiente\n";
                    cout<<"2.Mostrar dato anterior\n";
                    cout<<"3.Insertar nuevo dato antes del actual\n";
                    cout<<"4.Insertar nuevo dato despues del actual\n";
                    cout<<"5.Salir\nSeleccion--->";
                    cout << "---------------------------------------------------------------------------------\n";
                    system("pause");
                    system("cls");
                    cout << "Ingresa una opcion: "; cin>>opp;
                    if(opp==1){tmp=tmp->sig;}
                    if(opp==2){tmp=tmp->ant;}
                    if(opp==3){insertarAntes();}
                    if(opp==4){insertarDespues();}

                    system("pause");
                    system("cls");
                }while(opp!=5);
            }//hay elementos en la pila

        }//fin insertar dato

        if(op==2){
            if(inicio==NULL){cout<<"No hay elementos que eliminar.\n";}
            else{eliminarNodo();}//si hay elementos
        }//eliminar nodo

        if(op==3){
            if(inicio==NULL){cout<<"No hay elementos en la lista.\n";}
            else{mostrarLista();}//si hay elementos
        }//mostrar datos
        cout << "---------------------------------------------------------------------------------\n";
        system("pause");
        system("cls");
    }while(op!=4);
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

void insertarDespues(){
    if(tmp==fin){
        nodo *aux=new nodo();
        cout<<"Ingrese dato despues del final--->";
        cin>>aux->dato;
        aux->ant=fin;
        aux->sig=inicio;
        fin->sig=aux;
        inicio->ant=aux;
        fin=aux;
    }//es el ultimo elemento
    else{
        nodo *aux=new nodo();
        cout<<"Ingrese dato despues--->";
        cin>>aux->dato;
        aux->ant=tmp;
        aux->sig=tmp->sig;
        tmp->sig->ant=aux;
        tmp->sig=aux;
    }
}

void insertarAntes(){
    if(tmp==inicio){
        nodo *aux=new nodo();
        cout<<"Ingrese dato antes del inicio--->";
        cin>>aux->dato;
        aux->ant=fin;
        aux->sig=inicio;
        inicio->ant=aux;
        fin->sig=aux;
        inicio=aux;
    }//es el primer elemento
    else{
        nodo *aux=new nodo();
        cout<<"Ingrese dato antes--->";
        cin>>aux->dato;
        aux->ant=tmp->ant;
        aux->sig=tmp;
        tmp->ant->sig=aux;
        tmp->ant=aux;
    }
}

void eliminarNodo(){
    int op=-1;
    tmp=inicio;
    do{
        cout<<"Dato Actual: "<<tmp->dato<<endl;
        cout<<"1.Mostrar dato siguiente\n";
        cout<<"2.Mostrar dato anterior\n";
        cout<<"3.Eliminar dato actual\n4.Salir\n";
        cout<<"Seleccion--->";
        cin>>op;
        if(op==1){tmp=tmp->sig;}
        if(op==2){tmp=tmp->ant;}
        if(op==3){
            if(inicio->sig==inicio && inicio->ant==inicio){
                inicio=NULL;
            }
            else if (inicio->sig==fin && fin->ant==inicio){
                inicio=tmp->sig;
                inicio->sig=inicio;
                inicio->ant=inicio;
                fin=NULL;
            }
            else if(tmp==inicio){
                nodo *aux=new nodo();
                aux=inicio;
                aux->sig->ant=fin;
                aux->ant->sig=aux->sig;
                inicio=aux->sig;
                delete aux;
            }//esta al "inicio"
            else if(tmp==fin){
                nodo *aux=new nodo();
                aux=fin;
                aux->sig->ant=aux->ant;
                aux->ant->sig=inicio;
                fin=aux->ant;
                delete aux;
            }//esta al "final"
            else{
                nodo *aux=new nodo();
                aux=tmp;
                aux->sig->ant=aux->ant;
                aux->ant->sig=aux->sig;
                delete aux;
            }//es "intermedio"
            tmp=inicio;
        }//fin elimina nodo

        system("pause");
        system("cls");
    }while(op!=4 && inicio!=NULL);
    if(inicio==NULL){cout<<"Al parecer ya no tienes mas elementos\n";}
}

void mostrarLista(){
    int op=-1;
    tmp=inicio;
    do{
        cout<<"Dato Actual: "<<tmp->dato<<endl;
        cout<<"1.Mostrar dato siguiente\n";
        cout<<"2.Mostrar dato anterior\n";
        cout<<"3.Salir\nSeleccion--->";
        cin>>op;
        if(op==1){tmp=tmp->sig;}
        if(op==2){tmp=tmp->ant;}

        system("pause");
        system("cls");
    }while(op!=3);
}
