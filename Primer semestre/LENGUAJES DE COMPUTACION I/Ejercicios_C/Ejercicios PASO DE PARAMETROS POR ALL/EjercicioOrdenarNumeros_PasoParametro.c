/* JOSE LUIS SANDOVAL PEREZ 
ICI 1°A
EJERCICIOS PASO DE PARAMETRO POR REFERENCIA */



#include<stdio.h>
#include<stdio.h>


void numeros(int n[]);
void orden(int n[],int menor, int mayor);

int main(){
	
	const int tamNum=5;
	int a,n[tamNum],mayor,menor;
	
	printf("Este programa pedira 5 numeros y dira cual es el menor asi como dira cual es el mayor\n");
	printf("A continucion ingresa 5 numeros");
	
	numeros(n); //FUNCION QUE CREA EL ARREGLO DE 5 NUMEROS
	
	printf("Tus numeros son\n");
	
	for(a=0;a<5;a++){ //IMPRESION DE NUMEROS INGRESADOS EN LA FUNCION.
		printf("\nNumero %d: %d", a+1 ,n[a]);
	}
	mayor=0;
	
	orden(n,menor,mayor); //FUNCION QUE OBTIENE EL NUMERO MAYOR Y MENOR DEL ARREGLO
	
	
}

void numeros(int n[]){
	
	int a=0;
	
	
	for(a=0;a<5;a++){
		printf("\nIngresa numero %d: ", a+1);
		scanf("%d", &n[a]);
	}
	
	
}
void orden(int n[],int menor,int mayor){
	
	int a=0;
	
	for(a=0;a<5;a++){ 
		if(n[a]>mayor){
			mayor=n[a];	
		}
	}
	printf("\nEl numero mayor de los numeros ingresados es: %d", mayor);
	menor=mayor;
	for(a=0;a<5;a++){ 
		if(n[a]<menor){
			menor=n[a];	
		}
	}
	printf("\nEl numero menor de los numeros ingresados es: %d", menor);
	
}