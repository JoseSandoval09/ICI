//JOSE LUIS SANDOVAL PEREZ 



#include<iostream>
#include<stdlib.h>
#include<conio.h>




using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

Nodo *arbol=NULL;
//FUNCIONES A USAR
void Menu();
Nodo *crearNodo(int);
void insertar(Nodo *&,int);
void Mostrar_Arbol(Nodo *, int);
bool buscar(Nodo *, int);
void pre_Orden(Nodo *);
void in_Orden(Nodo *);

//Funcion crear nodo

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo= new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;

    return nuevo_nodo;
}



//FUNCION INSERTAR ELMENTOS EN EL ARBOL
void insertar(Nodo *&arbol,int n){


    if(arbol==NULL){
        Nodo *nuevo_nodo= crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{

        int valorRaiz=arbol->dato;
        
        if(n<valorRaiz){
            insertar(arbol->izq,n);
        }
        else{
            insertar(arbol->der,n);
        }


    }

}
//Mostrar arbol
void Mostrar_Arbol(Nodo *arbol,int cont){
    if(arbol==NULL){
        return;
    }
    else{
        Mostrar_Arbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"  ";
        }
        cout<<arbol->dato<<endl;
        Mostrar_Arbol(arbol->izq,cont+1);
    }
}
//Buscar Nodos en el arbol
bool buscar(Nodo *arbol, int n){

    if(arbol==NULL){
        return false;
    }
    else if(arbol->dato==n){
        return true;
    }
    else if(n<arbol->dato){
        return buscar(arbol->izq,n);
    }
    else{
        return buscar(arbol->der,n);
    }
}
//Menu
void Menu(){

    int op,dato,cont=0;
    do{

        cout<<"MENU"<<endl;
        cout<<"1. Insertar nodo"<<endl;
        cout<<"2. Mostrar el arbol"<<endl;
        cout<<"3. Buscar un nodo"<<endl;
        cout<<"4. Recorrer arbol PreOrden"<<endl;
        cout<<"5. Recorrer arbol InOrden"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Elige una opcion: ";
        cin>>op;

        switch(op){
            case 1:{
                cout<<"\nIngrese numero para el nodo: ";
                cin>>dato;
                insertar(arbol,dato);
                cout<<"\n";
                system("pause");
                break;
            }
            case 2:{
                cout<<"Este es el arbol ingresado"<<endl;
                Mostrar_Arbol(arbol,cont);
                cout<<"\n";
                system("pause");
                break;
            }
            case 3:{
                cout<<"Nodo a buscar: ";
                cin>>dato;
                if(buscar(arbol,dato)==true){
                    cout<<"El nodo "<<dato<<" existe en el arbol";
                }
                else{
                    cout<<"El nodo "<<dato<<" no ha sido encontrado en el arbol";
                }
                cout<<"\n";
                system("pause");
                break;
            }
            case 4:{
                cout<<"P R E O R D E N"<<endl;;
                pre_Orden(arbol);
                cout<<"\n\n";
                system("pause");
            }
            case 5:{
                cout<<" I N O R D E N"<<endl;
                in_Orden(arbol);
                cout<<"\n\n";
                system("pause");
            }
            
        }
        system("cls");
        
    }while (op!=5);

}
//Recorrido preOrden
void pre_Orden(Nodo *arbol){
    if (arbol==NULL){
        return;
    }
    else{
        cout<<arbol->dato<<" - ";
        pre_Orden(arbol->izq);
        pre_Orden(arbol->der);
    }

}
void in_Orden(Nodo *Arbol){
    if(arbol==NULL){
        return;

    }
    else{
        in_Orden(arbol->izq);
        cout<<arbol->dato<<" - ";
        in_Orden(arbol->der);
    }
}

int main(){

    Menu();
    return 0;
}



