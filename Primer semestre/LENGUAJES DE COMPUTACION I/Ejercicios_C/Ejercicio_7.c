#include<stdio.h>

int main(){
	
	float pag=0, prec=0, camb=0;
	
	printf("Ingrese el precio del articulo\n");
	scanf("%f", &prec);
	printf("Ingresa la cantidad a pagar\n");
	scanf("%f", &pag);
	
	if (pag==prec)
	printf("NO TE SOBRA CAMBIO");
		else if(pag>prec){
		
		camb=pag-prec;
		printf("Tu cambio es  $ %.2f", camb);}		
			else
			printf("El pago es menor, ingresa cantidad restante");
}
