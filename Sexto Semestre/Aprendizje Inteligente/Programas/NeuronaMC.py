## Universdad Autonoma De Aguascalientes
## Ciencia de la Computacion
## Aprendizaje Inteligente
## Dr. Francisco Javier Luna Rosas
## Jose Luis Sandoval Perez
## Enero-Junio 2024

## NEURONA DE McCulloch Pits y Algoritmo de Percepcion simple

#Determinar si se le aprueba o no , una tarjeta de credito a un cliente considerando edad y ahorro que tiene en cuenta bancaria.

##Librerias Phyton

import numpy as np
##import matplot.pylot as plt

## Datos de 10 personas [Edad y ahorro]

personas = np.array([[0.3,0.4], [0.4, 0.3],
                     [0.3,0.2], [0.4, 0.1],
                     [0.5,0.4], [0.4, 0.8],
                     [0.6,0.8], [0.5, 0.6],
                     [0.7,0.6], [0.8, 0.5]]) 

##Clases; Aprobada 1  / Negada 0

clases = np.array([0,0,0,0,0,1,1,1,1,1])

##Funcion de Activacion


# w1*x1 + w2*x2 +...+ wn*xn
def activacion(pesos,x, b):
    z = pesos * x
    if z.sum() + b > 0:
        return 1
    else:
        return 0
    
##Entrenamiento neurona
    
pesos = np.random.uniform(-1,1, size=2)
b = np.random.uniform(-1,1)
tasa_de_aprendizaje = 0.01
epocas = 100

for epoca in range(epocas):
    error_total = 0
    for i in range(len(personas)):
        prediccion = activacion(pesos, personas[i], b)
        error = clases[i] - prediccion
        error_total += error**2
        pesos[0] += tasa_de_aprendizaje * personas[i][0] * error
        pesos[1] += tasa_de_aprendizaje * personas[i][1] * error
        b += tasa_de_aprendizaje * error
    print(error_total, end=" ")
    
activacion(pesos,[0.5,0.8],b)

pesos, b, activacion(pesos,[0.5,0.8],b)








