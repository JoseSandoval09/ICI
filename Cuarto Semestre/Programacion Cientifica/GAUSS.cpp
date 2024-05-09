/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Departamento de ciencias de la computacion
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo 
Metodo Gauss
Luis Fernando Guiterrez Marfileño

Este programa resuelve el siguiente sistema de ecuaciones 3x3 por el metodo de Gauss-Jordan


-x1+x2-x3=-1
4x1-2x2+2x3=0
-3x1-2x2+0x3=-4
*/

#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Ingrese el tamaño del sistema de ecuaciones: ";
   cin >> n;

   double matriz[n][n+1];

   // Pedir valores de la matriz aumentada
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n+1; j++) {
         cout << "\nIngrese el valor de los coeficientes de la ecuacion " << i+1<<endl;
         if(j!=n){
            cout<<"coeficiente "<<j+1<<" :";
         }
         
         if(j==n){
            cout<<"Termino independiente: ";
         }
         cin >> matriz[i][j];
      }
   }

   // Transformar la matriz en una matriz escalonada reducida
   for (int i = 0; i < n; i++) {
      double coeficiente_diagonal = matriz[i][i];
      for (int j = i; j < n+1; j++) {
         matriz[i][j] /= coeficiente_diagonal;
      }
   }

   // Mostrar los valores de las variables
   cout << "Solucion del sistema de ecuaciones:" << endl;
   for (int i = 0; i < n; i++) {
      cout << "x" << i+1 << " = " << matriz[i][n] << endl;
   }

   return 0;
}