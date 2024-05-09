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

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
    long int num;
    nodo *sig;
};

nodo *inicio=NULL;

void sumarLargos(int,int);
void insertarNum(int);

int main(){
    cout<<"PROBLEMA:\nPara representar un entero largo, de mas de 30 digitos, utilizar una lista circular\n";
    cout<<"cuyos nodos tienen como atributo dato un digito del entero largo. Escribir un programa cuya entrada\n";
    cout<<"sea dos enteros largos y se obtenga su suma.\n";
    cout << "---------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");

    long int A,B;
    cout<<"Ingrese primer entero largo: "; cin>>A;
    cout<<"Ingrese segundo entero largo: "; cin>>B;
    system("pause");
        sumarLargos(A,B);
        cout<<"RESULTADO DE LA SUMA: ";
        nodo *t = new nodo();
        t=inicio;
        while(t!=NULL){
            cout<<t->num;
            t=t->sig;
        }//fin while
            cout<<endl;
        system("pause");
        system("cls");

    cout << "---------------------------------------------------------------------------------\n";
    cout << "PROGRAMA HECHO POR:" << endl;
    cout << "Angel David Ortiz Quiroz        ID : 261481" << endl;
    cout << "Ximena Rivera Delgadillo        ID : 261261" << endl;
    cout << "Erick Ivan Ramirez Reyes        ID : 260806" << endl;
    cout << "Diego Emanuel Saucedo Ortega    ID : 261230" << endl;
    cout << "Jose Luis Sandoval Perez        ID : 261731" << endl;
    cout << "Carlos Daniel Torres Macias     ID : 244543" << endl;
    system("pause");
return 0;
}

void sumarLargos(int A,int B){
    while(A>0 || B>0){
        int aux = (A%10) + (B%10);
        insertarNum(aux%10);
        A/=10; B/=10;
        if(aux>9){A+=aux/10;}
    }//fin while
}

void insertarNum(int N){
    if(inicio==NULL){
        inicio = new nodo();
        inicio->num = N;
        inicio->sig = NULL;
    }
    else{
        nodo *tmp = new nodo();
        tmp->num = N;
        tmp->sig = inicio;
        inicio = tmp;
    }
}
