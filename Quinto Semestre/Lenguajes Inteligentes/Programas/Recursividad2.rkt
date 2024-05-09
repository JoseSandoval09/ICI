

(define (potencia base exponente)
  (cond
    ((= exponente 0) 1) ; Cualquier número elevado a la potencia 0 es 1
    (else (* base (potencia base (- exponente 1))))))

(display "Ingresa la base: ")
(define base (read))
(display "Ingresa el exponente: ")
(define exponente (read))

(display "El resultado de ")
(display base)
(display " elevado a la potencia ")
(display exponente)
(display " es ")
(display (potencia base exponente))
