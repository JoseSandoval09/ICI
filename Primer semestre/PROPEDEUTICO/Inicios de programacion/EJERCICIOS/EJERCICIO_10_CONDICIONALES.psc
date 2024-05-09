Proceso ejercicio_5_Condicionales
	Escribir "Inserta 3 valores"
	Leer a,b,c
	si (a>b y b>c)
		Escribir a," ",b," ",c
	Sino
		si (a>c y c>b)
			Escribir a," ",c," ",b
		Sino
			si (b>c y c>a)
				Escribir b," ",c, " ", a
			Sino
				si (b>a y a>c)
					Escribir b," ",a," ",c
				Sino
					si(c>a y a>b)
						Escribir c," ",a," ",b
					Sino
						si (c>b y b>a)
							Escribir c," ",b," ",a
						Sino
							si (a=b y b=c)
								Escribir "Los 3 valores son iguales"
							Sino
								Escribir "Dos de ellos son iguales"
								
							FinSi
						FinSi
					FinSi
					
				FinSi
				
				
			FinSi
		FinSi

	FinSi
	
FinProceso
