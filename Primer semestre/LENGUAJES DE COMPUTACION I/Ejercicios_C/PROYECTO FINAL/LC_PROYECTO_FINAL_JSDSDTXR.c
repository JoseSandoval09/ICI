#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
PROYECTO FINAL LENGUAJES DE COMPUTACION
Ximena Rivera Delgadillo ID:261261
Jose Luis Sandoval Perez ID: 261731
Diego Emanuel Saucedo Ortega ID:261230
Carlos Daniel Torres Macias ID:244543
*/

//Constantes
 //definimos las contantes para delimitar el tamaño de nuestros arreglos
#define NOMBRES_C 9
#define APELLIDOS_C 9
#define SALARIO_MIN 102.0f
#define MAX_SS 1000000
int NT=10;

//Arreglos del trabajador
int claves_W[25]; //claves de trabajadores
char nombre_W[25][33]; //nombre de trabajadores
double salario_W[25]; //salario de trabajadores


//explicacion de la funcion del programa
void funcion();
//opciones para cambiar de tema
void cambiarTemaConsola();

//F U N C I O N E S opciones

    void menu();//menu de opciones
//OP:1 agenda de trabajadores
    void agenda();
//OP:2
    int buscarClave();
    int buscarNombre();
//OP:3
    void ordenarClave();
    void ordenarNombre();
    void ordenarSalario();
//OP:4 insertar nuevos registros
    void insertar();
//OP:5 eliminar registros
    void eliminarClave();
    void eliminarNombre();
//OP:6 Modificar registros
    void modificarClave();
    void modificarNombre();
    void modificarSalario();

//Para llenar los registros
void generaClaves(int claves[]);
void generaNombres(char nombres[][33]);
void generaSalarios(double salarios[]);



//Nombres y Apellidos para llenar registros
    char NOMBRES[NOMBRES_C][10]={
    "Kobe","Michael","Damian",
    "Paul","Emanuel","Devin",
    "Bam","Jalen","Shaq"};

    char APELLIDOS[APELLIDOS_C][10]={
    "O'Neil","Suggs","Adebayo",
    "Booker","Ginobili","Gasol",
    "Lillard","Jordan","Bryant"};

