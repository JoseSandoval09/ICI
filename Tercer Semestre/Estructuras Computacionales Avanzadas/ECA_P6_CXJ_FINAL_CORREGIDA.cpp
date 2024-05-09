#include <iostream>
using namespace std;
/*
Universidad Autonoma De Aguascalientes
Ingenier�a en Computacion Inteligencia
Estructuras Computacionales Avanzadas

El�as Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfile�o

 I N S T R U C C I O N E S
Para la creaci�n del programa deber�n realizarse los siguientes pasos:
1. En las primeras l�neas elaborar comentarios con la siguiente informaci�n:
a. Nombre de la instituci�n
b. Nombre de la carrera
c. Nombre de la materia
d. Nombre(s) de quien(es) realiza(n) la pr�ctica
e. Nombre del profesor
f. Una descripci�n breve de lo que realiza el programa
2. Solicitar al usuario en n�mero de nodos del grafo (m�ximo 10).
3. A partir del cual se definir� la dimensi�n de la matriz de adyacencia.
4. Crear un men� que contenga las siguientes opciones:
a. Solicitar los valores de la presencia o no de arcos en cada elemento de la matriz.
b. Determinar y se�alar al usuario si el grafo analizado es o no un �rbol.
c. Una opci�n para salir

*/
void menu();
void makematrix(int n);
void printmatrix(int n);
void arbol_o_noarbol(int n);
int matrix[10][10] = {
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};

int matrix_aux[10][10] = {
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
};







int main()
{
    
    cout << "\tI N T R O D U C C I O N  del  p r o g r a m a" << endl;
    cout << "El siguiente programa nos permitira identificar a traves de la matriz de adyacencias de un grafo x,\n";
    cout << "si el grafo ingresado es o no un arbol";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    menu();
}

void menu() {

    int opcion , n;

    do{
        cout<<" M E N U "<<endl;

        cout<<"1. Ingresar matriz de adyacencia\n2.Determinar si el grafo es un arbol\n3.Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        system("pause");
        system("cls");

    
        switch (opcion)
        {
            case 1:
                cout << "\tR E A L I Z A C I O N  de la MATRIZ de ADYACENCIAS" << endl;
                cout << "Ingresa numero de nodos del grafo: "; cin >> n;
                if (n <= 10) {
                    makematrix(n);
                }
                else {
                    cout << "ERROR el grado maximo del grafo es de 10\n";
                    cout << "v u e l v e l o   a   i n t e n t a r...\n";
                    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
                    system("pause");
                    system("cls");
                    cout << "Ingresa nodos del grafo: "; cin >> n;
                }
                cout << "\n-------------------------------------------------------------------------------------------------" << endl;
                system("pause");
                system("cls");
            break;

            case 2:
                cout<<" M A T R I Z   i n g r e s a d a "<<endl;

                cout<<"----------------------------------------"<<endl;
                printmatrix(n);
                cout<<"\n----------------------------------------"<<endl;
                arbol_o_noarbol(n);

                system("pause");
                system("cls");
            
            default:
                cout<<"Opcion invalida ";
                break;
        }
    }while(opcion!=3);
}

void makematrix(int n) {
    int i, j;
  
    cout << "\nA D Y A C E N C I A S entre N O D O S\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
                
            cout << "EXISTE adyacencia entre los nodos(" << i+1 << ") (" << j+1 << ") escribe 1=SI o 0=NO *ADVERTENCIA: LA CONEXION DE 1-2 Y 2-1 ES LA MISMA, REPORTAR CON 0 LA CONEXION INVERTIDA SI ES QUE YA EXISTE:\n";
            cin >> matrix[i][j];
            if (matrix[i][j] > 1)
            {
                cout << "\n-------------------------------------------------------------------------------------------------" << endl;
                cout << "ERROR valor no existente\n";
                cout << "v u e l v e l o   a   i n t e n t a r...\n";
                j--;
                system("pause");
                system("cls");
            }
        }
    }
}

void printmatrix(int n) {
    int i, j;
    cout << "M A T R I Z   de  A D Y A C E N C I A S\n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout << "\t";
    }
}

void arbol_o_noarbol(int n){
    int i,j;

    bool tree=true;


    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i==j && matrix[i][j]==1 ){
                cout<<"El grafo al tener adyacencia en la posicion ["<<i<<"]" <<" ["<<j<<"]"<<" ya que presenta un ciclo en esa posicion\n";
                tree=false;
            } 
			if(matrix[i][j]==1 && matrix[i+1][j]==1){
                cout<<"El grafo al tener 2 conexion en una columna presenta un circuito\n";
                tree=false;
            }   
        }
    }

    if(tree!=false){
        cout<<" EL GRAFO SI ES UN ARBOL"<<endl;
    }
    else{
    	cout<<"\n EL GRAFO NO ES UN ARBOL "<<endl;
	}
	cout<<"\n";

}
