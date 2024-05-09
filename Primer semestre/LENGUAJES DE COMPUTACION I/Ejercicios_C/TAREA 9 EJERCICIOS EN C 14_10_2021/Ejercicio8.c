/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 8
Programa que solicite la edad de 10 personas y que muestre cuantos son mayores y cuantos son menores de edad.
*/

#include<stdio.h>

int main(){
	
	int edad[10],i,may=0,men=0;
	
	for (i=1;i<=10;i++){
		printf("Ingresa edad %d\n",i);
		scanf("%d", &edad[i]);
		if (edad[i]>=18)
			may++;
			else
			men++;
	}
	
	printf("De las edades de las 10 personas %d son mayores de edad\n", may);
	printf("%d edades restantes son menores de edad", men);

}
