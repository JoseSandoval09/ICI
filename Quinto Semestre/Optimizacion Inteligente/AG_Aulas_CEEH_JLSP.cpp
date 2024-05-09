/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	PROYECTO FINAL 
	
	Algoritmo Gen�tico para la asignaci�n de aulas en la universidad
	
	Este algoritmo busca generar una gerramienta capaz de realizar un asignaci�n de
	aulas para las diferentes asignaturas de manera que se puedan distribuir
	correctamente sin que los cursos, aulas u horarios choquen entre s�
	
	Se busca proponer un sistema que reduzca el tiempo de respuesta a unos cuantos
	segundos, y que adem�s encuentre una soluci�n �ptima en la mayor�a de las
	pruebas realizadas.
*/	

// LIBRERIAS 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

// DEFINE
#define BITS 8
#define INDIVIDUOS 100
#define CURSOS 30
#define GRUPOS 5
#define POBLACIONES 1000

// STRUCT
struct poblacion{
	string ind[CURSOS][BITS];
	int aptitud;
	string cromosoma[CURSOS];
};
struct poblacion padres[INDIVIDUOS];
struct poblacion elite[INDIVIDUOS];

// FUNCIONES PRINCIPALES
void ppa(poblacion[],int); // POBLACION INICIAL
void apt(poblacion[],int,int); // OBTENER EL NUMERO DE CHOQUES 
void crm(poblacion[],int,int); // OBTENER EL CROMOSOMA
void imp(poblacion[],int,int); // IMPRIMIR POBLACION
void impA(poblacion[],int,int); // IMPRIMIR CHOQUES Y CROMOSOMA
void ord(poblacion[],int); // ORDENAR POBLACION DE MENOS A MAS CHOQUES
void elm(poblacion[],int); // ELIMINAR PEORES 50 INDIVIDUOS
void mi(poblacion[],poblacion[],int,int,int); // MEZCLAR INDIVIDUOS
void ah(poblacion[],poblacion[],int); // A�ADIR HIJOS
void mut(poblacion[],int,int,int,int,int,int,int,int); // MUTACION

// VARIABLES GLOBALES
int sol,corridas,h,i,j,k,random,a1,a2,a3,pA,pa,b,ps,in,cur,m1,m2,m3,m4,m5,m6;

// CROMOSOMA
// #1 ID del curso
string idCurso[30] = {
	{"LC1-1"},{"FEC-2"},{"CD-3"},{"AS-4"},{"CB-5"},{"LC3-6"},{"ECA-7"},{"IA-8"},{"AL-9"},{"EDP-10"},
	{"RB-11"},{"OI-12"},{"AU-13"},{"AID-14"},{"LI-15"},{"ED-16"},{"BD-17"},{"AU2-18"},{"DMD-19"},{"MH-20"},
	{"ESI-21"},{"PI-22"},{"LE-23"},{"RE1-24"},{"TSI-25"},{"SI1-26"},{"SW-27"},{"PA-28"},{"SIS-29"},{"MD-30"},
};

// #2 Grupo
string grupo[5] = {
	{"1a"},{"3a"},{"5a"},{"7a"},{"9a"}
};

// #3 Primer d�a
string pDia[3] = {
	{"Lunes"},{"Martes"},{"Miercoles"}
};

// #4 Hora primer d�a
string horapDia[7] = {
	{"7:00"},{"8:00"},{"9:00"},{"10:00"},{"11:00"},{"12:00"},{"13:00"}
};

// #5 Ultimo d�a
string uDia[2] = {
	{"Jueves"},{"Viernes"}
};

// #6 Hora ultimo dia
string horauDia[7] = {
	{"7:00"},{"8:00"},{"9:00"},{"10:00"},{"11:00"},{"12:00"},{"13:00"}
};

// #7 tipo de aula
string aula[3] = {
	{"AULA"},{"LAB"},{"AUD"}
};

// #8 ID del aula
string idAula[9] = {
	{"54 A"},{"54 C"},{"54 F"},{"54 G"},{"54 H"},{"61 LAB"},{"203 LAB"},{"204 LAB"},{"1 AUD"}
};

