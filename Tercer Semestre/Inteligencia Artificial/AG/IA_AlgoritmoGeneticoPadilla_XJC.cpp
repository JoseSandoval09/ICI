#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// DEFINE
#define GENERACIONES 250
#define REPETICIONES 1000
#define BITS 11

// STRUCT
struct poblacion{
	int bits [BITS];
	int ceros;
};
struct poblacion fila [BITS];
struct poblacion hijos [4];
struct poblacion mM [2];

// VARIABLE GLOBALES
int i,j,k,g,v,sep,mut1,mut2,per,fin,m1,m2,m3,m4,corridas;
int resultados[REPETICIONES];

// FUNCIONES PRINCIPALES 
void inicio();
void mi(poblacion[]); // MATRIZ INICIAL
void im(poblacion[],int); // IMPRIMIR MATRIZ
void im_mut(poblacion[],int,int,int); // IMPRIMIR MATRIZ DESPUES DE MUTACION
void cc(poblacion[]); // CONTADOR DE CEROS
void nc(poblacion[]); // CONTADOR DE CADENAS MAXIMAS 
bool fa(); // FIN DEL ALGORITMO
void cam(poblacion[],int,int); // CADENAS A MEZCLAR
void mc(poblacion[],poblacion[],int,int,int); // MEZCLAR CADENAS
void cpd(poblacion[],poblacion[],int,int,int); // COMPARAR PADRES E HIJOS
void om(poblacion[],int,int); // ORDENAR MATRIZ (BUBBLE METHOD)
void caM(); // CADENAS A MUTAR
void bm(poblacion[],int,int,int); // BITS A MUTAR
void mut(poblacion[],poblacion[],int,int,int); // MUTACIONES

// MATRIZ INICIAL
// IMPRIMIR MATRIZ
// CONTAR CEROS
// COMPROBAR SI EL ALGORITMO ESTA COMPLETO
// OBTENER CADENAS A MEZCLAR
// MEZCLAR CADENAS
// COMPARAR PADRES E HIJOS 
// REMPLAZAR LOS DOS MEJORES EN EL LUGAR DE LOS PADRES
// ORDENAR MATRIZ
// OBTENER CADENAS A MODIFICAR
// OBTENER BITS A MUTAR
// MUTAR


int main(){
	int y;
	int corridas=0;
	do{ // CICLO DE 1000 REPETICIONES
	srand(time(NULL));
	inicio(); // Indicaciones del inicio del programa
	mi(fila); // Primera matriz de 0 y 1 aleatorios
	g=1;
		 do{ // CICLO DE GENERACIONES 
			cout << "\n GENERACION " << g; 
			cout << "\n\n";
			cc(fila); // Contador de ceros
			im(fila,10); // Imprimir la primera matriz
			fin=0;
			nc(fila); // Comprobar cantidad de 0 
			cout <<"\n "<<fin;
			if (fa() == true){ // Comprobar si se llego al total de 0
				break;
			}else{
				g++;	
			}
			
			sep = (rand()%(8-2+1))+2; // Numero de separacion para mezclar bits
			cout << "\n\n Numero de separacion para mezcla ---> " << sep;
			if (fin<9){// CONDICIONAL QUE COMPRUEBA SI FIN = 9
				v=3;
			}else{
				v=1;	
			}
			y=0;
			for (int x=0; x<v; x++){// CICLO PARA REALIZAR MEZCLAS
				cam(fila,y+x,x);
				y++;
			}
			om(fila,10,9);// Ordena matriz despues de los cruces
			cout <<" \n\n ---------------------------------------------------------------------------------------------\n";
			cout << " --- PRESIONA ENTER PARA REALIZAR MUTACION ---\n";
			system ("pause");
			system ("cls");
			fin=0;
			nc(fila);
			if (fin < 9){ // CICLO PARA REALIZAR MUTACION 
				cout<<"\n\nMATRIZ ORDENADA PREVIA A LA MUTACION\n\n";	
				im(fila,10); // Imprimir matriz ordenada
				per=((rand()%(4-1+1))+1); // Porcentaje a mutar
				cout <<" \n\n ---------------------------------------------------------------------------------------------\n";
				cout<<"Porcentaje para realizar la mutacion ---> "<<per;
				caM(); // Seleccionar cadenas para mutar
				y=0;
				bm(mM,0,per,y); // Bits a mutar cadena 1
				bm(mM,1,per,y+1); // Bits a mutar cadena 2
				mut(fila,mM,0,mut1,per); // Mutaciones cadena 1
				mut(fila,mM,1,mut2,per); // Mutaciones cadena 2
				cc(fila);
				cout <<" \n\n ---------------------------------------------------------------------------------------------\n";
				cout<<"MATRIZ SIN ORDENAR DESPUES DE LA MUTACION \n\n";
				im_mut(fila,10,mut1,mut2);
				cout <<" \n\n ---------------------------------------------------------------------------------------------\n";
				cout << " --- PRESIONA ENTER PARA IMPRIMIR SIGUIENTE GENERACION ---\n";
				system ("pause");
				system ("cls");
			} // FIN DEL CICLO DE LA MUTACION

			om(fila,10,9);

		}while (g<GENERACIONES); // FIN DEL CICLO DE GENERACIONES
		cout<<"\n\n---------Corrida: "<<corridas+1<<"-----------";
		cout<<"Numero de generaciones:"<<g<<"\n";
		resultados[corridas] = g;
		corridas++;
		cout << "\n\n --- PRESIONA ENTER PARA IMPRIMIR SIGUIENTE CORRIDA ---\n";
		system("pause");
		system("cls");
		
	}while (corridas<REPETICIONES); // FIN DEL CICLO DE REPETICIONES

	system("cls");
	cout<< "RESULTADOS DE LAS CORRIDAS: \n\n";
	for (i=0; i<REPETICIONES; i++){ // Impresion en una lista con comas
		cout << resultados[i];
		if (i+1 != REPETICIONES){
			cout << ",";
		}else{
			cout << "\n\n";
		}
	}
	for (i=0; i<REPETICIONES; i++){ // Impresion en una lista ordenada
		cout<<" ["<<i+1<<"] ---> "<<resultados[i]<<"\n";
	}

	return 0;
}

