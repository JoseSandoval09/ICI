/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	M�todo de Newton: Este m�todo permite calcular el m�ximo o m�nimo de una funci�n, haciendo
	uso de una aproximaci�n cuadr�tica dada por la serie de Taylor. 
	
*/	

// Librer�as 
#include<iostream>
#include<math.h>
using namespace std;	

void Newton();

int main(){
	int end=0;
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE OBTENER EL MINIMO O MAXIMO DE UNA \n FUNCION MEDIANTE EL METODO DE NEWTON \n\n";
		cout << " Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Metodo de Newton \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: 
				system("cls");
				cout<<" METODO DE NEWTON \n\n";
				Newton(); break;
			case 2: 
				system("cls");
				end=2;
				break;
			default: system("cls"); cout << " OPCION INVALIDA"; break;
		}
	}
	while (end != 2);
	cout << " Saliendo del programa ... Hasta luego \n\n";
	return 0;
	
   
}

void Newton(){
	int no_i=1;
	double x=0, fx=0,fx1=0,fx2=0,error;

	// Solicitando valores inicial y error
    cout<<" Ingrese el valor inicial: ";cin>>x;
    cout<<" Ingresa el error: ";cin>>error;
    
    cout<<"\n\n";
    system("pause");
    system ("cls");
    
    cout<<" Funcion Original \t Primera derivada \t Segunda derivada\n";
	cout<<" 2*(x*x)+16/x     \t 4*x-16/(x*x)     \t 32/(x*x*x)+4 \n\n";
	
	cout<<" ----- RESULTADOS ----- \n\n";
    cout<<" no_i\t\tx\t\tfx\t\tfx1\t\tfx2\t\tx(k+1)"<<endl;
	 
	
	// M�todo de Newton
    do{
        cout<<" "<<no_i<<"\t\t"<<x<<"\t\t"<<fx<<"\t\t"<<fx1<<"\t\t"<<fx2<<"\t\t";
        no_i++;
        fx=2*(x*x)+16/x;
        fx1=4*x-16/(x*x);
        fx2=32/(x*x*x)+4;
        x=x-(fx1/fx2);
        cout<<x<<endl;
   }while(abs(fx1)>error);

   cout<<"\n VALOR MINIMO DE LA FUNCION: \n "<<2*(x*x)+16/x<<"\n\n";
   system("pause");
}
