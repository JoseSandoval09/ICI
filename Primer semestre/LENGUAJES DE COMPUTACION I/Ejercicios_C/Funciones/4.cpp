#include<locale.h>
#include<stdio.h>
#include<stdio.h>
#include<conio.h>
//EJERCICIO 3: Funciones (Paso de Parámetros Por Valor; Pasar los parámetros por referencia)
//Lenguajes de Computación 1°E  (PARCIAL 3)
//Carlos Daniel Torres Macias ID:244543
//Diego Emanuel Saucedo Ortega ID:261230
//José Luis Sandoval Perez ID: 261731
//Ximena Rivera Delgadillo ID:261261
void iq(int valor);
int bajo=80, normal=90, promedio=110, superior=120, IQ=234;
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
	
	printf("Tu valor de IQ es %d ", IQ);
	printf("Es broma crack");
	iq(IQ);
	getch();
	
	
	
	system("color B0");
	printf("\n\nHecho:\nCarlos Daniel Torres Macias ID:244543 \nDiego Emanuel Saucedo Ortega ID:261230 \nJosé Luis Sandoval Perez ID: 261731 \nXimena Rivera Delgadillo ID:261261\n\n");
	system("pause");
	return 0;
	}
	
void iq(int &valor){
	printf("¿Cual es tu verdadero valor?");
	scanf("%d", &valor);
	valor=IQ;
 if(valor<=0){printf("El valor ingresado no es válido\n");}
 if(valor<=bajo && valor>0){
  bajo=valor;
  printf("Tu IQ se encuentra en el rango:\n");
  printf("Muy muy bajo, UPS tu IQ es:%d\n",bajo);
 } 
  if(valor>=bajo && valor<normal){
  bajo=valor;
  
  printf("Tu verdadero IQ se encuentra en el rango:\n");
  printf("Bajo, tu IQ es:%d\n",bajo);
 } 
 if(valor>=normal && valor<promedio){
  normal=valor;
  printf("Tu verdadero IQ se encuentra en el rango:\n");
  printf("Normal, tu IQ es:%d\n",normal);
 } 
 if(valor>=promedio && valor<superior){
  promedio=valor;
  printf("Tu verdadero IQ se encuentra en el rango:\n");
  printf("Alto, tu es IQ:%d ",promedio);
 } 
 if(valor>=superior && valor<129){
  superior=valor;
  printf("Tu verdadero IQ se encuentra en el rango:\n");
  printf("Superior al promedio, tu IQ es:%d",superior);
 } 
 if(valor>129){
  superior=valor;
  printf("Tu verdadero IQ se encuentra en el rango:\n");
  printf("Muy muy muy alto,WOW WOW WOW tu IQ es:%d",superior);
  }
}