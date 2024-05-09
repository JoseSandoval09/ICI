/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4�A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfile�o

Este programa implementea el metodo de punto fijo para la obtencion de raices de la ecuacion
e^-x - x = 0

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int op=0;
    
    cout<<"\t\tI N T R O D U C C I O N\n Este programa encuentra un valor de raiz de la funcion:\n\t\te^-x - x = 0\n";
    cout<<"\t  con la formula despejada de: x=e^-x\n";
	cout<<"-------------------------------------------------------------------------------\n";
	system("pause");
	system("cls");
   while(op!=3)
   {
   		cout<<"\t\t M E N U\n1-Evaluacion del metodo de punto fijo\n2-Salir\n";
    	cout<<"-------------------------------------------------------------------------------\n";
    	cout<<"Seleccione una opcion: ";cin>>op;
    	cout<<"\n-------------------------------------------------------------------------------\n";
		 system("pause");
		 system("cls");
				switch(op){
				case 1:{
					long double inicial=0;
    				long double error=0;
    				long double x=0;
   					int cont=0;
					cout<<"\t\tM e t o d o   de   p u n t o   f i j o\n";
					cout<<"\nTeclea  el valor incial de x: "; cin>>inicial;
	    		    cout<<"\nTeclea el valor de tolerancia del error: ";cin>>error;
	    			x=exp(-inicial);
	    			cout<<"-------------------------------------------------------------------------------\n";
					cout<<"\t\tR E S U L T A D O S\n";
	   				 cout<<"-El valor de x es: "<<x<<endl;
	   				 while(abs(inicial-x)>error){
	        			 cont++;
	       				 inicial=x;
	       				 x=exp(-x);
						 cout<<fixed;
	    				 cout<<setprecision(9);
						 cout<<"Valor de la aproximacion: "<<x<<endl;
	    			   }
	    			cout<<fixed;
	    			cout<<setprecision(9);
	    			cout<<"-El valor de la raiz es: "<<x<<endl;
	    			cout<<"-En numero de iteraciones: "<<cont<<endl;
	    			cout<<"-------------------------------------------------------------------------------\n";
					system("pause");
					system("cls");
				break;
				}
				case 2:{
					cout<<"-------------------------------------------------------------------------------\n";
		        cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
		        return 0;
				break;
				}
			}
	}
}
