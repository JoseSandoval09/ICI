/*	Univeridad Autonoma de Aguascalientes
	Ingenieria en Computacion Inteligente
	Alumnos: 
	Ximena Rivera Delgadillo
	Jose Luis Sandoval Perez
	ID:261261
	ID:261731
	Maestro: Luis Fernando Guitierrez Marfile�o
	Este programa calcula valores para la funcion tan(x) mediante series de Taylor
*/

#include <iostream>
#include<stdio.h>
#include <math.h>
#include <string>

using namespace std;

#define pi 3.141592653589793

double conversion(double grados)
{
	double radianes = 0; 
	radianes = grados * (pi/180);
	return radianes;
}

int factorial(int fact){
    if(fact==1 | fact ==0){
        return 1;
    }else{
        return factorial(fact-1) * fact;
    }
}

double SerieTaylorTangente(int termino, double angulo){
    if(termino ==2){
        return angulo;
    }else if(termino ==4){
        return 2 * pow(angulo, 3) / factorial(3);
    }else if(termino == 6){
        return 16 * pow(angulo,5) / factorial(5);
    }else
        return 0;
}

bool IsNumber(string maybeNumber){
    int contPunt = 0;
    for(int i =0; i<maybeNumber.length(); i++){
        if(maybeNumber[i]<46 ||  maybeNumber[i]> 57 || maybeNumber[i]==47)
            return false;
        if(maybeNumber[i]==46)
            contPunt++;
    }
    if(contPunt>1)
        return false;
    else    
        return true;
}

int main()
{
	bool listo = false;
	int op;
	double diferencia;
    double terminos = 0;
    double val_x = 0;
    double val_x_rad =0;
    double valorTaylor = 0;
    double valorFuncion = 0;
    
	cout<<"\t\tI N T R O D U C C I O N\n Este programa calcula el valor de la funcion tan(x) mendiante series de Taylor\n";
	cout<<"-------------------------------------------------------------------------------\n";
	system("pause");
	system("cls");

	while(op!=3)
	{
		cout<<"\tM  E  N  U\n 1-Calcular tan(x)\n 2-Salir\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"Opcion: ";
		cin>>op;
	    cout<<"-------------------------------------------------------------------------------\n";
	    system("pause");
        system("cls");
		switch(op)
		{
			case 1:
		    	cout<<"\t\tSERIES DE TAYLOR tan(X)\n";
		    	cout<<" Ingresa el valor del angulo en grados: "; cin>>val_x;
			    cout<<endl;
			    while(val_x<=-999 ||val_x>=999){
			        cout<<" Error, el valor ingresado es muy chico o muy grande\nIntentalo de nuevo...";
			        cout<<"-------------------------------------------------------------------------------\n";
	    			system("pause");
        			system("cls");
			        cout<<" Ingresa el valor del angulo en grados: "; cin>>val_x;
			    }
    			val_x_rad = conversion(val_x);
    			cout<<"-------------------------------------------------------------------------------\n\n";
					diferencia = 0;
				cout<<" Ingresa la cantidad de terminos que quieres de la serie (2 , 4 , 6): "; cin>>terminos;
				cout<<endl;
				while(terminos<1 || terminos>=7){
				    cout<<" Error, no me has proporcionado un numero entre 1 y 6\n";
				    cin>>terminos;
				}
				    valorTaylor = 0;
				    for (int i =1; i <= terminos; i++)
				    {
				        valorTaylor += SerieTaylorTangente(i,val_x_rad);
				    }
				    cout<<"-------------------------------------------------------------------------------\n";
				    cout<<"\t\tR E S U L T A D O S\n";
				    cout<<" -La serie de taylor con "<<terminos<<" terminos de tan(x) evaluada en el angulo "<< val_x << " es: " << valorTaylor<<endl;
				    cout<<" -A comparacion con la funcion de tan(x) de math.h que da como valor: "<< tan(val_x_rad)<<endl;
				    diferencia = tan(val_x_rad) - valorTaylor;
				    cout<<" -Por lo que tenemos una magnitud de error por truncamiento de: "<<diferencia<<"\n";
				    cout<<"-------------------------------------------------------------------------------\n";
					system("pause");
				    system("cls");
		    break;
		    case 2:
		    	cout<<"-------------------------------------------------------------------------------\n";
	            cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";
	        return 0;
		}
	}
}
