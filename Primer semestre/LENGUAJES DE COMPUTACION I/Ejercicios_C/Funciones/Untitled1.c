#include<locale.h>
#include<stdio.h>
#include<stdio.h>
#include<conio.h>
//EJERCICIO 3: Funciones (Paso de Parámetros Por Valor; Pasar los parámetros por referencia)
//Lenguajes de Computación 1°E  (PARCIAL 3)
//Carlos Daniel Torres Macias ID:244543
//Diego Emmanuel Saucedo Ortega ID:261230
//José Luis Sandoval Perez ID: 261731
//Ximena Rivera Delgadillo ID:261261
void iq(int valor);
int bajo=80, normal=90, promedio=110, superior=120;
int main(){
	setlocale(LC_ALL,"spanish");
	printf("El siguiente programa nos permitirá utilizar las funciones paso de parámetros por valor o por referencia\n");
	int IQ=0;
	printf("El siguiente programa le permitirá conocer el rango intelectual que posee a partir del valor ingresado de IQn");
	printf("\nRANGOS DE COEFICIENTE INTELECTUAL\n");
	printf("Puntuaciones de CI de entre %d y 89 puntos: Bajo\n",bajo);
	printf("Puntuaciones de CI de entre %d y 109 puntos: Normal\n",normal);
	printf("Puntuaciones de CI de entre %d y 119 puntos: Alto\n",promedio);
	printf("Puntuaciones de CI de entre %d y 129 puntos: Nivel de inteligencia superior al promedio\n",superior);
	
	printf("\nIngrese el valor correspondiente a su IQ\n");
	scanf("%d",&IQ);
	iq(IQ);
	getch();
	system("pause");
	return 0;
	}
	
void iq(int ;&valor){
 if(valor<=0){printf("El valor ingresado no es válido\n");}
 if(valor<=bajo && valor>0){
  bajo=valor;
  printf("Su IQ:%d es muy bajo\n",bajo);
 } 
  if(valor>=bajo && valor<normal){
  bajo=valor;
  printf("Su IQ:%d es bajo\n",bajo);
 } 
 if(valor>=normal && valor<promedio){
  normal=valor;
  printf("Su IQ:%d es normal\n",normal);
 } 
 if(valor>=promedio && valor<superior){
  promedio=valor;
  printf("Su IQ:%d es alto",promedio);
 } 
 if(valor>=superior && valor<129){
  superior=valor;
  printf("Su IQ:%d es superior al promedio",superior);
 } 
 if(valor>129){
 superior=valor;
  printf("WOW su IQ:%d es muy muy muy alto",superior);
  }
}

