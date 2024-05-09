/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 5
Programa que pida el nombre de 2 personas, su edad e indicar cuál es el mayor de los 2.

*/

#include <stdio.h>
#include <stdlib.h>

int main (){
    int i,n=2,edad[n];
    char nombre[n][25];
    for(i=1;i<=n;i++){
        fflush(stdin);
        printf("Ingrese su nombre: ");
        gets(nombre[i]);
        printf("Introduzca su edad: ");
        scanf("%d", &edad[i]);
    }
    if (edad[1]<edad[2])
        printf("\n%s con %d es mayor que %s con la edad de %d\n", nombre[2],edad[2],nombre[1],edad[1]);
        else
        printf("\n%s con %d es mayor que %s con la edad de %d\n", nombre[1],edad[1],nombre[2],edad[2]);
    system("pause");
    return 0;
}