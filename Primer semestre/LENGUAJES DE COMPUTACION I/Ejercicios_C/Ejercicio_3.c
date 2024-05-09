#include<stdio.h>
#include<stdlib.h>




int main(){
	
	int MAT=0;
	float CAL1=0, CAL2=0, CAL3=0, CAL4=0, CAL5=0;
	
	printf("Inserta tu matricula\n");
	scanf("%d", &MAT);
	printf("Tu matricula: %d\n", MAT);
	printf("Inserta tus 5 calificaciones\n");
	scanf("%f", &CAL1);
	scanf("%f", &CAL2);
	scanf("%f", &CAL3);
	scanf("%f", &CAL4);
	scanf("%f", &CAL5);
	
	float PROM=0;
	
	PROM = (CAL1+CAL2+CAL3+CAL4+CAL5)/(5);
	
	printf("Tu matricula es %d\n", MAT);
	printf("El promedio de tus califiaciones es: %f ", PROM);
	
	
	
		 
	
	
}
