/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Se va a crear un programa para generar un arbol de expansion
minima dado un grafo.

*/

#include <iostream>
#include <stdio.h>
#define SINGLE 0
using namespace std;

int main()
{
    cout << "\t I N T R O D U C C I O N\n";
    cout << "Dados n hombres y n mujeres, donde cada persona ha clasificado a todos los miembros del sexo";
    cout << "opuesto en orden de preferencia, se trata de casar a los hombres y mujeres juntos de modo que";
    cout << "no haya dos personas del sexo opuesto que prefieran tenerse el uno al otro más que a sus parejas";
    cout << "actuales. " << endl;
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    int matrizW[4][4] = { {0, 0, 0, 0},
                          {1, 1, 2, 3},
                          {2, 2, 1, 3},
                          {3, 1, 2, 3}}; 
    int matrixM[4][4] = { {0, 0, 0, 0},
                          {1, 2, 1, 3},
                          {2, 1, 2, 3},
                          {3, 1, 2, 3}};
    int actualM[4] = { 0, 0, 0, 0};  
    int actualW[4] = { 0, 0, 0, 0};
    int nextproM[4] = { 1, 1, 1, 1 };
    bool menDis = true;
    int m = 1;
    while (menDis)
    {
        menDis = false;
        int w = matrixM[m][nextproM[m]++];
        if (actualW[w] == SINGLE)
        {
            actualW[w] = m;
            actualM[m] = w;
        }
        else
        {
            bool betterpro = false; 
            for (int i = 1; i <= 3; i++)
            {
                if (matrizW[w][i] == actualW[w])
                {
                    betterpro = false;
                    break;
                }
                if (matrizW[w][i] == m)
                {
                    betterpro = true;
                    break;
                }
            }
            if (betterpro)
            {
                actualM[actualW[w]] = SINGLE;
                actualW[w] = m;
                actualM[m] = w;
            }
        }
        for (int j = 1; j <= 3; j++)
        {
            if (actualM[j] == SINGLE)
            {
                m = j;
                menDis = true;
                break;
            }
        }
    }
    cout << "\t"<< "  A L G O R I T M O    G A L E  -  S H A P L E Y " << endl;
    cout << "\n";
    cout << "   TABLA de preferencias h o m b r e s" << endl;
    for (int g = 1; g <= 3; g++)
    {
        for (int d = 0; d <= 3; d++)
        {
            if (d == 0) {
                if (g == 1) cout << " Jorge  ";
                if (g == 2) cout << " Luis   ";
                if (g == 3) cout << " Mario  ";
            }
            if (d > 0) { cout << matrixM[g][d] << "\t"; }
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "   TABLA de preferencias m u j e r e s" << endl;
    for (int h = 1; h <= 3; h++)
    {
        for (int u = 0; u <= 3; u++)
        {
            if (u == 0) {
                if (h == 1) cout << " Ana    ";
                if (h == 2) cout << " Bea    ";
                if (h == 3) cout << " Clara  ";
            }
            if (u > 0) { cout << matrizW[h][u] << "\t"; }
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\tM A T R I M O N I O S   E S T A B L E S\n";
    for (int k = 1; k <= 3; k++)
    {
        if (k == 1) { cout << "Jorge " << "y "; }if (k == 2) { cout << "Luis " << "y "; }if (k == 3) { cout << "Mario " << "y "; }
        if(actualM[k]==1){ cout<<"Ana" << endl; }if (actualM[k] == 2) { cout << "Bea" << endl; }if (actualM[k] == 3) { cout << "Clara" << endl; }
    }
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    cout << "S A L I R  S A L I R  S A L I R" << endl;
    cout << "PROGRAMA REALIZADO POR:\n";
    cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    return 0;
}
