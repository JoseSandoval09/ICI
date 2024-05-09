#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void bubble(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i] < A[j])
            {
                A[i] += A[j];
                A[j] = A[i] - A[j];
                A[i] = A[i] - A[j];
            }
        }//fin for j
    }//fin for i
}
int main()
{
    int N; int A[100];
    cout << "Ingrese el numero de elementos: "; cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "Elemento " << i << ": "; cin >> A[i];
    }//fin for i


    bubble(A, N);

    cout << "Arreglo ordenado:\n";
    
    for (int i = 0; i < N; i++)
    {
    cout << "\t" << A[i];
    }//fin for i
    
    cout << "\n .:PROGRAMA REALIZADO POR :. ";
    cout << "\nAngel David Ortiz Quiroz ID:261481";
    cout << "\nErick Ivan Ramirez Reyes ID:260806";
    cout << "\nXimena Rivera Delgadillo ID:261261";
    cout << "\nJose Luis Sandoval Perez ID:261731";
    cout << "\nDiego Emanuel Saucedo Ortega ID:261230";
    cout << "\nCarlos Daniel Torres Macias ID : 244543";
    cout << "\n";
    return 0;
}