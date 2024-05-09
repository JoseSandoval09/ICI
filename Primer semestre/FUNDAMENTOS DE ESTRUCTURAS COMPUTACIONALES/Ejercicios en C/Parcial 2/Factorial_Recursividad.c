//Calcula el factorial recursivo

//Directivas al computador
#include<stdio.h>
#include<stdlib.h>

//Declaracion de funciones

double fact(int n);
int n;

//Programa main 
int main(){
	printf("Calcula el factorial de un numero\n");
	printf("Introduce el valor al cual sacaras factorial: ");
	scanf("%d", &n);
	//llamado a la funcion
	printf("El factorial de %d es: %.2lf\n", n, fact(n));
	system("pause");
	
}


//Cuerpo de la funcion
double fact(int n){
	if(n<=2)
		return n;
	else
		return n*fact(n-1);
}