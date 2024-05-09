//Jose Luis Sandoval Perez 1°A ICI
//Tombola con numero ganador

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
	
	int juga=0,i=0;
	
	printf("Cuantos jugadores jugaran en esta ronda: ");
	scanf("%d", &juga);
	
	srand(time(NULL)); 
	
	printf("El ganador de la tombola es el numero %d ",rand()%juga);
}
	
	
	
	
	
