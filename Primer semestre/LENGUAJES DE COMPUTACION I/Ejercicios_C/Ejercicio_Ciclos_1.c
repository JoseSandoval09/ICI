#include<stdio.h>

int main()
{
	
	int num,pares=0;
	
	for(num=2;num<=100;num+=2){
		printf("\n%d +  %d  ", pares,num);
		pares=pares+num;
		printf("= %d", pares);
	}
	printf("\nLa suma de los numeros pares es: %d", pares);	
	
	
	
	
}