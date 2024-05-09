Algoritmo Obrero
	Escribir "Ingresa numero de articulos realizados el Lunes"
	Leer dia1
	Escribir "Ingresa numero de articulos realizados el Martes"
	Leer dia2
	Escribir "Ingresa numero de articulos realizados el Miercoles"
	Leer dia3
	Escribir "Ingresa numero de articulos realizados el Jueves"
	Leer dia4
	Escribir "Ingresa numero de articulos realizados el Viernes"
	Leer dia5
	
	Escribir "Ingresa pago por articulo"
	Leer pag
	
	
	totl_d1=dia1*pag
	totl_d2=dia2*pag
	totl_d3=dia3*pag
	totl_d4=dia4*pag
	totl_d5=dia5*pag
	total_semanal=totl_d1+totl_d2+totl_d3+totl_d4+totl_d5
	ahorro_semanal=total_semanal*.10
	total_semanal_desc=total_semanal-ahorro_semanal
	
	Escribir "Dia 1 ganaste: ", totl_d1
	Escribir "Dia 2 ganaste: " totl_d2
	Escribir "Dia 3 ganaste: " totl_d3
	Escribir "Dia 4 ganaste: " totl_d4
	Escribir "Dia 5 ganaste: " totl_d5
	Escribir "El total semanal sin descuento de ahorro es:  ", total_semanal ".00"
	Escribir "El total de esta semana con descuento es: ", total_semanal_desc ".00"
	Escribir "Esta semana ahorraste: " , ahorro_semanal ".00"
	
	

	
	
	
FinAlgoritmo
