

(define (calcular-suma n)
  (cond
    ((= n 1) 1)  ; Caso base: la suma de 1 es 1
    (else (+ n (calcular-suma (- n 1))))))

(display "Ingresa un número para calcular la suma desde 1 hasta ese número: ")
(define numero (read))
(display "La suma desde 1 hasta ")
(display numero)
(display " es ")
(display (calcular-suma numero))

(display " \n ")

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



