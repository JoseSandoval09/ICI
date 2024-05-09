# UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
# Introduccion a los Sistemas Operativos
# Maestra: CLELIA IVETTE RUIZ VERTIZ
# 6to Semestre

# Cesar Eduardo Elias del Hoyo
# Jose Luis Sandoval Perez

# PROGRAMACION DE ALGORITMOS

from operator import itemgetter
import matplotlib.pyplot as plt
import numpy as np
import os

class Process(object):
    def __init__(self, id, llegada, rafaga, inicio, fin, total, espera):
        self.id = id
        self.llegada = llegada
        self.rafaga = rafaga
        self.inicio = inicio
        self.fin = fin
        self.total = total
        self.espera = espera
        self.terminado = False

def graficar_procesos(procesos_ordenados, tiempoEspera, cantidad, totalTR):
    fig, (ax1, ax2) = plt.subplots(2, 1, gridspec_kw={'height_ratios': [1, 1]})
    
    # Crear Cronograma
    ax1.set_title('ALGORITMO DE PLANEACION DE PROCESOS DEL CPU')
    ax1.set_xlabel('Tiempo')
    ax1.set_ylabel('Numero de proceso')

    procesos_ordenados = list(reversed(procesos_ordenados))

    # Colocando los limites para X y Y
    ax1.set_ylim(0, cantidad)
    ax1.set_xlim(0, tiempoEspera)

    #ax1.set_yticks(range(cantidad))
    #ax1.set_yticklabels([proceso.id for proceso in procesos_ordenados])
    ax1.set_yticks(range(1, len(procesos_ordenados) + 1))
    ax1.set_yticklabels([proceso.id for proceso in procesos_ordenados])

    #for proceso in enumerate(procesos_ordenados):
        #ax1.broken_barh([(i+2, proceso.rafaga) for proceso, tiempoRespuesta in zip(procesos_ordenados, totalTR)], (i, 3), facecolors = (color[i]))
        # ax1.broken_barh([[proceso.llegada, proceso.espera] for proceso, tiempoRespuesta in zip(procesos_ordenados, totalTR)], (5, 3), facecolors = ('black'))
        #i = i + 1 

    color = ["red", "green", "blue", "orange", "pink", "gray", "brown", "purple", "yellow"]
    for i, proceso in enumerate(procesos_ordenados):
        ax1.broken_barh([(proceso.inicio, proceso.rafaga)], (i + 0.5, 1), facecolors=(color[i]))
        if proceso.espera > 0:
            ax1.broken_barh([(proceso.llegada, proceso.espera)], (i + 0.5, 1), facecolors=('black'))
    procesos_ordenados = list(reversed(procesos_ordenados))
    
    # Crear Tabla
    tabla = ax2.table(cellText=[[proceso.id, proceso.llegada, proceso.rafaga, proceso.inicio, proceso.fin, proceso.total, proceso.espera] for proceso, tiempoRespuesta in zip(procesos_ordenados, totalTR)],
                    colLabels=["Proceso", "Llegada", "Rafaga", "Inicio", "Fin", "T Total", "Espera"],
                    loc='center')

    tabla.auto_set_font_size(False)
    tabla.set_fontsize(10)
    tabla.scale(1.2, 1.2)
    ax2.axis('off')
    plt.show()

def tabla_procesos_fifo():
    clear = lambda: os.system('cls')
    clear()
    print('----- ALGORITMO FIFO -----\n')
    print('💻💻💻💻💻💻 OBTENEMOS DATOS DE ENTRADA 💻💻💻💻💻💻')
    print()
    cantidad_procesos_FIFO = int(input('Ingrese el número de procesos: '))
    if cantidad_procesos_FIFO > 0:
        procesosFifo = []
        procesos_completados = []
        cola_espera = []
        # Llenado de datos de los procesos por parte del usuario
        for numProceso in range(cantidad_procesos_FIFO):
            print()
            print(f' ----- Proceso #{numProceso + 1} -----')
            llegada = int(input(f'Ingrese el tiempo de llegada del proceso #{numProceso + 1}: '))
            rafaga = int(input(f'Ingrese el valor de rafaga de tiempo en CPU del proceso #{numProceso + 1}: '))
            procesosFifo.append(Process(numProceso + 1, llegada, rafaga, 0, 0, 0, 0))
            print()
            
        print('✅✅✅✅✅ RESULTADOS ✅✅✅✅✅')
        tiempoRespuesta = 0
        totalTR = []
        # Imprimimos la tabla
        print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("Proceso", "Llegada", "Rafaga", "Inicio", "Fin", "T Total", "Espera"))
        for proceso in procesosFifo:
            tiempoRespuesta += proceso.rafaga
            proceso.inicio = tiempoRespuesta - proceso.rafaga
            proceso.fin = tiempoRespuesta
            proceso.total = tiempoRespuesta - proceso.llegada
            proceso.espera = max(0, tiempoRespuesta - proceso.llegada - proceso.rafaga)
            print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format(proceso.id, proceso.llegada, proceso.rafaga, proceso.inicio, proceso.fin, proceso.total, proceso.espera))
            totalTR.append(tiempoRespuesta)

        # Llamamos a la funcion para graficar los procesos
        graficar_procesos(procesosFifo, tiempoRespuesta, cantidad_procesos_FIFO, totalTR)
    else:
        print('El número de procesos debe ser mayor a 0 (cero)')