// FUNCION MAIN
int main (){
		int end=0;
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE ENCONTRAR UNA SOLUCION AL PROBLEMA DE LA ASIGNACION DE AULAS CON AYUDA DEL ALGORITMO GENETICO \n\n";
		cout << " *** PROYECTO FINAL *** \n\n Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona la accion que deseas realizar \n\n 1. Algoritmo Genetico (Aulas) \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: 
				system("cls");
				cout<<" ALGORITMO GENETICO \n";
				// PRIMER POBLACION
				corridas=0;
				srand(time(NULL));
				ppa(padres,INDIVIDUOS); // Generar la primera poblacion
				sol=0;
				// ALGORITMO GENETICO
				do{
					cout<<"---------------------------------------------------\n";
					cout<<" ----- POBLACION "<<corridas+1<<" -----\n";
					crm(padres,INDIVIDUOS,0); // Vaciar cromosoma
					apt(padres,INDIVIDUOS,0); // Obtener numero de choques y cromosoma
					for(int r=0; r<INDIVIDUOS; r++){ // Ciclo para ordenar individuos
						ord(padres,INDIVIDUOS); 
					}
					elm(padres,INDIVIDUOS); // Eliminar 50 peores individuos
					impA(padres,2,0); // Imprimir primera generacion ordenada
					
					// COMPROBAR SI SE ENCUENTRA UNA SOLUCION
					if(padres[0].aptitud == 0){
						sol=corridas+1;
						corridas=POBLACIONES;
					}else{
						corridas++;
					}
					// MEZCLAS
						pA=0;
						pa=49;
						b=0;
						for (int x=0; x<25; x++){
							mi(padres,elite,pA,pa,b); // Funcion para mezclar los bits (pA-pa)
							mi(padres,elite,pa,pA,b+1); // Funcion para mezclar los bits (pa-pA)
							pA++;
							pa--;
							b+=2;
						}
					cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
						ah(padres,elite,INDIVIDUOS); // A?adir hijos a la matriz padre
						
						// MUTACION
						in=(rand()%100);
						cur=(rand()%30);
						m1=(rand()%3);
						m2=(rand()%7);
						m3=(rand()%2);
						m4=(rand()%7);
						m5=(rand()%3);
						m6=(rand()%9);
						mut(padres,in,cur,m1,m2,m3,m4,m5,m6);
				}while(corridas<POBLACIONES); // Final de la poblacion
				if(sol!=0){
					cout<<"--------------------------------------------------------------\n";
					cout<<" SOLUCION ENCONTRADA\n POBLACION: "<<sol;
					cout<<"\n\n HORARIO OBTENIDO: \n\n";
					imp(padres,1,0);
					cout<<"\n\n--------------------------------------------------------------\n";
				}else{
					cout<<"--------------------------------------------------------------\n";
					cout<<" SOLUCION NO ENCONTRADA\n NUMERO DE POBLACIONES REALIZADAS: "<<corridas;
					cout<<"\n--------------------------------------------------------------\n";
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

// CREAR LA PRIMERA POBLACION DE INDIVIDUOS
void ppa(poblacion inicial[], int rep){
	for (h=0; h<rep; h++){
		for (i=0; i<CURSOS; i++){
			for (j=0; j<BITS; j++){
				switch(j+1){
					case 1: // ID DEL CURSO
						inicial[h].ind[i][j] = idCurso[i];
						break;
					case 2: // GRUPO
						if (i<5){
							inicial[h].ind[i][j] = grupo[0];
						}else{
							if (i<11){
								inicial[h].ind[i][j] = grupo[1];
							}else{
								if (i<17){
									inicial[h].ind[i][j] = grupo[2];
								}else{
									if (i<24){
										inicial[h].ind[i][j] = grupo[3];
									}else{
										inicial[h].ind[i][j] = grupo[4];
									}
								}
							}
						}
						break;
					case 3: // PRIMER DIA 
						random=rand()%3;
						inicial[h].ind[i][j] = pDia[random];
						break;
					case 4: // HORA DEL PRIMER DIA
						random=rand()%7;
						inicial[h].ind[i][j] = horapDia[random];
						break;
					case 5: // ULTIMO DIA
						random=rand()%2;
						inicial[h].ind[i][j] = uDia[random];
						break;
					case 6: // HORA DEL ULTIMO DIA
						random=rand()%7;
						inicial[h].ind[i][j] = horauDia[random];
						break;
					case 7: // TIPO DE AULA
						random=rand()%3;
						inicial[h].ind[i][j] = aula[random];
						break;
					case 8: // ID DEL AULA
						random=rand()%9;
						inicial[h].ind[i][j] = idAula[random];
						break;
				}
			}
		}
	}
}

// OBTENER EL NUMERO DE CHOQUES POR INDIVIDUO
void apt(poblacion choques[], int rep, int mut){
	// Limpiar aptitud
	for (h=mut; h<rep; h++){
		choques[h].aptitud = 0;
	}
	
	for (h=mut; h<rep; h++){
		a1=0;
		a2=0;
		a3=0;
		for (i=0; i<CURSOS; i++){
// Choque Tipo #1 - Aula no corresponde a tipo de aula
			// Auditorio
			if (choques[h].ind[i][6] == "AUD"){
				if (choques[h].ind[i][7] != "1 AUD"){
					a1+=1; // Actualizar Choques
					choques[h].cromosoma[i] = "1"; // Actualizar cromosoma
				}
			}
			// Laboratorio
			if (choques[h].ind[i][6] == "LAB"){
				if(choques[h].ind[i][7] != "61 LAB" 
				&& choques[h].ind[i][7] != "203 LAB" 
				&& choques[h].ind[i][7] != "204 LAB"){
					a1+=1; // Actualizar Choques
					choques[h].cromosoma[i] = "1"; // Actualizar cromosoma
				}
			}
			// Aula		
			if (choques[h].ind[i][6] == "AULA"){
				if(choques[h].ind[i][7] != "54 A" 
				&& choques[h].ind[i][7] != "54 C" 
				&& choques[h].ind[i][7] != "54 F"
				&& choques[h].ind[i][7] != "54 G"
				&& choques[h].ind[i][7] != "54 H"){
					a1+=1; // Actualizar Choques
					choques[h].cromosoma[i] = "1"; // Actualizar cromosoma
				}
			}
			
// Choque # 2 - Mismo grupo, mismo dia, mismo horario
			for (j=0; j<CURSOS; j++){
				if(i != j){
					// Primer d�a
					if (choques[h].ind[i][1] == choques[h].ind[j][1]
						&& choques[h].ind[i][2] == choques[h].ind[j][2]
						&& choques[h].ind[i][3] == choques[h].ind[j][3]){	
						a2+=1; // Actualizar Choques
					}
					// Ultimo d�a
					if (choques[h].ind[i][1] == choques[h].ind[j][1]
						&& choques[h].ind[i][4] == choques[h].ind[j][4]
						&& choques[h].ind[i][5] == choques[h].ind[j][5]){
						a2+=1; // Actualizar Choques
					}
				}
			}
			
// Choque # 3 - Diferente grupo, mismo dia, mismo horario, mismo aula
			for (j=0; j<CURSOS; j++){
				if(i != j){
					// Primer dia
					if (choques[h].ind[i][1] != choques[h].ind[j][1]
						&& choques[h].ind[i][2] == choques[h].ind[j][2]
						&& choques[h].ind[i][3] == choques[h].ind[j][3]
						&& choques[h].ind[i][7] == choques[h].ind[j][7]){
						a3+=1; // Actualizar Choques
					}
					
					// Ultimo dia
					if (choques[h].ind[i][1] != choques[h].ind[j][1]
						&& choques[h].ind[i][4] == choques[h].ind[j][4]
						&& choques[h].ind[i][5] == choques[h].ind[j][5]
						&& choques[h].ind[i][7] == choques[h].ind[j][7]){
						a3+=1; // Actualizar Choques
					}
				}
			}
			
			// NUMERO TOTAL DE CHOQUES
			choques[h].aptitud = a1 + (a2/2) + (a3/2);
		}
	}
}

// VACIAR EL CROMOSOMA DEL INDIVIDUO
void crm(poblacion crom[], int rep, int mut){
	for (h=mut; h<rep; h++){
		for (i=0; i<CURSOS; i++){
			crom[h].cromosoma[i] = "0";
		}
	}
}

// IMPRIMIR PRIMERA POBLACION
void imp(poblacion imprimir[], int rep, int mut){
	// IMPRIMIR POBLACION
	for (h=mut; h<rep; h++){
		cout << "\n ***** INDIVIDUO "<< h+1 << " ***** \n";
		for (i=0; i<CURSOS; i++){
			for (j=0; j<BITS; j++){
				cout << imprimir[h].ind[i][j];
				// Imprimir espacios para generar tabla esteticamente visual
				int longitud = 0;
				longitud = imprimir[h].ind[i][j].length();
				do{
					cout << " ";
					longitud++;
				}while(longitud < 12);
			}
			cout << "\n";
		}
		cout<<"\nCROMOSOMA: ";
		for(i=0; i<CURSOS; i++){
			cout<<imprimir[h].cromosoma[i];
		}
		cout<<"\nCHOQUES TOTALES: "<<imprimir[h].aptitud;
		cout << "\n\n";
	}
}

// IMPRIMIR CHOQUES Y CROMOSOMA
void impA(poblacion imprimir[], int rep, int mut){
	for(h=mut; h<rep; h++){
		cout << "\n ***** INDIVIDUO "<< h+1 << " ***** \n";
		cout<<"\nCROMOSOMA: ";
		for(i=0; i<CURSOS; i++){
			cout<<imprimir[h].cromosoma[i];
		}
		cout<<"\nCHOQUES TOTALES: "<<imprimir[h].aptitud;
		cout << "\n\n";
	}
}

// ORDENAR INDIVIDUOS CON MENOS CHOQUES
void ord(poblacion orden[], int rep){
	int auxA=0;
	string aux="",auxC="";
	for (h=0; h<(rep-1); h++){
		// Ordenar individuos
		if(orden[h].aptitud > orden[h+1].aptitud){
			for (i=0; i<CURSOS; i++){
				for (j=0; j<BITS; j++){
					aux=orden[h].ind[i][j];
					orden[h].ind[i][j]=orden[h+1].ind[i][j];
					orden[h+1].ind[i][j]=aux;
				}
				// Ordenar cromosoma
				auxC=orden[h].cromosoma[i];
				orden[h].cromosoma[i]=orden[h+1].cromosoma[i];
				orden[h+1].cromosoma[i]=auxC;
			}
			// Ordenar aptitud (choques)
			auxA=orden[h].aptitud;
			orden[h].aptitud=orden[h+1].aptitud;
			orden[h+1].aptitud=auxA;
		}
	}
}

// ELIMINAR 50 PEORES INDIVIDUOS 
void elm(poblacion eliminar[], int rep){ 
	for (h=(rep/2); h<rep; h++){
		for (i=0; i<CURSOS; i++){
			for (j=0; j<BITS; j++){
				eliminar[h].ind[i][j]="";	
			}
			eliminar[h].cromosoma[i] = "";
		}
		eliminar[h].aptitud=0;
	}
}

// MEZCLAR INDIVIDUOS
void mi(poblacion padre[],poblacion hijo[],int p1,int p2,int posc){ 
	ps = 15; // Punto de separaci?n (mitad de la cadena de bits)
	// A�ADIR CURSOS A LA MATRIZ HIJO
	for (h=0; h<INDIVIDUOS; h++){
		for (i=0; i<CURSOS; i++){
			hijo[h].ind[i][0] = idCurso[i];
			if (i<5){
				hijo[h].ind[i][1] = grupo[0];
			}else{
				if (i<11){
					hijo[h].ind[i][1] = grupo[1];
				}else{
					if (i<17){
						hijo[h].ind[i][1] = grupo[2];
					}else{
						if (i<24){
							hijo[h].ind[i][1] = grupo[3];
						}else{
							hijo[h].ind[i][1] = grupo[4];
						}
					}
				}
			}	
		}
	}
	
	// MEZCLAR pA EN LA MATRIZ HIJO
	for (i=0; i<CURSOS; i++){
		hijo[posc].ind[i][2] = padre[p1].ind[i][2];
		hijo[posc].ind[i][4] = padre[p1].ind[i][4];
		hijo[posc].ind[i][6] = padre[p1].ind[i][6];
	}
	
	// MEZCLAR pa EN LA MATRIZ HIJO
	for (i=0; i<CURSOS; i++){
		hijo[posc].ind[i][3] = padre[p2].ind[i][3];
		hijo[posc].ind[i][5] = padre[p2].ind[i][5];
		hijo[posc].ind[i][7] = padre[p2].ind[i][7];
	}
	
	crm(hijo,INDIVIDUOS,0); // Vaciar el cromosoma
	apt(hijo,(INDIVIDUOS/2),0); // Obtengo el fitness
}

// A?ADIR HJIJOS A LA POBLACION PADRE
void ah(poblacion padre[],poblacion hijo[], int rep){ 
	int y=0;
	for (h=(rep/2); h<rep; h++){
		for (i=0; i<CURSOS; i++){
			for (j=0; j<BITS; j++){
				padre[h].ind[i][j]=hijo[y].ind[i][j];
			}
			padre[h].cromosoma[i]=hijo[y].cromosoma[i];
		}
		padre[h].aptitud=hijo[y].aptitud;
		y++;
	}
}

// MUTAR UN CURSO DE UN INDIVIDUO
void mut(poblacion mutar[],int individuo, int cursel, int l1, int l2, int l3, int l4, int l5, int l6){
	// COLOCAR CURSO MUTADO
	mutar[individuo].ind[cursel][2] = pDia[l1];
	mutar[individuo].ind[cursel][3] = horapDia[l2];
	mutar[individuo].ind[cursel][4] = uDia[l3];
	mutar[individuo].ind[cursel][5] = horauDia[l4];
	mutar[individuo].ind[cursel][6] = aula[l5];
	mutar[individuo].ind[cursel][7] = idAula[l6];
	
	// OBTENER EL FITNESS Y CROMOSOMA NUEVO
	crm(mutar,individuo+1,individuo);
	apt(mutar,individuo+1,individuo);
}
