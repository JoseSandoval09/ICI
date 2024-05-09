#include <iostream>

using namespace std;

// Función para calcular el polinomio de Lagrange
double lagrange(double x[], double y[], int n, double xi) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main() {
    int n;

    cout << "Ingrese el número de coordenadas: ";
    cin >> n;

    double x[n], y[n];

    // Leer las coordenadas
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la coordenada x[" << i << "]: ";
        cin >> x[i];
        cout << "Ingrese la coordenada y[" << i << "]: ";
        cin >> y[i];
    }

    // Mostrar polinomios generados
    cout << "\nEl polinomio interpolante es:\n";
    for (int i = 0; i < n; i++) {
        cout<<"L"<<i<<"=";
        cout << "(" << y[i] << ")";

        for (int j = 0; j < n; j++) {
            if (j != i) {
                cout << "(x - " << x[j] << ") / (" << x[i] << " - " << x[j] << ")";
            }
        }

        if (i != n - 1) {
            cout << " + "<<endl;
        }
    }

    // Interpolar un valor
    double xi;

    cout << "\n\nIngrese el valor de x para interpolar: ";
    cin >> xi;

    double yi = lagrange(x, y, n, xi);

    cout << "El valor interpolado para x = " << xi << " es  = " << yi <<endl;

    return 0;
}