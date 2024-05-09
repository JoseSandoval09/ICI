/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
    Ejercicio Examen 2

	Recocido simulado

    Programar operaciones consiste en el proceso de organizar, elegir y dar tiempos al uso de recursos para llevar a cabo todas las actividades 
    necesarias para producir las salidas deseadas en los tiempos deseados, satisfaciendo a la vez un gran número de restricciones 
    de tiempo y relaciones entre las actividades y los recursos.
	
*/	

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

//declaramos una estructura para definir las coordenadas de maquina
struct Maquina {
    double t1,t2,t3,t4;
};


vector<int> generar_solucion_inicial(int num_ciudades);
vector<int> recocido_simulado(const vector<Maquina>& OrganizacionMaquinas, double temperatura_inicial, int iteraciones_max);


int main() {
	int end=0;
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE ENCONTRAR LA SOLUCION AL PROBLEMA De Flow-Shop USANDO EL RECOCIDO SIMULADO \n\n";
		cout << " Jose Luis Sandoval Perez \n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Recocido Simulado (Agente Viajero) \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: {	
				system("cls");
				cout<<" RECOCIDO SIMULADO \n";
			    srand(time(NULL));
			    int num_trabajos = 4;
			    double temperatura_inicial = 1000;
			    int iteraciones_max = 500;
			
			   
			    vector<Maquina> OrganizacionMaquinas = {
			        {5,1,7,2},
			        {8,7,2,3,},
			        {9,3,6,4},
			    };
			    
			    //se genera el mejor recorrido
                recocido_simulado(OrganizacionMaquinas, temperatura_inicial, iteraciones_max);

			    
			    
				system("pause");
				break;
			}
    		case 2: 
				system("cls");
				end=2;
				break;
				
			default: system("cls"); cout << " OPCION INVALIDA"; break;
		}
	}while (end != 2);
	cout << " Saliendo del programa ... Hasta luego \n\n";
	return 0;
}











vector<int> recocido_simulado(const vector<Maquina>& OrganizacionMaquinas, double temperatura_inicial, int iteraciones_max) {
    
    int ite=0;
	int a=0;
	int b=0;
    int temp=temperatura_inicial;

    vector<int> maquina1={5,1,7,2};
    vector<int> maquina2={8,7,2,3};
    vector<int> maquina3={9,3,6,4};





    for (int iteracion = 0; iteracion < iteraciones_max; iteracion++) {

        int maquinaswap=1+rand() % 4;

        switch (maquinaswap)
        {
        case 1:
            
        a = rand() % 4; 
            swap(maquina1[a], maquina1[b]);
		
            break;

        case 2:
            
        a = rand() % 4; 
        b = rand() % 4;
            swap(maquina2[a], maquina2[b]);
		
            break;

        case 3:
            
        a = rand() % 4; 
        b = rand() % 4;
            swap(maquina3[a], maquina3[b]);
		
            break;
        
        default:
            break;
        }

	

       

        temp =(temperatura_inicial/(1+log(ite))); //calculamos temperatura 
        
        ite=iteracion;
    }

	 
     
    cout<<"maquina 1\t";

    for (int i=0;i<=3;i++){
        cout<<"\t"<<maquina1[i];
        cout<<"\t";
    };
    cout<<endl;
      cout<<"maquina 2\t";
    for(int i=0;i<=3;i++){
       cout<<"\t"<<maquina2[i];
        cout<<"\t";
    };
    cout<<endl;
      cout<<"maquina 3\t";
    for(int i=0;i<=3;i++){
       cout<<"\t"<<maquina1[i];
        cout<<"\t";
    };

    cout<<endl;

    cout<<"El valor en cada maquina se refiere al numero de trabajo, ver en tabla previamente mostrada que valor corresponde a cada trabajo";



    
}
