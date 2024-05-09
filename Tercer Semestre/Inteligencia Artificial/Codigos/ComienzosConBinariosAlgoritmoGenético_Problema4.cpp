/*COMIENZOS CON BINARIOS DE AG - Problema 4
	Realizar un programa que genere
	aleatoriamente 10 cadenas de 10 bits (unos y
	ceros) cada cadena, y que en una segunda
	lista genere al azar el intercambio del la
	primer cadena con la ultima cadena
	generando dos nuevas cadenas y poner asi las
	6 cadenas nuevas mezclando 3 parejas
	de individuos aleatorios.
	- El cruce sera desde un bit aleatorio
	- Primera generacion aleatoria, segunda ordenada de mejor a peor
	
	Usar MUTACION en cada generacion a partir de la 2a. con
	las siguientes restricciones:
		-> Generar un valor aleatorio para los 5 ultimos individuos, y solo
		elegir el 20% (2) individuos o cromosomas.
		-> Generar para cada individuo seleccionado un porcentaje entre
		10% a 40%, para elegir con su porcentaje el cambio (mutacion) del bit
		(0 cambia a 1, 1 cambia a 0); si es 10%, mutar un bit; si es 20%, mutar 
		2 bits; si es 30%, 3 bits; si es 40%, 4 bits.
		-> Elegir al azar los puntos o bits a mutar.
		-> Volver a ordenar y repetir la accion para cada generacion
	*/
	
#include<bits/stdc++.h>
using namespace std;

#define BITS 10
#define TOTAL_POB 10
#define GENERACIONES 250

//Estructura de cada individuo que guarde la cadena y la cantidad de ceros
struct poblacion
{
	//10 primeras posiciones para los padres, las siguientes para los hijos
	//columna 11 para el total de 0's
	int cad[TOTAL_POB+6][BITS+1];
};

//Prototipos
void creacion(poblacion &pob);
void sexo2(poblacion &pob);
void imprimir(poblacion &pob);
void seleccion(poblacion &pob, int padre1, int padre2, int hijos);
void ordenar(poblacion &pob);
void mutar(poblacion &pob);
 
int main()
{
	cout << " \t***ALGORITMO GENETICO***" << endl;
	srand(time(NULL)); //semilla aleatoria
	//Se crea la generacion
	poblacion pob;
	//Variable para saber si se encontro un individuo de 10 ceros
	bool continuar = true;
	//Se crea la generacion 1 y se muestra en pantalla
	cout << " \t - GENERACION 1 -" << endl;
	creacion(pob);
	imprimir(pob);
	system("pause");
	cout << endl;
	//Se muestran las siguientes generaciones, llevando a cabo el proceso de cruza y de seleccion hasta encontrar un individuo de 10 ceros
	for(int i = 1; i < GENERACIONES && continuar; i++){
		sexo2(pob);
		ordenar(pob);
		mutar(pob);
		ordenar(pob);
		
		cout << " \t - GENERACION " << i + 1 << " -" << endl;
		imprimir(pob);
		
		cout << endl;
		//Una vez que los 10 individuos sean de 10 ceros (el ultimo individuo tendra 10 ceros), se termina el ciclo de 250 generaciones
		if(pob.cad[TOTAL_POB-1][10] == 10){
			cout << " Todos los individuos son de 10 ceros" << endl;
			continuar = false;
		}
	}
		
	return 0;
}

