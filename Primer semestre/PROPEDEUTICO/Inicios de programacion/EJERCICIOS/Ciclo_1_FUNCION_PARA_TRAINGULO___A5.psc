Algoritmo Ciclo_1_FUNCION_PARA_TRAINGULO
	//se pide construir o diseñar un triangulo de n filas con caracteres,
	//donde el usuario proporciona el numero de filas de entre 3 a 20.
	
	nfilas=1
	Mientras (nfilas<3 o nfilas>20)
		Escribir "Dame el numero de filas del triangulo de entre 3-20"
		leer nfilas
		si (nfilas<3 o nfilas>20)
			Escribir "El valor de las filas debe ser de 3-20"
		FinSi
	FinMientras
	
	Escribir ""
	Para filas=1 hasta nfilas
		Para columnas=1 hasta filas
			Escribir"*" Sin Saltar
		FinPara
		Escribir ""
		
	FinPara
	Escribir ""
	
	
FinAlgoritmo
