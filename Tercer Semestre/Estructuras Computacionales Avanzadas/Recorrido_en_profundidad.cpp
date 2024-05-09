/*Recorrido en profundidad

Roberto Cort�s Valero 	328892
*/
#include <bits/stdc++.h>

/*
0 1 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 1 0 0
1 0 0 0 0 1 1
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
*/

using namespace std;

//Se utiliza para saber si ya se visitaron todos los nodos o v�rtices del vector
bool todosVisitados(bool v[], int n){
	for (int x = 0; x < n; x++){
		if (v[x] == false){
			return false;
		}
	}
	return true;
}

int main(){
	srand(time(NULL));

	cout << " ***RECORRIDO EN PROFUNDIDAD***" << endl;
	cout << "Introduce la cantidad de nodos: ";
	int n; cin >> n;

	//Declaraci�n de variables: Matriz de adyacencias, vector de visitados y pila
	bool ady[n][n] = {};
	bool visitado[n] = {};
	//stack es el tipo de variable de una pila, entre <> se pone el tipo de valor a almacenar
	stack <int> pila;

	cout << "Introduce su matriz de adyacencia: " << endl;

	// Llenamos la matriz de adyacencia
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << " Ingresa la conexion de nodos [" << x << "][" << y << "]: ";
			cin >> ady[x][y];
		}
		cout << endl;
	}

	//Se declara una variable del nodo inicial, se pide al usuario y se imprime en pantalla,
	//adem�s se marca como visitado
	int inicio;
	cout << endl;
	do{
		cout << " Indica el nodo inicial: "; 
		cin >> inicio;
	}while(inicio < 0 || inicio >= n);
	cout << " Recorrido: " << inicio;
	visitado[inicio] = true;

	do{
		for (int x = 0; x < n; x++){
			//Si hay conexi�n entre el nodo inicial y los dem�s nodos que no han sido visitados
			//Se ingresa ese nodo a la pila
			if (ady[inicio][x] == 1 && visitado[x] == false){
				visitado[x] = true;
				pila.push(x);		
			}
		}
		//Si no est� vac�a
		if(!pila.empty()){
			//El inicio se hace el nodo de la cima de la pila y se imprime en pantalla, adem�s se saca de la pila
			inicio = pila.top();
			cout << " -> " << pila.top();
			pila.pop();
		}
		else{ //Si est� vac�a, significa que no puede seguir recorriendo, por lo que se sale del ciclo
			break;
		}
		
	//Se repetir� mientras no se hayan visitado a�n todos o la pila no est� vac�a
	} while(!todosVisitados(visitado, n) || !pila.empty()); 
	//Si no se visitaron todos
	if(!todosVisitados(visitado, n)){
		cout << endl << " No hay camino que recorra todos los nodos desde el nodo inicial" << endl;
	}
	
	cout << "\n";
	// Mostramos la matriz de adyacencia.
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << ady[x][y];
		}
		cout << endl;
	}
}
