/* 
Cesar Eduardo Elias del Hoyo
Ximena Rivera Delgadillo
Jos� Luis Sandoval P�rez
UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
Inteligenia Artificial
Maestro: Alejandro Padilla Diaz
3er Semestre
2ndo Parcial
   
   ALGORITMO GENETICO (Mutacion)
   
   De acuerdo a las �ltimas restricciones, solicitadas del cruzamiento en el que se debieron de elegir 6 al azar en cada generaci�n y realizar 
   el cruce de cada par de padres y en el mismo momento de cada para de padres e hijos, regresar los dos mejores a las posiciones de los padres, 
   realizar la mutaci�n DE ACUERDO A LO QUE SE SOLICITA:

	DESPU�S DE ORDENAR EN LA PRIMER GENERACI�N USANDO CRUZAMIENTO, SE LE AGREGAR� EN CADA GENERACI�N UNA MUTACI�N, COMO SIGUE:

		a) Tomando como restricci�n los �ltimos 5 individuos, elegir 2 individuos al azar, que ser�a equivalente al 20% de la poblaci�n.
		b) Generar para cada individuo seleccionado (de los dos), un porcentaje del 10 al 40%, para elegir con su porcentaje el cambio(mutaci�n) 
			del bit( 0 cambia a 1, � 1 cambia a 0); si se gener�

     			10% mutar 1 bit al azar
     			20% mutar 2 bit al azar
     			30% mutar 3 bit al azar
     			40% mutar 4 bit al azar

		c) Elegir al azar los puntos o bits a mutar, de acuerdo al porcentaje del punto b
		d) Volver a ordenar y repetir la acci�n para cada generaci�n
*/

// JOSE: FALTA MODIFICAR LA SELECCION DE LA CADENA A MUTAR, QUE NO SE SELECCIONE LAS CADENAS DONDE YA SE TIENE 10 BITS 0 
// COMPROBAR QUE SI SE HAGA UNICAMENTE UN INTERCAMBIO LLEGANDO A 9 CADENAS 0 
// VERIFICAR QUE SI SE COMPLETEN LAS 10 CADENAS CON CEROS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int g=1;

using namespace std;

