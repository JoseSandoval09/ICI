#include<stdio.h>


int main(){

char op;

	printf("A. ALTAS \n");
	printf("B. BAJAS \n");
	printf("C. MODIFICAR \n");
	printf("D. SALIR \n");
	scanf("%c", &op);
	
	switch(op)
	{
		case 'A':
		printf("Opcion Altas");
		break;
		
		case 'B':
		printf("Opcion Bajas");
		break;
		
		case 'C':
		printf("Opcion Modificiar");
		break;
		
		case 'D':
		printf("Opcion Salir");
		break;
		
		case 'a':
		printf("Opcion 1");
		break;
		
		case 'b':
		printf("Opcion 2");
		break;
		
		case 'c':
		printf("Opcion 3");
		break;
		
		case 'd':
		printf("Opcion 4");
		break;
		
		default:
			printf("Opcion invalida");
			break;	
		
	}





}