//FUNCION PRINCIPAL
int main(){

        srand(time(NULL));

        funcion(); //Funcion del programa
        cambiarTemaConsola(); //tema consola

        int op=0;//variable de selección

        generaClaves(claves_W);//Generamos las claves de los trabajadores
        generaNombres(nombre_W);//Generamos los nombres de los trabajadores
        generaSalarios(salario_W);//Generamos los nombres de los trabajadores

        printf("B I E N V E N I D O...\n");
	  printf("------------------------------------------\n");
        system("pause");
        system("cls");

        do{
        menu();//Funcion para mostrar Menú de opciones
        printf("Seleccione una opcion\n");
        fflush(stdin);
        scanf("%d",&op);
        printf("---------------------------------------------------------\n");
        system("pause");
        system("cls");

        if(op==1){agenda();}//imprimir lista de trabajadores

        if(op==2){ //buscar un trabajador
            int ot=-1,a;
            printf("\t\tB U S C A R \n");
            printf("Por que medio desea buscar el registro...\n");
            printf("1.Buscar por clave\n");
            printf("2.Buscar por nombre\n");
            printf("----------------------------------------------\n");
            printf("Seleccione una opcion\n");
            scanf("%d",&ot);
            printf("----------------------------------------------\n");
            system("pause");
            system("cls");
            if(ot!=1 && ot!=2){printf("Error 404: Not Found.\n");printf("------------------------------------------\n");system("pause");system("cls");continue;}
            if(ot==1){a=buscarClave();}
            if(ot==2){a=buscarNombre();}

            if(a<0){printf("Error 404: Not Found.\n"); printf("------------------------------------------\n");system("pause"); system("cls");continue;}
            else{
                printf("clave           n o m b r e         \t\tsalario\n");
		    printf("%04d\t%s\t\t\t%.2lf\n",claves_W[a],nombre_W[a],salario_W[a]);
		    printf("----------------------------------------------------------\n");
		
            }
        }

        if(op==3){ //Ordenar empleados
            int ot;
                printf("\t\tO R D E N A R \n");
                printf("De que forma desea ordenar el registro...\n");
		    printf("1.Ordenar por clave\n");
		    printf("2.Ordenar por nombre\n");
		    printf("3.Ordenar por salario\n");
		    printf("-------------------------------------------\n");
		    printf("Seleccione una opcion\n");
		    scanf("%d",&ot);
		    printf("--------------------------------------------\n");
                system("pause");
                system("cls");
		    if(ot==1){ordenarClave();}
		    if(ot==2){ordenarNombre();}
		    if(ot==3){ordenarSalario();}
		    if(ot!=3 && ot!=1 && ot!=2){printf("Error 404: Not Found.\n");printf("------------------------------------------\n");system("pause");system("cls");continue;}
        }

        if(op==4){insertar();}//Insertar un registro

        if(op==5){
            int ol=0;
                printf("\t\tE L I M I N A R\n");
                printf("Por que medio desea eliminar el registro...\n");
                printf("1) Clave del trabajador\n");
                printf("2) Nombre del trabajador\n");
                printf("----------------------------------------------\n");
                printf("Seleccione una opcion\n");
                scanf("%d",&ol);
                printf("-----------------------------------------------\n");
                system("pause");
                system("cls");
                    if(ol!=1 && ol!=2){printf("Error 404: Not Found.\n");printf("------------------------------------------\n");system("pause");system("cls");continue;}
                    if(ol==1){eliminarClave();}
                    if(ol==2){eliminarNombre();}

        }

        if(op==6){ //modificar registros
            int ol=0;
            printf("\t\tM O D I F I C A R\n");
            printf("Que desea  modificar del registro...\n");
            printf("1) Clave del trabajador\n");
            printf("2) Nombre del trabajador\n");
            printf("3) Salario del trabajador\n");
            printf("------------------------------------------\n");
            printf("Seleccione una opcion\n");
            scanf("%d",&ol);
            printf("-------------------------------------------\n");
            system("pause");
            system("cls");

                if(ol==1){modificarClave();}
                if(ol==2){modificarNombre();}
                if(ol==3){modificarSalario();}
                if(ol!=3 && ol!=1 && ol!=2){printf("Error 404: Not Found.\n");printf("------------------------------------------\n");system("pause");system("cls");continue;}
        }
            system("pause");
            system("cls");

        }while(op!=7);

printf("------------------------------------------------------------------------------------------------------------------\n");
printf("Hecho:\nCarlos Daniel Torres Macías ID:244543 \nDiego Emanuel Saucedo Ortega ID:261230 \nJosé Luis Sandoval Perez ID: 261731 \nXimena Rivera Delgadillo ID:261261\n\n");
system("pause");

return 0;
}

