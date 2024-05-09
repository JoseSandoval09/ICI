/* P R O G R A M A   III    Algoritmo Genetico(IA) */
/*
Alumnos:
Ximena Rivera Delgadillo   ID: 261261
Jose Luis Sandoval Perez   ID: 261731

I  N  S  T  R  U  C  C  I  O  N  E  S
3) En un tercer ejercicio se pide realizar el cruzamiento realizando la selecci�n de 6 padres y cruzar el primer seleccionado al azar con el
    segundo al azar, el tercer seleccionado al azar con el cuarto al azar y el quinto seleccionado al azar con el sexto y los siguientes ajustes:

   a) A partir de la 2a generaci�n ordenar de mayor a menor los 10 individuos con sus 10 genes, con los que tengan m�s ceros
   b) Seguir el cruzamiento en posiciones aleatorias
   c) De cada par de padres y de par de hijos, elegir los dos mejores y devolverlos a la posici�n que ten�an los padres de ese cruzamiento
   d) Realizarlo hasta 250 generaciones o cuando encuentre los primeros 10 individuos con 10 ceros.


*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define sizepob 10 //definir longitud de la poblacion
int cn = 0; //contador de unos para determinar el orden de la matrices y el cierre de los ciclos generacionales

//S t r u c t  G e n 
struct Gen {
    int matrix[17][sizepob]; //para crear las matrices principal y temporal (magnitud 20*10)
};

//D e f i n i c i o n   f u n c i o n e s 
void inicialPo(struct Gen* poAct); //Funcion Iniciar Poblacion
void Print(struct Gen* poAct, int which);//Funcion Imprimir Poblacion
void combinar(struct Gen* poAct);//Funcion Combinar Padres
void best(struct Gen* poAct, struct Gen* poTmp); //Funcion Ordenar Poblacion (menor a mayor en realcion a la cantidad de unos)

//F u n c i o n   p r i n c i p a l
int main(int argc, char* argv[])
{
    int nGen = 0; // Variable numero de generaciones
    struct Gen poAct; //Inicializacion poblacion actual
    struct Gen poTmp; //inicializacion poblacion temporal
    poAct.matrix[16][sizepob]; //deficion del tama�o de la poblacion  A c t u a l
    poTmp.matrix[16][sizepob];//deficion del tama�o de la poblacion  T e m p o r a l

    //I N T R O D U C C I O N   del   P R O G R A M A
    cout << "Realizar un tercer ejercicio se pide realizar el cruzamiento realizando la seleccion de 6 padres y cruzar\n";
    cout << "\nEl primer seleccionado al azar con el segundo al azar, el tercer seleccionado al azar con el cuarto al \n";
    cout << "azar y el quinto seleccionado al azar con el sexto y los siguientes ajustes:\n";
    cout << "\na) A partir de la 2a generacion ordenar de mayor a menor los 10 individuos con sus 10 genes, con los que \n";
    cout << "   tengan mas ceros\n";
    cout << "\nb) Seguir el cruzamiento en posiciones aleatorias\n";
    cout << "\nc) De cada par de padres y de par de hijos, elegir los dos mejores y devolverlos a la posicion que tenian\n";
    cout << "   los padres de  ese cruzamiento\n";
    cout << "\nd) Realizarlo hasta 250 generaciones o cuando encuentre el primer individuo con 10 ceros.\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");

    // I N I C I O 
    cout << "C O M E N Z A N D O  a l g o r i t m o  generacional\n";
    //paso 1: generar una matriz inicial con bits aleatorios
    inicialPo(&poAct);//inicializar matriz inicial
    //paso 2: primera generacion de combinaciones NO SE ORDENA
    combinar(&poAct); //Funcion para combinar la matriz
    cout << "\n\n\tM  A  T  R  I  Z    I  N  I  C  I  A  L\t\t\t\t\t\t   Num Unos\n";
    Print(&poAct, 1);//Funcion para imprimir matriz inicial
    cout << "\n\n\tM  A  T  R  I  Z    C  O  M  B  I  N  A  C  I  O  N  E  S\t\t\tNum Unos\n\n";
    Print(&poAct, 2);//Funcion para imprimir matriz hijos
    best(&poAct, &poTmp);//Funcion para ordenar la matriz de mejor a peor

    cout << "\n----------------------------------------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");

    void combinar();
    

    cout << "\n----------------------------------------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");
    cout << "Programa elaborado por: Ximena Rivera Delgadillo\n";
    cout << "Jose Luis Sandoval Perez\n";
    cout << "\n----------------------------------------------------------------------------------------------------------------\n";
    return 0;
}
//F u n c i o n   i m p r i m i r   P o b l a c i o n
void Print(struct Gen* poAct, int which) {

    int cont = 1;
    if (which == 1) {
        for (int i = 0; i < 10; i++) {
            cout << "\n";
            cn = 0;
            cout << cont << ")\t";
            for (int j = 0; j < 10; j++) {
                cout << poAct->matrix[i][j];
                cout << "\t";
                if (poAct->matrix[i][j] == 1) {
                    cn++;
                }
            }
            cont++;
            cout << "     " << cn;
        }
    }
    else {
        for (int i = 11; i < 17; i++) {
            cout << "\n";
            cn = 0;
            cout << cont << ")\t";
            for (int j = 0; j < 10; j++) {
                cout << poAct->matrix[i][j];
                cout << "\t";
                if (poAct->matrix[i][j] == 1) {
                    cn++;
                }
            }
            cont++;
            cout << "     " << cn;

        }
    }
    
}
//F u n c i o n   i n i c i a r   P o b l a c i o n
void inicialPo(struct Gen* poAct) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < sizepob; i++) {
        for (j = 0; j < sizepob; j++) {
            if ((rand() % 100) + 1 <= 50) {
                poAct->matrix[i][j] = 1;
            }
            else {
                poAct->matrix[i][j] = 0;
            }
        }
    }
}
//F u n c i o n   c o m b i n a r   P o b l a c i o n
void combinar(struct Gen* poAct) {
    int i, j;
    srand(time(NULL));
    int  nEv, nIv;

    for (i = 0; i < sizepob; i++) {
        for (j = 0; j < sizepob; j++) {
            poAct->matrix[i + sizepob][j] = poAct->matrix[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        nEv = (rand() % 10) + 1;
        nIv = (rand() % 5) + 1;
        for (j = 0; j < nEv; j++) {
            if ((rand() % 100) + 1 <= 50) {
                poAct->matrix[nIv + sizepob][j] = poAct->matrix[nIv][j];
            }
            else {
                poAct->matrix[nIv + sizepob][j] = poAct->matrix[9 - nIv][j];
            }
            if ((rand() % 100) + 1 <= 50) {
                poAct->matrix[nIv + 5 + sizepob][j] = poAct->matrix[nIv][j];
            }
            else {
                poAct->matrix[nIv + 5 + sizepob][j] = poAct->matrix[9 - nIv][j];
            }
        }
    }
}
//F u n c i o n   o r d e n a r   P o b l a c i o n
void best(struct Gen* poAct, struct Gen* poTmp) {
    int numC[16];
    int i, j, x, max, pos;
    for (i = 0; i < 15; i++) {
        numC[i] = 0;
        for (j = 0; j < sizepob; j++) {
            if (poAct->matrix[i][j] == 0) {
                numC[i]++;
            };
        }
    }
    for (x = 0; x < sizepob; x++) {
        max = 0; pos = 0;
        for (i = 0; i < 15; i++) {
            if (numC[i] > max) {
                max = numC[i];
                pos = i;
            }
        }
        numC[pos] = -1;
        for (j = 0; j < sizepob; j++) {
            poTmp->matrix[x][j] = poAct->matrix[pos][j];
        }
    }
}