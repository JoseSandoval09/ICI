#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"spanish"); //locale h para escribir correctamente
	int op=0,p=0,q=0,r=0,i=0,n=3,j=0,n1=7; const s=21;//variables y contantes a utilizar
	//función del programa
	printf("El siguiente programa nos permitirá conocer la tabla de verdad de un menú de 3 operaciones lógicas\n");
	//separador
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	system("pause"); //pausa
	system("cls"); // borro pantalla
	system("color 0D"); //cambio de color
	
	printf("MENÚ DE OPERACIONES\n"); //mostramos en la pantalla limpia el menú
	printf("1.- Conjunción\n");
	printf("2.- Disyunción\n");
	printf("3.- Salir\n");
	system("pause"); // pausa
	//separador
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	
	system("color 0C");//cambio de color
	printf("Ingresa la opción de la operación que deseas realizar\n");//pido que se seleccione una opción 
	scanf("%d",&op);//leemos la opción seleccionada
	//separador
	printf("--------------------------------------------------------------------------------------------------------------------\n");

	system("pause");//pausa
	system("cls");//limpio la pantalla
	system("color 0E");//cambio de color
	int dis[n],con[n1];//inicializo matrices a utilizar
	
	switch(op){ //abro el ciclo switch para la opción seleccionada
		case 1: { //caso 1 conjunción de tres variables
			 printf(" TABLA DE VERDAD\n");//titulo
		    printf(" Conjunción de tres variables\n");//subtitulo
		    //desarrollo de la matriz de la tabla de verdad
		    printf("  p  q  r  p^q  p^q^r\n");
			 for(i=0;i<n1+2;i++){ //columnas
		      for(j=0;j<n1;j++) //filas
		       {       //columna 0 fila 0 
		        	     if (i==0 && j==0){printf("  %d ",p);}
		        	     //columna 0 fila 1
		        	     if (i==0 && j==1){printf(" %d ",q);}
		        	     //columna 0 fila 2
		        	     if (i==0 && j==2){printf(" %d ",r);}
		        	     //columna 0 fila 3
		        	     if (i==0 && j==3){printf("  %d ",p&&q);}
		        	     //columna 0 fila 4
		        	     if (i==0 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 1 fila 0 
		        	     if (i==1 && j==0){printf("  %d ",p);}
		        	     //columna 1 fila 1
		        	     if (i==1 && j==1){printf(" %d ",q);}
		        	     //columna 1 fila 2
		        	     if (i==1 && j==2){r++;printf(" %d ",r);}
		        	     //columna 1 fila 3
		        	     if (i==1 && j==3){printf("  %d ",p&&q);}
		        	     //columna 1 fila 4
		        	     if (i==1 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 2 fila 0 
		        	     if (i==2 && j==0){printf("  %d ",p);}
		        	     //columna 2 fila 1
		        	     if (i==2 && j==1){q++;printf(" %d ",q);}
		        	     //columna 2 fila 2
		        	     if (i==2 && j==2){r--;printf(" %d ",r);}
		        	     //columna 2 fila 3
		        	     if (i==2 && j==3){printf("  %d ",p&&q);}
		        	     //columna 2 fila 4
		        	     if (i==2 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 3 fila 0 
		        	     if (i==3 && j==0){printf("  %d ",p);}
		        	     //columna 3 fila 1
		        	     if (i==3 && j==1){printf(" %d ",q);}
		        	     //columna 3 fila 2
		        	     if (i==3 && j==2){r++;printf(" %d ",r);}
		        	     //columna 3 fila 3
		        	     if (i==3 && j==3){printf("  %d ",p&&q);}
		        	     //columna 3 fila 4
		        	     if (i==3 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 4 fila 0 
		        	     if (i==4 && j==0){p++;printf("  %d ",p);}
		        	     //columna 4 fila 1
		        	     if (i==4 && j==1){q--;printf(" %d ",q);}
		        	     //columna 4 fila 2
		        	     if (i==4 && j==2){r--;printf(" %d ",r);}
		        	     //columna 4 fila 3
		        	     if (i==4 && j==3){printf("  %d ",p&&q);}
		        	     //columna 4 fila 4
		        	     if (i==4 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 5 fila 0 
		        	     if (i==5 && j==0){printf("  %d ",p);}
		        	     //columna 5 fila 1
		        	     if (i==5 && j==1){q++;printf(" %d ",q);}
		        	     //columna 5 fila 2
		        	     if (i==5 && j==2){printf(" %d ",r);}
		        	     //columna 5 fila 3
		        	     if (i==5 && j==3){printf("  %d ",p&&q);}
		        	     //columna 5 fila 4
		        	     if (i==5 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 6 fila 0 
		        	     if (i==6 && j==0){printf("  %d ",p);}
		        	     //columna 6 fila 1
		        	     if (i==6 && j==1){printf(" %d ",q);}
		        	     //columna 6 fila 2
		        	     if (i==6 && j==2){r++;printf(" %d ",r);}
		        	     //columna 6 fila 3
		        	     if (i==6 && j==3){printf("  %d ",p&&q);}
		        	     //columna 6 fila 4
		        	     if (i==6 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        }
				}
		     printf("\n");
			
			break;
		}
		
		break;
		
		case 2:{ //caso2 disyuncion de dos variables
			 printf(" TABLA DE VERDAD\n");//titulo
		    printf(" Disyunción de dos variables\n"); //subtitulo
		    //desarrollo de la matriz de la tabla de verdad
		    printf("  p  q  pvq \n");
			 for(i=0;i<n+1;i++){ //columnas
		      for(j=0;j<n;j++) //filas
		       {       //columna 0 fila 0 
		        	     if (i==0 && j==0){printf("  %d ",p);}
		        	     //columna 0 fila 1
		        	     if (i==0 && j==1){printf(" %d ",q);}
		        	     //columna 0 fila 2
		        	     if (i==0 && j==2){printf("  %d\n",p||q);}
		        	     
		        	     //columna 1 fila 0
		        	     if (i==1 && j==0){printf("  %d ",p);}
		        	     //columna 1 fila 1
		        	     if (i==1 && j==1){q++;printf(" %d ",q);}
		        	     //columna 1 fila 2
		        	     if (i==1 && j==2){printf("  %d\n",p||q);}
		        	     
		        	     //columna 2 fila 0
		        	     if (i==2 && j==0){p++;printf("  %d ",p);}
		        	     //columna 2 fila 1
		        	     if (i==2 && j==1){q--;printf(" %d ",q);}
		        	     //columna 2 fila 2
		        	     if (i==2 && j==2){printf("  %d\n",p||q);}
		        	     
		        	      //columna 3 fila 0
		        	     if (i==3 && j==0){printf("  %d ",p);}
		        	     //columna 3 fila 1
		        	     if (i==3 && j==1){q++;printf(" %d ",q);}
		        	     //columna 3 fila 2
		        	     if (i==3 && j==2){printf("  %d\n",p||q);}
		        }
				}
		     printf("\n");
			break;
	       }
		case 3://caso 3 salir
			
			system("color F4");//cambio de color
			while(i<s){//escribo salir y la carita triste 21 veces con la constante s
				i++;
				printf(":c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c \n");
				printf("SALIR SALIR SALIR SALIR SALIR SALIR SALIR\n");
			}
		break;
		
		default://caso default donde no se encuentra dentro de los valores 1,2,3
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			//separador
			system("color C7");//cambio de color
			printf("ERROR el valor ingresado no es válido\n");//indico el error
	}
	int o=0;
//REPETIR EL PROGRAMA
//separador
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("Si desea volver a ejecutar el programa ingrese 1\n");
	scanf("%d",&o);
	while(o==1){
	 system("pause");
	 system("cls"); // borro pantalla
	 system("color 0D"); //cambio de color
	 printf("MENÚ DE OPERACIONES\n"); //mostramos en la pantalla limpia el menú
    printf("1.- Conjunción\n");
    printf("2.- Disyunción\n");
	 printf("3.- Salir\n");
	 system("pause"); // pausa
	 //separador           
	 printf("--------------------------------------------------------------------------------------------------------------------\n");
	
	 system("color 0C");//cambio de color
	 printf("Ingresa la opción de la operación que deseas realizar\n");//pido que se seleccione una opción 
	 scanf("%d",&op);//leemos la opción seleccionada
	 //separador
	 printf("--------------------------------------------------------------------------------------------------------------------\n");

	 system("pause");//pausa
	 system("cls");//limpio la pantalla
	 system("color 0E");//cambio de color
	 int dis[n],con[n1];//inicializo matrices a utilizar
	
	 switch(op){ //abro el ciclo switch para la opción seleccionada
		case 1: { //caso 1 conjunción de tres variables
			 printf(" TABLA DE VERDAD\n");//titulo
		    printf(" Conjunción de tres variables\n");//subtitulo
		    //desarrollo de la matriz de la tabla de verdad
		    printf("  p  q  r  p^q  p^q^r\n");
			 for(i=0;i<n1+2;i++){ //columnas
		      for(j=0;j<n1;j++) //filas
		       {       //columna 0 fila 0 
		        	     if (i==0 && j==0){printf("  %d ",p);}
		        	     //columna 0 fila 1
		        	     if (i==0 && j==1){printf(" %d ",q);}
		        	     //columna 0 fila 2
		        	     if (i==0 && j==2){printf(" %d ",r);}
		        	     //columna 0 fila 3
		        	     if (i==0 && j==3){printf("  %d ",p&&q);}
		        	     //columna 0 fila 4
		        	     if (i==0 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 1 fila 0 
		        	     if (i==1 && j==0){printf("  %d ",p);}
		        	     //columna 1 fila 1
		        	     if (i==1 && j==1){printf(" %d ",q);}
		        	     //columna 1 fila 2
		        	     if (i==1 && j==2){r++;printf(" %d ",r);}
		        	     //columna 1 fila 3
		        	     if (i==1 && j==3){printf("  %d ",p&&q);}
		        	     //columna 1 fila 4
		        	     if (i==1 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 2 fila 0 
		        	     if (i==2 && j==0){printf("  %d ",p);}
		        	     //columna 2 fila 1
		        	     if (i==2 && j==1){q++;printf(" %d ",q);}
		        	     //columna 2 fila 2
		        	     if (i==2 && j==2){r--;printf(" %d ",r);}
		        	     //columna 2 fila 3
		        	     if (i==2 && j==3){printf("  %d ",p&&q);}
		        	     //columna 2 fila 4
		        	     if (i==2 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 3 fila 0 
		        	     if (i==3 && j==0){printf("  %d ",p);}
		        	     //columna 3 fila 1
		        	     if (i==3 && j==1){printf(" %d ",q);}
		        	     //columna 3 fila 2
		        	     if (i==3 && j==2){r++;printf(" %d ",r);}
		        	     //columna 3 fila 3
		        	     if (i==3 && j==3){printf("  %d ",p&&q);}
		        	     //columna 3 fila 4
		        	     if (i==3 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 4 fila 0 
		        	     if (i==4 && j==0){p++;printf("  %d ",p);}
		        	     //columna 4 fila 1
		        	     if (i==4 && j==1){q--;printf(" %d ",q);}
		        	     //columna 4 fila 2
		        	     if (i==4 && j==2){r--;printf(" %d ",r);}
		        	     //columna 4 fila 3
		        	     if (i==4 && j==3){printf("  %d ",p&&q);}
		        	     //columna 4 fila 4
		        	     if (i==4 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 5 fila 0 
		        	     if (i==5 && j==0){printf("  %d ",p);}
		        	     //columna 5 fila 1
		        	     if (i==5 && j==1){q++;printf(" %d ",q);}
		        	     //columna 5 fila 2
		        	     if (i==5 && j==2){printf(" %d ",r);}
		        	     //columna 5 fila 3
		        	     if (i==5 && j==3){printf("  %d ",p&&q);}
		        	     //columna 5 fila 4
		        	     if (i==5 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        	     //columna 6 fila 0 
		        	     if (i==6 && j==0){printf("  %d ",p);}
		        	     //columna 6 fila 1
		        	     if (i==6 && j==1){printf(" %d ",q);}
		        	     //columna 6 fila 2
		        	     if (i==6 && j==2){r++;printf(" %d ",r);}
		        	     //columna 6 fila 3
		        	     if (i==6 && j==3){printf("  %d ",p&&q);}
		        	     //columna 6 fila 4
		        	     if (i==6 && j==4){printf("    %d\n",p&&q&&r);}
		        	     
		        }
				}
		     printf("\n");
			
			break;
		}
		
		break;
		
		case 2:{ //caso2 disyuncion de dos variables
			 printf(" TABLA DE VERDAD\n");//titulo
		    printf(" Disyunción de dos variables\n"); //subtitulo
		    //desarrollo de la matriz de la tabla de verdad
		    printf("  p  q  pvq \n");
			 for(i=0;i<n+1;i++){ //columnas
		      for(j=0;j<n;j++) //filas
		       {       //columna 0 fila 0 
		        	     if (i==0 && j==0){printf("  %d ",p);}
		        	     //columna 0 fila 1
		        	     if (i==0 && j==1){printf(" %d ",q);}
		        	     //columna 0 fila 2
		        	     if (i==0 && j==2){printf("  %d\n",p||q);}
		        	     
		        	     //columna 1 fila 0
		        	     if (i==1 && j==0){printf("  %d ",p);}
		        	     //columna 1 fila 1
		        	     if (i==1 && j==1){q++;printf(" %d ",q);}
		        	     //columna 1 fila 2
		        	     if (i==1 && j==2){printf("  %d\n",p||q);}
		        	     
		        	     //columna 2 fila 0
		        	     if (i==2 && j==0){p++;printf("  %d ",p);}
		        	     //columna 2 fila 1
		        	     if (i==2 && j==1){q--;printf(" %d ",q);}
		        	     //columna 2 fila 2
		        	     if (i==2 && j==2){printf("  %d\n",p||q);}
		        	     
		        	      //columna 3 fila 0
		        	     if (i==3 && j==0){printf("  %d ",p);}
		        	     //columna 3 fila 1
		        	     if (i==3 && j==1){q++;printf(" %d ",q);}
		        	     //columna 3 fila 2
		        	     if (i==3 && j==2){printf("  %d\n",p||q);}
		        }
				}
		     printf("\n");
			break;
	       }
		case 3://caso 3 salir
			
			system("color F4");//cambio de color
			while(i<s){//escribo salir y la carita triste 21 veces con la constante s
				i++;
				printf(":c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c :c \n");
				printf("SALIR SALIR SALIR SALIR SALIR SALIR SALIR\n");
			}
		break;
		
		default://caso default donde no se encuentra dentro de los valores 1,2,3
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			//separador
			system("color C7");//cambio de color
			printf("ERROR el valor ingresado no es válido\n");//indico el error
	 }
	 printf("Si desea volver a ejecutar el programa ingrese 1\n");
	 scanf("%d",&o);
	 printf("--------------------------------------------------------------------------------------------------------------------\n");
	}
	system("cls");
	printf("GRACIAS\n");
	system("pause");
	//separador
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	//nombre de la autora
	printf("\nHecho por: Ximena Rivera Delgadillo\n");
	system("color 0B");//cambio de color
	return 0;//regreso 0