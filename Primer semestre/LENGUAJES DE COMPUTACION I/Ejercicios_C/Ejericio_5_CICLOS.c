/*
	Jose Luis Sandoval Perez
	ICI 1°A
	Realizar el programa que muestre 4 opciones: 1. Matemáticas, 2. Español, 3. Historia, 
	4. Salir y al dar el número indicado, solo imprima la materia que corresponde a la opción deseada. Si da
	una opción incorrecta que marque error. Este menú se repetirá hasta que se de la opción 4 de Salir y 
	entonces se terminará el programa

*/	

#include<stdio.h>
#include<locale.h>


int main (){
	
	setlocale(LC_ALL,"spanish");
	
	int opcion;
	printf("OPCION 1. MATEMATICAS\n");
	printf("OPCION 2. ESPAÑOL\n");
	printf("OPCION 3. HISTORIA\n");
	printf("OPCION 4. SALIDA\n");
	printf("ELIGE TU OPCION\n");
	scanf("%d", &opcion);

	switch(opcion)
	{
				case 1:
					printf("MATEMATICAS");
					break;
				case 2:
					printf("ESPAÑOL");
					break;
				case 3:
					printf("MATEMATICAS");
					break;
				case 4:
					printf("SALIR");
					break;
				default:
					printf("OPCION INVALIDA");
	}
}

	


