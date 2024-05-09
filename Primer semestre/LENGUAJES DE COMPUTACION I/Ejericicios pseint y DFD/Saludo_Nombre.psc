Algoritmo Nombres
	// Sandoval Perez José Luis 1°A ICI
	Escribir '¿Cual es  tu nombre?'
	Leer nom
	Escribir 'Hola ',nom
	Repetir
		Escribir 'Deseas introducir otro nombre?'
		Escribir '1 es para Sí y 2 es para NO'
		Leer resp
		Si resp=1 Entonces
			Escribir '¿Cual es  tu nombre?'
			Leer nom
			Escribir 'Hola ',nom
		FinSi
	Hasta Que resp=2
FinAlgoritmo
