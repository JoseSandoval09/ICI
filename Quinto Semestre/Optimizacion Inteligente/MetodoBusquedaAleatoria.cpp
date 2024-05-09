/* 	
	UNIVERSIDAD AUTï¿½NOMA DE AGUASCALIENTES
	Centro de Ciencias Bï¿½sicas
 	Departamento Ciencias de la Computaciï¿½n
	Optimizaciï¿½n Inteligente
	
	
	
	Maestro: Luis Fernando Gutierrez Marfileï¿½o
	
	Programa que  implemente busqueda aleatoria para Minimizar la siguiente función:
	
	- ((1+cos(12*sqrt(x1^2+x22)))/ 0.5*(x1^2+x2^2)+2)
	
*/	

// Librerï¿½as 

#include<iostream>
#include<math.h>
#include<time.h>
#include<cstdlib>

using namespace std;

double fx(int x1, int x2);

int main(){

	int op=0;
	int i=1;
	int iter=0;
	
	double aux=__DBL_MAX__;
	srand(time(0));

	do{
		
		double f_x=0;
		
		
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE RESOLVER UN PROBLEMA DE OPTIMIZACION MULTIDIMENSIONAL NO RESTRINGIDA A LA FUNCION  \n- ((1+cos(12*sqrt(x1^2+x22)))/ 0.5*(x1^2+x2^2)+2) \n  MEDIANTE EL METODO DE NEWTON \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Metodo de Busqueda Aleatoria \n 2. Salir \n ";
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
					
					

				    double minimo = -5.12;
				    double maximo = 5.12;	

					x1=(static_cast<double>(std::rand() % 1051) - 525) / 100.0;
					x2=(static_cast<double>(std::rand() % 1051) - 525) / 100.0;
					f_x=fx(x1,x2);
					


					if(f_x<aux){
						aux=f_x;
					}

					if(iter<=1000){
						cout<<"Iteracion:"<<i<<endl;
						cout<<"x1="<<x1<<endl;
						cout<<"x2="<<x2<<endl;
						cout<<"f(x)="<<f_x<<endl;
						cout<<endl;
						cout<<endl;
					}
					

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

     return -((1+cos(12*sqrt((x1*x1)+(x2*x2))))/0.5*((x1*x1)+(x2*x2))+2);
    
    
}
