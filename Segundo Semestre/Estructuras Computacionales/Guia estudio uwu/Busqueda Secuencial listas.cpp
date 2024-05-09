// UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
// ESTRUCTURAS COMPUTACIONALES II
// PROYECTO FINAL 3ER PARCIAL
// INTEGRANTES: 

// Carlos Leonardo Cruz Ortiz ID: 261696
// Leslie Miroslava Benítez Marín ID: 183817
// César Eduardo Elias del Hoyo ID: 262045

// ACTIVIDA 5
// Busqueda Secuencial listas

#include <bits/stdc++.h>
using namespace std;

struct List{
    int data;
    List *next = NULL;
}*root = NULL;

int main(){
    
    srand(time(NULL));

    List *aux;

    for (int i = 0; i < 10; i++)
    {
        List *aux = new (nothrow) List();
        if(aux)
        {
            if(root == NULL)
            {
                aux->data = rand()%100 + 1;
                aux->next = NULL;
                root = aux;
            }
            else
            {
                aux->data = rand()%100 + 1;
                aux->next = root;
                root = aux;
            }
        }
    }


    aux = root;

    do
    {
        cout<<aux->data<<", ";
        aux = aux->next;
    } while (aux->next != NULL);
    cout<<aux->data<<endl;

    cout<<"Numero a buscar: ";
    int num;
    cin>>num;

    aux = root;

    while(aux != NULL)
    {
        if(aux->data == num)
        {
            cout<<"El numero "<<num<<" se encuentra en la lista"<<endl;
            break;
        }
        aux = aux->next;
    }

    if(aux == NULL)
    {
        cout<<"El numero "<<num<<" no se encuentra en la lista"<<endl;
    }


    system("pause");

    return 0;
}
