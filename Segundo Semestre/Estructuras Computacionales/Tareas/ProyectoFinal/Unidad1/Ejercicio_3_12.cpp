/*Escribir un programa en el que se genere aleatoriamente un vector de 20 nÃºmeros enteros.
El vector ha de quedar de tal forma que la suma de los 10 primeros elementos sea mayor
que la suma de los 10 Ãºltimos elementos.Mostrar el vector original y el vector con la distribucion indicada.*/

/* INTEGRANTES DE EQUIPO
Carlos Daniel Torres Macias     ID: 244543
Ximena Rivera Delgadillo        ID: 261261
Erick Ivan Ramirez Reyes        ID: 260806
Diego Emanuel Saucedo Ortega    ID: 261230
Jose Luis Sandoval Perez        ID: 261731
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<Windows.h>

using namespace std;

void Numeros_Aleatorios(int A[]) {


    for (int i = 0; i <= 19; i++) {

        A[i] = rand() % 100;
    }//fin for i
}//fin funcion num random

void Ordenar_Num(int A[]) {

    //ordena numeros
    for (int i = 1; i < 20; i++) {
        int j = i - 1, p = A[i];
        while (p < A[j] && j >= 0) {
            A[j + 1] = A[j];
            j--;
        }//fin while

        A[j + 1] = p;

    }//fin for i

}//Fin funcion Ordenar los numeros

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}


int main() {

    srand(time(NULL));
    system("color D");
    

    cout << "Tema: Emo";
    

    int Alea[20];

    //Funcion que genera numeros aleatorios.
    Numeros_Aleatorios(Alea);
    //Mostrar vector original.
    gotoxy(35, 5); cout << "Vector Original:";
    gotoxy(5, 7);  cout << "*********************************************************************************\n";
    for (int i = 0; i < 20; i++) {
        if (i % 10 == 0) { cout << endl; }
        cout << "\t" << Alea[i];

    }
    Ordenar_Num(Alea);


    //Ordenacion del vector
    gotoxy(35, 12); cout << "Vector Ordenado:";
    gotoxy(5, 14); cout << "*********************************************************************************\n";
    int sA = 0, sB = 0;
    for (int i = 19; i >= 0; i--) {
        cout << "\t" << Alea[i];
        if (i == 10) { cout << " = " << sA; }
        if (i % 10 == 0 && i != 0) { cout << endl; }
        if (i > 10) {
            sA += Alea[i];
        }
        else { sB += Alea[i]; }
    }
    cout << " = " << sB << endl;
    system("pause>fin");



    return 0;
}