#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define D_LAB 40
#define MP make_pair
#define PB push_back

struct lab{
    char simbolo = '.';
    int f = 0;
    int g = 0;
    int h = 0;
    bool esCamino = false;
    lab* padre = NULL;
};



void mostrarLaberinto(lab[][D_LAB]);
pair<int,int>generarLaberinto(lab[][D_LAB]);
void hacerUnHuecoEnLaPared(lab[][D_LAB],int,int,int,int);
//de busqueda
void a_Estrella(lab[][D_LAB],pair<int,int>);
int buscarPunto(vector<pair<int,int>>,pair<int,int>);
void tratarPunto(lab[][D_LAB],pair<int,int>,pair<int,int>);

int main(){
    srand(time(NULL));
    lab casilla[D_LAB][D_LAB];

    pair<int,int>f = generarLaberinto(casilla);

    cout<<"\t--------:LABERINTO EVOLUCIONADO:--------\n";
    mostrarLaberinto(casilla);
    system("pause");
    system("cls");
    //implementar a_estrella
    a_Estrella(casilla,f);
return 0;
}

void mostrarLaberinto(lab casilla[][D_LAB]){
    for(int i=0;i<D_LAB;i++){
            cout<<"\t";
        for(int j=0;j<D_LAB;j++){
            cout<<casilla[i][j].simbolo;
        }//fin for j
            cout<<endl;
    }//fin for i
}

pair<int,int> generarLaberinto(lab casilla[][D_LAB]){
    for(int i=0;i<D_LAB;i++){
        /*
            se calcula el numero de obstaculos por fila
            el 33% de 40 es 13 y el 42% de 40 es 16, por lo tanto
            la cantidad de obstaculos debe rondar de 13 a 16
        */
        int n_ob = 13 + rand()%4;
        while(0<n_ob){
            int x = rand()%D_LAB;
            if(casilla[x][i].simbolo == '.'){
               casilla[x][i].simbolo = '#';
               n_ob--;
            }//si no es un obstaculo

        }//fin while obstaculos
    }//fin for i

    int fx = D_LAB-1,fy = rand()%D_LAB;

    //casilla final
    casilla[fx][fy].simbolo = 'f';
    casilla[fx][fy].esCamino = true;
    //casilla de inicio
    casilla[0][0].simbolo = '.';
    casilla[0][0].esCamino = true;

    hacerUnHuecoEnLaPared(casilla,fx,fy,1,0);
    hacerUnHuecoEnLaPared(casilla,fx,fy,0,1);

    return MP(fx,fy);
}

void hacerUnHuecoEnLaPared(lab casilla[][D_LAB],int fx,int fy,int x,int y){

    int q_abajo = 5 ; //la probabilidad de ir abajo es de 5
    int q_der = q_abajo + 4; // la probabilidad de ir a la derecha 4
    //entonces la probabilidad de que se mueva a la izquierda queda determinada por:
    //10 - q_der - q_abajo

    while(x!=fx || y!=fy){
        casilla[x][y].esCamino = true;

        if(casilla[x][y].simbolo = '#'){
            //si el camino se topa con un muro mueve ese muro en la misma fila
            //debe revisar que no sea parte de un camino y que no sea un muro
            int mover = rand()%D_LAB;
            while(casilla[mover][y].simbolo == '#' || casilla[mover][y].esCamino){  mover = rand()%D_LAB; }

            casilla[mover][y].simbolo = '#';//se mueve la casilla
        }//si la casilla es un muro
        casilla[x][y].simbolo = '.';

            int decision = rand()%10;

        if(x == fx){
            if(y>fy){ y--; }
            else{ y++; }
        }
        else{
            if(decision<=q_abajo && x<D_LAB-1){ x++; }//hacia abajo
            else if(decision<=q_der && y<D_LAB){ y++; }//preferiblemente a la derecha
            else if(y>0){ y--; }// a la izquierda
            else if(x<D_LAB-1){ x++; }// si se llega a un limite mejor bajar
        }

    }//despeja camino

}

