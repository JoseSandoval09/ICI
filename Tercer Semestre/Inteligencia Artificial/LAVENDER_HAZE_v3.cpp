#include <time.h>
#include <queue>
#include <iostream>
using namespace std;

#define N 40
#define MP make_pair


struct lab{
    char simbolo = '.';// espacio libre por donde pasar
    pair<int,int>padre; //pareja arreglo
    bool esCamino = false;//
};



//funciones de generacion
pair<int,int> generarLaberinto(lab[][N]); //regresa cordenada de salida
void mostrarLaberinto(lab[][N]); //imprime laberinto completo
void hacerUnHuecoEnLaPared(lab[][N],int,int,int,int);//hace camino
void restablecerMat(lab[][N]);//false todos los es camino
void BFS(lab[][N],pair<int,int>);//solucion

int main(){
    srand(time(NULL));
    lab casilla[N][N];

    pair<int,int>f = generarLaberinto(casilla);
    cout<<"\t--------:LABERINTO EVOLUCIONADO:--------\n";
    mostrarLaberinto(casilla);
    system("pause");
    system("cls");

    BFS(casilla,f);
    cout<<"\t----------:LABERINTO SOLUCION:----------\n";
    mostrarLaberinto(casilla);
return 0;
}

pair<int,int> generarLaberinto(lab casilla[][N]){
    //desde el struct el laberinto esta lleno de
    //espacios abiertos (.)

    for(int i=0;i<N;i++){
        /*
            se calcula el numero de obstaculos por fila
            el 33% de 40 es 13 y el 42% de 40 es 16, por lo tanto
            la cantidad de obstaculos debe rondar de 13 a 16
        */
        int n_ob = 13 + rand()%4;
        while(0<n_ob){
            int x = rand()%N;
            if(casilla[x][i].simbolo == '.'){
               casilla[x][i].simbolo = '#';
               n_ob--;
            }//si no es un obstaculo

        }//fin while obstaculos
    }//fin for i

    int fx = N-1,fy = rand()%N; //genera salida 

    //casilla final
    casilla[fx][fy].simbolo= 'f';
    casilla[fx][fy].esCamino = true;
    //casilla de inicio
    casilla[0][0].simbolo = '.';
    casilla[0][0].esCamino = true;

    //imprime el laberinto lleno por rands
    cout<<"\t----------:LABERINTO PRIMATE:----------\n";
    mostrarLaberinto(casilla);
    system("pause");
    system("cls");

    hacerUnHuecoEnLaPared(casilla,fx,fy,1,0);
    hacerUnHuecoEnLaPared(casilla,fx,fy,0,1);

    return MP(fx,fy);
}

void hacerUnHuecoEnLaPared(lab casilla[][N],int fx,int fy,int x,int y){

    int q_abajo = 5 ; //la probabilidad de ir abajo es de 5
    int q_der = q_abajo + 4; // la probabilidad de ir a la derecha 4
    //entonces la probabilidad de que se mueva a la izquierda queda determinada por:
    //10 - q_der - q_abajo

    while(x!=fx || y!=fy){
        casilla[x][y].esCamino = true;

        if(casilla[x][y].simbolo = '#'){
            //si el camino se topa con un muro mueve ese muro en la misma fila
            //debe revisar que no sea parte de un camino y que no sea un muro
            int mover = rand()%N;
            while(casilla[mover][y].simbolo == '#' || casilla[mover][y].esCamino){  mover = rand()%N; }

            casilla[mover][y].simbolo = '#';//se mueve la casilla
        }//si la casilla es un muro
        casilla[x][y].simbolo = '.';

            int decision = rand()%10;

        if(x == fx){
            if(y>fy){ y--; }
            else{ y++; }
        }
        else{
            if(decision<=q_abajo && x<N-1){ x++; }//hacia abajo
            else if(decision<=q_der && y<N){ y++; }//preferiblemente a la derecha
            else if(y>0){ y--; }// a la izquierda
            else if(x<N-1){ x++; }// si se llega a un limite mejor bajar
        }

    }//despeja camino

}

void mostrarLaberinto(lab casilla[][N]){
    for(int i=0;i<N;i++){
            cout<<"\t";
        for(int j=0;j<N;j++){
            cout<<casilla[i][j].simbolo;
        }//fin for j
            cout<<endl;
    }//fin for i
}

void restablecerMat(lab e[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            e[i][j].esCamino = false;
        }
    }
}

void BFS(lab c[][N],pair<int,int>f){
    queue<pair<int,int>> vis;
    restablecerMat(c);

    vis.push(MP(0,0));

    int x = vis.front().first;
    int y = vis.front().second;

    while(!vis.empty() && (x!=f.first || y!=f.second)){
        x = vis.front().first;
        y = vis.front().second;
        vis.pop();

        if(x-1>=0 && c[x-1][y].simbolo!='#' && !c[x-1][y].esCamino){ vis.push(MP(x-1,y)); c[x-1][y].esCamino=true; c[x-1][y].padre = MP(x,y); }//arriba
        if(x+1<N && c[x+1][y].simbolo!='#' && !c[x+1][y].esCamino){ vis.push(MP(x+1,y)); c[x+1][y].esCamino=true; c[x+1][y].padre = MP(x,y);}//abajo
        if(y-1>=0 && c[x][y-1].simbolo!='#' && !c[x][y-1].esCamino){ vis.push(MP(x,y-1)); c[x][y-1].esCamino=true; c[x][y-1].padre = MP(x,y);}//izquierda
        if(y+1<N && c[x][y+1].simbolo!='#' && !c[x][y+1].esCamino){ vis.push(MP(x,y+1)); c[x][y+1].esCamino=true; c[x][y+1].padre = MP(x,y);}//derecha

    }//while mientras no llegue al destino

    x = f.first;
    y = f.second;


    while(x!=0 || y!=0){
        c[x][y].simbolo = 'a';
        int fx = c[x][y].padre.first;
        int fy = c[x][y].padre.second;

        x = fx; y = fy;
    }//regresa el camino

    x = f.first;
    y = f.second;
    c[x][y].simbolo = 'f';

}
