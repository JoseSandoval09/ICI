#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include<conio.h>
/*
EJERCICIO: Cadenas de caracteres (Strings)
Lenguajes de Computación 1°E  (PARCIAL 3)
Ximena Rivera Delgadillo ID:261261
José Luis Sandoval Perez ID: 261731
Diego Emanuel Saucedo Ortega ID:261230
Carlos Daniel Torres Macias ID:244543
*/

int main()
{
    system("color B");
    setlocale(LC_ALL,"spanish");
	srand(time(NULL));
	

	//Apodos
	char apodos[27][30] ={
    "Mi Pandita Rojo", "Mi “Rocker”", "El Chocolatozo",
    "La Reina del oriente", "El cuchi cuchis", "Dr. Sexy",
    "El metro y sexual", "El metrosexual", "El pelos",
    "El cacas", "El patas", "El comal",
    "El power ranger", "El chicharito", "La tortilla de arriba",
    "El mata viejitas", "El nene", "El bicho, SIUU",
    "El Winnie de Pooh", "El chemo", "La chimenea",
    "La vaca", "El motorola", "La manteca",
    "El autogol", "El tilín", "El cagalubias"};
    //Usernames
    char user[27][30] ={
    "S3x0m4n69", "Vienbergas69", "BuscoNovia69",
    "GucciItachi69", "Nosabiaqueponer69", "Ladearribaesminovia",
    "AlexMarin69", "LaToxica69", "Matamancos69",
    "NotchMiPastor69", "Batman69", "MacMiller69",
    "EltonTito69", "Golosa69", "MaquinaDeFuego69",
    "AlphaKennyBody69", "TuMama69", "Mr.Loquendo",
    "BenitoCamelo69", "ConejoLetal" "AMLO2018",
    "Chacalito69", "AceInTheH0L3", "COBIG-69",
    "RosaMelano69", "JesusMariaJose69", "ElToxico69"};

    char name[26];//Almacena el nombre ingresado
    char g_name[31];//Garbage_name guarda borradores de nombres

	int x=0,m,peso,p;//variable de opción

	while (x != 5){
        printf("--->nombres&nombres.com<---");
		printf("\n1. Apodos coquetos.\n");
		printf("2. Un username para el discord de la UAA.\n");
		printf("3. Su nombre de espia super secreto.\n");
		printf("4. Brujo adivinador de peso\n");
		printf("5. Al chile, no tengo ganas de nada, mejor salir.\n");
        printf("¿Qué desea hacer?: ");
		scanf("%d", &x);

        fflush(stdin);

		switch(x){
			case 1:
				
				printf("Buen dia usuario, como se llama?: ");
				gets(name);
				m = rand()%27;
				strlwr(name);
				printf("\n%s, hoy eres bautizado como %s\n", name, apodos[m]);
            break;//Da un apodo aleatorio al usuario

			case 2:
				
				printf("Buen dia usuario, ingrese un nombre y su primer apellido\n");
				gets(name);
				p = rand()%27;
				printf("%s el username que debes de usar en el Warzone es: %s\n", name, user[p]);
            break;//Da un username de COD

			case 3:
				printf("Buen dia usuario, ingrese su nombre: ");
				gets(name);
				strset(name, 'x');
				printf("Agente: %s",name);
				printf("\nYa no tiene nombre, como los espias de verdad, se ha eliminado su registro.\n");
            break;//Nombre de espia

			case 4:
			
				printf("Buen dia usuario, ingrese un nombre y su primer apellido\n");
				gets(name);
				peso = strlen(name);
				strupr(name);
				printf("Entonces %s, usted pesa %d kilos\n", name, peso+30);
            break;//Da el peso de la cadena

			case 5:
				printf("Adios camarada, ten un bonito dia, te sanitizas.\n");
            break;

			default:
				printf("No le quieras jugar al chistocito, ya dame un numero del menu.\n");
            break;

		}//fin switch

		system("pause");
        system("cls");
	}//fin while menu

	system("color 70");

	printf("Goodbye!\n");

    printf("Hecho por:\nXimena Rivera Delgadillo ID:261261\n");
    printf("José Luis Sandoval Perez ID: 261731\n");
    printf("Diego Emanuel Saucedo Ortega ID:261230\n");
    printf("Carlos Daniel Torres Macias ID:244543\n");
    system("pause");
    getch();
	return 0;
}

