Proceso ejercicio_4_Condicionales
	Escribir "Inserta 3 valores separados por Enter"
	Leer a,b,c
	Si (a>b y a>c) 
		Escribir a, " Es mayor que los demas " 
	Sino
		si (b>a y b>c) 
			Escribir b, " Es mayor que los demas  " 
		Sino
			si (c>a y c>b)
				Escribir c, " Es mayor que los demas " 
			Sino
				Escribir "Al menos 2 datos de ellos son iguales"
				
			FinSi
		FinSi
	Fin Si
	
FinProceso
