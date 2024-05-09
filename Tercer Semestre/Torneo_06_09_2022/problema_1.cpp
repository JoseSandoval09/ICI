#include<iostream>
#include<string.h>


using namespace std;


string invertir(string num){

    string reversenum;

    for(int i=num.size()-1;i>=0;i--){
        
        reversenum=reversenum.append(1,num[i]);
    }

    return reversenum;

}

int main(){

    string cadena;
    cout<<"Ingresa cadena: ";
    cin>>cadena;

    cout<<"Cadena invertida: " + invertir(cadena);


}