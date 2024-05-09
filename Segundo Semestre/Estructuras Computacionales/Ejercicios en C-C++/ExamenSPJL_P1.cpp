/*
Pedir y calcular de cada trabajador la siguiente información: 
1.	Nombre
2.	Piezas elaboradas de cada día de la semana inglesa (lunes a viernes). Se debe de almacenar en un arreglo.
3.	Cantidad menor de piezas producidas (se debe calcular)
4.	Cantidad mayor de piezas producidas (se debe calcular)

Guarda en una lista la información de N trabajadores.   <<<Valor 1 pto.>>>

Realizar lo siguiente:
1.	Mostrar él o los trabajadores con mayor numero de piezas semanales. <<<Valor 2 pts.>>>
2.	Lista de trabajadores indicando que día o días de la semana obtuvo la producción menor.                <<<Valor 2 pts.>>>
3.	Hacer otra versión del programa que permita capturar días de trabajo especifico de cada día de la semana inglesa por cada trabajador. <<<Valor 2 pts.>>>
4.	Eliminar trabajadores dados de alta, indicados por el usuario. <<<Valor 2 pts.>>>

Nota 1: manejar una función que reciba al menos como parámetro un arreglo. <<<Valor 1 pto.>>>
Nota 2: Realiza de cada ejercicio una autoevaluación.
Nota 2: Indica el tiempo aproximado de realización del examen. 

*/

#include<iostream>
#include<conio.h>

using namespace std;

//Struct
struct Informacion{
    string Nombre[30];
    int dias=5;
    int numPiezas_Dia[5];

    Informacion *siguiente;

};

//Funciones
void CapturarInformacion(Informacion *&, int);



int main(){

    Informacion *lista= NULL;




}

void CapturarInformacion(Informacion *&lista, int n){

    Informacion *nueva_informacion= new Informacion();
    


}


