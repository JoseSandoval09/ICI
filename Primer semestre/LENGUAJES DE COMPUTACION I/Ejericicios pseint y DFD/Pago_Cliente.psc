Algoritmo Pago_Cliente
	// Jose Luis Sandoval Perez 1°A ICI
	Escribir '¿Cuál es el precio del articulo?'
	Leer prec
	Escribir 'Ingrese cantidad que desee pagar'
	Leer pago
	Si (prec=pago) Entonces
		Escribir 'Pago exacto, gracias'
	SiNo
		Si (pago>prec) Entonces
			camb <- pago-prec
			Escribir 'El pago excede el precio del articulo, te sobran $ ',camb
		SiNo
			Si (pago<prec) Entonces
				Repetir
					Escribir 'Tu pago es insuficiente, ingrese cantidad restante a pagar'
					Leer rest
					pago <- pago+rest
				Hasta Que pago=prec
				Si (pago=prec) Entonces
					Escribir 'Pago exacto, gracias'
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
