//Jose Luis Sandoval Perez ICI 1°A 
//Multiplicacion de matrices con numeros aleatorios

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){



int i=0,k=0,colu=0,n=0,dato=0;
	
	
	printf("A continuacion imprimire 2 matrices nxn  y las multiplicare");
	printf("\nPara eso te pedire el valor de n");
			
	printf("\nIngresa valor de la matriz nxn: ");
	scanf("%d", &n);
		
			
	int matriz1[n][n];
	int matriz2[n][n];
	int matrizmulti[n][n];
	
	srand(time(NULL)); 
	 
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		dato=1+rand()%(10);
		matriz1[i][k]=dato;
		}	
	}
	
	printf("MATRIZ 1\n");
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			printf("%d\t", matriz1[i][k]);
		}
		printf("\n");	
	}
	
	printf("\n");
	printf("MATRIZ 2\n");
	
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		dato=1+rand()%(10);
		matriz2[i][k]=dato;
		}	
	}
	
	printf("La matriz 2 es: \n");
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			printf("%d\t", matriz2[i][k]);
		}
		printf("\n");	
	}
	
	printf("\n");
	
	printf("La multiplicacion de las matrices es: \n");

	
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
			matrizmulti[i][k]=matriz1[i][k]*matriz2[i][k];
			printf("%d\t", matrizmulti[i][k]);
		}
		printf("\n");
	}
	
	system("pause");
	
}