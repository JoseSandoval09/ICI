import numpy as np

def funcion_escalon(x):
  return 1 if x >= 0 else 0

# Rango para pesos y bias
min_valor = -1
max_valor = 1

# Inicialización aleatoria de pesos y bias
w11 = np.random.uniform(min_valor, max_valor)
w12 = np.random.uniform(min_valor, max_valor)
b1 = np.random.uniform(min_valor, max_valor)
w21 = np.random.uniform(min_valor, max_valor)
w22 = np.random.uniform(min_valor, max_valor)
b2 = np.random.uniform(min_valor, max_valor)
w31 = np.random.uniform(min_valor, max_valor)
w32 = np.random.uniform(min_valor, max_valor)
b3 = np.random.uniform(min_valor, max_valor)

def XOR(x1, x2):
  # Capa oculta
  z1 = funcion_escalon(w11 * x1 + w12 * x2 + b1)
  z2 = funcion_escalon(w21 * x1 + w22 * x2 + b2)

  # Salida
  y = funcion_escalon(w31 * z1 + w32 * z2 + b3)

  return y

# Test
print("XOR(0, 0) = ", XOR(0, 0))
print("XOR(0, 1) = ", XOR(0, 1))
print("XOR(1, 0) = ", XOR(1, 0))
print("XOR(1, 1) = ", XOR(1, 1))