void cambiarTemaConsola(){
    int op=-1;
    do{
        printf("\tT E M A S\n");
        printf("1.System Default\n");
        printf("2.Cherry\n");
        printf("3.MatrixEyes\n");
        printf("4.Aqua\n");
        printf("5.Hazard\n");
        printf("6.Guardar y salir\n");
        printf("---------------------------\n");
        printf("Seleccione una opcion\n");
        scanf("%d",&op);
        system("cls");
        switch(op){
            case 1://System Default
                system("color 0C");
                printf("SYSTEM DEFAULT\n");
                printf("------------------------------------------\n");
            break;
            case 2://Cherry
                system("color 4C");
                printf("SYSTEM CHERRY\n");
                printf("------------------------------------------\n");
            break;
            case 3://MatrixEyes
                system("color 02");
                printf("SYSTEM MATRIX EYES\n");
                printf("------------------------------------------\n");
            break;
            case 4://Aqus
                system("color B0");
                printf("SYSTEM AQUS\n");
                printf("------------------------------------------\n");
            break;
            case 5://Hazard
                system("color E0");
                printf("SYSTEM HAZARD\n");
                printf("------------------------------------------\n");
            break;
            case 6:
                printf("Cambios guardados\n");
                printf("------------------------------------------\n");
            break;
            default:
                printf("Tema No disponible\n");
                printf("------------------------------------------\n");
            break;
        }//fin switch
      system("pause");
      system("cls");
    }while(op!=6);
}
void funcion(){
	//explicacion de la funcion del programa
        printf("                             \tF U N C I O N  del  P R O G R A M A\n");
        printf("El siguiente programa nos permitira:\n");
        printf(".Crear un arreglo de 10 registros que represente la clave de un trabajador (numerica entero de 4 posiciones)\n");
        printf(".Crear otro arreglo de 10 registros correspondiente al nombre de personas con orden Nombre y Apellidos\n");
        printf(".Crear un ultimo arreglo igualmente de 10 registros pero que contega el salario del trabajador\n");
        printf("\nAsi como mostrar un menu con las siguientes opciones:\n");
        printf("1)Mostrar todos los contactos (el contenido de los tres arreglos)\n");
        printf("2)Buscar un registro dado como parametro el nombre o la clave del trabajador\n");
        printf("3)Insertar nuevos registros\n");
        printf("4)Eliminar un registro ya sea por clave o por nombre\n");
        printf("5)Modificar la clave, el nombre o el salario de algun trabajador\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");
        system("pause");
        system("cls");
}
void menu(){
        printf("               M E N U\n");
        printf("1) Lista de contactos de trabajadores\n");
        printf("2) Buscar trabajador\n");
        printf("3) Ordenar lista de trabajadores\n");
        printf("4) Insertar nuevos registros\n");
        printf("5) Eliminar registros\n");
        printf("6) Modificar registros\n");
        printf("7) Guardar y Salir\n");
        printf("---------------------------------------------------------\n");
        system("pause");
}
void agenda(){
	//Registros de trabajadores
    printf("\t   C O N T A C T O S   de los    T R A B A J A D O R E S\n");
    printf("clave              n o m b r e         \t\t\t\tsalario\n");

    for(int i=0;i<NT;i++){
        printf("%04d",claves_W[i]);
        printf("\t\t%s\t\t\t\t%.2lf\n",nombre_W[i],salario_W[i]);
    }//fin for i

    printf("----------------------------------------------------------------------\n");
}
int buscarClave(){
	int llave=0;

	printf("\tB U S C A R  P O R  C L A V E \n");
	printf("Ingrese la clave del trabajador\n");
	scanf("%d", &llave);
	printf("----------------------------------------------\n");
	for(int i=0;i<NT;i++){
		if(llave == claves_W[i]){return i;}
	}
	printf("----------------------------------------------\n");
	return -1;
	
}

int buscarNombre(){
    char busca[33];
    fflush(stdin);
    printf("\tB U S C A R  P O R  N O M B R E \n");
	printf("Ingrese el nombre completo del trabajador\n");
	gets(busca);
	printf("----------------------------------------------------------\n");
	for(int i=0;i<NT;i++){
		if(strcmp(busca,nombre_W[i])==0){return i;}
	}
	printf("----------------------------------------------------------\n");
	return -1;
}

void ordenarClave(){
    for(int i=1;i<NT;i++){
        int j=i-1,p=claves_W[i];
        double p_salario=salario_W[i];
        char p_nombre[33];
        sprintf(p_nombre,"%s",nombre_W[i]);

        while(p<claves_W[j] && j>=0){
            claves_W[j+1]=claves_W[j];
            sprintf(nombre_W[j+1],"%s",nombre_W[j]);
            salario_W[j+1]=salario_W[j];
            j--;
        }//fin while

            claves_W[j+1]=p;
            sprintf(nombre_W[j+1],"%s",p_nombre);
            salario_W[j+1]=p_salario;

    }//fin for i
    printf("Los empleados han sido organizados por Clave...\n");
    printf("------------------------------------------------\n");
}

