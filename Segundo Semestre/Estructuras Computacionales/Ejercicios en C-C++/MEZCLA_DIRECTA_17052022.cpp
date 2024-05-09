#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define NE 41//real de 41
void mergeSort(int [],int, int);

int main(){

    int Numbers_Selection[]={
    -84,-14,-50,-90,-75,25,10,12,27,-10,
    -47,4,78,57,90,71,40,-96,-22,-12,-64,
    -38,-88,72,-40,-3,51,-54,-18,-92,77,
    32,-72,15,-71,-20,26,33,-13,-17,-86
    };

    cout<<"\nElementos ingresados: \n";
    for(int i=0;i<NE;i++){
        cout<<"\t"<<Numbers_Selection[i];
    }

    mergeSort(Numbers_Selection,0,NE-1);

    cout<<"\nElementos ordenados: \n";
    for(int i=0;i<NE;i++){
        cout<<"\t"<<Numbers_Selection[i];
    }
}

void Merge(int A[],int inicio,int fin,int mitad){
    int eIzq = mitad - inicio +1;
    int eDer = fin - mitad;

    int I[eIzq],D[eDer];

    for(int i=0;i<eIzq;i++){
        I[i] = A[inicio+i];
    }
    for(int j=0;j<eDer;j++){
        D[j] = A[mitad+j+1];
    }

    int i=0,j=0,k=inicio;
    while(i<eIzq && j<eDer){
        if(I[i]<=D[j]){
            A[k] = I[i];
            i++; k++;
        }
        else{
            A[k] = D[j];
            j++; k++;
        }
    }

    while(j < eDer){
        A[k] = D[j];
        j++; k++;
    }
    while(i < eIzq){
        A[k] = I[i];
        i++; k++;
    }
}

void mergeSort(int A[],int inicio,int fin){
    if(inicio<fin){
        int mitad = inicio + ((fin - inicio)/2);
        mergeSort(A,inicio,mitad);
        mergeSort(A,mitad+1,fin);
        Merge(A,inicio,fin,mitad);
    }
}
