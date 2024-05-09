#include<stdio.h>

int main(){
	
	float base=0, altura=0, supe=0, peri=0;
	
	printf("Ingresa la base de tu rectangulo\n");
	scanf("%f", &base);
	printf("Ingresa la altura de tu rectangulo\n");
	scanf("%f", &altura);
	
	supe= base + altura;
	
	printf("La superficie de tu rectangulo es: %.2f\n", supe);
	
	peri= 2*(base+altura);
	
	printf("El perimetro de tu rectangulo es: %.2f", peri); 
	
	
	
	
	
}
