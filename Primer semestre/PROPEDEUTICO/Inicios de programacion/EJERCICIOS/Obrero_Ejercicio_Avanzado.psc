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
	
	maxprd=999999
	minprd=-99999
	
	Si dia1<dia2 y dia<dia3 y dia1<dia4 y dia1<dia5 Entonces
		dia1pm=diamenprod
	SiNo
		
		Si dia1>dia2 o dia1>dia3 o dia1>dia4 o dia1>dia5 Entonces
			dia1pM=diamayprod
		SiNo
			Si dia2<dia1 y dia2<dia3 y dia2<dia4 y dia2<dia5 Entonces
				dia2pm=diamenprod
			SiNo
				
				Si dia2>dia1 y dia2>dia3 y dia2>dia4 y dia2>dia5 Entonces
					dia2pM=diamayprod
				FinSi
			Fin Si
			
			Si dia3<dia1 y dia3<dia2 y dia3<dia4 y dia3<dia5 Entonces
				dia3pm=diamenprod
			SiNo
				
				Si dia3>dia2 y dia3>dia1 y dia3>dia4 y dia3>dia5 Entonces
					dia3pM=diamayprod
				FinSi
			Fin Si
			
			Si dia4<dia1 y dia4<dia3 y dia4<dia2 y dia4<dia5 Entonces
				dia4pm=diamenprod
			SiNo
				
				Si dia4>dia2 y dia4>dia3 y dia4>dia1 y dia4>dia5 Entonces
					dia4pM=diamayprod
				FinSi
			Fin Si
			
			Si dia5<dia1 y dia5<dia3 y dia5<dia4 y dia5<dia2 Entonces
				dia5pm=diamenprod
			SiNo
				
				Si dia5>dia2 y dia5>dia3 y dia5>dia4 y dia5>dia1 Entonces
					dia5pM=diamayprod
				FinSi
			Fin Si
		FinSi
	Fin Si
	
	
	
	Si dia1pM>dia2pM y dia1pM>dia3pM y dia1pM>dia4pM y dia1pM>dia5pM Entonces
		Escribir "Tu dia mayor producido fue el lunes"
	SiNo
		Si dia2pM>dia1pM y dia2pM>dia3pM y dia2pM>dia4pM y dia2pM>dia5pM Entonces
			Escribir "Tu dia mayor producido fue el Martes"
		SiNo
			
		Si dia3pM>dia2pM y dia3pM>dia1pM y dia3pM>dia4pM y dia3pM>dia5pM Entonces
			Escribir "Tu dia mayor producido fue el Miercoles"
		SiNo
			Si dia4pM>dia2pM y dia4pM>dia3pM y dia4pM>dia1pM y dia4pM>dia5pM Entonces
				Escribir "Tu dia mayor producido fue el Jueves"
			SiNo
				Si dia5pM>dia2pM y dia5pM>dia3pM y dia5pM>dia4pM y dia5pM>dia1pM Entonces
					Escribir "Tu dia mayor producido fue el Viernes"
				SiNo
					Si dia1pM=dia2pM Entonces
						Escribir "Tus dias mayores producidos fueron Lunes y Martes"
					Sino 
						si dia1pM=dia3pM Entonces
							Escribir "Tus dias mayores producidos fueron Lunes y Miercoles"
						Sino 
							si dia1pM=dia4pM Entonces
								Escribir "Tus dias mayores producidos fueron Lunes y Jueves"
							Sino 
								si dia1pM=dia5pM Entonces
									Escribir "Tus dias mayores producidos fueron Lunes y Viernes"
								Sino 
									si dia2pM=dia1pM Entonces
										Escribir "Tus dias mayores producidos fueron Lunes y Martes"
									Sino 
										si dia2pM=dia3pM Entonces
											Escribir "Tus dias mayores producidos fueron Martes y Miercoles"
										Sino 
											si dia2pM=dia4pM Entonces
												Escribir "Tus dias mayores producidos fueron Martes y Jueves"
											Sino 
												si dia4pM=dia5pM Entonces
													Escribir "Tus dias mayores producidos fueron Martes y Viernes"
												SiNo
													Si dia3pM=dia1pM Entonces
														Escribir "Tus dias mayores producidos fueron Lunes y Miercoles"
													Sino 
														si dia3pM=dia2pM Entonces
															Escribir "Tus dias mayores producidos fueron Martes y Miercoles"
														SiNo
															Si dia3pM=dia4pM Entonces
																Escribir "Tus dias mayores producidos fueron Miercoles y Jueves"
															Sino 
																si dia3pM=dia5pM Entonces
																	Escribir "Tus dias mayores producidos fueron Viernes y Miercoles"
																SiNo
																	si dia4pM=dia1pM Entonces
																		Escribir "Tus dias mayores producidos fueron Lunes y Jueves"
																	SiNo
																		si dia4pM=dia2pM Entonces
																			Escribir "Tus dias mayores producidos fueron Martes y Jueves"
																		Sino 
																			si dia4pM=dia3pM Entonces
																				Escribir "Tus dias mayores producidos fueron Jueves y Miercoles"
																			Sino 
																				si dia4pM=dia5pM Entonces
																					Escribir "Tus dias mayores producidos fueron Jueves y Viernes"
																				Sino 
																					si dia5pM=dia1pM Entonces
																						Escribir "Tus dias mayores producidos fueron Lunes y Viernes"
																					Sino 
																						si dia5pM=dia2pM Entonces
																							Escribir "Tus dias mayores producidos fueron Viernes y Martes"
																						Sino 
																							si dia5pM=dia3pM Entonces
																								Escribir "Tus dias mayores producidos fueron Viernes y Miercoles"
																							Sino 
																								si dia5pM=dia4pM Entonces
																									
																									Escribir "Tus dias mayores producidos fueron Jueves y Viernes"
																								FinSi
																							FinSi
																							
																						FinSi
																					FinSi
																				FinSi
																			FinSi
																		FinSi
																	FinSi
																FinSi
															FinSi
														FinSi
													FinSi
												FinSi
											FinSi
										FinSi
										
									FinSi
								FinSi
								
							FinSi
							
						FinSi
					FinSi
					
				FinSi
				
			FinSi
			
		FinSi
	FinSi
		
	FinSi
	
	

	




	
	
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
