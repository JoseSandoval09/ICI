import psutil
import time
import multiprocessing
import numpy as np
import random

# Función objetivo que queremos minimizar (puede ser cualquier función compleja)
def funcion_objetivo(x):
    return sum(x_i**2 for x_i in x)

def pso(cantidad_particulas, dimension, iteraciones):
    """Implementación simple de PSO (Optimización por Enjambre de Partículas)"""
    # Parámetros de PSO
    w = 0.5  # Inercia
    c1 = 1.5  # Constante cognitiva
    c2 = 1.5  # Constante social

    # Inicialización de las partículas
    posiciones = np.random.uniform(-10, 10, (cantidad_particulas, dimension))
    velocidades = np.random.uniform(-1, 1, (cantidad_particulas, dimension))
    mejores_posiciones_particula = posiciones.copy()
    mejores_valores_particula = np.array([funcion_objetivo(pos) for pos in posiciones])
    mejor_global = mejores_posiciones_particula[np.argmin(mejores_valores_particula)]
    
    for iteracion in range(iteraciones):
        for i in range(cantidad_particulas):
            # Actualización de la velocidad y posición
            velocidades[i] = (w * velocidades[i]
                              + c1 * random.random() * (mejores_posiciones_particula[i] - posiciones[i])
                              + c2 * random.random() * (mejor_global - posiciones[i]))
            posiciones[i] += velocidades[i]
            
            # Evaluar el nuevo valor de la función objetivo
            valor_actual = funcion_objetivo(posiciones[i])

            # Actualizar la mejor posición de la partícula
            if valor_actual < mejores_valores_particula[i]:
                mejores_valores_particula[i] = valor_actual
                mejores_posiciones_particula[i] = posiciones[i]

        # Actualizar la mejor posición global
        mejor_global = mejores_posiciones_particula[np.argmin(mejores_valores_particula)]
    
    return mejor_global

def generar_carga_con_pso():
    """Generar carga usando PSO con un problema de optimización complejo"""
    # Parámetros de la PSO
    cantidad_particulas = 500  # Aumenta para más carga
    dimension = 30  # Dimensiones del problema
    iteraciones = 1000  # Número de iteraciones para mayor carga

    # Ejecutar el algoritmo PSO
    mejor_solucion = pso(cantidad_particulas, dimension, iteraciones)
    print(f"Mejor solución encontrada: {mejor_solucion}")

def monitorear_procesador(indice_procesador):
    """Función que monitorea el uso de un procesador lógico específico."""
    try:
        while True:
            # Obtener el uso de todos los procesadores lógicos
            uso_por_procesador = psutil.cpu_percent(interval=1, percpu=True)

            # Verificar si el índice del procesador es válido
            if 0 <= indice_procesador < len(uso_por_procesador):
                # Mostrar la carga del procesador lógico seleccionado
                print(f"Procesador lógico {indice_procesador}: {uso_por_procesador[indice_procesador]}%")
            else:
                print(f"El procesador lógico {indice_procesador} no es válido.")

            time.sleep(1)

    except KeyboardInterrupt:
        print(f"\nMonitoreo del procesador lógico {indice_procesador} detenido.")

if __name__ == "__main__":
    indice_procesador = 0  # Cambia este valor para monitorear otro procesador lógico

    # Crear un proceso para monitorear el uso del procesador lógico
    proceso_monitoreo = multiprocessing.Process(target=monitorear_procesador, args=(indice_procesador,))
    
    # Crear otro proceso que genere carga con PSO
    proceso_carga = multiprocessing.Process(target=generar_carga_con_pso)
    
    # Iniciar ambos procesos
    proceso_monitoreo.start()
    proceso_carga.start()

    # Continuar con el programa principal
    try:
        print("Monitoreo y generación de carga usando PSO en progreso.")
        proceso_monitoreo.join()  # Bloquear el programa principal hasta que el monitoreo termine
        proceso_carga.join()      # Bloquear el programa principal hasta que el proceso de carga termine
    except KeyboardInterrupt:
        print("\nPrograma principal detenido. Terminando los procesos.")
        proceso_monitoreo.terminate()
        proceso_carga.terminate()
        proceso_monitoreo.join()
        proceso_carga.join()
