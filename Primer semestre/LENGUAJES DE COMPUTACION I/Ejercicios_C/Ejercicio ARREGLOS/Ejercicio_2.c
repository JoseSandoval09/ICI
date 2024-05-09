//Jose Luis Sandoval Perez 1°A ICI
//Escribir un programa que lea 10 número por teclado. 
//Luego lea dos más e indique si éstos están 
//entre los anteriores e indicar en qué posición se encuentran.


#include<stdio.h>
#include<stdlib.h>

int main(){
	
	const int tam=10;
	int num[tam];
	int n1=0,n2=0,i=0, pos1=0,pos2=0,n1si=0,n2si=0;
	
	
	printf("Te pedire 10 numeros ingresalos por favor");
	
	for(i=0;i<=9;i++){
		printf("\n Ingresa el numero %d: ", i+1);
		scanf("%d",&num[i]);
	}
	
	printf("Ingresa 2 numeros extras: \n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	
	for(i=0;i<=9;i++){
		if(num[i]==n1)
		{
			n1si=1;
			pos1=pos1+1;
			printf("El primer numero extra ingresado (%d) es parte de los 10 principales y esta en la posicion. %d\n", n1, i+1, pos1);
		}
		else if(num[i]==n2){
			n2si=1;
			pos2=i+1;
			printf("El segundo numero extra ingresado (%d) es parte de los 10 principales y esta en la posicion. %d\n", n2, i+1, pos2);
		}
	}
	if(n1si==1 && n2si==1){
		printf("Los 2 numeros extra (%d,%d) perteneces a los 10 principales.", n1,n2);}
		else if (n1si==1 && n2si==0){
			printf("El numero extra (%d) si pertence a los 10 principales, pero el extra 2 (%d) no lo hace.\n", n1,n2);}
				else if (n1si==0 && n2si==1){
					printf("El numero extra (%d) no pertence a los 10 principales, pero el extra 2 (%d) si lo hace.\n", n1,n2);}
					else if (n1si==0 && n2si==0){
					printf("Ninguno de los numeros extras pertenece a los 10 principales.");
				}		
}