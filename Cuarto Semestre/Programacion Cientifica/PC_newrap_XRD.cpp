/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de Newton Raphson
de la funcion   f(x) = cos (x) - x
*/
#include <iostream>
#include <iomanip> 
#include <cmath>

#define PRECISION 10
#define INTERVALOS 10
#define PI 3.14159265358979323846
using namespace std;

void menu();
double f(double x);	
double f_derivada(double x); 
void newton_raphson(double x0, double tolerancia, int max_interaciones);
double radianesAGrados(double radianes);

int main()
{
	double a; //10 grados
	double b;//90 grados
	double tolerancia;	
	double x0; 
	int MAX_ITERACIONES, op;
	
	cout << setprecision(PRECISION);
    cout<<"\t\tI N T R O D U C C I O N\n Este programa calcula la raiz de la funcion f(x)=  cos(x) - x\n";
    cout<<"\t  por el metodo de Newton Raphson\n";
	cout<<"-------------------------------------------------------------------------------\n";
	system("pause");
	system("cls");
		do{
		 menu();
    	 cin >> op;
   	 	 cout<<"\n-------------------------------------------------------------------------------\n";
		 system("pause");
		 system("cls");
		if(op==1){
			cout<<"\tM E T O D O   de   N E W T O N    R A P H S O N\n";
			// intervalo
			a=10;
			a=radianesAGrados(a);
			b=90;
			b=radianesAGrados(b);
			
			cout << "\nIngrese el valor inicial (x0) en grados= ";
			cin >> x0;
	
			cout << "Ingrese el rango de tolerancia = ";
			cin >> tolerancia;
	
			cout<<"Ingrese el numero maximo de interaciones= ";
			cin>>MAX_ITERACIONES;
			
			cout<<"-------------------------------------------------------------------------------\n";
     		cout<<"\t\tR E S U L T A D O S\n";
			newton_raphson(x0, tolerancia, MAX_ITERACIONES);	
			cin.get();
			cin.get();
		}
		cout<<"\n-------------------------------------------------------------------------------\n";
	   	system("pause");
	   	system("cls");	
	}while(op!=2);
	cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
    return 0;
}

double f(double x)
{
	return cos(x)-x;
}

double f_derivada(double x)
{
	return -sin(x)-1;
}

void newton_raphson(double x0, double tolerancia, int max_iteraciones)
{
	double x1; 
	double error;
	int iteracion; 
	bool converge = true;
	
	cout << "\nAproximacion inicial:\n";
	cout << "x0 = " << x0 << "\n"
		<< "f(x0) = " << f(x0) << "\n"
		<< "f'(x0) = " << f_derivada(x0) << endl;
	
	iteracion = 1;
	do {
	
		if (iteracion > max_iteraciones) {
			converge = false;	
			break;
		
		} else {
			x1 = x0 - f(x0) / f_derivada(x0); 
			error = fabs(x1 - x0);	
			
			cout << "\a";
			cout << "\n\nIteracion #" << iteracion << endl;
			cout << "\nx" << iteracion << "     = " << x1 << "\n"
				<< "f(x" << iteracion << ")  = " << f(x1) << "\n"
				<< "f'(x" << iteracion << ") = " << f_derivada(x1) << "\n"
				<< "error  = " << error << endl
				<<"x1 = "<<x1<<endl;
			
			if (error <= tolerancia) { 
				converge = true;
				break;
			
			} else {
				x0 = x1;
				iteracion++;
			}
		}
	
	} while (1);
	
	cout << "\a";
	if (converge) {
		cout << "\n\nPara una tolerancia de " << tolerancia << " la RAIZ APROXIMADA de f es = " << x1 << endl;
	
	} else {
		cout << "\n\nSe sobrepaso la m�xima cantidad de iteraciones permitidas" << endl;
	}
}
double radianesAGrados(double radianes)
{
    return radianes * 180 / PI;
}
void menu(){
 cout<<"\t\t M E N U\n1-Calcular el valor de la raiz de la funcion por Newton Raphson\n2-Salir\n";
 cout<<"-------------------------------------------------------------------------------\n";
 cout<<"Seleccione una opcion: ";

}
