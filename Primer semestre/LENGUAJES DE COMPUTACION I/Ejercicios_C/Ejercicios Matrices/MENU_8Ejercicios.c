/* José Luis Sandoval Pérez 1°A ICI

MENU 8 EJERCICIOS MATRICES
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>

int main(){
	
	setlocale(LC_ALL,"spanish");
	
	int op=0;
	
	
	while(op!=9){
	
	system("cls");
	
	printf("------MENU------");
	printf("\n");
	printf("Selecciona una opción y te muestrare la matriz que corresponde:");
	printf("\n");
	printf("1-Matriz 4x4 y la suma total de todos sus elementos.");
	printf("\n2-Matriz 4x4 y la suma de todos sus elementos x fila.");	
	printf("\n3-Matriz 4x4 y la suma de todos sus elementos x columna.");
	printf("\n4-Matriz nxn x un escalar, mostrando 2 matrices y el escalar.");
	printf("\n5-Suma de 2 matrices cuadradas,mostrando las 2 matrices y matriz resultado.");
	printf("\n6-Ordenar una matriz de menor a mayor, mostrando matriz original y ordenada.");
	printf("\n7-Ordenar una matriz de mayor a menor, mostrando matriz original y ordenada.");
	printf("\n8-Matriz identidad.");
	printf("\n9-Salir");
	printf("\n");
	printf("Que opcion eliges: ");
	scanf("%d", &op);
	
	

	
	switch(op){
		case 1:{
			
			system("cls");
			
			const int tam=4;
			int matriz[tam][tam];
			int i,k;
			int suma=0;
			
			printf("Elegiste opcion 1\n");
			
			for(i=1;i<=tam;i++){
				for(k=1;k<=tam;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
					suma=suma+ matriz[i][k];
				}
			}
			printf("La matriz dada es: \n");
			for(i=1;i<=tam;i++)
			{
				for(k=1;k<=tam;k++)
				{
					printf("\t%d",matriz[i][k]);
				}
				printf("\n");
			}
			printf("La suma de los valores de la matriz es: %d\n", suma);
			
			system("pause");
			
			continue;	
		}
		case 2:{
			
			system("cls");
			
			const int tam=4;
			int matriz[tam][tam];
			int i,k;
			int sumafila=0;
			
			printf("Elegiste opcion 2\n");
			
			for(i=1;i<=tam;i++){
				for(k=1;k<=tam;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
				}
			}
			printf("La matriz dada es: \n");
			for(i=1;i<=tam;i++)
			{
				sumafila=0;
				for(k=1;k<=tam;k++)
				{
					sumafila=sumafila+matriz[i][k];
					printf("\t%d\t",matriz[i][k]);
				}
				printf("La suma de la fila %d es: %d\n", i,sumafila);
			}	
			
			system("pause");		
			continue;
		}
		case 3:{
			
			system("cls");
			
			const int tam=4;
			int matriz[tam][tam];
			int i,k;
			int sumacolum=0;
			
			printf("Elegiste opcion 3\n");
			
			for(i=1;i<=tam;i++){
				for(k=1;k<=tam;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
				}
			}
			printf("La matriz dada es: \n");
			
			for(k=1;k<=tam;k++)
			{
				sumacolum=0;
				for(i=1;i<=tam;i++)
				{
					sumacolum=sumacolum+matriz[k][i];
					printf("\t%d\t",matriz[i][k]);
				}
				printf("La suma de la columna %d es: %d\n", k,sumacolum);
			}
			
			system("pause");
			continue;
		}	
		case 4:{
			
			system("cls");
			
			int tamc=0,tamf=0,i=0,k=0;
			int suma=0, escalar=0;
			
			printf("Elegiste opcion 4\n");
			
			printf("\nIngresa valor de filas de la matriz: ");
			scanf("%d", &tamf);
			printf("Ingresa valor de columnas de la matriz: ");
			scanf("%d", &tamc);
			printf("\nIngresa el escalar que multiplicara a la matriz: ");
			scanf("%d", &escalar);
			
			int matriz[tamf][tamc];
			int matrizm[tamf][tamc]; 
			
			for(i=0;i<tamf;i++){
				for(k=0;k<tamc;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
				}
			}
			
			
			printf("La matriz dada es: \n");
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			
			printf("\nEl escalar es: %d ", escalar);
			
			printf("\nLa matriz multiplicada por el escalar %d es: \n", escalar);
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					matrizm[i][k]=matriz[i][k]*escalar;
					printf("\t%d", matrizm[i][k]);
				}
				printf("\n");
			}
			
			printf("\n");
			system("pause");
			continue;
		}
		case 5:{
			
			system("cls");
			
			int i=0,k=0,n=0;
		
			
			printf("Elegiste opcion 5\n");
			
			printf("\nIngresa valor de la matriz nxn : ");
			scanf("%d", &n);
		
			
			int matriz1[n][n];
			int matriz2[n][n];
			int matrizsuma[n][n]; 
			
			for(i=0;i<n;i++){
				for(k=0;k<n;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz1[i][k]);
				}
			}
			
			printf("Ingresa matriz 2: \n");
			for(i=0;i<n;i++){
				for(k=0;k<n;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz2[i][k]);
				}
			}
			
			
			printf("La matrices dadas son: \n");
			printf("Matriz 1\n");
			for(i=0;i<n;i++)
			{
				for(k=0;k<n;k++)
				{
					printf("\t%d", matriz1[i][k]);
				}
				printf("\n");
			}
			
			printf("Matriz 2\n");
			for(i=0;i<n;i++)
			{
				for(k=0;k<n;k++)
				{
					printf("\t%d", matriz2[i][k]);
				}
				printf("\n");
			}
			
			printf("\nLa matriz suma es: \n");
			
			for(i=0;i<n;i++)
			{
				for(k=0;k<n;k++)
				{
					matrizsuma[i][k]=matriz1[i][k]+matriz2[i][k];
					printf("\t%d", matrizsuma[i][k]);
				}
				printf("\n");
			}
			
			system("pause");
			continue;
		}
		case 6:{
			
			system("cls");
			
			int tamc=0,tamf=0,i=0,k=0,aux=0,y=0,z=0;
			
			printf("Elegiste opcion 6\n");
			
			printf("\nIngresa valor de filas de la matriz: ");
			scanf("%d", &tamf);
			printf("Ingresa valor de columnas de la matriz: ");
			scanf("%d", &tamc);
			
			int matriz[tamf][tamc];
			
			for(i=0;i<tamf;i++){
				for(k=0;k<tamc;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
				}
			}
			
			printf("La matriz dada es: \n");
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			
			for(i=0;i<tamf;i++){
				for(k=0;k<tamc;k++){
					for(y=0;y<tamf;y++){
						for(z=0;z<tamc;z++){
							if(matriz[i][k]<matriz[y][z]){
								aux=matriz[i][k];
								matriz[i][k]=matriz[y][z];
								matriz[y][z]=aux;
							}
						}
					}
				}
			}
			
			printf("La matriz ordenada de menor a mayor es: \n");
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			
			system("pause");
			continue;
		}
		case 7:{
			
			system("cls");
			
			int tamc=0,tamf=0,i=0,k=0,aux=0,y=0,z=0;
			
			printf("Elegiste opcion 7\n");
			
			printf("\nIngresa valor de filas de la matriz: ");
			scanf("%d", &tamf);
			printf("Ingresa valor de columnas de la matriz: ");
			scanf("%d", &tamc);
			
			int matriz[tamf][tamc];
			
			for(i=0;i<tamf;i++){
				for(k=0;k<tamc;k++){
					printf("Ingresa el valor de la casilla [%d][%d]:",i, k);
					scanf("%d", &matriz[i][k]);
				}
			}
			
			printf("La matriz dada es: \n");
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			
			for(i=0;i<tamf;i++){
				for(k=0;k<tamc;k++){
					for(y=0;y<tamf;y++){
						for(z=0;z<tamc;z++){
							if(matriz[i][k]>matriz[y][z]){
								aux=matriz[i][k];
								matriz[i][k]=matriz[y][z];
								matriz[y][z]=aux;
							}
						}
					}
				}
			}
			
			printf("La matriz ordenada mayor a menor es: \n");
			for(i=0;i<tamf;i++)
			{
				for(k=0;k<tamc;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			system("pause");
			continue;
		}
		case 8:{
			
			system("cls");
			
			int i=0,k=0,n=0;
			
			printf("Elegiste opcion 8\n");
			
			printf("\nIngresa valor de la matriz nxn : ");
			scanf("%d", &n);
	
			int matriz[n][n];
 
			
			for(i=0;i<n;i++){
				for(k=0;k<n;k++){
					if(i==k){
						matriz[i][k]=1;
					}	else{
						matriz[i][k]=0;
					}						
				}
			}
		
			
			printf("La matriz identidad nxn es: \n");
			for(i=0;i<n;i++)
			{
				for(k=0;k<n;k++)
				{
					printf("\t%d", matriz[i][k]);
				}
				printf("\n");
			}
			
			system("pause");
			continue;
		}
	}
}


	printf("Decidiste salir, hasta luego usuario");	
		
		
		
		
		
}


	
	
	
	
	