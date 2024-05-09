Proceso sin_titulo
	Escribir "Dame una fecha separada por enter en formato Dia/Mes/Año "
	Leer dia,mes,año
	tope=0
	si (mes<1 o mes>12)
		Escribir "El mes es incorrecto"
	Sino
		segun mes hacer
			1,3,5,7,8,10,12: tope=31
			4,6,8,11:		 tope=30
			2:
				si(año%4=0 y año%100<>0 o año%400=0)Entonces
					tope=29
				Sino
					tope=28
					
				FinSi
		FinSegun
		Si (dia>=1 y dia <=tope)
			Escribir "fecha correcta"
			si(dia=tope y mes=12)
				dia_sig=1
				mes_sig=1
				año_sig=año+1
			Sino
				si (Dia=tope)
					dia_sig=1
					mes_sig=mes+1
					año_sig=año
				sino
					dia_sig=dia+1
					mes_sig=mes
					año_sig=año
				FinSi
				
			FinSi
			Escribir "Dia Actual: ",dia,"-",mes,"-",año
			Escribir "Dia Siguiente: ", dia_sig,"-",mes_sig,"-",año_sig
		Sino
			Escribir "Dia incorrecto"
			
		FinSi
	FinSi

FinProceso
