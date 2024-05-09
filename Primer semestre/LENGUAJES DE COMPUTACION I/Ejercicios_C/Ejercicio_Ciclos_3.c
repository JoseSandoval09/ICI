/*
	Jose Luis Sandoval Perez
	ICI 1°A
	Programa donde dados como datos los sueldos de 10 trabajadores obtenga el total a pagar.
*/	

#include<stdio.h>
#include<stdlib.h>


int main(){

	
	int sueldo=0,i=1,total=0;
	
	while(i<=10)
	{
		printf("Dame el suelo del trabajador %d\n", i);
		scanf("%d", &sueldo);
		total=sueldo+total;
		i++;
	}
	printf("El total a pagar de los sueldos es: $ %d", total);

	return 0;		
}
		