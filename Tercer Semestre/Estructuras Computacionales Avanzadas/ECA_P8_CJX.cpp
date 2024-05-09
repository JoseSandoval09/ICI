/*
Universidad Autonoma De Aguascalientes
Ingenier�a en Computacion Inteligencia
Estructuras Computacionales Avanzadas

El�as Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfile�o

Se va a crear un programa para la implementaci�n del metodo hungaro para determinar un
arbol de expansi�n m�nimo
*/
//b i b l i o t e c a s
#include <iostream>
using namespace std;

//d e c l a r a c i o n  m a t r i z  tareas*trabajadores
int matrix[3][3] = {
    {15,10,9},
    {9,15,10},
    {10,10,8} };

void copyMatrix(int[][3]);
void printMatrix(int[][3]);
int min(int[][3], int, int);

int main() {
    int aux[3][3],minicost = 0, i, j;//vector auxiliar
    bool ch[3] = { false,false,false };//elegidos
    cout << "\tI N T R O D U C C I O N  del  p r o g r a m a" << endl;
    cout << "El siguiente programa nos permitira implementar el metodo hungaro para determinar un arbol de\n";
    cout << "expansion minimo\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    copyMatrix(aux);//copiar matriz a aux
    cout << "   M A T R I Z   I N I C I A L\n";
    printMatrix(aux);//imprimir matriz
    //sacar  minimo columna y restar
    for (i = 0; i < 3; i++) {
        int minJ = min(matrix, i, 0);
        for (j = 0; j < 3; j++) {
            aux[i][j] -= minJ;
        }
    }
    cout << "   M A T R I Z   P A S O (1)\n";
    printMatrix(aux);//imprimir matriz
    //sacar  minimo fila y restar
    for (i = 0; i < 3; i++) {
        int minI = min(aux, i, 1);
        for (j = 0; j < 3; j++) {
            
            aux[j][i] -= minI;
        }
    }
    cout << "   M A T R I Z   P A S O (2)\n";
    printMatrix(aux);//imprimir matriz
    cout << "\t A S I G N A C I O N  de  t a r e a s" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (aux[i][j] == 0 && !ch[j]) {
                cout <<"TRABAJADOR ("<<i + 1 << ") tarea asignada = " << j + 1 <<"\n";
                minicost += matrix[i][j];
                ch[j] = true;
                break;
            }
        }
    }
    cout << "Costo minimo: " << minicost << endl;
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");

    cout << "PROGRAMA REALIZADO POR:\n";
    cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    return 0;
}

void copyMatrix(int A[][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "\t" << matrix[i][j];
        }
        cout <<"\n";
    }
    cout << "\n";
}
int min(int matrix[][3], int i, int mode) {

    int menor = 999;
    for (int j = 0; j < 3; j++) {
        if (mode == 0) { menor = min(menor, matrix[i][j]); }
        else { menor = min(menor, matrix[j][i]); }
    }
    return menor;
}