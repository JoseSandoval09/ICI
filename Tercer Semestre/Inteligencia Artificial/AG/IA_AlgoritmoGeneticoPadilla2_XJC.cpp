/* P R O G R A M A   II    Algoritmo Genetico(IA) */
/*
Alumnos:
Ximena Rivera Delgadillo   ID: 261261
Jose Luis Sandoval Perez   ID: 261731
Cesar Eduardo Elias Del Hoyo ID: 262045
I  N  S  T  R  U  C  C  I  O  N  E  S
2) En un segundo ejercicio se pide realizar el cruzamiento de igual manera 1-10, 2-9, 3-8, 4-7, 5-6, pero con los siguientes ajustes:

   a) A partir de la 2a generaci�n ordenar de mayor a menor los 10 individuos con sus 10 genes, con los que tengan m�s ceros
   b) Seguir el cruzamiento en posiciones aleatorias
   c) De cada par de padres y de par de hijos, elegir los dos mejores y devolverlos a la posici�n que ten�an los padres de ese cruzamiento
   d) Realizarlo hasta 250 generaciones o cuando encuentre el primer individuo con 10 ceros.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define sizepob 10 //definir longitud de la poblacion
int numOnes=-1; //contador de unos para determinar el orden de la matrices y el cierre de los ciclos generacionales

//S t r u c t  G e n 
struct Gen {
    int matrix[16][sizepob]; //para crear las matrices principal y temporal (magnitud 20*10)
};

//D e f i n i c i o n   f u n c i o n e s 
void inicialPo(struct Gen* poAct); //Funcion Iniciar Poblacion
void Print(struct Gen* poAct, int which);//Funcion Imprimir Poblacion
void combinar(struct Gen* poAct);//Funcion Combinar Padres
void best(struct Gen* poAct, struct Gen* poTmp); //Funcion Ordenar Poblacion (menor a mayor en realcion a la cantidad de unos)
void mutar(struct Gen* poAct);
void clear(struct Gen* poAct, struct Gen* poTmp);

//F u n c i o n   p r i n c i p a l
int main(int argc, char* argv[])
{
        srand(time(NULL)); //random
        int nGen = 0; // Variable numero de generaciones
        struct Gen poAct; //Inicializacion poblacion actual
        struct Gen poTmp; //inicializacion poblacion temporal
        poAct.matrix[16][sizepob]; //deficion del tama�o de la poblacion  A c t u a l
        poTmp.matrix[16][sizepob];//deficion del tama�o de la poblacion  T e m p o r a l
        nGen = 1;
        //I N T R O D U C C I O N   del   P R O G R A M A
        cout << " I  N  T  R  O  D  U  C  C  I  O  N   del   P  R  O  G  R  A  M  A" << endl;
        cout << "De acuerdo a las ultimas restricciones del cruzamiento en el que se elegieron 6 al azar en cada generacion y realizar el\n";
        cout << "cruce de cada par de padres y en el mismo momento de cada par de padres e hijos, regresar los dos mejores a las posiciones\n";
        cout << "de los padres, realizar la mutacion DE ACUERDO A LO QUE SE SOLICITA:\n";
        cout << "DESPUES DE ORDENAR EN LA PRIMER GENERACION USANDO CRUZAMIENTO, SE LE AGREGARA EN CADA GENERACION UNA MUTACION, COMO SIGUE:\n";
        cout << "a) Tomando los ultimos 5 individuos, elegir 2 individuos al azar, que seria equivalente al 20% de la poblacion el cambio\n";
        cout << "b) Generar para cada individuo seleccionado (de los dos), un porcentaje del 10 al 40%, para elegir con su porcentaje \n";
        cout << "del bit( 0 cambia a 1, o 1 cambia a 0); si se genero\n";
        cout << "10%   mutar 1 bit al azar\n";
        cout << "20%   mutar 2 bit al azar\n";
        cout << "30%   mutar 3 bit al azar\n";
        cout << "40%   mutar 4 bit al azar\n";
        cout << "c) Elegir al azar los puntos o bits a mutar, de acuerdo al porcentaje del punto b\n";
        cout << "d) d) Volver a ordenar y repetir la acci�n para cada generacion\n";
        cout << "----------------------------------------------------------------------------------------------------------------------------\n";
        system("pause");
        system("cls");


        // I N I C I O 
        cout << "C O M E N Z A N D O  a l g o r i t m o  generacional\n";
        //paso 1: generar una matriz inicial con bits aleatorios
        inicialPo(&poAct);//inicializar matriz inicial
        for (nGen = 1; nGen < 251; nGen++) {
            if (numOnes != 0) {
                cout << "\n\t\t  G  E  N  E  R  A  C  I  O  N : " << nGen << endl;
                combinar(&poAct); //Funcion para combinar la matriz
                cout << "\n\n\tM  A  T  R  I  Z    I  N  I  C  I  A  L\t\t\t\t\t\t   Num Ceros\n";
                Print(&poAct, 1);//Funcion para imprimir matriz inicial (matriz 10*10) primeros 10 padres ultimos 10 hijos
                cout << "\n\n\tM  A  T  R  I  Z    C  O  M  B  I  N  A  C  I  O  N  E  S\t\t\tNum Unos\n\n";
                Print(&poAct, 2);//Funcion para imprimir matriz hijos 
                best(&poAct, &poTmp);//Funcion para ordenar la matriz de mejor a peor 
                cout << "\n\n\tM A T R I Z   c o m b i n a c i o n e s   O  R  D  E  N  A  D  A\t\t  Num Unos\n\n";
                Print(&poTmp, 1);//Funcion para imprimir matriz inicial (matriz 10*10) primeros 10 padres ultimos 10 hijos
                mutar(&poAct);
                cout << "\n\n\tM A T R I Z    m u t a c i o n e s   a l e a t o r i a s\t\t            Num Unos\n\n";
                Print(&poAct, 1);//Funcion para imprimir matriz inicial (matriz 10*10) primeros 10 padres ultimos 10 hijos
                best(&poAct, &poTmp);//Funcion para ordenar la matriz de mejor a peor  
            }
            else {
                cout << " T A R E A    F I N A L I Z A D A   C O R R E C T A M E N T E\n";
                cout << "Los 10 individuos se encuentran compuestos unicamente con valores de 0" << endl;
                cout << "\n\tT O T A L  de g e n e r a c i o n e s  alcanzadas (" << nGen - 1 << ")\n";
                nGen = 251;
            }
            cout << "\n----------------------------------------------------------------------------------------------------------------\n";
            system("pause");
            system("cls");
        } 
    cout << "\nG R A C I A S  G R A C I A S  G R A C I A S  G R A C I A S  G R A C I A S  G R A C I A S  G R A C I A S  G R A C I A S\n";
    cout << "Programa elaborado por:\nCesar Eduardo Elias Del Hoyo\nXimena Rivera Delgadillo\n";
    cout << "Jose Luis Sandoval Perez\n";
    cout << "\n--------------------------------------------------------------------------------------------------------------------\n";
    return 0;
}
//F u n c i o n   i m p r i m i r   P o b l a c i o n
void Print(struct Gen* poAct, int which) {

    int cont = 1;//contador de renglon individuo
    if (which == 1) { //nos permite delimitar si vamos a imprimir la matriz completa Padres e Hijos o unicamente una u otra
        for (int i = 0; i < 10; i++) {//for que recorre unicamente los primeros 10 renglones (padres)
            cout << "\n";
            numOnes = 0;//contador de numero de unos inicializado a 0
            cout << cont << ")\t"; //imprimimos el contador renglon para saber de que individuo se trata
            for (int j = 0; j < 10; j++) { //for que recorre las columnas de 0 a 9
                cout << poAct->matrix[i][j]; //imprimimos el valor de la posicion en la matriz
                cout << "\t";//tabulacion para separar
                if (poAct->matrix[i][j] == 1) { //si el valor de la posicion es 1 el contador de unos aumenta
                    numOnes++;
                }
            }
            cont++;//incremento del contador renglones
            cout << "     " << numOnes;//imprimimos el contador de unos 
        }
    }
    else {
        for (int i = 10; i < 16; i++) {//for que recorre toda la matriz es decir Padres e Hijos
            cout << "\n";
            numOnes = 0;//contador de numero de unos inicializado a 0
            cout << cont << ")\t";//imprimimos el contador renglon para saber de que individuo se trata
            for (int j = 0; j < 10; j++) { //for que recorre las columnas de 0 a 9
                cout << poAct->matrix[i][j];//imprimimos el valor de la posicion en la matriz
                cout << "\t";//tabulacion para separar
                if (poAct->matrix[i][j] == 1) {//si el valor de la posicion es 1 el contador de unos aumenta
                    numOnes++;
                }
            }
            cont++;//incremento del contador renglones
            cout << "     " << numOnes;//imprimimos el contador de unos 
        }
    }
}

//F u n c i o n   i n i c i a r   P o b l a c i o n
void inicialPo(struct Gen* poAct) {
    int i, j; //contadores i y j
    for (i = 0; i < sizepob; i++) { //for que recorre la matriz de 0 a 9 renglones unicamente Padres
        for (j = 0; j < sizepob; j++) {//for que recorre la matriz de 0 a 9 columnas
            if ((rand() % 100) + 1 <= 50) { //condicional que nos permita realizar un random y llenar la matriz de 0 o 1
                poAct->matrix[i][j] = 1;
            }
            else {poAct->matrix[i][j] = 0;}
        }
    }
}
//F u n c i o n   c o m b i n a r   P o b l a c i o n
void combinar(struct Gen* poAct) {
    int i, j, c=0; //contadores
    int nIv; 
    int aux[6], father, mother;
    for (int u = 0; u < 6; u++) { aux[u] = -1; }//llenamos el vector aux con -1
    bool esta = true; 
    //ciclo 3 veces la creacion de 1 padres y 1 madres TOTAL:6
    //cout << "\n-i n f o r m a c i o n  de  c o m b i n a c i o n e s-\n";
    for (int three = 0; three < 3; three++) {
        for (i = 0; i < 6; i++) {//6 posibles elecciones
            while (esta == true){
                father = (rand() % 9); //cual valor voy a cambiar
                mother = (rand() % 9);//random que escoge a mother
                esta = false; //marcamos esta como falso
                for (int x = 0; x <= 6; x++) { //for que recorre el vector de 0 hasta el valor que valor antes que el i
                    if (aux[x]==father|| father == mother|| aux[x] == mother) { //si el valor de aux es igual a wh
                        esta = true;//cambiamos el booleneo a verdadero
                    }
                }
            } //si son iguales elige otro para que sean diferentes
            if(i==0){aux[i] = father;aux[i+1] = mother;}
            if(i==1){aux[i+1] = father;aux[i+2] = mother;}
            if(i==2){aux[i+2] = father;aux[i+3] = mother;}
            esta = true;//cambiamos el booleano a verdadero
            //cout << " PADRES a combinar: (" << father+1 << "," << mother+1 << ")" << endl; //imprimimos el par de padres elegidos
            for (i = 0; i < 16; i++) { //for que recorre la matriz completa
                for (j = 0; j < sizepob; j++) { //for para las columnas
                    if (three == 0) { //si three es 0 copiamos a el padre a las posiciones 10 y 11
                        poAct->matrix[10][j] = poAct->matrix[father][j];
                        poAct->matrix[11][j] = poAct->matrix[father][j];
                    }
                    if (three == 1) {//si three es 1 copiamos a el padre a las posiciones 12 y 13
                        poAct->matrix[12][j] = poAct->matrix[father][j];
                        poAct->matrix[13][j] = poAct->matrix[father][j];
                    }
                    if (three == 2) {//si three es 2 copiamos a el padre a las posiciones 14 y 15
                        poAct->matrix[14][j] = poAct->matrix[father][j];
                        poAct->matrix[15][j] = poAct->matrix[father][j];
                    }
                }
            }
            nIv = (rand() % 5) + 1; //seleccionamos la cantidad de individuos a cambiar (valor entre 1 y 5)
            //cout << " BITS aleatorios a cambiar (" << nIv << ")\n"; //imprimimos los valores a cambiar
            //cout << "\n";
            for (i = 10; i < 16; i++) {//for que recorre la matriz completa
                for (j = 0; j < nIv; j++) {//for que recorre la cantidad se individuos que vamos a cambiar
                    if ((rand() % 100) + 1 <= 50) { //condicional random que nos permita seleccionar aleatoriamente cuales son los bits que vamos a cambiar
                        poAct->matrix[i][mother] = poAct->matrix[i][j];
                    }
                    else {
                        poAct->matrix[i][mother] = poAct->matrix[i][j];
                    }
                }
            }
        }
    }
}
//F u n c i o n   o r d e n a r   P o b l a c i o n
void best(struct Gen* poAct, struct Gen* poTmp)
{
    int numC[16];//arreglo numero de 0
    int i, j, x, max, pos; //i=filas j=columnas x=filas max=valor maximo de 0 pos=posicion del valor maximo de 0 
    //ciclo for que recorre la matriz completa para seleccionar los mejores
    for (i = 0; i < 16; i++) {
        numC[i] = 0; //arreglo numero de 0 inicializado a 0
        for (j = 0; j < sizepob; j++) { //ciclo for recorre las columnas
            if (poAct->matrix[i][j] == 0) { //si el valor es un cero aumenta el contador y lo guarda en la misma posicion del arreglo
                numC[i]++;
            };
        }
    }
    for (x = 0; x < sizepob; x++) {//for filas de la 0 a la 9
        max = 0; pos = 0; //valor maximo de ceros es 0 su posicion es 0
        for (i = 0; i < 16; i++) { //for que recorre toda la matriz
            if (numC[i] > max) { //si el valor del arreglo de la cantidad de ceros es mayor al pasado entonces
                max = numC[i]; //maximo va a tomar ese valor
                pos = i;// y vamos a guardar su posicion
            }
        }
        numC[pos] = -1; //y ahora vamos a guardar en esa posicion en el arreglo un -1 para distinguirlo de los 0
        for (j = 0; j < sizepob; j++) {//for recorre las columnas
            poTmp->matrix[x][j] = poAct->matrix[pos][j]; //copia los mejores de la matriz actual a la temporal
        }
    }
    //ciclo for para copiar los mejores de la matriz temporal a la original
    for (i = 0; i < sizepob; i++) {
        for (j = 0; j < sizepob; j++) {
            poAct->matrix[i][j] = poTmp->matrix[i][j];
        }
    }
}
void mutar(struct Gen* poAct) {
    int porcent;//porcentaje de mutacion
    int stop=0;
    int numC[16];//arreglo numero de 0
    //agregando a la matriz una columna con numero de ceros
    for (int i = 0; i < 10; i++) {
        numC[i] = 0; //arreglo numero de 0 inicializado a 0
        for (int j = 0; j < 10; j++) {
            if (poAct->matrix[i][j] == 0) {
                numC[i]++;
            }
        }
    }
    // SUMAR LAS CADENAS CON 0 unos
    for (int i = 0; i < 10; i++) {
        if (numC[i] == 10) {
            stop++;
        }
    }
    //cout << "\n\nCadenas con puros 0: " << stop <<"\n";
    if (stop < 9) {
        int var = -1, cho1 = -1; //variable que nos permita que la eleccion del individuo a mutar sea diferente, choice que es la eleccion del individuo a mutar
        for (int i = 0; i < 2; i++) {//for que nos permite hacer la mutuacion a 2 individuos
            while (cho1 == var) {
               cho1 = (rand() % 4) + 5; //eleccion
            }
            //cout << "\n\n INDIVIDUO a mutar( " << cho1 + 1 << ")\n"; //imprimimos el individuo a mutar
            porcent = (rand() % 4) + 1; //sacamos un valor random entre 1 y 4
            //cout << " PORCENTAJE a mutar: " << porcent * 10 << "%\n"; //imprimimos el porcentaje obtenido
            int aux[4], wh = -2; //tenemos un vector aux que nos permite identificar que los valores aleatorios de bits que vamos a cambiar sean diferentes
            for (int u = 0; u < 4; u++) { aux[u] = -1; }//llenamos el vector aux con -1
            bool esta = true; //declaramos un booleano llamado esta que nos permite identificar si wh esta en el vetor o no
            
            for (int j = 0; j < porcent; j++) {  // cuantos voy a cambiar
                while (esta == true) { //mientras esta sea verdadero sacamos otra vez cual valor voy a cambiar
                    wh = (rand() % 9); //cual valor voy a cambiar
                    esta = false; //marcamos esta como falso
                    for (int x = 0; x <= j; x++) { //for que recorre el vector de 0 hasta el valor que valor antes que el j
                        if (aux[x] == wh) { //si el valor de aux es igual a wh
                            esta = true;//cambiamos el booleneo a verdadero
                        }
                    }
                }
                aux[j] = wh; //guardamos en el vector el valor de wh
                esta = true;//cambiamos el booleano a verdadero
                //cout << " BIT a  m u t a r: " << wh + 1 << "\n";//imprimimos el BIT a mutar (es decir el que es distinto, el que si se queda) 
                if (poAct->matrix[cho1][wh] == 1) { poAct->matrix[cho1][wh] = 0; } //condicional para cambiar el valor del bit por el contrario
                else {
                    poAct->matrix[cho1][wh] = 1;
                }
            }
            var = cho1;
        }
    }
}