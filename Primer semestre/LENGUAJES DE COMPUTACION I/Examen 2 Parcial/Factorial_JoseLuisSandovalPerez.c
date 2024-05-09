/* Jose Luis Sandoval Perez 1°A ICI

Analisis:

Objetivo: Programa en c que muestre el factorial de un número dado.
Datos de entrada: Numero dado por el usuario (n)
Datos de salida: Factorial del numero.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL, "");
	
	double n=0,i=1;
	double fact=1;
	const  int op1=1, op2=2, op3=3;
	int opc=0;
	int inicio=0;
	
	printf("¡Este programa calcula el factorial de un numero!\n");
	printf("Bienvenido usuario!\n");
	
	
	while(opc!=3){
		printf("\n¿Con que ciclo desea obtener su factorial?\n");
		printf("1 - Do while\n");
		printf("2 - For\n");
		printf("3 - Salir\n");
		printf("\n");
		printf("Ingresa tu opcion: ");
		scanf("%d", &opc);	
		
		switch(opc){
			case 1:{
				printf("\nIngresa un numero y te dire su factorial\n");
				scanf("%lf", &n);
				while(i<=n){
				fact=fact*i;
				printf(" %.0lf x ",i);
				i++;
				}
				printf("\nEl resultado del factorial es: %.0lf \n", fact);
				break;
			}
			case 2:{
				printf("\nIngresa un numero y te dire su factorial\n");
				scanf("%lf", &n);
				for(i=1;i<=n;i++){
				fact=fact*i;
				printf(" %.0lf x ",i);
				}
				printf("\nEl resultado del factorial es: %.0lf\n", fact);
				break;
			}
			case 3:{
				printf("Decidiste salir del programa,hasta la proxima usuario!\nFue un gusto verte!");
				break;
			}
	}
	}
}
	