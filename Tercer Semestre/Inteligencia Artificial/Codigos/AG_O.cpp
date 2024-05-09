/*
Objetivo: Omar Villalobos Rodriguez 315374
Hecho por: Comparar 10 vectores de 0 y 1
Carrera: Ingenieria en computacion Inteligente Semestre 3
*/

//Librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//funcion principal
int main(){
	
	//Variables
	int i,j,k,x,generacion=1,random,cero,index,mayor;
	int corte,inicio,final;
	
	//creamos los numeros 
	int numeros[11][11];	
	int aux[11][11];
	
	//Limpiamos los numeros
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			numeros[i][j]=0;
			aux[i][j] = 0;
		}
	}
	
	//Rellenar con Random
	srand(time(NULL));
	for(i=0;i<11;i++){
		for(j=0;j<10;j++){
			if ((rand()%100)+1 <= 50) {
				numeros[i][j]=0;
			} else {
				numeros[i][j]=1;
			}
		}
	}
	
	//Ciclo principal del programa Generaciones
	do{
		
		//Contamos la cantidad de 0 de cada linea
		for(i=0;i<11;i++){
			cero = 0;
			for(j=0;j<10;j++){
				if(numeros[i][j]==0){
					cero++;
				}
			}
			numeros[i][10]=cero;
		}
		
		if(numeros[0][10]==10){ //Si se logro encontrar el numero con puros 0
			//Mostramos la matriz
			cout<<endl<<"=== GENERACION DE 0 ENCONTRADA "<<generacion<<" ==="<<endl<<endl;
			for(i=0;i<11;i++){
				for(j=0;j<11;j++){
					cout<<numeros[i][j];
				}
				cout<<"   Numero de 0: "<<numeros[i][10]<<endl;
			}
			system("pause");
		}
		else{ //Si se hace otra generacion
			//Ordebamos la matriz de mayor numero de 0 a menor
			x=0;
			index=0;
			while(x<11){
				mayor=0;
				//buscamos el numero mayor
				for(i=0;i<11;i++){
					if(numeros[i][10]>mayor){
						mayor = numeros[i][10];
						index = i;
					}
				}
			
				//hacemos un intercambio ordenado a una matriz auxiliar
				for(k=0;k<11;k++){
					aux[x][k]=numeros[index][k];
				}
				//aumentamos el x 
				x++; 
				numeros[index][10]=0;
			}
			
			//Creada la matriz aux ordenada
			for(i=0;i<11;i++){
				for(j=0;j<11;j++){
					numeros[i][j] = aux [i][j];
				}
			}
			
			
			//Mostramos la matriz
			cout<<endl<<"=== GENERACION "<<generacion<<" ==="<<endl<<endl;
			for(i=0;i<11;i++){
				for(j=0;j<11;j++){
					cout<<numeros[i][j];
				}
				cout<<"   Numero de 0: "<<numeros[i][10]<<endl;
			}
			system("pause");
			
			//Hacemos los cambios 
			//obtenemos otro numero random
			corte = (rand()%6)+1;
			inicio = 0;
			final = 10;
			int temp[corte];
			int temp2[corte];
			while(inicio<6){
				
				//Cortamos la linea y la guardamos en un vector
				for(i=corte;i<10;i++){
					temp[i]=numeros[inicio][i];
				}
				for(i=corte;i<10;i++){
					temp2[i]=numeros[final][i];
				}
				//intercambiamos las lineas
				for(i=corte;i<10;i++){
					numeros[inicio][i]=temp2[i];
				}
				for(i=corte;i<10;i++){
					numeros[final][i]=temp[i];
				}
				
				inicio++;
				final--;
			}
			generacion++;
		}
		
	}while(generacion<11||numeros[0][10]==10);//Fin de generaciones
	
	return 0;	
}//Fin del programa