void a_Estrella(lab casilla[][D_LAB],pair<int,int>f){
    vector<pair<int,int>>abierto;
    vector<pair<int,int>>cerrado;
    vector<pair<int,int>>vecinos;

    cerrado.PB(MP(0,0));

    while(buscarPunto(cerrado,f)==-1){
        int x = cerrado.back().first;
        int y = cerrado.back().second;
        cout<<"Actual: "<<x<<" "<<y<<endl;
        //se marca que se uso la casilla
        casilla[x][y].simbolo = 'a';

        //tomar los 4 puntos
        if(x-1>=0 && casilla[x-1][y].simbolo != '#' && buscarPunto(cerrado,MP(x-1,y))==-1){
            casilla[x-1][y].padre = &casilla[x][y];
            vecinos.PB(MP(x-1,y));
            tratarPunto(casilla,MP(x-1,y),f);
        }//buscar arriba
        if(x+1<D_LAB-1 && casilla[x+1][y].simbolo != '#' && buscarPunto(cerrado,MP(x+1,y))==-1){
            casilla[x+1][y].padre = &casilla[x][y];
            vecinos.PB(MP(x+1,y));
            tratarPunto(casilla,MP(x+1,y),f);
        }//buscar abajo
        if(y-1>=0 && casilla[x][y-1].simbolo != '#' && buscarPunto(cerrado,MP(x,y-1))==-1){
            casilla[x][y-1].padre = &casilla[x][y];
            vecinos.PB(MP(x,y-1));
            tratarPunto(casilla,MP(x,y-1),f);
        }//buscar izquierda
        if(y+1<D_LAB-1 && casilla[x][y+1].simbolo != '#' && buscarPunto(cerrado,MP(x,y+1))==-1){
            casilla[x][y+1].padre = &casilla[x][y];
            vecinos.PB(MP(x,y+1));
            tratarPunto(casilla,MP(x,y+1),f);
        }//buscar derecha

        while(!vecinos.empty()){
                pair<int,int>aux = vecinos.back();
                int enCerrado = buscarPunto(cerrado,aux);
                int enAbierto = buscarPunto(abierto,aux);
            if(enAbierto==-1 && enCerrado==-1){
                abierto.PB(vecinos.back());
            }//fin no esta en abiertos ni cerrados
            else if(enAbierto!=-1){
                int vx = aux.first;
                int vy = aux.second;

                int ax = abierto[enAbierto].first;
                int ay = abierto[enAbierto].second;
                if(casilla[vx][vy].g < casilla[ax][ay].g){
                    casilla[ax][ay].g = casilla[vx][vy].g;
                    casilla[ax][ay].h = casilla[vx][vy].h;
                    casilla[ax][ay].f = casilla[vx][vy].f;
                    casilla[ax][ay].padre = casilla[vx][vy].padre;
                }//actualizar casilla
            }//fin se encuentra en abierto

            vecinos.pop_back();
        }//para todos los vecinos

        int mejor = 0;
        for(int i=1;i<abierto.size();i++){

            int mx = abierto[mejor].first;
            int my = abierto[mejor].second;

            int ax = abierto[i].first;
            int ay = abierto[i].second;

            cout<<ax<<" "<<ay<<endl;
            if(buscarPunto(cerrado,abierto[i])==-1 && casilla[ax][ay].f < casilla[mx][my].f){
                mejor = i;
            }//fin if
        }//fin buscar al punto con menor costo


        cerrado.PB(abierto[mejor]);
        cout<<"ELIGIO: "<<abierto[mejor].first<<" "<<abierto[mejor].second<<endl;

        mostrarLaberinto(casilla);
        system("pause");
        system("cls");
    }//fin mientras el punto final no este en cerrado

}

int buscarPunto(vector<pair<int,int>>c,pair<int,int>busca){
    //busca si el punto se encuentra en el vector c
    for(int i=0;i<c.size();i++){
        int x = c[i].first;
        int y = c[i].second;

        if(x==busca.first && y==busca.second){ return i; }
    }//fin for i

    return -1;
}

void tratarPunto(lab casilla[][D_LAB],pair<int,int>p,pair<int,int>f){
    //calcula f del punto

    int x = p.first;
    int y = p.second;

    int fx = f.first - x;
    int fy = f.second - y;

    if(fx<0){ fx*=-1; }
    if(fy<0){ fy*=-1; }

    casilla[x][y].g = casilla[x][y].padre->g +1;
    casilla[x][y].h = fx+fy;
    casilla[x][y].f = casilla[x][y].g + casilla[x][y].h;
}
