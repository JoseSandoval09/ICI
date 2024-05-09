#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Carlos Leonardo Cruz Ortiz

// No tuve mucho tiempo de hacer este ejercicio porque me centre mas en la manipulacion de archivos
// la de F1 Y F2

struct Tree{
    int Amount;
    short id;
    string Articulo;
    Tree *Left = NULL, *Right = NULL; 
    Tree *Parent = NULL;
}
*Root = NULL;

Tree *CreateNode(int Amount, Tree *Parent, string Articulo, short id){
    Tree *NewNode = new Tree(); // Creamos una nueva rama del árbol
    NewNode->Amount = Amount;
    NewNode->Articulo = Articulo;
    NewNode->id = id;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Parent = Parent;
    
    return NewNode; // Retornamos el nodo creado
}

void Insert(Tree *&Root, int Amount, Tree *Parent, string Articulo, short id){
    if(Root == NULL)
    {
        Tree *Node = CreateNode(Amount,Parent, Articulo, id); 
        Root = Node; 

    }else if(id != Root->id) 
    {
            if(id < Root->id) 
                Insert(Root->Left, Amount,Root, Articulo, id); // Insertamos en la izquierda
            else 
                Insert(Root->Right, Amount,Root, Articulo, id);  // Insertamos en la derecha
    }else{
        cout<<"El id ya existe"<<endl; 
        system("pause");
    }
}

bool Search(Tree *Root, short id){
    if(Root == NULL) 
        return false; 
    else if(id == Root->id) 
        return true; 
    else if(id < Root->id) 
        return Search(Root->Left, id); 
    else 
        return Search(Root->Right, id); 
}

void ShowTree(Tree *Root){
    if(Root == NULL)
        return; 
    else
    {
        ShowTree(Root->Left);
        cout<<"Nombre del articulo: "<<Root->Articulo<<"\nCantidad: "<<Root->Amount<<"\nID: "<< Root->id<<"\n\n";
        ShowTree(Root->Right);  
    }
}

Tree *SearchLess(Tree *Root){
    if(Root == NULL)
        return NULL; 
    if(Root->Left)
        return SearchLess(Root->Left); 
    else
        return Root;
}

void Replace(Tree *&Root, Tree *Node){
    if(Root->Parent){
        if(Root->id == Root->Parent->Left->id)
        {
            Root->Parent->Left = Node; // Reemplazamos el nodo izquierdo
        }
        else if(Root->id == Root->Parent->Right->id)
        {
            Root->Parent->Right = Node; // Reemplazamos el nodo derecho
        }
    }
    if(Node){
        Node->Parent = Root->Parent; // Reemplazamos el nodo padre
    }
}

void Destroy(Tree *node)
{
    node->Left = NULL;
    node->Right = NULL;
    delete node;
}

void DeleteNode(Tree *node){
    if(node->Left && node->Right)
    {
        Tree *Less = SearchLess(node->Right); 
        node->id = Less->id; 
        DeleteNode(Less); 
    }
    else if(node->Left) 
    {
        Replace(node, node->Left); 
        Destroy(node); 
    }
    else if(node->Right) 
    {
        Replace(node, node->Right); 
        Destroy(node); 
    }
    else 
    {
        Replace(node, NULL); 
        Destroy(node); 
    }
}

void Delete(Tree *Root, short id){
    if(Root == NULL) 
        return; 
    else if(id < Root->id) 
        Delete(Root->Left, id); 
    else if(id > Root->id) 
        Delete(Root->Right, id);
    else{
        DeleteNode(Root);
    }
}

void MainMenu(){
    int Choice, x;
    short id;
    char articulo[100];

    do{
        system("cls");
        cout<<"Programa de arboles"<<endl;
        cout<<"\n1. Almacenar articulos"<<endl;
        cout<<"2. Ver almacen"<<endl;
        cout<<"3. Eliminar"<<endl;
        cout<<"4. Salir\n"<<endl;
        cout<<"-->"; cin>>Choice;
        system("cls");

        switch (Choice)
        {
        case 1:
            cout<<"Si quiere salir inserte n"<<endl;
            do{
                
                cout<<"Inserte el nombre del articulo: "<<endl;
                cout<<"-->";   cin.ignore(); cin.getline(articulo, 100);
                if(strcmp(articulo, "n") == 0)
                    break;

                do{
                    cout<<"Inserte la cantidad del articulo: "<<endl;
                    cout<<"-->"; cin>>x;
                }while(x <= 0);

                do{
                cout<<"Inserte el id del articulo: "<<endl;
                cout<<"-->";  cin>>id;
                }while(id < 0);
                
                Insert(Root, x, NULL, articulo, id);

                system("cls");

            }while(true);
            break;

        case 2:
            ShowTree(Root); // Imprime el arbol
            cout<<endl;
            system("pause");
            break;

        case 3:
            ShowTree(Root); // Imprime el arbol

            cout<<"Para eliminar ponga su ID: "; cin>>id;
            Delete(Root, id);
            break;
        }
    }while(Choice != 4);
}

int main(){
    MainMenu();
    return 0;
}
