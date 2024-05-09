
//JOSE LUIS SANDOVAL PEREZ 2A
//ESTRUCTURAS COMPUTACIONALES
//TAREA PILAS CON LISTAS


#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
} *tope,*tmp,*inicio;



//prototipo de funciones

void push(){
    tmp= new nodo();
    cout<<"Inserta un valor: ";
    cin>>tmp->dato;
    tmp->sig= tope;
    tope=tmp;
}

void pop(){
    if(tope != NULL){
        cout<<"Elemento eliminado: "<<tope->dato;
        tmp=tope;
        tope=tope->sig;
        delete tmp;
    }
    else{
        cout<<"No hay elementos a borrar :v ";

    }

}

void imprepila(){
    tmp=tope;
    while(tmp!=NULL){
        cout<<"\n";
        cout<<tmp->dato;
        tmp=tmp->sig;
    }
}

int main(){

    tope=0;
    inicio = NULL;
    int op;

    do{

        cout<<"\n----MENU----"<<endl;
        cout<<"1.Insertar elementos."<<endl;
        cout<<"2.Eliminar elementos."<<endl;
        cout<<"3.Mostrar pila"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"\n\n\nSELECIONE UNA OPCION: ";
        cin>>op;

        switch(op){

            case 1:{
                push();

                break;
            }

            case 2:{
                pop();
               
                break;

            }

            case 3:{
            
                cout<<"Elementos de la pila:\t ";
                imprepila();

                
                break;

            }
            case 4:{
                cout<<"Decidiste salir, adios ";
            }

            default:
            cout<<"Opcion invalida";
        }



    }while(op!=3);



}