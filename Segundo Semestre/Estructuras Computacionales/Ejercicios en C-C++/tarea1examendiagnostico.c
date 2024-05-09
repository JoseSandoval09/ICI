/* Jose Luis Sandoval Perez 2°A ICI
Examen diagnostico*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n=0,i=0,rep=0,x=0,j=0;
	srand(time(NULL));

	
	printf("Este programa creara un arreglo de numero aleatorios del 1-10 \n Cuantos numeros quieres que tenga el arreglo: ");
	scanf("%d", &n);
	int aleatorios[n];
	
	for(i=0;i<n;i++){
		
		aleatorios[i]= rand()% 11;
		printf("El numero aleatorio en la posicion %d es: %d\n", i,aleatorios[i]);	
	}
	
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			if(aleatorios[i]==aleatorios[j] && x!=aleatorios[i])
			{
				rep++;
				x=aleatorios[i];
				printf("Encontre el numero %d, %d veces dentro del arreglo\n", x, rep);
			}
			
		}
	}
}
		
	

	
