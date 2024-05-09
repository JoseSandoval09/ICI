//EQUIPO 3.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<locale.h>

using namespace std; 
int N, A, B;

int main(){
	setlocale (LC_ALL, "");
	cout<<"-----------SALVEMOS LA NAVIDAD!--------------------\n";
	cout<<"";
	cin>>N;
	if (2<= N && N<=100){
		cout<<"OK :) \n";
	}
	else{
	        do{
			    cout<<"Introduce una cantidad entre 2 y 100 \n";
				cout<<"¿Cuanto tiempo queda para terminar los regalos (en minutos)?: ";
	            cin>>N;
	        }while (N<2 && N>100);
	};
	cout<<"Cuantos minutos ocupas para terminar el regalo 1: ";
	cin>>A;
	cout<<"Cuantos minutos ocupas para terminar el regalo : ";
	cin>>B;
	if (1<=A && B<=100){
		if ((A+B)<=N){
			cout<<"Podemos hacerlo! \n";
		}
		else{
			cout<<"Tomorrow sera otro dia. \n";
		}
	}
	else{
		do{
			cout<<"Introduce valores que no sobrepasen los 100 minutos\n";
			cout<<"Cuantos minutos ocupas para terminar el regalo 1: ";
	        cin>>A;
	        cout<<"Cuantos minutos ocupas para terminar el regalo 2: ";
	        cin>>B;
		}while(A<1 && B>100);
	}
	
	system ("pause");
	return 0;
}