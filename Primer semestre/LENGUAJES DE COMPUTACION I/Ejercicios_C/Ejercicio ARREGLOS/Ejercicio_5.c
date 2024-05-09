/* Jose Luis Sandoval Perez 1°A
 Leer 10 números enteros, guardarlos en un vector, elevarlos al cuadrado y guardar el resultado 
en otro vector. Al final imprimir los 2 vectores.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	const int tam=10;
	int num[tam], numcuad[tam];
	int i;
	
	printf("Ingresa 10 numeros y te dire su cuadrado\n");
	
	for(i=1;i<=10;i++){
		printf("\nIngresa numero %d: ", i);
		scanf("%d", &num[i]);
		numcuad[i]=pow(num[i],2);
		printf("\nNumero\tCuadrado");
		printf("\n%d\t%d", num[i],numcuad[i]);
	}
}