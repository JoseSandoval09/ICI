#include<iostream>

using namespace std;

void recursiva1(int n){
    
    if (n>1){
        recursiva1(n-1);
    }
    else{
        cout<<"Fin de la recursividad\n\n";

    }
    cout<<n<<", ";
}

int main(){
    recursiva1(10);
    return 0;
}