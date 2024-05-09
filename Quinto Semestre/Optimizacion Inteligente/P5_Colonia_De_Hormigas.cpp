/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	C�sar Eduardo Elias del Hoyo 
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
	Sistema de colonia de hormigas
	EL algoritmo permite simular el recorrido de una hormiga en busca de comida, guiandose mediante 
	ferom�nas que van dejando como rastro las dem�s hormigas. Esto permite buscar caminos y obtener 
	una soluci�n �ptima a cierto problema
	
*/	

// Librer�as
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Par�metros
const int numMachines = 3;
const int numJobs = 3;
const int alpha = 1;
const int beta = 2;
const double evaporationRate = 0.1;
const double initialPheromone = 1.0;
const int numAnts = 50;

// STRUCT DE DEFINICION DEL NODO (JOB)
struct Job {
    int id;
    std::vector<std::pair<int, int>> operations;  // <Machine, Time>
};

// STRUCT DE DEFINICION DE LA HORMINGA
struct Ant {
    std::vector<std::pair<int, int>> tour;  // <Machine, Job>
    int makespan;
};

// FUNCIONES
std::vector<Job> jobs = {
    {1, {{1, 3}, {2, 3}, {3, 3}}},
    {2, {{3, 2}, {1, 3}, {2, 4}}},
    {3, {{2, 3}, {3, 3}, {1, 2}}}
};

std::vector<std::pair<int, int>> generateRandomTour() {
    std::vector<std::pair<int, int>> tour;
    for (int i = 1; i <= numJobs; ++i) {
        tour.push_back({rand() % numMachines + 1, i});
    }
    std::random_shuffle(tour.begin(), tour.end());
    return tour;
}

int calculateMakespan(const std::vector<std::pair<int, int>>& tour) {
    std::vector<int> machineTime(numMachines, 0);
    int makespan = 0;

    for (const auto& operation : tour) {
        int machine = operation.first - 1;
        int job = operation.second - 1;
        machineTime[machine] += jobs[job].operations[machine].second;
        makespan += jobs[job].operations[machine].second;
    }

    return makespan;
}

void updatePheromones(const std::vector<Ant>& ants) {
    // Actualiza las feromonas seg�n el resultado de las hormigas
}

Ant findBestAnt(const std::vector<Ant>& ants) {
    return *std::min_element(ants.begin(), ants.end(), [](const Ant& a, const Ant& b) {
        return a.makespan < b.makespan;
    });
}

void printTour(const std::vector<std::pair<int, int>>& tour) {
    for (const auto& operation : tour) {
        std::cout << "Machine " << operation.first << " -> Job " << operation.second << " | ";
    }
    std::cout << std::endl;
}

// MAIN
int main(){
	int end=0; 
	do{
		system ("cls");
		cout << " --- INICIO DEL PROGRAMA --- \n";
		cout << " ESTE PROGRAMA PERMITE ENCONTRAR UNA SOLUCION AL PROBLEMA APLICANDO EL ALGORITMO DE COLONIA DE HORMIGAS \n\n";
		cout << " Jose Luis Sandoval Perez \n Cesar Eduardo Elias del Hoyo \n\n";
		cout << " MENU \n\n Selecciona el metodo que deseas utilizar \n\n 1. Colonia de Hormigas \n 2. Salir \n ";
		cout << "\n Opcion: ";
		cin >> end;
		switch (end){
			case 1: {
				system("cls");
				cout<<" ALGORITMO COLONIA DE HORMIGAS \n SOLUCION PROBLEMA DE JOP SHOP \n\n";
				srand(static_cast<unsigned int>(time(nullptr)));

			    std::vector<Ant> ants;
			    for (int antIndex = 0; antIndex < numAnts; ++antIndex) {
			        Ant ant;
			        ant.tour = generateRandomTour();
			        ant.makespan = calculateMakespan(ant.tour);
			        ants.push_back(ant);
			    }
			
			    Ant bestAnt = findBestAnt(ants);
			    updatePheromones(ants);
			
			    std::cout << " Best Makespan = " << bestAnt.makespan << std::endl;
			    std::cout << " Best Tour: ";
			    printTour(bestAnt.tour);
			    std::cout << "\n\n";
			    system("pause");
				break;
			}
			case 2: 
				system("cls");
				end=2;
				break;
			default: system("cls"); cout << " OPCION INVALIDA"; break;
		}	
	}while(end != 2);
	cout << " Saliendo del programa ... Hasta luego \n\n";
	return 0;
}
