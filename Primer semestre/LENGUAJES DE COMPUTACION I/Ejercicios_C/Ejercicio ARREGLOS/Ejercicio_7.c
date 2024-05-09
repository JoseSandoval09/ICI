/*
Jose Luis Sandoval Perez 1°A 
Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en 
otro vector. Sumarlos y el resultado guardarlo en otro vector.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=8;
	int num1[tam], num2[tam], suma[tam];
	int i=0;
	
	printf("Ingresa 10 numeros en 2 vectores y te dire su suma\n");
	
	for(i=1;i<=8;i++){
		printf("\nIngresa numero %d: ", i);
		scanf("%d", &num1[i]);
		printf("Ingresa numero %d de vector 2: ", i);
		scanf("%d", &num2[i]);
		suma[i]=(num1[i] + num2[i]);
		printf("\nNumeros\tSuma");
		printf("\n%d+%d \t%d", num1[i],num2[i], suma[i]);
	}
}


