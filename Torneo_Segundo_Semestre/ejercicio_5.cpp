#include <bits/stdc++.h>
using namespace std;

float A[2][3];

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        string h;
        cin>>h;
        float s,b,a,cs,cb,ca;
        cin>>s>>b>>a;
        cin>>cs>>cb>>ca;
            A[0][0]+=s;
            A[0][1]+=b;
            A[0][2]+=a;
            A[1][0]+=cs;
            A[1][1]+=cb;
            A[1][2]+=ca;
    }
    float ps,pb,pa;
    ps=(A[1][0]*100)/A[0][0];
    pb=(A[1][1]*100)/A[0][1];
    pa=(A[1][2]*100)/A[0][2];
    printf("Puntos de saque: %.2f %.\n",ps);
    printf("Puntos de bloqueo: %.2f %.\n",pb);
    printf("Puntos de ataque: %.2f %.",pa);
return 0;
}