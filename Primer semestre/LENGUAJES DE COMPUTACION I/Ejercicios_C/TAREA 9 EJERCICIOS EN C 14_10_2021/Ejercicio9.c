/* Jose Luis Sandoval Perez ICI 1°A

EJERCICIO 9
9.	Programa que lea el password de un usuario y si el password es igual a “12345” desplegar 
“Password correcto” y terminar el programa. 
Si el password es diferente desplegar “Password incorrecto” y seguir pidiendo el password. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
    int password=12345,passwordi=0;
    printf("Introduce el password de 5 digitos\n");
    scanf("%d",&passwordi);
    while (passwordi!=password){
        printf("\nContraseña incorrecta, vuelva a intentar: ");
        scanf("%d",&passwordi);
    }
    printf("Contraseña correcta\n");
    return 0;
}

	      
	
			