/* Jose Luis Sandoval Perez 2A ICI

Realiza los siguientes programas:

1. Con una estructura de un empleado con nombre, edad y sueldo.
2. Con siete empleados. Maneja un arreglo de estructura.
3. Agrega a la estructura los sueldos diarios de lunes a sábado. Que el campo sueldo seas un vector de seis elementos.
4. Modifica el nombre para que sea una estructura que tenga nombre de pila, apellido paterno y apellido materno.
5. Programa libre que maneje uniones.

*/


#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>


struct InfoEmpleado1{
    char nomb[30];
    int edad;
    double sueldo;
}
Trabajador1;

struct InfoEmpleado2{
    char nomb[30];
    int edad;
    double sueldo;
}

Trabajadores1[6];

struct InfoEmpleado3{
    char nomb[30];
    int edad;
    double sueldo[5];
}

Trabajadores2[6];

struct InfoEmpleado4{
    char nomb[30];
    char apeP[30];
    char apeM[30];
    int edad;
    double sueldo[5];
}

Trabajadores3[6];




int main(){

    int op,i,j,total;

    printf("El siguiente programa simulara un registro de datos de trabajadores\n, habra diferentes opciones\n");
    printf("-------------------------------------\n");
    printf("\nMENU DE OPCIONES\n");
    printf("1.Mostrar en una estructura de un empleado nombre, edad y sueldo.\n");
    printf("2.Estructura con siente empleados,un arreglo de estructura. \n");
    printf("3.Estructura anterior + los sueldos diarios de lunes a sábado. Que el campo sueldo seas un vector de seis elementos.\n");
    printf("4.Modifica el nombre para que sea una estructura que tenga nombre de pila, apellido paterno y apellido materno.\n ");
    printf("*--SELECCIONA UNA OPCION--*\n");
    printf("\nOPCION: ");
    scanf("%d", &op);
    system("cls");
    printf("-------------------------------------------------------------------------------\n");


    switch(op){

           case 1:{

            printf("Decidiste la opcion 1 -> Estructura de un empleado con nombre edad y sueldo \n");
            printf("-------------------------------------------------------------------------------\n");
            printf("CAPTURA DE DATOS INICIADA\n");

            printf("Ingresa nombre de pila del empleado: \n");
            fflush(stdin);
            gets(Trabajador1.nomb);
            printf("Ingrese la edad del empleado(numero): \n");
            fflush(stdin);
            scanf("%d", &Trabajador1.edad);
            printf("Ingresa el sueldo del empleado: $ ");
            fflush(stdin);
            scanf("%lf", &Trabajador1.sueldo);

            printf("\t----------------DATOS CORRECTAMENTE GUARDADOS----------------\n");

            

            printf("\tNOMBRE\tEDAD\tSUELDO\n");
            printf("\t%s\t%d\t%.2lf", Trabajador1.nomb,Trabajador1.edad,Trabajador1.sueldo);

            
            break;


        } 
        case 2:{

            

            printf("Decidiste la opcion 2 -> Estructura con siente empleados,un arreglo de estructura.\n");
            printf("-------------------------------------------------------------------------------\n");
            printf("CAPTURA DE DATOS INICIADA\n");

            for(i=0;i<=6;i++){

                printf("\nIngresa nombre de pila del empleado %d: ", i+1);
                fflush(stdin);
                gets(Trabajadores1[i].nomb);
                printf("\nIngrese la edad del empleado(numero): ");
                fflush(stdin);
                scanf("%d", &Trabajadores1[i].edad);
                printf("\nIngresa sueldo del trabajador:$ ");
                scanf("%lf", &Trabajadores1[i].sueldo);
            }

            printf("\n\t----------------DATOS CORRECTAMENTE GUARDADOS----------------\n");
        
            

            printf(" \tNOMBRE\tEDAD\tSUELDO\n");

            for(i=0;i<=6;i++){

                printf("%d \t%s\t%d\t$%.2lf\n",i+1,Trabajadores1[i].nomb,Trabajadores1[i].edad,Trabajadores1[i].sueldo);

            }

            break;

        }
        case 3:{

            printf("Decidiste la opcion 3 -> Estructura anterior + los sueldos diarios de lunes a sabado. Que el campo sueldo seas un vector de seis elementos.\n");
            printf("-------------------------------------------------------------------------------\n");
            printf("CAPTURA DE DATOS INICIADA\n");

            for(i=0;i<=6;i++){

                printf("\nIngresa nombre de pila del empleado %d: ", i+1);
                fflush(stdin);
                gets(Trabajadores2[i].nomb);
                printf("\nIngrese la edad del empleado(numero): ");
                fflush(stdin);
                scanf("%d", &Trabajadores2[i].edad);

                for(j=0;j<=5;j++){
                    printf("\nIngresa sueldo del trabajador %d del dia %d (Lun-Sabado):$ ", i+1,j+1);
                 scanf("%lf", &Trabajadores2[i].sueldo[j]);
                }

                printf("-----------------------------------------------------------------");

                printf("\nEMPLEADO %d REGISTRADO CORRECTAMENTE\n", i+1);
                system("pause");
                system("cls");
                

                
            }

            printf("\n\t----------------DATOS CORRECTAMENTE GUARDADOS----------------\n");
        
            

            

            for(i=0;i<=6;i++){

                printf("\n\tNOMBRE\tEDAD\n");


                printf("\n%d.  \t%s\t%d\n",i+1,Trabajadores2[i].nomb,Trabajadores2[i].edad);

                for(j=0;j<=5;j++){
                    printf("\nSueldo dia %d: $ ", j+1);
                    printf("%.2lf", Trabajadores2[i].sueldo[j]);
                }

                printf("\n-----------------------------------------------------------------");



                break;

            }

        }
        case 4:{


            printf("Decidiste la opcion 4 -> Modifica el nombre para que sea una estructura que tenga nombre de pila, apellido paterno y apellido materno.\n");
            printf("-------------------------------------------------------------------------------\n");
            printf("CAPTURA DE DATOS INICIADA\n");

            for(i=0;i<=6;i++){

                printf("\nIngresa nombre de pila del empleado %d: ", i+1);
                fflush(stdin);
                gets(Trabajadores3[i].nomb);

                printf("\nIngresa apellido paterno %d: ", i+1);
                fflush(stdin);
                gets(Trabajadores3[i].apeP);

                printf("\nIngresa apellido materno %d: ", i+1);
                fflush(stdin);
                gets(Trabajadores3[i].apeM);

                printf("\nIngrese la edad del empleado(numero): ");
                fflush(stdin);
                scanf("%d", &Trabajadores3[i].edad);

                for(j=0;j<=6;j++){
                    printf("\nIngresa sueldo del trabajador %d del dia %d (Lun-Sabado):$ ", i+1,j+1);
                 scanf("%lf", &Trabajadores3[i].sueldo[j]);
                }

                printf("-----------------------------------------------------------------");

                printf("\nEMPLEADO %d REGISTRADO CORRECTAMENTE\n", i+1);
                system("pause");
                system("cls");
                

                
            }

            printf("\n\t----------------DATOS CORRECTAMENTE GUARDADOS----------------\n");
        
            

            

            for(i=0;i<=6;i++){

                printf("\n\tNOMBRE\tAPELLIDO PATERNO\tAPELLIDO MATERNO\tEDAD\n");


                printf("\n%d.  \t%s\t%s\t\t%s\t\t\t%d\n",i+1,Trabajadores3[i].nomb,Trabajadores3[i].apeP,Trabajadores3[i].apeM,Trabajadores3[i].edad);

                for(j=0;j<=5;j++){
                    printf("\nSueldo dia %d: $ ", j+1);
                    printf("%.2lf", Trabajadores3[i].sueldo[j]);
                }

                printf("\n-----------------------------------------------------------------\n");



                

            }
            break;


        }


    }




}
