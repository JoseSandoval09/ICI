/* Jose Luis Sandoval Perez 1°A ICI

Analisis:

Objetivo: Obtener el valor de la suma de 10 valores, sumandole 10 a cada uno, determinar cual de los 10 resultados de la suma es menor y en que posicion se encuentra.
Datos de entrada: 10 numeros dados por el usario(num)
Datos de salida: Resultado de cada numero más 10, numero menor de los resultados y posicion del numero menor.
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=10;
	int num[tam], resu[tam];
	int pos=0,men,i=1;
	
	printf("Pedire 10 numeros y le sumare 10 de forma individual\n");
	
	for(i=0;i<10;i++){
		printf("\nIngresa numero %d: ", i+1);
		scanf("%d", &num[i]);
		resu[i]=num[i] + 10;
		printf("\n\tNumero\t Suma\tResultado\n");
		printf("\n\t%d   +    %d\t%d\n",num[i],tam,resu[i]);
		
		if(i==0){
			men=resu[i];
			pos=pos+1;
		}
		else if(resu[i]<men){
			men=resu[i];
			pos=i+1;
		}
	}
	printf("\nEl numero menor despues de la suma es %d y su posicion es %d",men, pos);
	}
	
	
	
	