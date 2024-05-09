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

#include <iostream>
#include <queue>
using namespace std;

#define N 5

void mostrarMatriz(int A[][N]);
void obtenerAbarcador(int A[][N]);
void BFS(int A[][N]);
bool todosVisitados(bool A[]);

void mostrarMatriz(int A[][N]){
    for(int i=0;i<N;i++){
            cout<<"\t";
        for(int j=0;j<N;j++){
            cout<<"\t"<<A[i][j];
        }
            cout<<endl;
    }

}

void obtenerAbarcador(int A[][N]){
    bool vis[N] = {1,0,0,0};

    int AT[N][N] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}};

    queue<int>Cola;

    Cola.push(0);
    do{
        int act = Cola.front();
        Cola.pop();
        for(int i=0;i<N;i++){

            if(!vis[i] &&   A[act][i] != 0){
                Cola.push(i);
                vis[i] = true;
                AT[act][i] = A[act][i];
            }

        }
    }while(!todosVisitados(vis));

    cout<<"\nARBOL ABARCADOR:\n";
    mostrarMatriz(AT);

    BFS(AT);
}

void BFS(int A[][N]){
    queue<int>Cola;

    Cola.push(0);

    cout<<"\n\tRECORRIDO BFS:\n";
    cout<<"\t\t";
    while(!Cola.empty()){
        int act = Cola.front();
        char act_C = act + 65;
        cout<<act_C<<" - ";
        Cola.pop();

        for(int i=0;i<N;i++){
            if(A[act][i] == 1){ Cola.push(i); }
        }

    }

    cout<<endl;
}

bool todosVisitados(bool A[]){

    for(int i=0;i<N;i++){
            if(!A[i]){ return false;}
    }

    return true;
}

int main(){

    cout << " ***RECORRIDO EN ANCHURA***\n " << endl;

    int Ady_MA[N][N] = {
        {0,1,0,1,0},
        {0,0,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,1,0}};

    cout<<"\nMATRIZ ADYACENCIA:\n";
    mostrarMatriz(Ady_MA);
    obtenerAbarcador(Ady_MA);

    return 0;
}


