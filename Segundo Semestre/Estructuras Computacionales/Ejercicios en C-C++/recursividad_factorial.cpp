//JOSE LUIS SANDOVAL PEREZ 
// 2A ICI 
//FACTORIAL CON RECURSIVIDAD
#include<iostream>
#include<stdlib.h>

using namespace std;

//Funcion recursiva
int factorial(int x){

   
    if(x==1){
        return 1;
    }

    return x * factorial(x-1);

}

void recursivo1(int n ){
    cout<<n<<endl;
    if(n==1){
        cout<<1;
    }
    else{
        recursivo1(n-1);
    }
    cout<<n<<endl;
}

int main(){
    
    int x;
    cout<<"Numero para calcular su factorial: ";
    cin>>x;
    cout<<"Factorial: "<<factorial(x)<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"S E G U N D A ----- F U N C I O N ------ R E C U R S I V A "<<endl;
   recursivo1(10);

}