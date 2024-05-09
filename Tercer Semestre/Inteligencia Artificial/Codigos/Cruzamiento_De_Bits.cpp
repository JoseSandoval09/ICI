#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;

const int Size_Pob =10;
const int Long_Ind =11;
int poblacion[10][11];
void creacion_poblacion(int a,int b);
void cruzamiento();



int main(){

    srand(time(NULL));

    int i,j,randnum,ceros=0;//interadores i y j , randnum numero aleatorio, ceros conteo de ceros en la fila
    
    //creacion de poblacion

    for(int i=0;i<Size_Pob;i++){
        for(int j=0;j<Long_Ind;j++){
            randnum= rand()%100;
            if(randnum%2==0){
                poblacion[i][j]=0;
                
            }else{
                poblacion[i][j]=1;
            }
            
        }

        
    }

    //conteo de ceros
    for(i=0;i<Size_Pob;i++){
        ceros=0; 
        for(j=0;j<Long_Ind;j++){
            if(poblacion[i][j-1]==0){
                ceros++;
            }
        }  
        poblacion[i][10]=ceros;
        
    }

    //mostrar matriz

    for( i=0;i<Size_Pob;i++){
        for(j=0;j<Long_Ind;j++){
           cout<<poblacion[i][j]<<" ";
        }
        cout<<"\n";
    }

    int matrixaux[10][10];

    //cruzamiento
    int puntocruza;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matrixaux[i][j]=0;
        }
    }


    



    
    

    

        





    
    



}