#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * sin(x) - 1;
}

void bisection(double a, double b, double tol) {
    int iter = 0;
    double fa = f(a);
    double fb = f(b);
    /*if (fa * fb >= 0) {
        cout << "No se puede aplicar el metodo de biseccion en este intervalo." << endl;
        return;
    }*/
    while (true) {
        double c = (a + b) / 2;
        double fc = f(c);
        if (abs(fc) < tol) {
            cout << "Raiz encontrada en x = " << setprecision(9) << c << " despues de " << iter << " iteraciones." << endl;
            return;
        }
        iter++;
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }
}

int main() {
    double a, b, tol;
    char opcion;

    do {
        cout<<"--------------HOLA Gatita-----------------\n";
        cout << "\tIntroduzca el limite inferior del intervalo: ";
        cin >> a;
        cout << "\tIntroduzca el limite superior del intervalo: ";
        cin >> b;
        cout << "\tIntroduzca la tolerancia al error: ";
        cin >> tol;
        bisection(a, b, tol);
        cout << "Desea continuar? (S/N): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            cout << "Dale, vamos a seguir";
        }
        else {
            cout << "Bye, it was Britney, bitch";
        }
        system("pause");
        system("cls");
    } while (opcion == 'S' || opcion == 's');

    return 0;
}
