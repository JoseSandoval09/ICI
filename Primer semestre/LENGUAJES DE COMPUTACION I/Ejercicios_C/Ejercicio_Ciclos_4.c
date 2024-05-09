/*
	Jose Luis Sandoval Perez
	ICI 1°A
	Realizar el programa  que al realizar el pago de una compra, indique “Gracias por su 
compra”, si el pago es exacto. Si la cantidad pagada es mayor al precio, indicar cuánto es el cambio que 
se le devolverá al cliente y si el pago es menor al precio, indicarle que le falta dinero y cuánto le falta.

*/	

#include<stdio.h>

int main(){

    float pag=0, prec=0, camb=0, rest=0;

    printf("Ingrese el precio del articulo\n");
    scanf("%f", &prec);
    printf("Ingresa la cantidad a pagar\n");
    scanf("%f", &pag);
    
    while(1)
    if (pag==prec){
    printf("Tu pago es exacto, gracias");
    	break;
        }else if(pag>prec){
        camb=pag-prec;
        printf("\nTu cambio es  $ %.2f", camb);
        break;
		}
            else{
            rest= prec-pag;
            printf("\nEl pago es menor, la cantidad restante por pagar es: $%.2f", rest);
            break;
		}
}