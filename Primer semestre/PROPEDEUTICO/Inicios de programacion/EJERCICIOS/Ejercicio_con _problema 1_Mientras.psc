Proceso Ejercicio_ProblemaCal_Mientras
	Escribir "Insertar calificaciones de examen"
	Leer a
	Escribir "Inserta calificacion de proyecto"
	Leer b
	Escribir "Insertar  numero de tareas entregadas"
	Leer c
	Escribir "Inserte numero de tareas totales a entregar"
	Leer d
	
	Mientras (a<0 o a>10 o b<0 o b>10 o  c>d o d<1) Hacer
		
		Escribir "Valores incorrectos, por favor revisarlos"
		
		Escribir "Ingresar valores de nuevo en el mismo orden anterior"
		Leer a
		Leer b
		leer c
		leer d
	FinMientras
	
	Escribir "Valores correctos"
	cal_a= a* .3
	cal_b= b* .3
	cal_c= c*4 / d
	cal_t= cal_a+cal_b+cal_c
	
	Si cal_t<=6.4 Entonces
		Escribir "Tu calificacion es reprobatoria"
	Sino
		Si cal_t>=6.5 Entonces
			Escribir "Tu calificacion es aprobatoria"
		Fin Si
		
	Fin Si
	
	
	Escribir "Tu calificacion total es: " cal_t
	
	
	
FinProceso