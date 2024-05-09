pesos = np.random.uniform(-1,1, size=2)
b=np.random.uniform(-1,1)
tasa_de_aprendizaje=0.01
epocas=100

for epoca in range(epocas):
    error_total=0
    for i in range(len(personas)):
        prediccion= activacion(pesos,personas[i],b)
        error=clases[i] - prediccion
        error_total += error**2
        pesos[0] += tasa_de_aprendizaje * personas [i][0] * error
        pesos[1] += tasa_de_aprendizaje * personas [i][1] * error
        b += tasa_de_aprendizaje * error
    print(error_total, end=" ")

activacion(pesos,[0.5,0.8],b)

pesos, b, activacion(pesos,[0.5,0.8],b)