/* Jose Luis Sandoval Perez 1°A 
Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en 
otro vector. Dividirlos y el resultado guardarlo en otro vector.
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=8;
	float num1[tam], num2[tam]; 
	float div[tam];
	int i=0;
	
	printf("Ingresa 10 numeros en 2 vectores y te dire division \n");
	
	for(i=1;i<=8;i++){
		printf("\nIngresa numero %d: ", i);
		scanf("%f", &num1[i]);
		printf("Ingresa numero %d de vector 2: ", i);
		scanf("%f", &num2[i]);
		div[i]=num1[i] / num2[i];
		printf("\nNumeros\tDivision");
		printf("\n%.0f/%.0f \t%.2f", num1[i],num2[i], div[i]);
	}
}