void ordenarNombre(){
    for(int i=1;i<NT;i++){
            int j=i-1,p=claves_W[i];
            double p_salario=salario_W[i];
            char p_nombre[33];
            sprintf(p_nombre,"%s",nombre_W[i]);

            while(strcmp(p_nombre,nombre_W[j])<0 && j>=0){
                claves_W[j+1]=claves_W[j];
                sprintf(nombre_W[j+1],"%s",nombre_W[j]);
                salario_W[j+1]=salario_W[j];
                j--;
            }//fin while

                claves_W[j+1]=p;
                sprintf(nombre_W[j+1],"%s",p_nombre);
                salario_W[j+1]=p_salario;

    }//fin for i

    printf("Los empleados han sido organizados por Nombre...\n");
    printf("-------------------------------------------------\n");
}

void ordenarSalario(){
    for(int i=0;i<NT;i++){
        for(int j=0;j<NT;j++){
            if(salario_W[i]<salario_W[j]){
                double aux_S=salario_W[i];
                salario_W[i]=salario_W[j];
                salario_W[j]=aux_S;
                int aux_C=claves_W[i];
                claves_W[i]=claves_W[j];
                claves_W[j]=aux_C;
                char aux_N[33];
                sprintf(aux_N,"%s",nombre_W[i]);
                sprintf(nombre_W[i],"%s",nombre_W[j]);
                sprintf(nombre_W[j],"%s",aux_N);
            }
        }//fin for j
    }//fin for i
    printf("Los empleados han sido organizados por Salario...\n");
    printf("--------------------------------------------------\n");
}
void insertar(){
	printf("\t\tI N S E R T A R\n");
	printf("Ingrese la clave del trabajador (4 digitos)\n");
	fflush(stdin);
	scanf("%d",&claves_W[NT]);
	printf("----------------------------------------------------------\n");
	printf("Ingrese el nombre del trabajador (omita el uso de acentos)\n");
	fflush(stdin);
	gets(nombre_W[NT]);
	printf("-----------------------------------------------------------\n");
	printf("Ingrese el salario del trabajador (separe los decimales con una coma |,|)\n");
	scanf("%lf",&salario_W[NT]);
	printf("------------------------------------------------------------------------------------------\n");
	NT++;
	printf("Cambios Guardados!\n");
      printf("---------------------------------------------------------------------------------------------\n");
}
void eliminarClave(){
    int llave,k_pos=-1;
    printf("Ingrese la clave del empleado a eliminar en el registro\n");
    scanf("%d",&llave);
    printf("---------------------------------------------------------\n");
    for(int i=0;i<NT;i++){
		if(llave == claves_W[i]){k_pos=i; break;}
	}

    if(k_pos==-1){printf("Error 404: Not Found.\n"); printf("-------------------\n"); system("pause"); system("cls");return;}
    printf("Se elimino:|%04d|\t%s\t\t%0.2lf\n",claves_W[k_pos],nombre_W[k_pos],salario_W[k_pos]);
    printf("---------------------------------------------------------------------------------------------\n");
    while(k_pos<NT-1){
        claves_W[k_pos]=claves_W[k_pos+1];

        sprintf(nombre_W[k_pos],"%s",nombre_W[k_pos+1]);

        salario_W[k_pos]=salario_W[k_pos+1];
        k_pos++;
    }

	NT--;
	printf("Cambios Guardados!\n");
      printf("---------------------------------------------------------------------------------------------\n");
}

void eliminarNombre(){
    char llave[33],k_pos=-1;
    printf("Ingrese el nombre completo del empleado a eliminar en el registro\n");
    fflush(stdin);
    gets(llave);
    printf("---------------------------------------------------------------------\n");
    for(int i=0;i<NT;i++){
		if(strcmp(llave,nombre_W[i])==0){k_pos=i; break;}
	}

    if(k_pos==-1){printf("Error 404: Not Found.\n"); printf("-------------------\n"); system("pause"); system("cls");return;}
    printf("Se elimino:|%04d|\t%s\t\t%0.2lf\n",claves_W[k_pos],nombre_W[k_pos],salario_W[k_pos]);
    printf("---------------------------------------------------------------------------------------------\n");

    while(k_pos<NT-1){
        claves_W[k_pos]=claves_W[k_pos+1];

        sprintf(nombre_W[k_pos],"%s",nombre_W[k_pos+1]);

        salario_W[k_pos]=salario_W[k_pos+1];
        k_pos++;
    }

	NT--;
	printf("Cambios Guardados!\n");
      printf("---------------------------------------------------------------------------------------------\n");
}

