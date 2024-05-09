/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Crear un programa que ejecute el desarrollo de todos
los subconjuntos de un conjunto de n elementos.
*/


#include<iostream>

using namespace std;


#include <iostream>
#include <string>
using namespace std;

string conversor(int a);

int main() {
	
	const int Word_letters = 6;
	string binary;
    int n = 6;
	string word[] = {"R","E","Z","A","G","O"};

	for(int i=0;i<=63;i++){
		binary = conversor(i);
		cout<<binary<<" - {";
		for(int i=0;i<n;i++){
			if(binary[i]=='1'){
				cout<<word[i]<<", ";
			}
		}
		cout<<"}\n";
	}
}

string conversor(int c){
	string b;
    int binario[6];
    for (int i = 0;i < 6;i++)
    {
        binario[i] = c % 2;
        c /= 2;
    }
    for (int i = 5; i >= 0; i--)
    {
        b+=binario[i]+'0';
    }
    return b;
}
