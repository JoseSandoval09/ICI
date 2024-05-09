/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 6
Programa que pida el número (dato entero) de un mes del año y que muestre por pantalla el nombre correspondiente a dicho mes.
*/


#include<stdio.h>

int main(){
	
	int mes=0;
	
	printf("Introduce un numero del 1 al 12 y te dire ese numero a que mes corresponde\n");
	scanf("%d", &mes);
	
	switch (mes){

		case 1:{
			printf("1-ENERO");
			break;
		}	
		case 2:{
			printf("2-FEBRERO");
			break;
		}	
		case 3:{
			printf("3-MARZO");
			break;
		}
		case 4:{
			printf("4-ABRIL");
			break;
		}	
		case 5:{
			printf("5-MAYO");
			break;
		}
		case 6:{
			printf("6-JUNIO");
			break;
		}
		case 7:{
			printf("7-JULIO");
			break;
		}
		case 8:{
			printf("8-AGOSTO");
			break;
		}
		case 9:{
			printf("9-SEPTIEMBRE");
			break;
		}
		case 10:{
			printf("10-OCTUBRE");
			break;
		}
		case 11:{
			printf("11-NOVIEMBRE");
			break;
		}
		case 12:{
			printf("12-DICIEMBRE");
			break;
		}
		default:{
			printf("ERROR MES INCORRECTO");
			break;
		}
	}
}