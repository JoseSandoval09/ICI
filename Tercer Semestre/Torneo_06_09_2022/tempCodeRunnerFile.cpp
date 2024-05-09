#include<iostream>
#include<string.h>


using namespace std;


void invertir(string text){

    string reversedtext;

    for(int i=text.size()-1;i>=0;i--){
        
        reversedtext=reversedtext.append(1,text[i]);
    }

    cout<<"Cadena invertida: " + reversedtext;


    if(text==reversedtext){
        cout<<"\nPalabra palindroma";
    }
    else{
        cout<<"\nNo palindroma";
    }
    



}

int main(){

    string cadena;
    cout<<"Ingresa cadena sin mayusculas y sin espacios: ";
    cin>>cadena;

    invertir(cadena);

    

}