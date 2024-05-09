#include<stdio.h>

int main(){
	
	float N1=0 , N2=0, SUM=0, RES=0, MULT=0;
	
	printf("Inserta 2 numeros reales\n");
	scanf("%f", &N1);
	scanf("%f", &N2);
	
	SUM= (N1+N2);
	printf("El resultado de la suma de tus 2 numeros es: %.2f\n" , SUM);
	RES= (N1-N2);
	printf("El resultado de la resta de tus 2 numeros es: %.2f\n", RES);
	MULT= (N1*N2);
	printf("El resultado de la multiplicacion de tus 2 numeros es: %.2f", MULT);
	
	
}
