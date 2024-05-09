##NEURONA de McCullohPitts
##librerias de python
import numpy as np
#Modulo de pandas 
import pandas as pd
#Cargar datos de la flor [largoPetalo, largoCefalo]
#Importar datos
datos = pd.read_csv('iris.csv', sep=';')
#p.length
pL = datos.iloc[:,2]

#p.length
sL = datos.iloc[:,0]

#Tipo
tip = datos.iloc[:,4]

#Funcion de activacion
#w1*x1 + w2*x2 + ...+wn*xn
def activacion (pesos, x, b):
    z=pesos * x 
    if z.sum()+b>0:
         return 1
    else:
         return 0


#entrenamiento de perceptron
pesos=np.random.uniform(1,8,size=2)
b= np.random.uniform(1,8)
tasa_de_aprendizaje = 0.1
epocas = 100

for epoca in range(epocas):
    error_total = 0
    for index, valor in pL.items():
       prediccion = activacion(pesos, [pL[index],sL[index]],b) #El resultado será la prediccion
       #salida actual - salida deseada
       if tip[index] == 'setosa':
           clase = 1
       else:
           clase = 0
       error= clase - prediccion
       error_total += error**2
       #Ajustar el error, correspondiente a la edad y a la orden
       pesos[0]+=tasa_de_aprendizaje*pL[index]*error
       pesos[1]+=tasa_de_aprendizaje*sL[index]*error
       b+=tasa_de_aprendizaje*error
    print(error_total, end=" ")