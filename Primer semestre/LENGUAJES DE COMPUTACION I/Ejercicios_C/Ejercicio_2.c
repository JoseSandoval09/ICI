#include<stdio.h>
#include<math.h>



int main() {
	
	int A=0, B=0;
	float Resul=0;
	
	printf("Dame 2 numeros\n");
	scanf("%d", &A);
	scanf("%d", &B);
	
	Resul= pow(A+B,2) / 2;
	
	printf("El resultado de la operacion es: %.2f ", Resul);
	

	
	
}