void inicio (){ // INTRUCCIONES INICIALES
	cout << " --- INICIO DEL PROGRAMA ---\n ALGORITMO GENETICO\n\n";
	cout << " Realizar un algoritmo genetico que, a partir de una matriz aleatoria de 0 y 1, comience a mutar haciendo intercambios";
	cout << "\n entre las cadenas de individuos, ordenados de mayor a menor (segun la cantidad de ceros), donde se intercambien 3 ";
	cout << "\n pares de cadenas aleatorias y, a partir de los intercambios obtenidos, obtener una nueva generacion de individuos";
	cout << "\n El programa cuando se encuentre una cadena de 10 bits 0 o, por el contrario, al realizar 250 generaciones distintas";
	cout << "\n --------------------------------------------------------------------------------------------------------------- \n";
}

void mi(poblacion cadena[]){ // MATRIZ INICIAL (UNICAMENTE EN LA PRIMERA GENERACION)
	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			if ((rand()%100)+1 <= 50) {
				cadena[i].bits[j]=0;
			} else {
				cadena[i].bits[j]=1;
			}
		}
	}
}

void cc(poblacion cadena[]){ // CONTADOR DE CEROS
	cadena[i].ceros=0;
	for (i=0; i<10; i++){
		for (j=0; j<10; j++){
			if (cadena[i].bits[j]==0){
				cadena[i].ceros++;
			}
		}
		cadena[i].bits[10]=cadena[i].ceros;
		cadena[i].ceros=0;
	}
}

void im (poblacion cadena[],int lim){ // IMPRIMIR LA MATRIZ
	for (i=0; i<lim; i++){
		for (j=0; j<10; j++){
				cout << " " << cadena[i].bits[j] ;
		}
		cout << "   " << cadena[i].bits[10];
		cout << "\n";
	}
}

void im_mut(poblacion cadena[],int lim,int mutacion1,int mutacion2){
	for (i=0; i<lim; i++){
		for (j=0; j<10; j++){
				cout << " " << cadena[i].bits[j] ;
		}
		cout << "   " << cadena[i].bits[10];
		if (i == mutacion1-1){
			cout<<"   <--- Mutacion 1";	
		}
		if (i == mutacion2-1){
			cout<<"   <--- Mutacion 2";	
		}
		cout << "\n";
	}
}

void nc(poblacion cadena[]){ // NUMERO DE CADENAS CON MAXIMO NUMERO DE CEROS
	for (i=0; i<10; i++){
		if (cadena[i].bits[10] == 10){
			fin++;
		}
	}
}

