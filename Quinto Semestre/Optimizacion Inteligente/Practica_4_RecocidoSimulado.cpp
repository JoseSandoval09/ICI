//Universidad Autonoma De Aguascalientes
//Centro de Ciencias Basicas
//Departamento de computacion
//Ingenieria en computacion inteligente
//Practica 4 - Recocido Simulado
//Cesar Eduardo Elias Del Hoyo
//Jose Luis Sandoval Perez

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
    srand(time(NULL));
    int num_ciudades = 25;
    double temperatura_inicial = 1000;
    int iteraciones_max = 1000;

    //declaracion de un vector tipo struct en el cual tiene las coordenadas de las ciudades
    vector<Ciudad> ciudades = {
        {5, 4},
        {7, 4},
        {5, 6},
        {4.3},
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
        {12,8}
    };
    
    //se genera el mejor recorrido
    vector<int> mejor_recorrido = recocido_simulado(ciudades, temperatura_inicial, iteraciones_max);

    //impresion de mejor recorrido
    cout << "Mejor recorrido: ";
    for (int ciudad : mejor_recorrido) {
        cout << ciudad << " ";
    }
    cout << endl;
    cout << "Mejor distancia: " << calcular_distancia_total(mejor_recorrido, ciudades) << endl;

  
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
    vector<int> recorrido(num_ciudades); //se crea un vector de 25 posiciones
    for (int i = 0; i < num_ciudades; i++) {
        recorrido[i] = i; //se llena el vector con los numeros de las ciudades 
    }
   
    //se reordenan de manera aleatoria las ciudades 
    for (int i = num_ciudades - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    swap(recorrido[i], recorrido[j]);
    }

    cout<<"Solucion inicial: [";
    for( int i=0;i<num_ciudades;i++){
        cout<<recorrido[i]<<" ";
    }
    cout<<"]"<<endl;

    return recorrido;
}

//Se declaara una funcion para calcular la distancia total de nuestro recorrido ciudad por ciudad

double calcular_distancia_total(const vector<int>& recorrido, const vector<Ciudad>& ciudades) {
    double distancia = 0.0;
    for (int i = 0; i < recorrido.size() - 1; i++) {
        distancia += calcular_distancia(ciudades[recorrido[i]], ciudades[recorrido[i + 1]]); //se calcula distancia entre ciudades y se saca la distancia total
    }
    distancia += calcular_distancia(ciudades[recorrido.back()], ciudades[recorrido[0]]); //se calcula distancia de la ultima ciudad a la primera
    return distancia;
}


// declaramos un vector como funcion el cual nos regresara el recorrido de menor costo
vector<int> recocido_simulado(const vector<Ciudad>& ciudades, double temperatura_inicial, int iteraciones_max) { // se delcara el vector dandole como parametros nuestro vector de cordenadas de nuestras ciudades, temperatura inicial y las iteraciones maximas
    vector<int> recorrido_actual = generar_solucion_inicial(ciudades.size()); // creamos nuestro recorrido actual que seria nuestro recorrido inicial definido por la funcion generar_solucion_inicial
    double distancia_actual = calcular_distancia_total(recorrido_actual, ciudades); //sacamos nuestra distancia inicial con nuestra funcion previamente definida, pasandole como parametros nuestro recorrido inicial y las cordenadas de las ciudades
    vector<int> mejor_recorrido = recorrido_actual; //declaramos nuestro mejor recorrido como el recorrido inicial
    double mejor_distancia = distancia_actual; //declaramos la mejor distancia como nuestra distancia actual
    double temp=0;
    int ite=0;

    cout<<"Distancia inicial: "<<distancia_actual;

    for (int iteracion = 0; iteracion < iteraciones_max; iteracion++) {
        int a = rand() % ciudades.size(); //seleccionamos 2 valores aleatorios de nuestro recorrido de 25 ciudad y hacemos el cambio entre estas 2
        int b = rand() % ciudades.size();
        swap(recorrido_actual[a], recorrido_actual[b]);
        double distancia_vecino = calcular_distancia_total(recorrido_actual, ciudades);
        double diferencia = distancia_vecino - distancia_actual; //calculamos diferencia entre distancia del vecino(nuevo recorrido generado al cambiar) y el actual

        if (diferencia < 0 || (rand() / double(RAND_MAX)) < exp(-diferencia / temperatura_inicial)) { //evaluamos si la diferencia es <0 si lo es remplazamops la distancia actual con la del vecino y sino evaluamos la funcion de probabilidad de aceptacion definida 
            distancia_actual = distancia_vecino;

            if (distancia_actual < mejor_distancia) { 
                mejor_recorrido = recorrido_actual; //actualizamos el mejor recorido
                mejor_distancia = distancia_actual; //actualizamos la mejor distancia
            }
        } else {
            swap(recorrido_actual[a], recorrido_actual[b]);
        }

        temp = 0.8*(temperatura_inicial/(1+iteracion)); //calculamos temperatura 
         // Ajuste de temperatura
        if(temp<=20){ //condicion de paro 
            break;
        }
        ite=iteracion;
    }

    cout<<"\nTemperatura minima alcanzada: "<<temp<<" en "<<ite<<"iteraciones"<<endl;

    return mejor_recorrido;
}

