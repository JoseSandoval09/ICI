// Jose Luis Sandoval Perez 1°A ICI
/* Programa pida 10 números enteros por teclado y que imprima por pantalla:
a) Cuántos de esos números son pares.
b) Cuál es el valor del número máximo
c) Cuál es el valor del número mínimo
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int i=0, nmay=0,nmen=0,pares=0;
	const int tam=10;
	int num[tam];
	
	printf("A continuacion pedire 10 numeros enteros, ingresalos por favor\n");
	
	for(i=1;i<=10;i++)
	{
    	printf("Ingresa el numero %d \n",i);
    	scanf("%d",&num[i]);
    	if (i==0){
    		nmay=num[0];
			nmen=num[0];
    	}else{
    		if (num[i]>nmay){
    			nmay=num[i];
    		}
    		if (num[i]<nmen){
    			nmen=num[i];
    		}
    	}
    	if (num[i]%2==0){
    		pares++;
    	}
    }
	
	printf("Hay %d numeros pares, el valor maximo es: %d y el minimo es: %d", pares,nmay,nmen);
	return 0;
}