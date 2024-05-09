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
      // Dividir la fila por el coeficiente de la diagonal
      double coeficiente_diagonal = matriz[i][i];
      for (int j = i; j < n+1; j++) {
         matriz[i][j] /= coeficiente_diagonal;
      }
      // Restar la fila a las filas siguientes para eliminar los coeficientes
      for (int k = 0; k < n; k++) {
         if (k != i) {
            double coeficiente = matriz[k][i];
            
         }
      }
   }

   // Mostrar los valores de las variables
   cout << "Solucion del sistema de ecuaciones:" << endl;
   for (int i = 0; i < n; i++) {
      cout << "x" << i+1 << " = " << matriz[i][n] << endl;
   }

   return 0;
}





