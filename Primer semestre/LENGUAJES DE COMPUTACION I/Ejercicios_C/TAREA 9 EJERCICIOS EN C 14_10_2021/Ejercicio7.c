/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 7
Programa que pida un número arábigo entre 1 y 10 (dato entero) y que muestre por pantalla el número correspondiente en romano.
*/


#include<stdio.h>

int main(){
	
	int num=0;

printf("Introduce un numero del 1 al 10 y mostrare en pantalla el numero correspondiente en romano\n");
	scanf("%d", &num);
	
	switch (num){

		case 1:{
			printf("Numero en romano es: I " );
			break;
		}	
		case 2:{
			printf("Numero en romano es: II ");
			break;
		}	
		case 3:{
			printf("Numero en romano es: III ");
			break;
		}
		case 4:{
			printf("Numero en romano es: IV ");
			break;
		}	
		case 5:{
			printf("Numero en romano es:  V  ");
			break;
		}
		case 6:{
			printf("Numero en romano es:  VI  ");
			break;
		}
		case 7:{
			printf("Numero en romano es:  VII  ");
			break;
		}
		case 8:{
			printf("Numero en romano es: VIII ");
			break;
		}
		case 9:{
			printf("Numero en romano es:  IX  ");
			break;
		}
		case 10:{
			printf("Numero en romano es:  X  ");
			break;
		}
		default:{
			printf("ERROR NUMERO INCORRECTO");
			break;
		}
	}
}