bool fa(){ // COMPROBAR SI EL ALGORITMO ESTA TERMINADO
	if (fin == 10){
		cout << "\n\n GENERACION MAXIMA COMPLETADA \n FIN DEL PROGRAMA \n ";
		return true;
	}else{
		return false;
	}
}

void cam (poblacion cadena[], int y, int x){ // OBTENER LAS CADENAS QUE MUTAREMOS
	int p[6]; // Vector de variables aletorias (padres aleatorios)
	int pA,pa;
	if (fin < 9){ // CADENA 1 (pA)
		pA=0;
		do{
			pA=(1+rand()%(11-1));
		}
		while (pA==p[0] || pA==p[1] || pA==p[2] || pA==p[3] || pA==p[4] || pA==p[5]);
	}else{
		pA = 10;
	}
	p[y]=pA;
	y++;
	pa=0;
	srand(time(NULL));
	do{ // CADENA 2 (pa)
		pa=(1+rand()%(11-1));
	}
	while (pa==p[0] || pa==p[1] || pa==p[2] || pa==p[3] || pa==p[4] || pa==p[5]);
	p[y]=pa;

	int b=0;
	cout << "\n\n --------------- INTERCAMBIO " <<x+1<< " ---------------\n";
	mc(fila,hijos,pA,pa,b); // Funcion para mezclar las bits (pA-pa)
	mc(fila,hijos,pa,pA,b+1); // Funcion para mezclar los bits (pa-pA)
	cpd(fila,hijos,pA,pa,b);
}

void mc (poblacion cadena[], poblacion comparar[],int n1, int n2, int posc){ // MEZCLAR CADENAS
	comparar[posc].ceros=0;
	for (j=0; j<sep; j++){ // MEZCLA <SEP
		comparar[posc].bits[j]=cadena[n1-1].bits[j];
		if (comparar[posc].bits[j]==0){
			comparar[posc].ceros++;
		}
	}
				
	for (j=sep; j<10; j++){ // MEZCLA >SEP
		comparar[posc].bits[j]=cadena[n2-1].bits[j];
		if (comparar[posc].bits[j]==0){
			comparar[posc].ceros++;
		}
	}

	comparar[posc].bits[10]=comparar[posc].ceros;
	if (posc==1){cout<<"\n\n";}
	cout << " Intercambio " << n1 << "-" << n2 << " \n";
	for (j=0; j<10; j++){ // NUMERO DE CEROS DEL HIJO RESULTANTE
		cout << comparar[posc].bits[j];
	}
	cout << "  " << comparar[posc].bits[10];
	comparar[posc].ceros=0;
}

void cpd (poblacion cadena[], poblacion comparar[],int n1, int n2, int posc){ // COMPARAR CADENAS
	for (j=0; j<11; j++){// Comparar los padres con los hijos 
		comparar[2].bits[j]=cadena[n1-1].bits[j];
		comparar[3].bits[j]=cadena[n2-1].bits[j];
	}
	om(hijos,4,3);// ORDENAR CADENAS DE HIJOS Y PADRES PARA TOMAR A LOS MEJORES
	cout<<"\n\n Matriz temporal ordenada (dos padres y dos hijos)\n";
	im(hijos,4); // MOSTRAR MATRIZ TEMPORAL
	
	for (i=0; i<11; i++){ // CAMBIAR LAS 2 MEJORES CADENAS EN LA POSICION DE LOS PADRES ORIGINALES		
		cadena[n1-1].bits[i]=comparar[posc].bits[i];
		cadena[n2-1].bits[i]=comparar[posc+1].bits[i];
	}
}

void om (poblacion ordenar[],int l1, int l2){ // ORDENAR MATRIZ
	int aux=0;
	for (i=0; i<l1; i++){
		for (j=0; j<l2; j++){
			if (ordenar[j].bits[10]<ordenar[j+1].bits[10]){
				for (k=0; k<10; k++){
					aux=ordenar[j].bits[k];
					ordenar[j].bits[k]=ordenar[j+1].bits[k];
					ordenar[j+1].bits[k]=aux;
				}
				aux=ordenar[j].bits[10];
				ordenar[j].bits[10]=ordenar[j+1].bits[10];
				ordenar[j+1].bits[10]=aux;
			}
		}
	}
}

