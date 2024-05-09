
; Declaración de una función para calcular el área de un rectángulo
(define (area-rectangulo largo ancho)
  (* largo ancho))

; Declaración de una función para calcular el área de un círculo
(define (area-circulo radio)
  (* 3.1416 (* radio radio)))

; Declaración de una función para verificar si un número es par
(define (es-par? n)
  (if (even? n)
      #t
      #f))

; Declaración de una función para encontrar el máximo entre dos números
(define (maximo a b)
  (if (> a b)
      a
      b))

; Declaración de una función para encontrar el mínimo entre dos números
(define (minimo a b)
  (if (< a b)
      a
      b))

; Uso de las funciones
(define largo-rectangulo 5)
(define ancho-rectangulo 3)
(define radio-circulo 4)

(display "Área del rectángulo: ")
(display (area-rectangulo largo-rectangulo ancho-rectangulo))
(newline)

(display "Área del círculo: ")
(display (area-circulo radio-circulo))


(define numero 7)

(if (es-par? numero)
    (display "El número es par.")
    (display "El número es impar."))

(display "El número máximo es: ")
(display (maximo 9 12))

(display "El número mínimo es: ")
(display (minimo 7 10))

