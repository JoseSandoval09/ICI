import random

# Inicialización de parámetros
num_particulas = 30  # Número de partículas en el enjambre
num_procesadores = 5  # Número de procesadores
num_tareas = 20  # Número de tareas
max_iteraciones = 100  # Máximo número de iteraciones
w = 0.5  # Factor de inercia
c1 = 1.5  # Coeficiente de aceleración cognitiva
c2 = 1.5  # Coeficiente de aceleración social

# Generar tiempos de ejecución aleatorios para las tareas
tiempos_tareas = [random.randint(1, 10) for _ in range(num_tareas)]
print("Tiempos de ejecución de las tareas:", tiempos_tareas)

# Función para evaluar la función objetivo
def evaluar_funcion_objetivo(asignacion):
    procesador_carga = [0] * num_procesadores
    for tarea, procesador_asignado in enumerate(asignacion):
        procesador_carga[procesador_asignado] += tiempos_tareas[tarea]
    
    makespan = max(procesador_carga)
    utilizacion = sum(procesador_carga) / (num_procesadores * makespan)
    # Ejemplo de función de fitness que considera makespan y utilización
    fitness = makespan * (1 - utilizacion)
    return fitness

# Inicialización de partículas
enjambre = []

# Generar partículas iniciales aleatorias
for _ in range(num_particulas):
    posicion = [random.randint(0, num_procesadores - 1) for _ in range(num_tareas)]
    velocidad = [random.uniform(-1, 1) for _ in range(num_tareas)]
    fitness = evaluar_funcion_objetivo(posicion)
    particula = {
        'posicion': posicion,
        'velocidad': velocidad,
        'pbest': posicion[:],
        'pbest_fitness': fitness,
        'fitness': fitness
    }
    enjambre.append(particula)

# Determinar la mejor posición global inicial
global_best = min(enjambre, key=lambda x: x['pbest_fitness'])

# Comenzar iteraciones del PSO
for iteracion in range(max_iteraciones):
    for particula in enjambre:
        # Actualizar velocidad de la partícula
        for i in range(num_tareas):
            r1 = random.random()
            r2 = random.random()
            particula['velocidad'][i] = (
                w * particula['velocidad'][i] +
                c1 * r1 * (particula['pbest'][i] - particula['posicion'][i]) +
                c2 * r2 * (global_best['pbest'][i] - particula['posicion'][i])
            )

        # Actualizar posición de la partícula
        particula['posicion'] = [
            int(particula['posicion'][i] + particula['velocidad'][i]) % num_procesadores
            for i in range(num_tareas)
        ]

        # Evaluar la función objetivo con la nueva posición
        nuevo_fitness = evaluar_funcion_objetivo(particula['posicion'])
        particula['fitness'] = nuevo_fitness

        # Actualizar pbest
        if nuevo_fitness < particula['pbest_fitness']:
            particula['pbest'] = particula['posicion'][:]
            particula['pbest_fitness'] = nuevo_fitness

        # Actualizar el mejor global
        if nuevo_fitness < global_best['pbest_fitness']:
            global_best = {
                'pbest': particula['pbest'][:],
                'pbest_fitness': particula['pbest_fitness']
            }

    # Salida de la iteración
    print(f"Iteración {iteracion + 1}/{max_iteraciones}: Mejor fitness global = {global_best['pbest_fitness']}")

# Salida del mejor resultado encontrado
print("\nMejor asignación de tareas encontrada:")
print("Asignación:", global_best['pbest'])
print("Fitness:", global_best['pbest_fitness'])

# Mostrar la asignación de tareas a cada procesador
procesadores = [[] for _ in range(num_procesadores)]
for tarea, procesador in enumerate(global_best['pbest']):
    procesadores[procesador].append(tarea)

for i in range(num_procesadores):
    print(f"Procesador {i}: Tareas {procesadores[i]}")
