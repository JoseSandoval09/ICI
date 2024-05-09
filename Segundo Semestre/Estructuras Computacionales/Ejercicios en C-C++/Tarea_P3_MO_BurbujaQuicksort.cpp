//METODO ORDENACION QUICKSORT Y BURBUJA 
//JOSE LUIS SANDOVAL PEREZ 2°A ICI

#include <iostream>
#include<stdlib.h>
#include<stdio.h>


using namespace std;


//Ordenacion por metodo Quicksort
void quicksort(double a[], int primero, int ultimo) {
    int i, j, central;
    double pivote;
    central = (primero + ultimo) / 2;
    pivote = a[central];
    i = primero;
    j = ultimo;
    
    do {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (primero < j) {
        quicksort(a, primero, j);
    }
    if (i < ultimo) {
        quicksort(a, i, ultimo);
    }
}
//Ordenacion por metodo Burbuja
void ordBurbuja(int a[], int n) {
    bool interruptor = true;
    int pasada, j;
    for (pasada = 0; pasada < n - 1 && interruptor; pasada++) {
        interruptor = false;
        for (j = 0; j < n - pasada - 1; j++) {
            if (a[j] > a[j + 1])
            {
                interruptor = true;
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int a1[7] = { 21,5,10,2,19,35,9 };
    double a2[10] = {24,21,5,84,11,3,5,44,90,45 };
    int n_1 = 7, n_2 = 10;
    ordBurbuja(a1, n_1);
    cout << "Metodo de la Burbuja" << endl;
    for (int i = 0; i < n_1; i++) {
        cout << a1[i] << ", ";
    }
    cout << endl;
    cout << "Metodo QuickSort" << endl;
    quicksort(a2, 0, 9);
    for (int i = 0; i < n_2; i++) {
        cout << a2[i] << ", ";
    }
    cout << endl;
    system("pause");
    return 0;
}