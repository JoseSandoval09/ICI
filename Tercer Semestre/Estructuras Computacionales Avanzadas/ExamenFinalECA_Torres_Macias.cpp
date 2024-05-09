/*
* Carlos Daniel Torres Mac�as
* 244543
* Examen Final: Estructuras Computacionales Avanzadas
* 
* El siguiente programa realiza un recorrido en anchura de
* un digrafo previamente establecido, tiene que desplegar
* la matriz de adyacencia, tambi�n obtener y desplegar el
* arbol abarcador de dicho grafo. Desplegar el recorrdido
* en anchura de dicho grafo.
* 
* Cuya matriz de adyacencia es la siguiente
* 
*0 1 0 1 0 
*0 0 1 1 1 
*0 0 0 0 1 
*0 0 0 0 1 
*0 0 0 1 0
*/

#include <iostream>
#include <conio.h>
#include <queue>

#define NODOS 5

int MA[NODOS][NODOS] = {
    {0,1,0,1,0},
    {0,0,1,1,1},
    {0,0,0,0,1},
    {0,0,0,1,0} };

std::queue <int> Cola;

void BFS();
bool todosVisitados(bool[]);

int main() {
    std::cout << "-----------::MATRIZ DE ADYACENCIA::-----------\n";
    for (int i = 0; i < NODOS; i++) {
        for (int j = 0; j < NODOS; j++) {
            std::cout << "\t" << MA[i][j];
        }//fin for j
        std::cout << "\n";
    }//fin for i
    std::cout << "\n\n";
    BFS();

    system("pause");
    system("cls");

    return 0;
}

void BFS() {
    bool vis[NODOS] = { 1,0,0,0 };

    int AT[NODOS][NODOS] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0} };

    Cola.push(0);
    std::cout << "\tRECORRIDO:\n";
    std::cout << "\n\tNodo actual: A\n";
    do {
        int act = Cola.front();
        Cola.pop();
        for (int i = 0; i < NODOS; i++) {

            if (!vis[i] && MA[act][i] != 0) {
                Cola.push(i);
                std::cout << "";
                switch (i + 1){
                	case 1:{
						std::cout << "\tNodo actual: A" << std::endl;
						break;
					} 
					case 2:{
						std::cout << "\tNodo actual: B" << std::endl;
						break;
					} 
					case 3:{
						std::cout << "\tNodo actual: C" << std::endl;
						break;
					} 
					case 4:{
						std::cout << "\tNodo actual: D" << std::endl;
						break;
					} 
					case 5:{
						std::cout << "\tNodo actual: E" << std::endl;
						break;
					}
				}     
                vis[i] = true;
                AT[act][i] = AT[i][act] = MA[act][i];
            }//fin if no visitado

        }//fin for i
    } while (!todosVisitados(vis));

    std::cout << "\n----------::ARBOL ABARCADOR::------------\n";
    for (int i = 0; i < NODOS; i++) {
        for (int j = 0; j < NODOS; j++) {
            std::cout << "\t" << AT[i][j];
        }
        std::cout << std::endl;
    }

}

bool todosVisitados(bool vis[]) {
    for (int i = 0; i < NODOS; i++) {
        if (!vis[i]) { return false; }
    }
    return true;
}
