/* Jose Luis Sandoval Perez ICI 1°A
Practica 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"spanish");

    int n1,n2,n3,n,peso,suma,cont=0,cont2;

    printf("El siguiente programa nos permitirá visualizar y contar todas las cadenas de longitud igual a 3 que \nse pueden construir con un alfabeto de k simbolos así como su peso\n ");
    printf("Ingresa el tamañ|o del alfabeto: ");
    scanf("%d", &n);
    printf("\nIngresa el peso a contar: ");
    scanf("%d", &peso);

    printf("\nCadena\tPeso\n");
    for (n1=0;n1<n;n1++)
        for(n2=0;n2<n;n2++)
            for(n3=0;n3<n;n3++)
            {
                suma=n1+n2+n3;
                printf("%d,%d,%d\t%d\n",n1,n2,n3,suma);
                    if(suma==peso){
                        cont++;
                    }
                    cont2++;
            }
    printf("\n\nEl numero de cadenas con peso igual a %d de las %d combinaciones posibles es: %d\n", peso,cont2,cont);
system("pause");
return 0;
}


	
	
	
	
