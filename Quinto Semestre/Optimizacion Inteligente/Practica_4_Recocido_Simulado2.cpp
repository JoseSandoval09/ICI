/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	Practica 4
	Recocido simulado
	Consiste en un m�todo metaheuristico que permite solucionar problemas de optimizacion
	global. Debido a su naturaleza estocastica, este metodo garantaiza que, en sentido 
	probabilistico, el optimo global sera alcanzado
	
*/	

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

//declaramos una estructura para definir las coordenadas de cada ciudad
struct Ciudad {
    double x, y;
};

double calcular_distancia(const Ciudad& ciudad1 ,const Ciudad& ciudad2);
double calcular_distancia_total(const vector<int>& recorrido, const vector<Ciudad>& ciudades);
vector<int> generar_solucion_inicial(int num_ciudades);
vector<int> recocido_simulado(const vector<Ciudad>& ciudades, double temperatura_inicial, int iteraciones_max);


int main() {
	int end=0;
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE ENCONTRAR LA SOLUCION AL PROBLEMA DEL AGENTE VIAJERO USANDO EL RECOCIDO SIMULADO \n\n";
		cout << " Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Recocido Simulado (Agente Viajero) \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: {	
				system("cls");
				cout<<" RECOCIDO SIMULADO \n";
			    srand(time(NULL));
			    int num_ciudades = 25;
			    double temperatura_inicial = 1000;
			    int iteraciones_max = 2000;
			
			    //declaracion de un vector tipo struct en el cual tiene las coordenadas de las ciudades
			    vector<Ciudad> ciudades = {
			        {5,4},
			        {7,4},
			        {5,6},
			        {4,3},
			        {3,6},
			        {4,5},
			        {2,4},
			        {1,3},
			        {1,5},
			        {3,2},
			        {6,3},
			        {7,7},
			        {6,1},
			        {4,1},
			        {1,1},
			        {1,7},
			        {4,7},
			        {7,2},
			        {9,2},
			        {8,5},
			        {10,4},
			        {11,1},
			        {10,7},
			        {13,6},
			        {12,8},
			    };
			    
			    //se genera el mejor recorrido
			    vector<int> mejor_recorrido = recocido_simulado(ciudades, temperatura_inicial, iteraciones_max);
			
			    //impresion de mejor recorrido
			    cout << "\nMejor recorrido: [ ";
			   for( int i=0;i<=25;i++){
       			 cout<<mejor_recorrido[i]<<" ";
    			}
    			cout<<"]"<<endl;

			    cout << "Mejor distancia: " << calcular_distancia_total(mejor_recorrido, ciudades) << endl;  
			    
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




//funcion para evaluar la distancia entre cada ciudad de nuestra solucion
double calcular_distancia(const Ciudad& ciudad1, const Ciudad& ciudad2) {
    double dx = ciudad1.x - ciudad2.x;
    double dy = ciudad1.y - ciudad2.y;
    return sqrt(dx * dx + dy * dy);
}


// se genera una solucion inicial la solucion general es una lista de nuestras 25 ciudades
vector<int> generar_solucion_inicial(int num_ciudades) {
    vector<int> recorrido(num_ciudades);
	recorrido[0]=0;
	recorrido[25]=0; //se crea un vector de 25 posiciones
    for (int i = 1; i < num_ciudades; i++) {
        recorrido[i] = i; //se llena el vector con los numeros de las ciudades 
    }
	
   
   int j=0;
    //se reordenan de manera aleatoria las ciudades 
    for (int i = num_ciudades - 1; i > 0; i--) {
		do{
			j = rand() % (i + 1);
		}while(j==0 || j==25 );
   
    	swap(recorrido[i], recorrido[j]);
    }

    cout<<"Solucion inicial: [";
    for( int i=0;i<=num_ciudades;i++){
        cout<<recorrido[i]<<" ";
    }
    cout<<"]"<<endl;

    return recorrido;
}

//Se declaara una funcion para calcular la distancia total de nuestro recorrido ciudad por ciudad

double calcular_distancia_total(const vector<int>& recorrido, const vector<Ciudad>& ciudades) {
    double distancia = 0.0;
    for (int i = 0; i < recorrido.size(); i++) {
        distancia += calcular_distancia(ciudades[recorrido[i]], ciudades[recorrido[i + 1]]); //se calcula distancia entre ciudades y se saca la distancia total
    }
    //distancia += calcular_distancia(ciudades[recorrido.back()], ciudades[recorrido[0]]); //se calcula distancia de la ultima ciudad a la primera
    return distancia;
}


// declaramos un vector como funcion el cual nos regresara el recorrido de menor costo
vector<int> recocido_simulado(const vector<Ciudad>& ciudades, double temperatura_inicial, int iteraciones_max) { // se delcara el vector dandole como parametros nuestro vector de cordenadas de nuestras ciudades, temperatura inicial y las iteraciones maximas
    vector<int> recorrido_actual = generar_solucion_inicial(ciudades.size()); // creamos nuestro recorrido actual que seria nuestro recorrido inicial definido por la funcion generar_solucion_inicial
    double distancia_actual = calcular_distancia_total(recorrido_actual, ciudades); //sacamos nuestra distancia inicial con nuestra funcion previamente definida, pasandole como parametros nuestro recorrido inicial y las cordenadas de las ciudades
    vector<int> mejor_recorrido = recorrido_actual; //declaramos nuestro mejor recorrido como el recorrido inicial
    double mejor_distancia = distancia_actual; //declaramos la mejor distancia como nuestra distancia actual
    double temp=temperatura_inicial;
    int ite=0;
	int a=0;
	int b=0;

    cout<<"Distancia inicial: "<<distancia_actual<<endl;

	recorrido_actual[0]=recorrido_actual[25]=0;

    for (int iteracion = 0; iteracion < iteraciones_max; iteracion++) {


		do{
        a = rand() % ciudades.size(); //seleccionamos 2 valores aleatorios de nuestro recorrido de 25 ciudad y hacemos el cambio entre estas 2
        b = rand() % ciudades.size();
		
		}while(a==0 || b==0 ||a==25 || b==25 );



        swap(recorrido_actual[a], recorrido_actual[b]);
        double distancia_vecino = calcular_distancia_total(recorrido_actual, ciudades);
        double diferencia = distancia_vecino - distancia_actual; //calculamos diferencia entre distancia del vecino(nuevo recorrido generado al cambiar) y el actual

	
		double probabilidad=exp(-diferencia / temp);
		double random=(rand() / double(RAND_MAX));

        if (diferencia < 0 || random<probabilidad ) { //evaluamos si la diferencia es <0 si lo es remplazamops la distancia actual con la del vecino y sino evaluamos la funcion de probabilidad de aceptacion definida 
            distancia_actual = distancia_vecino;

            if (distancia_actual < mejor_distancia) { 
                mejor_recorrido = recorrido_actual; //actualizamos el mejor recorido
                mejor_distancia = distancia_actual; //actualizamos la mejor distancia
            }
        } else {
            swap(recorrido_actual[a], recorrido_actual[b]);
        }


        temp = 0.8*(temperatura_inicial/(1+iteracion)); //calculamos temperatura 
        
        ite=iteracion;
    }

	 
  

	mejor_recorrido[25]=0;

    return mejor_recorrido;
}
