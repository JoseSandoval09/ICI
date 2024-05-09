/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4°A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa calcula la raiz de una funcion utilizando el metodo de la falsa posicion
Funcion f(x) = f(x) = e^(-x) – ln (x).

*/
#include<iostream>
#include<cmath>
using namespace std; 

double a, b, TOL, EXACTITUD;
int MAXIT;
void menu() {
 cout<<"\t\t M E N U\n1-Calcular el valor de la raiz de la funcion por Falsa Posicion\n2-Salir\n";
 cout<<"-------------------------------------------------------------------------------\n";
 cout<<"Seleccione una opcion: ";
}
double F(double x){
    
    return exp(-x)-log(x); //funcion
} 
double falsa_posicion(double a, double b,int MAXIT,double TOL,double EXACTITUD){
    int cont=1;
    double fa=F(a);
    double fb=F(b);
    double c;     
    double fc;     
    while(cont<MAXIT){
    	cout<<"\n\t\tInteraccion ("<<cont<<")"<<endl;
        c=(a*F(b)-b*F(a))/(F(b)-F(a));//formula de la falsa posicion    
		cout<<"\t\tValor obtenido: "<<fc<<"\n";   
        fc=F(c);
        if(abs(fc)<=EXACTITUD){
        	cout<<"Raiz: "<<endl;
            return c;//raiz encontrada
        }
        if(abs(b-a)<=TOL){
            c=(a+b)/2;
            cout<<"Raiz: "<<endl;
            return c;//raiz encontrada
        }
        
        if(fc*fb>0)
            a=c;
        if(fa*fc>0)
            b=c;
        cont=cont+1;
    
    }
return c;
} 
int main (int argc, char *argv[]) {
	int op;
	cout<<"\t\tI N T R O D U C C I O N\n Este programa calcula la raiz de la funcion:\n\t\tf(x) = f(x) = e^(-x) – ln (x)\n";
    cout<<"\t  por el Metodo de la Falsa Posicion\n";
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
			cout<<"\t\tM e t o d o   g r a f i c o\n";
      		cout << "Ingrese el valor de [x, 0] (Intervalo Inferior): ";
      		cin >> a;
     		cout << "Ingrese el valor del [0, x] (Intervalo Superior): ";
     		cin >> b;
     		cout<<"Ingrese el valor maximo de interacciones: ";
     		cin>> MAXIT;
     		cout<<"Ingrese el valor maximo de tolerancia al error: ";
     		cin>>TOL;
     		cout<<"-------------------------------------------------------------------------------\n";
     		cout<<"\t\tR E S U L T A D O S\n";
     		 //(double a, double b,int MAXIT,double TOL,double EXACTITUD)
			cout<<falsa_posicion(a,b,MAXIT,TOL,0.0000001);//retorna la raiz  
		}
		cout<<"\n-------------------------------------------------------------------------------\n";
	   	system("pause");
	   	system("cls");	
	}while(op!=2);
    cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
    return 0;
}
