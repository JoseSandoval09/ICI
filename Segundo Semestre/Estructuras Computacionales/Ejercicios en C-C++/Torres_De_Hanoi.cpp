#include<iostream>

using namespace std;

void Hanoi(char varInicial, char varCentral, char varFinal, int n){
    if(n==1){
        cout<<"Mover disco"<<n<<" desde varilla"<<varInicial<<"a varilla "<< varFinal<<endl;
    }
    else{
        Hanoi(varInicial,varFinal,varCentral,n-1);
        cout<<"Mover disco"<<n<<" desde varilla"<<varInicial<<"a varilla "<< varFinal<<endl;
        Hanoi(varCentral,varInicial,varFinal,n-1);
        
    }
    
}

int main(){

    cout<<"T O R R E S  D E  H A N O I \n\n";
    cout<<"H A N O I  4  D I S C O S\n\n\n";

    Hanoi('A','B','C', 4);


}