//Creacion de la primera generacion
void creacion(poblacion &pob)
{
	int ceros;
	//Se llenan con bits aleatorios
	for(int i = 0; i < TOTAL_POB; i++){
		ceros = 0;
		for(int j = 0; j < BITS; j++){
			pob.cad[i][j] = rand()%2; //aleatorio entre 0 y 1
			if(pob.cad[i][j] == 0){
				ceros++;
			}
		}
		//Guarda la cantidad de ceros que contiene el individuo
		pob.cad[i][10] = ceros;
	}
}
//Cruzamiento 
void sexo2(poblacion &pob)
{
	int bit; //Bit del que se partira
	//set es una especie de vector que almacena diferentes valores ordenados
	//Se usara para verificar si se repiten o no los padres
	set <int> usados; 
	usados.clear(); //Se limpia para cada vez que se llame
	int padre1, padre2; //Variables que almacenan posicion de los padres
	int hijos; //Variable que alamcena la posicion de los hijos
	int ceros1, ceros2; //Variable que almacena 0's
	for(int i = 0; i < 3; i++){
		bit = 1 + rand()%9; //particion entre 1 y 9
		hijos = 10 + (i * 2); //Posicion de los hijos en la matriz
		//Se inicializan en 0 las variables que cuentan 0's
		ceros1 = 0;
		ceros2 = 0;
		//Se calcula la posicion de los padres
		do{
			padre1 = rand()%10; //Posicion entre 0 y 9
		}while(usados.count(padre1)); //La funcion count devuelve 0 o 1 si se encuentra o no en el set, asi se verifica si ya se selecciono
		usados.insert(padre1);
		do{
			padre2 = rand()%10; //Posicion entre 0 y 9
		}while(usados.count(padre2)); //La funcion count devuelve 0 o 1 si se encuentra o no en el set, asi se verifica si ya se selecciono
		usados.insert(padre2);
		
		//Cruzamiento y creacion de los hijos
		for(int x = 0; x < bit; x++){ //Primera partici�n de los bits
			pob.cad[hijos][x] = pob.cad[padre1][x];
			if(pob.cad[hijos][x] == 0) ceros1++; //suma ceros al primer hijo
			pob.cad[hijos+1][x] = pob.cad[padre2][x];
			if(pob.cad[hijos+1][x] == 0) ceros2++; //suma ceros al segundo hijo
		}
		for(int y = bit; y < BITS; y++){ //segunda particion de los bits
			pob.cad[hijos][y] = pob.cad[padre2][y];
			if(pob.cad[hijos][y] == 0) ceros1++;
			pob.cad[hijos+1][y] = pob.cad[padre1][y];
			if(pob.cad[hijos+1][y] == 0) ceros2++;
		}
		//Se almacenan los ceros
		pob.cad[hijos][10] = ceros1;
		pob.cad[hijos+1][10] = ceros2;
		//Seleccionar los dos mejores de entre los padres e hijos
		seleccion(pob, padre1, padre2, hijos);
	}
}
//Imprimir la generacion
void imprimir(poblacion &pob)
{
	cout << "    \tIndividuo:\tCeros:" << endl;
	for(int i = 0; i < TOTAL_POB; i++){
		cout << " " << i +1 << ".\t";
		for(int j = 0; j < BITS; j++){
			cout << pob.cad[i][j]; 
		}
		cout << "\t" << pob.cad[i][10] << endl;
	}
	
}
//Seleccionar los dos mejores de entre el par de padres e hijos
void seleccion(poblacion &pob, int padre1, int padre2, int hijos)
{
	//Se intercambian los valores en caso de ser mayores en el lugar de los padres
	for(int y = hijos; y < hijos + 2; y++){
		//Si el hijo es mayor que el padre 1, se intercambian de lugar
		if(pob.cad[y][10] > pob.cad[padre1][10]){ 
			for(int x = 0; x < BITS + 1; x++)
				swap(pob.cad[y][x], pob.cad[padre1][x]);
		}
		//Si el hijo es mayor que el padre 2, se intercambian de lugar
		if(pob.cad[y][10] > pob.cad[padre2][10]){ 
			for(int x = 0; x < BITS + 1; x++)
				swap(pob.cad[y][x], pob.cad[padre2][x]);
		}
	}
}
//Ordenar de mayor a menor a los 10 individuos que quedaron
void ordenar(poblacion &pob)
{
	//Variables para almacenar el que tenga mas ceros y su posicion
	int mayor, pos;
	for(int i = 0; i < TOTAL_POB; i++){
		//Se almacena en la variable auxiliar el valor mayor
		mayor = pob.cad[i][10];
		pos = i;
		for(int j = i + 1; j < TOTAL_POB; j++){
			//Si el siguiente es mayor al anterior, se cambia la variable auxiliar
			//hasta recorrer todos y encontrar el mayor, guardando su posicion
			if(pob.cad[j][10] > mayor){
				mayor = pob.cad[j][10];
				pos = j;
			}
		}
		//Se intercambian de lugares para que el que contenga mas ceros quede primero
		for(int x = 0; x < BITS + 1; x++)
			swap(pob.cad[i][x], pob.cad[pos][x]);
	}
}
//Mutacion
void mutar(poblacion &pob)
{
	//Para verificar que no se repitan los individuos y sus bits que cambiaran
	set <int> individuos;
	individuos.clear();
	set <int> bits;
	bits.clear();
	//Variables de individuos y bits
	int indSeleccionado, cantBits, bitSeleccionado;
	//Variable que verificara que los ultimos 5 individuos no tengan 10 ceros,
	// y que solo se tomen 2 de los 5 o menos, si hay 4 o mas con 10 ceros
	int cantidad = 2;
	//Si el penultimo es igual a 10, ya que estan ordenados, quiere decir que solo se mutara el ultimo
	//en caso de que tenga menos de 10 ceros
	if (pob.cad[8][10] == 10) cantidad--;
	//Si el ultimo individuo tiene 10 ceros, no se mutara ningun individuo
	if (pob.cad[9][10] == 10) cantidad--;
	for(int i = 0; i < cantidad; i++){
		do{
			indSeleccionado = 5 + rand()%(10 - 5); //Se selecciona un individuo entre 5 y 9 (los ultimos 5)
		}while(individuos.count(indSeleccionado) || pob.cad[indSeleccionado][10] == 10); //Verifica si se encuentra ya en el set o que no tenga 10 ceros
		individuos.insert(indSeleccionado);
		//Se genera el total de bits a mutar, entre 1 y 4
		cantBits = 1 + rand()%(5 - 1);
		
		//Se mutan la cantidad de bits
		for(int j = 0; j < cantBits; j++){
			do{
				bitSeleccionado = rand()%10; //Se selecciona un bit entre 0 y 9
			}while(bits.count(bitSeleccionado)); //Verifica si se encuentra ya en el set
			bits.insert(bitSeleccionado);
			//Si es igual a 1 cambia a 0, si es igual a 0 cambia a 1, y se cambia el contador de 0's
			if(pob.cad[indSeleccionado][bitSeleccionado] == 1){
				pob.cad[indSeleccionado][bitSeleccionado] = 0;
				pob.cad[indSeleccionado][10]++;
			}	
			else{
				pob.cad[indSeleccionado][bitSeleccionado] = 1;
				pob.cad[indSeleccionado][10]--;
			}
		}
		//Se limpia el set para el siguiente individuo
		bits.clear(); 
	}
}
