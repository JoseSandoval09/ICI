/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Crear un programa que ejecute el desarrollo de todas las
permutaciones de un conjunto de N elementos usando el Algoritmo de Heap.
*/

#include<iostream>

using namespace std;

void PermutacionesChar(int CharEle, char Perm_ch[], int a);
void printPerm(int x, char perm[]);
void menu();
int Factorial(int x);

int main() {

    int op = 0;
    char Char_Array[10];

    cout << "B I E N V E N I D O       U S U A R I O \n" << endl;
    cout << "El siguiente programa desarrollara las permutaciones de un conjunto de N elementos." << endl;
    cout << "Los elementos del conjunto pueden ser caracateres o numeros" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");


    while (op != 3) {
        int EleChar;
        menu();
        cin >> op;
        cout << "\n-------------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
        if (op == 1) {
            cout << " P E R M U T A C I O N E S  e n t e r o s " << endl;
            cout << "\nIngrese el numero de elementos que desea utilizar? (maximo 10 minimo 1): "; cin >> EleChar;
            if (EleChar > 10 || EleChar < 1) {
                system("pause");
                system("cls");
                cout << " E R R O R\t E R R O R \t E R R O R\t E R R O R\t E R R O R\t E R R O R" << endl;
                cout << "el numero de elementos ingresado es incorrecto" << endl;
                cout << "EL LIMITE DE PERMUTACIONES es maximo 10 minimo 1\n";
                cout << "---------------intentelo de nuevo---------------" << endl;
                system("pause"); system("cls");
            }
            else {
                for (int i = 0; i < EleChar; i++) { cout << "Elemento " << i + 1 << ":"; cin >> Char_Array[i]; }
                cout << "\nGracias, introduciste " << EleChar << " elementos\n" << endl;
                cout << "AHORA el programa generara " << Factorial(EleChar) << " permutaciones\n" << endl;
                PermutacionesChar(EleChar, Char_Array, EleChar);
                cout << "\n"; system("pause"); system("cls");
            }
        }
        if (op == 2) {
            cout << " P E R M U T A C I O N E S  c a r a c t e r e s " << endl;
            cout << "\nIngrese el numero de elementos que desea utilizar? (maximo 10 minimo 1): "; cin >> EleChar;
            if (EleChar > 10 || EleChar < 1) {
                system("pause");
                system("cls");
                cout << " E R R O R\t E R R O R \t E R R O R\t E R R O R\t E R R O R\t E R R O R" << endl;
                cout << "el numero de elementos ingresado es incorrecto" << endl;
                cout << "EL LIMITE DE PERMUTACIONES es maximo 10 minimo 1\n";
                cout << "---------------intentelo de nuevo---------------" << endl;
                system("pause"); system("cls");
            }
            else {
                for (int i = 0; i < EleChar; i++) { cout << "Elemento " << i + 1 << ":"; cin >> Char_Array[i]; }
                cout << "\nGracias, introduciste " << EleChar << " elementos\n" << endl;
                cout << "AHORA el programa generara " << Factorial(EleChar) << " permutaciones\n" << endl;
                PermutacionesChar(EleChar, Char_Array, EleChar);
                cout << "\n"; system("pause"); system("cls");
            }
        }
        if (op == 3) {
            cout << " S A L I R\t S A L I R\t S A L I R\t S A L I R\t S A L I R\t S A L I R\t\n";
            cout << "PROGRAMA REALIZADO POR:\n";
            cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
            cout << "\n-------------------------------------------------------------------------------------------" << endl;
            system("pause");
            return 0;
        }
    }
    return 0;
}
void menu() {
    cout << " P E R M U T A C I O N E S   D E     C A R A C T E R E S" << endl;
    cout << "\tM E N U" << endl;
    cout << "1) Enteros\n";
    cout << "2) Caracteres simples\n";
    cout << "3) Salir\n";
    cout << "Ingrese la opcion deseada: ";
}

void printPerm(int x, char perm[]) {
    cout << "\t";
    for (int i = 0; i < x; i++) {
        cout << perm[i] << " ";
    }

    cout << endl;
}

void PermutacionesChar(int CharEle, char Perm[], int x) {

    if (CharEle == 1) {
        printPerm(x, Perm);
        return;
    }
    for (int i = 0; i < CharEle; i++) {
        PermutacionesChar(CharEle - 1, Perm, x);
        if (CharEle % 2 == 1) {
            swap(Perm[0], Perm[CharEle - 1]);
        }
        else {
            swap(Perm[i], Perm[CharEle - 1]);
        }
    }
}

int Factorial(int x) {
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact = i * fact;
    }
    return fact;
}