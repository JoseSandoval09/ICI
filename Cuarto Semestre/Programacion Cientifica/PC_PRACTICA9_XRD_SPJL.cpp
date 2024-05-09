/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa utiliza los metodos de minimos cuadrados, interpolacion unica, interpolacion Lagrange y Interpolacion Newtonb
*/


#include<iostream>
#include<math.h>

using namespace std;

void minimoscuadrados();
void polinomiointerpolacion();
void interNewton();
void lagrange();


int main(){

    int op;

    do{
    cout<<"\t-----------------PRACTICA 9-------------------"<<endl;

    cout<<"1.Minimos Cuadrados\n2.Interpolacion Unica\n3.Interpolacion Lagrange\n4.Interpolacion Newton\n5.Salir"<<endl;

    cout<<"Seleccione una opcion: "; cin>>op;

   
    system("cls");

    switch (op)
    {
    case 1:
        minimoscuadrados();
        system("pause");
        system("cls");
        break;
    case 2:
        polinomiointerpolacion();
        system("pause");
        system("cls");
        break;
    case 3:
        lagrange();
        system("pause");
        system("cls");
        break;
    case 4:
        interNewton();
        system("pause");
        system("cls");
        break;
   
    }

    }while(op!=5);

    cout<<"SALIR!!!SALIR!!"<<endl;

    cout<<"PROGRAMA REALIZADO POR: \nXIMENA RIVERA DELGADILLO\nJOSE LUIS SANDOVAL PEREZ"<<endl;
    


 

   




    return 0;
}

void minimoscuadrados()
{
    int data{0};

    cout<<"\t----------------METODO DE MINIMOS CUADRADOS-------------------"<<endl;
    cout<<"Ingrese numero de coordenadas: ";
    cin>>data;

    int x[data];
    int y[data];
    int xy[data];
    double xsquare[data];
    double sumx{0};
    double sumy{0};
    double sumxy{0};
    double sumxquare{0};

    cout<<"Ingresa datos de x"<<endl;
    for(int i=0;i<data;i++){
        
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
    }


    cout<<"Ingresa datos de y"<<endl;
    for(int i=0;i<data;i++){
        cout<<"y["<<i<<"]: ";
        cin>>y[i];
    }

    for(int i=0;i<data;i++){
        sumy=sumy+y[i];
        sumx=sumx+x[i];
        sumxquare=sumxquare+(x[i]*x[i]);
        sumxy=sumxy+(x[i]*y[i]);
    }


    
    double a1,a0;


   //a1=(sumxy-sumx*sumy/data)/(sumxquare-sumx*sumx/data);
   a1=(data*sumxy-sumx*sumy)/(data*sumxquare-sumx*sumx);
   a0=(sumy-a1*sumx)/data;


    cout<<"Ecuacion de regresion linea: "<<a1<<"x+"<<a0<<endl;
    cout<<"Peso aproximado para un persona de 6 años = "<<a1*6+a0<<endl;

}

