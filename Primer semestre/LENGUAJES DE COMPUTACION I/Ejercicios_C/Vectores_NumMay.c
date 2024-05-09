// Jose Luis Sandoval Perez 1°A ICI


#include<stdio.h>
#include<stdlib.h>


int main(){
	
	const int TAM=5;
	int i, nmay=0, pos=0;
	int arreglo[TAM];
	
	for(i=0; i < TAM; i++)
	{
		printf("Ingresa un numero\n", i+1);
		scanf("%d", &arreglo[i]);
	}
	
	nmay=arreglo[0];
	pos=0;
	
	for(i=0; i < TAM; i++)
	{
		if (arreglo[i]>nmay)
		{
			
			nmay=arreglo[i];
			pos= i+1;
		}
	}
	
	printf("\nLos numeros ingresados son: ");
	for(i=0; i< TAM; i++)
	{
		printf("%d   ", arreglo[i]);	
	}
	
	printf("\n El numero mayor del arreglo es: %d y se encuentra en la posicion %d", nmay, pos);
	
	
	
}
