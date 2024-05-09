Proceso Ejercicio1_ciclo
	// realizar programa que eleve un valor x a la potencia z
	Escribir 'Se obtendra el valor de x a la potencia z'
	Escribir 'Inserte valor de X y Z, separados por ENTER'
	Leer x,z
	potencia=1
	
	Si (Z==0) Entonces
		potencia=1
	Sino
		
	Para i=1 Hasta z 
		potencia= potencia*x
	FinPara
	
	FinSi

	Escribir 'El valor de ',x,' elevado a la potencia ',z,' es: ',potencia
FinProceso

