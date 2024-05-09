
(define (iniciar-conversacion)
  (display "Hola, hazme una pregunta\n")
  (conversacion))

(define (conversacion)
  (let ((respuesta (read-line)))
    (cond
      ((string=? respuesta "Adios")
       (display "¡Hasta luego!\n"))
      (else
       (display (generar-pregunta respuesta))
       (newline)
       (conversacion)))))

(define (generar-pregunta respuesta)
  (string-append "" respuesta "?"))

(iniciar-conversacion)

