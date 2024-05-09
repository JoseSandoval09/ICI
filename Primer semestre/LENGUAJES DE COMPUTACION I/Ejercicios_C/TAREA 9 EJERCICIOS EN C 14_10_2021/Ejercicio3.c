/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 3
Programa que convierte de pulgadas a centímetros.
*/


#include<stdio.h>


int main(){
	
	// 1inch= 2.54cm
	
	float pulg=0,pulg_cm=2.54,valor=0;
	
	printf("Este programa convierte pulgadas a centimetros (1 inch= 2.54 cm)\n");
	printf("Introduce cuantas pulgadas quieres convertir a centimetros: ");
	scanf("%f", &pulg);
	
	valor= pulg * pulg_cm;
	
	printf("Las  %.2f pulgadas convertidas a centimetros son: %.2f", pulg,valor);
	
	
	
}