#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>


/*
EJERCICIO Arreglos: Funciones (Paso de Arreglos)
Lenguajes de Computaci�n 1�E  (PARCIAL 3)
Ximena Rivera Delgadillo ID:261261
Jos� Luis Sandoval Perez ID: 261731
Diego Emanuel Saucedo Ortega ID:261230
Carlos Daniel Torres Macias ID:244543
*/
void relaciona(int numS[],int signo);

int main()
{
    system("color 75");
    setlocale(LC_ALL,"spanish");
    srand(time(NULL));

	int sign;
	int num_suerte[5];

	do{
	printf("Buen dia usuario, por favor indique su signo zodiacal y le dire sus numeros de la suerte\n");
	printf("1. Aries.\n");
	printf("2. Tauro.\n");
	printf("3. Geminis.\n");
	printf("4. Cancer.\n");
	printf("5. Leo.\n");
	printf("6. Virgo.\n");
	printf("7. Libra.\n");
	printf("8. Escorpio.\n");
	printf("9. Sagitario.\n");
	printf("10. Capricornio.\n");
	printf("11. Acuario.\n");
	printf("12. Piscis.\n");
	printf("13. Salir de programa.\n");
	printf("Opci�n: ");
	scanf("%d", &sign);

	system("clear");

        switch(sign)
		{
			//Aries
			case 1:
			{
                printf("Aries, fluyes como el aire, pero hueles como una flatulencia de tacos de higado encebellado\n");
                printf("Tus numeros de la suerte son:\n");
				break;
			}
			//Tauro
			case 2:
			{
				printf("Neta eres tauro???? Compartes signo con Hitle, pues ya sabes lo que �l hizo\n");
				printf("Tus numeros de la suerte son:\n");

				break;
			}
			//Geminis
			case 3:
			{
				printf("Geminis, seguro no vas a estar de acuerdo con tus numeros, pero eso es muy tipico de geminis, equis");
				printf("Tus numeros de la suerte son:\n");

				break;
			}
			//Cancer
			case 4:
			{
				printf("Llorar todos los d�as no es un buen h�bito para tu salud...Puedes secarte\n");
				printf("Recuerda resolver tus problemas en vez de ocuparte en los de los otros :)\n");
				printf("Tus n�meros de la suerte son:\n");

				break;
			}
			//Leo
			case 5:
			{
				printf("Sigue tus sue�os Leo, como yo. So�e con conocer al amor de mi vida y la segui a su casa\n");
				printf("Deje de hacerlo cuando vi lonas con mi cara en la cuadra\n");
				printf("Tus n�meros de la suerte son:\n");

				break;
			}
			//Virgo
			case 6:
			{
				printf("Le falta un poco de color a tu outfit, ponte algo colorido\n");
				printf("Sin duda eres muy fuerte, pero a veces se vale llorar para sanar\n");
				printf("Tus n�meros de la suerte son : \n");
				break;
			}
			//Libra
			case 7:
			{
				printf("�Sab�as que una unidad tuya equivale a 0.453592 de Kilogramos?\n");
				printf("Las decisiones de la vida soy muy importantes, trata de no cambiarlas 3 veces a �ltimo minuto\n");
				printf("Tus n�meros de la suerte son:\n");

				break;
			}
			//Escorpio
			case 8:
			{
				printf("Mejora tu salud y has una cita con tu m�dico, intenta cambiar tus malos habitos:\n");
				printf("Morderte las u�as, disfrazarte para ver una pel�cula, dejarme en visto, salir de mi vida :(");
				printf("Tus n�meros de la suerte son:\n");

				break;
			}
			//Sagitario
			case 9:
			{
				printf("Sonr�e que esa sonrisa es lo que te salvar� de esta tormenta\n");
				printf("Eres el m�s guapo la verdad, aunque le duela a los dem�s signos del zodiaco uwu\n");
				printf("Tus n�meros de la suerte son : \n");
				break;
			}
			//Capricornio
			case 10:
			{
				printf("�Ya pensaste en lo mala e injusta que es la vida el d�a de hoy? No seas tan pesimista, siempre hay un lado positivo en las cosas :)\n");
				printf("Ghostear a las personas no es la �nica respuesta a las cosas, intenta algo nuevo\n");
				printf("Tus n�meros de la suerte son:\n");

				break;
			}
			//Acuario
			case 11:
			{
				printf("No le digas a sagitario pero t� eres el m�s bellx del zodiaco\n");
				printf("por favor ya no regreses con tu ex, eso no se hace\n");
				printf("Tus n�meros de la suerte son : \n");

				break;
			}
			//Piscis
			case 12:
            {
                printf("No tienes dinero.\n");
				printf("�Qu� prefieres? 100 pesos o un consejo millonario. *le vende un curso*\n");
				printf("Tus n�meros de la suerte son : \n");
                break;
            }

			//Salir
			case 13:
			{
				break;
			}
			default:
			{
				break;
			}
		}//fin switch*/

		if(sign<13 && sign>0){
            for(int i=0;i<5;i++){
                num_suerte[i]=(rand()%20)+1;
                printf("\t%d",num_suerte[i]);
            }
            printf("\n\n");
            relaciona(num_suerte,sign);
		}

		system("pause");
		system("clear");


	}while(sign != 13);

	printf("Hecho por:\nXimena Rivera Delgadillo ID:261261\n");
    printf("Jos� Luis Sandoval Perez ID: 261731\n");
    printf("Diego Emanuel Saucedo Ortega ID:261230\n");
    printf("Carlos Daniel Torres Macias ID:244543\n");
    system("pause");
	return 0;
}


void relaciona(int numS[],int signo){
    for(int i=0;i<5;i++){
        if(numS[i]==7 && signo!=1){printf("%d te relaciona con Aries.\n",numS[i]);}
        if(numS[i]==4 && signo!=2){printf("%d te relaciona con Tauro.\n",numS[i]);}
        if(numS[i]==9 && signo!=3){printf("%d te relaciona con Geminis.\n",numS[i]);}
        if(numS[i]==8 && signo!=4){printf("%d te relaciona con C�ncer.\n",numS[i]);}
        if(numS[i]==10 && signo!=5){printf("%d te relaciona con Leo.\n",numS[i]);}
        if(numS[i]==15 && signo!=7){printf("%d te relaciona con Virgo.\n",numS[i]);}
        if(numS[i]==19 && signo!=8){printf("%d te relaciona con Libra.\n",numS[i]);}
        if(numS[i]==13 && signo!=9){printf("%d te relaciona con Escorpio.\n",numS[i]);}
        if(numS[i]==16 && signo!=10){printf("%d te relaciona con Capricornio.\n",numS[i]);}
        if(numS[i]==14 && signo!=11){printf("%d te relaciona con Acuario.\n",numS[i]);}
        if(numS[i]==5 && signo!=12){printf("%d te relaciona con Piscis.\n",numS[i]);}
    }//fin for i
}

