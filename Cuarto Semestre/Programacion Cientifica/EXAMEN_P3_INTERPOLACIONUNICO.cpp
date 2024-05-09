/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Departamento de ciencias de la computacion
Jose Luis Sandoval Perez
Luis Fernando Guiterrez Marfileño
Examen Tercer Parcial Polinomio unico de interpolacion

Este programa utiliza el metodo de interpolacion unica para los siguientes valores (8,0.5), (18,0.4), (28, 0.6) interpolandolo con un valor de x=12
*/

#include<iostream>
#include<math.h>

using namespace std;

void polinomiointerpolacion();

int main(){

    int op=0;



    do{

        cout<<"POLINIOMIO DE INTERPOLACION UNICA EXAMEN PARCIAL 3"<<endl<<endl;

        cout<<"Este programa utiliza el metodo de interpolacion unica para los siguientes valores (8,0.5), (18,0.4), (28, 0.6) interpolandolo con un valor de x=12"<<endl<<endl;

        cout<<"Selecciona una opcion: \n1.Poliniomio de interpolacion\n2.Salir"<<endl;
        cout<<"Opcion: "; cin>>op;

        system("cls");

        switch (op)
        {
        case 1:
            polinomiointerpolacion();
            break;
        
        default :
            system("pause");
            system("cls");
        }






    }while(op!=2);

    cout<<"DECIDISTE SALIR!!! ES TODO!!\n Jose Luis Sandoval Perez";






    return 0;
}
void polinomiointerpolacion(){

     cout<<"\t----------------METODO DE POLINOMIO UNICO-------------------"<<endl;

    int coord=0;

    cout<<"Ingresa numero de coordenadas: ";
    cin>>coord;


    double matrix[coord][coord+1]; 



    matrix[0][0]=1;
    matrix[1][0]=1;
    matrix[2][0]=1;
    matrix[0][1]=8;
    matrix[0][2]=64;
    matrix[0][3]=0.5;
    matrix[1][1]=18;
    matrix[1][2]=324;
    matrix[1][3]=0.4;
    matrix[2][1]=28;
    matrix[2][2]=784;
    matrix[2][3]=0.6;



    double inter=0.0;
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

    cout<<"valor aproximado de x="<<inter<<" es="<<solutionesA[0]+solutionesA[1]*inter+solutionesA[2]*(inter*inter)<<endl;

    system("pause");
    system("cls");

}