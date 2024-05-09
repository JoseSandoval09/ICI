/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	Problema de las 8 reinas
	Consiste en la creaci�n de un tablero de ajedrez en donde se tenga 8 reinas y ninguna de ellas se pueda matar a otra
	Para este problema, usaremos el Algoritmo Gen�tico como base para la creaci�n de los espacios del tablero y obtener
	los cromosomas de manera binaria
	
*/	

// Librer�as 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

// DEFINE
#define BITS 10
#define REPETICIONES 100
#define REPHIJOS 50
#define POBLACIONES 100


// STRUCT
struct poblacion{ 
	int filCol[BITS][BITS];
	int fitness;
	string cromosoma[BITS];
	int cromDec[BITS];
};
struct poblacion ind[REPETICIONES];
struct poblacion hijos[REPHIJOS];


// VARIABLES GLOBALES
int h,i,j,corridas,ps,pA,pa,b,tm,rm,bm,solucion;

// FUNCIONES PRINCIPALES
void ppr(poblacion[],int); // MATRIZ INICIAL
void crm(poblacion[],int,int); // OBTENER EL CROMOSOMA PARA CADA INDIVIDUO
void fit(poblacion[],int,int); // OBTENER EL FITNESS DE CADA INDIVIDUO
void ord(poblacion[],int); // ORDENAR DE MENOR A MAYOR CHOQUES
void imp(poblacion[],int,int); // IMPRIMIR INDIVIDUOS
void impF(poblacion[],int,int); // IMPRIMIR CROMOSOMAS 
bool fin(int); // COMPROBAR SI EXISTE UNA SOLUCION
void elm(poblacion[],int); // ELIMINAR PEORES 50 INDIVIDUOS
void mi(poblacion[],poblacion[],int,int,int); // MEZCLAR INDIVIDUOS
void ah(poblacion[],poblacion[],int); // A�ADIR HIJOS
void mut(poblacion[],int,int,int); // MUTACIONES



int main(){
	int end=0;
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE ENCONTRAR UNA SOLUCION AL PROBLEMA DE LAS 8 REINAS CON AYUDA DEL ALGORITMO GENETICO \n\n";
		cout << " Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Algoritmo Genetico (Problema de las 8 reinas) \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: 
				system("cls");
				cout<<" ALGORITMO GENETICO \n";
				corridas=0;
				srand(time(NULL));
				// PRIMERA POBLACION
				ppr(ind,REPETICIONES); // Genero la primera poblaci�n
				solucion=0;
				// ALGORITMO GENETICO
				do{
						cout<<"---------------------------------------------------\n";
						cout<<" POBLACION "<<corridas+1<<"\n";
						crm(ind,REPETICIONES,0); // Obtengo el cromosoma
						fit(ind,REPETICIONES,0); // Obtengo el fitness
						for(i=0; i<REPETICIONES; i++){ // Ciclo para ordenar individuos
							ord(ind,REPETICIONES); 
						}	
						elm(ind,REPETICIONES);
						//imp(ind,(REPETICIONES/2),0);
						cout<<" PRIMEROS 5 CROMOSOMAS \n\n";
						impF(ind,5,0); // IMPRIMIR PRIMEROS 
						//imp(ind,5,0);
						// COMPROBAR SI SE ENCUENTRA UNA SOLUCION
						if(ind[0].fitness == 0){
							corridas=POBLACIONES;
						}else{
							corridas++;
						}
						// MEZCLAS
						pA=0;
						pa=49;
						b=0;
						for (int x=0; x<25; x++){
							mi(ind,hijos,pA,pa,b); // Funci�n para mezclar los bits (pA-pa)
							mi(ind,hijos,pa,pA,b+1); // Funci�n para mezclar los bits (pa-pA)
							pA++;
							pa--;
							b+=2;
						}
						//cout<<" \n\n HIJOS: \n";
						//imp(hijos,REPHIJOS,0);
						//system("pause");
						//system("cls");
						//cout<<" \n\n HIJOS SIN ORDENAR";
						ah(ind,hijos,REPETICIONES); // A�adir hijos a la matriz padre
						ord(ind,REPETICIONES);
						//imp(ind,5,0);
						// MUTACION
						srand(time(NULL));
						tm=(rand()%100);
						rm=(rand()%8);
						do{
							bm=(rand()%8);
						}while(bm==rm);
						cout<<"\n INDIVIDUO ANTES DE MUTAR: "<<tm<<" \n";
						cout<<" CORONA A MUTAR: "<<rm<<" \n";
						impF(ind,tm+1,tm);
						cout<<"\n INDIVIDUO MUTADO: "<<tm<<"\n";
						//cout<<"\n ANTES DE MUTAR \n";
						//imp(ind,(4+1),4);
						mut(ind,tm,rm,bm);
						//cout<<"\n DESPUES DE MUTAR \n";
						//imp(ind,(4+1),4);
						
			}while(corridas<POBLACIONES); // Final de la poblaci�n
			if(ind[0].fitness == 0){
				cout<<" SOLUCION NO ENCONTRADA\n NUMERO DE POBLACIONES REALIZADAS: "<<corridas<<"\n\n";
			}else{
				solucion=corridas;
				cout<<"\n\n--------------------------------------------------------------\n";
				cout<<" SOLUCION ENCONTRADA\n POBLACION: "<<solucion<<" \n\n CROMOSOMA: ";
				for(i=0; i<8; i++){
					cout<<ind[solucion].cromosoma[i]<<" ";
				}
				cout<< " \n FITNESS: "<< ind[solucion].fitness;
			}
			system("pause");
			break;
		case 2: 
			system("cls");
			end=2;
			break;
		default: system("cls"); cout << " OPCION INVALIDA"; break;
		}
	}while (end != 2);
	cout << " Saliendo del programa ... Hasta luego \n\n";
	return 0;
}