void caM (){ // ELECCION DE LA CADENAS A MUTAR
	mut1=0;
	mut2=0;
	srand(time(NULL));
	do{ // PRIMERA CADENA
		mut1=((rand()%(10-6+1))+6);
	}
	while (mut1 <= fin);

	do{ // SEGUNDA CADENA
		mut2=((rand()%(10-6+1))+6);
	}
	while (mut1 == mut2 || mut2 <= fin);
	cout<< "\n------------------------------------------------------------------------------------------------\n";
	cout<<"Mutacion 1 en la cadena ---> "<<mut1<<endl;
	cout<<"Mutacion 2 en la cadena ---> "<<mut2;
	cout<< "\n------------------------------------------------------------------------------------------------";
}

void bm (poblacion b_mut[],int posc, int porcentaje, int x){ // ELECCION DE LOS BITS A MUTAR
	if (porcentaje >= 1){ /*10%*/
		b_mut[posc].bits[0]=(1+rand()%(11-1));
	}
	if (porcentaje >= 2){ /*20%*/
		do{
			b_mut[posc].bits[1]=(1+rand()%(11-1));
		}
		while (b_mut[posc].bits[0] == b_mut[posc].bits[1]);
	}
	if (porcentaje >= 3){ /*30%*/
		do{
			b_mut[posc].bits[2]=(1+rand()%(11-1));
		}
		while (b_mut[posc].bits[0] == b_mut[posc].bits[1] 
		|| b_mut[posc].bits[0] == b_mut[posc].bits[2] 
		|| b_mut[posc].bits[1] == b_mut[posc].bits[2]);

	}
	if (porcentaje >= 4){ /*40%*/
		do{
			b_mut[posc].bits[3]=(1+rand()%(11-1));
		}
		while (b_mut[posc].bits[0] == b_mut[posc].bits[1] || b_mut[posc].bits[0] == b_mut[posc].bits[2] 
		|| b_mut[posc].bits[0] == b_mut[posc].bits[3] || b_mut[posc].bits[1] == b_mut[posc].bits[2] 
		|| b_mut[posc].bits[1] == b_mut[posc].bits[3] || b_mut[posc].bits[2] == b_mut[posc].bits[3]);
	}

	cout << "\nBITS MUTACION "<< x+1 <<" ---> ";
	switch (porcentaje){ // Estetica (imprimir los bits a mutar)
		case 1: cout << b_mut[posc].bits[0]; break;
		case 2: cout << b_mut[posc].bits[0] <<"-"<< b_mut[posc].bits[1]; break;
		case 3: cout << b_mut[posc].bits[0] <<"-"<< b_mut[posc].bits[1] <<"-"<< b_mut[posc].bits[2];
			break;
		case 4: cout << b_mut[posc].bits[0] <<"-"<< b_mut[posc].bits[1] <<"-"<< b_mut[posc].bits[2] 
			<<"-"<< b_mut[posc].bits[3]; break;
			
	}
}

void mut (poblacion cadena[],poblacion mutacion[], int posc, int cadena_mutar, int porcentaje){ // MUTACIONES
	m1 = mutacion[posc].bits[0];
	m2 = mutacion[posc].bits[1];
	m3 = mutacion[posc].bits[2];
	m4 = mutacion[posc].bits[3];
	
	if (porcentaje>=1){ /*10%*/
		if (cadena[cadena_mutar-1].bits[m1-1] == 0){
			cadena[cadena_mutar-1].bits[m1-1] = 1;
		}else{
			cadena[cadena_mutar-1].bits[m1-1] = 0;
		}
	}
	if (porcentaje>=2){ /*20%*/
		if (cadena[cadena_mutar-1].bits[m2-1] == 0){
			cadena[cadena_mutar-1].bits[m2-1] = 1;
		}else{
			cadena[cadena_mutar-1].bits[m2-1] = 0;
		}
	}
	if (porcentaje>=3){ /*30%*/
		if (cadena[cadena_mutar-1].bits[m3-1] == 0){
			cadena[cadena_mutar-1].bits[m3-1] = 1;
		}else{
			cadena[cadena_mutar-1].bits[m3-1] = 0;
		}
	}
	if (porcentaje>=4){ /*40%*/
		if (cadena[cadena_mutar-1].bits[m4-1] == 0){
			cadena[cadena_mutar-1].bits[m4-1] = 1;
		}else{
			cadena[cadena_mutar-1].bits[m4-1] = 0;
		}
	}
}
