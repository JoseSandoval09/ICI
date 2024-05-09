//JOSE LUIS SANDOVAL PEREZ 2A ICI
//EJEMPLO UNIONES


#include<stdio.h>


typedef union Persona Persona;

union Persona{
    char nombre[50];
    char inicial;

};


int main(){

    Persona nombre = {"Pepito"};
    nombre.inicial = 'L';

    printf("Se que no me diste tu nombre pero porque ya se me acabara la pila te nombrare %s",nombre.nombre);


}