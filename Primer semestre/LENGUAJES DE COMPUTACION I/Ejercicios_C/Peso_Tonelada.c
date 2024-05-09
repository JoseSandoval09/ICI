#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL, "");
	
	int edad;
	printf("Ingresa tu edad (Solo numeros positivos)\n ");
	scanf("%d", &edad);
	
	if (edad<=10)
	{
		printf("NIÑO");
		
	}
	else if (edad<=65 && edad>10)
	{
		printf("Eres un adulto");
		
	}
	else if (edad>65)
	{
		printf("Jubilado");
	}
	else
	{
		printf("Edad invalida");
	}
	
}
