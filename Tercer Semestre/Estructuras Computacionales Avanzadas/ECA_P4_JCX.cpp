/*
Universidad Autonoma De Aguascalientes
Ingenier�a en Computacion Inteligencia
Estructuras Computacionales Avanzadas

El�as Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfile�o
Se va a crear un programa que calcule las componentes conexas de un grafo mediante el
algoritmo de Warshall del siguiente grafo:
*/
#include <iostream>
using namespace std;

void printma(bool M[6][6]) {
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            cout << "\t" << M[i][j]; 
        }
        cout << endl;
    }
}
void warshallma(bool ma[6][6]) {
    cout << "\tM A T R I C E S    w  a  r  s  h  a  ll\n";
    for (int k = 0; k < 6; k++) 
    {
        for (int i = 0; i < 6; i++) 
        {
            for (int j = 0; j < 6; j++) 
            {
                ma[i][j] = ma[i][j] || (ma[i][k] && ma[k][j]);
            }
        }
        cout << "\nmatriz " << k + 1 << endl;
        printma(ma);
    }
}

int main() {
    int op;
    bool matriz[6][6] = {
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {1,0,0,0,0,1},
        {0,1,0,0,1,0},
        {0,0,1,0,0,0},
        {0,1,0,0,0,0} };
    cout << "\tI N T R O D U C C I O N  del  p r o g r a m a" << endl;
    cout << "\tEl siguiente programa nos permitira calcular las componentes conexas " << endl;
    cout << "\tde un grafo mediante el algoritmo de Warshall de grafo INICIAL" << endl;
    cout << "\n------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    cout << "           G  R  A  F  O     I  N  I  C  I  A  L\n";
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "   m  a  t  r  i  z   de   a  d  y  a  c  e  n  c  i  a"<<endl;
    printma(matriz);
    cout << "\n------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    do
    {
        
        cout << "\tM  E  N  U    w  a  r  s  h  a  ll\n";
        cout << "---------------------------------------------------" << endl;
        cout << "\t1.Warshall"<<endl;
        cout << "\t2.SALIR" << endl;
        cout << "\tSeleccione una opcion: ";cin >> op;
        cout << "\n---------------------------------------------------" << endl;
        system("pause");
        system("cls");

        if (op == 1) 
        {
            warshallma(matriz); 
            cout << "\n------------------------------------------------------------------------------" << endl;
            system("pause");
            system("cls");
        }
    } while (op != 2);
        
    cout << "\nPROGRAMA REALIZADO POR:\n";
    cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
    cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    return 0;
}
