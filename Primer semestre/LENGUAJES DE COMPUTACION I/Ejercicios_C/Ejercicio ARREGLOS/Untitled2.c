// Jose Luis Sandoval Perez 1°A ICI
/* Programa pida 10 números enteros por teclado y que imprima por pantalla:
a) Cuántos de esos números son pares.
b) Cuál es el valor del número máximo
c) Cuál es el valor del número mínimo
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
	
	const int tam=10;
	int i, nmay=0,nmen=0,pares=0,par=0;
	int num[tam];
	
	printf("A continuacion pedire 10 numeros enteros, ingresalos");
	
	for (i=0; i<tam;i++){	
		printf("\nEscribe el numero:\n", i+1);
		scanf("\%d", &num[i]);
	}
	
	nmay=0;
	nmen=0;
	par=0;
	pares=0;
	for (i=0; i<tam;i++){
		par=num[i]%2;
		if (par==0)
		{pares=pares+1;}
		else if (nmen<num[i])
			{nmen=num[i];}	
		if(num[i]>nmay)
		{nmay=num[i];}	
	}
	
	/*printf("\nLos numeros ingresados son: ");
	for(i=0; i< num; i++)
	{
		printf("%d", num[i]);	
	}
	*/
	
	printf("\n El numero mayor del arreglo es: %d, el numero menor es %d y %d de numeros son pares", nmay,nmen, pares);
	
	
	
	
	
	
}