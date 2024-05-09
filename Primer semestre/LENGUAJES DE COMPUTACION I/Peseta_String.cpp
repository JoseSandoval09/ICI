#include<stdio.h>

#define EURO 166.386
#define TEXTO "Esto es una prueba"
const int PESETA=1;

main()
{
	printf ("El valor del euro es %f pesetas", EURO);
	printf("\nEl valor de la peseta es %d peseta", PESETA);
	printf("\n%s", TEXTO);
	printf("");
}
