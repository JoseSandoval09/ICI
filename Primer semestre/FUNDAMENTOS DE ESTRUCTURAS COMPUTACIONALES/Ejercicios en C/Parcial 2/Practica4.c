/* PRACTICA 4
Jose Luis Sandoval Perez 1°A 
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int gradn;
	int fila,col;
	int matrz[fila][col];

	printf("Ingrese grado del grafo\n");
	scanf("%d", &gradn);
	
	for(col=0;col<gradn;col++){
		for(fila=0;fila<gradn;fila++){
			printf("Hay adyacencia entre vertice %d y vertice %d [1=SI,0=N0]\n",fila+1,col+1);
			scanf("%d", &matrz[col][fila]);
		}
	}
	
	for(col=0;col<gradn;col++){
		for(fila=0;fila<gradn;fila++){
			printf("%d ",matrz[col][fila]);
		}
		printf("\n");
	}
	
	
	
	
	
	
}