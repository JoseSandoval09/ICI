#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir el tablero
void imprimirTablero(vector<int> tablero) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (tablero[i] == j) {
        cout << "Q ";
      } else {
        cout << "- ";
      }
    }
    cout << endl;
   
  }
}

// Función para verificar si una posición es segura para colocar una reina
bool esPosicionSegura(vector<int> tablero, int fila, int columna) {
  // Revisar las filas
  for (int i = 0; i < fila; i++) {
    if (tablero[i] == columna) {
      return false;
    }
  }

  // Revisar las diagonales
  for (int i = 0; i < fila; i++) {
    int col_izquierda = columna - (fila - i);
    int col_derecha = columna + (fila - i);

    if (col_izquierda >= 0 && col_izquierda < 8 && tablero[i] == col_izquierda) {
      return false;
    }

    if (col_derecha >= 0 && col_derecha < 8 && tablero[i] == col_derecha) {
      return false;
    }
  }

  return true;
}

// Función recursiva para encontrar todas las soluciones
void encontrarSoluciones(vector<int> tablero, int fila) {
  // Si se ha llegado a la última fila, se ha encontrado una solución
  if (fila == 8) {
    imprimirTablero(tablero);
    cout<<"_____________________________________"<<endl;
    return;
  }

  // Probar todas las columnas en la fila actual
  for (int columna = 0; columna < 8; columna++) {
    // Si la posición es segura, colocar una reina y continuar con la siguiente fila
    if (esPosicionSegura(tablero, fila, columna)) {
      tablero[fila] = columna;
      encontrarSoluciones(tablero, fila + 1);
    }
  }
}

int main() {
  // Inicializar el tablero
  vector<int> tablero(8, -1);

    cout<<"TABLEROS DE SOLUCION PARA EL PROBLEMA DE LAS 8 REINAS"<<endl;

  // Encontrar todas las soluciones
  encontrarSoluciones(tablero, 0);
    system("pause");
  return 0;
}
