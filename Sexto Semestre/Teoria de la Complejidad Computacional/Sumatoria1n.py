import time
import matplotlib.pyplot as plt

# Función para calcular la sumatoria de 1 a n
def sumatoria(n):
  suma = 0
  for i in range(1, n + 1):
    suma += i
  return suma

# Lista para almacenar los valores de n
n_values = list(range(1, 1001))

# Lista para almacenar los tiempos de ejecución
tiempos = []

# Recorrer la lista de valores de n
for n in n_values:
  # Iniciar el temporizador
  start_time = time.time()

  # Calcular la sumatoria
  sumatoria(n)

  # Detener el temporizador
  end_time = time.time()

  # Calcular el tiempo de ejecución
  tiempo_ejecucion = end_time - start_time

  # Almacenar el tiempo de ejecución
  tiempos.append(tiempo_ejecucion)

# Graficar el tiempo de ejecución en función de n
plt.plot(n_values, tiempos)
plt.xlabel("Valor de n")
plt.ylabel("Tiempo de ejecución (segundos)")
plt.show()