void ppr(poblacion first[], int rep){ // CREAR PRIMERA POBLACION DE INDIVIDUOS (TABLEROS)
	// Llenar tablero con ceros
	for (h=0; h<rep; h++){
		for (i=0; i<8; i++){
			for (j=0; j<8; j++){
				first[h].filCol[i][j]=0;
			}
		}
	}
	
	// Colocar una reina (1) en cada columna
	for (h=0; h<rep; h++){
		for (j=0; j<8; j++){
			i=rand()%8;
			first[h].filCol[i][j]=1;
		}
	}
}

void crm(poblacion cro[], int rep, int mutacion){ // OBTENER EL CROMOSOMA DE CADA INDIVIDUO
	for (h=mutacion; h<rep; h++){
		for (j=0; j<8; j++){ 
			cro[h].cromDec[j]=0;
			cro[h].cromosoma[j]="";
		}
	}
	
	
	// Obtener la posici�n de la reina para cada columna (decimal)
	for (h=mutacion; h<rep; h++){
		for (j=0; j<8; j++){ 
			cro[h].cromosoma[j]="";
			for (i=0; i<8; i++){
				if(cro[h].filCol[i][j]==1){
					cro[h].cromDec[j]=i; //Guardando valores del cromosoma en decimal 
					switch(i){
						case 0: cro[h].cromosoma[j] = "000 "; break;
						case 1: cro[h].cromosoma[j] = "001 "; break;
						case 2: cro[h].cromosoma[j] = "010 "; break;
						case 3: cro[h].cromosoma[j] = "011 "; break;
						case 4: cro[h].cromosoma[j] = "100 "; break;
						case 5: cro[h].cromosoma[j] = "101 "; break;
						case 6: cro[h].cromosoma[j] = "110 "; break;
						case 7: cro[h].cromosoma[j] = "111 "; break;
					}
				}
			}
		}
	}
	
	
}

void fit(poblacion indF[], int rep, int mutacion){ // OBTENER EL FITNESS (CHOQUES POR INDIVIDUO)
	int fila[BITS], dDes[BITS], dAsc[BITS]; // Vectores para comprobar choques
	// LIMPIAR FITNESS
	for (h=mutacion; h<rep; h++){
		indF[h].fitness=0;
	}
	
	
	for (h=mutacion; h<rep; h++){
		// PRIMERO ASIGNO LA POSICI�N DE CADA REINA
		for (j=0; j<8; j++){
			for (i=0; i<8; i++){
				if(indF[h].filCol[i][j]==1){
					// FILA
					fila[j]=i;
					// DIAGONAL IZQUIERDA
					dDes[j]=i+j;
					// DIAGONAL DERECHA
					dAsc[j]=i-j;
				}
			}
		}
		
		// DESPU�S, COMPRUEBO LOS CHOQUES QUE EXISTEN	
		indF[h].fitness=0;
		for (j=0; j<8; j++){
			// Comprobar choques por fila
			for (i=0; i<8; i++){
				if(fila[j] == fila[i] && j != i){
					indF[h].fitness+=1;
				}
			}
			
			// Comprobar choques por diagonales
			for (i=0; i<8; i++){
				if(dDes[j] == dDes[i] && j != i){
					indF[h].fitness+=1;
				}
			}
			for (i=0; i<8; i++){
				if(dAsc[j] == dAsc[i] && j != i){
					indF[h].fitness+=1;
				}
			}
		}
	}
	
	// OBTENER FITNESS SIN DUPLICAR
	for(h=0; h<rep; h++){
		indF[h].fitness/=2;
	}
}

void ord(poblacion orden[], int rep){ // ORDENAR INDIVIDUOS
	int aux=0,auxF=0;
	string auxC="";
	for (h=0; h<(rep-1); h++){
		// Ordenar individuos
		if(orden[h].fitness>orden[h+1].fitness){
			for (i=0; i<8; i++){
				for (j=0; j<8; j++){
					aux=orden[h].filCol[i][j];
					orden[h].filCol[i][j]=orden[h+1].filCol[i][j];
					orden[h+1].filCol[i][j]=aux;
				}
				// Ordenar cromosoma
				auxC=orden[h].cromosoma[i];
				orden[h].cromosoma[i]=orden[h+1].cromosoma[i];
				orden[h+1].cromosoma[i]=auxC;
			}
			// Ordenar fitness
			auxF=orden[h].fitness;
			orden[h].fitness=orden[h+1].fitness;
			orden[h+1].fitness=auxF;
		}
	}
}

