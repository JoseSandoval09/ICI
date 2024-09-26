import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import time

# Parámetros
num_processors = 8
time_per_review = 1  # en segundos
n_values = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
num_particles = 30
iterations = 100
window_size = 1000  # Tamaño de la ventana deslizante

# Cargar el archivo CSV
file_path = 'movie_data.csv'  # Reemplaza con la ruta a tu archivo
data = pd.read_csv(file_path)

# Asegúrate de que la columna con las críticas se llama 'critica'
criticas = data[0].tolist()  # Cambia 'critica' por el nombre real de la columna

def evaluate(position):
    # Calcula el tiempo total para el procesador más ocupado
    return max(position) / time_per_review

def initialize_particles(num_particles, n, num_processors):
    particles = []
    for _ in range(num_particles):
        position = np.random.randint(0, n // num_processors + 1, num_processors)
        position = (position / position.sum() * n).astype(int)  # Normaliza a n críticas
        velocity = np.random.uniform(-1, 1, num_processors)
        particles.append((position, velocity))
    return particles

def update_particles(particles, global_best_position):
    for i, (position, velocity) in enumerate(particles):
        inertia = 0.5
        cognitive = 1.5
        social = 1.5

        r1 = np.random.random(size=num_processors)
        r2 = np.random.random(size=num_processors)

        # Actualiza velocidad
        velocity = (inertia * velocity +
                    cognitive * r1 * (particles[i][0] - position) +
                    social * r2 * (global_best_position - position))
        # Actualiza posición
        position += velocity.astype(int)

        # Asegúrate de que la posición es válida
        position[position < 0] = 0
        position = (position / position.sum() * position.sum()).astype(int)  # Normaliza a n críticas
        particles[i] = (position, velocity)

def pso_dynamic_load_balancing(n):
    particles = initialize_particles(num_particles, n, num_processors)
    global_best_position = None
    global_best_value = float('inf')

    for _ in range(iterations):
        for i, (position, _) in enumerate(particles):
            cost = evaluate(position)
            if cost < global_best_value:
                global_best_value = cost
                global_best_position = position

        update_particles(particles, global_best_position)

    return global_best_value

def sliding_window_pso(n):
    total_time = 0
    num_windows = (n + window_size - 1) // window_size

    for window in range(num_windows):
        start = window * window_size
        end = min(start + window_size, n)
        # Llama a PSO para cada ventana
        total_time += pso_dynamic_load_balancing(end - start)

    return total_time

# Simulación y almacenamiento de resultados
sequential_times = []
parallel_times = []

for n in n_values:
    # Tiempo secuencial
    sequential_time = n * time_per_review
    sequential_times.append(sequential_time)

    # Tiempo paralelo usando PSO y ventana deslizante
    start_time = time.time()
    parallel_time = sliding_window_pso(n)
    parallel_times.append(parallel_time)

    # Despliegue de progreso
    print(f"Procesando {n} críticas: Tiempo paralelo estimado: {parallel_time:.2f} s")

# Mostrar resultados en tabla
print("Críticas | Tiempo Secuencial (s) | Tiempo Paralelo (s)")
for n, seq, par in zip(n_values, sequential_times, parallel_times):
    print(f"{n:<9} | {seq:<23} | {par:.2f}")

# Graficar resultados
plt.plot(n_values, sequential_times, label='Secuencial', marker='o')
plt.plot(n_values, parallel_times, label='Paralelo (PSO + Ventana Deslizante)', marker='o')
plt.xlabel('Número de Críticas')
plt.ylabel('Tiempo (s)')
plt.title('Comparación de Tiempos de Procesamiento')
plt.legend()
plt.grid()
plt.show()