int main (){

	
	for(int vu=1;vu<=2;vu++){
		// Variables numericas
		g=0;
		int i,j,k,c,m,sep,pA,pa,aux,mut1,mut2,per,m1,m2,m3,m4,M1,M2,M3,M4,v,fin,fm;
		// Vector de variables aletorias (padres aleatorios)
		int p[6];
		// Matrices para generar los individuos 
		int ga[11][11];
		int gt[4][11];
		
		// Generar la primera generacion con individuos aleatorias (primera matriz)
		srand(time(NULL));
		for (i=0; i<10; i++){
			for (j=0; j<10; j++){
				if ((rand()%100)+1 <= 50) {
					ga[i][j]=0;
				} else {
					ga[i][j]=1;
				}
			}
		}
		
		cout << " --- INICIO DEL PROGRAMA ---\n ALGORITMO GENETICO\n\n";
		cout << " Realizar un algoritmo genetico que, a partir de una matriz aleatoria de 0 y 1, comience a mutar haciendo intercambios";
		cout << "\n entre las cadenas de individuos, ordenados de mayor a menor (segun la cantidad de ceros), donde se intercambien 3 ";
		cout << "\n pares de cadenas aleatorias y, a partir de los intercambios obtenidos, obtener una nueva generacion de individuos";
		cout << "\n El programa cuando se encuentre una cadena de 10 bits 0 o, por el contrario, al realizar 250 generaciones distintas";
		cout << "\n --------------------------------------------------------------------------------------------------------------- \n";
		
		g=1;
		
		
	// CICLO DE 250 GENERACIONES (A MENOS QUE SE OBTENGA LA CADENA DE 10 BITS CEROS
		do {
			cout << "\n GENERACION " << g; 
			cout << "\n\n";
			
			c=0;
			
			// Contador de ceros
			for (i=0; i<10; i++){
				for (j=0; j<10; j++){
					if (ga[i][j]==0){
						c++;
					}
				}
				ga[i][10]=c;
				c=0;
			}

		
		// IMPRIMIR MATRIZ 
			for (i=0; i<10; i++){
				for (j=0; j<10; j++){
					cout << " " << ga[i][j] ;
				}
				cout << "   " << ga[i][10];
				cout << "\n";
			}

			fin = 0;
		// COMPROBAR SI EL ALGORITMO ESTA TERMINADO
			for (i=0; i<10; i++){
				if (ga[i][10] == 10){
					fin++;
				}
			}
			cout <<"\n "<<fin;
			if (fin == 10){
				cout << "\n\n GENERACION MAXIMA COMPLETADA \n FIN DEL PROGRAMA \n ";
				
				break;
			}
			
			// Seleccionar una separacion para mezclar las cadenas
			srand(time(NULL));
			sep = (rand()%(8-2+1))+2;
			//cout << "\n\n Numero de separacion para mezcla ---> " << sep;
			
			// Asignamos valores iniciales para comenzar con la mezcla
			c=0;
			m=0;
			for (i=0; i<6; i++){
				p[i]=0;
			}
		// MEZCLA DE LOS INDIVIDUOS DE CADA PAR DE CADENAS	
			if (fin<9){
				v=3;
			}else{
				v=1;	
			}
			
			for (int x=0; x<v; x++){
			// OBTENER CADENAS ALEATORIAS PARA MEZCLAR	
				// CADENA 1 (pA)
				if (fin < 9){
					pA=0;
					srand(time(NULL));
					do{
						pA=(1+rand()%(11-1));
					}
					while (pA==p[0] || pA==p[1] || pA==p[2] || pA==p[3] || pA==p[4] || pA==p[5]);
				}else{
					pA = 10;
				}
				p[m]=pA;
				m++;
				
				// CADENA 2 (pa)
				pa=0;
				srand(time(NULL));
				do{
					pa=(1+rand()%(11-1));
				}
				while (pa==p[0] || pa==p[1] || pa==p[2] || pa==p[3] || pa==p[4] || pa==p[5]);
				p[m]=pa;
				m++;
						
				// Numero de intercambio
				//cout << "\n\n --------------- INTERCAMBIO " <<x+1<< " ---------------\n";
				
			// PRIMERA MEZCLA 
				for (j=0; j<sep; j++){
					gt[0][j]=ga[pA-1][j];
					if (gt[0][j]==0){
						c++;
					}
				}
					
				for (j=sep; j<10; j++){
					gt[0][j]=ga[pa-1][j];
					if (gt[0][j]==0){
						c++;
					}
				}
					
				// Numero de ceros del hijo 1 resultante
				gt[0][10]=c;
				
				
				c=0;	
					
			// SEGUNDA MEZCLA
				for (j=0; j<sep; j++){
					gt[1][j]=ga[pa-1][j];
					if (gt[1][j]==0){
						c++;
					}
				}
				
				for (j=sep; j<10; j++){
					gt[1][j]=ga[pA-1][j];
					if (gt[1][j]==0){
						c++;
					}
				}
					
				// Numero de ceros del hijo 2 resultante
				gt[1][10]=c;
					
			
			
				// Colocar padres en el arreglo gt (temporal) para compararlos con los hijos
				for (j=0; j<11; j++){
					gt[2][j]=ga[pA-1][j];
					gt[3][j]=ga[pa-1][j];
				}
			
			// COMPARAR PADRES E HIJOS PARA DETERMINAR CON CUAL CADENAS DE INDIVIDUOS QUEDARSE (Metodo de la burbuja para ordenarlos de mejor a peor)
				for (i=0; i<4; i++){
					for (j=0; j<3; j++){
						if (gt[j][10]<gt[j+1][10]){
							for (k=0; k<10; k++){
								aux=gt[j][k];
								gt[j][k]=gt[j+1][k];
								gt[j+1][k]=aux;
							}
							aux=gt[j][10];
							gt[j][10]=gt[j+1][10];
							gt[j+1][10]=aux;
						}
					}
				}
						
		// CAMBIAR LAS 2 MEJORES CADENAS EN LA POSICION DE LOS PADRES ORIGINALES
				for (i=0; i<11; i++){
					ga[pA-1][i]=gt[0][i];
					ga[pa-1][i]=gt[1][i];
				}
			
				c=0;
				
			}// Fin ciclo de cruce y cambio
		
			
		// ORDENAR MATRIZ DE MEJOR A PEOR (De acuerdo a la cantidad de 0 en cada cadena)
			// METODO DE LA BURBUJA
			for (i=0; i<10; i++){
				for (j=0; j<9; j++){
					if (ga[j][10]<ga[j+1][10]){
						for (k=0; k<10; k++){
							aux=ga[j][k];
							ga[j][k]=ga[j+1][k];
							ga[j+1][k]=aux;
						}
						aux=ga[j][10];
						ga[j][10]=ga[j+1][10];
						ga[j+1][10]=aux;
					}
				}
			}
			
			fin = 0;
			// SUMAR NUEVAMENTE LAS CADENAS CON CEROS
			for (i=0; i<10; i++){
				if (ga[i][10] == 10){
					fin++;
				}
			}
			
	// NUEVO PARAMETRO --- MUTACION DE LOS INDIVIDUOS DE UNA (LAS) CADENA(S) DE CARACTERES
			if (fin < 9){ // CONDICIONAL PARA DEJAR DE MUTAR CUANDO FIN LLEGUE A 9
			
			
		// OBTENER PORCENTAJE SELECCIONADO 	
			per=((rand()%(4-1+1))+1);
				
		// ELECCION DE CADENAS A MUTAR
			mut1=0;
			mut2=0;
			srand(time(NULL));
			do{
				mut1=((rand()%(10-6+1))+6);
			}
			while (mut1 <= fin);
			
			do{
				mut2=((rand()%(10-6+1))+6);
			}
			while (mut1 == mut2 || mut2 <= fin);
			
		
		// SELECCIONAR BITS DE LAS CADENAS SELECCIONADAS
			m1=0;m2=0;m3=0;m4=0;
			M1=0;M2=0;M3=0;M4=0;
		//	cout<< "\n------------------------------------------------------------------------------------------------\n";
			switch(per){
		/*10%*/	case 1:
					m1=(1+rand()%(11-1));
					//cout << "BIT MUTACION 1 ---> "<<m1;
					M1=(1+rand()%(11-1));
					//cout << "\nBIT MUTACION 2 ---> "<<M1;
					break;
		/*20%*/	case 2:
					m1=(1+rand()%(11-1));
					do{
						m2=(1+rand()%(11-1));
					}
					while (m1 == m2);
					//cout << "BITS MUTACION 1 ---> "<<m1<<"-"<<m2;
					M1=(1+rand()%(11-1));
					do{
						M2=(1+rand()%(11-1));
					}
					while (M1 == M2);
					//cout << "\nBITS MUTACION 2 ---> "<<M1<<"-"<<M2;
					break;
		/*30%*/	case 3:
					m1=(1+rand()%(11-1));
					do{
						m2=(1+rand()%(11-1));
					}
					while (m1 == m2);
					do{
						m3=(1+rand()%(11-1));
					}
					while (m1 == m2 || m1 == m3 || m2 == m3);
					//cout << "BITS MUTACION 1 ---> "<<m1<<"-"<<m2<<"-"<<m3;
					M1=(1+rand()%(11-1));
					do{
						M2=(1+rand()%(11-1));
					}
					while (M1 == M2);
					do{
						M3=(1+rand()%(11-1));
					}
					while (M1 == M2 || M1 == M3 || M2 == M3);
					//cout << "\nBITS MUTACION 2 ---> "<<M1<<"-"<<M2<<"-"<<M3;
					break;
		/*40%*/	case 4:
					m1=(1+rand()%(11-1));
					do{
						m2=(1+rand()%(11-1));
					}
					while (m1 == m2);
					do{
						m3=(1+rand()%(11-1));
					}
					while (m1 == m2 || m1 == m3 || m2 == m3);
					do{
						m4=(1+rand()%(11-1));
					}
					while (m1 == m2 || m1 == m3 || m1 == m4 || m2 == m3 || m2 == m4 || m3 == m4);
					//cout << "BITS MUTACION 1 ---> "<<m1<<"-"<<m2<<"-"<<m3<<"-"<<m4;
					M1=(1+rand()%(11-1));
					do{
						M2=(1+rand()%(11-1));
					}
					while (M1 == M2);
					do{
						M3=(1+rand()%(11-1));
					}
					while (M1 == M2 || M1 == M3 || M2 == M3);
					do{
						M4=(1+rand()%(11-1));
					}
					while (M1 == M2 || M1 == M3 || M1 == M4 || M2 == M3 || M2 == M4 || M3 == M4);
					//out << "\nBITS MUTACION 2 ---> "<<M1<<"-"<<M2<<"-"<<M3<<"-"<<M4;
					break;
		/*SM*/	default: cout << "NO HAY MUTACION ("<<per<<"0%)";
			}
			
		// REALIZAR MUTACIONES
			if (per < 5){
		/*10%*/	if (per>=1){
					// Individuo 1
					if (ga[mut1-1][m1-1] == 0){
						ga[mut1-1][m1-1] = 1;
					}else{
						ga[mut1-1][m1-1] = 0;
					}
					// Individuo 2
					if (fin < 9){
						if (ga[mut2-1][M1-1] == 0){
							ga[mut2-1][M1-1] = 1;
						}else{
							ga[mut2-1][M1-1] = 0;
						}	
					}
				}
				
		/*20%*/	if (per>=2){
					// Individuo 1
					if (ga[mut1-1][m2-1] == 0){
						ga[mut1-1][m2-1] = 1;
					}else{
						ga[mut1-1][m2-1] = 0;
					}
					// Individuo 2
					if (fin < 9){
						if (ga[mut2-1][M2-1] == 0){
							ga[mut2-1][M2-1] = 1;
						}else{
							ga[mut2-1][M2-1] = 0;
						}	
					}
				} 
				
		/*30%*/	if (per>=3){
					// Individuo 1
					if (ga[mut1-1][m3-1] == 0){
						ga[mut1-1][m3-1] = 1;
					}else{
						ga[mut1-1][m3-1] = 0;
					}
					// Individuo 2
					if (fin < 9){
						if (ga[mut2-1][M3-1] == 0){
							ga[mut2-1][M3-1] = 1;
						}else{
							ga[mut2-1][M3-1] = 0;
						}	
					}
				}
				
		/*40%*/	if (per=4){
					// Individuo 1
					if (ga[mut1-1][m4-1] == 0){
						ga[mut1-1][m4-1] = 1;
					}else{
						ga[mut1-1][m4-1] = 0;
					}
					// Individuo 2
					if (fin < 9){
						if (ga[mut2-1][M4-1] == 0){
							ga[mut2-1][M4-1] = 1;
						}else{
							ga[mut2-1][M4-1] = 0;
						}	
					}
				}	
			}
			
			c=0;
			
			// Contador de ceros
			for (i=0; i<10; i++){
				for (j=0; j<10; j++){
					if (ga[i][j]==0){
						c++;
					}
				}
				ga[i][10]=c;
				c=0;
			}
			
			
		}
			
			// ORDENAR LA MATRIZ PREVIO A IMPRIMIR LA SIGUIENTE GENERACION
			// METODO DE LA BURBUJA
			for (i=0; i<10; i++){
				for (j=0; j<9; j++){
					if (ga[j][10]<ga[j+1][10]){
						for (k=0; k<10; k++){
							aux=ga[j][k];
							ga[j][k]=ga[j+1][k];
							ga[j+1][k]=aux;
						}
						aux=ga[j][10];
						ga[j][10]=ga[j+1][10];
						ga[j+1][10]=aux;
					}
				}
			}
			
			cout <<" \n\n ---------------------------------------------------------------------------------------------\n";
			
		}while (g<=250);	

		cout<<"Corrida: "<<vu<<endl;

		
	}

}		