def tabla_procesos_spn():
    clear = lambda: os.system('cls')
    clear()
    print('----- ALGORITMO SPN (MAS CORTO PRIMERO) -----\n')
    print('💻💻💻💻💻💻 OBTENEMOS DATOS DE ENTRADA 💻💻💻💻💻💻')
    print()
    cantidad_procesos_SPN = int(input('Ingrese el número de procesos: '))
    if cantidad_procesos_SPN > 0:
        tiempo_actual = 0
        procesosSPN = []
        procesos_completados = []
        cola_espera = []
        # Llenado de datos de los procesos por parte del usuario
        for numProceso in range(cantidad_procesos_SPN):
            print()
            print(f' ----- Proceso #{numProceso + 1} -----')
            llegada = int(input(f'Ingrese el tiempo de llegada del proceso #{numProceso + 1}: '))
            rafaga = int(input(f'Ingrese el valor de rafaga de tiempo en CPU del proceso #{numProceso + 1}: '))
            procesosSPN.append(Process(numProceso + 1, llegada, rafaga, 0, 0, 0, 0))
            print()

        print('✅✅✅✅✅ RESULTADOS ✅✅✅✅✅')
        # Imprimimos la tabla
        tiempoRespuesta = 0
        totalTR = []
        print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("Proceso", "Llegada", "Rafaga", "Inicio", "Fin", "T Total", "Espera"))
        
        while procesosSPN or cola_espera:
            # Mover procesos a cola_espera si ya llegaron
            while procesosSPN and procesosSPN[0].llegada <= tiempo_actual:
                cola_espera.append(procesosSPN.pop(0))

            if cola_espera:
                # Ordenar la cola espera por tiempo de rafaga
                cola_espera.sort(key=lambda p:p.rafaga)

                proceso2 = cola_espera.pop(0)
                proceso2.inicio = tiempo_actual
                proceso2.espera = tiempo_actual - proceso2.llegada
                tiempo_actual += proceso2.rafaga
                tiempoRespuesta += proceso2.rafaga
                proceso2.fin = tiempo_actual
                proceso2.total = proceso2.fin - proceso2.llegada
                procesos_completados.append(proceso2)
                print(f'{proceso2.id} (Tiempo: {tiempo_actual})')
                totalTR.append(tiempoRespuesta)
            else:
                tiempo_actual += 1
        
        procesos_completados.sort(key=lambda proceso: proceso.id)

        for proceso_final in procesos_completados:
            print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format(proceso_final.id, proceso_final.llegada, proceso_final.rafaga, proceso_final.inicio, proceso_final.fin, proceso_final.total, proceso_final.espera))

        # Llamamos a la funcion para graficar los procesos
        graficar_procesos(procesos_completados, tiempo_actual, cantidad_procesos_SPN, totalTR)
    else:
        print('El número de procesos debe ser mayor a 0 (cero)')

def main():
    while True:
        clear = lambda: os.system('cls')
        clear()
        print(' TAREA DE ALGORITMOS DE PROCESOS\n\n Cesar Eduardo Elias del Hoyo\n Jose Luis Sandoval Perez')
        print("\nMenú:\n")
        print("1. Tabla de procesos FIFO")
        print("2. Tabla de procesos SPN")
        print("0. Salir\n")

        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            tabla_procesos_fifo()
        elif opcion == "2":
            tabla_procesos_spn()
        elif opcion == "0":
            print("¡Hasta luego!")
            break
        else:
            print("Opción no válida. Por favor, seleccione una opción válida.")


if __name__ == "__main__":
    main()