void modificarClave(){
    int ol=-1;
    printf("\tM O D I F I C A R       c l a v e\n");
    printf(" clave  \tn o m b r e\t\tsalario\n");
    for(int i=0;i<NT;i++){
        printf("%d.%04d\t%s\t\t%.2lf\n",i+1,claves_W[i],nombre_W[i],salario_W[i]);
    }
    printf("---------------------------------------------------------------------------------------------\n");

    printf("Seleccione de la lista al empleado que se modificara su CLAVE (numero a la derecha): ");
    scanf("%d",&ol); ol--;
    printf("---------------------------------------------------------------------------------------------\n");

    if(ol<0 || ol>=NT){printf("Error 404: Not Found.\n"); printf("-------------------\n"); system("pause"); system("cls");return;}

    printf("Ingrese la nueva clave de %s (recuerde que la clave tiene como maximo 4 digitos)\n",nombre_W[ol]);
    scanf("%d",&claves_W[ol]);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Cambios Guardados!\n");
    printf("---------------------------------------------------------------------------------------------\n");
}

void modificarNombre(){
    int ol=-1;
    printf("\t\tM O D I F I C A R       n o m b r e\n");
    printf(" clave  \tn o m b r e\t\tsalario\n");
    for(int i=0;i<NT;i++){
        printf("%d.%04d\t%s\t\t%.2lf\n",i+1,claves_W[i],nombre_W[i],salario_W[i]);
    }
    printf("---------------------------------------------------------------------------------------------\n");

    printf("De la lista seleccione al empleado del que se modificara su NOMBRE (numero a la derecha): ");
    scanf("%d",&ol); ol--;
    printf("---------------------------------------------------------------------------------------------\n");

    if(ol<0 || ol>=NT){printf("Error 404: Not Found.\n");printf("-------------------\n"); system("pause"); system("cls");return;}

    printf("Ingrese el NOMBRE del empleado %d (recuerde omitir acentos)\n",claves_W[ol]);
    fflush(stdin);
    gets(nombre_W[ol]);
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Cambios Guardados!\n");
    printf("----------------------------------------------------------------------------------------------\n");
}

void modificarSalario(){
    int ol=-1;
    printf("\t\tM O D I F I C A R       s a l a r i o\n");
    printf(" clave  \tn o m b r e\t\tsalario\n");
    for(int i=0;i<NT;i++){
        printf("%d.%04d\t%s\t\t%.2lf\n",i+1,claves_W[i],nombre_W[i],salario_W[i]);
    }
    printf("---------------------------------------------------------------------------------------------\n");
    printf("De la lista seleccione al empleado que se modificara su SALARIO...\n");
    printf("Ingrese su nombre\n");
    scanf("%d",&ol); ol--;
    printf("---------------------------------------------------------------------------------------------\n");
    if(ol<0 || ol>=NT){printf("Error 404: Not Found.\n"); printf("-------------------\n"); system("pause"); system("cls"); return;}

    printf("Ingrese el salario del empleado %s (separe los decimales con coma |,|)\n",nombre_W[ol]);
    scanf("%lf",&salario_W[ol]);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Cambios Guardados!\n");
    printf("---------------------------------------------------------------------------------------------\n");
}

void generaClaves(int claves[]){
    for(int i=0;i<10;i++){
		claves[i]=rand()%10000;
    }//fin for i
}

void generaNombres(char nombres[][33]){
    for(int i=0;i<10;i++){
        int n=rand()%NOMBRES_C;
        int a1=rand()%APELLIDOS_C;
        int a2=rand()%APELLIDOS_C;

        sprintf(nombres[i],"%s %s %s",NOMBRES[n],APELLIDOS[a1],APELLIDOS[a2]);
    }
}

void generaSalarios(double salarios[]){
    for(int i=0;i<10;i++){
        double a=(rand()%MAX_SS)/100.00;
        salarios[i]=SALARIO_MIN+a;
        a=(rand()%10)/100.00;
        salarios[i]+=a;
    }
}
