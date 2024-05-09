//JOSE LUIS SANDOVAL PEREZ 2°A ICI
//EXAMEN PARCIAL 2 ESTRUCTURAS COMPUTACIONALES II 
//PROBLEMA 11.3

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct nodo{
    char dato;
    struct nodo *sgte;
};

typedef struct nodo *CNPila;


CNPila crearNodo(char x)
{
    CNPila newNodo = new(struct nodo);
    newNodo->dato = x;
    return newNodo;
}

void push(CNPila &top, char x)
{
    CNPila aux = crearNodo(x);
    aux->sgte = top;
    top = aux;
}

char pop(CNPila &top)
{
    int c ;
    CNPila aux;
     
    aux = top ;
    c = aux->dato;  
    top = aux->sgte ;
    delete(aux);
    return c;
}

void balanceoSimbolos( CNPila &p, string cad)
{
    CNPila aux;
    int i = 0;
     
    while( cad[i] != '\0')
    {
        if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
        {
            push( p, cad[i] );          
            }
        else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
        {
            aux = p;
                 
            if(aux!=NULL)
            {
                if( cad[i]==')' )
                {
                    if( aux->dato == '(')
                    pop( p );
                }
                else if( cad[i]==']' )
                {
                    if( aux->dato == '[')
                    pop( p );
                }
                else if( cad[i]=='}' )
                {
                    if( aux->dato == '{')
                    pop( p );
                }        
            }
            else{
                push( p, cad[i] );
            }
        }
        i++;           
    }
     
    if(p==NULL){
        cout<<"ERES UN GENIO \n\tEquilibrio correcto de parentesis dentro de la expresion"<<endl;
    }
    else{
        cout<<"\n\t No hay equilibrio correcto en la expresion"<<endl;          
    }
     
}



int main()
{
        
    
    CNPila pila = NULL;    
    string cadena;
        
    cout << " Ingrese expresion: ";
    getline(cin, cadena);
        
    balanceoSimbolos( pila, cadena );
        
    cout<<"\n\n";
    system("pause");
    system("cls");

    cout<<"JOSE LUIS SANDOVAL PEREZ :)";
    
    
    return 0;
}