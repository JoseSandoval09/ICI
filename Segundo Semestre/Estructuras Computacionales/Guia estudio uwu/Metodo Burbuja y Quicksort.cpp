// UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
// ESTRUCTURAS COMPUTACIONALES II
// PROYECTO FINAL 3ER PARCIAL
// INTEGRANTES: 

// Carlos Leonardo Cruz Ortiz ID: 261696
// Leslie Miroslava Ben�tez Mar�n ID: 183817
// C�sar Eduardo Elias del Hoyo ID: 262045

// ACTIVIDA 4
// M�todo de la Burbuja y Quicksort

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <thread>
using namespace std;

void BubbleSort(int a []){
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j <= 10; j++){
            if(a[j] < a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}

void QuickSort(int a[], int first, int last){

    int i, j;
    int pivot;

    pivot = a[(first + last) / 2];
    i = first;
    j = last;

    do{
        while(a[i] < pivot){
            i++;
        }

        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }   
    }while(i <= j);

    if(first < j){
        QuickSort(a, first, j);
    }
    if(last > i){
        QuickSort(a, i, last);
    }
}

int main(){
    int Array[10];
    int copy[10];
    int temp;
    srand(time(NULL)); 

    // Generar numeros aleatorios
    for(int i = 0; i < 10; i++){
        Array[i] = rand() % 1000;
    }
    for(int i = 0; i < 10; i++){
        copy[i] = Array[i];
    }

    cout<<"Array original"<<endl;

    for (int i = 0; i < 10; i++) //Imprimir Array
    {
        
        if(i == 9)
        {
            cout<<copy[i]<<", ";
        }
        else
        {
            cout<<copy[i]<<", ";
        }
    }
    

    BubbleSort(Array);

    cout << "\n\nBubbleSort" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(i == 9)
        {
            cout<<Array[i];
        }
        else
        {
            cout<<Array[i]<<", ";
        }
    }

    cout<<"\n\nQuickSort"<<endl;

    QuickSort(copy, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        if(i == 9)
        {
            cout<<copy[i];
        }
        else
        {
            cout<<copy[i]<<", ";
        }
    }
    
    return 0;
}
