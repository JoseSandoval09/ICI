/*

Diagnostico

Jose Luis Sandoval Perez

Si funciono o no, indicar el nivel de entendimiento.

Codigo funciona para 4 numeros perfectos, no logre obtener el 5 y 6. Diria que nivel de entendimiento 60% si batalle un poco.

Ejecuta para los primeros 6 números perfectos y de cuanto tardo en hacerlo.

Para primeros 4 tarda alrededor de 1 segundos.



Determina el Big O de esta lógica. 

No recuerdo como obtener el big O


*/




#include<iostream>
#include<math.h>

using namespace std;


int main(){

    int numP=0,n=2,nA=0, sumaD=1;
    int perfectos[6];
  

    cout<<"Cuantos numeros perfectos quieres?";
    cin>>numP;

    int iteA=0;
    int numPP=0;
    nA=n;

    while(numPP<numP){

        sumaD=1;

        for(n=2;n<=nA/2;n++){
            if(nA%n==0){
                sumaD+=n;
            }
        }

        if(sumaD==nA){
            cout<<nA<<endl;
            perfectos[iteA]=nA;
            numPP++;
            iteA++;
        }

        nA++;




    }
    



            
}        

        









