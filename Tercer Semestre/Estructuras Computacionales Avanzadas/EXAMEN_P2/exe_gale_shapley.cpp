#include <iostream>
using namespace std;

#define PER_POR_GENERO 5// numero de personas por genero (hombre,mujer)

int H[PER_POR_GENERO][PER_POR_GENERO+1] = {
    {3,1,0,4,2,-1},
    {0,1,3,4,2,-1},
    {3,2,1,0,4,-1},
    {0,3,1,2,4,-1},
    {0,1,4,2,3,-1}};
int M[PER_POR_GENERO][PER_POR_GENERO+1] = {
    {3,2,0,4,1,-1},
    {2,1,4,3,0,-1},
    {3,4,1,0,2,-1},
    {0,1,2,3,4,-1},
    {3,0,1,2,4,-1}};

bool pareja[PER_POR_GENERO][2];

int buscarPreferencia(int j,int propuesta){
    for(int i=0;i<PER_POR_GENERO;i++){
        if(propuesta==M[j][i]){ return i; }
    }
    return -1;
}

void GalesShapley(){
    int j[PER_POR_GENERO];

    for(int i=0;i<PER_POR_GENERO;i++){ j[i]=0; }

    int hombres_casado = 0;

    while(hombres_casado<PER_POR_GENERO){
        hombres_casado = 0;
        for(int i=0;i<PER_POR_GENERO;i++){

            int hombre = i;
            int mujer = H[hombre][j[i]];
            cout<<hombre<<" "<<mujer;

            if(pareja[hombre][0]){ hombres_casado++; }

            else{
                if(!pareja[mujer][1]){
                    pareja[hombre][0] = pareja[mujer][1] = true;
                    H[hombre][PER_POR_GENERO] = mujer;
                    M[mujer][PER_POR_GENERO] = hombre;
                }//la mujer no tiene pareja
                else{
                    int esposo = M[mujer][PER_POR_GENERO];
                    int pref_hombre = buscarPreferencia(mujer,hombre);
                    int pref_esposo = buscarPreferencia(mujer,esposo);

                    cout<<" E:"<<esposo<<" PE| "<<pref_esposo<<" PH| "<<pref_hombre;
                    if(pref_esposo>pref_hombre){
                        //se remueve al esposo como pareja
                        pareja[esposo][0] = false;
                        H[esposo][PER_POR_GENERO] = -1;
                        j[esposo]++;

                        pareja[hombre][0] = true;
                        H[hombre][PER_POR_GENERO] = mujer;
                        M[mujer][PER_POR_GENERO] = hombre;
                    }
                    else{ j[hombre] ++; }//la mujer no quizo
                }//la mujer tiene pareja
            }//el hombre no tiene pareja

            cout<<"----"<<endl;
        }//fin for i
        cout<<hombres_casado<<endl;
    }//fin for while

    //impresion de mstrimonios
    for(int i=0;i<PER_POR_GENERO;i++){
        cout<<"Sujeto "<<i+1<<" casado con "<<H[i][PER_POR_GENERO]+1<<endl;
    }
}


int main(){
    GalesShapley();
    return 0;
}
