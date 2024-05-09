/* 			PRACTICA 10

Universidad Autonoma de Aguascalientes
	Programacion Cientifica ICI 4 A
	
	Jose Luis Sandoval Perez
	Ximena Rivera Delgadillo
 Luis Fernando Guiterrez Marfileño
 
 INTRODUCCION:
Este programa utiliza el metodo del trapecio para obtener una aproximacion a la siguiente integral 

f(x)=sec(x) 0-pi/4

*/
#include<iostream>
#include<math.h>

double SacarF(double x);


using namespace std;

int main(){

    int subin=0, op=0;
    
	cout<<"\t\tI N T R O D U C C I O N "<<endl;
        cout<<"Este programa nos permite obtener la aproximacion de la siguiente integral\n";
		cout<<"\t\tf(x)=sec(x) 0-pi/4\n \t a partir del metodo del trapecio"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        system("pause");
        system("cls");
    
    	do{
			cout<<"\t\tM E N U "<<endl;
			cout<<"(1) Metodo del Trapecio"<<endl;
			cout<<"(2) Salir"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			cout<<"Opcion: "; cin>>op;
			cout<<"---------------------------------------------------------"<<endl;
			system("pause");
			system("cls");
			
			if(op==1)
			{
				cout<<"\tM E T O D O   del  T R A P E C I O\n";
				cout<<"Ingresa el numero de subintervalos a dividir la funcion: ";
				cin>>subin;
				double n=0,a=0,b=0,h=0,PI=3.141593;
				n=subin;
				a=0;
				b=PI/4;
				h=(b-a)/n;
				double x[subin],fx[subin];
				x[0]=a;
				x[subin]=b;
				
				for(int i=1;i<=subin;i++ )
				{
					x[i]=x[i-1]+h;   
				}
				for(int i=0;i<=subin;i++)
				{
					fx[i]=SacarF(x[i]);
				}  
			
			
				double aprox;
				aprox=fx[0]+fx[subin];

				for(int i=1; i<subin;i++){

					aprox+=2*fx[i];

				}

				aprox=h/2*aprox;
			cout<<"\nResultado: ";
			cout<<"El valor aproximado de la integral definida sec(x) desde 0 a pi/4 es igual a:  "<<aprox<<endl;
				  
        }
        system("pause");
        system("cls");
    }while(op!=2);
    cout<<"PROGRAMA REALIZADO POR: \nXimena Rivera Delgadillo\nJose Luis Sandoval Perez"<<endl;
    system("pause");
}

double SacarF(double x){
    return 1/cos(x);
}

