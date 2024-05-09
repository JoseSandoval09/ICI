#include<iostream>
#include<stdlib.h>

using namespace std;

const int MAX = 5;
int pila[MAX], tope =0;

//prototipo de funciones

void push(){
    if(tope<MAX){
        cout<<"Dame un elemento a insertar: ";
        cin>>pila[tope];
        tope++;
    }
    else{
        cout<<"No hay espacio en la pila";
    }

}

void pop(){
    if(tope>0){
        tope--;
        cout<<"Elemento eliminado: ";
        cout<<pila[tope];
    }
}

void imprepila(){
    for (int i =tope-1;i>0;i--){
        cout<<pila[i]<<" ,";
    }
}

int main(){

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