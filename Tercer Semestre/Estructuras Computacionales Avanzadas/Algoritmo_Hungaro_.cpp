/*
	Universidad Autonoma de Aguascalientes
	Ingenieria en Computacion Inteligente
	Estructuras Computacionales Avanzadas
	Integrantes:
		Aranda Gonzalez Diego Alberto
		Galvan Niño de Rivera Gibran Antonio
	Profesor:
		Dr. en C. Luis Fernando Gutierrez Marfileño
	Practica 8
		Crear un programa que implemente el metodo hungaro
*/
#include<bits/stdc++.h>
using namespace std;

int m[3][3] = {	{15,10,9},
				{9,15,10},
				{10,12,8}};
				
int a[3][3] = {	{0,0,0},
				{0,0,0},
				{0,0,0}};
struct cost{
	int x,y,c;
};
cost aux[3];
int main(){
	int minim;
	for(int i=0;i<3;i++){
		minim=999;
		for(int j=0;j<3;j++){
			if(m[i][j]<minim){
				minim=m[i][j];
				aux[i].x=j;
				aux[i].y=i;
				aux[i].c=m[i][j];
			}
		}
	}
	cout << "Matriz Inicial" << endl;
	for(int i=0;i<3;i++){
		a[aux[i].y][aux[i].x]=aux[i].c;
	}
	for (int d = 0; d<3;d++){
		for (int e = 0; e<3;e++){
			cout << m[d][e] << "\t";
		}
		cout << endl;
	}

	
	cout << endl;
	cout << "Metodo Hungaro" << endl;
	for(int k=0;k<3;k++){
		switch(k){
			case 0:for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
			case 1: for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
			case 2: cout << "Matriz Final"<< endl;
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
		}
		cout<<"\n";
	}
	

}
