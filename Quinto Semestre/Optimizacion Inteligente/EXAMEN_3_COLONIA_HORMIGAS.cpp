/* 	
	UNIVERSIDAD AUT�NOMA DE AGUASCALIENTES
	Centro de Ciencias B�sicas
 	Departamento Ciencias de la Computaci�n
	Optimizaci�n Inteligente
	
	Jos� Luis Sandoval Perez
	
	Maestro: Luis Fernando Gutierrez Marfile�o
	
    Ejercicio Examen 

	Colonia de hormigas

    Se tiene una instancia del problema del agente viajero con 10 ciudades, el objetivo es encontrar el menor recorrido, en el que, partiendo de una ciudad se pase una vez por todas las demás y se regrese a la ciudad inicial.
	

*/	

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

const int num_cities = 11;
const int num_ants = 5;
const double alpha = 1.0;
const double beta = 2.0;
const double rho = 0.5;
const double initial_pheromone = 1.0;
const double pheromone_deposit = 5.0;
const int max_iterations = 100;

struct City {
    int x, y;
};

double distance(const City& city1, const City& city2) {
    return sqrt(pow(city1.x - city2.x, 2) + pow(city1.y - city2.y, 2));
}

void initializePheromones(vector<vector<double>>& pheromone_matrix) {
    for (int i = 0; i < num_cities; ++i) {
        vector<double> row(num_cities, initial_pheromone);
        pheromone_matrix.push_back(row);
    }
}

int selectNextCity(int current_city, const vector<int>& not_visited, const vector<vector<double>>& pheromone_matrix, const vector<City>& cities) {
    double total_probability = 0.0;
    vector<double> probabilities;

    for (int city : not_visited) {
        double pheromone = pow(pheromone_matrix[current_city][city], alpha);
        double dist = 1.0 / pow(distance(cities[current_city], cities[city]), beta);
        double probability = pheromone * dist;
        probabilities.push_back(probability);
        total_probability += probability;
    }

    double random_value = (double)rand() / RAND_MAX * total_probability;
    double cumulative_probability = 0.0;
    for (int i = 0; i < not_visited.size(); ++i) {
        cumulative_probability += probabilities[i];
        if (cumulative_probability >= random_value) {
            return not_visited[i];
        }
    }

    return not_visited.back();
}

void updatePheromones(vector<vector<double>>& pheromone_matrix, const vector<vector<int>>& ant_paths, const vector<City>& cities) {
    for (int i = 0; i < num_cities; ++i) {
        for (int j = 0; j < num_cities; ++j) {
            double pheromone = 0.0;
            for (int k = 0; k < num_ants; ++k) {
                for (int l = 0; l < ant_paths[k].size() - 1; ++l) {
                    if ((ant_paths[k][l] == i && ant_paths[k][l + 1] == j) || (ant_paths[k][l] == j && ant_paths[k][l + 1] == i)) {
                        pheromone += pheromone_deposit / distance(cities[ant_paths[k][l]], cities[ant_paths[k][l + 1]]);
                    }
                }
            }
            pheromone_matrix[i][j] = (1.0 - rho) * pheromone_matrix[i][j] + pheromone;
        }
    }
}

int main() {

    vector<City> cities = {{5, 4}, {7, 4}, {5, 6}, {4, 3}, {3, 6}, {4, 5}, {2, 4}, {1, 3}, {1,5}, (3,2)};
    vector<vector<double>> pheromone_matrix;
    initializePheromones(pheromone_matrix);

    srand(static_cast<unsigned int>(time(nullptr)));

    vector<vector<int>> ant_paths(num_ants);

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        for (int ant = 0; ant < num_ants; ++ant) {
            vector<int> not_visited;
            for (int i = 1; i < num_cities; ++i) {
                not_visited.push_back(i);
            }

            vector<int>& path = ant_paths[ant];
            path.clear();
            path.push_back(0);

            while (!not_visited.empty()) {
                int current_city = path.back();
                int next_city = selectNextCity(current_city, not_visited, pheromone_matrix, cities);
                path.push_back(next_city);
                not_visited.erase(remove(not_visited.begin(), not_visited.end(), next_city), not_visited.end());
            }
        }

        updatePheromones(pheromone_matrix, ant_paths, cities);
    }

    double min_distance = numeric_limits<double>::infinity();
    vector<int> best_path;

    for (const auto& path : ant_paths) {
        double distance_sum = 0.0;
        for (int i = 0; i < path.size() - 1; ++i) {
            distance_sum += distance(cities[path[i]], cities[path[i + 1]]);
        }

        if (distance_sum < min_distance) {
            min_distance = distance_sum;
            best_path = path;
        }
    }

    cout << "Mejor recorrido encontrado: ";
    for (int city : best_path) {
        cout << city << " ";
    }
    cout << "Distancia total: " << min_distance << endl;

    return 0;
}




