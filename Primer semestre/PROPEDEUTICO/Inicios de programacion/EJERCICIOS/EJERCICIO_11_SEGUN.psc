Proceso ejemplo_1_SEGUN
	Escribir "Dame una fecha separada por enter en formato Dia/Mes/A�o "
	Leer dia,mes,a�o
	tope=0
	si (mes<1 o mes>12)
		Escribir "El mes es incorrecto"
	Sino
		segun mes hacer
			1,3,5,7,8,10,12: tope=31
			4,6,8,11:		 tope=30
			2:
				si(a�o%4=0 y a�o%100<>0 o a�o%400=0)Entonces
					tope=29
				Sino
					tope=28
					
				FinSi
		FinSegun
		si (dia>1 y dia<=tope)
			Escribir "Fecha correcta"
		Sino
			Escribir "Fecha incorrecta"
		
		FinSi
	FinSi
FinProceso