/*

Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa implementa el metodo de la regla de crammer para resolver el siguiente sistema de ecuaciones

2x1 – x2 + 6x3 = 77
-3x1 + 4x2 - 5x3 = -30
8x1 – 7x2 – 9x3 = -133 


*/
#include<iostream>
using namespace std;

void menu() {
 cout<<"\t\t M E N U\n1-Resolver el sistema de ecuaciones por crammer\n2-Salir\n";
 cout<<"-------------------------------------------------------------------------------\n";
 cout<<"Seleccione una opcion: ";
}

int main(){
	int op, num;
	float x, y, z;
	float a1, b1, c1, a2, b2, c2, a3, b3, c3;
	float resp1, resp2, resp3;
	float detx, dety, detz, detg;
	
	cout<<"\t\tI N T R O D U C C I O N\n Este programa resuelve el sistema de ecuaciones: \n";
    cout<<"\t2x1 - x2 + 6x3 = 77\n\t-3x1 + 4x2 - 5x3 = -30\n\t8x1 -7x2 -9x3 = -133\n por el metodo de Crammer\n";
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
			cout<<"\t\tC  r  a  m  m  e  r\n";
      		cout << "Ingrese la dimension del sistema (MAXIMO 3 ecuaciones): "; cin >> num;
			if(num<=3 && num>1){
				cout<<"*1RA ecuacion*\n";
					cout<<"\tIngresa el valor de a1: ";cin>>a1;
					cout<<"\tIngresa el valor de b1: ";cin>>b1;
					cout<<"\tIngresa el valor de c1: ";cin>>c1;
					cout<<"\tIngresa el valor del lado derecho del igual: "; cin>>resp1;
					cout<<"\n-----------------------------------------------------------\n";
					cout<<"*2DA ecuacion*\n";
					cout<<"\tIngresa el valor de a2: ";cin>>a2;
					cout<<"\tIngresa el valor de b2: ";cin>>b2;
					cout<<"\tIngresa el valor de c2: ";cin>>c2;
					cout<<"\tIngresa el valor del lado derecho del igual: "; cin>>resp2;
					cout<<"\n-----------------------------------------------------------\n";
				if(num==3){
					cout<<"*3RA ecuacion*\n";
					cout<<"\tIngresa el valor de a3: ";cin>>a3;
					cout<<"\tIngresa el valor de b3: ";cin>>b3;
					cout<<"\tIngresa el valor de c3: ";cin>>c3;
					cout<<"\tIngresa el valor del lado derecho del igual: "; cin>>resp3;
					cout<<"\n-----------------------------------------------------------\n";
					system("pause");
					system("cls");	
				}
			cout<<"\t\tR E S U L T A D O S\n";
			//calculo de determinantes
					//general
						detg=a1*((b2*c3)-(b3*c2))-b1*((a2*c3)-(a3*c2))+c1*((a2*b3)-(a3*b2));
		                cout<<"\n-El determinante general es: "<<detg<<endl;
		            //x
			            detx=resp1*((b2*c3)-(b3*c2))-b1*((resp2*c3)-(resp3*c2))+c1*((resp2*b3)-(resp3*b2));
						cout<<"-El determinante de x es: "<<detx<<endl;
					//y
						dety=a1*((resp2*c3)-(resp3*c2))-resp1*((a2*c3)-(a3*c2))+c1*((a2*resp3)-(a3*resp2));
						cout<<"-El determinante de y es: "<<dety<<endl;
					//z
					detz=a1*((b2*resp3)-(b3*resp2))-b1*((a2*resp3)-(a3*resp2))+resp1*((a2*b3)-(a3*b2));
					cout<<"-El determinante de z es: "<<detz<<endl;
					
			cout<<"\n\nLa SOLUCION de las variables en el sistema de ecuaciones es: \n\n";
	
				x=detx/detg;
				y=dety/detg;
				z=detz/detg;
	
				cout<<"x = "<<x<<endl;
				cout<<"y = "<<y<<endl;
				cout<<"z = "<<z<<endl;
			}else{
				cout<<"ERROR/t el valor ingresado no es valido :( ";
			}
     		
		}
		cout<<"\n-------------------------------------------------------------------------------\n";
	   	system("pause");
	   	system("cls");	
	}while(op!=2);
 	cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
	return 0;
}
