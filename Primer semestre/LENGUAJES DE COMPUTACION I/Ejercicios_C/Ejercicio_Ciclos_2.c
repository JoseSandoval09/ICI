/* Jose luis Sandoval Perez
	ICI 1°A 
	Programa que obtenga la suma de los números pares e impares del 100 al 400.
*/

#include<stdio.h>

int main(){
	
	int  num,sumap=0,sumaimp=0;
    for(num=100;num<=400;num++){
       if (num%2==0){
       	sumap=sumap+num;
	   } 
	   else {
	   	sumaimp=sumaimp+num;
	   }
}
	printf("\nLa suma de los pares es: %d",sumap);
	printf("\nLa suma de los impares es: %d", sumaimp);      
	
	
}
	