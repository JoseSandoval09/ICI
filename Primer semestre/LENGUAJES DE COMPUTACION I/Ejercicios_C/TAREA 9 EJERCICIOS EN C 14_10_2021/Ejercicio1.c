/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 1
Programa que calcula el área de un círculo usando una constante pi definida con define.
*/

#include<stdio.h>
#include<math.h>

#define pi 3.1416



int main(){
	
	float radi=0, area=0;
	
	
	printf("Este programa calcula el area de un circulo siguiendo la formula pi x r^2\n (pi=3.1416)");
	printf("\nTe pedire a continuacion el radio del circulo, por favor introducirlo con 2 decimales\n");
	scanf("%f", &radi);
	
	area= pi * pow(radi,2);
	
	printf("El area del circulo con es: %.2f metros cuadrados", area);
	
}
