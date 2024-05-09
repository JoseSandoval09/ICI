/* Jose Luis Sandoval Perez 1°A
Leer 8 numero enteros, guardarlos en un vector, multiplicarlos por 2 y guardar el resultado en 
otro vector. Al final imprimir los 2 vectores.
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=8;
	int num[tam], mult[tam];
	int i;
	
	printf("Ingresa 10 numeros y te dire su doble \n");
	
	for(i=1;i<=10;i++){
		printf("\nIngresa numero %d: ", i);
		scanf("%d", &num[i]);
		mult[i]=(num[i] * 2);
		printf("\nNumero\tDoble");
		printf("\n%d\t%d", num[i],mult[i]);
	}
}

