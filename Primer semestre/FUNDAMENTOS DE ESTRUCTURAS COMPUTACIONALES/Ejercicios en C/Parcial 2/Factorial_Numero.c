#include<stdio.h>

int main(){
	
	double n, i;
	double fact=1;
	
	printf("Ingresa un numero para sacar su factorial\n");
	scanf("%lf", &n);
	
	for (i=1;i<=n; i++){
		fact=fact*i;
	}
	fflush(stdin);
	printf("El resultado del factorial es: %.0lf ",fact);
	
	
	
}

	

	

	
	
	
	
	
	

