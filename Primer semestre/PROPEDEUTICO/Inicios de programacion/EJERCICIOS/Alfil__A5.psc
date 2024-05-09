Algoritmo Alfil
	fil=0; col=0
	
	Mientras (fil<1 o fil>8 o col<1 o col>8)
		Escribir "¿En que fila se encuentra el alfil"
		Leer fil
		Escribir "¿En que columna se encuentra el alfil?"
		Leer col
	FinMientras
	para f=1 hasta 8
		Escribir "";
		para c=1 hasta 8
			si(f-c=fil-col o f+c=fil+col)
				Escribir "[*]" Sin Saltar
			sino 
				Escribir "[]" Sin saltar
			FinSi
		FinPara
	FinPara
	Escribir ""
	
	
FinAlgoritmo
