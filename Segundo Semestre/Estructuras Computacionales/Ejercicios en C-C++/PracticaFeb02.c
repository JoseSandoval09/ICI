//Jose Luis Sandoval Perez 2A ICI

#include<stdio.h>
#include<stdlib.h>

struct datos{

    char nombre[50];
    char direccion[100];
    char codigo[10];
    float salario[6];
    char fechanacimiento[100];
}

trabajadores[100];



int main(){

    
    int registro=0,i=0,j=0,totalS=0;

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
        fflush(stdin);
        gets(trabajadores[i].nombre);
        printf("\nDireccion del trabajador: ");
        fflush(stdin);
        gets(trabajadores[i].direccion);
        printf("\nCodigo postal del trabajador: ");
        fflush(stdin);
        gets(trabajadores[i].codigo);
        printf("\nFecha de nacimientro del trabajador (dd/mm/aaaa): ");
        fflush(stdin);
        gets(trabajadores[i].fechanacimiento);

        printf("Ahora ingresa el sueldo del trabajador por dia\n");
        for(j=0;j<=5;j++){
            fflush(stdin);
            printf("Ingresa sueldo del dia %d : \n", j+1);
            scanf("%d", trabajadores[i].salario[j]);
            fflush(stdin);
            totalS=trabajadores[i].salario[j]+trabajadores[i].salario[j];
           
            



        }
        
        
    }

    printf("Datos registrados con exitooo!!!");
    getchar();
    //system("cls");

    int opcion=0;

    printf("\t--BIENVENIDO EL REGISTRO DE LOS TRABAJADORES YA ESTA CONFIGURADO--\n");

    printf("\t-------------------------------------------------------------------\n");
    printf(" NOMBRE\tDIRECCION\tCP\tSALARIO\tFECHA DE NACMIENTO\n");

            
    for(i=1;i<=registro;i++){
    printf(" %d.\t%s\t%s\t%s\t%.2f\t%s\n",i,trabajadores[i].nombre,trabajadores[i].direccion,totalS,trabajadores[i].fechanacimiento);
    }

    printf("Gracias por hacer el registro. Hasta luego!!!!");
      
    
} 