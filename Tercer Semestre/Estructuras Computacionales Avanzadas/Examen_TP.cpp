
#include <iostream>
#include <stdio.h>
#include <queue>
#include <time.h>
using namespace std;

/*Recorrido en anchura

Jose Luis Sandoval Perez 261731
El siguiente programa desplegara el recorrido de un grafo dirigido en anchura\n

*/

/*
	A B C D E
A 	0 1 0 1 0
B 	0 0 1 1 1
C 	0 0 0 0 1
D 	0 0 0 0 1
E 	0 0 0 1 0

*/
int n=5;


//Se utiliza para saber si ya se visitaron todos los nodos o v�rtices del vector
bool todosVisitados(bool vis[]){
	for (int x = 0; x < n; x++){
		if (vis[x] == false){
			return false;
		}
	}
	return true;
}

int main(){
	srand(time(NULL));

	cout << " ***RECORRIDO EN ANCHURA***\n " << endl;

	

	
	bool MA_ady[n][n] = {
        {0,1,0,1,0},
        {0,0,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,1,0},
    };
	bool visitado[n] = {};
	
	queue <int> cola;

	cout << " Matriz de adyacencia: " << endl;
    
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << MA_ady[x][y];
		}
		cout << endl;
	}

	
	int inicio=0;
	
	cout << " Recorrido: " << inicio;
	visitado[inicio] = true;
	
	do{
		for (int x = 0; x < n; x++){
			
			if (MA_ady[inicio][x] == 1 && visitado[x] == false){
				visitado[x] = true;
				cola.push(x);
			}
		}
		
		if(!cola.empty()){
			
			inicio = cola.front();
			cout << " -> " << cola.front();
			cola.pop();
		}
		else{ 
			break;
		}
		

	} while(!todosVisitados(visitado) || !cola.empty()); 
	
	if(!todosVisitados(visitado)){
		cout << endl << " No hay camino que recorra todos los nodos desde el nodo inicial" << endl;
	}

	cout << "\n";
    
    bool vis[n] = {1,0,0,0};

    int AT[n][n] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}};

    

    cola.push(0);
    do{
        int act = cola.front();
        cola.pop();
        for(int i=0;i<n;i++){

            if(!vis[i] && MA_ady[act][i] != 0){
                cola.push(i);
                vis[i] = true;
                AT[act][i] = MA_ady[act][i];
            }//fin if no visitado

        }//fin for i
    }while(!todosVisitados(vis));

    for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << AT[x][y];
		}
		cout << endl;
	}

   

   
}
	


