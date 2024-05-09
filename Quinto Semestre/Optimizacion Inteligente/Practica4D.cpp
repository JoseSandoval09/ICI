/*
Universidad Autonoma de Aguascalientes

Centro de Ciencias Basicas

Departamento de Computacion

Optimizacion Inteligente

Cesar Donnet Hernandez Gastelum 283189

LUIS FERNANDO GUTIERREZ MARFILEÑO


Este programa resuelve el problema de TSP del viajero que debe visitar 25 ciudades empezando por una de ellas y terminan en esa misma con el menor recorrido posible, 
el programa usa el algoritmo de recocido simulado para resolverlo


*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct City {
    std::string name;
    int x;
    int y;

    City(std::string n, int xx, int yy) : name(n), x(xx), y(yy) {}
};
std::vector<City> generate_unique_cities(int num_cities, const std::vector<City>& available_cities) {
    std::vector<City> cities;

    for (int i = 0; i < num_cities; ++i) {
        while (true) {
            City city = available_cities[rand() % available_cities.size()];
            bool city_exists = false;
            for (size_t j = 0; j < cities.size(); ++j) {
                if (cities[j].name == city.name) {
                    city_exists = true;
                    break;
                }
            }
            if (!city_exists) {
                cities.push_back(city);
                break;
            }
        }
    }

    return cities;
}


void print_city_map(const std::vector<City>& cities) {
    const int map_size = 13;  // Tamaño del mapa (ajusta según sea necesario)

    for (int y = map_size; y >= 0; --y) {
        for (int x = 0; x <= map_size; ++x) {
            bool city_found = false;

            for (size_t i = 0; i < cities.size(); ++i) {
                if (cities[i].x == x && cities[i].y == y) {
                    city_found = true;
                    break;
                }
            }

            if (city_found) {
                std::cout << "x ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}


double calculate_distance(const City& city1, const City& city2) {
    return sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2));
}

void print_coordinates_table(const std::vector<City>& route) {
    std::cout << "\nTabla de Coordenadas:\n";
    std::cout << "+--------------+--------------+\n";
    std::cout << "|   Ciudad     | Coordenadas  |\n";
    std::cout << "+--------------+--------------+\n";
    for (size_t i = 0; i < route.size(); ++i) {
        std::cout << "|    " << route[i].name << "    | (" << route[i].x << ", " << route[i].y << ")  |\n";
    }
    std::cout << "|    " << route[0].name << "    | (" << route[0].x << ", " << route[0].y << ")  |\n";
    std::cout << "+--------------+--------------+\n";
}

double calculate_fitness(const std::vector<City>& route) {
    double total_distance = 0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        total_distance += calculate_distance(route[i], route[i+1]);
    }
    total_distance += calculate_distance(route.back(), route[0]);
    return total_distance;
}

std::vector<City> mutate(std::vector<City> individual) {
    int index1 = rand() % (individual.size() - 2) + 1;
    int index2 = rand() % (individual.size() - 2) + 1;
    City temp = individual[index1];
    individual[index1] = individual[index2];
    individual[index2] = temp;
    return individual;
}
std::vector<City> simulated_annealing(int num_generations, const std::vector<City>& cities, double initial_temp, double cooling_rate, double final_temp) {
    std::vector<City> current_solution = cities;
    double current_cost = calculate_fitness(current_solution);
    std::vector<City> best_solution = current_solution;
    double best_cost = current_cost;

    for (int generation = 0; generation < num_generations; ++generation) {
        double temperature = std::max(final_temp, initial_temp * pow(cooling_rate, generation));

        std::vector<City> neighbor_solution = mutate(current_solution);
        double neighbor_cost = calculate_fitness(neighbor_solution);

        if (neighbor_cost < current_cost || rand() / double(RAND_MAX) < exp((current_cost - neighbor_cost) / temperature)) {
            current_solution = neighbor_solution;
            current_cost = neighbor_cost;
        }

        if (current_cost < best_cost) {
            best_solution = current_solution;
            best_cost = current_cost;
        }

        if (generation == 0) {
            cout << "\t\tMapa Cartesiano de 13x13\n\n";
            print_city_map(cities);
            std::cout << "Generación " << (generation + 1) << ": la Mejor distancia recorrida es = " << best_cost << "\n";
            print_coordinates_table(best_solution);
        }

    }

    return best_solution;
}




int main() {
	
	//Declaracion de las ciudades (paises) y sus respectivas posiciones
   std::vector<City> available_cities;

    available_cities.push_back(City("Ecuador", 5, 4));
    available_cities.push_back(City("Colombia", 7, 4));
    available_cities.push_back(City("Paraguay", 5, 6));
    available_cities.push_back(City("Uruguay", 4, 3));
    available_cities.push_back(City("Bolivia", 3, 6));
    available_cities.push_back(City("Venezuela", 4, 5));
    available_cities.push_back(City("Guatemala", 2, 4));
    available_cities.push_back(City("Honduras", 1, 3));
    available_cities.push_back(City("Nicaragua", 1, 5));
    available_cities.push_back(City("Barbados", 3, 2));
    available_cities.push_back(City("Guyana", 6, 3));
    available_cities.push_back(City("Jamaica", 7, 7));
    available_cities.push_back(City("Haiti", 6, 1));
    available_cities.push_back(City("Belice", 4, 1));
    available_cities.push_back(City("Trinidad", 1, 1));
    available_cities.push_back(City("Panama", 1, 7));
    available_cities.push_back(City("Surinam", 4, 7));
    available_cities.push_back(City("Canada", 7, 2));
    available_cities.push_back(City("ElSalvador", 9, 2));
    available_cities.push_back(City("Cuba", 8, 5));
    available_cities.push_back(City("Bahamas", 10, 4));
    available_cities.push_back(City("Mexico", 11, 1));
    available_cities.push_back(City("Brasil", 10, 7));
    available_cities.push_back(City("Peru", 13, 6));
    available_cities.push_back(City("Argentina", 12, 8));

    int num_cities = 25;
     std::vector<City> cities = generate_unique_cities(num_cities, available_cities);
    int num_generations;
    double initial_temp, rate_coling, final_temp;
    
    int opc=0;
    while(opc!=2){
    	cout<<"\t\t MENU\n";
    	cout<<"1.Ejecutar programa\n";
    	cout<<"2.Salir\n";
    	cout<<"Eleccion: ";
    	cin>>opc;
    	if(opc == 1){
    		system("cls");
    std::cout << "Cuantas iteraciones quieres? ";
    std::cin >> num_generations;
    std::cout << "Cuanta temperatura inicial? ";
    std::cin >> initial_temp;
    std::cout<< "Cuanto de temperatura final ? ";
    std::cin>> final_temp;
    std::cout << "Cuanto de coling rate? ";
    std::cin >> rate_coling;

std::vector<City> best_route = simulated_annealing(num_generations, cities, initial_temp, rate_coling, final_temp);
    double best_distance = calculate_fitness(best_route);
	std::cout << "\n Generacion : "<<num_generations<<" la distancia total recorrida es: " << best_distance << "\n";

    print_coordinates_table(best_route);
    
    
   
		}else if(opc != 2){
			cout<<"Opcion invalida  \n";
			system("pause");
			system("cls");
		}else{
			return 0;
		}
	}
    


    return 0;
}

