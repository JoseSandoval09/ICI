/* Jose Luis Sandoval Perez 2A ICI

Realizar cualquier problema del capitulo 3 haciendo uso de structs

Ejercicio 3.7>>>>>Realizar un programa C que permita leer y escribir la informacion
de un empleado que contenga su nombre, direccion, codigo postal, salario neto y
fecha de nacimiento. */

#include<stdio.h>
#include<stdlib.h>

struct datos{

    char nombre[50];
    char direccion[100];
    char codigo[10];
    float salario;
    char fechanacimiento[100];
}

trabajadores[100];



int main(){

    
    int registro=0,i=0;

    printf("--REGISTRO NUEVO DE TRABAJADORES--\n");
    printf("Ingresa el numero de trabajadores a registrar: ");
    fflush(stdin);
    scanf("%d", &registro);
    printf("\nEstas a punto de hacer un registro de %d trabajadores\n", registro);
    printf("\nLa informacion que se te pedira sera; nombre,direccion,codigo postal, salario y fecha de nacimiento del trabajador\n");
    system("\npause");
    system("cls");
    
    

    for(i=1;i<=registro;i++){

        fflush(stdin);

        printf("Ingrese la informacion del trabajador %d", i);
        printf("\nNombre del trabajador: ");
        gets(trabajadores[i].nombre);
        printf("\nDireccion del trabajador: ");
        gets(trabajadores[i].direccion);
        printf("\nCodigo postal del trabajador: ");
        gets(trabajadores[i].codigo);
        printf("\nSalario del trabajador: ");
        scanf("%f",  &trabajadores[i].salario);
        printf("\nFecha de nacimientro del trabajador (dd/mm/aaaa): ");
        fflush(stdin);
        gets(trabajadores[i].fechanacimiento);
        
    }

    printf("Datos registrados con exitooo!!!");
    getchar();
    system("cls");

    int opcion=0;

    printf("\t--BIENVENIDO EL REGISTRO DE LOS TRABAJADORES YA ESTA CONFIGURADO--\n");

    printf("\t-------------------------------------------------------------------\n");
    printf(" NOMBRE\tDIRECCION\tCP\tSALARIO\tFECHA DE NACMIENTO\n");

            
    for(i=1;i<=registro;i++){
    printf(" %d.\t%s\t%s\t%s\t%.2f\t%s\n",i,trabajadores[i].nombre,trabajadores[i].direccion,trabajadores[i].codigo,trabajadores[i].salario,trabajadores[i].fechanacimiento);
    }

    printf("Gracias por hacer el registro. Hasta luego!!!!");
      
    
} 