
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;



struct Tree{
    int Number;
    Tree *Left = NULL, *Right = NULL;
}
*Root = NULL;

Tree *CreateNode(int Number){
    Tree *NewNode = new Tree(); // Creamos una nueva rama del árbol
    NewNode->Number = Number;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
   
    return NewNode; // Retornamos el nodo creado
}

void Insert(Tree *&Root, int Number){
    if(Root == NULL)
    {
        Tree *Node = CreateNode(Number); // Creamos un nodo
        Root = Node; // Lo insertamos en la raíz

    }else if(Number != Root->Number) // Si el numero es diferente al numero de la raíz
    {
        if(Number < Root->Number) // Si el numero es menor que el numero de la raíz
            Insert(Root->Left, Number); // Insertamos en la izquierda
        else
            Insert(Root->Right, Number);  // Insertamos en la derecha
    }else{
        cout<<"El numero ya existe"<<endl; // Si el numero es igual al numero de la raíz
        system("pause");
    }
}

void MainMenu(){
    int Choice, x;

    do{
        system("cls");
        cout<<"Programa de arboles"<<endl;
        cout<<"\n1. Rellenar el arbol"<<endl;
        cout<<"2. Salir\n"<<endl;
        cout<<"-->"; cin>>Choice;
        system("cls");

        switch (Choice)
        {
        case 1:
            cout<<"Si quiere salir inserte presione 0"<<endl;
            do{
                cout<<"Inserte el numero para agregar: "<<endl;
                cin>>x;
                if(x != 0)
                    Insert(Root, x);
                system("cls");

            }while(x != 0);
            break;
        }
    }while(Choice != 2);
}

int main(){
    MainMenu();
    return 0;
}