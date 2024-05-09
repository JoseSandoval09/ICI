//Jose Luis Sandoval Perez 1°A
//Leer un vector de 10 elementos enteros y ordenarlo de mayor a menor.


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=10;
	int num[tam];
	int aux=0, i=0,j=0;
	
	printf("Ingresaras 10 numeros enteros y los ordenare de menor a mayor\n");
	for(i=1;i<=10;i++){
		printf("Inserte el numero %d: " ,i);
		scanf("%d", &num[i]);
	}
	for(i=1;i<=10;i++){
		for(j=1;j<=10;j++){
			if(num[j] < num[j+1]){
				aux=num[j+1];
				num[j+1]= num[j];
				num[j]=aux;
			}
		}	
	}
	
	printf("Los numeros ordenados son: ");
	for(i=1;i<=10;i++){
		printf("\n%d", num[i+1]);
	}
	printf("\n");
}