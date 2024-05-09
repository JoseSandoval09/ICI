#include <iostream>

using namespace std;

// Función para calcular los coeficientes de las diferencias divididas
void calcularDiferenciasDivididas(double x[], double y[], double diferenciasDivididas[][10], int n) {
    // Inicializar la primera columna con los valores de y
    for (int i = 0; i < n; i++) {
        diferenciasDivididas[i][0] = y[i];
    }

    // Calcular las diferencias divididas
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diferenciasDivididas[i][j] = (diferenciasDivididas[i + 1][j - 1] - diferenciasDivididas[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Función para calcular el polinomio de Newton
void calcularPolinomioNewton(double x[], double diferenciasDivididas[][10], double coeficientes[], int n) {
    for (int i = 0; i < n; i++) {
        coeficientes[i] = diferenciasDivididas[0][i];
    }
}

// Función para mostrar el polinomio resultante
void mostrarPolinomioNewton(double x[], double coeficientes[], int n) {
    cout << "P(x) = ";
    for (int i = 0; i < n; i++) {
        cout << coeficientes[i];

        for (int j = 0; j < i; j++) {
            cout << "*(x - " << x[j] << ")";
        }

        if (i != n - 1) {
            cout << " + ";
        }
    }

    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el número de coordenadas: ";
    cin >> n;

    double x[10];
    double y[10];

    cout << "Ingrese las coordenadas (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Coordenada " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double diferenciasDivididas[10][10];
    calcularDiferenciasDivididas(x, y, diferenciasDivididas, n);

    double coeficientes[10];
    calcularPolinomioNewton(x, diferenciasDivididas, coeficientes, n);

    mostrarPolinomioNewton(x, coeficientes, n);

    return 0;
}