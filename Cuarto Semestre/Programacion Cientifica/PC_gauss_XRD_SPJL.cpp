/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Departamento de ciencias de la computacion
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo 
Metodo Gauss
Luis Fernando Guiterrez Marfileño

Este programa resuelve el siguiente sistema de ecuaciones 3x3 por el metodo de Gauss-Jordan


-x1+x2-x3=-1
4x1-2x2+2x3=0
-3x1-2x2+0x3=-4
*/






#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10 //tama�o maximo de la matriz

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n,op;

     cout<< setprecision(3)<< fixed; //precision de los decimales


	
		
		
		while(true){

			cout<<"M E T O D O\t E L I M I N A C I O N\t\t G A U S S"<<endl;
			cout<<"-----------------------------------------------------------------------"<<endl;
			cout<<"MENU"<<endl;
			cout<<"1.Metodo Gauss"<<endl;
			cout<<"2.Salir"<<endl;
		
		cout<<"Opcion: "; cin>>op;
	
			switch (op)
			{
			case 1:
				//ingresamos el numero de incognitas
				cout<<"Ingresa el numero de incognitas del sistema: ";
				cin>>n;
				//ingresamos los coeficientes de la matriz
				cout<<"Ingresa los coeficientes de la matriz argumentada: "<< endl;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n+1;j++)
					{
						cout<<"a["<< i<<"]["<< j<<"]= ";
						cin>>a[i][j];
					}
				}
				/* GAUSS*/
				for(i=1;i<=n-1;i++)
				{
					if(a[i][i] == 0.0)
					{
						cout<<"Error"; //si alguno de los valores de la horizontal es igual 0 no es posible realizar la eliminacion gaussiana
						exit(0);
					}
					for(j=i+1;j<=n;j++)
					{
						ratio = a[j][i]/a[i][i]; //sacamos ratio dividiendo el valor de la matriz en el que estamos entre el de la horizontal

						for(k=1;k<=n+1;k++)
						{
								a[j][k] = a[j][k] - ratio*a[i][k];
						}
					}
				}
				//metodo de sustitucion inversa
				x[n] = a[n][n+1]/a[n][n];

				for(i=n-1;i>=1;i--)
				{
					x[i] = a[i][n+1];
					for(j=i+1;j<=n;j++)
					{
							x[i] = x[i] - a[i][j]*x[j];
					}
					x[i] = x[i]/a[i][i];
				}

				//imprimir solucion
				cout<< endl<<"Resultados: "<< endl;
				for(i=1;i<=n;i++)
				{
					cout<<"x["<< i<<"] = "<< x[i]<< endl;
				}

				system("pause");
				system("cls");
				
					
			
			case 2:
				cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
				system("pause");
				system("cls");
				break;
				
				
			}

			

			if (op==2)
			{
				break;
			}
			
		}
		
		
		
		

		
		
	
	

	



	 return(0);
}
