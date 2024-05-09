Proceso multmat
	Definir correcto,A,B,R,c,d,e Como Entero
	Dimension A[10,10],B[10,10],R[10,10]
	correcto=0
	Mientras correcto=0
		Escribir "Total de filas de Matriz A entre 2 a 10"
		Leer FilA
		Escribir "Total de columnas de Matriz A entre 2 a 10"
		Leer CoA
		Escribir "Total de filas de Matriz B entre 2 a 10"
		Leer FilB
		Escribir "Total de Columnas de Matriz B entre 2 a 10"
		Leer ColB
		si FilA>=2 y FilA<=10 y CoA>=2 y CoA<=10 y ColB>=2 y ColB<=10 y CoA=FilB
			correcto=1
		Sino
			Escribir "Incorrecto "
		FinSi
	FinMientras
	//Entrada de datos
	Escribir "MATRIZ A"
	Para c=1 hasta FilA
		Para d=1 hasta CoA
			Escribir "Fila ",c," Columna ",d
			Leer A[c,d]
		FinPara
	FinPara
	Escribir "MATRIZ B"

	Para c=1 hasta FilB
		Para d=1 hasta ColB
			Escribir "Fila ",c," Columna ",d
			Leer B[c,d]
		FinPara
	FinPara
	//Método de Multiplicación de matrices
	Para c=1 hasta FilA
		Para d=1 hasta ColB
			R[c,d]=0
			Para e=1 hasta CoA
				R[c,d]=R[c,d]+(A[c,e]*B[e,d])
			FinPara
		FinPara
	FinPara
	//impresién de las matrices
	Escribir "MATRIZ A"
	Escribir ""
	Para c=1 hasta FilA
		Para d=1 hasta CoA
			Escribir Sin Saltar A[c,d]," "
		FinPara
		Escribir ""
	FinPara
	Escribir "MATRIZ B"
	Escribir ""
	Para c=1 hasta FilB
		Para d=1 hasta ColB
			Escribir Sin Saltar B[c,d]," "
		FinPara
		Escribir ""
	FinPara
	Escribir "MATRIZ RESULTANTE  R"
	Escribir ""
	Para c=1 hasta FilA
		Para d=1 hasta ColB
			Escribir Sin Saltar R[c,d]," "
		FinPara
		Escribir ""
	FinPara
FinProceso
