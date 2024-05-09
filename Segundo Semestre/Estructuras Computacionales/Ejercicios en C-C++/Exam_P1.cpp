/*
Pedir y calcular de cada trabajador la siguiente información: 
1.	Nombre
2.	Piezas elaboradas de cada día de la semana inglesa (lunes a viernes). Se debe de almacenar en un arreglo.
3.	Cantidad menor de piezas producidas (se debe calcular)
4.	Cantidad mayor de piezas producidas (se debe calcular)

Guarda en una lista la información de N trabajadores.   <<<Valor 1 pto.>>>

Realizar lo siguiente:
1.	Mostrar él o los trabajadores con mayor numero de piezas semanales. <<<Valor 2 pts.>>>
2.	Lista de trabajadores indicando que día o días de la semana obtuvo la producción menor.                <<<Valor 2 pts.>>>
3.	Hacer otra versión del programa que permita capturar días de trabajo especifico de cada día de la semana inglesa por cada trabajador. <<<Valor 2 pts.>>>
4.	Eliminar trabajadores dados de alta, indicados por el usuario. <<<Valor 2 pts.>>>

Nota 1: manejar una función que reciba al menos como parámetro un arreglo. <<<Valor 1 pto.>>>
Nota 2: Realiza de cada ejercicio una autoevaluación.
Nota 2: Indica el tiempo aproximado de realización del examen. 

*/

#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

struct Informacion{

    string Name[30];
    int Piezas;
    int may,menor;
    int dias[5];
    int totalpiezas;
    

};


//Funciones a utilizar
void gotoxy(int x, int y);
void Menu(int *n);
void Captura_De_Datos();




int main(){

    int nTrab;
    gotoxy(30,12);
    cout<<"BIENVENIDO AL REGISTRO DE DATOS"<<endl;
    cout<<"Ingresa el numero de trabajadores a registrar: ";
    cin<<nTrab;
       


}

//GOTOXY
void gotoxy(int x,int y ){

    HANDLE hCon;
    hCon= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}