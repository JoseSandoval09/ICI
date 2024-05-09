/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4�A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfile�o

Este programa calcula la raiz de una funcion utilizando el metodo grafico
Funcion f(x) = x^3 + 2x^2 + 3x - 5

*/
#include <iostream>
#include <cmath>
#include<iomanip>
#define raiz_real 0.8945582428

using namespace std;

void imprimir_menu() {
 cout<<"\t\t M E N U\n1-Calcular el valor de la raiz de la funcion por Metodo Grafico\n2-Salir\n";
 cout<<"-------------------------------------------------------------------------------\n";
 cout<<"Seleccione una opcion: ";
}

int main() {

  int opcion;
  float raiz;
  int a, b;

  cout<<"\t\tI N T R O D U C C I O N\n Este programa calcula la raiz de la funcion:\n\t\tf(x) = x^3 + 2x^2 + 3x - 5\n";
  cout<<"\t  por el Metodo Grafico\n";
	cout<<"-------------------------------------------------------------------------------\n";
	system("pause");
	system("cls");
	
  do {

    imprimir_menu();
    cin >> opcion;
    cout<<"\n-------------------------------------------------------------------------------\n";
	system("pause");
	system("cls");
    if (opcion == 1) {
 	  cout<<"\t\tM e t o d o   g r a f i c o\n";
      cout << "Ingrese el valor de [x, 0] (Intervalo Inferior): ";
      cin >> a;
      cout << "Ingrese el valor del [0, x] (Intervalo Superior): ";
      cin >> b;

      float valores_x[(b - a + 1) * 10];
      float valores_y[(b - a + 1) * 10];
      int indice = 0;
      
      cout<<"-------------------------------------------------------------------------------\n";
	  cout<<"\t\tR E S U L T A D O S\n";
      for (double i = a; i <= b; i = i + 0.1) {
        valores_x[indice] = pow(i, 3) + 2 * pow(i, 2) + 3 * i - 5 ;
        valores_y[indice] = i;
        cout << "f(" << valores_y[indice] << ") = " << valores_x[indice] << endl;
        indice++;
      }
      cout<<"-------------------------------------------------------------------------------\n";
      for (int i = 0; i < (b - a + 1) * 10; i++) {
        if (valores_x[i] * valores_x[i + 1] < 0) {
          raiz = (valores_y[i] + valores_y[i + 1]) / 2;
          cout<<fixed;
          cout<<setprecision(9);
          cout << "La raiz de la funcion es: " << raiz << endl;
        }
      }
      cout<<"-------------------------------------------------------------------------------\n";
      cout << "La raiz real de la funcion es: " << raiz_real << endl;
      cout << "El error cometido es: " << abs(raiz - raiz_real) << endl;

    } else if (opcion == 2) {
      cout<<"-------------------------------------------------------------------------------\n";
	  cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
    } else {
      cout << "ERROR: Opcion no valida" << endl;
    }
   cout<<"\n-------------------------------------------------------------------------------\n";
   system("pause");
   system("cls");
  } while (opcion != 2);

  return 0;
}
