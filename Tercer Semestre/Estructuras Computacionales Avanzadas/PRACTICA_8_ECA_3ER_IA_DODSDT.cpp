#include <iostream>
using namespace std;

/*
Benemerita Universidad Autonoma de Aguascalientes
Ing. En Computacion Inteligente
Estructuras Computacionales Avanzadas
Integrantes:
    Angel David Ortiz Quiroz        ID: 261481
    Diego Emanuel Saucedo Ortega    ID: 261230
    Carlos Daniel Torres Macias     ID: 244543
Profesor: Mr. en C. Luis Fernando Gutierrez Marfileño

---->PROGRAMA
Determinar el menor costo para un arreglo de costo-tarea
*/

int matriz[3][3] = {
    {15,10,9},
    {9,15,10},
    {10,10,8} };

/*int matriz[3][3] = {
    {40,60,15},
    {25,30,45},
    {55,30,25} };*/

void copiarMatriz(int[][3]);
void mostrarMatriz(int[][3]);
int obtenerMinimo(int [][3],int,int);

int main(){
    int A[3][3];
    bool picked[3] = {false,false,false};

    copiarMatriz(A); 
    mostrarMatriz(A);

    for(int i=0;i<3;i++){

        int menorc = obtenerMinimo(matriz,i,0);
        for(int j=0;j<3;j++){
            A[i][j] -= menorc;
        }//fin for j
        
    }//fin for i

    mostrarMatriz(A);

    for(int i=0;i<3;i++){

        int menorf = obtenerMinimo(A,i,1);
        for(int j=0;j<3;j++){
            A[j][i] -= menorf;
        }//fin for j
        
    }//fin for i

    mostrarMatriz(A);

    int costo_final = 0;
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(A[i][j]==0 && !picked[j]){
                cout<<"Trabajador "<<i+1<<"-> Tarea "<<j+1<<endl;
                costo_final += matriz[i][j];
                picked[j] = true;
                break;
            }//fin if
        }//fin for j
    }//fin for i
    cout<<"Costo Total: "<<costo_final<<endl;


    return 0;
}

void copiarMatriz(int A[][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            A[i][j] = matriz[i][j];
        }//fin for j
    }//fin for i

}

void mostrarMatriz(int A[][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<A[i][j];
        }//fin for j
            cout<<endl;
    }//fin for i
    cout<<endl;
}
int obtenerMinimo(int A[][3],int i,int mode){

    int menor = 999;
    for(int j=0;j<3;j++){ 
            if(mode == 0){ menor = min(menor,A[i][j]); } 
            else{ menor = min(menor,A[j][i]);}
    }//fin for 

return menor;
}