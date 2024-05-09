#include<stdio.h>
#include<stdlib.h>

#define R 3
#define C 2

int enteros[R][C];
int r,c;


int main(){
	
	printf("Este programa contruye un arreglo\n");
	printf("Introduce valor que se solicitan\n");
	for(r=0; r<R ;r++){
		for(c=0; c<C ;c++){
			printf("Introduce el valor : [%d][%d] : \n",r,c);
			scanf("%d",&enteros[r][c]);
		}//fin for 
	}//fin for
	
	printf("El arreglo guardado es: \n");
	for(r=0; r<R ;r++){
		for(c=0; c<C ;c++){
			printf("\t%d", enteros[r][c]);
		}//fin for 
		printf("\n");
	}//fin for
	system("pause");
}