void elm(poblacion eliminar[], int rep){ // ELIMINAR 50 PEORES INDIVIDUOS
	for (h=(rep/2); h<rep; h++){
		for (i=0; i<8; i++){
			for (j=0; j<8; j++){
				eliminar[h].filCol[i][j]=0;	
			}
			eliminar[h].cromosoma[i] = "";
		}
		eliminar[h].fitness=0;
	}
}

void imp(poblacion imprimir[],int rep, int mutacion){ // IMPRIMIR INDIVIDUOS
	for (h=mutacion; h<rep; h++){
		cout << " INDIVIDUO " << h+1 << "\n";
		for (i=0; i<8; i++){
			for (j=0; j<8; j++){
				cout << " " << imprimir[h].filCol[i][j];
			}
			cout << "\n";
		}
		
		// IMPRIMIR EL CROMOSOMA Y FITNESS DE CADA TABLERO (INDIVIDUO)
		cout<<"CROMOSOMA: ";
		for(i=0; i<8; i++){
			cout<<imprimir[h].cromosoma[i]<<" ";
		}
		cout<<"\nFITNESS: "<<imprimir[h].fitness;
		cout << "\n\n";
	}
}

void impF(poblacion imprimirCF[], int rep, int mutacion){ // IMPRIMIR CROMOSOMAS
	for(h=mutacion; h<rep; h++){
		cout<<"CROMOSOMA: ";
		for(i=0; i<8; i++){
			cout<<imprimirCF[h].cromosoma[i]<<" ";
		}
		cout<<"\nFITNESS: "<<imprimirCF[h].fitness;
		cout << "\n\n";
	}
}

bool fin(int end){ // COMPROBAR SI SE ENCONTRO UNA SOLUCION
	if(ind[end].fitness == 0){
		return true;
	}else{
		return false;
	}
}

void mi(poblacion padre[],poblacion hijo[],int p1,int p2,int posc){ // MEZCLAR INDIVIDUOS
	ps = 4; // Punto de separaci�n (mitad de la cadena de bits)
	for(i=0; i<8; i++){
		hijo[posc].cromosoma[i]="";
	}
	// MEZCLA PRIMEROS 12 BITS (pA)
	for(j=0; j<ps; j++){
		hijo[posc].cromosoma[j] = padre[p1].cromosoma[j];
	}
	// A�ADIR pA EN LA MATRIZ HIJO
	for (j=0;j<ps;j++){
		for(i=0;i<8;i++){
			hijo[posc].filCol[i][j] = padre[p1].filCol[i][j];
		}
	}
	
	// MEZCLA ULTIMOS 12 BITS (pa)
	for(j=ps; j<8; j++){
		hijo[posc].cromosoma[j] = padre[p2].cromosoma[j];
	}
	// A�ADIR pa EN LA MATRIZ HIJO
	for (j=ps;j<8;j++){
		for(i=0;i<8;i++){
			hijo[posc].filCol[i][j] = padre[p2].filCol[i][j];
		}
	}
	fit(hijo,(REPETICIONES/2),0); // Obtengo el fitness
}

void ah(poblacion padre[],poblacion hijo[], int rep){ // A�ADIR HJIJOS A LA POBLACION 
	int y=0;
	for (h=(rep/2); h<rep; h++){
		for (i=0; i<8; i++){
			for (j=0; j<8; j++){
				padre[h].filCol[i][j]=hijo[y].filCol[i][j];
			}
			padre[h].cromosoma[i]=hijo[y].cromosoma[i];
		}
		padre[h].fitness=hijo[y].fitness;
		y++;
	}
}

void mut(poblacion mutar[], int individuo) {
    // Clonar el individuo original
    poblacion copiaIndividuo = mutar[individuo];

    // Elegir aleatoriamente una reina y una posición de bit para mutar
    int reina = rand() % 8;
    int bit = rand() % 8;

    // ENCONTRAR LA COLUMNA DE LA REINA
    for (int i = 0; i < 8; i++) {
        if (mutar[individuo].filCol[i][reina] == 1) {
            mutar[individuo].filCol[i][reina] = 0;
        }
    }

    // COLOCAR CORONA MUTADA
    mutar[individuo].filCol[bit][reina] = 1;

    // OBTENER EL FITNESS Y CROMOSOMA NUEVO
    fit(mutar, individuo, 0);
    crm(mutar, individuo, 0);

    // Comprobar si la mutación empeora el fitness
    if (mutar[individuo].fitness > copiaIndividuo.fitness) {
        // Si la mutación empeora el fitness, restaurar el individuo original
        mutar[individuo] = copiaIndividuo;
    }
}
