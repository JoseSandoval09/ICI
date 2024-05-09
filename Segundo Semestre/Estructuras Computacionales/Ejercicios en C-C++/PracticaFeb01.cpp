/* PRACTICA 01/02/2022
JOSE LUIS SANDOVAL PEREZ 2A ICI*/


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdint.h>

using namespace std;



struct estructura{
    char nomb[30];
    int edad;
    float sueldo;

};

struct estructura datosEmpleado;

int main(){

    char nomb[30];
    int edad;
    float sueldo;

    cout<<"Dame tu nombre: ";
    cin.getline(datosEmpleado.nomb,30);

   
    cout<<"Dame tu edad: ";
    fflush(stdin);
    cin>> datosEmpleado.edad;
    cout<<"Dame tu sueldo: ";
    cin>> datosEmpleado.sueldo;
    cout<<"Hola "<<datosEmpleado.nomb<<"tienes "<<datosEmpleado.edad<<"years old y tu sueldo es: "<<datosEmpleado.sueldo;


    





    return 0;

}