void polinomiointerpolacion(){

     cout<<"\t----------------METODO DE POLINOMIO UNICO-------------------"<<endl;

    int coord{0};

    cout<<"Ingresa numero de coordenadas: ";
    cin>>coord;


    double matrix[coord][coord+1]; 

    cout<<"A continuacion tendras que ingresar las coordenadas de la siguiente manera\n-El coeficiente 1 en cada coordenada sera 1\n-El coeficiente 2 sera el valor de x \n-El valor del coeficiente 3 sera x al cuadrado\n-El termino independiente sera el valor de y "<<endl;
   
   for (int i = 0; i < coord; i++) {
    cout << "\nCoordenada  " << i+1<<endl;
      for (int j = 0; j < coord+1; j++) {
         
         if(j!=coord){
            cout<<"coeficiente "<<j+1<<" :";
         }
         
         if(j==coord){
            cout<<"Termino independiente: ";
         }
         cin >> matrix[i][j];
      }
   }

    double inter{0.0};
   cout<<"\nIngresa valor a interpolar:";
   cin>>inter;

   //se utiliza la regla de crammer para obtener valor de a0,a1,a2

    double detMatrix = (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])) -
                       (matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])) +
                       (matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]));

   

    double solutionesA[3];
    for (int i = 0; i < 3; i++) {
        double tempMatrix[3][3];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == i)
                    tempMatrix[j][k] = matrix[j][3];
                else
                    tempMatrix[j][k] = matrix[j][k];
            }
        }
        double detX = (tempMatrix[0][0] * (tempMatrix[1][1] * tempMatrix[2][2] - tempMatrix[1][2] * tempMatrix[2][1])) -
                      (tempMatrix[0][1] * (tempMatrix[1][0] * tempMatrix[2][2] - tempMatrix[1][2] * tempMatrix[2][0])) +
                      (tempMatrix[0][2] * (tempMatrix[1][0] * tempMatrix[2][1] - tempMatrix[1][1] * tempMatrix[2][0]));

        solutionesA[i] = detX / detMatrix;
    }

    cout << "Las soluciones del sistema son:" << endl;
    cout << "a0 = " << solutionesA[0] << endl;
    cout << "a1 = " << solutionesA[1] << endl;
    cout << "a2 = " << solutionesA[2] << endl;

    cout<<"P del valor a interpolar es="<<solutionesA[0]+solutionesA[1]*inter+solutionesA[2]*(inter*inter)<<endl;

}

void lagrange(){

     cout<<"\t----------------METODO DE LAGRANGE-------------------"<<endl;
    int data;

    cout << "Ingrese el número de coordenadas: ";
    cin >> data;

    double x[data], y[data];

    cout<<"A continuacion ingresa las coordenadas xy \n"<<endl;

    // Leer las coordenadas
    for (int i = 0; i < data; i++) {
        cout << "Ingrese la coordenada x[" << i << "]: ";
        cin >> x[i];
        cout << "Ingrese la coordenada y[" << i << "]: ";
        cin >> y[i];
    }

    // Mostrar polinomios generados
    cout << "\nEl polinomio interpolante es:\n";
    for (int i = 0; i < data; i++) {
        cout<<"L"<<i<<"=";
        cout << "(" << y[i] << ")";

        for (int j = 0; j < data; j++) {
            if (j != i) {
                cout << "(x - " << x[j] << ") / (" << x[i] << " - " << x[j] << ")";
            }
        }

        if (i != data - 1) {
            cout << " + "<<endl;
        }
    }

    // Interpolar un valor
    double xi;

    cout << "\n\nIngrese el valor de x para interpolar: ";
    cin >> xi;

    double result = 0.0;

    for (int i = 0; i < data; i++) {
        double term = y[i];

        for (int j = 0; j < data; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }


    double yi = result;

    cout << "El valor interpolado para x = " << xi << " es  = " << yi <<endl;
}

void interNewton(){

     cout<<"\t----------------METODO DE NEWTON-------------------"<<endl;

    int data;
    cout << "Ingrese el número de coordenadas: ";
    cin >> data;

    double x[10];
    double y[10];

    cout<<"A continuacion ingresa las coordenadas x,y separadas por un espacio\n"<<endl;

    cout << "Ingrese las coordenadas (x, y):" << endl;
    for (int i = 0; i < data; i++) {
        cout << "Coordenada " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double tabladiferenciasDivididas[10][10];

    for (int i = 0; i < data; i++) {
        tabladiferenciasDivididas[i][0] = y[i];
    }

    // Calcular las diferencias divididas
    for (int j = 1; j < data; j++) {
        for (int i = 0; i < data - j; i++) {
            tabladiferenciasDivididas[i][j] = (tabladiferenciasDivididas[i + 1][j - 1] - tabladiferenciasDivididas[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    double coeficientes[10];
    for (int i = 0; i < data; i++) {
        coeficientes[i] = tabladiferenciasDivididas[0][i];
    }

    //mostrando polinomio
    cout << "P(x) = ";
    for (int i = 0; i < data; i++) {
        cout << coeficientes[i];

        for (int j = 0; j < i; j++) {
            cout << "*(x - " << x[j] << ")";
        }

        if (i != data - 1) {
            cout << " + ";
        }
    }

    cout << endl;

}