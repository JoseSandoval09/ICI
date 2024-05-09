/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Examen Parcial 2 
Metodo Gauss-Jordan
Luis Fernando Guiterrez Marfileño

Este programa resuelve el siguiente sistema de ecuaciones 3x3 por el metodo de Gauss-Jordan


2x1+x2+3x3=1
2x1+6x2+8x3=3
6x1+8x2+18x3=5
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {


    cout<<"Este programa resuelve  sistema de ecuaciones 3x3 por el metodo de Gauss-Jordan"<<endl;


    double matrix[3][4]; 

    cout<<"A continuacion ingresa los coeficientes de cada ecuacion: "<<endl;
   
    for(int i = 0; i < 3; i++) {
        cout << "Ecuacion " << i+1 << ":" << endl;
        for(int j = 0; j < 4; j++) {
           
           if(j!=3){
            cout<<"coeficiente "<<j+1<<" :";
            }
         
            if(j==3){
            cout<<"Termino independiente: ";
         }
           

            cin >> matrix[i][j];
        }
    }

   
    cout << "Matriz de los coeficentes ingresada:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    
    for(int i = 0; i < 3; i++) {
        
        double PIV = matrix[i][i];
        for(int j = i; j < 4; j++) {
            matrix[i][j] /= PIV;
        }

        
        for(int k = i+1; k < 3; k++) {
            double fK = matrix[k][i];
            for(int j = i; j < 4; j++) {
                matrix[k][j] -= fK * matrix[i][j];
            }
        }
    }

   
    cout << "---------MATRIZ RESULTANTE------:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Resolver el sistema de ecuaciones sustituyendo hacia atrás
    double incognitas[3];
    incognitas[2] = matrix[2][3];
    incognitas[1] = matrix[1][3] - matrix[1][2] * incognitas[2];
    incognitas[0] = matrix[0][3] - matrix[0][1] * incognitas[1] - matrix[0][2] * incognitas[2];

    // Mostrar las soluciones del sistema de ecuaciones
    cout << "Soluciones:" << endl;
    cout << "x = " << incognitas[0] << endl;
    cout << "y = " << incognitas[1] << endl;
    cout << "z = " << incognitas[2] << endl;

    return 0;
}




