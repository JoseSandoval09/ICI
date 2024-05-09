/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 4
Programa que calcule el monto a pagar por articulo y en total.
Costos:libros a $100.00 cada uno, cuadernos a $15.50 y plumas a $2.35. 
*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	float lib=100.00,cuad=15.50,plum=2.35,total=0,totallib=0,totalcuad=0,totalplum=0;
	int cant_lib,cant_cuad,cant_plum;
	
	printf("A continuacion calculare el total a pagar de tu compra, estos son los precios:\n");
	printf("libros: $100.00\n");
	printf("cuadernos: $15.50\n");
	printf("plumas: $2.35\n");
	printf("¿cuantos libros deseas comprar?\n");
	scanf("%d", &cant_lib);
	printf("¿cuantos cuadernos deseas comprar?\n");
	scanf("%d", &cant_cuad);
	printf("¿cuantas plumas deseas comprar? \n");
	scanf("%d", &cant_plum);
	
	totallib=cant_lib * lib;
	totalcuad=cant_cuad * cuad;
	totalplum=cant_plum * plum;
	total= (cant_lib * lib) + (cant_cuad * cuad) + (cant_plum * plum);
	
	printf("El total a pagar de los libros es: $%.2f\n", totallib);
	printf("El total de los cuadernos es: $%.2f\n", totalcuad);
	printf("El total de las plumas es: $%.2f\n", totalplum);
	printf("El total de tu compra es: $%.2f", total);
	
	
}