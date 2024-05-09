/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	Optimizacion por metodo de busqueda aleatoria

	
*/	

// Librer�as 
#include<iostream>
#include<math.h>
#include<time.h>
#include<cstdlib>

using namespace std;

double fx(int x1, int x2);

int main(){

		int op=0;
		
	do{		
		int i=1;
		int iter=0;
		
		double aux=__DBL_MAX__;
		srand(time(NULL));

	
		
		double f_x=0;
		
		
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " Optimizacion por metodo de busqueda aleatoria de la funcion:  \n-((x2 + 47) * sin(sqrt(abs(x2 + x1/2 + 47))) - x1 * sin(sqrt(abs(x1 - (x2 + 47))))) \n   \n\n";
		cout << " Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Busqueda Aleatoria \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin>>op;
		system("cls");

		switch (op)
		{
		case 1:
				
				
				cout<<"Ingresa numero de iteraciones:";cin>>iter;
				
				while (i<=iter)
				{
				
				
					int x1=0;int x2=0;

					x1=rand()%1051-525;
					x2=rand()%1051-525;
					f_x=fx(x1,x2);
					


					if(f_x<aux){
						aux=f_x;
					}

					cout<<"Iteracion:"<<i<<endl;
					cout<<"x1="<<x1<<endl;
					cout<<"x2="<<x2<<endl;
					cout<<"f(x)="<<f_x<<endl;
					cout<<endl;
					cout<<endl;
					
					

					i++;
				}
				cout<<"El valor minimo encontrado en la funcion es:"<<aux<<endl;
				system("pause");
				system("cls");
			break;
				
		case 2:
			system("cls");
			break;
			
		
		default:
			system("cls"); cout << " OPCION INVALIDA"; 
			break;
		}

	}while(op!=2);

	cout << " Saliendo del programa ... Hasta luego \n\n";

    
	
		
				
	
    
    
    

  

  





}



double fx(int x1, int x2){

     return -((x2 + 47) * sin(sqrt(abs(x2 + x1/2 + 47))) - x1 * sin(sqrt(abs(x1 - (x2 + 47)))));
    
    
}
