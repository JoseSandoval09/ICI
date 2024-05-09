/*
JOSE LUIS SANDOVAL PEREZ 2A ICI 
ESTRUCTURAS COMPUTACIONALES
TAREA 4 RECURSIVIDAD
-PROGRAMA FACTORIAL
-PROGRAMA SUMA
-PROGRAMA LIBRE 
*/

#include<iostream>
#include<stdio.h>
#include <string>
#include <cstdlib>

using namespace std;


//Funcion recursiva ejercicio factorial
double Fact(int n){
    if(n==1){
        return 1;
    }

    return n * Fact(n-1);
}
//Funcion recursiva ejercicio suma 
int Suma(int x){
    int suma=0;
    if (x==1){
        suma=1;
    }
    else{
        suma=x+Suma(x-1);
    }
    return suma;
}

//Funcion recuersiva ejercicio libre (7.4 Joyanes)
int cant_vocales;
int vocales(string cadena, int i){
    //posicion de cada caracter = i;
    char c;
    c=cadena[i];
    if(cadena.length()==0){
        return 0;
    } 
    else{
        if(c=='a'||c=='A' ||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u' ){
            cant_vocales++;
            vocales(cadena,i+1);
        }
        else{
            if(c!= '\0'){
                vocales(cadena,i+1);
            }
        }
    }
    return cant_vocales;
}


//Funcion Menu

void Menu(){
    
    cout<<"\tB I E N V E N I D O  U S U A R I O"<<endl;
    cout<<"\t-----------------------------------\n"<<endl;
    system("pause");
    system("cls");
    int op=0;
    do{

       
        cout<<"\t\t M E N U"<<endl;
        cout<<"\t-----------------------------------\n"<<endl;
        cout<<"1. Factorial de un numero"<<endl;
        cout<<"2. Sumatoria"<<endl;
        cout<<"3. Contar vocales en una frase (Joyanes 7.4)"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingresa una opcion: ";cin>>op;
        system("cls");

        switch(op){
            case 1:{
                int num=0;
                double fact=0;
                cout<<"Ingresa un numero para sacar el factorial: ";cin>>num;
                cout<<"\nFactorial: "<<Fact(num);
                cout<<"\n";
                system("pause");
                system("cls");
                break;
                
            }
            case 2:{
                int numE=0;
                int sumatoria=0;
                do{
                cout<<"Ingresa el numero de elementos a sumar: ";
                cin>>numE;
                }while(numE<0);
                cout<<"\nSumatoria de los primeros "<<numE<<" es: "<<Suma(numE);
                cout<<"\n";
                system("pause");
                system("cls");
                break;
                
            }
            case 3:{
                string cadena;
                int resultado;
                cout<<"Ingresa una frase: ";
                getline(cin>>ws,cadena);
                resultado= vocales(cadena,0);
                cout<<"\nHay "<<resultado<<" vocales en la frase:"<<endl;
                cout<<cadena<<endl;
                system("pause");
                system("cls");
                
               break;    
            }
            default: "Opcion incorrecta";
        }
    }while(op!=4);
    cout<<" D E C I D I S T E  S A L I R   H A S T A   L U E G O   C A M P E O N ";

}

int main(){
    Menu();
    return 0;
}

